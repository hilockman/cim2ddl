package org.test.java;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestObjectIO {

	public static void main(String [] args) throws IOException, ClassNotFoundException {
		FileOutputStream fos = new FileOutputStream("d:/test/testjava/data/tesetobjectio.dat");
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		T t = new T();
		t.i = 100;
		oos.writeObject(t);
		oos.flush();
		oos.close();
		
		FileInputStream fis = new FileInputStream("d:/test/testjava/data/tesetobjectio.dat");
		
		ObjectInputStream ois = new ObjectInputStream(fis);
		T t1 = (T) ois.readObject();
		
		System.out.println(t1);
		ois.close();
	}
}


class T implements Serializable {

	int i = 80;
	int j = 90;
	String name = "fdsfsd";
	int k = 15;
	
	@Override
	public String toString() {
		return "T [i=" + i + ", j=" + j + ", name=" + name + ", k=" + k + "]";
	}
	public int getI() {
		return i;
	}
	public void setI(int i) {
		this.i = i;
	}
	public int getJ() {
		return j;
	}
	public void setJ(int j) {
		this.j = j;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getK() {
		return k;
	}
	public void setK(int k) {
		this.k = k;
	}
}