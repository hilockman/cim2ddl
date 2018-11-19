


#include "ColorTriangle.h"

#include <QtGui>
#include <QtCore>
#include <QtWidgets>

#include <math.h>
const double PI = 3.14159265358979323846264338327950288419717;
const double TWOPI = 2.0*PI;




struct DoubleColor
{
    double r, g, b;

    DoubleColor() : r(0.0), g(0.0), b(0.0) {}
    DoubleColor(double red, double green, double blue) : r(red), g(green), b(blue) {}
    DoubleColor(const DoubleColor &c) : r(c.r), g(c.g), b(c.b) {}
};




struct Vertex {
    DoubleColor color;
    QPointF point;

    Vertex(const DoubleColor &c, const QPointF &p) : color(c), point(p) {}
    Vertex(const QColor &c, const QPointF &p)
 : color(DoubleColor((double) c.red(), (double) c.green(),
       (double) c.blue())), point(p) {}
};





static void swap(Vertex **a, Vertex **b)
{
    Vertex *tmp = *a;
    *a = *b;
    *b = tmp;
}




QtColorTriangle::QtColorTriangle(QWidget *parent)
    : QWidget(parent), m_background(sizeHint(), QImage::Format_RGB32), selMode(Idle)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setFocusPolicy(Qt::StrongFocus);

    m_mustGenerateBackground = true;

    QColor tmp;
    tmp.setHsv(76, 184, 206);
    setColor(tmp);
}




QtColorTriangle::~QtColorTriangle()
{
}






void QtColorTriangle::polish()
{
    m_outerRadius = (contentsRect().width() - 1) / 2;
    if ((contentsRect().height() - 1) / 2 < m_outerRadius)
 m_outerRadius = (contentsRect().height() - 1) / 2;

    m_penWidth = (int) floor(m_outerRadius / 50.0);
    m_ellipseSize = (int) floor(m_outerRadius / 12.5);

    double cx = (double) contentsRect().center().x();
    double cy = (double) contentsRect().center().y();

    pa = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 5.0))),
       cy - (sin(a) * (m_outerRadius - (m_outerRadius / 5.0))));
    pb = QPointF(cx + (cos(b) * (m_outerRadius - (m_outerRadius / 5.0))),
       cy - (sin(b) * (m_outerRadius - (m_outerRadius / 5.0))));
    pc = QPointF(cx + (cos(c) * (m_outerRadius - (m_outerRadius / 5.0))),
       cy - (sin(c) * (m_outerRadius - (m_outerRadius / 5.0))));
    pd = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 10.0))),
       cy - (sin(a) * (m_outerRadius - (m_outerRadius / 10.0))));


    m_selectorPos = pointFromColor(m_currentColor);

    update();
}






int QtColorTriangle::heightForWidth(int w) const
{
    return w;
}







void QtColorTriangle::genBackground()
{

    double innerRadius = m_outerRadius - m_outerRadius / 5;


    m_background = QImage(contentsRect().size(), QImage::Format_RGB32);
    QPainter p(&m_background);
    p.setRenderHint(QPainter::Antialiasing);
    p.fillRect(m_background.rect(), palette().mid());

    QConicalGradient gradient(m_background.rect().center(), 90);
    QColor color;
    for (double i = 0; i <= 1.0; i += 0.1) {
#if QT_VERSION < 0x040100
        color.setHsv(int(i * 360.0), 255, 255);
#else
        color.setHsv(int(360.0 - (i * 360.0)), 255, 255);
#endif
        gradient.setColorAt(i, color);
    }

    QRectF innerRadiusRect(m_background.rect().center().x() - innerRadius, m_background.rect().center().y() - innerRadius,
                           innerRadius * 2 + 1, innerRadius * 2 + 1);
    QRectF outerRadiusRect(m_background.rect().center().x() - m_outerRadius, m_background.rect().center().y() - m_outerRadius,
                           m_outerRadius * 2 + 1, m_outerRadius * 2 + 1);
    QPainterPath path;
    path.addEllipse(innerRadiusRect);
    path.addEllipse(outerRadiusRect);

    p.save();
    p.setClipPath(path);
    p.fillRect(m_background.rect(), gradient);
    p.restore();

    double penThickness = m_background.width() / 400.0;
    for (int f = 0; f <= 5760; f += 20) {
        int value = int((0.5 + cos(((f - 1800) / 5760.0) * TWOPI) / 2) * 255.0);

        color.setHsv(int((f / 5760.0) * 360.0), 128 + (255 - value)/2, 255 - (255 - value)/4);
        p.setPen(QPen(color, penThickness));
        p.drawArc(innerRadiusRect, 1440 - f, 20);

        color.setHsv(int((f / 5760.0) * 360.0), 128 + value/2, 255 - value/4);
        p.setPen(QPen(color, penThickness));
        p.drawArc(outerRadiusRect, 2880 - 1440 - f, 20);
    }
    return;
}







