
#include "GraphSvgRW.h"
#include "GFunc.h"
#define NOVALUE -1

CGraphSvgReader::CGraphSvgReader(QIODevice* device):QObject(0),QXmlStreamReader(device){}
CGraphSvgReader::CGraphSvgReader(const QString & data) : QObject(0),QXmlStreamReader(data){}

bool CGraphSvgReader::Open(const QString& absPathFile)
{
    QFile* file=new QFile(absPathFile,this);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, tr("File"), tr("Open file failed! Please sure is file exised and has authority."));
        return false;
    }
    setDevice(file);
    return true;
}

QTransform CGraphSvgReader::GetTransformsFromSVG( QString& SVGTransform)
{
    QTransform ret;
    if(SVGTransform.at(0)=='m'){
        SVGTransform.remove(0,7).chop(1);
        QStringList matrix = SVGTransform.split(",");
        if(matrix.size()==6)
           ret = QTransform(matrix[0].toDouble(), matrix[2].toDouble(), matrix[4].toDouble(), matrix[1].toDouble(), matrix[3].toDouble(), matrix[5].toDouble(),0,0).transposed();
    }
    return ret;
}

int CGraphSvgReader::ReadNextStartElement()
{
    int ret=readNextStartElement();
    m_Attrs=attributes();
    return ret;
}

QVariant CGraphSvgReader::ReadAttribute(const QString& qualifiedName)
{
    return m_Attrs.value(qualifiedName).toString();
}

QVariantMap CGraphSvgReader::ReadAttributes(const QString & namespaceUri)
{
	QVariantMap attrs;
    foreach(QXmlStreamAttribute attr,m_Attrs)
    {
        if(attr.namespaceUri()==namespaceUri)
            attrs[attr.name().toString()]=attr.value().toString();
    }
    return attrs;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, int& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
	AttrValue = ref.toInt();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, uint& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
	AttrValue = ref.toUInt();
	return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, short& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
    AttrValue=ref.toShort();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QBitArray& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE; 

	AttrValue.resize(ref.size());
	for (int i = 0; i<ref.size(); i++)
        ref.at(i) == '1' ? AttrValue.setBit(i) : AttrValue.setBit(i, false);

    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QString& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
	AttrValue = ref.toString();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, qreal& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
    AttrValue=ref.toDouble();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, bool& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
    AttrValue=ref.toInt();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, char& AttrValue )
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;

	AttrValue = ref.at(0).unicode();
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, float& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
    AttrValue=ref.toFloat();
    return 0;
}

int CGraphSvgReader::ReadAttribute( const QString& qualifiedName, QColor& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;

	AttrValue.setNamedColor(ref.toString());
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QTransform& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
    AttrValue =QTransform( UnqFunc()->parseTransformationMatrix(ref));
    //AttrValue = GetTransformsFromSVG(ref.toString());
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QPolygonF& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;

    const QChar *s = ref.constData();
    QVector<qreal> points = UnqFunc()->parseNumbersList(s);
    AttrValue.resize(points.count()/2);
    for (int i = 0; i < AttrValue.size(); ++i)
        AttrValue[i] = QPointF(points.at(2 * i), points.at(2 * i + 1));

    /*
	QStringList PointList = ref.toString().split(" ", QString::SkipEmptyParts);
    for (int i = 0;i<PointList.size();i++)
    {
        QStringList point = PointList[i].split(",");
        if (point.size() == 2)
        {
            AttrValue<<QPointF(point[0].toDouble(),point[1].toDouble());
        }
    }*/
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QRectF& AttrValue)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
 
	QStringList rectList = ref.toString().split(",", QString::SkipEmptyParts);
    Q_ASSERT(rectList.size() == 4);
    AttrValue.setRect(rectList[0].toInt(),rectList[1].toInt(),rectList[2].toInt(),rectList[3].toInt());
    return 0;
}

int CGraphSvgReader::ReadAttribute(const QString& qualifiedName, QStringList& variant)
{
	QStringRef ref = m_Attrs.value(qualifiedName);
    if (ref.isEmpty())
		return NOVALUE;
 
    variant= ref.toString().split(",",QString::SkipEmptyParts);
    return 0;
}

