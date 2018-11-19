package com.znd.bus.test;

import java.io.UnsupportedEncodingException;
import java.util.Arrays;

import org.junit.Test;


public class CodecTest {

	@Test
	public void wrongCode() throws UnsupportedEncodingException {
		System.out.println("____________________wrongCode____________________");
		String s = "你好";
		byte[] bytes = s.getBytes("UTF-8");
		String string = new String(bytes, "GBK");
		// 输出浣犲ソ，由于编码和解码的码表不同导致
		System.out.println(string);
 
		// 拨乱反正
		String string2 = new String(string.getBytes("GBK"), "UTF-8");
		// 输出你好
		System.out.println(string2);
		System.out.println("____________________wrongCode____________________ end");
 
	}
	
	@Test
	public void wrongCode1() throws UnsupportedEncodingException {
		System.out.println("____________________wrongCode1____________________");
		String s = "你好";
		byte[] bytes = s.getBytes("GBK");
		String string = new String(bytes, "UTF-8");
		// 输出浣犲ソ，由于编码和解码的码表不同导致
		System.out.println(string);
 
		// 拨乱反正
		String string2 = new String(string.getBytes("UTF-8"), "GBK");
		// 输出你好
		System.out.println(string2);
		System.out.println("____________________wrongCode1____________________ end");
 
	}
	
	@Test
	public void gbktest() throws UnsupportedEncodingException {
		System.out.println("____________________gbktest____________________");
		String hello = "你好";
		System.out.println("hello = " + hello);
		byte[] bytes = null;
		try {
			bytes = hello.getBytes("GBK");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String hello1 = new String(bytes, "UTF-8");
		System.out.println("hello1 = " + hello1);
		
		String hello2 = new String(hello1.getBytes("UTF-8"), "GBK");
		System.out.println("hello2 = " + hello2);
		System.out.println("____________________gbktest____________________end");
	}
	
	
	
	@Test
	public void decode() throws UnsupportedEncodingException {
		System.out.println("____________________decode____________________");
		
		// String(byte[] bytes, Charset charset) 通过使用指定的 charset 解码指定的 byte
		// 数组，构造一个新的 String。
		// 把看不懂的转成看的懂的，就是把字节转换成字符
		String s = new String(new byte[] { -60, -29, -70, -61 }, "GBK");
		// 输出你好
		System.out.println(s);
 
		String s1 = new String(new byte[] { -60, -29, -70, -61 }, "UTF-8");
		// 输出???，平台默认是GBK，UTF-8是三个字节是一个字符，转换异常
		System.out.println(s1);
 
		String s2 = new String(new byte[] { -60, -29, -70, -61 }, "ISO8859-1");
		// 输出????，平台默认是GBK，ISO8859-1是一个字节是一个字符，转换异常，欧洲码表没有负数
		System.out.println(s2);
		
		System.out.println("____________________decode____________________end");
 
	}
 
	@Test
	public void encode() throws UnsupportedEncodingException {
		System.out.println("____________________encode____________________");
		String s = "你好";
		// 使用平台默认的编码集，也就是eclipse的GBK编码[-60, -29, -70, -61]默认GBK
		byte[] bytes = s.getBytes();
		System.out.println(Arrays.toString(bytes));
 
		// GBK一个字符是两个字节 [-60, -29, -70, -61]
		byte[] bytes1 = s.getBytes("GBK");
		System.out.println(Arrays.toString(bytes1));
 
		// UTF-8就是[-28, -67, -96, -27, -91, -67]，一个字符是3个字节
		byte[] bytes2 = s.getBytes("UTF-8");
		System.out.println(Arrays.toString(bytes2));
		
		System.out.println("____________________encode____________________end");
	}

}
