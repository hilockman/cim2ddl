package com.znd.ei.codegen.service;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.common.Utils;
import com.znd.ei.memdb.Connection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaField;
import com.znd.ei.memdb.MetaTable;

@Component
public class CheckService {

	private Pattern fieldPattern = null;
	private List<Pattern> invalidTablePatterns = new ArrayList<Pattern>();
	private List<Pattern> invalidFieldPatterns = new ArrayList<Pattern>();

	@Autowired
	public CheckService(CheckProperties properties) {
		List<String> names = properties.getInvalidFieldNames();

		if (properties.getValidFieldPattern() != null) {
			System.out.println("--validFieldPattern:"
					+ properties.getValidFieldPattern());

			fieldPattern = Pattern.compile(properties.getValidFieldPattern(),
					Pattern.CASE_INSENSITIVE);

		}
		if (!names.isEmpty()) {
			System.out.println("--ExcludeFieldNames:" + names);
			String patternString = "(" + String.join("|", names) + ")";
			invalidFieldPatterns.add(Pattern.compile(patternString,
					Pattern.CASE_INSENSITIVE));
		}

		String str = properties.getInvalidFieldPattern();
		if (str != null && !str.isEmpty()) {
			invalidFieldPatterns.add(Pattern.compile(str));
			System.out.println("--InvalidFieldPattern:" + str);
		}

		names = properties.getInvalidTableNames();
		if (!names.isEmpty()) {
			System.out.println("--InvalidTableNames:" + names);
			String patternString = "(" + String.join("|", names) + ")";
			invalidTablePatterns.add(Pattern.compile(patternString,
					Pattern.CASE_INSENSITIVE));
		}
	}

	public void check(DbEntryOperations ops, String path) {

		Connection conn = ops.getConnection();

		System.out.println(String.format(
				"*********Check memdb : name=%s desc=%s***********",
				conn.getName(), conn.getDesc()));
		List<MetaTable> tables = ops.getTables();
		List<String> logs = new ArrayList<String>();
		for (MetaTable t : tables) {
			check(t, logs);
		}

		File dir = new File(path);
		if (!dir.exists()) {
			dir.mkdirs();
		}
		File logFile = new File(path + "/" + conn.getName() + ".check.log");
		if (logs.size() > 0) {

			PrintWriter fw = null;

			try {
				fw = new PrintWriter(
						new BufferedWriter(new FileWriter(logFile)));

				for (String log : logs) {
					fw.println(log);
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return;
			}
			fw.flush();
			fw.close();
		} else {
			Utils.deleteAllFilesOfDir(logFile);
		}
	}

	public void check(DbEntryOperations opss[], String path) {

		
		for (DbEntryOperations ops : opss) {
			check(ops, path);
		}
	}
	public boolean check(MetaTable t) {
		List<String> logs = new ArrayList<String>();
		check(t, logs);
		return logs.isEmpty();
	}
	private void check(MetaTable t, List<String> logs) {
		System.out.println("check table : " + t.getName());
		for (Pattern excludePattern : invalidTablePatterns) {
			Matcher isMatch = excludePattern.matcher(t.getName());

			if (isMatch.matches()) {

				System.out.println("表名:" + t.getName() + "("
						+ t.getDescription() + ")为保留名称," + t.getName()
						+ "(" + t.getDescription() + ")");

				logs.add("Invalid table name : " + t.getName() + ","
						+ t.getDescription());
			}
		}

		List<MetaField> fields = t.getFields();
		for (MetaField f : fields) {

			if (fieldPattern != null) {
				Matcher m = fieldPattern.matcher(f.getName());
				if (!m.matches()) {
					String log = String
							.format("Invalid field name: name=%s desc=%s , in table= %s, desc=%s, check rule=%s",
									f.getName(), f.getDescription(),
									t.getName(), t.getDescription(),
									fieldPattern);
					System.out.println(log);
					logs.add("Invalid field name : " + t.getName() + "->"
							+ f.getName() + "," + f.getDescription());
				}
			}

			for (int i = 0; i < invalidFieldPatterns.size(); i++) {
				Pattern excludePattern = invalidFieldPatterns.get(i);
				Matcher isMatch = excludePattern.matcher(f.getName());

				if (isMatch.matches()) {
					String log = String
							.format("Invalid field name: name=%s desc=%s , in table= %s, desc=%s, exclude rule ='%s'",
									f.getName(), f.getDescription(),
									t.getName(), t.getDescription(),
									excludePattern.pattern());
					System.out.println(log);
					logs.add("Invalid field name : " + t.getName() + "->"
							+ f.getName() + "," + f.getDescription());
				}
			}
		}
	}
}
