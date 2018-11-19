#ifndef KDCHARTLEGEND_H
#define KDCHARTLEGEND_H 

#include "KDChartAbstractAreaWidget.h"
#include "KDChartPosition.h"
#include "KDChartMarkerAttributes.h"

class QTextTable;

namespace KDChart {

    class AbstractDiagram;
    typedef QList<AbstractDiagram*> DiagramList;
    typedef QList<const AbstractDiagram*> ConstDiagramList;
class KDCHART_EXPORT Legend : public AbstractAreaWidget
{
    Q_OBJECT

    Q_DISABLE_COPY( Legend )
    KDCHART_DECLARE_PRIVATE_DERIVED_QWIDGET( Legend )

public:
    explicit Legend( QWidget* parent = 0 );
    explicit Legend( KDChart::AbstractDiagram* diagram, QWidget* parent );
    virtual ~Legend();


    enum LegendStyle { MarkersOnly = 0,
                       LinesOnly = 1,
                       MarkersAndLines = 2 };


    void setLegendStyle( LegendStyle style );
    LegendStyle legendStyle() const;


    virtual Legend * clone() const;




    bool compare( const Legend* other ) const;

    virtual void resizeEvent( QResizeEvent * event );

    virtual void paint( QPainter* painter );
    virtual void setVisible( bool visible );
    void setReferenceArea( const QWidget* area );







    const QWidget* referenceArea() const;







    KDChart::AbstractDiagram* diagram() const;







    DiagramList diagrams() const;




    ConstDiagramList constDiagrams() const;







    void addDiagram( KDChart::AbstractDiagram* newDiagram );






    void removeDiagram( KDChart::AbstractDiagram* oldDiagram );






    void removeDiagrams();
    void replaceDiagram( KDChart::AbstractDiagram* newDiagram,
                         KDChart::AbstractDiagram* oldDiagram = 0 );





    uint dataSetOffset( KDChart::AbstractDiagram* diagram );
    void setDiagram( KDChart::AbstractDiagram* newDiagram );
    void setPosition( Position position );





    Position position() const;
    void setAlignment( Qt::Alignment );





    Qt::Alignment alignment() const;






    void setTextAlignment( Qt::Alignment );






     Qt::Alignment textAlignment() const;







     void setLegendSymbolAlignment(Qt::Alignment);







     Qt::Alignment legendSymbolAlignment() const;
    void setFloatingPosition( const RelativePosition& relativePosition );





    const RelativePosition floatingPosition() const;

    void setOrientation( Qt::Orientation orientation );
    Qt::Orientation orientation() const;


    void setSortOrder( Qt::SortOrder order );
    Qt::SortOrder sortOrder() const;

    void setShowLines( bool legendShowLines );
    bool showLines() const;

    void resetTexts();
    void setText( uint dataset, const QString& text );
    QString text( uint dataset ) const;
    const QMap<uint,QString> texts() const;
    void setHiddenDatasets( const QList<uint> hiddenDatasets );
    const QList<uint> hiddenDatasets() const;
    void setDatasetHidden( uint dataset, bool hidden );
    bool datasetIsHidden( uint dataset ) const;

    uint datasetCount() const;

    void setDefaultColors();
    void setRainbowColors();
    void setSubduedColors( bool ordered = false );

    void setBrushesFromDiagram( KDChart::AbstractDiagram* diagram );






    void setColor( uint dataset, const QColor& color );

    void setBrush( uint dataset, const QBrush& brush );
    QBrush brush( uint dataset ) const;
    const QMap<uint,QBrush> brushes() const;

    void setPen( uint dataset, const QPen& pen );
    QPen pen( uint dataset ) const;
    const QMap<uint,QPen> pens() const;






    void setMarkerAttributes( uint dataset, const MarkerAttributes& );
    MarkerAttributes markerAttributes( uint dataset ) const;
    const QMap<uint, MarkerAttributes> markerAttributes() const;
    void setUseAutomaticMarkerSize( bool useAutomaticMarkerSize );
    bool useAutomaticMarkerSize() const;

    void setTextAttributes( const TextAttributes &a );
    TextAttributes textAttributes() const;

    void setTitleText( const QString& text );
    QString titleText() const;

    void setTitleTextAttributes( const TextAttributes &a );
    TextAttributes titleTextAttributes() const;

    void setSpacing( uint space );
    uint spacing() const;


    virtual void forceRebuild();

    virtual QSize minimumSizeHint() const;
    virtual QSize sizeHint() const;
    virtual void needSizeHint();
    virtual void resizeLayout( const QSize& size );

Q_SIGNALS:
    void destroyedLegend( Legend* );

    void propertiesChanged();

private Q_SLOTS:
    void emitPositionChanged();
    void resetDiagram( AbstractDiagram* );
    void activateTheLayout();
    void setNeedRebuild();
    void buildLegend();
};

}


#endif
