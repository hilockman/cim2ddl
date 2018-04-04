package test;
import java.util.Comparator;


public class SwapSort {

	public static <T> void print(T[] array) {
		System.out.print("[");
		for (int i = 0; i < array.length; i++) {
			if (i > 0) {
				System.out.print(", ");
			}
			
			System.out.print(array[i]);
			
		}
		System.out.println("]");
	}
	
	
	
	public static void sort(Integer[] datas) {
		sort(datas, (v1, v2)->{ return v1.compareTo(v2); });
	}
	
	public static void sort(int[] array) {	
		sort(array, 0, array.length);
	}
	
	public static void sort(String[] datas) {
		sort(datas, (v1, v2)->{ return v1.compareTo(v2); });
	}
	
	
	public static <T> void sort(T[] datas,  Comparator<? super T> c) {
		sort(datas, c, 0, datas.length - 1);
	}
	
	
	public static <T> void swap(final T[] arr, final int pos1, final int pos2){
		  if (pos1 == pos2)
			  return;
		  
		  final T temp = arr[pos1];
		  
		  arr[pos1] = arr[pos2];
		  arr[pos2] = temp;
	}	
	
	public static  void swap(final int[] arr, final int pos1, final int pos2){
		  if (pos1 == pos2)
			  return;
		  
		  final int temp = arr[pos1];
		  
		  arr[pos1] = arr[pos2];
		  arr[pos2] = temp;
	}	
	
	public static  void sort(int[] datas, int i0, int j0) {
		if (j0 <= i0) {
			return;
		}
		
		int i = i0;
		int j = j0;
		int v = datas[(i+j)/2];
		while (i <= j) {
			while (i < j0 && datas[i] < v)
				++i;								 
			while (j > i0 && datas[j] > v)
				--j;

			if (i <= j)
			{
				swap(datas, i, j);

				++i;
				--j;
			}
		}

		sort(datas, i0, j);

		sort(datas, i, j0);
	}
	
	public static <T> void sort(T[] datas,  Comparator<? super T> c, int i0, int j0) {
		if (j0 <= i0) {
			return;
		}
		
		int i = i0;
		int j = j0;
		T v = datas[(i+j)/2];
		while (i <= j) {
			while (i < j0 && c.compare(datas[i], v) < 0)
				++i;								 
			while (j > i0 && c.compare(datas[j] , v) > 0)
				--j;

			if (i <= j)
			{
				swap(datas, i, j);

				++i;
				--j;
			}
		}

		sort(datas, c, i0, j);

		sort(datas, c, i, j0);
	}
	
}
