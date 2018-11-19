






#include "CNaviDialog.h"
CNaviDialog::CNaviDialog(QWidget * parent, Hmi::SCENE_TYPE wnd ,const char * name , Qt::WindowFlags f )
    :QLabel(parent, f)
{
    resize ( 200, 200 );
    m_NaviRect = rect();
    setAlignment(Qt::AlignTop);
    m_Disable=false;

}


CNaviDialog::~CNaviDialog()
{

}



void CNaviDialog::mousePressEvent(QMouseEvent *e)
{
    m_Disable=true;
    QLabel::mousePressEvent(e);
    setCursor(QCursor(Qt::PointingHandCursor ));


}

void CNaviDialog::mouseMoveEvent(QMouseEvent *e)
{
    float x=e->pos().x()-m_NaviRect.width()/2;
    float y=e->pos().y()-m_NaviRect.height()/2;
    m_NaviRect.moveTo(x,y);


    emit ViewPosChg( e->pos().x()/200.0,e->pos().y()/200.0);
    QLabel::mouseMoveEvent(e);
    update();

}
void CNaviDialog::mouseReleaseEvent(QMouseEvent *e)
{


    setCursor(QCursor(Qt::ArrowCursor));
    QLabel::mouseReleaseEvent(e);

    m_Disable=false;

}

void CNaviDialog::UpdateGraphFile(const QString &file_name,double h_w_factor)
{
    QString graph_name = file_name;

    QPixmap tmppix(file_name);
    QPixmap pix=tmppix.scaledToWidth(rect().width());
    m_NaviRect = pix.rect();
    setPixmap(pix);

    update();

}


void CNaviDialog::paintEvent(QPaintEvent *e)
{
    QLabel::paintEvent(e);
    QPainter painter(this);
    painter.setPen(Qt::blue);



    painter.drawRect(m_NaviRect );

}


void CNaviDialog::OnMatrixChg(float scale,int dx,int dy)
{
    if (m_Disable)
    {
        return;
    }
    float kk=1;
    m_Matrix.setMatrix(1/scale,0,0,1/scale,-dx/kk/scale,-dy/kk/scale);
    QRect rect(0,0,200,200);
    if (pixmap())
    {
        rect=pixmap()->rect();
    }
    m_NaviRect=m_Matrix.mapRect(rect);
    update();

}
