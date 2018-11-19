
#include <QAbstractTableModel>
#include <KDChartChart>
#include <KDChartPieDiagram>
#include <KDChartBarDiagram>
#include <KDChartStockDiagram>
#include <KDChartPieAttributes>
#include <KDChartBarAttributes>
#include <KDChartStockBarAttributes>
#include <KDChartBackgroundAttributes>
#include <KDChartPolarCoordinatePlane>
#include <KDChartThreeDPieAttributes>
#include <KDChartThreeDBarAttributes>
#include <KDChartDataValueAttributes>
#include <KDChartPosition>
#include <KDChartTextAttributes>
#include <KDChartMarkerAttributes>
#include <QItemSelectionModel>
#include "ChartWrap.h"
#include "BaseData.h"
#include "Global.h"
#include "ChartTableModel.h"
#include "GraphSvgRW.h"

using namespace KDChart;

CBaseChartData::CBaseChartData( QGraphicsItem* item ) : CWidgetData(item)
{
    SetItem(item);
}

void CBaseChartData::SaveBaseProperty( CGraphSvgWriter* xio ) const
{
    QAbstractItemModel* model = GetDiagram()->model();
    xio->WriteAttribute("isShow3D", GetIsShow3D());
    xio->WriteAttribute("isShowData", GetIsShowData());
    xio->WriteAttribute("dataFont", GetDataFont());
    xio->WriteAttribute("dataColor", GetDataColor());
    xio->WriteAttribute("modelRow", model->rowCount());
    xio->WriteAttribute("modelColumn", model->columnCount());
    CWidgetData::SaveBaseProperty(xio);

}

void CBaseChartData::SaveSubProperty( CGraphSvgWriter* xio ) const
{
    AbstractDiagram* diagram = GetDiagram();
    QAbstractItemModel* model = diagram->model();
    for(int row=0; row<model->rowCount(); ++row)
    {
        QString modelData;
        for(int col=0; col<model->columnCount(); ++col)
        {
            QTextStream oss(&modelData);
            oss<<model->data(model->index(row, col), Qt::EditRole).toString()<<","<<diagram->brush(model->index(row, col)).color().name()<<" ";
        }
      //  qDebug()<<"modelData:"<<modelData;
        xio->writeStartElement("data");
        xio->WriteAttribute("modelData", modelData);
        xio->writeEndElement();
    }
}

void CBaseChartData::LoadBaseProperty( CGraphSvgReader* xio )
{
    QAbstractItemModel* model = GetDiagram()->model();
    bool isShow3D, isShowData;
    int modelRow, modelColumn;
    QFont f;
    QColor c;
    xio->ReadAttribute("isShow3D", isShow3D);
    xio->ReadAttribute("isShowData", isShowData);
    xio->ReadAttribute("dataFont", f, Hmi::SVG);
    xio->ReadAttribute("dataColor", c);
    xio->ReadAttribute("modelRow", modelRow);
    xio->ReadAttribute("modelColumn", modelColumn);
    CWidgetData::LoadBaseProperty(xio);

    SetShow3D(isShow3D);
    SetShowData(isShowData);
    SetDataFont(f);
    SetDataColor(c);

    ((CChartTableModel*)model)->clear();
    model->insertRows(0, modelRow);
    model->insertColumns(0, modelColumn);
}

void CBaseChartData::LoadSubProperty( CGraphSvgReader* xio )
{
    AbstractDiagram* diagram = GetDiagram();
    QAbstractItemModel* model = diagram->model();
    QStringList dataList;
    int rowCnt=0;
    while (xio->readNextStartElement())
    {
        if(xio->name() == "data")
        {
            QString modelData;
            dataList<<QString();
            xio->ReadAttribute("modelData",dataList[rowCnt++]);
        }
        xio->skipCurrentElement();
    }

	const bool isPieDiagram = (g_dataPtr(Item())->Type() == Hmi::PieWidget);
    Q_ASSERT(dataList.size() == model->rowCount());
    for(int row=0; row<model->rowCount(); ++row)
    {
        QStringList rowList = dataList[row].split(' ', QString::SkipEmptyParts);
        Q_ASSERT(rowList.size() == model->columnCount());
        for(int col=0; col<model->columnCount(); ++col)
        {
            const QModelIndex index = model->index(row, col);
            QStringList valAndColor = rowList[col].split(',', QString::SkipEmptyParts);
            model->setData(index, valAndColor[0], Qt::EditRole);
            if(isPieDiagram)
                diagram->setPen(index, QPen(QColor(valAndColor[1])));
            diagram->setBrush(index, QBrush(QColor(valAndColor[1])));
        }
    }

}

