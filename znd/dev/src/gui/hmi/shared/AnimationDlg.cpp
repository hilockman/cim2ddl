

#include "Global.h"
#include "AnimationDlg.h"
#include "propertyeditor.h"
#include "AnimateDriver.h"
#include "GraphItem.h"
#include "GraphScene.h"
#include "ItemBox.h"
#include "Colorbutton.h"
#include "CDyTableItemDelegate.h"
#include "GFunc.h"
#include "CommunicatePluginMng.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif

QString COLOR_CFG = QString(QT_TRANSLATE_NOOP("AnimationDlg", "animSetting"));
QString CHILD_PRE = QString(QT_TRANSLATE_NOOP("AnimationDlg", "child-"));
enum col_name
{
    Val=0,Description,LineColor,FillColor,FillMode,IfTwinking,Freq,LineDnColor,FillDnColor,RunFlag,IconPlane,Text,PixName,IfShow,Priority
};

AnimationDlg::AnimationDlg(QWidget *parent ,QGraphicsScene* pscene )
    : QDialog(parent)
{

    CAnimateDriver::LoadColorCfg();
    m_pScene=pscene;
    m_default_pre_name="<null>";
    m_CurType=-1;
    m_pItem=NULL;
    m_IfSetScene=false;
    ui.setupUi(this);

    connect(ui.m_ScriptEdit,SIGNAL(textChanged()),this,SLOT(OnScriptChg()));
    QList<PPTGroupPair> pptList;
    QList< QPair<QString,QVariant> > property_list;

    ui.m_DataSourceTable->setColumnHidden(1,true);
    ui.m_DataSourceTable->setColumnHidden(2,true);

    ui.m_DataSourceTable->setDragDropMode(QAbstractItemView::DropOnly);
    ui.m_DataSourceTable->installEventFilter(this);
    connect(ui.m_DataSourceTable, SIGNAL(itemChanged ( QTableWidgetItem * )),this, SLOT(OnTagItemChanged ( QTableWidgetItem * )));
    connect(ui.m_IfStateChgByValue, SIGNAL(stateChanged(int )),this, SLOT(OnAnimFlagChg ( int )));

    UpdateDlg(m_pScene);

    pptList.append(PPTGroupPair(tr("property"),property_list));
    m_pPropertyDetail = new PropertyEditor(ui.m_PropFrame);
    QStringList headLabels1;
    headLabels1<< tr("property")<< tr("value");
    m_pPropertyDetail->SetHeaderLabels(headLabels1);
    connect(m_pPropertyDetail, SIGNAL(propertyValueChanged(QString,QVariant,bool )), this, SLOT(updatePropertyDetail(QString,QVariant,bool)));

    m_pPropertyDetail->CreatePropertySheet(pptList);
    QGridLayout * gridLayout1 = new QGridLayout(ui.m_PropFrame);
    gridLayout1->addWidget(m_pPropertyDetail, 0, 0, 1, 1);

    SetupIcon();


    connect( ui.new_col_profile_btn, SIGNAL( clicked() ), this, SLOT( CreateNewColProfile()) );
    connect( ui.del_col_profile_btn, SIGNAL( clicked()), this, SLOT( DeleteColProfile()) );
    connect( ui.save_col_profile_btn, SIGNAL( clicked()), this, SLOT( SaveColProfileToDB()) );
    connect( ui.add_col_row_btn, SIGNAL(clicked()), this, SLOT( AddRowToDyTableWidget()));
    connect( ui.del_col_row_btn,SIGNAL(clicked()), this, SLOT( DelRowFromDyTableWidget()));
    //connect( ui.col_profile_name, SIGNAL( currentIndexChanged(int)), this,SLOT( ShiftColProfile(int)) );
    //connect( ui.dy_col_table, SIGNAL( cellChanged(int,int)), this,SLOT( SetModCfgFlag(int,int)));
    connect( ui.col_profile_name, SIGNAL( currentIndexChanged(const QString &)), this,SLOT( ShiftColProfile(const QString &)) );
    connect( ui.m_LTreeWidget, SIGNAL(ItemClicked( int,int,QString,QString)), this,SLOT( OnLTreeItemClicked(int,int,QString,QString)));


    connect(ui.pushButtonCancel,SIGNAL(clicked()),this,SLOT(OnRejected()));
    connect(ui.pushButtonApply,SIGNAL(clicked()),this,SLOT(OnAccepted()));

    QMap<int, CAnimationInfo>::iterator itr;
    for (itr = m_Props.begin(); itr != m_Props.end(); ++itr)
    {
        if (itr->valide)
        {
            this->PropertyItemChg("self", m_TypeName[CAnimation::COLOR_CFG]);
        }
    }
}

