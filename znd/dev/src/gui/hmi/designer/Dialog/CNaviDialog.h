#if !defined _AFX_NAVIDLG_H
#define _AFX_NAVIDLG_H 

#include "Global.h"

class CNaviDialog : public QLabel
{
    Q_OBJECT
public:


    CNaviDialog(QWidget * parent,Hmi::SCENE_TYPE wnd = Hmi::Designer, const char * name = 0, Qt::WindowFlags f = 0);

    void UpdateGraphFile(const QString& file_name,double h_w_factor =1.0);

public slots:

    void OnMatrixChg(float scale,int dx,int dy);
signals:
    void ViewPosChg(float dx,float dy);
public:
    virtual ~CNaviDialog();
protected:

    void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );
    void mouseMoveEvent ( QMouseEvent * e );
    void paintEvent(QPaintEvent *e);


private:
    bool m_Disable;
    QMatrix m_Matrix;

    QRect m_NaviRect;

};




#endif
