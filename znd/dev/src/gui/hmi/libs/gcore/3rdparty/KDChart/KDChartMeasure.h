#ifndef KDCHARTMEASURE_H
#define KDCHARTMEASURE_H 

#include <QDebug>
#include <Qt>
#include <QStack>
#include "KDChartGlobal.h"
#include "KDChartEnums.h"







QT_BEGIN_NAMESPACE
class QObject;
class QPaintDevice;
QT_END_NAMESPACE

namespace KDChart {







class KDCHART_EXPORT Measure
{
public:
    Measure();
                 Measure( qreal value,
                          KDChartEnums::MeasureCalculationMode mode = KDChartEnums::MeasureCalculationModeAuto,
                          KDChartEnums::MeasureOrientation orientation = KDChartEnums::MeasureOrientationAuto );
    Measure( const Measure& );
    Measure &operator= ( const Measure& );

    void setValue( qreal val ) { mValue = val; }
    qreal value() const { return mValue; }

    void setCalculationMode( KDChartEnums::MeasureCalculationMode mode ) { mMode = mode; }
    KDChartEnums::MeasureCalculationMode calculationMode() const { return mMode; }





    void setRelativeMode( const QObject * area,
                          KDChartEnums::MeasureOrientation orientation )
    {
        mMode = KDChartEnums::MeasureCalculationModeRelative;
        mArea = area;
        mOrientation = orientation;
    }
    void setAbsoluteValue( qreal val )
    {
        mMode = KDChartEnums::MeasureCalculationModeAbsolute;
        mValue = val;
    }





    void setReferenceArea( const QObject * area ) { mArea = area; }




    const QObject * referenceArea() const { return mArea; }

    void setReferenceOrientation( KDChartEnums::MeasureOrientation orientation ) { mOrientation = orientation; }
    KDChartEnums::MeasureOrientation referenceOrientation() const { return mOrientation; }





    qreal calculatedValue( const QObject * autoArea, KDChartEnums::MeasureOrientation autoOrientation ) const;
    qreal calculatedValue( const QSizeF& autoSize, KDChartEnums::MeasureOrientation autoOrientation ) const;
    const QSizeF sizeOfArea( const QObject* area ) const;

    bool operator==( const Measure& ) const;
    bool operator!=( const Measure& other ) const { return !operator==(other); }

private:
    qreal mValue;
    KDChartEnums::MeasureCalculationMode mMode;
    const QObject* mArea;
    KDChartEnums::MeasureOrientation mOrientation;
};
class GlobalMeasureScaling
{
public:
    static GlobalMeasureScaling* instance();

    GlobalMeasureScaling();
    virtual ~GlobalMeasureScaling();

public:




    static void setFactors(qreal factorX, qreal factorY);





    static void resetFactors();




    static const QPair< qreal, qreal > currentFactors();




    static void setPaintDevice( QPaintDevice* paintDevice );




    static QPaintDevice* paintDevice();

private:
    QStack< QPair< qreal, qreal > > mFactors;
    QPaintDevice* m_paintDevice;
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::Measure& );
#endif

#endif
