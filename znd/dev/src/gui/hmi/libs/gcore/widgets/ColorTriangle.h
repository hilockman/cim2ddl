


#ifndef COLORTRIANGLE_H
#define COLORTRIANGLE_H 
#include <QtGui>
#include <QtCore>
#include <QtWidgets>

class QPointF;
struct Vertex;


class QtColorTriangle : public QWidget
{
    Q_OBJECT

public:
    QtColorTriangle(QWidget *parent = 0);
    ~QtColorTriangle();

    int heightForWidth(int w) const;

    void polish();
    QColor color() const;

Q_SIGNALS:
    void colorChanged(const QColor &col);

public Q_SLOTS:
    void setColor(const QColor &col);

protected:

    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *e);
    void resizeEvent(QResizeEvent *);
    void drawTrigon(QImage *p, const QPointF &a, const QPointF &b,
                    const QPointF &c, const QColor &color);

private:
    double radiusAt(const QPointF &pos, const QRect &rect) const;
    double angleAt(const QPointF &pos, const QRect &rect) const;
    QPointF movePointToTriangle(double x, double y, const Vertex &a,
                                const Vertex &b, const Vertex &c) const;

    QPointF pointFromColor(const QColor &col) const;
    QColor colorFromPoint(const QPointF &p) const;

    void genBackground();

    QImage m_background;
    double a, b, c;
    QPointF pa, pb, pc, pd;

    QColor m_currentColor;
    int m_currentHue;

    bool m_mustGenerateBackground;
    int m_penWidth;
    int m_ellipseSize;

    int m_outerRadius;
    QPointF m_selectorPos;

    enum SelectionMode {
        Idle,
        SelectingHue,
        SelectingSatValue
    } selMode;
};

#endif