void QtColorTriangle::mouseMoveEvent(QMouseEvent *e)
{
    if ((e->buttons() & Qt::LeftButton) == 0)
        return;

    QPointF depos((double) e->pos().x(), (double) e->pos().y());
    bool newColor = false;

    if (selMode == SelectingHue) {



 a = angleAt(depos, contentsRect());
 b = a + TWOPI / 3.0;
 c = b + TWOPI / 3.0;
 if (b > TWOPI) b -= TWOPI;
 if (c > TWOPI) c -= TWOPI;

 double am = a - PI/2;
 if (am < 0) am += TWOPI;

 m_currentHue = 360 - (int) (((am) * 360.0) / TWOPI);
 int h,s,v;
 m_currentColor.getHsv(&h, &s, &v);

 if (m_currentHue != h) {
     newColor = true;
     m_currentColor.setHsv(m_currentHue, s, v);
 }

 double cx = (double) contentsRect().center().x();
 double cy = (double) contentsRect().center().y();

 pa = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 5.0))),
                     cy - (sin(a) * (m_outerRadius - (m_outerRadius / 5.0))));
 pb = QPointF(cx + (cos(b) * (m_outerRadius - (m_outerRadius / 5.0))),
                     cy - (sin(b) * (m_outerRadius - (m_outerRadius / 5.0))));
 pc = QPointF(cx + (cos(c) * (m_outerRadius - (m_outerRadius / 5.0))),
                     cy - (sin(c) * (m_outerRadius - (m_outerRadius / 5.0))));
 pd = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 10.0))),
                     cy - (sin(a) * (m_outerRadius - (m_outerRadius / 10.0))));

 m_selectorPos = pointFromColor(m_currentColor);
    } else {
 Vertex aa(Qt::black, pa);
 Vertex bb(Qt::black, pb);
 Vertex cc(Qt::black, pc);

 Vertex *p1 = &aa;
 Vertex *p2 = &bb;
 Vertex *p3 = &cc;
 if (p1->point.y() > p2->point.y()) swap(&p1, &p2);
 if (p1->point.y() > p3->point.y()) swap(&p1, &p3);
 if (p2->point.y() > p3->point.y()) swap(&p2, &p3);

 m_selectorPos = movePointToTriangle(depos.x(), depos.y(), aa, bb, cc);
 QColor col = colorFromPoint(m_selectorPos);
 if (col != m_currentColor) {


     int h,s,v;
     col.getHsv(&h, &s, &v);
     m_currentColor.setHsv(m_currentHue, s, v);
     newColor = true;
 }
    }

    if (newColor)
 emit colorChanged(m_currentColor);

    update();
}
void QtColorTriangle::mousePressEvent(QMouseEvent *e)
{

    if (e->button() != Qt::LeftButton)
 return;

    QPointF depos((double) e->pos().x(), (double) e->pos().y());
    double rad = radiusAt(depos, contentsRect());
    bool newColor = false;



    if (rad > (m_outerRadius - (m_outerRadius / 5))) {
 selMode = SelectingHue;

 a = angleAt(depos, contentsRect());
 b = a + TWOPI / 3.0;
 c = b + TWOPI / 3.0;
 if (b > TWOPI) b -= TWOPI;
 if (c > TWOPI) c -= TWOPI;

 double am = a - PI/2;
 if (am < 0) am += TWOPI;

 m_currentHue = 360 - (int) ((am * 360.0) / TWOPI);
 int h,s,v;
 m_currentColor.getHsv(&h, &s, &v);

 if (h != m_currentHue) {
     newColor = true;
     m_currentColor.setHsv(m_currentHue, s, v);
 }

 double cx = (double) contentsRect().center().x();
 double cy = (double) contentsRect().center().y();

 pa = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 5.0))),
    cy - (sin(a) * (m_outerRadius - (m_outerRadius / 5.0))));
 pb = QPointF(cx + (cos(b) * (m_outerRadius - (m_outerRadius / 5.0))),
    cy - (sin(b) * (m_outerRadius - (m_outerRadius / 5.0))));
 pc = QPointF(cx + (cos(c) * (m_outerRadius - (m_outerRadius / 5.0))),
    cy - (sin(c) * (m_outerRadius - (m_outerRadius / 5.0))));
 pd = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 10.0))),
    cy - (sin(a) * (m_outerRadius - (m_outerRadius / 10.0))));

 m_selectorPos = pointFromColor(m_currentColor);
 emit colorChanged(m_currentColor);
    } else {
 selMode = SelectingSatValue;

 Vertex aa(Qt::black, pa);
 Vertex bb(Qt::black, pb);
 Vertex cc(Qt::black, pc);

 Vertex *p1 = &aa;
 Vertex *p2 = &bb;
 Vertex *p3 = &cc;
 if (p1->point.y() > p2->point.y()) swap(&p1, &p2);
 if (p1->point.y() > p3->point.y()) swap(&p1, &p3);
 if (p2->point.y() > p3->point.y()) swap(&p2, &p3);

 m_selectorPos = movePointToTriangle(depos.x(), depos.y(), aa, bb, cc);
 QColor col = colorFromPoint(m_selectorPos);
 if (col != m_currentColor) {
     m_currentColor = col;
     newColor = true;
 }
    }

    if (newColor)
 emit colorChanged(m_currentColor);

    update();
}






