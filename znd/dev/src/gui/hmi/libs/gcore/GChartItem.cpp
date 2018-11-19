

#include "GChartItem.h"
#include "GFunc.h"
#include "GraphScene.h"

#include <QValueAxis>
#include <QCategoryAxis>
#include <QBarCategoryAxis>
#include <QDateTimeAxis>
#include <QLogValueAxis>
#include <QAreaSeries>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QPercentBarSeries>
#include <QPieSeries>
#include <QScatterSeries>
#include <QHorizontalBarSeries>
#include <QHorizontalStackedBarSeries>
#include <QHorizontalPercentBarSeries>
#include <QBoxPlotSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegendMarker>
#include <QBarLegendMarker> 
#include <QPieLegendMarker> 
#include <QRubberBand> 

CGChartData::CGChartData(QGraphicsItem* item):CBaseData(item)
{
	m_chartType = RealTime;
	m_timeSpace = 5;
	m_sampleMode = 0;
	m_showCurve = false;
	m_axisYAdapte = true;
}
void CGChartData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CGChartItem* pItem = (CGChartItem*)Item();
	QRectF rc = pItem->rect();
    //xio->WriteAttribute("x", rc.x());
    //xio->WriteAttribute("y", rc.y());
    xio->WriteAttribute("width", rc.width());
    xio->WriteAttribute("height", rc.height());
	xio->WriteAttribute("fill", QString("none"));//for web

    xio->WriteAttribute("seriesType", pItem->GetSeriesType());
    xio->WriteAttribute("chartTheme", pItem->theme());
    xio->WriteAttribute("animationOption", pItem->animationOptions());
    xio->WriteAttribute("legendAlign", pItem->legend()->isVisible() ? pItem->legend()->alignment() : -1);
	xio->WriteAttribute("backgroundVisible", pItem->isBackgroundVisible());
	xio->WriteAttribute(QString("chartType"), m_chartType);
    QList<QAbstractSeries *> allSeries = pItem->series();
    if (allSeries.size() > 0)
    {
        QAbstractSeries *series = allSeries.at(0);
        switch (series->type())
        {
        case QAbstractSeries::SeriesTypePie:
        {
            QPieSeries* pie = (QPieSeries*)series;
			xio->WriteAttribute(QString("pieHoleSize"), pie->holeSize());
            QList<QPieSlice *> slices = pie->slices();
            for (int j = 0; j < slices.size(); j++)
            {
                xio->WriteAttribute(QString("pieSliceLabel_%1").arg(j), slices.at(j)->label());
                xio->WriteAttribute(QString("pieSliceColor_%1").arg(j), slices.at(j)->color());
                xio->WriteAttribute(QString("pieSliceExploded_%1").arg(j), slices.at(j)->isExploded());
                xio->WriteAttribute(QString("pieSliceLabelVisible_%1").arg(j), slices.at(j)->isLabelVisible());
				xio->WriteAttribute(QString("pieSliceLabelPosition_%1").arg(j), slices.at(j)->labelPosition());
            }
        }
            break;
        case QAbstractSeries::SeriesTypeBar:
        {
            QBarSeries* bar = (QBarSeries*)series;
            QList<QBarSet *> sets = bar->barSets();
            for (int j = 0; j < sets.size(); j++)
            {
                xio->WriteAttribute(QString("barSetLabel_%1").arg(j), sets.at(j)->label());
                xio->WriteAttribute(QString("barSetColor_%1").arg(j), sets.at(j)->color());
            }

            QBarCategoryAxis* xAxis = (QBarCategoryAxis*)pItem->axisX(bar);
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY(bar);
            if (xAxis == NULL || yAxis == NULL)
                return;
            xio->WriteAttribute(QString("barAxisXCategorys"), xAxis->categories().join(","));
			if (xAxis->categories().size()>1)
			{
				xio->WriteAttribute(QString("barCategoryValues"), m_categoryValues);
			}
            xio->WriteAttribute(QString("barAxisYTitle"), yAxis->titleText());
            xio->WriteAttribute(QString("barAxisYmin"), yAxis->min());
            xio->WriteAttribute(QString("barAxisYmax"), yAxis->max());
			xio->WriteAttribute(QString("barAxisYAdapte"), m_axisYAdapte);
			xio->WriteAttribute(QString("showCurve"), m_showCurve);
        }
            break;
        case QAbstractSeries::SeriesTypeSpline:
        case QAbstractSeries::SeriesTypeLine:
        {
			for (int i = 0; i < allSeries.size(); i++)
            {
                series = allSeries.at(i);
                xio->WriteAttribute(QString("lineName_%1").arg(i), ((QXYSeries*)series)->name());
                xio->WriteAttribute(QString("lineColor_%1").arg(i), ((QXYSeries*)series)->color());
                xio->WriteAttribute(QString("linePointsVisible_%1").arg(i), ((QXYSeries*)series)->pointsVisible());
            }

            QDateTimeAxis* xAxis = (QDateTimeAxis*)pItem->axisX(series);
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY(series);
            if (xAxis == NULL || yAxis == NULL)
                return;

            xio->WriteAttribute(QString("lineAxisXTitle"), xAxis->titleText());
            xio->WriteAttribute(QString("lineAxisXTickCount"), xAxis->tickCount());
            xio->WriteAttribute(QString("lineAxisXFormat"), xAxis->format());
			if (m_chartType == History){
				xio->WriteAttribute(QString("lineAxisXFromTime"), xAxis->min().toString(xAxis->format()));
				xio->WriteAttribute(QString("lineAxisXTimeSpace-s"), m_timeSpace);
				xio->WriteAttribute("sampleMode", m_sampleMode);
			}
			xio->WriteAttribute(QString("lineAxisXRange-s"), (int)(xAxis->min().msecsTo(xAxis->max()) / 1000));
            xio->WriteAttribute(QString("lineAxisYTitle"), yAxis->titleText());
            xio->WriteAttribute(QString("lineAxisYmin"), yAxis->min());
            xio->WriteAttribute(QString("lineAxisYmax"), yAxis->max());
			xio->WriteAttribute(QString("lineAxisYAdapte"), m_axisYAdapte);
            QList<QAbstractAxis*> addAxes = pItem->GetAddAxes();
            xio->WriteAttribute(QString("addAxisNum"), addAxes.size());
            for (int i = 0; i<addAxes.size(); i++)
            {
                xio->WriteAttribute(QString("addAxisType_%1").arg(i), addAxes[i]->type());
                xio->WriteAttribute(QString("addAxisAlign_%1").arg(i), addAxes[i]->alignment());
                xio->WriteAttribute(QString("addAxisTitle_%1").arg(i), addAxes[i]->titleText());
                xio->WriteAttribute(QString("addAxisColor_%1").arg(i), addAxes[i]->linePenColor());
                if (addAxes[i]->type() == QAbstractAxis::AxisTypeValue)
                {
                    xio->WriteAttribute(QString("addAxisMin_%1").arg(i), ((QValueAxis*)addAxes[i])->min());
                    xio->WriteAttribute(QString("addAxisMax_%1").arg(i), ((QValueAxis*)addAxes[i])->max());
                    xio->WriteAttribute(QString("addAxisTickCount_%1").arg(i), ((QValueAxis*)addAxes[i])->tickCount());
                }
                else if (addAxes[i]->type() == QAbstractAxis::AxisTypeCategory)
                {
                    xio->WriteAttribute(QString("addAxisMin_%1").arg(i), ((QCategoryAxis*)addAxes[i])->min());
                    xio->WriteAttribute(QString("addAxisMax_%1").arg(i), ((QCategoryAxis*)addAxes[i])->max());
                    QStringList cates = ((QCategoryAxis*)addAxes[i])->categoriesLabels();
                    xio->WriteAttribute(QString("addAxisCategoryLabels_%1").arg(i), cates.join(","));
                    QStringList vals;
                    for (int j = 0; j < cates.size(); j++)
                        vals << QString::number(((QCategoryAxis*)addAxes[i])->endValue(cates[j]));
                    xio->WriteAttribute(QString("addAxisCategoryEndValues_%1").arg(i), vals.join(","));
                }
            }
        }
            break;
        }
    }
    CBaseData::SaveBaseProperty(xio);
}

