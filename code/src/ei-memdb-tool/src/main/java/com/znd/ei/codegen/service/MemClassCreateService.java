package com.znd.ei.codegen.service;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.codegen.domain.FieldInfo;
import com.znd.ei.common.Utils;
import com.znd.ei.memdb.DbEntry;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaField;
import com.znd.ei.memdb.MetaTable;

@Component
public class MemClassCreateService implements ClassCreateService {
	// private DbEntryOperations ops;
	private Path rootLocation;
	private static final Logger log = LoggerFactory
			.getLogger(MemClassCreateService.class);

	private GenCodeProperties properties;

	@Autowired
	private CheckService checkService;

	@Autowired
	public MemClassCreateService(/* DbEntryOperations bPAOps, */
	GenCodeProperties properties) {
		rootLocation = Paths.get(properties.getTarget());
		// this.ops = bPAOps;
		// this.setMemDbRepository(bPAOps);
		this.properties = properties;

	}

	// public DbEntryOperations getMemDbRepository() {
	// return ops;
	// }
	//
	// public void setMemDbRepository(DbEntryOperations memDbRepository) {
	// this.ops = memDbRepository;
	// }

	private void createClasses(Pattern pattern, DbInfo dbInfo) {

		DbEntryOperations ops = DbEntryOperations.find(dbInfo.getEntryName());
		String packageName = dbInfo.getPackageName();
		String path = properties.getTarget() + "/"
				+ packageName.replaceAll("\\.", "/");
		Path location = Paths.get(path);
		try {
			Files.createDirectories(location);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		List<MetaTable> tables = ops.getTables();
		for (MetaTable table : tables) {
			if (pattern != null) {
				Matcher m = pattern.matcher(table.getName());
				if (m.matches()) {
					log.info(">>>>>>>>>Omit Class:" + table.getName()
							+ ", alias:" + table.getDescription());
					continue;
				}
			}
			log.info("Create name:" + table.getName() + ", alias:"
					+ table.getDescription());
			store(table, location, packageName);
		}

		log.info("类创建完成！");
	}

	@Override
	public void createClasses() {

		List<String> excludeClasses = properties.getExcludeClasses();
		Pattern pattern = null;
		if (excludeClasses != null && !excludeClasses.isEmpty()) {
			log.info("--ExcludeClasses:" + excludeClasses);
			pattern = Pattern.compile("(" + String.join("|", excludeClasses)
					+ ")", Pattern.CASE_INSENSITIVE);
		}

		List<DbInfo> dbInfos = properties.getDbInfos();
		for (DbInfo dbInfo : dbInfos) {
			createClasses(pattern, dbInfo);
		}
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

	// @Override
	// public void deleteAll() {
	//
	// FileSystemUtils.deleteRecursively(rootLocation.toFile());
	//
	// String strs[] = rootLocation.toString().split("[/|\\\\]");
	// File path = Paths.get(strs[0]).toAbsolutePath().toFile();
	// // Utils.deleteAllFilesOfDir(path);
	// }

	private String lowerCaseFirstLetter(String name) {
		StringBuffer buff = new StringBuffer();
		buff.append(name.substring(0, 1).toLowerCase()).append(
				name.substring(1));
		return buff.toString();
	}

	@Override
	public void store(MetaTable table, Path location, String packageName) {

		String str = location.toString();
		// String packageName = toPackageName(str);
		String fileName = str + "/" + table.getName() + ".java";
		Utils.deleteAllFilesOfDir(new File(fileName));

		if (!checkService.check(table)) { // 表字段有误则不产生java文件
			return;
		}
		CodeTemplateContext context = new CodeTemplateContext();

		context.add(new CodeBlock() { // 包声明

			@Override
			public void write(FileLineWriter w) {
				// 写入包信息
				w.write("package " + packageName + ";");
				w.write();
				if (properties.isEnableEntityAnnotation()) {
					w.writeln("import javax.persistence.Entity");
					w.writeln("import javax.persistence.GeneratedValue");
					w.writeln("import javax.persistence.GenerationType");
					w.writeln("import javax.persistence.Id");
					w.write();
				} else {
					w.writeln("import com.znd.ei.memdb.MemIndexable");
				}

				w.write("");
				w.write("/**********************");
				w.write("*" + table.getDescription() + "\t*");
				w.write("***********************/");
				if (properties.isEnableEntityAnnotation()) {
					w.write("@Entity");
				}
			}
		});

		CodeBlockNode classNode = context.add(new CodeBlock() {

			@Override
			public void write(FileLineWriter w) {
				if (properties.isEnableEntityAnnotation()) {
					w.write("public class " + table.getName());
				} else {
					w.write("public class " + table.getName()+"  implements MemIndexable ");
				}
			}
		});

		List<MetaField> fields = table.getFields();
		List<FieldInfo> fieldInfos = new ArrayList<FieldInfo>();
		if (properties.isEnableEntityAnnotation()) {
			addField(fieldInfos, "Id", "id", "Integer", "@Id",
					"@GeneratedValue(strategy=GenerationType.AUTO)");
		} else {
			addField(fieldInfos, "Id", "id", "Integer");
		}

		addField(fieldInfos,
				Utils.upperCaseFirstLetter(DbEntry.MEM_INDEX_COLUMN_NAME),
				DbEntry.MEM_INDEX_COLUMN_NAME, "Integer");

		for (int i = 0; i < fields.size(); i++) {
			MetaField f = fields.get(i);
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
			//info.setStandardName(lowerCaseFirstLetter(f.getName()));
			info.setStandardName(f.getName());
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
									.append(" ").append(info.getStandardName());
							w.writeln(buff.toString());
							w.write();
						}
					});

		}

