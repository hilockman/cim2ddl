package com.znd.ads.service.impl;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.DependsOn;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import com.znd.ads.exception.ModelException;
import com.znd.ads.mapper.ModelSourceMapper;
import com.znd.ads.model.ModelData;
import com.znd.ads.model.po.ModelSource;
import com.znd.ads.service.ModelService;
import com.znd.bus.common.buffer.ModelSourceBuffer;
import com.znd.ei.Utils;

@Service
@DependsOn("defaultBufferConfig")
public class ModelServiceImpl implements ModelService {

	private final Logger logger = LoggerFactory.getLogger(ModelService.class);

	@Value("${model.cachedDir}")
	private String cachedDir;

	private final List<ModelItem> roots = new ArrayList<>();
	
	private final List<ModelItem> allItems = new ArrayList<>();

	@Autowired
	private ModelSourceBuffer modelSourceBuffer;
	
	@Autowired
	private ModelSourceMapper modelSourceMapper;
	
	
	public static TraverseFunction FUNC = (parent, info, node) -> {

		if (node.isDirectory()) {
			info.setFolder(true);		
		} else {
			info.setFolder(false);
			info.setSpace(node.length());
		}
		info.setId(node.getName());
		info.setName(node.getName());
		info.setLastUpdate(new Date(node.lastModified()));

		if (parent != null) {
			info.setParentId(parent.getId());

			if (!info.getFolder()) {
				parent.setSpace(info.getSpace() + parent.getSpace());
			}
		}
		return info;
	};
	
	public static List<ModelItem> traverse(List<ModelItem> items, ModelItem parent, File node,
			TraverseFunction func) {

		ModelItem info = new ModelItem();
		if (func != null)
			func.visit(parent, info, node);
		
		if (node.isDirectory()) {
			String[] subNote = node.list();
			for (String filename : subNote) {
				traverse(items, info, new File(node, filename), func);
			}
		}
		
		items.add(info);

		return items;

	}

	/**
	 * 遍历根目录（不包括根目录）
	 * @param items
	 * @param rootDir
	 * @param func
	 * @return
	 */
	public static List<ModelItem> traverse(List<ModelItem> items, File rootDir, TraverseFunction func) {

		File[] files = rootDir.listFiles();
		for (File file : files)
			traverse(items, null, file, func);

		return items;
	}

	public static void main(String args[]) {
		List<ModelItem> items = traverse(new ArrayList<>(), new File("D:\\GitHub\\study-notes\\html"), FUNC);
		for (ModelItem item : items) {
			System.out.println(item);
		}
	}

	private void reload() {
		synchronized (this) {
			File rootDir = new File(cachedDir);
			roots.clear();
			allItems.clear();
			if (rootDir.exists())
				traverse(allItems, rootDir, FUNC);
			
			for (ModelItem item : allItems) {
				if (item.getParentId() == null) {
					roots.add(item);
				}
			}

			modelSourceBuffer.deleteAll();
			
			if (roots != null && roots.size() > 0) {
				for (ModelItem item : roots) {
					ModelSource ms = modelSourceMapper.findById(item.getId());
					if (ms == null)
						continue;
					
					item.setDesc(ms.getDesc());
					item.setName(ms.getName());

					modelSourceBuffer.save(ms);
				}
			}
		}
	}

	@Override
	public List getAll() {
		synchronized (this) {
			if (allItems.isEmpty()) {
				reload();
			}

			return allItems;
		}
	}

	@Override
	public List getRoots() {
		synchronized (this) {
			if (allItems.isEmpty()) {
				reload();
			}

			return roots;
		}
	}

	// save file
	private File[] cacheFiles(String root, String child,
			List<MultipartFile> files) throws IOException {

		Path base = Paths.get(root, child);
		File dir = base.toFile();
		if (!dir.exists()) {
			dir.mkdirs();
		}

		boolean flag = false;
		for (MultipartFile file : files) {

			if (file.isEmpty()) {
				continue; // next pls
			}

			byte[] bytes = file.getBytes();
			String fileName = file.getOriginalFilename();
			Path path = Paths.get(base.toAbsolutePath().toString(), fileName);
			logger.info("save file : " + path.toAbsolutePath().toString());
			Files.write(path, bytes);
			// if (p != null)
			// p.process(fileName, bytes);
			flag = true;
		}

		if (flag) {
			return dir.listFiles();
		} else {
			return new File[0];
		}

	}

	@Transactional(propagation = Propagation.REQUIRED)
	@Override
	public void upload(ModelData model) throws ModelException {		
				
		ModelSource o = new ModelSource();
		o.setId(Utils.randomKey());
		o.setName(model.getName());
		o.setDesc(model.getDesc());
		o.setLastUpdate(new Date());
		o.setType(model.getType());
		o.setId(Utils.randomKey());
		modelSourceMapper.insert(o);

		//System.out.println("Interted :"+o);
		Path path = Paths.get(cachedDir, o.getId());
		File file = path.toFile();
		if (file.exists()) {
//			throw new ModelException("模型已经存在：" + file.getName() + ", 目录："
//					+ file.getAbsolutePath());
			//TODO 删除模型
		} else
			file.mkdirs();
			
		try {
			cacheFiles(cachedDir, o.getId(),
					Arrays.asList(model.getFiles()));
		} catch (IOException e) {
			//e.printStackTrace();
			throw new ModelException("保存模型文件失败：" + o.getName() + ", "
					+ e.getMessage());
		}

		reload();
	}

	public static void removeIt(File node) {
		if (node.isDirectory()) {

			String[] subNote = node.list();
			for (String filename : subNote) {
				removeIt(new File(node, filename));
			}
		}

		node.delete();

	}

	@Transactional(propagation = Propagation.REQUIRED)
	@Override
	public void remove(String id) {
		if (id == null || id.isEmpty()) {
			throw new ModelException("模型名称为空。");
		}
		modelSourceMapper.removeById(id);
		
		Path path = Paths.get(cachedDir, id);
		File file = path.toFile();
		if (!file.exists()) {
			throw new ModelException("模型不存在：" + id);
		}
		removeIt(file);
		reload();
		logger.info("remove model : " + id);
	}

	@Override
	public ModelSource findModel(String modelId) {
		return modelSourceBuffer.findById(modelId);
	}

}
