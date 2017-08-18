package com.znd.ei.service;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.FileSystemUtils;

import com.znd.ei.memdb.dao.MemDbRepository;
import com.znd.ei.memdb.dao.MemField;
import com.znd.ei.memdb.dao.MemTable;

@Service
public class MemClsssCreateService implements ClasssCreateService {
	private MemDbRepository memDbRepository;
	private Path rootLocation;
	private static final Logger log = LoggerFactory
			.getLogger(MemClsssCreateService.class);

	@Autowired
	public MemClsssCreateService(MemDbRepository memDbRepository,	StorageProperties properties) {
		rootLocation = Paths.get(properties.getLocation());
		this.setMemDbRepository(memDbRepository);

	}

	public MemDbRepository getMemDbRepository() {
		return memDbRepository;
	}

	public void setMemDbRepository(MemDbRepository memDbRepository) {
		this.memDbRepository = memDbRepository;
	}

	@Override
	public void createClasses() {

		List<MemTable> tables = memDbRepository.getTables();
		for (int i = 0; i < tables.size(); i++) {
			MemTable table = tables.get(i);
			log.info("name:" + table.getName() + ", alias:"
					+ table.getDescription());
			store(table);
		}

		log.info("类创建完成！");

	}

	@Override
	public void init() {
		try {
			Files.createDirectories(rootLocation);
		} catch (IOException e) {
			throw new StorageException("Could not initialize storage", e);
		}
	}

	public static String toPackageName(String pathName) {
		return pathName.replaceAll("[/|\\\\]", ".");
	}

	// 递归删除文件夹
	private void deleteFile(File file) {
		if (file.exists()) {// 判断文件是否存在
			if (file.isFile()) {// 判断是否是文件
				file.delete();// 删除文件
			} else if (file.isDirectory()) {// 否则如果它是一个目录
				File[] files = file.listFiles();// 声明目录下所有的文件 files[];
				for (int i = 0; i < files.length; i++) {// 遍历目录下所有的文件
					this.deleteFile(files[i]);// 把每个文件用这个方法进行迭代
				}
				file.delete();// 删除文件夹
			}
		} else {
			System.out.println("所删除的文件不存在");
		}
	}
	
	public static void deleteAllFilesOfDir(File path) {  
	    if (!path.exists())  
	        return;  
	    if (path.isFile()) {  
	        path.delete();  
	        return;  
	    }  
	    File[] files = path.listFiles();  
	    for (int i = 0; i < files.length; i++) {  
	        deleteAllFilesOfDir(files[i]);  
	    }  
	    path.delete();  
	}  
	
	@Override
	public void deleteAll() {
		
		FileSystemUtils.deleteRecursively(rootLocation.toFile());
		
	    String strs[] = rootLocation.toString().split("[/|\\\\]");
		File path = Paths.get(strs[0]).toAbsolutePath().toFile();
		deleteAllFilesOfDir(path);
	}


	class MyLineWriter implements FileLineWriter
	{
		private  OutputStreamWriter out;
		public MyLineWriter(OutputStreamWriter o)
		{
			this.out = o;			
		}
		
		
		@Override
		public void write(String line) {
			write(line, 0);
		}
		@Override
		public void write() {
			write("");
		}


		@Override
		public void write(String line, int dent) {
			try {
				String sdent="";
				if (dent > 0) {
					char [] cs = new char[dent];
					for (int i = 0; i < dent; i++) {
						cs[i] = ' ';
					}
					
					sdent = new String(cs);
				}
				out.append(sdent+line+"\r\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}			
		}
	};
	
	private String lowerCaseFirstLetter(String name) {
		StringBuffer buff = new StringBuffer();
		buff.append(name.substring(0,1).toLowerCase())
	    .append(name.substring(1));
		return buff.toString();
	}
	
	@Override
	public void store(MemTable table) {

		// TODO Auto-generated method stub
		FileOutputStream out = null;

		try {

			String str = rootLocation.toString();
			String packageName = toPackageName(str);
			String fileName = str + "/" + table.getName() + ".java";
			File file = new File(fileName);
			
			out = new FileOutputStream(file);
			OutputStreamWriter oStreamWriter = new OutputStreamWriter(out, "utf-8");
			FileLineWriter w = new MyLineWriter(oStreamWriter);

			w.write("package " + packageName+";");
			w.write("");
			w.write("/**********************");
			w.write("*"+table.getDescription()+"\t*");
			w.write("***********************/");
			w.write("class " + table.getName());
			w.write("{");
			List<MemField> fields = table.getFields();
			int dent = 2;
			for (int i = 0;i < fields.size(); i++) {
			    MemField f = fields.get(i);
			    if (f == null)
			    	continue;
			    
			    String typeName;
			    w.write("//"+f.getDescription(), dent);
			    switch (f.getType()) {
			    case DOUBLE:
			    	typeName = "Double";
			    	break;
			    case INTEGER:
			    	typeName = "Integer";
			    	break;
			    case STRING:
			    	typeName = "String";
			    	break;
			    default:
			    	throw new StorageException("UnknowFileType : "+f.toString());
			    }
			    StringBuffer buff = new StringBuffer();
			    buff.append("private ").append(typeName)
			    .append(" ")
			    .append(lowerCaseFirstLetter(f.getName()))
			    .append(";");
			    w.write(buff.toString(), dent);
			    w.write();
			}
			
			for (int i = 0;i < fields.size(); i++) {
			    MemField f = fields.get(i);
			    if (f == null)
			    	continue;
			    
			    String typeName;
			    w.write("//"+f.getDescription(), dent);
			    switch (f.getType()) {
			    case DOUBLE:
			    	typeName = "Double";
			    	break;
			    case INTEGER:
			    	typeName = "Integer";
			    	break;
			    case STRING:
			    	typeName = "String";
			    	break;
			    default:
			    	throw new StorageException("UnknowFileType : "+f.toString());
			    }
			    StringBuffer buff = new StringBuffer();
			    buff.append("public ")
			    .append(typeName)
			    .append(" get")
			    .append(f.getName())
			    .append("() {");
			    w.write(buff.toString(), dent);
			    
			    String fieldName = lowerCaseFirstLetter(f.getName());
			    w.write("return "+fieldName+";", dent+2);
			    w.write("}",dent);
			    w.write();
			    
			    buff.delete(0, buff.length());
			    buff.append("public void")
			    .append(" set")
			    .append(f.getName())
			    .append("(")
			    .append(typeName)
			    .append(" ")
			    .append(fieldName)
			    .append("){");
			    
			    w.write(buff.toString(), dent);
			    w.write("this."+fieldName+" = "+fieldName+";",dent+2);
			    w.write("}",dent);
			    w.write();
			}
			
			
			w.write("}");

			long begin = System.currentTimeMillis();

			oStreamWriter.flush();
			oStreamWriter.close();
			out.close();
			long end = System.currentTimeMillis();
			log.info("FileOutputStream执行耗时:" + (end - begin) + " 豪秒");
		} catch (Exception e) {
			e.printStackTrace();
		}

		finally {
			try {
				out.close();
			} catch (Exception e) {
				e.printStackTrace();
			}

		}

	}

}
