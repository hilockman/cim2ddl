package com.znd.ei.common;

import java.io.File;

public class Utils {
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

	public static String upperCaseFirstLetter(String str) {
		StringBuilder sb = new StringBuilder();
		sb.append(str.substring(0, 1).toUpperCase()).append(str.substring(1));
		return sb.toString();
	}
}
