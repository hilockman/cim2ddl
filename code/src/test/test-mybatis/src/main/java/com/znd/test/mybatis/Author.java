package com.znd.test.mybatis;

import java.sql.Date;

public class Author {

    public Author(Integer id, String name, String sex, Date birthday, String address) {
		super();
		this.id = id;
		this.name = name;
		this.sex = sex;
		this.birthday = birthday;
		this.address = address;
	}
    
	public Author(String name, String sex, Date birthday, String address) {
		this(null,  name, sex, birthday, address);
	}
	//属性名要和数据库表的字段对应
    private Integer id;
    private String name;// 用户姓名
    private String sex;// 性别
    private Date birthday;// 生日
    private String address;// 地址
	public Integer getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public Date getBirthday() {
		return birthday;
	}
	public void setBirthday(Date birthday) {
		this.birthday = birthday;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	@Override
	public String toString() {
		return "Author [id=" + id + ", name=" + name + ", sex=" + sex
				+ ", birthday=" + birthday + ", address=" + address + "]";
	}
}
