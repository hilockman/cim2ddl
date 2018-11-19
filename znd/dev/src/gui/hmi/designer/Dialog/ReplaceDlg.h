

#ifndef REPLACEDLG_H
#define REPLACEDLG_H 

#include "Global.h"
#include "ui_ReplaceDlg.h"
class CAnimation;
class QGraphicsSimpleTextItem;

class ReplaceDlg : public QDialog
{
    Q_OBJECT

public:
    ReplaceDlg(QWidget *parent = 0,QGraphicsScene* pscene=0);
    ~ReplaceDlg();
public slots:
    void OnAccepted();
    void OnReplaceClicked();
private:
    void Fliter(QGraphicsItem * item);

private:
    Ui::ReplaceDlgClass ui;
    QGraphicsItem * m_pItem;
	QMultiHash<QString, QGraphicsSimpleTextItem* > m_ItemText;
    QMultiHash<QString, CAnimation > m_AnimTag;
    bool m_isIcon;
    QGraphicsScene* m_pScene;
};

#endif