void CBaseChartData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CWidgetData::GetPropertyList(property_list);
    property_list.push_back(qMakePair(QObject::tr("Show3D"), QVariant(GetIsShow3D())));
    property_list.push_back(qMakePair(QObject::tr("ShowData"), QVariant(GetIsShowData())));
    property_list.push_back(qMakePair(QObject::tr("DataFont"), QVariant(GetDataFont())));
    property_list.push_back(qMakePair(QObject::tr("DataColor"), QVariant(GetDataColor())));
}

bool CBaseChartData::SetProperty( const QString& propname,const QVariant& value )
{
    if(QObject::tr("Show3D") == propname)
        SetShow3D(value.toBool());
    else if(QObject::tr("ShowData") == propname)
        SetShowData(value.toBool());
    else if(QObject::tr("DataFont") == propname)
        SetDataFont(value.value<QFont>());
    else if(QObject::tr("DataColor") == propname)
        SetDataColor(value.value<QColor>());
    else
        return CWidgetData::SetProperty(propname, value);

    GetDiagram()->update();
    return true;
}

#define G_GEGDATAMARO \
    AbstractDiagram* diagram = GetDiagram();\
    DataValueAttributes dva = diagram->dataValueAttributes();\
    TextAttributes ta = dva.textAttributes()

#define G_SETDATAMARO \
    dva.setTextAttributes(ta); \
    diagram->setDataValueAttributes(dva)

bool CBaseChartData::GetIsShowData() const
{
    G_GEGDATAMARO;
    return ta.isVisible()&&dva.isVisible();
}

void CBaseChartData::SetShowData( bool show )
{
    G_GEGDATAMARO;
    ta.setVisible(show);
    dva.setVisible(true);
    G_SETDATAMARO;
}

QFont CBaseChartData::GetDataFont() const
{
    G_GEGDATAMARO;
    return ta.font();
}

void CBaseChartData::SetDataFont( const QFont& f )
{
    G_GEGDATAMARO;
    ta.setFont(f);
    ta.setFontSize(Measure(f.pointSizeF()));
    G_SETDATAMARO;

}

QColor CBaseChartData::GetDataColor() const
{
    G_GEGDATAMARO;
    return ta.pen().color();
}

void CBaseChartData::SetDataColor( const QColor& c )
{
    G_GEGDATAMARO;
    QPen p = ta.pen();
    p.setColor(c);
    ta.setPen(p);
    G_SETDATAMARO;
}

CBaseChartWidget::CBaseChartWidget()
    :KDChart::Chart(), m_model(new CChartTableModel(this)), m_selectModel(new QItemSelectionModel(m_model,this))
{
    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(QColor(Qt::transparent)));
    setPalette(pal);

}

CBaseChartWidget::~CBaseChartWidget()
{
    //delete m_selectModel;
    //delete m_model;
}

void CBaseChartWidget::OnItemClicked( const QModelIndex& index )
{
    //qDebug("CBaseChartWidget::OnItemClicked");
}






CPieChartData::CPieChartData( QGraphicsItem* item ) : CBaseChartData(item)
{
    SetItem(item);
}

void CPieChartData::SaveBaseProperty( CGraphSvgWriter* xio ) const
{
    xio->WriteAttribute("isExplode", GetIsExplode());
    CBaseChartData::SaveBaseProperty(xio);
}

void CPieChartData::LoadBaseProperty( CGraphSvgReader* xio )
{
    bool isExplode;
    xio->ReadAttribute("isExplode", isExplode);
    CBaseChartData::LoadBaseProperty(xio);

    SetExplode(isExplode);
}

QGraphicsItem* CPieChartData::Clone()
{

    return NULL;
}

void CPieChartData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CBaseChartData::GetPropertyList(property_list);
    property_list.push_back( qMakePair( QString(QObject::tr("IsExplode")) ,QVariant(GetIsExplode()))) ;
}

bool CPieChartData::SetProperty( const QString& propname,const QVariant& value )
{
    if(propname == QObject::tr("IsExplode"))
    {
        SetExplode(value.toBool());
    }
    else
        return CBaseChartData::SetProperty(propname, value);

    GetDiagram()->update();
    return true;
}

bool CPieChartData::GetIsShow3D() const
{
    const ThreeDPieAttributes attrs(m_pieWidget->m_pieDiagram->threeDPieAttributes() );
    return attrs.isEnabled();
}

