#ifndef KDCHARTTEXTATTRIBUTES_H
#define KDCHARTTEXTATTRIBUTES_H 

#include <QDebug>
#include <QMetaType>
#include "KDChartGlobal.h"
#include "KDChartMeasure.h"

QT_BEGIN_NAMESPACE
class QPen;
class QFont;
class QTextDocument;
QT_END_NAMESPACE

namespace KDChart {
class KDCHART_EXPORT TextAttributes
{
public:
  TextAttributes();
  TextAttributes( const TextAttributes& );
  TextAttributes &operator= ( const TextAttributes& );
  bool operator==( const TextAttributes& ) const;
  inline bool operator!=( const TextAttributes& other ) const
  { return !operator==(other); }

  ~TextAttributes();





  void setVisible( bool visible );




  bool isVisible() const;
  void setFont( const QFont& font );




  QFont font() const;






  void setFontSize( const Measure & measure );




  Measure fontSize() const;






  void setMinimalFontSize( const Measure & measure );




  Measure minimalFontSize() const;
  qreal calculatedFontSize( const QSizeF &referenceSize,
                            KDChartEnums::MeasureOrientation autoReferenceOrientation ) const;
#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
  const qreal calculatedFontSize(
#else
  qreal calculatedFontSize(
#endif
        const QObject* autoReferenceArea,
        KDChartEnums::MeasureOrientation autoReferenceOrientation ) const;
  const QFont calculatedFont(
        const QObject* autoReferenceArea,
        KDChartEnums::MeasureOrientation autoReferenceOrientation ) const;




  bool hasAbsoluteFontSize() const;






  void setAutoRotate( bool autoRotate );





  bool autoRotate() const;






  void setAutoShrink( bool autoShrink );





  bool autoShrink() const;
  void setRotation( int rotation );
  void resetRotation();
  bool hasRotation() const;




  int rotation() const;





  void setPen( const QPen& pen );




  QPen pen() const;





  QTextDocument* textDocument() const;




  void setTextDocument(QTextDocument* layout);



private:
  KDCHART_DECLARE_PRIVATE_BASE_VALUE( TextAttributes )

};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::TextAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::TextAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::TextAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE
Q_DECLARE_METATYPE( KDChart::TextAttributes )

#endif
