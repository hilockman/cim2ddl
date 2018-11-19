

#ifndef GLOBALTOOLBAR_H
#define GLOBALTOOLBAR_H 

#include <QObject>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QString>

class GlobalToolBarCreator : public QObject
{
    Q_OBJECT

public:
    GlobalToolBarCreator(QMainWindow* window);

public slots:
    void currentFontChanged(const QFont &font);
    void fontSizeChanged(const QString &size);
    //void textColorChanged();
    void itemColorChanged();
    void lineColorChanged();
    //void textButtonTriggered();
    void fillButtonTriggered();
    void lineButtonTriggered();
    void handleFontChange();
    void patchCheckChanged(int state);
    void setDrawSettings(QVariantMap& settings);
    void getColor();
private:
    QMenu *createColorMenu(const char *slot, QColor defaultColor, QString flag);
    QIcon createColorToolButtonIcon(const QString &image, QColor color);
    QIcon createColorIcon(QColor color);


    QComboBox *itemColorCombo;
    QComboBox *textColorCombo;
    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;

    QButtonGroup *backgroundButtonGroup;
    //QToolButton *fontColorToolButton;
    QToolButton *fillColorToolButton;
    QToolButton *lineColorToolButton;
    QAction *boldAction;
    QAction *underlineAction;
    QAction *italicAction;
    //QAction *textAction;
    QAction *fillAction;
    QAction *lineAction;
    QAction *copyAction;
    QAction *groupAction;
    QAction *testAction;
    QAction *iconAction;
    QAction *m_customfcolor;
    QAction *m_customlcolor;
    QMainWindow* m_window;

    QCheckBox* patchCreateItemCheck;
    QSpinBox* createNum;


};
#endif
