package org.test.java;

import static org.junit.Assert.assertArrayEquals;

import java.util.Arrays;
import java.util.Random;

import org.junit.Test;

import test.SwapSort;

public class SortsTest {

	private Random rand = new Random();
	
	Integer[] RandomArray(int size) {
		
		Integer array[] = new Integer[size];
		for (int i = 0; i < size; i++) {
			array[i] = rand.nextInt(size - 1);
		}
		return array;
	}
	

	@Test
	public void correct() {
	
		
		
		for (int i = 0; i < 10000; i++) {
		
			Integer[] array = RandomArray(10000);		
			
			Integer[] array1 = Arrays.copyOf(array, array.length);
		    SwapSort.sort(array);
		    Arrays.sort(array1);
		    assertArrayEquals(array, array1);
		   // SwapSort.print(array);
		}
		
	}
	
	@Test
	public void swapsort() {
	
		
		
		for (int i = 0; i < 1000; i++) {
		
			Integer[] array = RandomArray(10000);		
		    SwapSort.sort(array);

		}
		
	}
	

	@Test
	public void quicksort() {
	
		for (int i = 0; i < 1000; i++) {
			Integer[] array = RandomArray(10000);		
		    Arrays.sort(array);
		}
		
	}
	
	
}