		List<String> toStringMethods = new ArrayList<String>();
		for (int i = 0; i < fieldInfos.size(); i++) {
			FieldInfo info = fieldInfos.get(i);
			StringBuffer buff = new StringBuffer();
			classNode.add(w -> {// get方法名

						w.write(formMethodString("public", info.getTypeName(),
								"get" + info.getName()));
					}).add(w -> {// get函数体
						w.writeln("return " + info.getStandardName());
					});

			classNode.add(w -> {// set 方法名
						w.write(formMethodString("public", "void",
								"set" + info.getName(), info.getTypeName(),
								info.getStandardName()));
					}).add(w -> {// set 函数体
						w.writeln("this." + info.getStandardName() + " = "
								+ info.getStandardName());
					});

			toStringMethods.add((i > 0 ? "\t + \", " : "\"")
					+ info.getStandardName() + " = \" + "
					+ info.getStandardName());
		}

		classNode.add(w -> {
			w.write(formMethodString("public", "String", "toString"));
		}).add(w -> {
			w.writeln("return " + wrapprerWithQuota(table.getName() + " [")
					+ "+" + String.join("\n", toStringMethods) + "+"
					+ wrapprerWithQuota("]"));
		});

		long begin = System.currentTimeMillis();

		context.save(fileName);

		long end = System.currentTimeMillis();
		log.info("执行耗时:" + (end - begin) + " 豪秒");

	}

	private String wrapprerWithQuota(String str) {
		return wrapperWith(str, "\"");
	}

	private String wrapperWith(String str, String w) {
		return w + str + w;
	}

	private String wrapperWith(String str, String[] w) {
		return w[0] + str + w[1];
	}

	private String formMethodString(String scope, String returnParmType,
			String name, String... params) {
		StringBuffer buff = new StringBuffer();
		buff.delete(0, buff.length());
		buff.append(scope).append(' ').append(returnParmType).append(' ')
				.append(name);
		List<String> strs = new ArrayList<String>();
		for (int i = 0; i < params.length; i++) {
			if (i % 2 == 1) {
				strs.add(params[i - 1] + " " + params[i]);
			}

		}
		String[] ends = { "(", ")" };
		buff.append(wrapperWith(String.join(", ", strs), ends));
		return buff.toString();
	}

	private void addField(List<FieldInfo> fieldInfos, String name,
			String standardName, String typeName, String... annotations) {

		FieldInfo idInfo = new FieldInfo();
		idInfo.setName(name);
		idInfo.setTypeName(typeName);
		idInfo.setStandardName(standardName);
		List<String> list = Arrays.asList(annotations);
		idInfo.setAnnotations(list);
		fieldInfos.add(idInfo);
	}

	public Path getRootLocation() {
		return rootLocation;
	}

	public void setRootLocation(Path rootLocation) {
		this.rootLocation = rootLocation;
	}

}
