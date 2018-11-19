

#ifndef _CGRID_H_
#define _CGRID_H_ 

#include "Global.h"

const int OFFSET = 2;


class DLL_CLASS CGrid : QObject
{
    Q_OBJECT
    enum Grid_Type
    {
        Enum_Dot,
        Enum_Dash,
        Enum_Solid,
    };
public:
    CGrid();
    void GetCatchPoint( QPointF & );
    void Draw( QPainter *painter, const QRectF &rectF );
    QPen GetPen()
    {
        return m_Pen;
    };

    void SetPen( QPen &pen )
    {
        m_Pen = pen;
    };

    void SetGridType( CGrid::Grid_Type nType )
    {
        m_nType = nType;
    };
    void SetGridSize( int size){m_GridSize = size>0?size:1;};
    int GetGridSize( ){return m_GridSize  ;};
    bool Visible();
    void SetVisible( bool bVisible );
    bool Adhere();
    void SetAdhere( bool bAdhere );
    int GetWidth();
    int GetHeight();
protected:
    void PaintLineGrid( QPainter *painter, const QRectF &rectF );
    void PaintDotGrid( QPainter *painter, const QRectF &rectF );
private:
    QPen m_Pen;
    bool m_bVisible;
    bool m_bAdhere;
    Grid_Type m_nType;
    QColor m_Color;
    int m_nWidth;
    int m_nHeight;
    int m_GridSize ;//OFFSET * 3;
};

DLL_CLASS CGrid * UnqGrid();


#endif
