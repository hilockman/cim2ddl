//
// 此文件是由 JavaTM Architecture for XML Binding (JAXB) 引用实现 v2.2.8-b130911.1802 生成的
// 请访问 <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// 在重新编译源模式时, 对此文件的所有修改都将丢失。
// 生成时间: 2018.08.30 时间 03:10:48 PM CST 
//


package com.znd.bus.server.message;




public enum IDKindType {

    NAME("name"),
    UUID("uuid"),
    TRANSACTION("transaction"),
    OTHER("other");
    private final String value;

    IDKindType(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static IDKindType fromValue(String v) {
        for (IDKindType c: IDKindType.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