void CPieChartData::SetShow3D( bool show )
{
    ThreeDPieAttributes attrs(m_pieWidget->m_pieDiagram->threeDPieAttributes() );
    attrs.setEnabled(show);
    m_pieWidget->m_pieDiagram->setThreeDPieAttributes(attrs);
    m_pieWidget->m_pieDiagram->update();
}

bool CPieChartData::GetIsExplode() const
{
    const PieAttributes attrs( m_pieWidget->m_pieDiagram->pieAttributes() );
    return attrs.explode();
}

void CPieChartData::SetExplode( bool explode )
{
    PieAttributes attrs( m_pieWidget->m_pieDiagram->pieAttributes() );
    attrs.setExplode(explode);
    m_pieWidget->m_pieDiagram->setPieAttributes(attrs);
}

CPieChartWidget::CPieChartWidget() : CBaseChartWidget()
{
    PolarCoordinatePlane* polarPlane = new PolarCoordinatePlane(this);
    replaceCoordinatePlane(polarPlane);
    m_pieDiagram = new PieDiagram();
    m_model->TestInit();
    m_pieDiagram->setModel(m_model);
    coordinatePlane()->replaceDiagram(m_pieDiagram);

    resize(200, 200);

    m_pieDiagram->setSelectionModel(m_selectModel);
    connect( m_pieDiagram, SIGNAL(clicked(const QModelIndex&)), SLOT(OnItemClicked(const QModelIndex&)) );
}





CBarChartData::CBarChartData( QGraphicsItem* item ) : CBaseChartData(item)
{
    SetItem(item);
}

void CBarChartData::SaveBaseProperty( CGraphSvgWriter* xio ) const
{
    xio->WriteAttribute("isShowAxis", GetIsShowAxis());
    xio->WriteAttribute("axisTextColor", GetAxisTextColor());

    xio->WriteAttribute("barWidth", GetBarWidth());
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    xio->WriteAttribute("barOrientation", diagram->orientation()-1);
    CBaseChartData::SaveBaseProperty(xio);
}

void CBarChartData::LoadBaseProperty( CGraphSvgReader* xio )
{
    bool isShowAxis;
    QColor c;
    QFont f;
    qreal width;
    int orientation;
    xio->ReadAttribute("isShowAxis", isShowAxis);
    xio->ReadAttribute("axisTextColor", c);

    xio->ReadAttribute("barWidth", width);
    xio->ReadAttribute("barOrientation", orientation);

    SetShowAxis(isShowAxis);
    SetAxisTextColor(c);
    SetAxisTextFont(f);
    SetBarWidth(width);
    SetBarOrientation(orientation);

    CBaseChartData::LoadBaseProperty(xio);
}

QGraphicsItem* CBarChartData::Clone()
{

    return NULL;
}

void CBarChartData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CBaseChartData::GetPropertyList(property_list);

    property_list.push_back(qMakePair(QObject::tr("BarOrientation"), QVariant(GetBarOrientation())));
    property_list.push_back(qMakePair(QObject::tr("BarWidth"), QVariant(GetBarWidth())));
    property_list.push_back(qMakePair(QObject::tr("AxisTextFont"), QVariant(GetAxisTextFont())));
    property_list.push_back(qMakePair(QObject::tr("AxisTextColor"), QVariant(GetAxisTextColor())));
}

bool CBarChartData::SetProperty( const QString& propname,const QVariant& value )
{
    if(QObject::tr("BarOrientation") == propname)
        SetBarOrientation(value.toInt());
    else if(QObject::tr("BarWidth") == propname)
        SetBarWidth(value.toFloat());
    else if(QObject::tr("AxisTextFont") == propname)
        SetAxisTextFont(value.value<QFont>());
    else if(QObject::tr("AxisTextColor") == propname)
        SetAxisTextColor(value.value<QColor>());
    else if(QObject::tr("ShowAxis") == propname)
        SetShowAxis(value.toBool());
    else
        return CBaseChartData::SetProperty(propname, value);

    GetDiagram()->update();
    return false;
}

bool CBarChartData::GetIsShow3D() const
{
    ThreeDBarAttributes attrs = m_barWidget->m_barDiagram->threeDBarAttributes();
    return attrs.isEnabled();

}

void CBarChartData::SetShow3D( bool show )
{
    ThreeDBarAttributes attrs = m_barWidget->m_barDiagram->threeDBarAttributes();
    attrs.setEnabled(show);
    m_barWidget->m_barDiagram->setThreeDBarAttributes(attrs);
}

