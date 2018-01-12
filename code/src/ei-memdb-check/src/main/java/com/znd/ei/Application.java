package com.znd.ei;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.Connection;
import com.znd.ei.memdb.DbEntry;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MetaField;
import com.znd.ei.memdb.MetaTable;

@SpringBootApplication
@EnableConfigurationProperties(CheckProperties.class)
public class Application {

	public static void main(String[] args) {
		System.exit(SpringApplication.exit(SpringApplication.run(
				Application.class, args)));
	}

	@Bean
	public DbEntryOperations[] pROps(DbEntryCollection c) throws DbException {
		String[] entryNames = MDBDefine.g_strDBEntryArray;
		DbEntryOperations[] opss = new DbEntryOperations[entryNames.length];
		int index = 0;

		for (String entryName : entryNames) {
			DbEntryOperations ops = c.findOrCreateDbEntry(entryName);
			opss[index++] = ops;
		}

		return opss;
	}

	@Bean
	public CommandLineRunner init(DbEntryOperations[] opss,
			CheckProperties properties) {
		return (args) -> {
			List<String> names = properties.getExcludeFieldNames();
			List<Pattern> excludeFieldPatterns = new ArrayList<Pattern>();
			Pattern fieldPattern = null;
			if (properties.getFieldPattern() != null) {
				System.out.println("--fieldPattern:"
						+ properties.getFieldPattern());

				fieldPattern = Pattern.compile(properties.getFieldPattern(),
						Pattern.CASE_INSENSITIVE);

			}
			if (!names.isEmpty()) {
				System.out.println("--ExcludeFieldNames:" + names);
				String patternString = "(" + String.join("|", names) + ")";
				excludeFieldPatterns.add(Pattern.compile(patternString,
						Pattern.CASE_INSENSITIVE));
			}

			String str = properties.getExcludeFieldPattern();
			if (str != null && !str.isEmpty()) {
				excludeFieldPatterns.add(Pattern.compile(str));
				System.out.println("--ExcludeFieldPattern:" + str);
			}

			List<Pattern> excludeTablePatterns = new ArrayList<Pattern>();
			names = properties.getExcludeTableNames();
			if (!names.isEmpty()) {
				System.out.println("--ExcludeTableNames:" + names);
				String patternString = "(" + String.join("|", names) + ")";
				excludeTablePatterns.add(Pattern.compile(patternString,
						Pattern.CASE_INSENSITIVE));
			}

			for (DbEntryOperations ops : opss) {
				Connection conn = ops.getConnection();
				System.out.println(String.format(
						"*********Check memdb : name=%s desc=%s***********",
						conn.getName(), conn.getDesc()));
				List<MetaTable> tables = ops.getTables();

				for (MetaTable t : tables) {
					System.out.println("check table : " + t.getName());
					for (Pattern excludePattern : excludeTablePatterns) {
						Matcher isMatch = excludePattern.matcher(t.getName());

						if (isMatch.matches()) {
							System.out.println("表名:" + t.getName() + "("
									+ t.getDescription() + ")为保留名称,"
									+ t.getName() + "(" + t.getDescription()
									+ ")");
						}
					}

					List<MetaField> fields = t.getFields();
					for (MetaField f : fields) {

						 //System.out.println("\tField:"+f.getName()+", Table:"+t.getName());


						if (fieldPattern != null) {
							Matcher m = fieldPattern.matcher(f.getName());
							if (!m.matches()) {
								String log = String
										.format("Invalid field name: name=%s desc=%s , in table= %s, desc=%s, check rule=%s",
												f.getName(),
												f.getDescription(),
												t.getName(), t.getDescription(), fieldPattern);
								System.out.println(log);
							}
						}

						for (int i = 0; i < excludeFieldPatterns.size(); i++) {
							Pattern excludePattern  = excludeFieldPatterns.get(i);
							Matcher isMatch = excludePattern.matcher(f
									.getName());

							if (isMatch.matches()) {
								String log = String
										.format("Invalid field name: name=%s desc=%s , in table= %s, desc=%s, exclude rule ='%s'",
												f.getName(),
												f.getDescription(),
												t.getName(), t.getDescription(),excludePattern.pattern());
								System.out.println(log);
							}
						}
					}
				}
			}

		};
	}
}
