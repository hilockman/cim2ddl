

#ifndef GRAPHSVGREADER_H
#define GRAPHSVGREADER_H 

#include <QtSvg>
#include "Global.h"

const QString POWERHMIURI="PH";
const QString CUSTOMURI="CP";

class DLL_CLASS CGraphSvgReader:public QObject,public  QXmlStreamReader
{
    Q_OBJECT
public:
    explicit CGraphSvgReader(QObject *parent = 0):QObject(parent),QXmlStreamReader(){};
    CGraphSvgReader(QIODevice* device);
	CGraphSvgReader(const QString & data);
     int ReadAttribute(const QString& qualifiedName, QString& variant);
     int ReadAttribute(const QString& qualifiedName, qreal& variant);
     int ReadAttribute(const QString& qualifiedName, int& variant);
     int ReadAttribute(const QString& qualifiedName, uint& variant);
     int ReadAttribute(const QString& qualifiedName, short& variant);
     int ReadAttribute(const QString& qualifiedName, QColor& variant);
     int ReadAttribute(const QString& qualifiedName, QTransform& variant);
     int ReadAttribute(const QString& qualifiedName, QPolygonF& variant);
    //inline int ReadAttribute(const QString& qualifiedName, QPolygon& variant);
     int ReadAttribute(const QString& qualifiedName, QRectF& AttrValue);
     int ReadAttribute(const QString& qualifiedName, QStringList& variant);
     int ReadAttribute(const QString& qualifiedName, bool& variant);
     int ReadAttribute(const QString& qualifiedName, QFont& font, Hmi::SaveType type);
     int ReadAttribute(const QString& qualifiedName, char& variant);
     int ReadAttribute(const QString& qualifiedName, float& variant);
     int ReadAttribute(const QString& qualifiedName, QBitArray& AttrValue);
    QXmlStreamAttributes& Attributes(){return m_Attrs;};

public slots:
    bool Open(const QString& absPathFile);
    int ReadNextStartElement();
    QVariant ReadAttribute(const QString& qualifiedName);
    QVariantMap ReadAttributes(const QString & namespaceUri);
    QString Name(){return name().toString();};
    void SkipCurrentElement()   {skipCurrentElement();};
    QString ReadElementText()   {return readElementText();};

private:
    inline QTransform GetTransformsFromSVG( QString& SVGTransform);
    QXmlStreamAttributes m_Attrs;
};

class DLL_CLASS CGraphSvgWriter:public QObject,public QXmlStreamWriter
{
    Q_OBJECT
public slots:
    bool Open(const QString& absPathFile);
    void WriteStartDocument(const QString &version="1.0", bool standalone="yes"){ writeStartDocument( version, standalone);};
    void WriteEndDocument() { writeEndDocument();};
    void WriteStartElement(const QString &qualifiedName){  writeStartElement( qualifiedName); };
    void WriteEndElement()      { writeEndElement();m_IsClosed=true;};
    void WriteNamespace(const QString &namespaceUri, const QString &prefix = QString()){writeNamespace(namespaceUri,prefix);};
    int  WriteAttribute(const QString& AttrName, const QString& variant, Hmi::SaveType type = Hmi::SVG);
    void WriteCharacters(const QString &text){ writeCharacters( text);};
public:
    CGraphSvgWriter();
    CGraphSvgWriter(QIODevice* device);
    ~CGraphSvgWriter();
    enum SAVE_TYPE {PIC, ICON, CFG, TMP};
    int Init();    
    int WriteAttribute(const QString& AttrName, qreal variant, Hmi::SaveType type = Hmi::SVG);
    int WriteAttribute(const QString& AttrName, int variant, Hmi::SaveType type = Hmi::SVG);
    int WriteAttribute(const QString& AttrName, uint variant, Hmi::SaveType type = Hmi::SVG);
    int WriteAttribute(const QString& AttrName, const QFont& font, Hmi::SaveType type = Hmi::SVG);

    int WriteAttribute(const QString& AttrName, const QColor& variant);
    int WriteAttribute(const QString& AttrName, const QTransform& variant);
    int WriteAttribute(const QString& AttrName, const QRectF& variant);
    int WriteAttribute(const QString& AttrName, const QSize& variant);
    int WriteAttribute(const QString& AttrName, const QPolygonF& variant);
    int WriteAttribute(const QString& AttrName, const QStringList& variant);
    int WriteAttribute(const QString& AttrName, const QBitArray& variant, Hmi::SaveType type);
    int WriteAttributes(const QMap<QString,QString>& attrs);
    void SetSvgType(Hmi::SaveType type){m_SvgType = type;};
    Hmi::SaveType GetSvgType(){return m_SvgType;};

private:
    Hmi::SaveType m_SvgType;
    bool WriteSceneTransform(const QString& AttrName, const QTransform& transform);
    bool WriteFillInfo(const QBrush& brush);
    int WriteFillPattern(const QBrush& brush);
    int WritePolygonF(const QString& attrName,const QPolygonF& poloygon);
    int WritePolygon(const QString& attrName,const QPolygon& poloygon);
    bool m_IsClosed;

};
#endif