void CBarChartData::SetAxisTextFont(const QFont& f)
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    CartesianAxisList axisList = diagram->axes();
    foreach(CartesianAxis* axis, axisList)
    {
        TextAttributes rulerAttr = axis->textAttributes();
        rulerAttr.setFont(f);
        rulerAttr.setFontSize(f.pointSize());
        axis->setTextAttributes(rulerAttr);
    }

}

QFont CBarChartData::GetAxisTextFont() const
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    CartesianAxisList axisList = diagram->axes();
    if(axisList.empty())
        return QFont();
    QFont f = axisList[0]->textAttributes().font();
    f.setPointSizeF(axisList[0]->textAttributes().fontSize().value());

    return f;

}

bool CBarChartData::GetIsShowAxis() const
{
    return true;
}

void CBarChartData::SetShowAxis( bool show )
{

}

void CBarChartData::SetAxisTextColor( const QColor& c )
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    CartesianAxisList axisList = diagram->axes();
    foreach(CartesianAxis* axis, axisList)
    {
        TextAttributes rulerAttr = axis->textAttributes();
        QPen p = rulerAttr.pen();
        p.setColor(c);
        rulerAttr.setPen(p);
        axis->setTextAttributes(rulerAttr);
    }
}

QColor CBarChartData::GetAxisTextColor() const
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    CartesianAxisList axisList = diagram->axes();
    if(axisList.empty())
        return QColor();
    return axisList[0]->textAttributes().pen().color();

}

void CBarChartData::SetBarWidth( qreal width )
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    BarAttributes ba( diagram->barAttributes() );
    ba.setFixedBarWidth(width);
    ba.setUseFixedBarWidth(true);
    diagram->setBarAttributes(ba);
}

qreal CBarChartData::GetBarWidth() const
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    BarAttributes ba( diagram->barAttributes() );
    return ba.fixedBarWidth();
}

void CBarChartData::SetBarOrientation(int orientation)
{
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    diagram->setOrientation((Qt::Orientation)(orientation+1));
    CartesianAxisList axisList = diagram->axes();
    Q_ASSERT(axisList.size()==1);
    if(diagram->orientation() == Qt::Vertical)
        axisList.first()->setPosition(KDChart::CartesianAxis::Left);
    else
        axisList.first()->setPosition(KDChart::CartesianAxis::Top);
}

QMap<QString, QVariant> CBarChartData::GetBarOrientation() const
{
    QMap<QString, QVariant> mp;
    BarDiagram* diagram = m_barWidget->m_barDiagram;
    mp.insert(QObject::tr("Horizontal"), 0);
    mp.insert(QObject::tr("Vertical"), 1);
    mp.insert("__CurrentValue", diagram->orientation()-1);

    return mp;
}


CBarChartWidget::CBarChartWidget() : CBaseChartWidget()
{

    m_barDiagram = new BarDiagram();
    m_barDiagram->setModel(m_model);
    QPen pen(m_barDiagram->pen());
    pen.setWidth(0);
    m_barDiagram->setPen(pen);
    coordinatePlane()->replaceDiagram(m_barDiagram);

#if 0
    CartesianAxis *xAxis = new CartesianAxis(m_barDiagram);
    xAxis->setPosition ( KDChart::CartesianAxis::Bottom );
    m_barDiagram->addAxis(xAxis);
#endif
    CartesianAxis *yAxis = new CartesianAxis(m_barDiagram);
    yAxis->setPosition ( KDChart::CartesianAxis::Left );
    m_barDiagram->addAxis(yAxis);

    BackgroundAttributes pba;
    pba.setVisible(true);
    coordinatePlane()->setBackgroundAttributes( pba);
    setGlobalLeadingTop(10);

    AbstractDiagram* diagram = coordinatePlane()->diagram();
    DataValueAttributes dva = diagram->dataValueAttributes();
    TextAttributes ta = dva.textAttributes();
    ta.setRotation(0);
    QFont f;
    f.setPointSize(40);
    ta.setFont(f);
    ta.setFontSize(40);
    RelativePosition posPos( dva.positivePosition() );
    posPos.setReferencePosition( KDChart::Position::North );
    posPos.setAlignment( Qt::AlignCenter );
    posPos.setHorizontalPadding( KDChart::Measure(-500.0) );
    posPos.setVerticalPadding( KDChart::Measure(-1000.0) );
    dva.setPositivePosition(posPos);
    dva.setTextAttributes(ta);
    diagram->setDataValueAttributes(dva);

    m_model->TestInit();
    resize(300, 200);
    m_barDiagram->setSelectionModel(m_selectModel);
    connect( m_barDiagram, SIGNAL(clicked(const QModelIndex&)), SLOT(OnItemClicked(const QModelIndex&)) );
}




