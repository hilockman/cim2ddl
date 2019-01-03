package com.ei.ads.server;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.net.URISyntaxException;
import java.net.URL;

import org.junit.Test;

public class UrlTest {

	@Test
	public  void test() throws IOException {
        File file = new File("./JavaWorkspace/SingleServerConfig.cfg");
		if (!file.exists()) {
			System.out.println("Find no file :"+file.getAbsolutePath());
			return;
		}
		FileReader fr = new FileReader(file);
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();
		System.out.println("file is "+file.getAbsolutePath());
		while (line != null) {
			System.out.println(line);
			line = br.readLine();
		}
	}
}
 