void QtColorTriangle::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
 selMode = Idle;
}




void QtColorTriangle::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
 case Qt::Key_Left: {
     --m_currentHue;
     if (m_currentHue < 0) m_currentHue += 360;
     int h,s,v;
     m_currentColor.getHsv(&h, &s, &v);
     QColor tmp;
     tmp.setHsv(m_currentHue, s, v);
     setColor(tmp);
 }
     break;
 case Qt::Key_Right: {
     ++m_currentHue;
     if (m_currentHue > 359) m_currentHue -= 360;
     int h,s,v;
     m_currentColor.getHsv(&h, &s, &v);
     QColor tmp;
     tmp.setHsv(m_currentHue, s, v);
     setColor(tmp);
 }
     break;
 case Qt::Key_Up: {
     int h,s,v;
     m_currentColor.getHsv(&h, &s, &v);
     QColor tmp;
     if (e->modifiers() & Qt::ShiftModifier) {
  if (s > 5) s -= 5;
  else s = 0;
     } else {
  if (v > 5) v -= 5;
  else v = 0;
     }
     tmp.setHsv(m_currentHue, s, v);
     setColor(tmp);
 }
     break;
 case Qt::Key_Down: {
     int h,s,v;
     m_currentColor.getHsv(&h, &s, &v);
     QColor tmp;
     if (e->modifiers() & Qt::ShiftModifier) {
  if (s < 250) s += 5;
  else s = 255;
     } else {
  if (v < 250) v += 5;
  else v = 255;
     }
     tmp.setHsv(m_currentHue, s, v);
     setColor(tmp);
 }
     break;
    };
}






void QtColorTriangle::resizeEvent(QResizeEvent *)
{
    m_outerRadius = (contentsRect().width() - 1) / 2;
    if ((contentsRect().height() - 1) / 2 < m_outerRadius)
 m_outerRadius = (contentsRect().height() - 1) / 2;

    m_penWidth = (int) floor(m_outerRadius / 50.0);
    m_ellipseSize = (int) floor(m_outerRadius / 12.5);

    double cx = (double) contentsRect().center().x();
    double cy = (double) contentsRect().center().y();

    pa = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 5.0))),
                 cy - (sin(a) * (m_outerRadius - (m_outerRadius / 5.0))));
    pb = QPointF(cx + (cos(b) * (m_outerRadius - (m_outerRadius / 5.0))),
                 cy - (sin(b) * (m_outerRadius - (m_outerRadius / 5.0))));
    pc = QPointF(cx + (cos(c) * (m_outerRadius - (m_outerRadius / 5.0))),
                 cy - (sin(c) * (m_outerRadius - (m_outerRadius / 5.0))));
    pd = QPointF(cx + (cos(a) * (m_outerRadius - (m_outerRadius / 10.0))),
                 cy - (sin(a) * (m_outerRadius - (m_outerRadius / 10.0))));


    m_selectorPos = pointFromColor(m_currentColor);

    m_mustGenerateBackground = true;
    update();
}