CStockChartData::CStockChartData(QGraphicsItem *item):CBaseChartData(item)
{
    SetItem(item);
}

void CStockChartData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    xio->WriteAttribute("stockChartType", GetStockChartType());
    xio->WriteAttribute("perspectiveAngle", (int)GetPerspectiveAngle());
    xio->WriteAttribute("perspectiveDepth", GetPerspectiveDepth());
    xio->WriteAttribute("isUseShadowColors", GetIsUseShadowColors());
    CBaseChartData::SaveBaseProperty(xio);
}

void CStockChartData::LoadBaseProperty(CGraphSvgReader *xio)
{
    int stockChartType;
    int perspectiveAngle;
    double perspectiveDepth;
    bool useShadowColors;
    xio->ReadAttribute("stockChartType",stockChartType);
    xio->ReadAttribute("perspectiveAngle",perspectiveAngle);
    xio->ReadAttribute("perspectiveDepth",perspectiveDepth);
    xio->ReadAttribute("isUseShadowColors",useShadowColors);
    SetStockChartType(stockChartType);
    SetPerspectiveAngle(perspectiveAngle);
    SetPerspectiveDepth(perspectiveDepth);
    SetUseShadowColors(useShadowColors);
    CBaseChartData::LoadBaseProperty(xio);
}

QGraphicsItem* CStockChartData::Clone()
{
    return NULL;
}

void CStockChartData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CBaseChartData::GetPropertyList(property_list);
    QMap<QString,QVariant> typemap;
    typemap.insert(tr("HighLowClose"),StockDiagram::HighLowClose);
    typemap.insert(tr("OpenHighLowClose"),StockDiagram::OpenHighLowClose);
    typemap.insert(tr("Candlestick"),StockDiagram::Candlestick);
    typemap.insert( "__CurrentValue" ,StockDiagram::OpenHighLowClose);
    property_list.push_back(qMakePair(QObject::tr("DiagramType"), QVariant(typemap)));
    property_list.push_back(qMakePair(QObject::tr("PerspectiveAngle"), QVariant(GetPerspectiveAngle())));
    property_list.push_back(qMakePair(QObject::tr("PerspectiveDepth"), QVariant(GetPerspectiveDepth())));
    property_list.push_back(qMakePair(QObject::tr("UseShadowColors"), QVariant(GetIsUseShadowColors())));
}

bool CStockChartData::SetProperty( const QString& propname,const QVariant& value )
{
    if(QObject::tr("DiagramType") == propname)
        SetStockChartType(value.toInt());
    else if(QObject::tr("PerspectiveAngle") == propname)
        SetPerspectiveAngle(value.toUInt());
    else if(QObject::tr("PerspectiveDepth") == propname)
        SetPerspectiveDepth(value.toDouble());
    else if(QObject::tr("UseShadowColors") == propname)
        SetUseShadowColors(value.toBool());
    else
        return CBaseChartData::SetProperty(propname, value);

    GetDiagram()->update();
    return true;
}

bool CStockChartData::GetIsShow3D() const
{
    ThreeDBarAttributes attrs = m_stockWidget->m_stockDiagram->threeDBarAttributes();
    return attrs.isEnabled();

}

void CStockChartData::SetShow3D( bool show )
{
    ThreeDBarAttributes attrs = m_stockWidget->m_stockDiagram->threeDBarAttributes();
    attrs.setEnabled(show);
    m_stockWidget->m_stockDiagram->setThreeDBarAttributes(attrs);
}

int CStockChartData::GetStockChartType() const
{
    return m_stockWidget->m_stockDiagram->type();
}

void CStockChartData::SetStockChartType(const int &type)
{
    if (type == 0)
    {
        m_stockWidget->m_stockDiagram->setType(StockDiagram::HighLowClose);
    }
    else if (type == 1)
    {
        m_stockWidget->m_stockDiagram->setType(StockDiagram::OpenHighLowClose);
    }
    else if(type == 2)
    {
        m_stockWidget->m_stockDiagram->setType(StockDiagram::Candlestick);
    }
}

int CStockChartData::GetPerspectiveAngle() const
{
    return m_stockWidget->m_stockDiagram->threeDBarAttributes().angle();
}

void CStockChartData::SetPerspectiveAngle(const int &angle)
{
    ThreeDBarAttributes attrs = m_stockWidget->m_stockDiagram->threeDBarAttributes();
    attrs.setAngle(angle);
    m_stockWidget->m_stockDiagram->setThreeDBarAttributes(attrs);
}

