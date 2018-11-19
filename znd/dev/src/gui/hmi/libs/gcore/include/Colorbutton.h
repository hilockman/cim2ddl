


#ifndef GCOLORBUTTON_H
#define GCOLORBUTTON_H 

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include "Export.h"

class DLL_CLASS ColorButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(bool backgroundCheckered READ isBackgroundCheckered WRITE setBackgroundCheckered)
public:
    ColorButton(QWidget *parent = 0);
    ~ColorButton();

    bool isBackgroundCheckered() const;
    void setBackgroundCheckered(bool checkered);

    QColor color() const;

public slots:
   //for script
QString GetColorName(){ return m_color.name(); }
void SetColor(QString name){ setColor(QColor(name)); }

public slots :

    void setColor(const QColor &color);
    void slotEditColor();
signals:
    void colorChanged(const QColor &color);
protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor m_color;
    bool m_backgroundCheckered;


    QColor shownColor() const;
    QPixmap generatePixmap() const;
};

class DLL_CLASS GCDyColorWidget : public QWidget
{
public:
    GCDyColorWidget(QWidget *parent = NULL );
    ~GCDyColorWidget(void);
    QString GetColor () const ;
    void SetColor( QString color );
    int isModified( ) { return (m_nInitColor!=GetColor());};
    void ResetStatus() { m_nInitColor = GetColor();};
private:
    QString m_nInitColor;
    QCheckBox *m_pCheckBox;
    ColorButton *m_pColorButton;
};

#endif