void CGChartData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CGChartItem* pItem = (CGChartItem*)Item();
    qreal /*x, y, */width, height;
   // xio->ReadAttribute("x", x);
   // xio->ReadAttribute("y", y);
    xio->ReadAttribute("width", width);
    xio->ReadAttribute("height", height);
    pItem->resize(QSizeF(width, height));

    int seriesType;
    xio->ReadAttribute("seriesType", seriesType); pItem->SetSeriesType(seriesType);
    int theme;
    xio->ReadAttribute("chartTheme", theme); pItem->SetTheme(theme);
    int animation;
    xio->ReadAttribute("animationOption", animation); pItem->SetAnimationOptions(animation);
    int align;
    xio->ReadAttribute("legendAlign", align); SetProperty(CBaseData::tr("legendAlign"), align);
	bool bgVisiable;
	xio->ReadAttribute("backgroundVisible", bgVisiable); pItem->setBackgroundVisible(bgVisiable);
	xio->ReadAttribute(QString("chartType"), m_chartType);
    QString userData;
    xio->ReadAttribute("user-data", userData); SetProperty(CBaseData::tr("userData"), userData);

    QList<QAbstractSeries *> allSeries = pItem->series();
    if (allSeries.size() > 0)
    {
        QAbstractSeries *series = allSeries.at(0);
        switch (series->type())
        {
        case QAbstractSeries::SeriesTypePie:
        {
            QPieSeries* pie = (QPieSeries*)series;
            QList<QPieSlice *> slices = pie->slices();
			qreal holeSize;
			xio->ReadAttribute(QString("pieHoleSize"), holeSize); pie->setHoleSize(holeSize);
            for (int j = 0; j < slices.size(); j++)
            {
				QString label; QColor color; bool isExploded = false; bool isLabelVisible = true; int labelPosition = QPieSlice::LabelOutside;
                xio->ReadAttribute(QString("pieSliceLabel_%1").arg(j), label); slices.at(j)->setLabel(label);
                xio->ReadAttribute(QString("pieSliceColor_%1").arg(j), color); slices.at(j)->setColor(color);
                xio->ReadAttribute(QString("pieSliceExploded_%1").arg(j), isExploded); slices.at(j)->setExploded(isExploded);
                xio->ReadAttribute(QString("pieSliceLabelVisible_%1").arg(j), isLabelVisible); slices.at(j)->setLabelVisible(isLabelVisible);
				xio->ReadAttribute(QString("pieSliceLabelPosition_%1").arg(j), labelPosition); slices.at(j)->setLabelPosition((QPieSlice::LabelPosition)labelPosition);
            }
        }
            break;
        case QAbstractSeries::SeriesTypeBar:
        {
            QBarSeries* bar = (QBarSeries*)series;
            QList<QBarSet *> sets = bar->barSets();
            for (int j = 0; j < sets.size(); j++)
            {
                QString label;
                QColor color;
                xio->ReadAttribute(QString("barSetLabel_%1").arg(j), label); sets.at(j)->setLabel(label);
                xio->ReadAttribute(QString("barSetColor_%1").arg(j), color); sets.at(j)->setColor(color);
            }
            QBarCategoryAxis* xAxis = (QBarCategoryAxis*)pItem->axisX(bar);
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY(bar);
            if (xAxis == NULL || yAxis == NULL)
                return;

            QString category; QString yTitle; qreal yMin; qreal yMax;
            xio->ReadAttribute(QString("barAxisXCategorys"), category); xAxis->setCategories(category.split(","));
			if (category.split(",").size() > 1)
			{
				xio->ReadAttribute(QString("barCategoryValues"), m_categoryValues);
				QStringList lst = m_categoryValues.split(",");
				for (int lstI = 0; lstI < lst.size(); lstI++)
				{
					QStringList vals = lst[lstI].split(" ");
					for (int valI = 0; valI < vals.size(); valI++)
					{
						if (sets.at(valI))
						{
							sets.at(valI)->insert(lstI, vals[valI].toFloat());
						}
					}
				}
			}
            xio->ReadAttribute(QString("barAxisYTitle"), yTitle); yAxis->setTitleText(yTitle);
            xio->ReadAttribute(QString("barAxisYmin"), yMin); yAxis->setMin(yMin);
            xio->ReadAttribute(QString("barAxisYmax"), yMax); yAxis->setMax(yMax);
			xio->ReadAttribute(QString("barAxisYAdapte"), m_axisYAdapte);
			xio->ReadAttribute(QString("showCurve"), m_showCurve); pItem->ShowCurve(m_showCurve);
        }
            break;
        case QAbstractSeries::SeriesTypeSpline:
        case QAbstractSeries::SeriesTypeLine:
        {
			for (int i = 0; i < allSeries.size(); i++)
            {
                series = allSeries.at(i);
                QString name; QColor color; bool pointVisible = false;
                xio->ReadAttribute(QString("lineName_%1").arg(i), name); ((QXYSeries*)series)->setName(name);
                xio->ReadAttribute(QString("lineColor_%1").arg(i), color); ((QXYSeries*)series)->setColor(color);
                xio->ReadAttribute(QString("linePointsVisible_%1").arg(i), pointVisible); ((QXYSeries*)series)->setPointsVisible(pointVisible);
            }

            QDateTimeAxis* xAxis = (QDateTimeAxis*)pItem->axisX();
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY();
            if (xAxis == NULL || yAxis == NULL)
                return;
			QString xTitle; int tickCount; QString format; QString fromTime; int xRange; QString yTitle; qreal yMin; qreal yMax;
            xio->ReadAttribute(QString("lineAxisXTitle"), xTitle); xAxis->setTitleText(xTitle);
            xio->ReadAttribute(QString("lineAxisXTickCount"), tickCount); xAxis->setTickCount(tickCount);
            xio->ReadAttribute(QString("lineAxisXFormat"), format); xAxis->setFormat(format);
			if (m_chartType == History){
				xio->ReadAttribute(QString("lineAxisXFromTime"), fromTime); xAxis->setMin(m_chartType == RealTime ? QDateTime::currentDateTime() : pItem->getDateTime(fromTime, format));
				xio->ReadAttribute(QString("lineAxisXTimeSpace-s"), m_timeSpace);
				xio->ReadAttribute("sampleMode", m_sampleMode);
			}
			xio->ReadAttribute(QString("lineAxisXRange-s"), xRange); /*xAxis->setMin(QDateTime::currentDateTime());*/ xAxis->setMax(xAxis->min().addSecs(xRange));
            xio->ReadAttribute(QString("lineAxisYTitle"), yTitle); yAxis->setTitleText(yTitle);
            xio->ReadAttribute(QString("lineAxisYmin"), yMin); yAxis->setMin(yMin);
            xio->ReadAttribute(QString("lineAxisYmax"), yMax); yAxis->setMax(yMax);
			xio->ReadAttribute(QString("lineAxisYAdapte"), m_axisYAdapte);
            int addAxisNum;
            xio->ReadAttribute(QString("addAxisNum"), addAxisNum);
            for (int i = 0; i<addAxisNum; i++)
            {
                int type; int align; QString title; QColor color;
                xio->ReadAttribute(QString("addAxisType_%1").arg(i), type);
                xio->ReadAttribute(QString("addAxisAlign_%1").arg(i), align);
                xio->ReadAttribute(QString("addAxisTitle_%1").arg(i), title);
                xio->ReadAttribute(QString("addAxisColor_%1").arg(i), color);
                if (type == QAbstractAxis::AxisTypeValue)
                {
                    qreal min; qreal max; int tickCount;
                    xio->ReadAttribute(QString("addAxisMin_%1").arg(i), min);
                    xio->ReadAttribute(QString("addAxisMax_%1").arg(i), max);
                    xio->ReadAttribute(QString("addAxisTickCount_%1").arg(i), tickCount);

                    QValueAxis* ax = new QValueAxis();
                    ax->setTitleText(title);
                    ax->setLinePenColor(color);
                    ax->setMin(min);
                    ax->setMax(max);
                    ax->setTickCount(tickCount);
                    pItem->addAxis(ax, (Qt::Alignment)align);
                    pItem->InsertAdditionalAxis(ax);
                }
                else if (type == QAbstractAxis::AxisTypeCategory)
                {
                    qreal min; qreal max; QString cates; QString vals;
                    xio->ReadAttribute(QString("addAxisMin_%1").arg(i), min);
                    xio->ReadAttribute(QString("addAxisMax_%1").arg(i), max);
                    xio->ReadAttribute(QString("addAxisCategoryLabels_%1").arg(i), cates);
                    xio->ReadAttribute(QString("addAxisCategoryEndValues_%1").arg(i), vals);

                    QCategoryAxis* ax = new QCategoryAxis();
                    ax->setTitleText(title);
                    ax->setLinePenColor(color);
                    ax->setMin(min);
                    ax->setMax(max);
                    ax->setTickCount(tickCount);
                    QStringList catesLst = cates.split(","); QStringList valsLst = vals.split(",");
                    if (catesLst.size() != valsLst.size())
                        continue;
                    for (int j = 0; j < catesLst.size(); j++)
                        ax->append(catesLst[j], valsLst[j].toDouble());
                    pItem->addAxis(ax, (Qt::Alignment)align);
                    pItem->InsertAdditionalAxis(ax);
                }
            }
        }
            break;
        }
    }
    CBaseData::LoadBaseProperty(xio);
}

void CGChartData::GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList)
{
    QList< QPair<QString,QVariant> > propertylist;

    GetPropertyList(propertylist);
    QString splitname=CBaseData::tr("chart");

    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >(splitname,propertylist));
    propertylist.clear();
    CGChartItem* pItem = dynamic_cast<CGChartItem*>(Item());
    const QMetaObject* metaobject = pItem->metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char* name = metaproperty.name();
        if( QWidget::staticMetaObject.indexOfProperty(name)<0|| strcmp(name,"styleSheet")==0)
        {
            propertylist << qMakePair(name, pItem->property(name));
        }
    }
    QString className=metaobject->className();
    if(className.left(2)=="CG")
        className.remove(0, 2);
    else if(className.left(1)=="Q")
        className.remove(0, 1);
    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >(className,propertylist));
    propertylist.clear();
    foreach(QByteArray barray, pItem->dynamicPropertyNames())
        propertylist << qMakePair(QString(barray), pItem->property(barray.data()));

    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >("custom property",propertylist));

}

