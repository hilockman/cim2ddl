#ifndef KDCHARTDATAVALUEATTRIBUTES_H
#define KDCHARTDATAVALUEATTRIBUTES_H 

#include <Qt>
#include <QMetaType>
#include "KDChartGlobal.h"
#include "KDChartEnums.h"
#include "KDChartRelativePosition.h"
namespace KDChart {

  class TextAttributes;
  class BackgroundAttributes;
  class FrameAttributes;
  class MarkerAttributes;
class KDCHART_EXPORT DataValueAttributes
{
public:
  DataValueAttributes();
  DataValueAttributes( const DataValueAttributes& );
  DataValueAttributes &operator= ( const DataValueAttributes& );
  bool operator==( const DataValueAttributes& ) const;
  inline bool operator!=( const DataValueAttributes& other ) const { return !operator==(other); }

  ~DataValueAttributes();

  static const DataValueAttributes& defaultAttributes();
  static const QVariant& defaultAttributesAsVariant();




  void setVisible( bool visible );




  bool isVisible() const;






  void setTextAttributes( const TextAttributes &a );




  TextAttributes textAttributes() const;







  bool mirrorNegativeValueTextRotation() const;




  void setMirrorNegativeValueTextRotation( bool enable );






  void setFrameAttributes( const FrameAttributes &a );






  FrameAttributes frameAttributes() const;






  void setBackgroundAttributes( const BackgroundAttributes &a );






  BackgroundAttributes backgroundAttributes() const;







  void setMarkerAttributes( const MarkerAttributes &a );






  MarkerAttributes markerAttributes() const;
  void setUsePercentage( bool enable );





  bool usePercentage() const;






  void setDecimalDigits( int digits );




  int decimalDigits() const;





  void setPrefix( const QString prefix );





  QString prefix() const;





  void setSuffix( const QString suffix );





  QString suffix() const;






  void setDataLabel( const QString label );





  QString dataLabel() const;




  bool showRepetitiveDataLabels() const;






  void setShowRepetitiveDataLabels( bool showRepetitiveDataLabels );




  bool showOverlappingDataLabels() const;






  void setShowOverlappingDataLabels( bool showOverlappingDataLabels );
  void setPowerOfTenDivisor( int powerOfTenDivisor );
  int powerOfTenDivisor() const;
  void setShowInfinite( bool infinite );
  bool showInfinite() const;
  void setNegativePosition( const RelativePosition& relPosition );





  const RelativePosition negativePosition() const;
  void setPositivePosition( const RelativePosition& relPosition );





  const RelativePosition positivePosition() const;

  const RelativePosition position( bool positive ) const
  {
    return positive ? positivePosition() : negativePosition();
  }

private:
  KDCHART_DECLARE_PRIVATE_BASE_VALUE( DataValueAttributes )

};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::DataValueAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::DataValueAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::DataValueAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::DataValueAttributes )

#endif
