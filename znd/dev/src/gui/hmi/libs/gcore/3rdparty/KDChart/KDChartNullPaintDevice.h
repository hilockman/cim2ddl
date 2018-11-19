#ifndef NULL_PAINT_DEVICE_H
#define NULL_PAINT_DEVICE_H 

#include <QPaintDevice>
#include <QPaintEngine>

namespace KDChart
{
    class NullPaintEngine : public QPaintEngine
    {
    public:
        virtual bool begin(QPaintDevice * ) { return true; }
        virtual void drawEllipse(const QRectF & ) { }
        virtual void drawEllipse(const QRect & ) { }
        virtual void drawImage(const QRectF & , const QImage & , const QRectF & , Qt::ImageConversionFlags ) { }
        virtual void drawLines(const QLineF * , int ) { }
        virtual void drawLines(const QLine * , int ) { }
        virtual void drawPath(const QPainterPath & ) { }
        virtual void drawPixmap(const QRectF & , const QPixmap & , const QRectF & ) { }
        virtual void drawPoints(const QPointF * , int ) { }
        virtual void drawPoints(const QPoint * , int ) { }
        virtual void drawPolygon(const QPointF * , int , PolygonDrawMode ) { }
        virtual void drawPolygon(const QPoint * , int , PolygonDrawMode ) { }
        virtual void drawRects(const QRectF * , int ) { }
        virtual void drawRects(const QRect * , int ) { }
        virtual void drawTextItem(const QPointF & , const QTextItem & ) { }
        virtual void drawTiledPixmap(const QRectF & , const QPixmap & , const QPointF & ) { }
        virtual bool end() { return true; }

        virtual Type type() const { return QPaintEngine::User; }
        virtual void updateState(const QPaintEngineState & ) { }
    };

    class NullPaintDevice : public QPaintDevice
    {
    public:
        NullPaintDevice(const QSize& size) : m_size(size) { }
        ~NullPaintDevice() { }

        int metric(PaintDeviceMetric metric) const
        {
            switch (metric)
            {
            case QPaintDevice::PdmWidth:
                return m_size.width();
            case QPaintDevice::PdmHeight:
                return m_size.height();
            case QPaintDevice::PdmWidthMM:
                return 1;
            case QPaintDevice::PdmHeightMM:
                return 1;
            case QPaintDevice::PdmNumColors:
                return int((uint)(-1));
            case QPaintDevice::PdmDepth:
                return 1;
            case QPaintDevice::PdmDpiX:
                return 1;
            case QPaintDevice::PdmDpiY:
                return 1;
            case QPaintDevice::PdmPhysicalDpiX:
                return 1;
            case QPaintDevice::PdmPhysicalDpiY:
                return 1;
            }
            return 1;
        }

        QPaintEngine* paintEngine() const
        {
            static NullPaintEngine nullPaintEngine;
            return &nullPaintEngine;
        }

    private:
        QSize m_size;
    };

}

#endif
