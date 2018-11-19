#ifndef __KDCHARTDIAGRAMOBSERVER_H_
#define __KDCHARTDIAGRAMOBSERVER_H_ 

#include "KDChartGlobal.h"

#include <QObject>
#include <QPointer>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
QT_END_NAMESPACE

namespace KDChart {

    class AbstractDiagram;





    class KDCHART_EXPORT DiagramObserver : public QObject
    {
        Q_OBJECT
    public:



        explicit DiagramObserver( AbstractDiagram * diagram, QObject* parent = 0 );
        ~DiagramObserver();

        const AbstractDiagram* diagram() const;
        AbstractDiagram* diagram();

    Q_SIGNALS:


        void diagramDestroyed( AbstractDiagram* diagram );

        void diagramAboutToBeDestroyed( AbstractDiagram* diagram );

        void diagramDataChanged( AbstractDiagram* diagram );

        void diagramDataHidden( AbstractDiagram* diagram );

        void diagramAttributesChanged( AbstractDiagram* diagram );

    private Q_SLOTS:
        void slotDestroyed(QObject*);
        void slotAboutToBeDestroyed();
        void slotHeaderDataChanged(Qt::Orientation,int,int);
        void slotDataChanged(QModelIndex,QModelIndex);
        void slotDataChanged();
        void slotDataHidden();
        void slotAttributesChanged();
        void slotAttributesChanged(QModelIndex,QModelIndex);
        void slotModelsChanged();

    private:
        void init();

        AbstractDiagram* m_diagram;
        QPointer<QAbstractItemModel> m_model;
        QPointer<QAbstractItemModel> m_attributesmodel;
   };
}

#endif
