

#ifndef ANIMATIONDIALOG
#define ANIMATIONDIALOG 

#include "Global.h"
#include "ui_AnimationDlg.h"
#include "AnimateDriver.h"
class PropertyEditor;

struct CAnimationInfo
{
    CAnimation anim;
    bool valide;
};

class AnimationDlg : public QDialog
{
    Q_OBJECT

public:
    AnimationDlg(QWidget *parent = 0,QGraphicsScene* pscene=0);
    ~AnimationDlg();
    void PropertyItemChg(QString groupName,QString propName);
    void closeEvent(QCloseEvent *event);
public slots:
    void updatePropertyDetail(const QString &name, const QVariant& value,bool enableSubPropertyHandling);
    void OnScriptChg();
    void OnAccepted();
    void OnRejected();
    void OnAnimFlagChg(int);
    void OnTagItemChanged( QTableWidgetItem * item );

    void CreateNewColProfile();
    void DeleteColProfile();
    void SaveColProfileToDB();
    void ShiftColProfile( const QString & name);
    void AddRowToDyTableWidget();
    void DelRowFromDyTableWidget();
    void UpdateDlg(QGraphicsScene *pscene );
    void OnLTreeItemClicked(int index, int column, QString text, QString data);

public:
    void SetupIcon();
    int SetDyRowData( int nRow, COLOR_CONFIG& color_cfg);
    void SetDyTableEditor();
    int InitColorCfgTab(const QString& propName);
    int GetColCfgByName( const QString & cfg_name);
    CAnimationInfo* CurAnimInfo();
    void SetTagRef(int row,QString tag_name);
    QJsonValue ParserJson(int groupid, QString groupName, QVector<int> anims);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    PropertyEditor *m_pPropertyBox;
    PropertyEditor *m_pPropertyDetail;
    Ui::AnimationDlgClass ui;
    QMap<int,CAnimationInfo> m_Props;
    QMap<QString, QMap<int,CAnimationInfo> > m_ItemProps;
    int m_CurType;
    QString m_GroupName;
    QMap<int,QString> m_TypeName;
    QGraphicsItem * m_pItem;
    QString m_default_pre_name;
    bool m_nIsDyTableMod;
    QSet<QString> m_DyCfgNames;
    QGraphicsScene* m_pScene;
    bool m_IfSetScene;
};

#endif