void QtColorTriangle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    if (e->rect().intersects(contentsRect()))
  p.setClipRegion(e->region().intersected(contentsRect()));
    if (m_mustGenerateBackground) {
 genBackground();
 m_mustGenerateBackground = false;
    }



    QImage buf = m_background.copy();


    int h,s,v;
    m_currentColor.getHsv(&h, &s, &v);


    QColor hueColor;
    hueColor.setHsv(m_currentHue, 255, 255);


    drawTrigon(&buf, pa, pb, pc, hueColor);


    QPixmap pix = QPixmap::fromImage(buf);
    QPainter painter(&pix);
    painter.setRenderHint(QPainter::Antialiasing);


    QColor halfAlpha(0, 0, 0, 128);
    painter.setPen(QPen(halfAlpha, 0));
    painter.drawLine(pa, pb);
    painter.drawLine(pb, pc);
    painter.drawLine(pc, pa);

    int ri, gi, bi;
    hueColor.getRgb(&ri, &gi, &bi);
    if ((ri * 30) + (gi * 59) + (bi * 11) > 12800)
 painter.setPen(QPen(Qt::black, m_penWidth));
    else
 painter.setPen(QPen(Qt::white, m_penWidth));
    painter.drawEllipse((int) (pd.x() - m_ellipseSize / 2.0),
   (int) (pd.y() - m_ellipseSize / 2.0),
   m_ellipseSize, m_ellipseSize);

    m_currentColor.getRgb(&ri, &gi, &bi);



    if ((ri * 30) + (gi * 59) + (bi * 11) > 12800)
 painter.setPen(QPen(Qt::black, m_penWidth));
    else
 painter.setPen(QPen(Qt::white, m_penWidth));


    painter.drawEllipse(QRectF(m_selectorPos.x() - m_ellipseSize / 2.0,
                               m_selectorPos.y() - m_ellipseSize / 2.0,
                               m_ellipseSize + 0.5, m_ellipseSize + 0.5));


    p.drawPixmap(contentsRect().topLeft(), pix);
}
void QtColorTriangle::drawTrigon(QImage *buf, const QPointF &pa,
          const QPointF &pb, const QPointF &pc,
          const QColor &color)
{





    Vertex aa(color, pa);
    Vertex bb(Qt::black, pb);
    Vertex cc(Qt::white, pc);



    Vertex *p1 = &aa;
    Vertex *p2 = &bb;
    Vertex *p3 = &cc;
    if (p1->point.y() > p2->point.y()) swap(&p1, &p2);
    if (p1->point.y() > p3->point.y()) swap(&p1, &p3);
    if (p2->point.y() > p3->point.y()) swap(&p2, &p3);


    double p1p2ydist = p2->point.y() - p1->point.y();
    double p1p3ydist = p3->point.y() - p1->point.y();
    double p2p3ydist = p3->point.y() - p2->point.y();
    double p1p2xdist = p2->point.x() - p1->point.x();
    double p1p3xdist = p3->point.x() - p1->point.x();
    double p2p3xdist = p3->point.x() - p2->point.x();



    bool lefty = p1p2xdist < 0;





    QVarLengthArray<DoubleColor, 2000> leftColors;
    QVarLengthArray<DoubleColor, 2000> rightColors;
    QVarLengthArray<double, 2000> leftX;
    QVarLengthArray<double, 2000> rightX;

    leftColors.resize(int(floor(p3->point.y() + 1)));
    rightColors.resize(int(floor(p3->point.y() + 1)));
    leftX.resize(int(floor(p3->point.y() + 1)));
    rightX.resize(int(floor(p3->point.y() + 1)));



    DoubleColor source;
    DoubleColor dest;
    double r, g, b;
    double rdelta, gdelta, bdelta;
    double x;
    double xdelta;
    int y1, y2;


    x = p1->point.x();
    source = p1->color;
    dest = p3->color;
    r = source.r;
    g = source.g;
    b = source.b;
    y1 = (int) floor(p1->point.y());
    y2 = (int) floor(p3->point.y());



    xdelta = p1p3ydist == 0.0 ? 0.0 : p1p3xdist / p1p3ydist;
    rdelta = p1p3ydist == 0.0 ? 0.0 : (dest.r - r) / p1p3ydist;
    gdelta = p1p3ydist == 0.0 ? 0.0 : (dest.g - g) / p1p3ydist;
    bdelta = p1p3ydist == 0.0 ? 0.0 : (dest.b - b) / p1p3ydist;


    int y;
    for (y = y1; y < y2; ++y) {
 if (lefty) {
     rightColors[y] = DoubleColor(r, g, b);
     rightX[y] = x;
 } else {
     leftColors[y] = DoubleColor(r, g, b);
     leftX[y] = x;
 }

 r += rdelta;
 g += gdelta;
 b += bdelta;
 x += xdelta;
    }



    x = p1->point.x();
    source = p1->color;
    dest = p2->color;
    r = source.r;
    g = source.g;
    b = source.b;
    y1 = (int) floor(p1->point.y());
    y2 = (int) floor(p2->point.y());



    xdelta = p1p2ydist == 0.0 ? 0.0 : p1p2xdist / p1p2ydist;
    rdelta = p1p2ydist == 0.0 ? 0.0 : (dest.r - r) / p1p2ydist;
    gdelta = p1p2ydist == 0.0 ? 0.0 : (dest.g - g) / p1p2ydist;
    bdelta = p1p2ydist == 0.0 ? 0.0 : (dest.b - b) / p1p2ydist;


    for (y = y1; y < y2; ++y) {
 if (lefty) {
     leftColors[y] = DoubleColor(r, g, b);
     leftX[y] = x;
 } else {
     rightColors[y] = DoubleColor(r, g, b);
     rightX[y] = x;
 }

 r += rdelta;
 g += gdelta;
 b += bdelta;
 x += xdelta;
    }



    x = p2->point.x();
    source = p2->color;
    dest = p3->color;
    r = source.r;
    g = source.g;
    b = source.b;
    y1 = (int) floor(p2->point.y());
    y2 = (int) floor(p3->point.y());



    xdelta = p2p3ydist == 0.0 ? 0.0 : p2p3xdist / p2p3ydist;
    rdelta = p2p3ydist == 0.0 ? 0.0 : (dest.r - r) / p2p3ydist;
    gdelta = p2p3ydist == 0.0 ? 0.0 : (dest.g - g) / p2p3ydist;
    bdelta = p2p3ydist == 0.0 ? 0.0 : (dest.b - b) / p2p3ydist;


    for (y = y1; y < y2; ++y) {
 if (lefty) {
     leftColors[y] = DoubleColor(r, g, b);
     leftX[y] = x;
 } else {
     rightColors[y] = DoubleColor(r, g, b);
     rightX[y] = x;
 }

 r += rdelta;
 g += gdelta;
 b += bdelta;
 x += xdelta;
    }



    const int p3yfloor = int(floor(p3->point.y()));
    for (int y = int(floor(p1->point.y())); y < p3yfloor; ++y) {
 double lx = leftX[y];
 double rx = rightX[y];

 int lxi = (int) floor(lx);
 int rxi = (int) floor(rx);
 DoubleColor rc = rightColors[y];
 DoubleColor lc = leftColors[y];


 double xdist = rx - lx;
 if (xdist != 0.0) {
            double r = lc.r;
            double g = lc.g;
            double b = lc.b;
            double rdelta = (rc.r - r) / xdist;
            double gdelta = (rc.g - g) / xdist;
            double bdelta = (rc.b - b) / xdist;

            QRgb *scanline = reinterpret_cast<QRgb *>(buf->scanLine(y));
            scanline += lxi;


            for (int i = lxi; i < rxi; ++i) {
                *scanline++ = qRgb((int) r, (int) g, (int) b);
                r += rdelta;
                g += gdelta;
                b += bdelta;
            }
        }
    }
}





