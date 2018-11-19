package com.znd.bus.test;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

import org.junit.Test;

import com.znd.bus.server.CompressUtils;

public class CompressTest {


	
	
	
    public static final String GZIP_ENCODE_UTF_8 = "UTF-8";
    
    public static final String GZIP_ENCODE_ISO_8859_1 = "ISO-8859-1";
 
    /**
     * 字符串压缩为GZIP字节数组
     * 
     * @param str
     * @return
     */
    public static byte[] compress(String str) {
        return compress(str, GZIP_ENCODE_UTF_8);
    }
 
    /**
     * 字符串压缩为GZIP字节数组
     * 
     * @param str
     * @param encoding
     * @return
     */
    public static byte[] compress(String str, String encoding) {
        if (str == null || str.length() == 0) {
            return null;
        }
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        GZIPOutputStream gzip;
        try {
            gzip = new GZIPOutputStream(out);
            gzip.write(str.getBytes(encoding));
            gzip.close();
        } catch (IOException e) {
            //ApiLogger.error("gzip compress error.", e);
        }
        return out.toByteArray();
    }
 
    /**
     * GZIP解压缩
     * 
     * @param bytes
     * @return
     */
    public static byte[] uncompress(byte[] bytes) {
        if (bytes == null || bytes.length == 0) {
            return null;
        }
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ByteArrayInputStream in = new ByteArrayInputStream(bytes);
        try {
            GZIPInputStream ungzip = new GZIPInputStream(in);
            byte[] buffer = new byte[256];
            int n;
            while ((n = ungzip.read(buffer)) >= 0) {
                out.write(buffer, 0, n);
            }
        } catch (IOException e) {
            //ApiLogger.error("gzip uncompress error.", e);
        }
 
        return out.toByteArray();
    }
 
    /**
     * 
     * @param bytes
     * @return
     */
    public static String uncompressToString(byte[] bytes) {
        return uncompressToString(bytes, GZIP_ENCODE_UTF_8);
    }
 
    /**
     * 
     * @param bytes
     * @param encoding
     * @return
     */
    public static String uncompressToString(byte[] bytes, String encoding) {
        if (bytes == null || bytes.length == 0) {
            return null;
        }
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ByteArrayInputStream in = new ByteArrayInputStream(bytes);
        try {
            GZIPInputStream ungzip = new GZIPInputStream(in);
            byte[] buffer = new byte[256];
            int n;
            while ((n = ungzip.read(buffer)) >= 0) {
                out.write(buffer, 0, n);
            }
            return out.toString(encoding);
        } catch (IOException e) {
           // ApiLogger.error("gzip uncompress to string error.", e);
        }
        return null;
    }
    //static String str = "%5B%7B%22lastUpdateTime%22%3A%222011-10-28+9%3A39%3A41%22%2C%22smsList%22%3A%5B%7B%22liveState%22%3A%221";
    static String str = "1111111111111111111111111111111111111222222222222222222222222222222222333333333333333333333333333334444444444444444444444";
 
    @Test
    public  void test1() {
    	System.out.println("_____________________test1_________________");
        System.out.println("原长度：" + str.length());
        System.out.println("压缩后字符串：" + compress(str).toString().length());

        System.out.println("解压缩后字符串：" + uncompressToString(compress(str)));
        System.out.println("_____________________test1_________________");
    }
	@Test
	public void test() throws Exception {
		System.out.println("______________________test_______________________");

		System.out.println("原长度：" + str.length());
		System.out.println("压缩后字符串长度：" + CompressUtils.compress(str).length);
		System.out.println("压缩后字符串长度：" + CompressUtils.compress(str).toString().length());
		System.out.println("压缩编码后后字符串长度：" + CompressUtils.compressAndEncodeToString(str).length());
		System.out.println("解码解压缩后字符串：" + CompressUtils.decodeAndUncompressToString(CompressUtils.compressAndEncodeToString(str)));
		System.out.println("______________________test_______________________");
	}
}
