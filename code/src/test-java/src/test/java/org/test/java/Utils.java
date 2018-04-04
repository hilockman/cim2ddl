package org.test.java;

import java.util.Random;

public class Utils {
	private static final Random rand = new Random();
	
	public static Integer[] randomArray(int size) {
		
		Integer array[] = new Integer[size];
		for (int i = 0; i < size; i++) {
			array[i] = rand.nextInt(size - 1);
		}
		return array;
	}
}