void QtColorTriangle::setColor(const QColor &col)
{
    if (col == m_currentColor)
 return;

    m_currentColor = col;

    int h, s, v;
    m_currentColor.getHsv(&h, &s, &v);


    if (h != -1)
 m_currentHue = h;

    a = (((360 - m_currentHue) * TWOPI) / 360.0);
    a += PI / 2.0;
    if (a > TWOPI) a -= TWOPI;

    b = a + TWOPI/3;
    c = b + TWOPI/3;

    if (b > TWOPI) b -= TWOPI;
    if (c > TWOPI) c -= TWOPI;

    double cx = (double) contentsRect().center().x();
    double cy = (double) contentsRect().center().y();
    double innerRadius = m_outerRadius - (m_outerRadius / 5.0);
    double pointerRadius = m_outerRadius - (m_outerRadius / 10.0);

    pa = QPointF(cx + (cos(a) * innerRadius), cy - (sin(a) * innerRadius));
    pb = QPointF(cx + (cos(b) * innerRadius), cy - (sin(b) * innerRadius));
    pc = QPointF(cx + (cos(c) * innerRadius), cy - (sin(c) * innerRadius));
    pd = QPointF(cx + (cos(a) * pointerRadius), cy - (sin(a) * pointerRadius));

    m_selectorPos = pointFromColor(m_currentColor);
    update();

    emit colorChanged(m_currentColor);
}





QColor QtColorTriangle::color() const
{
    return m_currentColor;
}






double QtColorTriangle::radiusAt(const QPointF &pos, const QRect &rect) const
{
    double mousexdist = pos.x() - (double) rect.center().x();
    double mouseydist = pos.y() - (double) rect.center().y();
    return sqrt(mousexdist * mousexdist + mouseydist * mouseydist);
}
double QtColorTriangle::angleAt(const QPointF &pos, const QRect &rect) const
{
    double mousexdist = pos.x() - (double) rect.center().x();
    double mouseydist = pos.y() - (double) rect.center().y();
    double mouserad = sqrt(mousexdist * mousexdist + mouseydist * mouseydist);
    if (mouserad == 0.0)
        return 0.0;

    double angle = acos(mousexdist / mouserad);
    if (mouseydist >= 0)
 angle = TWOPI - angle;

    return angle;
}





inline double qsqr(double a)
{
    return a * a;
}





inline double vlen(double x, double y)
{
    return sqrt(qsqr(x) + qsqr(y));
}





inline double vprod(double x1, double y1, double x2, double y2)
{
    return x1 * x2 + y1 * y2;
}