void CGChartData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{

    CGChartItem* pItem = dynamic_cast<CGChartItem*>(Item());
    if (pItem)
    {
        property_list.push_back(qMakePair(CBaseData::tr("name"), QVariant(GetName())));

        property_list.push_back(qMakePair(CBaseData::tr("rect"), QVariant(pItem->mapRectToScene(pItem->rect()))));

        QMap<QString, QVariant> tmpMap;
        tmpMap[CBaseData::tr("SeriesTypeLine")] = QAbstractSeries::SeriesTypeLine;

        tmpMap[CBaseData::tr("SeriesTypeBar")] = QAbstractSeries::SeriesTypeBar;


        tmpMap[CBaseData::tr("SeriesTypePie")] = QAbstractSeries::SeriesTypePie;

        tmpMap[CBaseData::tr("SeriesTypeSpline")] = QAbstractSeries::SeriesTypeSpline;




        tmpMap["__CurrentValue"] = pItem->GetSeriesType();
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("seriesType"), QVariant(tmpMap)));

        QMap<QString, QVariant> themeMap;
        themeMap[CBaseData::tr("ChartThemeLight")] = QChart::ChartThemeLight;
        themeMap[CBaseData::tr("ChartThemeBlueCerulean")] = QChart::ChartThemeBlueCerulean;
        themeMap[CBaseData::tr("ChartThemeDark")] = QChart::ChartThemeDark;
        themeMap[CBaseData::tr("ChartThemeBrownSand")] = QChart::ChartThemeBrownSand;
        themeMap[CBaseData::tr("ChartThemeBlueNcs")] = QChart::ChartThemeBlueNcs;
        themeMap[CBaseData::tr("ChartThemeHighContrast")] = QChart::ChartThemeHighContrast;
        themeMap[CBaseData::tr("ChartThemeBlueIcy")] = QChart::ChartThemeBlueIcy;
        themeMap[CBaseData::tr("ChartThemeQt")] = QChart::ChartThemeQt;
        themeMap["__CurrentValue"] = pItem->theme();
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("chartTheme"), QVariant(themeMap)));

        QMap<QString, QVariant> AnimationMap;
        AnimationMap[CBaseData::tr("NoAnimation")] = QChart::NoAnimation;
        AnimationMap[CBaseData::tr("GridAxisAnimations")] = QChart::GridAxisAnimations;
        AnimationMap[CBaseData::tr("SeriesAnimations")] = QChart::SeriesAnimations;
        AnimationMap[CBaseData::tr("AllAnimations")] = QChart::AllAnimations;
        AnimationMap["__CurrentValue"] = (int)pItem->animationOptions();
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("animationOption"), QVariant(AnimationMap)));

        property_list.push_back(qMakePair(CBaseData::tr("backgroundVisible"), QVariant(pItem->isBackgroundVisible())));
		QMap<QString, QVariant> typeMap;
        typeMap[CBaseData::tr("RealTime")] = RealTime;
        typeMap[CBaseData::tr("History")] = History;
		typeMap["__CurrentValue"] = m_chartType;
        property_list.push_back(qMakePair(QString(CBaseData::tr("chartType")), typeMap));

        property_list.push_back(qMakePair(CBaseData::tr("userData"), QVariant(GetUserData())));

        QMap<QString, QVariant> legendMap;
        legendMap[CBaseData::tr("NoLegen")] = -1;
        legendMap[CBaseData::tr("AlignLeft")] = Qt::AlignLeft;
        legendMap[CBaseData::tr("AlignRight")] = Qt::AlignRight;
        legendMap[CBaseData::tr("AlignHCenter")] = Qt::AlignHCenter;
        legendMap[CBaseData::tr("AlignJustify")] = Qt::AlignJustify;
        legendMap[CBaseData::tr("AlignTop")] = Qt::AlignTop;
        legendMap[CBaseData::tr("AlignBottom")] = Qt::AlignBottom;
        legendMap[CBaseData::tr("AlignVCenter")] = Qt::AlignVCenter;
        legendMap[CBaseData::tr("AlignBaseline")] = Qt::AlignBaseline;
        legendMap[CBaseData::tr("AlignCenter")] = Qt::AlignCenter;
        legendMap["__CurrentValue"] = pItem->legend()->isVisible() ? pItem->legend()->alignment() : -1;
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("legendAlign"), QVariant(legendMap)));

        QList<QAbstractSeries *> allSeries = pItem->series();
        if (allSeries.size() == 0)
            return;
        QAbstractSeries *series = allSeries.at(0);
        switch (series->type())
        {
        case QAbstractSeries::SeriesTypePie:
        {
            QPieSeries* pie = (QPieSeries*)series;
			QVariantList holeLst;
			holeLst.append(pie->holeSize());//value
			QJsonObject holeLimit;
			holeLimit["minimum"] = 0;
			holeLimit["maximum"] = 1;
			holeLst.append(holeLimit);//inputlimit
            property_list.push_back(qMakePair(QString(CBaseData::tr("pieHoleSize")), QVariant(holeLst)));

            QList<QPieSlice *> slices = pie->slices();
            for (int j = 0; j < slices.size(); j++)
            {
                property_list.push_back(qMakePair(QString(CBaseData::tr("pieSliceLabel_%1").arg(j)), QVariant(slices.at(j)->label())));
                property_list.push_back(qMakePair(QString(CBaseData::tr("pieSliceColor_%1").arg(j)), QVariant(slices.at(j)->color())));
                property_list.push_back(qMakePair(QString(CBaseData::tr("pieSliceLabelVisible_%1").arg(j)), QVariant(slices.at(j)->isLabelVisible())));
				QMap<QString, QVariant> typeMap;
                typeMap[CBaseData::tr("LabelOutside")] = QPieSlice::LabelOutside;
                typeMap[CBaseData::tr("LabelInsideHorizontal")] = QPieSlice::LabelInsideHorizontal;
                typeMap[CBaseData::tr("LabelInsideTangential")] = QPieSlice::LabelInsideTangential;
                typeMap[CBaseData::tr("LabelInsideNormal")] = QPieSlice::LabelInsideNormal;
				typeMap["__CurrentValue"] = slices.at(j)->labelPosition();
                property_list.push_back(qMakePair(QString(CBaseData::tr("pieSliceLabelPosition_%1").arg(j)), typeMap));
                property_list.push_back(qMakePair(QString(CBaseData::tr("pieSliceExploded_%1").arg(j)), QVariant(slices.at(j)->isExploded())));
            }
        }
            break;
        case QAbstractSeries::SeriesTypeBar:
        {
            QBarSeries* bar = (QBarSeries*)series;
            QList<QBarSet *> sets = bar->barSets();
            for (int j = 0; j < sets.size(); j++)
            {
                property_list.push_back(qMakePair(QString(CBaseData::tr("barSetLabel_%1").arg(j)), QVariant(sets.at(j)->label())));
                property_list.push_back(qMakePair(QString(CBaseData::tr("barSetColor_%1").arg(j)), QVariant(sets.at(j)->color())));
            }

            QBarCategoryAxis* xAxis = (QBarCategoryAxis*)pItem->axisX(bar);
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY(bar);
            if (xAxis == NULL || yAxis == NULL)
                return;

            property_list.push_back(qMakePair(QString(CBaseData::tr("barAxisXCategorys")), QVariant(xAxis->categories().join(","))));
			if (xAxis->categories().size()>1)
			{
				m_categoryValues = "";
				for (int categoryI = 0; categoryI < xAxis->categories().size(); categoryI++)
				{
					if (categoryI>0)
						m_categoryValues.append(",");
					for (int barI = 0; barI < sets.size(); barI++)
					{
						m_categoryValues.append(QString::number(sets.at(barI)->at(categoryI))).append(" ");
					}
					m_categoryValues = m_categoryValues.left(m_categoryValues.length()-1);
				}
                property_list.push_back(qMakePair(QString(CBaseData::tr("barCategoryValues")), m_categoryValues));
			}
            property_list.push_back(qMakePair(QString(CBaseData::tr("barAxisYTitle")), QVariant(yAxis->titleText())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("barAxisYmin")), QVariant(yAxis->min())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("barAxisYmax")), QVariant(yAxis->max())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("barAxisYAdapte")), QVariant(m_axisYAdapte)));
            property_list.push_back(qMakePair(QString(CBaseData::tr("showCurve")), QVariant(m_showCurve)));
        }
            break;
        case QAbstractSeries::SeriesTypeSpline:
        case QAbstractSeries::SeriesTypeLine:
        {
			for (int i = 0; i < allSeries.size(); i++)
            {
                series = allSeries.at(i);
                property_list.push_back(qMakePair(QString(CBaseData::tr("lineName_%1").arg(i)), QVariant(((QXYSeries*)series)->name())));
                property_list.push_back(qMakePair(QString(CBaseData::tr("lineColor_%1").arg(i)), QVariant(((QXYSeries*)series)->color())));
                property_list.push_back(qMakePair(QString(CBaseData::tr("linePointsVisible_%1").arg(i)), QVariant(((QXYSeries*)series)->pointsVisible())));
            }

            QDateTimeAxis* xAxis = (QDateTimeAxis*)pItem->axisX(series);
            QValueAxis* yAxis = (QValueAxis*)pItem->axisY(series);
            if (xAxis == NULL || yAxis == NULL)
                return;

            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXTitle")), QVariant(xAxis->titleText())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXTickCount")), QVariant((uint)xAxis->tickCount())));
			QMap<QString, QVariant> formatMap;
			formatMap[("hh:mm:ss")] = 0;
			formatMap[("MM-dd")] = 1;
			formatMap[("MM-dd hh")] = 2;
			formatMap[("yyyy-MM-dd")] = 3;
			formatMap[("yyyy-MM-dd hh:mm:ss")] = 4;
			formatMap["__CurrentValue"] = formatMap[xAxis->format()];
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXFormat")), QVariant(formatMap)));
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXRange-s")), QVariant(xAxis->min().msecsTo(xAxis->max()) / 1000)));
			if (m_chartType == History){
                property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXFromTime")), QVariant(xAxis->min().toString(xAxis->format()))));
                property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisXTimeSpace-s")), m_timeSpace));
				QMap<QString, QVariant> modeMap;
                modeMap[CBaseData::tr("START")] = 0;
                modeMap[CBaseData::tr("MIDDLE")] = 1;
                modeMap[CBaseData::tr("END")] = 2;
                modeMap[CBaseData::tr("MAX")] = 3;
                modeMap[CBaseData::tr("MIN")] = 4;
                modeMap[CBaseData::tr("AVERAGE")] = 5;
				modeMap["__CurrentValue"] = m_sampleMode;
                property_list.push_back(qMakePair(CBaseData::tr("sampleMode"), modeMap));
			}
            
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisYTitle")), QVariant(yAxis->titleText())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisYmin")), QVariant(yAxis->min())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisYmax")), QVariant(yAxis->max())));
            property_list.push_back(qMakePair(QString(CBaseData::tr("lineAxisYAdapte")), QVariant(m_axisYAdapte)));
            QList<QAbstractAxis*> addAxes = pItem->GetAddAxes();
            property_list.push_back(qMakePair(QString(CBaseData::tr("addAxisNum")), QVariant((uint)addAxes.size())));

            for (int i = 0; i<addAxes.size(); i++)
            {
                QMap<QString, QVariant> tmpMap;
                tmpMap[CBaseData::tr("QValueAxis")] = QAbstractAxis::AxisTypeValue;
                tmpMap[CBaseData::tr("QCategoryAxis")] = QAbstractAxis::AxisTypeCategory;
                tmpMap["__CurrentValue"] = addAxes[i]->type();
                property_list.push_back(qMakePair(CBaseData::tr("addAxisType_%1").arg(i), QVariant(tmpMap)));

                QMap<QString, QVariant> alignMap;
                alignMap[CBaseData::tr("AlignLeft")] = Qt::AlignLeft;
                alignMap[CBaseData::tr("AlignRight")] = Qt::AlignRight;
                alignMap[CBaseData::tr("AlignHCenter")] = Qt::AlignHCenter;
                alignMap[CBaseData::tr("AlignJustify")] = Qt::AlignJustify;
                alignMap[CBaseData::tr("AlignTop")] = Qt::AlignTop;
                alignMap[CBaseData::tr("AlignBottom")] = Qt::AlignBottom;
                alignMap[CBaseData::tr("AlignVCenter")] = Qt::AlignVCenter;
                alignMap[CBaseData::tr("AlignBaseline")] = Qt::AlignBaseline;
                alignMap[CBaseData::tr("AlignCenter")] = Qt::AlignCenter;
                alignMap["__CurrentValue"] = (int)addAxes[i]->alignment();
                property_list.push_back(qMakePair(CBaseData::tr("addAxisAlign_%1").arg(i), QVariant(alignMap)));
                property_list.push_back(qMakePair(CBaseData::tr("addAxisTitle_%1").arg(i), QVariant(addAxes[i]->titleText())));
                property_list.push_back(qMakePair(CBaseData::tr("addAxisColor_%1").arg(i), QVariant(addAxes[i]->linePenColor())));

                if (addAxes[i]->type() == QAbstractAxis::AxisTypeValue)
                {
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisMin_%1").arg(i), QVariant(((QValueAxis*)addAxes[i])->min())));
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisMax_%1").arg(i), QVariant(((QValueAxis*)addAxes[i])->max())));
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisTickCount_%1").arg(i), QVariant(((QValueAxis*)addAxes[i])->tickCount())));
                }
                else if (addAxes[i]->type() == QAbstractAxis::AxisTypeCategory)
                {
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisMin_%1").arg(i), QVariant(((QCategoryAxis*)addAxes[i])->min())));
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisMax_%1").arg(i), QVariant(((QCategoryAxis*)addAxes[i])->max())));
                    QStringList cates = ((QCategoryAxis*)addAxes[i])->categoriesLabels();
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisCategoryLabels_%1").arg(i), QVariant(cates.join(","))));
                    QStringList vals;
                    for (int j = 0; j < cates.size(); j++)
                        vals << QString::number(((QCategoryAxis*)addAxes[i])->endValue(cates[j]));
                    property_list.push_back(qMakePair(CBaseData::tr("addAxisCategoryEndValues_%1").arg(i), QVariant(vals.join(","))));
                }
            }
        }
            break;
        }

    }
}

