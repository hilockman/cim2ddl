//
// 此文件是由 JavaTM Architecture for XML Binding (JAXB) 引用实现 v2.2.8-b130911.1802 生成的
// 请访问 <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// 在重新编译源模式时, 对此文件的所有修改都将丢失。
// 生成时间: 2018.08.30 时间 03:10:48 PM CST 
//


package com.znd.bus.message;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAnyElement;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;
import javax.xml.datatype.XMLGregorianCalendar;
import org.w3c.dom.Element;


/**
 * Message header type definition
 * 
 * <p>HeaderType complex type的 Java 类。
 * 
 * <p>以下模式片段指定包含在此类中的预期内容。
 * 
 * <pre>
 * &lt;complexType name="HeaderType">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="Verb">
 *           &lt;simpleType>
 *             &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string">
 *               &lt;enumeration value="cancel"/>
 *               &lt;enumeration value="canceled"/>
 *               &lt;enumeration value="change"/>
 *               &lt;enumeration value="changed"/>
 *               &lt;enumeration value="create"/>
 *               &lt;enumeration value="created"/>
 *               &lt;enumeration value="close"/>
 *               &lt;enumeration value="closed"/>
 *               &lt;enumeration value="delete"/>
 *               &lt;enumeration value="deleted"/>
 *               &lt;enumeration value="get"/>
 *               &lt;enumeration value="reply"/>
 *               &lt;enumeration value="execute"/>
 *               &lt;enumeration value="executed"/>
 *             &lt;/restriction>
 *           &lt;/simpleType>
 *         &lt;/element>
 *         &lt;element name="Noun" type="{http://www.w3.org/2001/XMLSchema}string"/>
 *         &lt;element name="Revision" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="ReplayDetection" type="{http://iec.ch/TC57/2011/schema/message}ReplayDetectionType" minOccurs="0"/>
 *         &lt;element name="Context" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="Timestamp" type="{http://www.w3.org/2001/XMLSchema}dateTime" minOccurs="0"/>
 *         &lt;element name="Source" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="AsyncReplyFlag" type="{http://www.w3.org/2001/XMLSchema}boolean" minOccurs="0"/>
 *         &lt;element name="ReplyAddress" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="AckRequired" type="{http://www.w3.org/2001/XMLSchema}boolean" minOccurs="0"/>
 *         &lt;element name="User" type="{http://iec.ch/TC57/2011/schema/message}UserType" minOccurs="0"/>
 *         &lt;element name="MessageID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="CorrelationID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="Comment" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="Property" type="{http://iec.ch/TC57/2011/schema/message}MessageProperty" maxOccurs="unbounded" minOccurs="0"/>
 *         &lt;any processContents='lax' namespace='##other' maxOccurs="unbounded" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "HeaderType", propOrder = {
    "verb",
    "noun",
    "revision",
    "replayDetection",
    "context",
    "timestamp",
    "source",
    "asyncReplyFlag",
    "replyAddress",
    "ackRequired",
    "user",
    "messageID",
    "correlationID",
    "comment",
    "property",
    "any"
})
public class HeaderType {

    @XmlElement(name = "Verb", required = true)
    protected String verb;
    @XmlElement(name = "Noun", required = true)
    protected String noun;
    @XmlElement(name = "Revision")
    protected String revision;
    @XmlElement(name = "ReplayDetection")
    protected ReplayDetectionType replayDetection;
    @XmlElement(name = "Context")
    protected String context;
    @XmlElement(name = "Timestamp")
    @XmlSchemaType(name = "dateTime")
    protected XMLGregorianCalendar timestamp;
    @XmlElement(name = "Source")
    protected String source;
    @XmlElement(name = "AsyncReplyFlag")
    protected Boolean asyncReplyFlag;
    @XmlElement(name = "ReplyAddress")
    protected String replyAddress;
    @XmlElement(name = "AckRequired")
    protected Boolean ackRequired;
    @XmlElement(name = "User")
    protected UserType user;
    @XmlElement(name = "MessageID")
    protected String messageID;
    @XmlElement(name = "CorrelationID")
    protected String correlationID;
    @XmlElement(name = "Comment")
    protected String comment;
    @XmlElement(name = "Property")
    protected List<MessageProperty> property;
    @XmlAnyElement(lax = true)
    protected List<Object> any;

    /**
     * 获取verb属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getVerb() {
        return verb;
    }

    /**
     * 设置verb属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setVerb(String value) {
        this.verb = value;
    }

    /**
     * 获取noun属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getNoun() {
        return noun;
    }

    /**
     * 设置noun属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setNoun(String value) {
        this.noun = value;
    }

    /**
     * 获取revision属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getRevision() {
        return revision;
    }

    /**
     * 设置revision属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setRevision(String value) {
        this.revision = value;
    }

    /**
     * 获取replayDetection属性的值。
     * 
     * @return
     *     possible object is
     *     {@link ReplayDetectionType }
     *     
     */
    public ReplayDetectionType getReplayDetection() {
        return replayDetection;
    }

    /**
     * 设置replayDetection属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link ReplayDetectionType }
     *     
     */
    public void setReplayDetection(ReplayDetectionType value) {
        this.replayDetection = value;
    }

    /**
     * 获取context属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getContext() {
        return context;
    }

    /**
     * 设置context属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setContext(String value) {
        this.context = value;
    }

    /**
     * 获取timestamp属性的值。
     * 
     * @return
     *     possible object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public XMLGregorianCalendar getTimestamp() {
        return timestamp;
    }

    /**
     * 设置timestamp属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public void setTimestamp(XMLGregorianCalendar value) {
        this.timestamp = value;
    }

    /**
     * 获取source属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSource() {
        return source;
    }

    /**
     * 设置source属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSource(String value) {
        this.source = value;
    }

    /**
     * 获取asyncReplyFlag属性的值。
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isAsyncReplyFlag() {
        return asyncReplyFlag;
    }

    /**
     * 设置asyncReplyFlag属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setAsyncReplyFlag(Boolean value) {
        this.asyncReplyFlag = value;
    }

    /**
     * 获取replyAddress属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReplyAddress() {
        return replyAddress;
    }

    /**
     * 设置replyAddress属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReplyAddress(String value) {
        this.replyAddress = value;
    }

    /**
     * 获取ackRequired属性的值。
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isAckRequired() {
        return ackRequired;
    }

    /**
     * 设置ackRequired属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setAckRequired(Boolean value) {
        this.ackRequired = value;
    }

    /**
     * 获取user属性的值。
     * 
     * @return
     *     possible object is
     *     {@link UserType }
     *     
     */
    public UserType getUser() {
        return user;
    }

    /**
     * 设置user属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link UserType }
     *     
     */
    public void setUser(UserType value) {
        this.user = value;
    }

    /**
     * 获取messageID属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMessageID() {
        return messageID;
    }

    /**
     * 设置messageID属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMessageID(String value) {
        this.messageID = value;
    }

    /**
     * 获取correlationID属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCorrelationID() {
        return correlationID;
    }

    /**
     * 设置correlationID属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCorrelationID(String value) {
        this.correlationID = value;
    }

    /**
     * 获取comment属性的值。
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getComment() {
        return comment;
    }

    /**
     * 设置comment属性的值。
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setComment(String value) {
        this.comment = value;
    }

    /**
     * Gets the value of the property property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the property property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getProperty().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link MessageProperty }
     * 
     * 
     */
    public List<MessageProperty> getProperty() {
        if (property == null) {
            property = new ArrayList<MessageProperty>();
        }
        return this.property;
    }

    /**
     * Gets the value of the any property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the any property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getAny().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link Object }
     * {@link Element }
     * 
     * 
     */
    public List<Object> getAny() {
        if (any == null) {
            any = new ArrayList<Object>();
        }
        return this.any;
    }

}
