#include <QPainter>
#include <QVarLengthArray>
#include "CGrid.h"
#include <QtDebug>

static int GRIDSIZE=10;
CGrid * UnqGrid()
{
    static CGrid _CGrid_instance;
    return &_CGrid_instance;
}

CGrid::CGrid()
{
    m_GridSize=GRIDSIZE;
    m_Pen = QPen( Qt::black );
    m_Pen.setWidthF( 0 );

    m_Pen.setColor( Qt::darkGray );

    m_Color = QColor( 255, 255, 255 );

    m_bVisible = false;

    m_bAdhere = false;
    m_nType = Enum_Dot;
}

void CGrid::GetCatchPoint( QPointF &point )
{
    if( m_bAdhere )
    {
        int nX1 = point.x() / m_GridSize;
        int nY1 = point.y() / m_GridSize;

        int nX2 = nX1 + 1;
        int nY2 = nY1 + 1;

        int nX = nX1;
        int nY = nY1;

        if( abs( point.x() - nX1 * m_GridSize ) > abs( point.x() - nX2 * m_GridSize ) )
        {
            nX = nX2;
        }

        if( abs( point.y() - nY1 * m_GridSize ) > abs( point.y() - nY2 * m_GridSize ) )
        {
            nY = nY2;
        }

        point = QPointF( nX * m_GridSize, nY * m_GridSize );
    }
    else
    {
        int nX = qRound( point.x() );
        int nY = qRound( point.y() );
        point = QPointF( nX, nY );
    }
}

bool CGrid::Adhere()
{
    return m_bAdhere;
}

void CGrid::SetAdhere( bool bAdhere )
{
    m_bAdhere = bAdhere;
}

void CGrid::Draw( QPainter *painter, const QRectF &rectF )
{
    if(!m_bVisible) return;
    switch( m_nType )
    {
        case Enum_Dot:
            PaintDotGrid( painter, rectF );
            break;

        case Enum_Dash:
        case Enum_Solid:
            PaintLineGrid( painter, rectF );
            break;

        default:
            break;
    }
}


void CGrid::PaintLineGrid( QPainter *painter, const QRectF &rectF )
{
    painter->save();
    m_nWidth = rectF.width();
    m_nHeight = rectF.height();
    qreal left = int( rectF.left() ) - ( int( rectF.left() ) % m_GridSize );
    qreal top = int( rectF.top() ) - ( int( rectF.top() ) % m_GridSize );
    QVarLengthArray<QLineF, 100> lines;

    for( qreal x = left; x < rectF.right(); x += m_GridSize )
    {
        lines.append( QLineF( x, rectF.top(), x, rectF.bottom() ) );
    }

    for( qreal y = top; y < rectF.bottom(); y += m_GridSize )
    {
        lines.append( QLineF( rectF.left(), y, rectF.right(), y ) );
    }

    if( m_nType == Enum_Solid )
    {
        m_Pen.setStyle( Qt::SolidLine );
    }
    else
    {
        m_Pen.setStyle( Qt::DashLine );
    }

    painter->fillRect( rectF, QBrush( m_Color ) );
    painter->setPen( m_Pen );
    painter->drawLines( lines.data(), lines.size() );
    painter->restore();
}


void CGrid::PaintDotGrid( QPainter *painter, const QRectF &rectF )
{
    painter->save();
    int kk=(int) painter->matrix().m11() ;
    if(kk<=9) m_GridSize=GRIDSIZE;
    if(kk>9) m_GridSize=1;

    m_nWidth = rectF.width();
    m_nHeight = rectF.height();
    int nx = rectF.width() / m_GridSize ;
    int ny = rectF.height() / m_GridSize;
    QVarLengthArray<QPointF, 100> points;

    for( int i = 0; i < ny; i++ )
    {
        for( int j = 0; j < nx; j++ )
        {
            points.append( QPointF( j * m_GridSize, i * m_GridSize ) );
        }
    }


    painter->setPen( m_Pen );
    painter->drawPoints( points.data(), points.size() );
    painter->restore();
}

bool CGrid::Visible()
{
    return m_bVisible;
}

void CGrid::SetVisible( bool bVisible )
{
    m_bVisible = bVisible;
}

int CGrid::GetWidth()
{
    return m_nWidth;
}

int CGrid::GetHeight()
{
    return m_nHeight;
}