AnimationDlg::~AnimationDlg()
{

}

QJsonValue AnimationDlg::ParserJson(int groupid,QString groupName,QVector<int> anims)
{
    QJsonObject ret;
    QJsonArray jarr;
    for(int i=0;i<anims.size();i++)
    {
        int type=anims[i];
        QJsonObject jobj;
        jobj.insert("id", type );
        jobj.insert("text",m_TypeName[type]);
        jobj.insert("checked",m_Props[type].valide ? 2:0);
        jarr.append(jobj);
    }
    ret.insert("id",groupid);
    ret.insert("text",groupName);
    ret.insert("children",jarr);
    return ret;
}

void AnimationDlg::UpdateDlg(QGraphicsScene* pscene)
{
    if(this->isVisible()==false)
        return;

    if(pscene==NULL)
        return;
    m_pScene=pscene;
    m_CurType=-1;
    m_pItem=NULL;
    m_IfSetScene=false;

    if (m_pScene->selectedItems().size()==0)
    {
        m_IfSetScene=true;
    }

    QList<PPTGroupPair> pptList;
    QList< QPair<QString,QVariant> > property_list;


    CAnimationInfo animInfo;
    animInfo.valide=false;
    for(int i=CAnimation::COLOR_CFG;i<=CAnimation::FRAME_CHG;i++)
    {
        animInfo.anim.SetType(i);
        m_Props[i]=animInfo;
        m_TypeName[i]=CAnimation::GetAnimDesc(i);
    }

    QVector<CAnimation> animations;
    QString userData;
    if(m_IfSetScene)
    {
        userData=dynamic_cast<CGraphScene*>(m_pScene)->GetUserData();
    }
    else
    {
        m_pItem=m_pScene->selectedItems().first();
        if (m_pItem && g_dataPtr(m_pItem))
            userData = g_dataPtr(m_pItem)->GetUserData();
    }
    animations = CAnimation::ParseJsonStr(userData, g_dataPtr(m_pItem));

    for(int i=0;i<animations.size();i++)
    {
        animInfo.valide=true;
        animInfo.anim= animations[i];
        m_Props[animInfo.anim.type()]=animInfo;
    }
    m_ItemProps["self"]=m_Props;
    if (m_pItem && m_pItem->type() == Hmi::QtChart)
        m_Props[CAnimation::COLOR_CFG].valide = true;


    QJsonArray janims;
    QVector<int> types;
    types<<CAnimation::COLOR_CFG;
    QJsonValue jval=ParserJson(1000,tr("color"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::VISIBLE;
    jval=ParserJson(1001,tr("visible"),types);janims.append(jval);
    types.clear();
    types<<CAnimation::H_MOVE<<CAnimation::V_MOVE;
    jval=ParserJson(1002,tr("move"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::ROTATE<<CAnimation::ROTATE_OP;
    jval=ParserJson(1002,tr("rotate"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::H_FILL_PERCENT<<CAnimation::V_FILL_PERCENT;
    jval=ParserJson(1002,tr("fill"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::H_SCALE<<CAnimation::V_SCALE;
    jval=ParserJson(1002,tr("scale"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::H_MOVE_OP<<CAnimation::V_MOVE_OP;
    jval=ParserJson(1002,tr("mouseDrag"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::L_MOUSE_CLICK<<CAnimation::L_MOUSE_DBCLICK;
    jval=ParserJson(1002,tr("mouseClick"),types); janims.append(jval);
    types.clear();
    types<<CAnimation::TEXT_OUT<<CAnimation::FRAME_CHG;
    jval=ParserJson(1002,tr("text"),types); janims.append(jval);
    QJsonDocument jdoc(janims);
    QString jsonArrays=jdoc.toJson();

    ui.m_LTreeWidget->LoadData(jsonArrays,"id","pid");
    ui.m_LTreeWidget->expandAll();
    ui.m_LTreeWidget->SetCurrentItem(0,0,0);
    ui.m_LTreeWidget->setHeaderLabel(tr("animtype"));

    PropertyItemChg("self", m_TypeName[CAnimation::COLOR_CFG]);
}


CAnimationInfo* AnimationDlg::CurAnimInfo()
{
    return &(m_ItemProps[m_GroupName][m_CurType]);
}

void AnimationDlg::OnLTreeItemClicked(int index,int column,QString text,QString data)
{
    int id=ui.m_LTreeWidget->currentItem()->data(0,Qt::ToolTipRole).toInt();
    if(id<1000)
    {
        m_GroupName="self";
        m_CurType=m_TypeName.key(text);//id
        bool checked=ui.m_LTreeWidget->currentItem()->checkState(0);
        CurAnimInfo()->valide=checked;
        PropertyItemChg( m_GroupName,text);
    }
}

void AnimationDlg::PropertyItemChg(QString groupName,QString propName)
{
    
    QList<PPTGroupPair> pptList;
    QList< QPair<QString,QVariant> > property_list;

    m_CurType=m_TypeName.key(propName);
    m_GroupName=groupName;
    ui.m_ScriptEdit->setPlainText( CurAnimInfo()->anim.GetScript());
    ui.m_IfStateChgByValue->setChecked(CurAnimInfo()->anim.AnimationFlag());

    if(InitColorCfgTab(propName)<0)
    {
        ui.stackedWidget->setCurrentIndex(0);
        CurAnimInfo()->anim.GetPropertyList(property_list);
        pptList.append(PPTGroupPair("property",property_list));
        m_pPropertyDetail->CreatePropertySheet(pptList);
    }


    ui.m_DataSourceTable->setRowCount(0);
    QVector<CTag> tags=CurAnimInfo()->anim.GetTag();
    int rows= tags.size()>10 ? tags.size():10 ;
    ui.m_DataSourceTable->setRowCount(rows);
    QStringList lables;
    for(int i=0;i<rows;i++)
    {
        lables.append(QString("x%1").arg(i));
    }

    ui.m_DataSourceTable->setVerticalHeaderLabels(lables);
    ui.m_DataSourceTable->verticalHeader()->show();

    for(int i=0;i<tags.size();i++)
    {
        ui.m_DataSourceTable->setItem(i,0,new QTableWidgetItem(tags[i].tag_name));
        ui.m_DataSourceTable->setItem(i,1,new QTableWidgetItem(tags[i].type));



        SetTagRef(i,tags[i].ChannelName());
    }

}

void AnimationDlg::SetTagRef(int row,QString tag_name)
{
}

void AnimationDlg::OnAnimFlagChg ( int state)
{
    bool IfStateChgByValue=ui.m_IfStateChgByValue->isChecked();
    CurAnimInfo()->anim.SetAnimationFlag(IfStateChgByValue);
}

void AnimationDlg::updatePropertyDetail(const QString &name, const QVariant& value,bool enableSubPropertyHandling)
{
    CurAnimInfo()->anim.SetProperty(name,value);
}

void AnimationDlg::OnScriptChg()
{
    CurAnimInfo()->anim.SetScript( ui.m_ScriptEdit->toPlainText());
}

void AnimationDlg::OnTagItemChanged ( QTableWidgetItem * item )
{
    QVector<CTag> tags;
    CTag tagval;

    for(int i=0;i<ui.m_DataSourceTable->rowCount();i++)
    {
        if (ui.m_DataSourceTable->item(i,0))
        {
            //ui.m_DataSourceTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            tagval.tag_name=ui.m_DataSourceTable->item(i,0)->text();
            if (ui.m_DataSourceTable->item(i,1))
                tagval.type=ui.m_DataSourceTable->item(i,1)->text();

            if (!tagval.tag_name.isEmpty())
            {
                tags.push_back(tagval);
                //if(i==row && col<2) SetTagRef(row, tagval.ChannelName());
            }
        }
    }
    CurAnimInfo()->anim.SetTag(tags);

}

void AnimationDlg::DeleteColProfile()
{


}

int AnimationDlg::InitColorCfgTab(const QString& propName)
{
    if (propName!=tr("animSetting") && propName!=tr("textOut"))
    {
        return -1;
    }
    ui.dy_col_table->setColumnCount(Priority+1);
    for(int i=Val;i<=Priority;i++)
    {
        ui.dy_col_table->showColumn(i);
    }

    ui.stackedWidget->setCurrentIndex(1);

    QString colorCfg=CurAnimInfo()->anim.GetColorCfg();
    CDyTableDelegate * pDelegate = new CDyTableDelegate();
    ui.dy_col_table->setItemDelegate( pDelegate );

    QStringList texts=CAnimateDriver::GetColorConfig()->keys();
    texts.push_front(m_default_pre_name);
    ui.col_profile_name->clear();
    ui.col_profile_name->addItems(texts );

    ui.dy_col_table->setAlternatingRowColors( true );


    int index = ui.col_profile_name->findText( colorCfg);
    if ( index > 0 )
        ui.col_profile_name->setCurrentIndex(index);
    GetColCfgByName( colorCfg );
    ui.dy_col_table->sortItems( 0 );

    ui.dy_col_table->hideColumn(FillMode) ;
    if (propName==tr("animSetting"))
    {
        ui.dy_col_table->hideColumn(Text) ;
        ui.dy_col_table->hideColumn(PixName) ;
    }
    else if (propName==tr("textOut"))
    {
        ui.dy_col_table->hideColumn(IconPlane) ;
        ui.dy_col_table->hideColumn(PixName) ;
    }
    return 0;
}

int AnimationDlg::GetColCfgByName( const QString & cfg_name)
{
    QMap<float,COLOR_CONFIG> itemMap=CAnimateDriver::GetColorConfig()->value(cfg_name);
    int row = 0;
    QMap<float,COLOR_CONFIG>::iterator it=itemMap.begin();

    ui.dy_col_table->setRowCount(0);
    for (it;it!=itemMap.end();++it)
    {
        ui.dy_col_table->insertRow(row);
        SetDyRowData( row,it.value() );
        row++;
    }

    return 0;
}

void AnimationDlg::AddRowToDyTableWidget()
{
    if ( ui.col_profile_name->currentText() ==m_default_pre_name || ui.col_profile_name->currentText().isEmpty() )
    {
        QMessageBox::critical(this, "Error","Profile name is empty or error!",QMessageBox::Ok);
        return;
    }
    int nRow = ui.dy_col_table->currentRow();
    if ( nRow < 0 )
    {
        nRow = ui.dy_col_table->rowCount();
        ui.dy_col_table->setRowCount( nRow+1 );
    }
    else
    {
        ui.dy_col_table->insertRow( nRow );
    }
    COLOR_CONFIG color_cfg;
    SetDyRowData( nRow, color_cfg );
    m_nIsDyTableMod = true;
}

void AnimationDlg::DelRowFromDyTableWidget()
{
    int nRow = ui.dy_col_table->currentRow();
    if ( nRow >= 0 )
    {
        ui.dy_col_table->removeRow( nRow );
    }
    m_nIsDyTableMod = true;
}


void AnimationDlg::CreateNewColProfile()
{
    if ( ui.col_profile_name->currentText().isEmpty() )
        return;

    if (ui.col_profile_name->currentText() != m_default_pre_name && !m_DyCfgNames.contains(ui.col_profile_name->currentText() ))
    {
        if ( QMessageBox::warning(this, "Tips","To give up the existing changes?",QMessageBox::Ok,QMessageBox::Cancel)== QMessageBox::Cancel)
            return;
    }
    ui.col_profile_name->clearEditText();
    ui.dy_col_table->clearContents();
    ui.dy_col_table->setRowCount(1);
    COLOR_CONFIG color_cfg;
    SetDyRowData( 0, color_cfg );
    ui.col_profile_name->setFocus();
}

void AnimationDlg::ShiftColProfile(const QString & cfg_name)
{
    CurAnimInfo()->anim.SetProperty(tr("colorCfg"),cfg_name);
    GetColCfgByName( cfg_name);
}

void AnimationDlg::SaveColProfileToDB()
{
    int nRow;
    COLOR_CONFIG color_cfg;
    QString cfgName=ui.col_profile_name->currentText();
    QMap<float,COLOR_CONFIG> itemMap;
    for ( nRow = 0; nRow < ui.dy_col_table->rowCount(); nRow++ )
    {
        color_cfg.value =ui.dy_col_table->item( nRow, Val )->data( Qt::DisplayRole).toDouble();
        color_cfg.text =ui.dy_col_table->item( nRow, Text )->data( Qt::DisplayRole).toString();
        color_cfg.pix_name =ui.dy_col_table->item( nRow, PixName )->data( Qt::DisplayRole).toString();
        color_cfg.line_color =((GCDyColorWidget *)ui.dy_col_table->cellWidget( nRow, LineColor ))->GetColor();
        color_cfg.fill_color =((GCDyColorWidget *)ui.dy_col_table->cellWidget( nRow, FillColor ))->GetColor();
        color_cfg.fill_mode =ui.dy_col_table->item( nRow, FillMode )->data( Qt::UserRole+1 ).toInt();
        color_cfg.if_twinking =ui.dy_col_table->item( nRow, IfTwinking )->data( Qt::DisplayRole).toBool();
        color_cfg.freq =ui.dy_col_table->item( nRow, Freq )->data( Qt::DisplayRole).toInt();
        color_cfg.line_dn_color =((GCDyColorWidget *)ui.dy_col_table->cellWidget( nRow, LineDnColor ))->GetColor();
        color_cfg.fill_dn_color =((GCDyColorWidget *)ui.dy_col_table->cellWidget( nRow, FillDnColor ))->GetColor();
        color_cfg.icon_plane =ui.dy_col_table->item( nRow, IconPlane )->data( Qt::DisplayRole).toInt();
        color_cfg.if_show =ui.dy_col_table->item( nRow, IfShow )->data( Qt::DisplayRole).toBool();
        color_cfg.priority =ui.dy_col_table->item( nRow, Priority )->data( Qt::DisplayRole).toInt();
        color_cfg.description =ui.dy_col_table->item( nRow, Description )->data( Qt::DisplayRole).toString();
        color_cfg.run_flg =ui.dy_col_table->item( nRow, RunFlag )->data( Qt::DisplayRole).toInt();
        itemMap[color_cfg.value]=color_cfg;

    }
    QMap<QString,QMap<float,COLOR_CONFIG> >* color_cfg_map=CAnimateDriver::GetColorConfig();
    color_cfg_map->insert ( cfgName, itemMap );
    CAnimateDriver::SaveColorCfg();
}

int AnimationDlg::SetDyRowData( int nRow, COLOR_CONFIG& color_cfg)
{
    QTableWidgetItem * pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.value );
    ui.dy_col_table->setItem( nRow, Val, pItem );

    GCDyColorWidget * pWidget = new GCDyColorWidget;
    pWidget->SetColor( color_cfg.line_color );
    ui.dy_col_table->setCellWidget( nRow , LineColor, pWidget );

    pWidget = new GCDyColorWidget;
    pWidget->SetColor( color_cfg.fill_color );
    ui.dy_col_table->setCellWidget( nRow , FillColor, pWidget );

    pItem = new QTableWidgetItem;
    short nfillmode = color_cfg.fill_mode;
    if((nfillmode<(int)Qt::NoBrush)||(nfillmode>(int)Qt::TexturePattern))
        nfillmode=(int)Qt::NoBrush;
    pItem->setData( Qt::UserRole, (int)QVariant::Brush );
    pItem->setData( Qt::UserRole+1, (int)nfillmode);
    ui.dy_col_table->setItem( nRow, FillMode, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole, (bool)color_cfg.if_twinking );
    ui.dy_col_table->setItem( nRow, IfTwinking, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.freq );
    ui.dy_col_table->setItem( nRow,Freq, pItem );

    pWidget = new GCDyColorWidget;
    pWidget->SetColor( color_cfg.line_dn_color );
    ui.dy_col_table->setCellWidget( nRow ,LineDnColor, pWidget );

    pWidget = new GCDyColorWidget;
    pWidget->SetColor( color_cfg.fill_dn_color );
    ui.dy_col_table->setCellWidget( nRow , FillDnColor, pWidget );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.icon_plane );
    ui.dy_col_table->setItem( nRow, IconPlane, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole, (bool)color_cfg.if_show );
    ui.dy_col_table->setItem( nRow, IfShow, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.text );
    ui.dy_col_table->setItem( nRow, Text, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.pix_name );
    ui.dy_col_table->setItem( nRow, PixName, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.priority );
    ui.dy_col_table->setItem( nRow, Priority, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.description );
    ui.dy_col_table->setItem( nRow, Description, pItem );

    pItem = new QTableWidgetItem;
    pItem->setData( Qt::DisplayRole,color_cfg.run_flg );
    ui.dy_col_table->setItem( nRow, RunFlag, pItem );
    return 0;
}

void AnimationDlg::SetDyTableEditor()
{
    CDyTableDelegate * pDelegate = new CDyTableDelegate();
    ui.dy_col_table->setItemDelegate( pDelegate );
    GCNoEditorDelegate *pNoEditor = new GCNoEditorDelegate();
    pNoEditor->insertColumn( 1 );
    pNoEditor->insertColumn( 2 );
    pNoEditor->insertColumn( 3 );
    GCNoEditorDelegate *pNoEditor1 = new GCNoEditorDelegate();
    pNoEditor1->insertColumn( 1 );
    pNoEditor1->insertColumn( 2 );
    pNoEditor1->insertColumn( 3 );

}

void AnimationDlg::SetupIcon()
{
    return;
}

void AnimationDlg::OnAccepted()
{
    QMap<int,CAnimationInfo>::iterator it = m_ItemProps["self"].begin();
    QJsonArray jsonArray;
    QString str;
    while (it != m_ItemProps["self"].end())
    {
        if (m_pItem && m_pItem->type() == Hmi::QtChart)
        {
            if (it.value().anim.type() == CAnimation::COLOR_CFG)
            {
                str = it.value().anim.GetTagInfo();
            }

        }
        else if (it.value().valide)
        {
            it.value().anim.SetType(it.key());
            QJsonObject jsonObj=it.value().anim.ToJsonObj();
            jsonArray.append(jsonObj);
        }
        ++it;
    }
    if (m_pItem && m_pItem->type() == Hmi::QtChart)
    {
#ifdef CHARTS
        CBaseData* pdata = NULL;
        pdata = g_dataPtr(m_pItem);
        ((CGChartItem*)m_pItem)->RemoveAllSeries();
        pdata->SetProperty("userData","[{!tags!:!" + str + "!}]");
#endif
    }
    else
    {
        QString str;
        if (!jsonArray.isEmpty())
        {
            QJsonDocument jdoc(jsonArray);
            str = jdoc.toJson(QJsonDocument::Compact);
            str.replace('"','!');
        }
        if(m_IfSetScene)
        {
            dynamic_cast<CGraphScene*>(m_pScene)->SetUserData(str);
        }
        else
        {
            CBaseData* pdata=NULL;
            pdata=g_dataPtr(m_pItem);
            pdata->SetUserData(str);
        }
    }
    //m_pScene->SetModified(true);
    hide();
}

void AnimationDlg::closeEvent(QCloseEvent *event)
{
    OnRejected();
}

void AnimationDlg::OnRejected()
{
    hide();
    return;
    QMessageBox mb("tip", tr("settings already be modified!\n Want to save?"),
                   QMessageBox::Warning, QMessageBox::Save | QMessageBox::Default,QMessageBox::Discard,
                   QMessageBox::Cancel ,this);
    mb.setButtonText( QMessageBox::Save, tr("Save") );
    mb.setButtonText( QMessageBox::Discard, tr("Discard") );
    mb.setButtonText( QMessageBox::Cancel, tr("Cancel") );
    int retmb=mb.exec();
    switch( retmb)
    {
    case QMessageBox::Save:
    {
        OnAccepted();
    }
        break;
    case QMessageBox::Discard:
        break;
    case QMessageBox::Cancel:
        return ;
    }
    hide();
}

bool AnimationDlg::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::DragEnter || event->type() == QEvent::DragMove) {
        QDropEvent *e = static_cast<QDropEvent *>(event);
        if (e->mimeData()->hasText() )
            e->acceptProposedAction();
        return true;
    } else if(event->type() == QEvent::Drop){
        QDropEvent *e = static_cast<QDropEvent *>(event);
        int nRow = ui.m_DataSourceTable->rowAt( e->pos().y());
        if ( nRow == -1 )   return true;
        if (e->mimeData()->hasText())
        {
            const QMimeData *mime = e->mimeData();
            QString  txt = mime->text();
            if (txt.length()<5)
            {
                return true;
            }
            QJsonArray jas=UnqFunc()->Str2JsonArray(txt);
            if (jas.size()<=0)
            {
                return true;
            }
            QJsonObject jo=jas[0].toObject();
            QString tag_name = jo["pnt_tag_name"].toString();
            e->acceptProposedAction();

            QTableWidgetItem *pItem = ui.m_DataSourceTable->item( nRow, 0);
            if ( pItem == NULL )
            {
                pItem = new QTableWidgetItem(tag_name);
                ui.m_DataSourceTable->setItem( nRow, 0, pItem );
            }
            else
            {
                pItem->setText( tag_name );
            }
        }
        return true;
    }
    else
        return QObject::eventFilter(obj, event);
}
