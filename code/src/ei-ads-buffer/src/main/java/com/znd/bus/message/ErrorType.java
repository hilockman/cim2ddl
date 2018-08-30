//
// 此文件是由 JavaTM Architecture for XML Binding (JAXB) 引用实现 v2.2.8-b130911.1802 生成的
// 请访问 <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// 在重新编译源模式时, 对此文件的所有修改都将丢失。
// 生成时间: 2018.08.30 时间 03:10:48 PM CST 
//


package com.znd.bus.message;

import java.math.BigInteger;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;
import javax.xml.bind.annotation.XmlValue;
import javax.xml.namespace.QName;


/**
 * Error Structure
 * 
 * <p>ErrorType complex type的 Java 类。
 * 
 * <p>以下模式片段指定包含在此类中的预期内容。
 * 
 * <pre>
 * &lt;complexType name="ErrorType">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="code" type="{http://www.w3.org/2001/XMLSchema}string"/>
 *         &lt;element name="level" minOccurs="0">
 *           &lt;simpleType>
 *             &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string">
 *               &lt;enumeration value="INFORM"/>
 *               &lt;enumeration value="WARNING"/>
 *               &lt;enumeration value="FATAL"/>
 *               &lt;enumeration value="CATASTROPHIC"/>
 *             &lt;/restriction>
 *           &lt;/simpleType>
 *         &lt;/element>
 *         &lt;element name="reason" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="details" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="xpath" type="{http://www.w3.org/2001/XMLSchema}QName" minOccurs="0"/>
 *         &lt;element name="stackTrace" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="Location" type="{http://iec.ch/TC57/2011/schema/message}LocationType" minOccurs="0"/>
 *         &lt;element name="ID" minOccurs="0">
 *           &lt;complexType>
 *             &lt;simpleContent>
 *               &lt;extension base="&lt;http://www.w3.org/2001/XMLSchema>string">
 *                 &lt;attGroup ref="{http://iec.ch/TC57/2011/schema/message}IDatts"/>
 *               &lt;/extension>
 *             &lt;/simpleContent>
 *           &lt;/complexType>
 *         &lt;/element>
 *         &lt;element name="relatedID" minOccurs="0">
 *           &lt;complexType>
 *             &lt;simpleContent>
 *               &lt;extension base="&lt;http://www.w3.org/2001/XMLSchema>string">
 *                 &lt;attGroup ref="{http://iec.ch/TC57/2011/schema/message}IDatts"/>
 *               &lt;/extension>
 *             &lt;/simpleContent>
 *           &lt;/complexType>
 *         &lt;/element>
 *         &lt;element name="object" type="{http://iec.ch/TC57/2011/schema/message}ObjectType" minOccurs="0"/>
 *         &lt;element name="operationId" type="{http://www.w3.org/2001/XMLSchema}integer" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "ErrorType", propOrder = {
    "code",
    "level",
    "reason",
    "details",
    "xpath",
    "stackTrace",
    "location",
    "id",
    "relatedID",
    "object",
    "operationId"
})
public class ErrorType {

    @XmlElement(required = true)
    protected String code;
    protected String level;
    protected String reason;
    protected String details;
    protected QName xpath;
    protected String stackTrace;
    @XmlElement(name = "Location")
    protected LocationType location;
    @XmlElement(name = "ID")
    protected ErrorType.ID id;
    protected ErrorType.RelatedID relatedID;
    protected ObjectType object;
    protected BigInteger operationId;

    /**
     * 获取code属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCode() {
        return code;
    }

    /**
     * 设置code属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCode(String value) {
        this.code = value;
    }

    /**
     * 获取level属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getLevel() {
        return level;
    }

    /**
     * 设置level属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setLevel(String value) {
        this.level = value;
    }

    /**
     * 获取reason属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReason() {
        return reason;
    }

    /**
     * 设置reason属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReason(String value) {
        this.reason = value;
    }

    /**
     * 获取details属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getDetails() {
        return details;
    }

    /**
     * 设置details属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setDetails(String value) {
        this.details = value;
    }

    /**
     * 获取xpath属性的值。
     * 
     * @return
     *     possible object is
     *     {@link QName }
     *     
     */
    public QName getXpath() {
        return xpath;
    }

    /**
     * 设置xpath属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link QName }
     *     
     */
    public void setXpath(QName value) {
        this.xpath = value;
    }

    /**
     * 获取stackTrace属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getStackTrace() {
        return stackTrace;
    }

    /**
     * 设置stackTrace属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setStackTrace(String value) {
        this.stackTrace = value;
    }

    /**
     * 获取location属性的值。
     * 
     * @return
     *     possible object is
     *     {@link LocationType }
     *     
     */
    public LocationType getLocation() {
        return location;
    }

    /**
     * 设置location属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link LocationType }
     *     
     */
    public void setLocation(LocationType value) {
        this.location = value;
    }

    /**
     * 获取id属性的值。
     * 
     * @return
     *     possible object is
     *     {@link ErrorType.ID }
     *     
     */
    public ErrorType.ID getID() {
        return id;
    }

    /**
     * 设置id属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link ErrorType.ID }
     *     
     */
    public void setID(ErrorType.ID value) {
        this.id = value;
    }

    /**
     * 获取relatedID属性的值。
     * 
     * @return
     *     possible object is
     *     {@link ErrorType.RelatedID }
     *     
     */
    public ErrorType.RelatedID getRelatedID() {
        return relatedID;
    }

    /**
     * 设置relatedID属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link ErrorType.RelatedID }
     *     
     */
    public void setRelatedID(ErrorType.RelatedID value) {
        this.relatedID = value;
    }

    /**
     * 获取object属性的值。
     * 
     * @return
     *     possible object is
     *     {@link ObjectType }
     *     
     */
    public ObjectType getObject() {
        return object;
    }

    /**
     * 设置object属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link ObjectType }
     *     
     */
    public void setObject(ObjectType value) {
        this.object = value;
    }

    /**
     * 获取operationId属性的值。
     * 
     * @return
     *     possible object is
     *     {@link BigInteger }
     *     
     */
    public BigInteger getOperationId() {
        return operationId;
    }

    /**
     * 设置operationId属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link BigInteger }
     *     
     */
    public void setOperationId(BigInteger value) {
        this.operationId = value;
    }


    /**
     * <p>anonymous complex type的 Java 类。
     * 
     * <p>以下模式片段指定包含在此类中的预期内容。
     * 
     * <pre>
     * &lt;complexType>
     *   &lt;simpleContent>
     *     &lt;extension base="&lt;http://www.w3.org/2001/XMLSchema>string">
     *       &lt;attGroup ref="{http://iec.ch/TC57/2011/schema/message}IDatts"/>
     *     &lt;/extension>
     *   &lt;/simpleContent>
     * &lt;/complexType>
     * </pre>
     * 
     * 
     */
    @XmlAccessorType(XmlAccessType.FIELD)
    @XmlType(name = "", propOrder = {
        "value"
    })
    public static class ID {

        @XmlValue
        protected String value;
        @XmlAttribute(name = "idType")
        protected String idType;
        @XmlAttribute(name = "idAuthority")
        protected String idAuthority;
        @XmlAttribute(name = "kind")
        protected IDKindType kind;
        @XmlAttribute(name = "objectType")
        protected String objectType;

        /**
         * 获取value属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getValue() {
            return value;
        }

        /**
         * 设置value属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setValue(String value) {
            this.value = value;
        }

        /**
         * 获取idType属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getIdType() {
            return idType;
        }

        /**
         * 设置idType属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setIdType(String value) {
            this.idType = value;
        }

        /**
         * 获取idAuthority属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getIdAuthority() {
            return idAuthority;
        }

        /**
         * 设置idAuthority属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setIdAuthority(String value) {
            this.idAuthority = value;
        }

        /**
         * 获取kind属性的值。
         * 
         * @return
         *     possible object is
         *     {@link IDKindType }
         *     
         */
        public IDKindType getKind() {
            return kind;
        }

        /**
         * 设置kind属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link IDKindType }
         *     
         */
        public void setKind(IDKindType value) {
            this.kind = value;
        }

        /**
         * 获取objectType属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getObjectType() {
            return objectType;
        }

        /**
         * 设置objectType属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setObjectType(String value) {
            this.objectType = value;
        }

    }


    /**
     * <p>anonymous complex type的 Java 类。
     * 
     * <p>以下模式片段指定包含在此类中的预期内容。
     * 
     * <pre>
     * &lt;complexType>
     *   &lt;simpleContent>
     *     &lt;extension base="&lt;http://www.w3.org/2001/XMLSchema>string">
     *       &lt;attGroup ref="{http://iec.ch/TC57/2011/schema/message}IDatts"/>
     *     &lt;/extension>
     *   &lt;/simpleContent>
     * &lt;/complexType>
     * </pre>
     * 
     * 
     */
    @XmlAccessorType(XmlAccessType.FIELD)
    @XmlType(name = "", propOrder = {
        "value"
    })
    public static class RelatedID {

        @XmlValue
        protected String value;
        @XmlAttribute(name = "idType")
        protected String idType;
        @XmlAttribute(name = "idAuthority")
        protected String idAuthority;
        @XmlAttribute(name = "kind")
        protected IDKindType kind;
        @XmlAttribute(name = "objectType")
        protected String objectType;

        /**
         * 获取value属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getValue() {
            return value;
        }

        /**
         * 设置value属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setValue(String value) {
            this.value = value;
        }

        /**
         * 获取idType属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getIdType() {
            return idType;
        }

        /**
         * 设置idType属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setIdType(String value) {
            this.idType = value;
        }

        /**
         * 获取idAuthority属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getIdAuthority() {
            return idAuthority;
        }

        /**
         * 设置idAuthority属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setIdAuthority(String value) {
            this.idAuthority = value;
        }

        /**
         * 获取kind属性的值。
         * 
         * @return
         *     possible object is
         *     {@link IDKindType }
         *     
         */
        public IDKindType getKind() {
            return kind;
        }

        /**
         * 设置kind属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link IDKindType }
         *     
         */
        public void setKind(IDKindType value) {
            this.kind = value;
        }

        /**
         * 获取objectType属性的值。
         * 
         * @return
         *     possible object is
         *     {@link String }
         *     
         */
        public String getObjectType() {
            return objectType;
        }

        /**
         * 设置objectType属性的值。
         * 
         * @param value
         *     allowed object is
         *     {@link String }
         *     
         */
        public void setObjectType(String value) {
            this.objectType = value;
        }

    }

}
