#ifndef __KDCHARTENUMS_H__
#define __KDCHARTENUMS_H__ 

#include "KDChartGlobal.h"

#include <QRectF>
#include <QObject>
#include <QVector>
class KDCHART_EXPORT KDChartEnums :public QObject
{
    Q_OBJECT
    Q_ENUMS( TextLayoutPolicy )
    Q_ENUMS( AreaName )
    Q_ENUMS( PositionFlag )

public:
    enum GranularitySequence {
        GranularitySequence_10_20,
        GranularitySequence_10_50,
        GranularitySequence_25_50,
        GranularitySequence_125_25,
        GranularitySequenceIrregular };
    static QString granularitySequenceToString( GranularitySequence sequence ) {
        switch ( sequence ) {
            case GranularitySequence_10_20:
                return QString::fromLatin1("GranularitySequence_10_20");
            case GranularitySequence_10_50:
                return QString::fromLatin1("GranularitySequence_10_50");
            case GranularitySequence_25_50:
                return QString::fromLatin1("GranularitySequence_25_50");
            case GranularitySequence_125_25:
                return QString::fromLatin1("GranularitySequence_125_25");
            case GranularitySequenceIrregular:
                return QString::fromLatin1("GranularitySequenceIrregular");
        }
        Q_ASSERT( !"Unknown GranularitySequenceValue" );
        return QString::fromLatin1("GranularitySequence_10_20");
    }
    static GranularitySequence stringToGranularitySequence( const QString& string ) {
      if ( string == QString::fromLatin1("GranularitySequence_10_20") )
          return GranularitySequence_10_20;
      if ( string == QString::fromLatin1("GranularitySequence_10_50") )
          return GranularitySequence_10_50;
      if ( string == QString::fromLatin1("GranularitySequence_25_50") )
          return GranularitySequence_25_50;
      if ( string == QString::fromLatin1("GranularitySequence_125") )
          return GranularitySequence_125_25;
      if ( string == QString::fromLatin1("GranularitySequenceIrregular") )
          return GranularitySequenceIrregular;

      return GranularitySequence_10_20;
    }
    enum TextLayoutPolicy { LayoutJustOverwrite,
        LayoutPolicyRotate,
        LayoutPolicyShiftVertically,
        LayoutPolicyShiftHorizontally,
        LayoutPolicyShrinkFontSize };
    static QString layoutPolicyToString( TextLayoutPolicy type );
    static TextLayoutPolicy stringToLayoutPolicy( const QString& string );
    enum PositionValue {
        PositionUnknown = 0,
        PositionCenter = 1,
        PositionNorthWest = 2,
        PositionNorth = 3,
        PositionNorthEast = 4,
        PositionEast = 5,
        PositionSouthEast = 6,
        PositionSouth = 7,
        PositionSouthWest = 8,
        PositionWest = 9,
        PositionFloating =10
    };
    enum MeasureCalculationMode { MeasureCalculationModeAbsolute,
        MeasureCalculationModeRelative,
        MeasureCalculationModeAuto,
        MeasureCalculationModeAutoArea,
        MeasureCalculationModeAutoOrientation };
    static QString measureCalculationModeToString( MeasureCalculationMode mode ) {
        switch ( mode ) {
            case MeasureCalculationModeAbsolute:
                return QString::fromLatin1("MeasureCalculationModeAbsolute");
            case MeasureCalculationModeAuto:
                return QString::fromLatin1("MeasureCalculationModeAuto");
            case MeasureCalculationModeAutoArea:
                return QString::fromLatin1("MeasureCalculationModeAutoArea");
            case MeasureCalculationModeAutoOrientation:
                return QString::fromLatin1("MeasureCalculationModeAutoOrientation");
            case MeasureCalculationModeRelative:
                return QString::fromLatin1("MeasureCalculationModeRelative");
        }
        Q_ASSERT( !"unhandled MeasureCalculationMode" );
        return QString::fromLatin1("MeasureCalculationModeAuto");
    }
    static MeasureCalculationMode stringToMeasureCalculationMode( const QString& string ) {
      if ( string == QString::fromLatin1("MeasureCalculationModeAbsolute") )
          return MeasureCalculationModeAbsolute;
      if ( string == QString::fromLatin1("MeasureCalculationModeAuto") )
          return MeasureCalculationModeAuto;
      if ( string == QString::fromLatin1("MeasureCalculationModeAutoArea") )
          return MeasureCalculationModeAutoArea;
      if ( string == QString::fromLatin1("MeasureCalculationModeAutoOrientation") )
          return MeasureCalculationModeAutoOrientation;
      if ( string == QString::fromLatin1("MeasureCalculationModeRelative") )
          return MeasureCalculationModeRelative;

      return MeasureCalculationModeAuto;
    }
    enum MeasureOrientation { MeasureOrientationAuto,
        MeasureOrientationHorizontal,
        MeasureOrientationVertical,
        MeasureOrientationMinimum,
        MeasureOrientationMaximum };
    static QString measureOrientationToString( MeasureOrientation mode ) {
        switch ( mode ) {
            case MeasureOrientationAuto:
                return QString::fromLatin1("MeasureOrientationAuto");
            case MeasureOrientationHorizontal:
                return QString::fromLatin1("MeasureOrientationHorizontal");
            case MeasureOrientationVertical:
                return QString::fromLatin1("MeasureOrientationVertical");
            case MeasureOrientationMinimum:
                return QString::fromLatin1("MeasureOrientationMinimum");
            case MeasureOrientationMaximum:
                return QString::fromLatin1("MeasureOrientationMaximum");
        }
        Q_ASSERT( !"Unknown MeasureOrientation value" );
        return QString::fromLatin1("MeasureOrientationAuto");
    }
    static MeasureOrientation stringToMeasureOrientation( const QString& string ) {
      if ( string == QString::fromLatin1("MeasureOrientationAuto") )
          return MeasureOrientationAuto;
      if ( string == QString::fromLatin1("MeasureOrientationHorizontal") )
          return MeasureOrientationHorizontal;
      if ( string == QString::fromLatin1("MeasureOrientationVertical") )
          return MeasureOrientationVertical;
      if ( string == QString::fromLatin1("MeasureOrientationMinimum") )
          return MeasureOrientationMinimum;
      if ( string == QString::fromLatin1("MeasureOrientationMaximum") )
          return MeasureOrientationMaximum;

      return MeasureOrientationAuto;
    }


};


#endif