bool angleBetweenAngles(double p, double a1, double a2)
{
    if (a1 > a2) {
 a2 += TWOPI;
 if (p < PI) p += TWOPI;
    }

    return p >= a1 && p < a2;
}
static bool pointAbovePoint(double x, double y, double px, double py,
       double ax, double ay, double bx, double by)
{
    bool result = false;

    if (floor(ax) > floor(bx)) {
 if (floor(ay) < floor(by)) {

     if (floor(x) < floor(px) || floor(y) < floor(py))
  result = true;
 } else if (floor(ay) > floor(by)) {

     if (floor(x) > floor(px) || floor(y) < floor(py))
  result = true;
 } else {

     if (y < ay) result = true;
 }
    } else if (floor(ax) < floor(bx)) {
 if (floor(ay) < floor(by)) {

     if (floor(x) < floor(px) || floor(y) > floor(py))
  result = true;
 } else if (floor(ay) > floor(by)) {

     if (floor(x) > floor(px) || floor(y) > floor(py))
  result = true;
 } else {

     if (y > ay)
                result = true;
 }
    } else {

 if (floor(ay) < floor(by)) {
     if (x < ax) result = true;
 } else if (floor(ay) > floor(by)) {
     if (x > ax) result = true;
 } else {
     if (!(x == ax && y == ay))
  result = true;
 }
    }

    return result;
}
static int pointInLine(double x, double y, double ax, double ay,
         double bx, double by)
{
    if (ax > bx) {
 if (ay < by) {




     if (y <= ay && x >= ax)
  return -1;



     if (y >= by && x <= bx)
  return 1;
 } else {



     if (floor(ay) == floor(by)) {



  if (x >= ax)
      return -1;
  else if (x <= bx)
      return 1;
     } else {


  if (y >= ay && x >= ax)
      return -1;



  if (y <= by && x <= bx)
      return 1;
     }
 }
    } else {
 if (ay < by) {




     if (y <= ay && x <= ax)
  return -1;



     if (y >= by && x >= bx)
  return 1;
 } else {



     if (floor(ay) == floor(by)) {
  if (x <= ax)
      return -1;
  else if (x >= bx)
      return 1;
     } else {


  if (y >= ay && x <= ax)
      return -1;



  if (y <= by && x >= bx)
      return 1;
     }
 }
    }



    return 0;
}
QPointF QtColorTriangle::movePointToTriangle(double x, double y, const Vertex &a,
            const Vertex &b, const Vertex &c) const
{



    double v1xA = x - a.point.x();
    double v1yA = y - a.point.y();
    double v2xA = b.point.x() - a.point.x();
    double v2yA = b.point.y() - a.point.y();
    double vpA = vprod(v1xA, v1yA, v2xA, v2yA);
    double cosA = vpA / (vlen(v1xA, v1yA) * vlen(v2xA, v2yA));
    double alphaA = acos(cosA);



    double v1xB = x - b.point.x();
    double v1yB = y - b.point.y();
    double v2xB = c.point.x() - b.point.x();
    double v2yB = c.point.y() - b.point.y();
    double vpB = vprod(v1xB, v1yB, v2xB, v2yB);
    double cosB = vpB / (vlen(v1xB, v1yB) * vlen(v2xB, v2yB));
    double alphaB = acos(cosB);



    double v1xC = x - c.point.x();
    double v1yC = y - c.point.y();
    double v2xC = a.point.x() - c.point.x();
    double v2yC = a.point.y() - c.point.y();
    double vpC = vprod(v1xC, v1yC, v2xC, v2yC);
    double cosC = vpC / (vlen(v1xC, v1yC) * vlen(v2xC, v2yC));
    double alphaC = acos(cosC);




    double angleA = angleAt(a.point, contentsRect());
    double angleB = angleAt(b.point, contentsRect());
    double angleC = angleAt(c.point, contentsRect());
    double angleP = angleAt(QPointF(x, y), contentsRect());


    if (angleBetweenAngles(angleP, angleA, angleB)) {




 double pdist = sqrt(qsqr(x - a.point.x()) + qsqr(y - a.point.y()));


 double p0x = a.point.x() + ((b.point.x() - a.point.x()) / vlen(v2xB, v2yB)) * cos(alphaA) * pdist;
 double p0y = a.point.y() + ((b.point.y() - a.point.y()) / vlen(v2xB, v2yB)) * cos(alphaA) * pdist;



 if (pointAbovePoint(x, y, p0x, p0y, a.point.x(), a.point.y(), b.point.x(), b.point.y())) {


     int n = pointInLine(p0x, p0y, a.point.x(), a.point.y(), b.point.x(), b.point.y());
     if (n < 0)
  return a.point;
     else if (n > 0)
  return b.point;

     return QPointF(p0x, p0y);
 }
    } else if (angleBetweenAngles(angleP, angleB, angleC)) {

 double pdist = sqrt(qsqr(x - b.point.x()) + qsqr(y - b.point.y()));


        double p0x = b.point.x() + ((c.point.x() - b.point.x()) / vlen(v2xC, v2yC)) * cos(alphaB) * pdist;
 double p0y = b.point.y() + ((c.point.y() - b.point.y()) / vlen(v2xC, v2yC)) * cos(alphaB) * pdist;

 if (pointAbovePoint(x, y, p0x, p0y, b.point.x(), b.point.y(), c.point.x(), c.point.y())) {
     int n = pointInLine(p0x, p0y, b.point.x(), b.point.y(), c.point.x(), c.point.y());
     if (n < 0)
  return b.point;
     else if (n > 0)
  return c.point;
     return QPointF(p0x, p0y);
 }
    } else if (angleBetweenAngles(angleP, angleC, angleA)) {

 double pdist = sqrt(qsqr(x - c.point.x()) + qsqr(y - c.point.y()));


        double p0x = c.point.x() + ((a.point.x() - c.point.x()) / vlen(v2xA, v2yA)) * cos(alphaC) * pdist;
 double p0y = c.point.y() + ((a.point.y() - c.point.y()) / vlen(v2xA, v2yA)) * cos(alphaC) * pdist;

 if (pointAbovePoint(x, y, p0x, p0y, c.point.x(), c.point.y(), a.point.x(), a.point.y())) {
     int n = pointInLine(p0x, p0y, c.point.x(), c.point.y(), a.point.x(), a.point.y());
     if (n < 0)
  return c.point;
     else if (n > 0)
  return a.point;
     return QPointF(p0x, p0y);
 }
    }


    return QPointF(x, y);
}
QPointF QtColorTriangle::pointFromColor(const QColor &col) const
{

    if (col == Qt::black)
 return pb;
    else if (col == Qt::white)
 return pc;


    double ab_deltax = pb.x() - pa.x();
    double ab_deltay = pb.y() - pa.y();
    double bc_deltax = pc.x() - pb.x();
    double bc_deltay = pc.y() - pb.y();
    double ac_deltax = pc.x() - pa.x();
    double ac_deltay = pc.y() - pa.y();


    int hue,sat,val;
    col.getHsv(&hue, &sat, &val);



    double p1 = pa.x() + (ab_deltax * (double) (255 - val)) / 255.0;
    double q1 = pa.y() + (ab_deltay * (double) (255 - val)) / 255.0;
    double p2 = pb.x() + (bc_deltax * (double) val) / 255.0;
    double q2 = pb.y() + (bc_deltay * (double) val) / 255.0;



    double p3 = pa.x() + (ac_deltax * (double) (255 - sat)) / 255.0;
    double q3 = pa.y() + (ac_deltay * (double) (255 - sat)) / 255.0;
    double p4 = pb.x();
    double q4 = pb.y();


 double x = 0;
 double y = 0;
 if (p1 != p2) {
  double a = (q2 - q1) / (p2 - p1);
  double c = (q4 - q3) / (p4 - p3);
  double b = q1 - a * p1;
  double d = q3 - c * p3;

  x = (d - b) / (a - c);
  y = a * x + b;
 }
 else {
  x = p1;
  y = q3 + (x - p3) * (q4 - q3) / (p4 - p3);
 }

    return QPointF(x, y);
}
QColor QtColorTriangle::colorFromPoint(const QPointF &p) const
{

    int outerRadius = (contentsRect().width() - 1) / 2;
    if ((contentsRect().height() - 1) / 2 < outerRadius)
 outerRadius = (contentsRect().height() - 1) / 2;


    double cx = (double) contentsRect().center().x();
    double cy = (double) contentsRect().center().y();



    QPointF pa(cx + (cos(a) * (outerRadius - (outerRadius / 5.0))),
     cy - (sin(a) * (outerRadius - (outerRadius / 5.0))));
    QPointF pb(cx + (cos(b) * (outerRadius - (outerRadius / 5.0))),
     cy - (sin(b) * (outerRadius - (outerRadius / 5.0))));
    QPointF pc(cx + (cos(c) * (outerRadius - (outerRadius / 5.0))),
     cy - (sin(c) * (outerRadius - (outerRadius / 5.0))));


    double angle = a - PI/2.0;
    if (angle < 0) angle += TWOPI;
    double hue = (360.0 * angle) / TWOPI;



    QColor color;
    color.setHsv(360 - (int) floor(hue), 255, 255);



    Vertex aa(color, pa);
    Vertex bb(Qt::black, pb);
    Vertex cc(Qt::white, pc);


    Vertex *p1 = &aa;
    Vertex *p2 = &bb;
    Vertex *p3 = &cc;
    if (p1->point.y() > p2->point.y()) swap(&p1, &p2);
    if (p1->point.y() > p3->point.y()) swap(&p1, &p3);
    if (p2->point.y() > p3->point.y()) swap(&p2, &p3);



    double p1p2ydist = p2->point.y() - p1->point.y();
    double p1p3ydist = p3->point.y() - p1->point.y();
    double p2p3ydist = p3->point.y() - p2->point.y();
    double p1p2xdist = p2->point.x() - p1->point.x();
    double p1p3xdist = p3->point.x() - p1->point.x();
    double p2p3xdist = p3->point.x() - p2->point.x();






    bool lefty = p1p2xdist < 0;




    bool firstshorty = (p.y() >= p1->point.y() && p.y() < p2->point.y());



    double leftx;
    double rightx;
    if (lefty) {
        if (firstshorty) {
            leftx = p1->point.x();
            if (floor(p1p2ydist) != 0.0) {
                leftx += (p1p2xdist * (p.y() - p1->point.y())) / p1p2ydist;
            } else {
                leftx = qMin(p1->point.x(), p2->point.x());
            }
        } else {
            leftx = p2->point.x();
            if (floor(p2p3ydist) != 0.0) {
                leftx += (p2p3xdist * (p.y() - p2->point.y())) / p2p3ydist;
            } else {
                leftx = qMin(p2->point.x(), p3->point.x());
            }
        }

        rightx = p1->point.x();
        rightx += (p1p3xdist * (p.y() - p1->point.y())) / p1p3ydist;
    } else {
        leftx = p1->point.x();
        leftx += (p1p3xdist * (p.y() - p1->point.y())) / p1p3ydist;

        if (firstshorty) {
            rightx = p1->point.x();
            if (floor(p1p2ydist) != 0.0) {
                rightx += (p1p2xdist * (p.y() - p1->point.y())) / p1p2ydist;
            } else {
                rightx = qMax(p1->point.x(), p2->point.x());
            }
        } else {
            rightx = p2->point.x();
            if (floor(p2p3ydist) != 0.0) {
                rightx += (p2p3xdist * (p.y() - p2->point.y())) / p2p3ydist;
            } else {
                rightx = qMax(p2->point.x(), p3->point.x());
            }
        }
    }



    double rshort = 0, gshort = 0, bshort = 0;
    double rlong = 0, glong = 0, blong = 0;
    if (firstshorty) {
        if (floor(p1p2ydist) != 0.0) {
            rshort = p2->color.r * (p.y() - p1->point.y()) / p1p2ydist;
            gshort = p2->color.g * (p.y() - p1->point.y()) / p1p2ydist;
            bshort = p2->color.b * (p.y() - p1->point.y()) / p1p2ydist;
            rshort += p1->color.r * (p2->point.y() - p.y()) / p1p2ydist;
            gshort += p1->color.g * (p2->point.y() - p.y()) / p1p2ydist;
            bshort += p1->color.b * (p2->point.y() - p.y()) / p1p2ydist;
        } else {
            if (lefty) {
                if (p1->point.x() <= p2->point.x()) {
                    rshort = p1->color.r;
                    gshort = p1->color.g;
                    bshort = p1->color.b;
                } else {
                    rshort = p2->color.r;
                    gshort = p2->color.g;
                    bshort = p2->color.b;
                }
            } else {
                if (p1->point.x() > p2->point.x()) {
                    rshort = p1->color.r;
                    gshort = p1->color.g;
                    bshort = p1->color.b;
                } else {
                    rshort = p2->color.r;
                    gshort = p2->color.g;
                    bshort = p2->color.b;
                }
            }
        }
    } else {
        if (floor(p2p3ydist) != 0.0) {
            rshort = p3->color.r * (p.y() - p2->point.y()) / p2p3ydist;
            gshort = p3->color.g * (p.y() - p2->point.y()) / p2p3ydist;
            bshort = p3->color.b * (p.y() - p2->point.y()) / p2p3ydist;
            rshort += p2->color.r * (p3->point.y() - p.y()) / p2p3ydist;
            gshort += p2->color.g * (p3->point.y() - p.y()) / p2p3ydist;
            bshort += p2->color.b * (p3->point.y() - p.y()) / p2p3ydist;
        } else {
            if (lefty) {
                if (p2->point.x() <= p3->point.x()) {
                    rshort = p2->color.r;
                    gshort = p2->color.g;
                    bshort = p2->color.b;
                } else {
                    rshort = p3->color.r;
                    gshort = p3->color.g;
                    bshort = p3->color.b;
                }
            } else {
                if (p2->point.x() > p3->point.x()) {
                    rshort = p2->color.r;
                    gshort = p2->color.g;
                    bshort = p2->color.b;
                } else {
                    rshort = p3->color.r;
                    gshort = p3->color.g;
                    bshort = p3->color.b;
                }
            }
        }
    }


    rlong = p3->color.r * (p.y() - p1->point.y()) / p1p3ydist;
    glong = p3->color.g * (p.y() - p1->point.y()) / p1p3ydist;
    blong = p3->color.b * (p.y() - p1->point.y()) / p1p3ydist;
    rlong += p1->color.r * (p3->point.y() - p.y()) / p1p3ydist;
    glong += p1->color.g * (p3->point.y() - p.y()) / p1p3ydist;
    blong += p1->color.b * (p3->point.y() - p.y()) / p1p3ydist;





    double rl, gl, bl, rr, gr, br;
    if (lefty) {
 rl = rshort; gl = gshort; bl = bshort;
 rr = rlong; gr = glong; br = blong;
    } else {
 rl = rlong; gl = glong; bl = blong;
 rr = rshort; gr = gshort; br = bshort;
    }





    double xdist = rightx - leftx;
    double saxdist = p.x() - leftx;
    double saxdist2 = xdist - saxdist;



    double r, g, b;
    if (xdist != 0.0) {
 r = (saxdist2 * rl / xdist) + (saxdist * rr / xdist);
 g = (saxdist2 * gl / xdist) + (saxdist * gr / xdist);
 b = (saxdist2 * bl / xdist) + (saxdist * br / xdist);
    } else {





 r = (rl + rr) / 2;
        g = (gl + gr) / 2;
 b = (bl + br) / 2;
    }




    int ri = (int) floor(r);
    int gi = (int) floor(g);
    int bi = (int) floor(b);
    if (ri < 0) ri = 0;
    else if (ri > 255) ri = 255;
    if (gi < 0) gi = 0;
    else if (gi > 255) gi = 255;
    if (bi < 0) bi = 0;
    else if (bi > 255) bi = 255;


    return QColor(ri, gi, bi);
}