double CStockChartData::GetPerspectiveDepth() const
{
    return m_stockWidget->m_stockDiagram->threeDBarAttributes().depth();
}

void CStockChartData::SetPerspectiveDepth(const int &depth)
{
    ThreeDBarAttributes attrs = m_stockWidget->m_stockDiagram->threeDBarAttributes();
    attrs.setDepth(depth);
    m_stockWidget->m_stockDiagram->setThreeDBarAttributes(attrs);
}

bool CStockChartData::GetIsUseShadowColors() const
{
    return m_stockWidget->m_stockDiagram->threeDBarAttributes().useShadowColors();
}

void CStockChartData::SetUseShadowColors(const bool useShadowColors)
{
    ThreeDBarAttributes attrs = m_stockWidget->m_stockDiagram->threeDBarAttributes();
    attrs.setUseShadowColors(useShadowColors);
    m_stockWidget->m_stockDiagram->setThreeDBarAttributes(attrs);
}


CStockChartWidget::CStockChartWidget():CBaseChartWidget()
{
    m_stockDiagram = new KDChart::StockDiagram();
    m_stockDiagram->setModel(m_model);
    SetDataModel("HLC.csv");
    QPen pen(m_stockDiagram->pen());
    pen.setWidth(0);
    m_stockDiagram->setPen(pen);
    coordinatePlane()->replaceDiagram(m_stockDiagram);

    CartesianAxis *leftAxis = new CartesianAxis( m_stockDiagram);

    CartesianAxis *bottomAxis = new CartesianAxis(m_stockDiagram);

    leftAxis->setPosition( CartesianAxis::Left );

    TextAttributes attributes = bottomAxis->textAttributes();
    attributes.setRotation( 90 );
    attributes.setFontSize( Measure( 7.0, KDChartEnums::MeasureCalculationModeAbsolute ) );
    bottomAxis->setTextAttributes( attributes );
    bottomAxis->setPosition( CartesianAxis::Bottom );
    m_stockDiagram->addAxis( leftAxis );
    m_stockDiagram->addAxis( bottomAxis );
    resize(300, 200);
    connect( m_stockDiagram, SIGNAL(clicked(const QModelIndex&)), SLOT(OnItemClicked(const QModelIndex&)) );
}

void CStockChartWidget::SetDataModel(const QString &filename )
{
    QString pathfileName = QString("%1/sys/").arg(qgetenv("SMARTSYS_HOME").data()) + filename;
    if (!QFile::exists(pathfileName))
    {
        m_model->TestInit();
    }
    else
    {
        m_model->loadFromCSV(pathfileName);
    }

}
#if 0
//////////////////////////////////////////////////////////////////////////
/////////////////////////////// Polar ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CPolarChartData::CPolarChartData(QGraphicsItem *item):CBaseChartData(item)
{
    SetItem(item);
}

void CPolarChartData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    xio->WriteAttribute("bg-brush", GetBackGroundBrush());				//In order to facilitate the system development,Texture gradient pattern will be ignored.
    xio->WriteAttribute("markState", GetMarkerState());
    xio->WriteAttribute("markStyle", GetMarkerStyle());
    xio->WriteAttribute("markSizeW", GetMarkerSize().width());
    xio->WriteAttribute("markSizeH", GetMarkerSize().height());
    xio->WriteAttribute("refPosition", GetReferencePosition());
    xio->WriteAttribute("startPostion", GetStartPosition());
    xio->WriteAttribute("align", GetAlignment());
    CBaseChartData::SaveBaseProperty(xio);
}

void CPolarChartData::LoadBaseProperty(CGraphSvgReader *xio)
{
    QString	brushstr;
    bool	markState;
    int		markStyle;
    QSize	markSize;
    int		refPosition;
    int		startPostion;
    int		align;
    xio->ReadAttribute("bg-brush",brushstr);
    xio->ReadAttribute("markState",markState);
    xio->ReadAttribute("markStyle",markStyle);
    int tempval = 0;
    xio->ReadAttribute("markSizeW",tempval);
    markSize.setWidth(tempval);
    xio->ReadAttribute("markSizeH",tempval);
    markSize.setHeight(tempval);
    xio->ReadAttribute("refPosition",refPosition);
    xio->ReadAttribute("startPostion",startPostion);
    xio->ReadAttribute("align",align);
    CBaseChartData::LoadBaseProperty(xio);

    SetBackGroundBrush(brushstr);
    SetMarkerState(markState);
    SetMarkerStyle(markStyle);
    SetMarkerSize(markSize);
    SetReferencePostion(refPosition);
    SetStartPosition(startPostion);
    SetAlignment(align);
}

