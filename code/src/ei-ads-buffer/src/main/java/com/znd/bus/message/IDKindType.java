//
// 此文件是由 JavaTM Architecture for XML Binding (JAXB) 引用实现 v2.2.8-b130911.1802 生成的
// 请访问 <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// 在重新编译源模式时, 对此文件的所有修改都将丢失。
// 生成时间: 2018.08.30 时间 03:10:48 PM CST 
//


package com.znd.bus.message;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>IDKindType的 Java 类。
 * 
 * <p>以下模式片段指定包含在此类中的预期内容。
 * <p>
 * <pre>
 * &lt;simpleType name="IDKindType">
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string">
 *     &lt;enumeration value="name"/>
 *     &lt;enumeration value="uuid"/>
 *     &lt;enumeration value="transaction"/>
 *     &lt;enumeration value="other"/>
 *   &lt;/restriction>
 * &lt;/simpleType>
 * </pre>
 * 
 */
@XmlType(name = "IDKindType")
@XmlEnum
public enum IDKindType {

    @XmlEnumValue("name")
    NAME("name"),
    @XmlEnumValue("uuid")
    UUID("uuid"),
    @XmlEnumValue("transaction")
    TRANSACTION("transaction"),
    @XmlEnumValue("other")
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
