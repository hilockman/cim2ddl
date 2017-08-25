package com.znd.ei.codegen.service;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.FileSystemUtils;

import com.fasterxml.jackson.databind.deser.DataFormatReaders.Match;
import com.znd.ei.codegen.domain.FieldInfo;
import com.znd.ei.common.Utils;
import com.znd.ei.memdb.dao.MemDbRepository;
import com.znd.ei.memdb.dao.MemField;
import com.znd.ei.memdb.dao.MemTable;

@Service
public class MemClsssCreateService implements ClassCreateService {
	private MemDbRepository memDbRepository;
	private Path rootLocation;
	private static final Logger log = LoggerFactory
			.getLogger(MemClsssCreateService.class);

	private StorageProperties properties;

	@Autowired
	public MemClsssCreateService(MemDbRepository memDbRepository,
			StorageProperties properties) {
		rootLocation = Paths.get(properties.getLocation());
		this.setMemDbRepository(memDbRepository);
		this.properties = properties;

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
		List<String> excludeClasses = properties.getExcludeClasses();
		Pattern pattern = null;
		if (excludeClasses != null && !excludeClasses.isEmpty()) {
			log.info("--ExcludeClasses:" + excludeClasses);
			pattern = Pattern.compile("(" + String.join("|", excludeClasses)
					+ ")", Pattern.CASE_INSENSITIVE);
		}

		for (MemTable table: tables) {
			if (pattern != null) {
				Matcher m = pattern.matcher(table.getName());
				if (m.matches()) {
					log.info(">>>>>>>>>Omit Class:" + table.getName() + ", alias:"
							+ table.getDescription());
					continue;
				}
			}
			log.info("Create name:" + table.getName() + ", alias:"
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

	@Override
	public void deleteAll() {

		FileSystemUtils.deleteRecursively(rootLocation.toFile());

		String strs[] = rootLocation.toString().split("[/|\\\\]");
		File path = Paths.get(strs[0]).toAbsolutePath().toFile();
		Utils.deleteAllFilesOfDir(path);
	}

	private String lowerCaseFirstLetter(String name) {
		StringBuffer buff = new StringBuffer();
		buff.append(name.substring(0, 1).toLowerCase()).append(
				name.substring(1));
		return buff.toString();
	}

	@Override
	public void store(MemTable table) {

		String str = rootLocation.toString();
		String packageName = toPackageName(str);
		String fileName = str + "/" + table.getName() + ".java";

		CodeTemplateContext context = new CodeTemplateContext();

		context.add(new CodeBlock() { // 包声明

			@Override
			public void write(FileLineWriter w) {
				// 写入包信息
				w.write("package " + packageName + ";");
				w.write();
				w.write("import javax.persistence.Entity;");
				w.write("import javax.persistence.GeneratedValue;");
				w.write("import javax.persistence.GenerationType;");
				w.write("import javax.persistence.Id;");
				w.write();

				w.write("");
				w.write("/**********************");
				w.write("*" + table.getDescription() + "\t*");
				w.write("***********************/");
				w.write("@Entity");
			}
		});

		CodeBlockNode classNode = context.add(new CodeBlock() {

			@Override
			public void write(FileLineWriter w) {
				w.write("public class " + table.getName());
			}
		});

		List<MemField> fields = table.getFields();
		List<FieldInfo> fieldInfos = new ArrayList<FieldInfo>();
		FieldInfo idInfo = new FieldInfo();
		idInfo.setName("Id");
		idInfo.setTypeName("Integer");
		idInfo.setStandardName("id");
		List<String> annotations = new ArrayList<String>();
		annotations.add("@Id");
		annotations.add("@GeneratedValue(strategy=GenerationType.AUTO)");
		idInfo.setAnnotations(annotations);
		fieldInfos.add(idInfo);

		for (int i = 0; i < fields.size(); i++) {
			MemField f = fields.get(i);
			if (f == null)
				continue;

			FieldInfo info = new FieldInfo();

			switch (f.getType()) {
			case DOUBLE:
				info.setTypeName("Double");
				break;
			case INTEGER:
				info.setTypeName("Integer");
				break;
			case STRING:
				info.setTypeName("String");
				break;
			default:
				throw new StorageException("UnknowFileType : " + f.toString());
			}

			info.setName(f.getName());
			info.setStandardName(lowerCaseFirstLetter(f.getName()));
			List<String> notes = new ArrayList<String>();
			notes.add(f.getDescription());
			info.setNotes(notes);
			fieldInfos.add(info);
		}

		for (int i = 0; i < fieldInfos.size(); i++) {
			FieldInfo info = fieldInfos.get(i);
			classNode.add(new CodeBlock() { // 写入属性声明

						@Override
						public void write(FileLineWriter w) {
							StringBuffer buff = new StringBuffer();
							if (info.getNotes() != null) {
								for (int j = 0; j < info.getNotes().size(); j++) {
									w.write("//" + info.getNotes().get(j));
								}
							}

							if (info.getAnnotations() != null) {
								for (int j = 0; j < info.getAnnotations()
										.size(); j++) {
									w.write(info.getAnnotations().get(j));
								}
							}

							buff.append("private ").append(info.getTypeName())
									.append(" ").append(info.getStandardName())
									.append(";");
							w.write(buff.toString());
							w.write();
						}
					});

		}

		for (int i = 0; i < fieldInfos.size(); i++) {
			FieldInfo info = fieldInfos.get(i);
			StringBuffer buff = new StringBuffer();
			classNode.add(new CodeBlock() {

				@Override
				public void write(FileLineWriter w) { // get方法名
					buff.append("public ").append(info.getTypeName())
							.append(" get").append(info.getName())
							.append("() ");
					w.write(buff.toString());
				}
			}).add(new CodeBlock() {// get函数体
				@Override
				public void write(FileLineWriter w) {
					w.write("return " + info.getStandardName() + ";");
				}
			});

			classNode.add(new CodeBlock() {// set 方法名

						@Override
						public void write(FileLineWriter w) {
							buff.delete(0, buff.length());
							buff.append("public void").append(" set")
									.append(info.getName()).append("(")
									.append(info.getTypeName()).append(" ")
									.append(info.getStandardName()).append(")");
							w.write(buff.toString());

						}
					}).add(new CodeBlock() {// set 函数体

						@Override
						public void write(FileLineWriter w) {
							w.write("this." + info.getStandardName() + " = "
									+ info.getStandardName() + ";");
						}
					});

		}

		long begin = System.currentTimeMillis();

		context.save(fileName);

		long end = System.currentTimeMillis();
		log.info("执行耗时:" + (end - begin) + " 豪秒");

	}

}
