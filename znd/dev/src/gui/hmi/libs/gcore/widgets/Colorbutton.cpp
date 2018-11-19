


#include "Global.h"
#include "Colorbutton.h"


void ColorButton::slotEditColor()
{
    bool ok;
    QRgb rgba = QColorDialog::getRgba(m_color.rgba(), &ok, 0);
    if (ok == false)
        return;
    QColor c;
    c.setRgba(rgba);
    if (c == color())
        return;
    setColor(c);
    emit colorChanged(m_color);
}

QColor ColorButton::shownColor() const
{
    return m_color;
}

QPixmap ColorButton::generatePixmap() const
{
    QPixmap pix(24, 24);

    int pixSize = 20;
    QBrush br(shownColor());

    QPixmap pm(2 * pixSize, 2 * pixSize);
    QPainter pmp(&pm);
    pmp.fillRect(0, 0, pixSize, pixSize, Qt::lightGray);
    pmp.fillRect(pixSize, pixSize, pixSize, pixSize, Qt::lightGray);
    pmp.fillRect(0, pixSize, pixSize, pixSize, Qt::darkGray);
    pmp.fillRect(pixSize, 0, pixSize, pixSize, Qt::darkGray);
    pmp.fillRect(0, 0, 2 * pixSize, 2 * pixSize, shownColor());
    br = QBrush(pm);

    QPainter p(&pix);
    int corr = 1;
    QRect r = pix.rect().adjusted(corr, corr, -corr, -corr);
    p.setBrushOrigin((r.width() % pixSize + pixSize) / 2 + corr, (r.height() % pixSize + pixSize) / 2 + corr);
    p.fillRect(r, br);

    p.fillRect(r.width() / 4 + corr, r.height() / 4 + corr,
               r.width() / 2, r.height() / 2,
               QColor(shownColor().rgb()));
    p.drawRect(pix.rect().adjusted(0, 0, -1, -1));

    return pix;
}



ColorButton::ColorButton(QWidget *parent)
    : QToolButton(parent)
{
    m_backgroundCheckered = true;
    setAcceptDrops(true);

    connect(this, SIGNAL(clicked()), this, SLOT(slotEditColor()));
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

ColorButton::~ColorButton()
{

}

void ColorButton::setColor(const QColor &color)
{
    if (m_color == color)
        return;
    m_color = color;
    update();
}

QColor ColorButton::color() const
{
    return m_color;
}

void ColorButton::setBackgroundCheckered(bool checkered)
{
    if (m_backgroundCheckered == checkered)
        return;
    m_backgroundCheckered = checkered;
    update();
}

bool ColorButton::isBackgroundCheckered() const
{
    return m_backgroundCheckered;
}

void ColorButton::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);
    if (!isEnabled())
        return;

    const int pixSize = 10;
    QBrush br(shownColor());
    if (m_backgroundCheckered) {
        QPixmap pm(2 * pixSize, 2 * pixSize);
        QPainter pmp(&pm);
        pmp.fillRect(0, 0, pixSize, pixSize, Qt::white);
        pmp.fillRect(pixSize, pixSize, pixSize, pixSize, Qt::white);
        pmp.fillRect(0, pixSize, pixSize, pixSize, Qt::black);
        pmp.fillRect(pixSize, 0, pixSize, pixSize, Qt::black);
        pmp.fillRect(0, 0, 2 * pixSize, 2 * pixSize, shownColor());
        br = QBrush(pm);
    }

    QPainter p(this);
    const int corr = 4;
    QRect r = rect().adjusted(corr, corr, -corr, -corr);
    p.setBrushOrigin((r.width() % pixSize + pixSize) / 2 + corr, (r.height() % pixSize + pixSize) / 2 + corr);
    p.fillRect(r, br);

    const QColor frameColor1(0, 0, 0, 26);
    p.setPen(frameColor1);
    p.drawRect(r.adjusted(1, 1, -2, -2));
    const QColor frameColor2(0, 0, 0, 51);
    p.setPen(frameColor2);
    p.drawRect(r.adjusted(0, 0, -1, -1));
}




GCDyColorWidget::GCDyColorWidget( QWidget *parent)
:QWidget( parent ),m_nInitColor("")
{
 setGeometry(0 , 0, 40, 20 );
 m_pCheckBox = new QCheckBox( this );
    m_pColorButton = new ColorButton( this );
 m_pCheckBox->setGeometry( 5, 5, 20, 17 );
 m_pColorButton->setGeometry(22, 5, 36, 19);
 m_pColorButton->setColor(Qt::white);
}

GCDyColorWidget::~GCDyColorWidget(void)
{
}


QString GCDyColorWidget::GetColor() const
{
 if ( m_pCheckBox ->isChecked() )
  return m_pColorButton->color().name();
 return "";
}

void GCDyColorWidget::SetColor( QString color )
{
 if ( color == "" )
 {
  m_pCheckBox->setChecked( false );
 }
 else
 {
  QColor qcolor( color );
  m_pCheckBox->setChecked( true );
  m_pColorButton->setColor( qcolor );
 }
 m_nInitColor = GetColor();
}