bool CGChartData::SetProperty(const QString& propname,const QVariant& value)
{
    CGChartItem* pItem = dynamic_cast<CGChartItem*>(Item());
    if (pItem)
    {
        if (propname == CBaseData::tr("rect") || propname == "rect")
		{
			QRectF rc = value.toRectF();
			QPointF dP = pItem->mapFromScene(rc.topLeft());
			pItem->setPos(pItem->pos() + dP);
			pItem->resize(rc.size());
		}
        else if (propname == CBaseData::tr("seriesType") || propname == "seriesType") {
            pItem->SetSeriesType(value.toInt());
            SetProperty(CBaseData::tr("userData"), GetUserData());
        }
        else if (propname == CBaseData::tr("chartTheme") || propname == "chartTheme") {
            pItem->SetTheme(value.toInt());
        }
        else if (propname == CBaseData::tr("animationOption") || propname == "animationOption") {
            pItem->SetAnimationOptions(value.toInt());
        }
        else if (propname == CBaseData::tr("userData") || propname == "userData") {
			QString valStr = value.toString();
			if (valStr.contains("attrType"))// drag from linkdb
			{
				valStr = "[{\"" + valStr.mid(valStr.indexOf("tags"));
			}
		
			QStringList str;
			if (valStr.contains("!"))
				str = valStr.split("!");
			else
				str = valStr.split("\"");
			QStringList taglst,taglist;
            if (str.length() == 5)
            {
				taglst = str.at(3).split(",", QString::SkipEmptyParts);
            }
			if (taglst.length() == 0)
            {
				CBaseData::SetProperty(propname, valStr);
                return true;
            }
			for (int li = 0; li < taglst.length(); li++)
			{
				if (pItem->GetChartByTag(taglst[li]) == NULL)
					taglist.append(taglst[li]);
			}
			QStringList tagData;
            int type = pItem->GetSeriesType();
            switch (type)
            {
            case QAbstractSeries::SeriesTypePie:
            {
				QPieSeries* pie = NULL;
				if (pItem->series().size() > 0)
					pie = (QPieSeries*)pItem->series().at(0);
				else
					pie = (QPieSeries*)pItem->AddSeries(QAbstractSeries::SeriesTypePie);
				if (pie == NULL)
					return false;
                for (int i = 0; i < taglist.length(); i++)
                {
                    QObject* pieSlice = pItem->AppendPieSlice(pie, taglist[i], 5);
                    pItem->InsertTagChart(taglist[i], pieSlice);
                }


				QMap<QString, QObject*>  tMap = pItem->GetTagsChart();
				for (int is = 0; is < pie->slices().size(); is++){
					tagData.append(tMap.key(pie->slices()[is]));
				}
            }
                break;
            case QAbstractSeries::SeriesTypeBar:
            {
				QBarSeries* bar = NULL;
				if (pItem->series().size() > 0)
					bar = (QBarSeries*)pItem->series().at(0);
				else{
					bar = (QBarSeries*)pItem->AddSeries(QAbstractSeries::SeriesTypeBar);
					QList<QAbstractAxis*> axes = pItem->axes();
					for (int i = 0; i < axes.size(); i++){
						if (!pItem->GetAddAxes().contains(axes[i]))
							bar->attachAxis(axes[i]);
					}
				}
                for (int i = 0; i < taglist.length(); i++)
                {
                    QObject* barSet = pItem->AppendBarSet(bar, taglist[i], QStringList() << "5");
                    pItem->InsertTagChart(taglist[i], barSet);
                }
                
				QMap<QString, QObject*>  tMap = pItem->GetTagsChart();
				for (int is = 0; is < bar->barSets().size(); is++){
					tagData.append(tMap.key(bar->barSets()[is]));
				}
            }
                break;
            case QAbstractSeries::SeriesTypeSpline:
            case QAbstractSeries::SeriesTypeLine:
            {
                QList<QAbstractAxis*> axes = pItem->axes();

				for (int i = 0; i < taglist.length(); i++)
				{
					QXYSeries* line = (QXYSeries*)pItem->AddSeries(type);
					// line->setPointsVisible(true);
					line->setName(taglist[i]);
					for (int j = 0; j < axes.size(); j++){
						if (!pItem->GetAddAxes().contains(axes[j]))
							line->attachAxis(axes[j]);
				    }
                    pItem->InsertTagChart(taglist[i], line);
					emit AddTag(taglist[i]);
                }
				QList<QAbstractSeries *> allSeries = pItem->series();
				QMap<QString, QObject*>  tMap = pItem->GetTagsChart();
				for (int is = 0; is < allSeries.size(); is++){
					tagData.append(tMap.key(allSeries[is]));
				}
            }
                break;
            }
		
			CBaseData::SetProperty(propname, "[{!tags!:!" + tagData.join(",") + "!}]");
			pItem->ConnectMarkers();
        }
        else if (propname == CBaseData::tr("backgroundVisible") || propname == "backgroundVisible") {
			pItem->setBackgroundVisible(value.toBool());
        }
        else if (propname == CBaseData::tr("legendAlign") || propname == "legendAlign") {
			int align = value.toInt();
			if (align < 0)
				pItem->legend()->hide();
			else{
				pItem->legend()->show();
				pItem->legend()->setAlignment((Qt::Alignment)align);
			}
		}
        else if (propname == CBaseData::tr("pieHoleSize") || propname == "pieHoleSize") {
			qreal holeSize = value.toReal();
			if (pItem->series().size() == 0)
				return false;
			QPieSeries* series = (QPieSeries*)pItem->series().at(0);
			series->setHoleSize(holeSize);
		}
        else if (propname.startsWith(CBaseData::tr("pieSlice")) || propname.startsWith("pieSlice"))
        {
			if (pItem->series().size() == 0)
				return false;
            QPieSeries* series = (QPieSeries*)pItem->series().at(0);
            int index = propname.split("_").last().toInt();
            if (propname.contains(CBaseData::tr("LabelVisible")) || propname.contains("LabelVisible"))
                series->slices().at(index)->setLabelVisible(value.toBool());
            else if (propname.contains(CBaseData::tr("LabelPosition")) || propname.contains("LabelPosition"))
				series->slices().at(index)->setLabelPosition((QPieSlice::LabelPosition)(value.toInt()));
            else if (propname.contains(CBaseData::tr("Label")) || propname.contains("Label"))
                series->slices().at(index)->setLabel(value.toString());
            else if (propname.contains(CBaseData::tr("Color")) || propname.contains("Color"))
                series->slices().at(index)->setColor(value.value<QColor>());
            else if (propname.contains(CBaseData::tr("Explode")) || propname.contains("Explode"))
                series->slices().at(index)->setExploded(value.toBool());
        }
        else if (propname == CBaseData::tr("chartType") || propname == "chartType")
		{
			m_chartType = value.toInt();
		}
        else if (propname.startsWith(CBaseData::tr("lineName")) || propname.startsWith("lineName"))
        {
			if (pItem->series().size() == 0)
				return false;
            QList<QAbstractSeries *> allSeries = pItem->series();
            int index = propname.split("_").last().toInt();
            ((QXYSeries*)allSeries[index])->setName(value.toString());
        }
        else if (propname.startsWith(CBaseData::tr("lineColor_")) || propname.startsWith("lineColor_"))
        {
			if (pItem->series().size() == 0)
				return false;
            QList<QAbstractSeries *> allSeries = pItem->series();
            int index = propname.split("_").last().toInt();
            ((QXYSeries*)allSeries[index])->setColor(value.value<QColor>());
        }
        else if (propname.startsWith(CBaseData::tr("linePointsVisible")) || propname.startsWith("linePointsVisible"))
        {
			if (pItem->series().size() == 0)
				return false;
            QList<QAbstractSeries *> allSeries = pItem->series();
            int index = propname.split("_").last().toInt();
            ((QXYSeries*)allSeries[index])->setPointsVisible(value.toBool());
        }
        else if (propname == CBaseData::tr("barAxisXCategorys") || propname == "barAxisXCategorys")
		{
			QBarCategoryAxis* axisX = (QBarCategoryAxis*)pItem->axisX();
			if (axisX)
				axisX->setCategories(value.toString().split(","));
		}
        else if (propname == CBaseData::tr("barCategoryValues") || propname == "barCategoryValues")
		{
			if (pItem->series().size() == 0)
				return false;
			QBarSeries* series = (QBarSeries*)pItem->series().at(0);
			QList<QBarSet*> sets = series->barSets();

			QBarCategoryAxis* axisX = (QBarCategoryAxis*)pItem->axisX();
			if (axisX)
			{
				QStringList vals = value.toString().split(",");
				if (axisX->categories().size() != vals.size())
					return false;
				for (int valI = 0; valI < vals.size(); valI++)
				{
					QStringList barVals = vals[valI].split(" ");
					if (barVals.size() != sets.size())
						continue;
					for (int barI = 0; barI < sets.size(); barI++)
					{
						if (sets[barI]->count() <= valI)
							sets[barI]->insert(valI, barVals[barI].toFloat());
						else
						    sets[barI]->replace(valI, barVals[barI].toFloat());
					}
				}
			}
		}
        else if (propname == CBaseData::tr("barAxisYTitle") || propname == "barAxisYTitle")
        {
            QValueAxis* axisy = (QValueAxis*)pItem->axisY();
            if (axisy)
                axisy->setTitleText(value.toString());
        }
        else if (propname == CBaseData::tr("barAxisYmin") || propname == "barAxisYmin")
        {
            QValueAxis* axisy = (QValueAxis*)pItem->axisY();
            if (axisy)
                axisy->setMin(value.toReal());
        }
        else if (propname == CBaseData::tr("barAxisYmax") || propname == "barAxisYmax")
		{
			QValueAxis* axisy = (QValueAxis*)pItem->axisY();
			if (axisy)
				axisy->setMax(value.toReal());
		}
        else if (propname == CBaseData::tr("barAxisYAdapte") || propname == "barAxisYAdapte")
        {
			m_axisYAdapte = value.toBool();
        }
        else if (propname == CBaseData::tr("showCurve") || propname == "showCurve")
		{
			m_showCurve = value.toBool();
			pItem->ShowCurve(m_showCurve);
		}
        else if (propname.startsWith(CBaseData::tr("barSet")) || propname.startsWith("barSet"))
		{
			if (pItem->series().size() == 0)
				return false;
			QBarSeries* series = (QBarSeries*)pItem->series().at(0);
			int index = propname.split("_").last().toInt();
            if (propname.contains(CBaseData::tr("Label")) || propname.contains("Label"))
				series->barSets().at(index)->setLabel(value.toString());
            else if (propname.contains(CBaseData::tr("Color")) || propname.contains("Color"))
				series->barSets().at(index)->setColor(value.value<QColor>());
		}
        else if (propname == CBaseData::tr("lineAxisXTitle") || propname == "lineAxisXTitle")
        {
            QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
            if (axisx)
                axisx->setTitleText(value.toString());
        }
        else if (propname == CBaseData::tr("lineAxisXTickCount") || propname == "lineAxisXTickCount")
        {
            QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
            if (axisx)
                axisx->setTickCount(value.toInt());
        }
        else if (propname == CBaseData::tr("lineAxisXFormat") || propname == "lineAxisXFormat")
        {
            QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
			if (axisx)
			{
				if (value.type()==QVariant::String)
				    axisx->setFormat(value.toString());
				else if (value.type() == QVariant::Int)
				{
					QMap<QString, QVariant> formatMap;
					formatMap[("hh:mm:ss")] = 0;
					formatMap[("MM-dd")] = 1;
					formatMap[("MM-dd hh")] = 2;
					formatMap[("yyyy-MM-dd")] = 3;
					formatMap[("yyyy-MM-dd hh:mm:ss")] = 4;
					QString formatStr = formatMap.key(value.toInt());
					axisx->setFormat(formatStr);
				}
			}
                
        }
        else if (propname == CBaseData::tr("lineAxisXFromTime") || propname == "lineAxisXFromTime")
		{
			//if (m_chartType != RealTime)
			{
				QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
				if (axisx)
				{
					int range = axisx->min().msecsTo(axisx->max()) / 1000;
					if (value.type() == QVariant::DateTime)
						axisx->setMin(value.toDateTime());
					else 
						axisx->setMin(pItem->getDateTime(value.toString(), axisx->format()));

					axisx->setMax(axisx->min().addSecs(range));
				}
			}
		}
        else if (propname == CBaseData::tr("lineAxisXTimeSpace-s") || propname == "lineAxisXTimeSpace-s")
		{
				m_timeSpace = value.toUInt();
		}
        else if (propname == CBaseData::tr("sampleMode") || propname == "sampleMode")
		{
				m_sampleMode = value.toInt();
		}
        else if (propname == CBaseData::tr("lineAxisXRange-s") || propname == "lineAxisXRange-s")
        {
            QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
            if (axisx)
                axisx->setMax(axisx->min().addSecs(value.toInt()));
        }
        else if (propname == CBaseData::tr("lineAxisYTitle") || propname == "lineAxisYTitle")
        {
            QValueAxis* axisy = (QValueAxis*)pItem->axisY();
            if (axisy)
                axisy->setTitleText(value.toString());
        }
        else if (propname == CBaseData::tr("lineAxisYmin") || propname == "lineAxisYmin")
        {
            QValueAxis* axisy = (QValueAxis*)pItem->axisY();
            if (axisy)
                axisy->setMin(value.toReal());
        }
        else if (propname == CBaseData::tr("lineAxisYmax") || propname == "lineAxisYmax")
        {
            QValueAxis* axisy = (QValueAxis*)pItem->axisY();
            if (axisy)
                axisy->setMax(value.toReal());
        }
        else if (propname == CBaseData::tr("lineAxisYAdapte") || propname == "lineAxisYAdapte")
		{
			m_axisYAdapte = value.toBool();
		}
        else if (propname == CBaseData::tr("addAxisNum") || propname == "addAxisNum")
        {
            int count = value.toInt();
            QList<QAbstractAxis*> addAxes = pItem->GetAddAxes();
            if (count < addAxes.size())
            {
                pItem->RemoveAdditionalAxis(count);
            }
            else
            {
				for (int i = 0; i < count - addAxes.size(); i++){
					QValueAxis* ax = new QValueAxis();
					pItem->addAxis(ax, Qt::AlignRight);
					pItem->InsertAdditionalAxis(ax);
				}
            }
        }
        else if (propname.startsWith(CBaseData::tr("addAxis")) || propname.startsWith("addAxis"))
        {
            QList<QAbstractAxis*> addAxes = pItem->GetAddAxes();
            int index = propname.split("_").last().toInt();
            if (propname.contains(CBaseData::tr("Type")) || propname.contains("Type"))
            {
                int newType = value.toInt();
                QAbstractAxis* ax = NULL;
                switch (newType)
                {
                case QAbstractAxis::AxisTypeValue:
                {
                    ax = new QValueAxis();
                }
                    break;
                case QAbstractAxis::AxisTypeCategory:
                {
                    ax = new QCategoryAxis();
                }
                    break;
                }
                if (ax)
                {
                    ax->setTitleText(addAxes[index]->titleText());
                    //ax->setLinePenColor(addAxes[index]->linePenColor());
                    pItem->removeAxis(addAxes[index]);
                    pItem->InsertAdditionalAxis(ax, index);
                }
            }
            else if (propname.contains(CBaseData::tr("Align")) || propname.contains("Align"))
            {
				QAbstractAxis *axis = addAxes[index];
				pItem->removeAxis(axis);
				pItem->addAxis(axis, (Qt::Alignment)value.toInt());
            }
            else if (propname.contains(CBaseData::tr("Title")) || propname.contains("Title"))
            {
                addAxes[index]->setTitleText(value.toString());
            }
            else if (propname.contains(CBaseData::tr("Color")) || propname.contains("Color"))
            {
				QColor cor;
				if (value.type() == QVariant::Color)
					cor = value.value<QColor>();
				else
					cor = QColor(value.toString());
				addAxes[index]->setLinePenColor(cor);
				addAxes[index]->setGridLinePen(QPen(cor));
            }
            else if (propname.contains(CBaseData::tr("Min")) || propname.contains("Min"))
            {
                addAxes[index]->setMin(value);
            }
            else if (propname.contains(CBaseData::tr("Max")) || propname.contains("Max"))
            {
                addAxes[index]->setMax(value);
            }
            else if (propname.contains(CBaseData::tr("TickCount")) || propname.contains("TickCount"))
            {
                ((QValueAxis*)addAxes[index])->setTickCount(value.toInt());
            }
            else if (propname.contains(CBaseData::tr("CategoryLabels")) || propname.contains("CategoryLabels"))
            {
                newCategoryLabels = value.toString();
            }
            else if (propname.contains(CBaseData::tr("CategoryEndValues")) || propname.contains("CategoryEndValues"))
            {
				QStringList old = ((QCategoryAxis*)addAxes[index])->categoriesLabels();
				for (int i = 0; i < old.size(); i++)
					((QCategoryAxis*)addAxes[index])->remove(old[i]);     

                QString categoryVal = value.toString();
                QStringList cates = newCategoryLabels.split(",");
                QStringList vals = categoryVal.split(",");
                pItem->CategoryAxisAppend((QCategoryAxis*)addAxes[index], cates, vals);
            }
        }
		else if (propname == "showCursor"){
			pItem->CorsorVisible(value.toBool());
			setProperty(propname.toStdString().c_str(), value);
		}
        else
            return CBaseData::SetProperty(propname, value);
    }
    else
        return CBaseData::SetProperty(propname, value);

	return true;
}

