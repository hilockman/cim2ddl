package com.znd.bus.test.model;

public class Person {

	private String id;
	private String Name;
	private String Address;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public String getAddress() {
		return Address;
	}

	public void setAddress(String address) {
		Address = address;
	}

	@Override
	public String toString() {
		return "Person [id=" + id + ", Name=" + Name + ", Address=" + Address
				+ "]";
	}
}
