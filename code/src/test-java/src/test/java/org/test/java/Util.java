package org.test.java;


public class Util {
	
	public static <T> String toString(T[] array) {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for (int i = 0; i < array.length; i++) {
			if (i > 0) {
				sb.append(", ");
			}
			
			sb.append(array[i]);
			
		}
		sb.append("]");
		return sb.toString();
	}
	
	public static String toString(int[] array) {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for (int i = 0; i < array.length; i++) {
			if (i > 0) {
				sb.append(", ");
			}
			
			sb.append(array[i]);
			
		}
		sb.append("]");
		return sb.toString();
	}
	
	public static <T> void print(T[] array) {
		System.out.println(toString(array));
		
	}

	public static void print(int[] array) {
		System.out.println(toString(array));
	}
}