QVariant CGChartData::Property(QString name, bool allprop)
{
	CGChartItem* pItem = dynamic_cast<CGChartItem*>(Item());
	
	if (name == "seriesType")
	{
		return pItem->GetSeriesType();
	}
	else if (name == "chartType")
	{
		return m_chartType;
	}
	else if (name == "sampleMode")
	{
		return m_sampleMode;
	}
	else
		return CBaseData::Property(name, allprop);
}

QVariant CGChartData::GetHistorySampleTime()
{
	CGChartItem* pItem = dynamic_cast<CGChartItem*>(Item());
	if (pItem)
	{
		QDateTimeAxis* axisx = (QDateTimeAxis*)pItem->axisX();
		if (axisx)
		{
			QVariantMap timeInfo;
			timeInfo["startTime"] = axisx->min().toTime_t();
			timeInfo["endTime"] = axisx->max().toTime_t();
			timeInfo["timeSpace"] = m_timeSpace;
			return timeInfo;
		}
	}
	return QVariant();
}

QGraphicsItem* CGChartData::Clone()
{
    return NULL;
}

QObject* CGChartData::Chart(){
	CGChartItem* pItem = (CGChartItem*)Item();
	return pItem;
}

CGChartItem::CGChartItem(QGraphicsItem *parent, QGraphicsScene *scene, Qt::WindowFlags wFlags) : QChart(parent, wFlags)
{
    m_pData = new CGChartData(this);
    g_SetData(this, m_pData);
    SetSeriesType(QAbstractSeries::SeriesTypeLine);
    connect(this, SIGNAL(TagsValChanged()), this, SLOT(OnTagsValChanged()));
	m_tooltip = NULL;
	m_tipVLine = NULL;
	setMargins(QMargins(0,0,2,0));
	setAcceptHoverEvents(true);
    bool ifdesigner= !(scene && ((CGraphScene*)scene)->GetSceneType()==Hmi::Explorer);
    setHandlesChildEvents(ifdesigner);
	m_pData->setProperty("showCursor", true);
}
void CGChartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QChart::paint(painter, option, widget);

    if (option->state & QStyle::State_Selected)
    {
        QVector<QPointF> vec;
		vec.reserve(8);
        QRectF rc=rect().adjusted(1,1,-1,-1);
        qreal w = rc.width();
        qreal h = rc.height();
        vec << rc.topLeft() << rc.topRight() <<rc.bottomLeft() << rc.bottomRight() << rc.topLeft() + QPointF(w / 2, 0) << rc.topLeft() + QPointF(0, h / 2) << rc.topRight() + QPointF(0, h / 2) << rc.bottomLeft() + QPointF(w/2, 0);
        g_PaintBoundingRect(scene(),painter, option, boundingRect());
		g_HighlightSelected(scene(), painter, option, vec, CORNER_RECTPAD, false, Qt::cyan);
    }

}
bool CGChartItem::IfDesigner()
{
    bool if_edit_mode = true;
    QGraphicsScene* pscene = scene();
    if (pscene && ((CGraphScene*)pscene)->GetSceneType()==Hmi::Explorer)
    {
        if_edit_mode = false;
    }
    return if_edit_mode;
}

void CGChartItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	//QChart::mousePressEvent(event);
    if(IfDesigner())
        QGraphicsItem::mousePressEvent(event);
    else
    {
        if ( event->button() == Qt::LeftButton && m_pData->property("zoom").toBool())
        {
            QRectF sr = mapToScene(plotArea()).boundingRect();
            m_startPos = event->scenePos();
            if (sr.contains(m_startPos))
                m_rubberBand = new QRubberBand(QRubberBand::Rectangle, this->scene()->views().first());
        }
    }
}
void CGChartItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	//QChart::mouseMoveEvent(event);
    if(IfDesigner())
		QGraphicsItem::mouseMoveEvent(event);
    else if ( m_pData->property("zoom").toBool()){
		if(event->buttons() & Qt::LeftButton)
		{
			int distance = (event->scenePos() - m_startPos).manhattanLength();
			if (distance >= QApplication::startDragDistance())
			{
				if (m_rubberBand != NULL)
				{
					m_isMoving = true;
					QRectF rct = QRectF(m_startPos, event->scenePos());
					m_rubberBand->setGeometry(rct.toRect().normalized());
					if (rct.width() < 0 || rct.height() < 0)
						m_rubberBand->setWhatsThis("zoomOut");					
					m_rubberBand->show();
				}
			}
		}
	}
	else
		QChart::mouseMoveEvent(event);
}

void CGChartItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	//QChart::mouseReleaseEvent(event);
    if(IfDesigner())
        QGraphicsItem::mouseReleaseEvent(event);
    else if (  event->button() == Qt::LeftButton && m_pData->property("zoom").toBool() && m_isMoving)
	{
		m_rubberBand->hide();
		m_isMoving = false;
		if (m_rubberBand->whatsThis()=="zoomOut")
			zoomOut();
		else{
			QRectF rct = mapFromScene(m_rubberBand->geometry()).boundingRect();

			QPointF startVal = mapToValue(m_rubberBand->geometry().topLeft() - this->scenePos());
			QPointF endVal = mapToValue(m_rubberBand->geometry().bottomRight() - this->scenePos());

			if (endVal.x() - startVal.x()>1000)// less than 1s, not do zoomIn
				zoomIn(rct);
		}
		m_rubberBand = NULL;
	}
}
void CGChartItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
   // QChart::mouseDoubleClickEvent(event);
}

void CGChartItem::RemoveAllSeries(QStringList tagInfo)
{
	if (tagInfo.size() == 0)
	{
		this->m_tagsChart.clear();
		removeAllSeries();
	}
	else
	{
		for (int i = 0; i < tagInfo.size();i++){
			QAbstractSeries* obj = (QAbstractSeries*)GetChartByTag(tagInfo[i]);
			if (obj)
			{
				removeSeries(obj);
			}
			m_tagsChart.remove(tagInfo[i]);
		}
	}
	AxisYAdape(0,false);
}

void CGChartItem::RomoveSeries(QObject* seriesObj)
{
	QAbstractSeries* abSeries = (QAbstractSeries*)seriesObj;
	if (abSeries)
	{
		removeSeries(abSeries);
		AxisYAdape(0, false);
	}
}

void CGChartItem::RemoveExtreme(QStringList tagInfo)
{
	if (tagInfo.size() == 0)
	{
		ExtremeValue(false);
	}
	else
	{
		for (int i = 0; i < tagInfo.size(); i++){
			QMap<QString, QObject*>::iterator maxItr = m_tagsExtremeTips.find(tagInfo[i].append(":max"));
			QMap<QString, QObject*>::iterator minItr = m_tagsExtremeTips.find(tagInfo[i].append(":min"));
			QMap<QString, QObject*>::iterator avgItr = m_tagsExtremeTips.find(tagInfo[i].append(":average"));
			if (maxItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* maxTip = (QGraphicsTextItem*)maxItr.value();
				scene()->removeItem(maxTip);
			}

			if (minItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* minTip = (QGraphicsTextItem*)minItr.value();
				scene()->removeItem(minTip);
			}
			if (avgItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* avgTip = (QGraphicsTextItem*)avgItr.value();
				scene()->removeItem(avgTip);
			}
			m_tagsExtremeTips.remove(tagInfo[i].append(":max"));
			m_tagsExtremeTips.remove(tagInfo[i].append(":min"));
			m_tagsExtremeTips.remove(tagInfo[i].append(":average"));
		}
	}
}

