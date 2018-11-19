#ifndef KDCHARTABSTRACTDIAGRAM_H
#define KDCHARTABSTRACTDIAGRAM_H 

#include <QList>
#include <QRectF>
#include <QAbstractItemView>

#include "KDChartGlobal.h"
#include "KDChartMarkerAttributes.h"
#include "KDChartAttributesModel.h"

namespace KDChart {

    class AbstractCoordinatePlane;
    class AttributesModel;
    class DataValueAttributes;
    class PaintContext;
    class KDCHART_EXPORT AbstractDiagram : public QAbstractItemView
    {
        Q_OBJECT
        Q_DISABLE_COPY( AbstractDiagram )
        KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC( AbstractDiagram )

    friend class AbstractCoordinatePlane;
    friend class CartesianCoordinatePlane;
    friend class PolarCoordinatePlane;

    protected:
        explicit inline AbstractDiagram(
            Private *p, QWidget* parent, AbstractCoordinatePlane* plane );
        explicit AbstractDiagram (
            QWidget* parent = 0, AbstractCoordinatePlane* plane = 0 );
    public:
        virtual ~AbstractDiagram();





        bool compare( const AbstractDiagram* other ) const;
        const QPair<QPointF, QPointF> dataBoundaries() const;
        virtual void paint ( PaintContext* paintContext ) = 0;







        virtual void resize ( const QSizeF& area ) = 0;


        virtual void setModel ( QAbstractItemModel * model );


        virtual void setSelectionModel( QItemSelectionModel* selectionModel );
        virtual void setAttributesModel( AttributesModel* model );







        virtual bool usesExternalAttributesModel() const;
        virtual AttributesModel* attributesModel() const;



        virtual void setRootIndex ( const QModelIndex& idx );


        virtual QRect visualRect(const QModelIndex &index) const;

        virtual void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);

        virtual QModelIndex indexAt(const QPoint &point) const;

        virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);

        virtual int horizontalOffset() const;

        virtual int verticalOffset() const;

        virtual bool isIndexHidden(const QModelIndex &index) const;

        virtual void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command);

        virtual QRegion visualRegionForSelection(const QItemSelection &selection) const;
        virtual QRegion visualRegion(const QModelIndex &index) const;

#if QT_VERSION < 0x050000
        virtual void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
#else
        virtual void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
#endif

        virtual void doItemsLayout();







        AbstractCoordinatePlane* coordinatePlane() const;







        virtual void setCoordinatePlane( AbstractCoordinatePlane* plane );
        void setHidden( const QModelIndex & index, bool hidden );
        void setHidden( int dataset, bool hidden );
        void setHidden( bool hidden );







        bool isHidden() const;
        bool isHidden( int dataset ) const;
        bool isHidden( const QModelIndex & index ) const;
        void setDataValueAttributes( const QModelIndex & index,
                                     const DataValueAttributes & a );






        void setDataValueAttributes( int dataset, const DataValueAttributes & a );





        void setDataValueAttributes( const DataValueAttributes & a );







        DataValueAttributes dataValueAttributes() const;
        DataValueAttributes dataValueAttributes( int dataset ) const;
        DataValueAttributes dataValueAttributes( const QModelIndex & index ) const;







        void setPen( const QModelIndex& index, const QPen& pen );






        void setPen( int dataset, const QPen& pen );





        void setPen( const QPen& pen );







        QPen pen() const;







        QPen pen( int dataset ) const;







        QPen pen( const QModelIndex& index ) const;







        void setBrush( const QModelIndex& index, const QBrush& brush);






        void setBrush( int dataset, const QBrush& brush );





        void setBrush( const QBrush& brush);







        QBrush brush() const;







        QBrush brush( int dataset ) const;







        QBrush brush( const QModelIndex& index ) const;







        void setUnitPrefix( const QString& prefix, int column, Qt::Orientation orientation );





        void setUnitPrefix( const QString& prefix, Qt::Orientation orientation );







        void setUnitSuffix( const QString& suffix, int column, Qt::Orientation orientation );





         void setUnitSuffix( const QString& suffix, Qt::Orientation orientation );
        QString unitPrefix( int column, Qt::Orientation orientation, bool fallback = false ) const;





        QString unitPrefix( Qt::Orientation orientation ) const;
        QString unitSuffix( int column, Qt::Orientation orientation, bool fallback = false ) const;





        QString unitSuffix( Qt::Orientation orientation ) const;





        void setAllowOverlappingDataValueTexts( bool allow );




        bool allowOverlappingDataValueTexts() const;






        void setAntiAliasing( bool enabled );





        bool antiAliasing() const;







        void useDefaultColors();






        void useRainbowColors();






        void useSubduedColors();





        QStringList itemRowLabels() const;





        QStringList datasetLabels() const;
        QList<QBrush> datasetBrushes() const;
        QList<QPen> datasetPens() const;
        QList<MarkerAttributes> datasetMarkers() const;
        void setPercentMode( bool percent );
        bool percentMode() const;

        virtual void paintMarker( QPainter* painter,
                                  const MarkerAttributes& markerAttributes,
                                  const QBrush& brush, const QPen&,
                                  const QPointF& point, const QSizeF& size );
        int datasetDimension() const;







        void setDatasetDimension( int dimension );

    protected:
        void setDatasetDimensionInternal( int dimension );

    public:
        void update() const;

        void paintMarker( QPainter* painter, const DataValueAttributes& a,
                          const QModelIndex& index,
                          const QPointF& pos );
        void paintMarker( QPainter* painter,
                          const QModelIndex& index,
                          const QPointF& pos );
        void paintDataValueText( QPainter* painter, const QModelIndex& index,
                                 const QPointF& pos, qreal value );





        QModelIndexList indexesAt( const QPoint& point ) const;
        QModelIndexList indexesIn( const QRect& rect ) const;

    protected:
        virtual bool checkInvariants( bool justReturnTheStatus=false ) const;
        virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const = 0;

    protected Q_SLOTS:
        void setDataBoundariesDirty() const;

    protected:







        virtual void paintDataValueTexts( QPainter* painter );







        virtual void paintMarkers( QPainter* painter );
        void setAttributesModelRootIndex( const QModelIndex& );
        QModelIndex attributesModelRootIndex() const;
        qreal valueForCell( int row, int column ) const;

    Q_SIGNALS:
        void layoutChanged( AbstractDiagram* );





        void aboutToBeDestroyed();


        void modelsChanged();


        void modelDataChanged();


        void dataHidden();


        void propertiesChanged();


        void boundariesChanged();

        void viewportCoordinateSystemChanged();

    private:
        QModelIndex conditionallyMapFromSource( const QModelIndex & sourceIndex ) const;
    };

    typedef QList<AbstractDiagram*> AbstractDiagramList;
    typedef QList<const AbstractDiagram*> ConstAbstractDiagramList;




    class PrivateAttributesModel : public AttributesModel {
        Q_OBJECT
    public:
        explicit PrivateAttributesModel( QAbstractItemModel* model, QObject * parent = 0 )
            : AttributesModel(model,parent) {}
    };
}

#endif