int CGraphSvgReader::ReadAttribute( const QString& qualifiedName, QFont& font, Hmi::SaveType type )
{
    QString familyAttrName, sizeAtrrName, weightAttrName, styleAttrName, textDecoratAttrName;

    familyAttrName = "font-family";
    sizeAtrrName = "font-size";
    weightAttrName = "font-weight";
    styleAttrName = "font-style";
    textDecoratAttrName = "text-decoration";

    QString family;
    if( ReadAttribute(familyAttrName,family) == 0 ) font.setFamily(family);

    qreal size;
	if (ReadAttribute(sizeAtrrName, size) == 0) font.setPointSizeF(size);

    int weight;
	if (ReadAttribute(weightAttrName, weight) == 0) font.setWeight(weight / 11);

    QString style;
    if (ReadAttribute(styleAttrName, style) == 0) font.setStyleName( style );

    QString dec ;
    if (ReadAttribute(textDecoratAttrName , dec) == 0)
	{
        if(dec.indexOf("line-")>=0) font.setStrikeOut(true);
        if(dec.indexOf("under")>=0) font.setUnderline(true);

	}
    return 0;
}



///////////////
/// \brief CGraphSvgWriter::CGraphSvgWriter

bool CGraphSvgWriter::Open(const QString& absPathFile)
{
    QFile* file=new QFile(absPathFile,this);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, tr("File"), tr("Open file failed! Please sure is file exised and has authority."));
        return false;
    }
    setDevice(file);
    setAutoFormatting(true);
    return true;
}

CGraphSvgWriter::CGraphSvgWriter( ):QObject(0),QXmlStreamWriter( )
{
    setCodec( QTextCodec::codecForName(LOCAL_LANGUAGE));
    m_IsClosed=false;
}

CGraphSvgWriter::CGraphSvgWriter(QIODevice* device):QObject(0),QXmlStreamWriter(device)
{
    setCodec( QTextCodec::codecForName(LOCAL_LANGUAGE));
    m_IsClosed=false;
}

CGraphSvgWriter::~CGraphSvgWriter()
{
    if(!m_IsClosed){
        writeEndElement();
        writeEndDocument();
    }
}

int CGraphSvgWriter::Init()
{
    setAutoFormatting(true);
    writeStartDocument();
    writeStartElement("svg");
    writeNamespace(POWERHMIURI,POWERHMIURI);
    writeNamespace(CUSTOMURI,CUSTOMURI);
    writeNamespace("QT","QT");
    writeNamespace("http://www.w3.org/2000/svg","svg");
    writeNamespace("http://www.w3.org/1999/xlink","xlink");
    writeAttribute("xmlns","http://www.w3.org/2000/svg");
    return 0;
}

int CGraphSvgWriter::WriteAttributes(const QMap<QString,QString>& attrs)
{
    foreach (const QString &attrName, attrs.keys())
        writeAttribute(attrName, attrs.value(attrName));
    return 0;
}

