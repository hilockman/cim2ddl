

#ifndef ICONDLG_H
#define ICONDLG_H 
#include "ui_icon-setting.h"





class QGraphicsItem;
class IconSetDlg : public QDialog
{
    Q_OBJECT
public:

    IconSetDlg(QPixmap& icon, QStringList& symbolInfo, QWidget* parent = 0);
    bool Init();



private slots:
    void on_buttonBox_clicked(QAbstractButton* button);
    void on_radioBtn_sel_clicked(bool checked);
    void on_radioBtn_auto_clicked(bool checked);

private:
    bool LoadTypeInfo();
    Ui_Dialog ui;
    QStringList& m_symbolInfo;
    QPixmap& m_icon;
	QString m_iconPicFile;
    QGraphicsItem* m_item;
    QStringList m_iconTypeList;
};





#endif