QGraphicsItem* CPolarChartData::Clone()
{
    return NULL;
}

void CPolarChartData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    QMap<QString,QVariant> typemap;
    CBaseChartData::GetPropertyList(property_list);
    property_list.push_back(qMakePair(QObject::tr("BackGroundBrush"), QVariant(GetBackGroundBrush())));
    property_list.push_back(qMakePair(QObject::tr("MarkerState"), QVariant(GetMarkerState())));
    typemap.clear();
    typemap.insert(tr("Circle"),MarkerStyle::MarkerCircle);
    typemap.insert(tr("Square"),MarkerStyle::MarkerSquare);
    typemap.insert(tr("Diamond"),MarkerStyle::MarkerDiamond);
    typemap.insert(tr("1Pixel"),MarkerStyle::Marker1Pixel);
    typemap.insert(tr("4Pixels"),MarkerStyle::Marker4Pixels);
    typemap.insert(tr("Ring"),MarkerStyle::MarkerRing);
    typemap.insert(tr("Cross"),MarkerStyle::MarkerCross);
    typemap.insert(tr("FastCross"),MarkerStyle::MarkerFastCross);
    typemap.insert( "__CurrentValue" ,GetMarkerStyle());
    property_list.push_back(qMakePair(QObject::tr("MarkerStyle"), QVariant(typemap)));
    property_list.push_back(qMakePair(QObject::tr("MarkerSize"), QVariant(GetMarkerSize())));
    typemap.clear();
    typemap.insert(tr("Unknown"),KDChartEnums::PositionUnknown);
    typemap.insert(tr("Center"),KDChartEnums::PositionCenter);
    typemap.insert(tr("NorthWest"),KDChartEnums::PositionNorthWest);
    typemap.insert(tr("North"),KDChartEnums::PositionNorth);
    typemap.insert(tr("NorthEast"),KDChartEnums::PositionNorthEast);
    typemap.insert(tr("East"),KDChartEnums::PositionEast);
    typemap.insert(tr("SouthEast"),KDChartEnums::PositionSouthEast);
    typemap.insert(tr("South"),KDChartEnums::PositionSouth);
    typemap.insert(tr("SouthWest"),KDChartEnums::PositionSouthWest);
    typemap.insert(tr("West"),KDChartEnums::PositionWest);
    typemap.insert(tr("Floating"),KDChartEnums::PositionFloating);
    typemap.insert( "__CurrentValue" ,GetReferencePosition());
    property_list.push_back(qMakePair(QObject::tr("ReferencePostion"), QVariant(typemap)));
    property_list.push_back(qMakePair(QObject::tr("StartPosition"), QVariant(GetStartPosition())));
    typemap.clear();
    typemap.insert(tr("LeftCenter"),0);
    typemap.insert(tr("RightCenter"),1);
    typemap.insert(tr("LeftTop"),2);
    typemap.insert(tr("RightTop"),3);
    typemap.insert(tr("LeftBottom"),4);
    typemap.insert(tr("RightBottom"),5);
    typemap.insert(tr("BidirectionalCenter"),6);
    typemap.insert( "__CurrentValue" ,GetAlignment());
    property_list.push_back(qMakePair(QObject::tr("ALignType"), QVariant(typemap)));

}

bool CPolarChartData::SetProperty( const QString& propname,const QVariant& value )
{
    if(QObject::tr("BackGroundBrush") == propname)
        SetBackGroundBrush(value.toString());
    else if(QObject::tr("MarkerState") == propname)
        SetMarkerState(value.toBool());
    else if(QObject::tr("MarkerStyle") == propname)
        SetMarkerStyle(value.toInt());
    else if(QObject::tr("MarkerSize") == propname)
        SetMarkerSize(value.toSize());
    else if(QObject::tr("ReferencePostion") == propname)
        SetReferencePostion(value.toBool());
    else if(QObject::tr("StartPosition") == propname)
        SetStartPosition(value.toInt());
    if(QObject::tr("ALignType") == propname)
        SetStartPosition(value.toInt());
    else
        return CBaseChartData::SetProperty(propname, value);
    return true;
}

bool CPolarChartData::GetIsShow3D() const
{
    ThreeDBarAttributes attrs = m_polarWidget->m_polarDiagram->threeDBarAttributes();
    return attrs.isEnabled();

}