int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QString& variant, Hmi::SaveType type)
{
	if (variant.isEmpty())
		return 0;
    if (type == Hmi::PowerHmi)
    {
        writeAttribute(POWERHMIURI, AttrName, variant);
    }
    else
    {
        writeAttribute(AttrName, variant);
    }
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QBitArray& variant, Hmi::SaveType type)
{
	if (variant.isEmpty())
		return 0;
    QString varStr;
    for (int i = 0;i<variant.size();i++)
        variant.testBit(i) ? varStr.append("1") : varStr.append("0");

    if (Hmi::PowerHmi == type)
        writeAttribute(POWERHMIURI,AttrName, varStr);
    else
        writeAttribute(AttrName, varStr);

    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, qreal variant, Hmi::SaveType type)
{
    if (type == Hmi::PowerHmi)
        writeAttribute(POWERHMIURI, AttrName, QString("%1").arg(variant));
    else
        writeAttribute(AttrName, QString("%1").arg(variant));
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName,  int variant, Hmi::SaveType type)
{
    if (type == Hmi::PowerHmi)
    {
        writeAttribute(POWERHMIURI, AttrName, QString("%1").arg(variant));
    }
    else
    {
        writeAttribute(AttrName, QString("%1").arg(variant));
    }
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName,  uint variant, Hmi::SaveType type)
{
	if (type == Hmi::PowerHmi)
	{
		writeAttribute(POWERHMIURI, AttrName, QString("%1").arg(variant));
	}
	else
	{
		writeAttribute(AttrName, QString("%1").arg(variant));
	}
	return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QColor& variant)
{
    writeAttribute(AttrName, variant.name());
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QTransform& variant)
{
    WriteSceneTransform(AttrName,variant);
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QPolygonF& variant)
{
    QString points;
    QTextStream oss(&points);
    for(int i = 0;i < variant.size();i++)
    {
        if (i != 0)
        {
            oss<<" ";
        }
        oss<<variant[i].x()<<","<<variant[i].y();
    }
    writeAttribute(AttrName,oss.readAll());
    return 1;
}
int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QRectF& variant)
{
    QString rectf;
    QTextStream oss(&rectf);
    oss<<variant.x()<<","<<variant.y()<<","<<variant.width()<<","<<variant.height();
    writeAttribute(AttrName,oss.readAll());
    return 1;
}

int CGraphSvgWriter::WriteAttribute( const QString& AttrName, const QSize& variant )
{
    QString sizef;
    QTextStream oss(&sizef);
    oss<<variant.width()<<","<<variant.height();
    writeAttribute(AttrName,oss.readAll());
    return 1;
}

bool CGraphSvgWriter::WriteSceneTransform(const QString& AttrName,const QTransform& transform)
{
    QTransform SVGTransMatrix(transform.m11(),transform.m21(),transform.m31(),transform.m12(),transform.m22(),transform.m32(),transform.m13(),transform.m23(),transform.m33());
    writeAttribute(AttrName,QString("matrix(%1,%2,%3,%4,%5,%6)").arg(SVGTransMatrix.m11()).arg(SVGTransMatrix.m21()).arg(SVGTransMatrix.m12()).arg(SVGTransMatrix.m22()).arg(SVGTransMatrix.m13()).arg(SVGTransMatrix.m23()));
    return true;
}

int CGraphSvgWriter::WriteAttribute(const QString& AttrName, const QStringList& variant)
{
    QString tmpStr=variant.join(",");
    writeAttribute(AttrName,tmpStr);
    return 1;
}


int CGraphSvgWriter::WriteAttribute( const QString& AttrName, const QFont& font, Hmi::SaveType type )
{
    QString familyAttrName, sizeAtrrName, weightAttrName, styleAttrName, textDecoratAttrName;

    familyAttrName = "font-family";
    sizeAtrrName = "font-size";
    weightAttrName = "font-weight";
    styleAttrName = "font-style";
    textDecoratAttrName = "text-decoration";

    WriteAttribute(familyAttrName, font.family());
	WriteAttribute(sizeAtrrName, font.pointSizeF()<0 ? font.pixelSize():font.pointSizeF());
    WriteAttribute(weightAttrName,font.weight()*11);
    QString stylename=font.styleName();
    if(stylename!="normal")
        WriteAttribute(styleAttrName,font.styleName());

    QString decSvg ;
    if (font.strikeOut())
    {
        decSvg += "line-through";
    }
    if (font.underline())
    {
        decSvg += " underline";
    }

    if(!decSvg.isEmpty())
    {
        WriteAttribute(textDecoratAttrName, decSvg );
    }

    return 0;
}

int CGraphSvgWriter::WriteFillPattern(const QBrush& brush)
{
    switch (brush.style())
    {
    case Qt::SolidPattern:
        writeAttribute("fill",brush.color().name());
        break;
    case Qt::HorPattern:
    default:
        break;
    }

    return 0;
}


bool CGraphSvgWriter::WriteFillInfo(const QBrush& brush)
{
    writeAttribute("fill",QString("%1").arg(brush.color().name()));
    writeAttribute(POWERHMIURI,"fill-pattern",QString("%1").arg(brush.style()));
    WriteFillPattern(brush);
    return true;
}
