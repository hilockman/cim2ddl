package com.znd.bus.server;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

import org.apache.commons.codec.binary.Base64;

public class CompressUtils {
	
	public static String DEFAULT_CHARSET = "UTF-8";
	
	public static byte[] compress(byte[] input) throws IOException {
		if (input == null || input.length == 0) {
            return null;
        }
		
		// GZIP the contents..
		ByteArrayOutputStream outstream = new ByteArrayOutputStream();		
		GZIPOutputStream gzipOut = null;
		try {
			gzipOut = new GZIPOutputStream(outstream);
			gzipOut.write(input);	
			gzipOut.close();
			gzipOut = null;
			
			return outstream.toByteArray();
		} finally {
			outstream.close();
			
			if (gzipOut != null)
				gzipOut.close();
			
		}
	}
	
	public static byte[] compress(String input) throws Exception {
		if (input == null)
			return null;
		
		return compress(input.getBytes(DEFAULT_CHARSET));
	}
	
	public static byte[] encode(byte[] input) {
		return Base64.encodeBase64(input);
	}
	
	public static byte[] decode(byte[] input) {
		return Base64.decodeBase64(input);
	}
	
	public static byte[] compressAndEncode(byte[] input) throws IOException {
		if (input == null || input.length == 0) {
            return null;
        }
		
		return encode(compress(input));
	}
	
	public static byte[] uncompress(byte[] input) throws IOException {			
		if (input == null || input.length == 0) {
            return null;
        }
		
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		GZIPInputStream gzipIn = null;
		try {	
			gzipIn = new GZIPInputStream(new ByteArrayInputStream(input));
			byte buffer[] = new byte[512];
				int n = 0;
				
			while ((n = gzipIn.read(buffer)) > 0) {
				out.write(buffer, 0, n);
			}
		
			
			return out.toByteArray();
		} finally {
			if (out != null)
				out.close();			
			if (gzipIn != null)
				gzipIn.close();

		}
	}
	
	
	public static byte[] decodeAndUncompress(byte[] input) throws IOException {	
		
		return uncompress(decode(input));
	}
	
	public static String compressAndEncodeToString(String input) {
		if (input == null)
			return null;
		
		try {
			return compressAndEncodeToString(input.getBytes(DEFAULT_CHARSET));
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			return null;
		}
	}
	
	public static String compressAndEncodeToString(byte[] input) {
		
		try {
			byte []array = compressAndEncode(input);
			
			return new String(array, DEFAULT_CHARSET);
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	public static String decodeAndUncompressToString(String input) {
		if (input == null)
			return null;
		
		try {
			return decodeAndUncompressToString(input.getBytes(DEFAULT_CHARSET));
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			return null;
		}
	}

	public static String decodeAndUncompressToString(byte[] input) {
		return decodeAndUncompressToString(input, DEFAULT_CHARSET);
	}
	
	public static String decodeAndUncompressToString(byte[] input, String encoding) {
		try {
			byte[] bytes = decodeAndUncompress(input);
			return new String(bytes, encoding);
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}
	
}