void CPolarChartData::SetShow3D( bool show )
{
    ThreeDBarAttributes attrs =  m_polarWidget->m_polarDiagram->threeDBarAttributes();
    attrs.setEnabled(show);
    m_polarWidget->m_polarDiagram->setThreeDBarAttributes(attrs);
}

QString CPolarChartData::GetBackGroundBrush() const
{
    BackgroundAttributes pba = static_cast<PolarCoordinatePlane*>(coordinatePlane())->backgroundAttributes();
    return UnqFunc()->GetBrushStyleText(pba.brush());
}

void CPolarChartData::SetBackGroundBrush(const QBrush &brush)
{
    BackgroundAttributes pba;
    pba.setBrush(brush);
    pba.setVisible(true);
    static_cast<PolarCoordinatePlane*>(coordinatePlane())->setBackgroundAttributes(pba);
}
void CPolarChartData::SetBackGroundBrush(const QString & brush)
{
    SetBackGroundBrush(UnqFunc()->SetBrushByText(brush));
}
void CPolarChartData::SetBackGroundBrush(const QColor & color)
{
    SetBackGroundBrush(QBrush(color));
}
void CPolarChartData::SetBackGroundBrush(int r,int g,int b,int a /* = 255 */)
{
    SetBackGroundBrush(QBrush(QColor::fromRgba(r,g,b,a)));
}

bool CPolarChartData::GetMarkerState() const
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    return dva.markerAttributes().isVisible();
}

void CPolarChartData::SetMarkerState(const bool mark)
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    MarkerAttributes		ma(dva.markerAttributes());
    ma.setVisible(mark);
    dva.setMarkerAttributes(ma);
    SetDataValueAtrributes(&dva);
}

QSize CPolarChartData::GetMarkerSize() const
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    MarkerAttributes		ma(dva.markerAttributes());
    return static_cast< const QSize>(ma.markerSize());
}


void CPolarChartData::SetMarkerSize(const QSize size)
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    MarkerAttributes		ma(dva.markerAttributes());
    ma.setMarkerSize(size);
    dva.setMarkerAttributes(ma);
    SetDataValueAtrributes(&dva);
}

void CPolarChartData::SetMarkerSize(const int w, const int h)
{
    QSize size(w,h);
    SetMarkerSize(size);
}

int CPolarChartData::GetReferencePosition() const
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    RelativePosition relativePosition( dva.positivePosition());
    return static_cast<int>(relativePosition.referencePosition());
}

void CPolarChartData::SetReferencePostion(const int pos)
{
    DataValueAttributes		dva(m_polarWidget->m_polarDiagram->dataValueAttributes());
    RelativePosition relativePosition( dva.positivePosition());
    switch (pos)
    {
    case 0:
        relativePosition.setReferencePosition(KDChartEnums::PositionUnknown);
        break;
    case 1:
        relativePosition.setReferencePosition(KDChartEnums::PositionCenter);
        break;
    case 2:
        relativePosition.setReferencePosition(KDChartEnums::PositionNorthWest);
        break;
    case 3:
        relativePosition.setReferencePosition(KDChartEnums::PositionNorth);
        break;
    case 4:
        relativePosition.setReferencePosition(KDChartEnums::PositionNorthEast);
        break;
    case 5:
        relativePosition.setReferencePosition(KDChartEnums::PositionEast);
        break;
    case 6:
        relativePosition.setReferencePosition(KDChartEnums::PositionSouthEast);
        break;
    case 7:
        relativePosition.setReferencePosition(KDChartEnums::PositionSouth);
        break;
    case 8:
        relativePosition.setReferencePosition(KDChartEnums::PositionSouthWest);
        break;
    case 9:
        relativePosition.setReferencePosition(KDChartEnums::PositionWest);
        break;
    case 10:
        relativePosition.setReferencePosition(KDChartEnums::PositionFloating);
        break;
    default:
        relativePosition.setReferencePosition(KDChartEnums::PositionCenter);
        break;
    }
    dva.setPositivePosition( relativePosition );
    SetDataValueAtrributes(&dva);
}

int CPolarChartData::GetStartPosition() const
{
    return static_cast<PolarCoordinatePlane*>(coordinatePlane())->startPosition();
}

void CPolarChartData::SetStartPosition(const double angle)
{

}

void CPolarChartData::SetDataValueAtrributes(const DataValueAttributes *dva)
{
    if(!dva)	return;
    m_polarWidget->m_polarDiagram->setDataValueAttributes(static_cast<const DataValueAttributes>(*dva));
}

#endif