void CGChartItem::RemoveAllAxes()
{
    QList<QAbstractAxis*> axes = this->axes();
	foreach(QAbstractAxis* axis, axes)
    {
        removeAxis(axis);
    }
    m_addAxes.clear();
}

void CGChartItem::CreateDefaultAxes()
{
    createDefaultAxes();
}
qreal CGChartItem::PlotAreaWidth()
{
    return plotArea().width()-margins().left()-margins().right();
}
void CGChartItem::Scroll(qreal dx, qreal dy)
{
    scroll(dx, dy);
}
void CGChartItem::Resize(qreal w, qreal h)
{
    resize(w, h);
}
void CGChartItem::SetMargins(int left, int top, int right, int bottom)
{
    this->setMargins(QMargins(left, top, right, bottom));
}
void CGChartItem::SetTheme(int themeType)
{
    setTheme(QChart::ChartTheme(themeType));
}
void CGChartItem::SetAnimationOptions(int options)
{
    setAnimationOptions(  QChart::AnimationOptions(options) );
}
QObject* CGChartItem::Legend()
{
    return this->legend();
}
void CGChartItem::SetLegendAlign( QString alignment)
{
    QLegend* qlegend = legend();
    if (!qlegend)
        return;

    Qt::Alignment align;
    if (alignment == "left")
    {
        align = Qt::AlignLeft;
    }
    else if (alignment == "right")
    {
        align = Qt::AlignRight;
    }
    else if (alignment == "hcenter")
    {
        align = Qt::AlignHCenter;
    }
    else if (alignment == "justify")
    {
        align = Qt::AlignJustify;
    }
    else if (alignment == "top")
    {
        align = Qt::AlignTop;
    }
    else if (alignment == "bottom")
    {
        align = Qt::AlignBottom;
    }
    else if (alignment == "vcenter")
    {
        align = Qt::AlignVCenter;
    }
    else if (alignment == "baseline")
    {
        align = Qt::AlignBaseline;
    }
    else if (alignment == "center")
    {
        align = Qt::AlignCenter;
    }
    else
        return ;

    qlegend->setAlignment(align);
}
void CGChartItem::ZoomIn()
{
    zoomIn();
}
void CGChartItem::ZoomOut()
{
    zoomOut();
}
void CGChartItem::ZoomIn(qreal x, qreal y, qreal width, qreal height)
{

	QRectF rct = QRectF(QPointF(x, y), QSizeF(width, height));

	QPointF startVal = mapToValue(QPointF(x, y) - this->scenePos());
	QPointF endVal = mapToValue(rct.bottomRight() - this->scenePos());

	if (endVal.x() - startVal.x()>1000)// less than 1s, not do zoomIn
		zoomIn(rct);
}
void CGChartItem::Zoom(qreal factor)
{
    zoom(factor);
}
void CGChartItem::ZoomReset()
{
    zoomReset();
}
bool CGChartItem::IsZoomed()
{
    return isZoomed();
}
QObject* CGChartItem::AddSeries(int type)
{
    switch (type)
    {
    case QAbstractSeries::SeriesTypeLine:
    {
        QLineSeries* series = new QLineSeries;
        addSeries(series);

		QList<QAbstractAxis*> axs = axes();	
		for (int j = 0; j < axs.size(); j++){
			if (!GetAddAxes().contains(axs[j]))
				series->attachAxis(axs[j]);
		}			
		ConnectMarkers();
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeArea:
    {
        QAreaSeries* series = new QAreaSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeBar:
    {
        QBarSeries* series = new QBarSeries;
        addSeries(series);
		QList<QAbstractAxis*> axs = axes();
		for (int j = 0; j < axs.size(); j++){
			if (!GetAddAxes().contains(axs[j]))
				series->attachAxis(axs[j]);
		}
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeStackedBar:
    {
        QStackedBarSeries* series = new QStackedBarSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypePercentBar:
    {
        QPercentBarSeries* series = new QPercentBarSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypePie:
    {
        QPieSeries* series = new QPieSeries;
		addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeScatter:
    {
        QScatterSeries* series = new QScatterSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeSpline:
    {
        QSplineSeries* series = new QSplineSeries;
        addSeries(series);
		QList<QAbstractAxis*> axs = axes();
		for (int j = 0; j < axs.size(); j++){
			if (!GetAddAxes().contains(axs[j]))
				series->attachAxis(axs[j]);
		}
		ConnectMarkers();
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeHorizontalBar:
    {
        QHorizontalBarSeries* series = new QHorizontalBarSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeHorizontalStackedBar:
    {
        QHorizontalStackedBarSeries* series = new QHorizontalStackedBarSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeHorizontalPercentBar:
    {
        QHorizontalPercentBarSeries* series = new QHorizontalPercentBarSeries;
        addSeries(series);
        return series;
    }
        break;
    case QAbstractSeries::SeriesTypeBoxPlot:
    {
        QBoxPlotSeries* series = new QBoxPlotSeries;
        addSeries(series);
        return series;
    }
        break;
    default:
    {
        return NULL;
    }
        break;
    }
    return NULL;
}
void CGChartItem::AppendPoint(QObject* seriesObj, qreal x, qreal y, bool adapeY)
{
    QXYSeries* series = (QXYSeries*)seriesObj;
	if (series)
	{
		series->append(x, y);
		if (adapeY)
			AxisYAdape(y);
	}
}
void CGChartItem::AppendTimePoint(QObject* seriesObj, QString timeStr, QString timeFormatStr, qreal y, bool adapeY )
{
	QXYSeries* series = (QXYSeries*)seriesObj;
    if (!series)
        return;
    QDateTime x;
    if (timeStr == "" && timeFormatStr == "")
    {
        x = QDateTime::currentDateTime();
    }
    else
		x = getDateTime(timeStr, timeFormatStr);
    qint64 xVal = x.toMSecsSinceEpoch();
    series->append(xVal, y);
	if (adapeY)
		AxisYAdape(y);
	QDateTimeAxis* lineAxisX = (QDateTimeAxis*)axisX();
	if (lineAxisX)
	{
		int dx = x.msecsTo(lineAxisX->max()) / 1000;
		if (dx <= 0)
		{
			int idx = PlotAreaWidth() / ((lineAxisX->min().msecsTo(lineAxisX->max()) / 1000));
			this->scroll((-dx + 1) *idx, 0);
			qint64 min = lineAxisX->min().toMSecsSinceEpoch();
			if (series->points().size() > 0)
			{
				QPointF first = series->at(0);
				if (first.x()<min)
					series->remove(0);
			}
			
		}
	}

}

void CGChartItem::AppendTimePoint(QObject* seriesObj, uint timeT, qreal y, bool adapeY)
{
	QXYSeries* series = (QXYSeries*)seriesObj;
	if (!series)
		return;
	QDateTime xVal = QDateTime::fromTime_t(timeT);
	series->append(xVal.toMSecsSinceEpoch(), y);
	if (adapeY)
		AxisYAdape(y);
	QDateTimeAxis* lineAxisX = (QDateTimeAxis*)axisX();
	if (lineAxisX)
	{
		int dx = xVal.msecsTo(lineAxisX->max()) / 1000;
		if (dx <= 0)
		{
			int idx = PlotAreaWidth() / ((lineAxisX->min().msecsTo(lineAxisX->max()) / 1000));
			this->scroll((-dx + 1) *idx, 0);
			qint64 min = lineAxisX->min().toMSecsSinceEpoch();
			if (series->points().size() > 0)
			{
				QPointF first = series->at(0);
				if (first.x()<min)
					series->remove(0);
			}
		}
	}
}

void CGChartItem::AppendTimePoint(QObject* seriesObj, QVariantMap points)
{
	QXYSeries* series = (QXYSeries*)seriesObj;
	if (!series)
		return;

	QList<QPointF> xyPoints;
	QVariantMap::iterator itr;
	qreal yMax=-999;
	qreal yMin = 999;
	for (itr = points.begin(); itr != points.end();++itr)
	{
		QDateTime xVal = QDateTime::fromTime_t(itr.key().toInt());
		QPointF p(xVal.toMSecsSinceEpoch(), itr.value().toReal());
		xyPoints.append(p);
		if (yMax < itr.value().toReal())
			yMax = itr.value().toReal();
		if (yMin > itr.value().toReal())
			yMin = itr.value().toReal();
	}
	AxisYAdape(yMax);
	AxisYAdape(yMin);
	series->append(xyPoints);
}

void CGChartItem::ExtremeValue(bool isShow)
{
	if (!isShow){
		QList<QObject*>  m_extremeTips = m_tagsExtremeTips.values();
		for (int i = 0; i < m_extremeTips.size(); i++)
			scene()->removeItem((QGraphicsTextItem*)m_extremeTips[i]);
		m_tagsExtremeTips.clear();
		return;
	}
	QMap<QString, QObject*>::iterator itr;
	int ino = 0;
	for (itr = m_tagsChart.begin(); itr != m_tagsChart.end(); ++itr)
	{
		QXYSeries* series = (QXYSeries*)itr.value();
		if (!series || !series->isVisible())
			continue;
		QList<QPointF> pts = series->points();
		if (pts.size() == 0)
			continue;
		ino++;
		qreal max = -9999;
		qreal min = 9999;
		qreal sum = 0;
		int ptNum = 0;
		qreal average = 0;

		QPointF maxPt;
		QPointF minPt;
		for (int i = 0; i < pts.size(); i++)
		{
			QPointF ptTemp = mapToPosition(pts[i], series);
			if (!plotArea().contains(ptTemp))
				continue;
			
			qreal val = pts[i].y();
			sum += val;
			ptNum++;
			if (val > max)
			{
				max = val;
				maxPt = pts[i];
			}

			if (val < min)
			{
				min = val;
				minPt = pts[i];
			}
		}
		average = sum / ptNum;
		/*ret["max"] = QString::number(max, 'f', 2);
		ret["min"] = QString::number(min, 'f', 2);
		ret["average"] = QString::number(sum / pts.size(), 'f', 2);*/

		//text 
		QGraphicsTextItem* maxTip = scene()->addText("");
		QGraphicsTextItem* minTip = scene()->addText("");
		QGraphicsTextItem* avgTip = scene()->addText("");
		QDateTimeAxis* axisx = (QDateTimeAxis*)axisX();
			
		qreal maxVal = maxPt.y();
		QString maxTime = QDateTime::fromMSecsSinceEpoch(maxPt.x()).toString(axisx->format());
        maxTip->setPlainText(CBaseData::tr("MaxValue: %1\n    Time: %2").arg(QString::number(maxVal, 'f', 2)).arg(maxTime));
		maxTip->setDefaultTextColor(series->color());
		maxTip->setPos(scenePos() + mapToPosition(maxPt, series) + QPoint(10, -40));

		qreal minVal = minPt.y();
		QString minTime = QDateTime::fromMSecsSinceEpoch(minPt.x()).toString(axisx->format());
        minTip->setPlainText(CBaseData::tr("MinValue: %1\n    Time: %2").arg(QString::number(minVal, 'f', 2)).arg(minTime));
		minTip->setDefaultTextColor(series->color());
		minTip->setPos(scenePos() + mapToPosition(minPt, series) + QPoint(10, 5));

		avgTip->setPlainText(CBaseData::tr("AverageValue: %1").arg(QString::number(average, 'f', 2)));
		avgTip->setDefaultTextColor(series->color());
		avgTip->setPos(scenePos() + QPoint(plotArea().width() - 50, 50+30 * ino));

		QString taginfo = itr.key();
		m_tagsExtremeTips.insert(taginfo.append(":max"), maxTip);
		m_tagsExtremeTips.insert(taginfo.append(":min"), minTip);
		m_tagsExtremeTips.insert(taginfo.append(":average"), avgTip);
	}
}

QObject* CGChartItem::AppendPieSlice(QObject* pieSeriesObj, QString label, qreal value)
{
    QPieSeries* series = (QPieSeries*)pieSeriesObj;
    if (series)
        return (QObject*)(series->append(label, value));
    return NULL;
}
QObject* CGChartItem::AppendBarSet(QObject* barSeriesObj, QString label, QStringList values)
{
    QBarSeries* series = (QBarSeries*)barSeriesObj;
    if (series)
    {
        QBarSet* barset = new QBarSet(label);
		
		foreach(QString val, values)
        {
            barset->append(val.toDouble());
			AxisYAdape(val.toDouble());
        }
        series->append(barset);
        return barset;
    }
    return NULL;
}
void CGChartItem::SetXYSeriesColor(QObject* seriesObj, QString color)
{
    QXYSeries* series = (QXYSeries*)seriesObj;
    if (series)
        series->setColor(QColor(color));
}
QString CGChartItem::GetXYSeriesColor(QObject* seriesObj)
{
    QXYSeries* series = (QXYSeries*)seriesObj;
    if (series)
        return series->color().name();
    return "";
}
void CGChartItem::SeriesClear(QObject* seriesObj)
{
    QAbstractSeries* abSeries = (QAbstractSeries*)seriesObj;
    if (abSeries)
    {
        int type = abSeries->type();
        switch (type)
        {
        case QAbstractSeries::SeriesTypeLine:
        {
            QLineSeries* series = (QLineSeries*)abSeries;
            //series->clear();
			QList<QPointF> plst;
			series->replace(plst);
        }
            break;
        case QAbstractSeries::SeriesTypeArea:
        {
            QAreaSeries* series = (QAreaSeries*)abSeries;
            series->upperSeries()->clear();
            series->lowerSeries()->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeBar:
        {
            QBarSeries* series = (QBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeStackedBar:
        {
            QStackedBarSeries* series = (QStackedBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypePercentBar:
        {
            QPercentBarSeries* series = (QPercentBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypePie:
        {
            QPieSeries* series = (QPieSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeScatter:
        {
            QScatterSeries* series = (QScatterSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeSpline:
        {
            QSplineSeries* series = (QSplineSeries*)abSeries;
           // series->clear();
			QList<QPointF> plst;
			series->replace(plst);
        }
            break;
        case QAbstractSeries::SeriesTypeHorizontalBar:
        {
            QHorizontalBarSeries* series = (QHorizontalBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeHorizontalStackedBar:
        {
            QHorizontalStackedBarSeries* series = (QHorizontalStackedBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeHorizontalPercentBar:
        {
            QHorizontalPercentBarSeries* series = (QHorizontalPercentBarSeries*)abSeries;
            series->clear();
        }
            break;
        case QAbstractSeries::SeriesTypeBoxPlot:
        {
            QBoxPlotSeries* series = (QBoxPlotSeries*)abSeries;
            series->clear();
        }
            break;
        default:
            break;
        }
    }
}
void CGChartItem::SetSeriesName(QObject* seriesObj, QString name)
{
	if (seriesObj->inherits("QtCharts::QBarSet"))
	 {
		((QBarSet*)seriesObj)->setLabel(name);
	 }
	 else if (seriesObj->inherits("QtCharts::QPieSlice"))
	 {
		 ((QPieSlice*)seriesObj)->setLabel(name);
	 }
	 else
	 {
		QAbstractSeries* abSeries = (QAbstractSeries*)seriesObj;
		if (abSeries)
		{
			abSeries->setName(name);
		}
	 }
}
QObject* CGChartItem::AddAxis(int axisType, QString alignment)
{
    Qt::Alignment align;
    if (alignment == "left")
    {
        align = Qt::AlignLeft;
    }
    else if (alignment == "right")
    {
        align = Qt::AlignRight;
    }
    else if (alignment == "hcenter")
    {
        align = Qt::AlignHCenter;
    }
    else if (alignment == "justify")
    {
        align = Qt::AlignJustify;
    }
    else if (alignment == "top")
    {
        align = Qt::AlignTop;
    }
    else if (alignment == "bottom")
    {
        align = Qt::AlignBottom;
    }
    else if (alignment == "vcenter")
    {
        align = Qt::AlignVCenter;
    }
    else if (alignment == "baseline")
    {
        align = Qt::AlignBaseline;
    }
    else if (alignment == "center")
    {
        align = Qt::AlignCenter;
    }
    else
        return NULL;


    switch (axisType)
    {
    case QAbstractAxis::AxisTypeNoAxis:
    {
        return NULL;
    }
        break;
    case QAbstractAxis::AxisTypeValue:
    {
        QValueAxis *axis = new QValueAxis;
        addAxis(axis, align);
        return axis;
    }
        break;
    case QAbstractAxis::AxisTypeBarCategory:
    {
        QBarCategoryAxis *axis = new QBarCategoryAxis;
        addAxis(axis, align);
        return axis;
    }
        break;
    case QAbstractAxis::AxisTypeCategory:
    {
        QCategoryAxis *axis = new QCategoryAxis;
        addAxis(axis, align);
        return axis;
    }
        break;
    case QAbstractAxis::AxisTypeDateTime:
    {
        QDateTimeAxis *axis = new QDateTimeAxis;
        addAxis(axis, align);
        return axis;
    }
        break;
    case QAbstractAxis::AxisTypeLogValue:
    {
        QLogValueAxis *axis = new QLogValueAxis;
        addAxis(axis, align);
        return axis;
    }
        break;
    default:
    {
        return NULL;
    }
        break;
    }
    return NULL;
}
void CGChartItem::SetLinePenColor(QObject* axisObj, QString color)
{
    QAbstractAxis* axis = (QAbstractAxis*)axisObj;
    if (axis)
        axis->setLinePenColor(QColor(color));
}
void CGChartItem::SetGridLineColor(QObject* axisObj, QString color)
{
    QAbstractAxis* axis = (QAbstractAxis*)axisObj;
    if (axis)
        axis->setGridLinePen(QColor(color));
}
bool CGChartItem::AttachAxis(QObject* seriesObj, QObject* axisObj)
{
    QAbstractSeries* series = (QAbstractSeries*)seriesObj;
    QAbstractAxis* axis = (QAbstractAxis*)axisObj;
    if (series && axis)
        return series->attachAxis(axis);

    return false;
}
void CGChartItem::BarAxisAppendCategery(QObject* axisObj, QStringList categories)
{
    QBarCategoryAxis* axis = (QBarCategoryAxis*)axisObj;
    if (axis)
        axis->append(categories);
}
void CGChartItem::CategoryAxisAppend(QObject* axisObj, QStringList categories, QStringList categoryEndValue)
{
    QCategoryAxis* axis = (QCategoryAxis*)axisObj;
    if (!axis)
        return;

    if (categories.size() != categoryEndValue.size())
        return;

    for (int i = 0; i < categories.size(); i++)
    {
        axis->append(categories.at(i), categoryEndValue.at(i).toDouble());
    }
}
void CGChartItem::ReplaceTagInfo(QString oldTagName, QString tagName)
{
	QString newUserData = m_pData->GetUserData().replace(oldTagName, tagName);
	RemoveAllSeries(QStringList() << oldTagName);
	m_pData->SetProperty("userData", newUserData);
}
void CGChartItem::OnTagsValChanged()
{
    QMap<QString, QVariant>::iterator itr;
    for (itr = m_tagsVal.begin(); itr != m_tagsVal.end();++itr)
    {
        QString tagName = itr.key();
        qreal tagVal = itr.value().toReal();

        QMap<QString, QObject*>::iterator cItr = m_tagsChart.find(tagName);
        if (cItr != m_tagsChart.end())
        {
            switch (m_seriesType)
            {
            case QAbstractSeries::SeriesTypePie:
            {
                QPieSlice* slice = (QPieSlice*)cItr.value();
                slice->setValue(tagVal);
            }
                break;
            case QAbstractSeries::SeriesTypeBar:
            {
                QBarSet* set = (QBarSet*)cItr.value();
                set->replace(0, tagVal);
				AxisYAdape(tagVal);
            }
                break;
            case QAbstractSeries::SeriesTypeSpline:
            case QAbstractSeries::SeriesTypeLine:
            {
                QXYSeries* series = (QXYSeries*)cItr.value();
                AppendTimePoint(series, "", "", tagVal);				
            }
                break;
            }
        }
    }
}
void CGChartItem::SetSeriesType(int type){
    m_seriesType = type;
	RemoveAllSeries();
	RemoveAllAxes();
    switch (m_seriesType)
    {
    case QAbstractSeries::SeriesTypeBar:
    {
        QBarCategoryAxis* barAxisX = (QBarCategoryAxis*)AddAxis(QAbstractAxis::AxisTypeBarCategory, "bottom");
        BarAxisAppendCategery(barAxisX, QStringList()<<CBaseData::tr("tags"));
        QValueAxis* barAxisY = (QValueAxis*)AddAxis(QAbstractAxis::AxisTypeValue, "left");
        barAxisY->setMin(0.0);
        barAxisY->setMax(10);
        barAxisY->setTitleText(CBaseData::tr("value"));
    }
        break;
    case QAbstractSeries::SeriesTypeSpline:
    case QAbstractSeries::SeriesTypeLine:
    {
        QDateTimeAxis* lineAxisX = (QDateTimeAxis*)AddAxis(QAbstractAxis::AxisTypeDateTime, "bottom");
        QValueAxis* lineAxisY = (QValueAxis*)AddAxis(QAbstractAxis::AxisTypeValue, "left");
        //lineAxisX->setTitleText(CBaseData::tr("time"));
        lineAxisX->setTickCount(5);
        lineAxisX->setFormat("hh:mm:ss");
        lineAxisX->setMin(QDateTime::currentDateTime());
        lineAxisX->setMax(QDateTime::currentDateTime().addSecs(60));
        //lineAxisY->setTitleText(CBaseData::tr("value"));
        lineAxisY->setMin(0);
        lineAxisY->setMax(10);
    }
        break;
    }

}
void CGChartItem::InsertAdditionalAxis(QAbstractAxis* axis, int index)
{
    if (index < 0)
        m_addAxes.append(axis);
    else
        m_addAxes.replace(index, axis);
}
void CGChartItem::RemoveAdditionalAxis(int retainCount)
{
    if (retainCount < m_addAxes.size())
    {
        for (int i = retainCount; i < m_addAxes.size(); i++)
            removeAxis(m_addAxes[i]);
        m_addAxes = m_addAxes.mid(0, retainCount);
    }
}
void CGChartItem::ConnectMarkers()
{
    foreach(QLegendMarker* marker, legend()->markers()) {

        disconnect(marker, SIGNAL(clicked()), this, SLOT(HandleMarkerClicked()));
        connect(marker, SIGNAL(clicked()), this, SLOT(HandleMarkerClicked()));
    }
	
	if (m_seriesType == QAbstractSeries::SeriesTypePie)
	{
		if (series().size() == 0)
			return ;
		QPieSeries* se = (QPieSeries*)(series().at(0));
		foreach(QPieSlice* slice, se->slices()) {
			connect(slice, SIGNAL(hovered(bool)), this, SLOT(ShowPieSliceHighlight(bool)));
		}
	}
	if (m_seriesType == QAbstractSeries::SeriesTypeBar)
	{
		if (series().size() == 0)
			return;
		QBarSeries* se = (QBarSeries*)(series().at(0));
		foreach(QBarSet* set, se->barSets()) {
			connect(set, SIGNAL(hovered(bool, int)), this, SLOT(ShowBarHovered(bool, int)));
		}
	}
	else if (m_seriesType == QAbstractSeries::SeriesTypeLine || m_seriesType == QAbstractSeries::SeriesTypeSpline)
	{
		if (series().size() == 0)
			return;
		foreach(QAbstractSeries* se, series()) {
			QXYSeries* xySr = (QXYSeries*)(se);
			connect(xySr, SIGNAL(hovered(QPointF, bool)), this, SLOT(ShowCurveTooltip(QPointF, bool)));
		}
	}
}
void CGChartItem::HandleMarkerClicked()
{
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    Q_ASSERT(marker);
	qreal alpha = 1.0;
	marker->setVisible(true);
    switch (marker->type())
    {
		case QLegendMarker::LegendMarkerTypeXY:
		{
			bool vi = marker->series()->isVisible();
			marker->series()->setVisible(!vi);
			marker->setVisible(true);
			if (!marker->series()->isVisible()) {
				alpha = 0.5;
			}
			//tip
			QString tag = m_tagsChart.key(marker->series());
			if (tag.isEmpty())
				break;

			QMap<QString, QObject*>::iterator maxItr = m_tagsExtremeTips.find(tag.append(":max"));
			QMap<QString, QObject*>::iterator minItr = m_tagsExtremeTips.find(tag.append(":min"));
			QMap<QString, QObject*>::iterator avgItr = m_tagsExtremeTips.find(tag.append(":average"));
			if (maxItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* maxTip = (QGraphicsTextItem*)maxItr.value();
				maxTip->setVisible(!vi);
			}

			if (minItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* minTip = (QGraphicsTextItem*)minItr.value();
				minTip->setVisible(!vi);
			}
		    
			if (avgItr != m_tagsExtremeTips.end()){
				QGraphicsTextItem* avgTip = (QGraphicsTextItem*)avgItr.value();
				scene()->removeItem(avgTip);
			}

			break;
		}
		case QLegendMarker::LegendMarkerTypeBar:
		{
			/*QBarLegendMarker* barMarker = (QBarLegendMarker*)marker;
			barMarker->barset()->setLabel(barMarker->barset()->label().isEmpty() ? barMarker->label():"");

			if (barMarker->barset()->label().isEmpty()) {
				alpha = 0.5;
			}							 
				*/								  
			break;
		}
		case QLegendMarker::LegendMarkerTypePie:
		{
			QPieLegendMarker* pieMarker = (QPieLegendMarker*)marker;

			pieMarker->slice()->setLabelVisible(!pieMarker->slice()->isLabelVisible());
			pieMarker->slice()->setExploded(pieMarker->slice()->isLabelVisible());

			if (!pieMarker->slice()->isLabelVisible()) {
				alpha = 0.5;										  
			}
											  
			break;
		}
		default:
		{
			//qDebug() << "Unknown marker type";
			break;
		}
		
    }
	QColor color;
	QBrush brush = marker->labelBrush();
	color = brush.color();
	color.setAlphaF(alpha);
	brush.setColor(color);
	marker->setLabelBrush(brush);

	brush = marker->brush();
	color = brush.color();
	color.setAlphaF(alpha);
	brush.setColor(color);
	marker->setBrush(brush);

	QPen pen = marker->pen();
	color = pen.color();
	color.setAlphaF(alpha);
	pen.setColor(color);
	marker->setPen(pen);
}
void CGChartItem::ShowPieSliceHighlight(bool show)
{
	QPieSlice* slice = (QPieSlice*)sender();
	if (slice)
	{
		slice->setLabelVisible(show);
		slice->setExploded(show);
	}
}
void CGChartItem::ShowBarHovered(bool status, int index)
{
	QBarSet* set = qobject_cast<QBarSet *>(sender());

	if (status) {
		set->setColor(set->color().lighter(150));
	}
	else {
		set->setColor(set->color().darker(150));
	}
}
void CGChartItem::ShowCurveTooltip(QPointF point, bool state)
{
	if (state) {
		if (IfDesigner() || !m_pData->property("showCursor").toBool())
			return;
		QRectF sr = mapToScene(plotArea()).boundingRect();
		QDateTimeAxis* axisx = (QDateTimeAxis*)axisX();
		if (point.x() < axisx->min().toMSecsSinceEpoch())
			return;
		//text
		if (m_tooltip == NULL)
		{
		    m_tooltip = this->scene()->addText("");
			m_tipVLine = scene()->addLine(point.x(), sr.y(), point.x(), sr.y() + sr.height());
		}
		
		QXYSeries *series = qobject_cast<QXYSeries *>(sender());
		QList<QPointF>	pts= series->points();
		QPointF inPt = point;
		if (point.x() <= pts[0].x())
		{
			inPt = pts[0];
		}
		else if (point.x() > pts[pts.size() - 1].x())
		{
			inPt = pts[pts.size() - 1];
		}
		else{
			for (int i = 0; i < pts.size()-1; i++)
			{
				if (pts[i].x() <= point.x() && point.x() <= pts[i + 1].x())
				{
					qreal dx1 = point.x() - pts[i].x();
					qreal dx2 = pts[i+1].x() - point.x();				
					inPt = (dx1 <= dx2 ? pts[i] : pts[i + 1]);
					break;
				}
			}
		}
		qreal val = inPt.y();
		QString time = QDateTime::fromMSecsSinceEpoch(inPt.x()).toString(axisx->format());
        QString tip=axisx->property("_tip_").toString();
        QString msgtip=tip+"\n"+CBaseData::tr("Time")+QString(": %1\n").arg(time)+CBaseData::tr("Value")+QString(": %1").arg(QString::number(val, 'f', 2));
        m_tooltip->setPlainText(msgtip);
		m_tooltip->setDefaultTextColor(series->pointLabelsColor());
		QPointF tipPt = scenePos() + mapToPosition(inPt, series);
		if (sr.width()-mapToPosition(inPt, series).x()<60)
			m_tooltip->setPos(tipPt - QPoint(60, 0));
		else
			m_tooltip->setPos(tipPt + QPoint(10, 0));
		m_tooltip->show();
		m_tipVLine->setLine(QLineF(tipPt.x(), sr.y(), tipPt.x(), sr.y() + sr.height()));
		m_tipVLine->setPen(QPen("#42a827"));
		m_tipVLine->show();
	}
	else {
		if (m_tooltip){
			m_tooltip->hide();
			m_tipVLine->hide();
		}
	}
}

QStringList CGChartItem::GetAllTags()
{
	QStringList tagNames;
	QMap<QString, QObject*>::iterator itr;
	for (itr = m_tagsChart.begin(); itr != m_tagsChart.end(); ++itr)
	{
		tagNames.append(itr.key());
	}
	return tagNames;
}
QObject* CGChartItem::GetChartByTag(QString tag)
{
	QMap<QString, QObject*>::iterator itr = m_tagsChart.find(tag);
	if (itr != m_tagsChart.end())
		return itr.value();
	else
		return NULL;
}
int CGChartItem::GetBarSetCount(QObject* barSetObj)
{ 
	QBarCategoryAxis* axisX = (QBarCategoryAxis*)this->axisX();
	if (axisX)
		return axisX->categories().size();
	return 0; 
}

void CGChartItem::ReplaceBarSetValue(QObject* barSetObj, int index, qreal value)
{ 
	((QBarSet*)barSetObj)->replace(index, value); 
	AxisYAdape(value);
}

void CGChartItem::ShowCurve(bool showCurve)
{
	if (!showCurve)
	{
		for (int i = 0; i < series().size(); i++)
		{
			if (series().at(i)->type() == QAbstractSeries::SeriesTypeSpline)
			{
				removeSeries(series().at(i));
				i--;
			}		
		}
	}
	else
	{
		QBarSeries* series = (QBarSeries*)(this->series().at(0));
		QList<QBarSet*> sets = series->barSets();

		QBarCategoryAxis* axisX = (QBarCategoryAxis*)this->axisX();
		if (axisX && sets.size()>0)
		{
			for (int barI = 0; barI < sets.size(); barI++)
			{
				QSplineSeries* series = new QSplineSeries;
                //series->setName(sets[barI]->label()+CBaseData::tr("-Curve"));
				series->setColor(sets[barI]->color());
				addSeries(series);
				setAxisX(axisX, series);
				setAxisY(axisY(), series);
				
				for (int valI = 0; valI < axisX->count(); valI++)
				{
					int qval = sets[barI]->at(valI) + 10;
					series->append(valI, qval);
					AxisYAdape(qval);
				}
			}
		}
	}
}
void CGChartItem::AxisYAdape(qreal value, bool extend)
{
	if (m_pData->IsAxisYAdapte())
	{
		QValueAxis* axY = (QValueAxis*)(this->axisY());
		if (axY)
		{
			qreal dx = (axY->max() - axY->min()) / 4;
			if (extend)
			{
				if (axY->max() <= value)
					axY->setMax(value + dx);
				else if (axY->min() >= value)
					axY->setMin(value - dx);
			}
			else if (!extend)
			{
				if (m_tagsChart.size() == 0)
				{
					axY->setMax(10);
					axY->setMin(0);
				}
				else
				{
					qreal max = -9999;
					qreal min = 9999;
					QMap<QString, QObject*>::iterator itr;
					for (itr = m_tagsChart.begin(); itr != m_tagsChart.end(); ++itr)
					{
						QXYSeries* series = (QXYSeries*)itr.value();
						if (!series)
							continue;
						QList<QPointF> pts = series->points();
						if (pts.size() == 0)
							continue;


						for (int i = 0; i < pts.size(); i++)
						{
							QPointF ptTemp = mapToPosition(pts[i], series);
							if (!plotArea().contains(ptTemp))
								continue;

							qreal val = pts[i].y();
							if (val > max)
							{
								max = val;
							}

							if (val < min)
							{
								min = val;
							}
						}
					}
					//gInfo(QString("HMI-chart: y: max: %1, min:%2").arg(max).arg(min).toStdString().data());
					if (max== -9999 && min == 9999)
						return;
					if (max == min)
						max += 10;
					dx = (max - min) / 4;
					axY->setMax(max + dx);
					axY->setMin(min - dx);
				}
			}
		}	
	}
}

QDateTime CGChartItem::getDateTime(const QString &value, const QString &format)
{
	QDateTime ret = QDateTime::fromString(value, format);
	if (format == "hh:mm:ss")
	{
		ret.setDate(QDate::currentDate());
	}
	else if (format == "MM-dd")
	{
		int dx = QDate::currentDate().year() - ret.date().year();
		ret = ret.addYears(dx);
	}
	else if (format == "MM-dd hh")
	{
		int dx = QDate::currentDate().year() - ret.date().year();
		ret = ret.addYears(dx);
	}
	
	return ret;
}
