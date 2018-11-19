


#include "Global.h"
#include "AnimateDriver.h"
#include "GraphItem.h"
#include "GroupItem.h"
#include "ReplaceDlg.h"

ReplaceDlg::ReplaceDlg(QWidget *parent ,QGraphicsScene* pscene )
    : QDialog(parent)
{
    m_isIcon=false;
    m_pScene=pscene;
    ui.setupUi(this);
    ui.tableWidget1->verticalHeader()->hide();
    ui.tableWidget2->verticalHeader()->hide();

    if (pscene->selectedItems().size()==0)
    {
        rejected();
        return;
    }

    QMap<QString,QString> txtMap,tagMap;
    /*if (pscene->selectedItems().first()->type()==Hmi::Icon)
    {
        CIconData* pdata=(CIconData*)g_dataPtr(pscene->selectedItems().first());
        if (pdata)
        {
            txtMap=pdata->GetTxtRefMap();
            tagMap=pdata->GetTagRefMap();
        }
        m_isIcon=true;
    }
    else*/
    {
        foreach(QGraphicsItem *item,pscene->selectedItems())
        {
            Fliter( item);
        }
        QList<QString> tmplist=m_ItemText.uniqueKeys();
        foreach(QString str,tmplist)
        {
            txtMap[str]="";
        }
        tmplist=m_AnimTag.uniqueKeys();
        foreach(QString str,tmplist)
        {
            tagMap[str]="";
        }
    }


    ui.tableWidget2->setRowCount(txtMap.size());
    QMap<QString,QString> ::iterator it=txtMap.begin();
    int i=0;
    for(it;it!=txtMap.end();++it,++i)
    {
        QTableWidgetItem* item=new QTableWidgetItem(it.key());
        int tmp = (int)item->flags();
        tmp &= ~(abs( Qt::ItemIsEditable ));
        item->setFlags((Qt::ItemFlags)tmp );
        ui.tableWidget2->setItem(i,0,item);
        ui.tableWidget2->setItem(i,1,new QTableWidgetItem(it.value()));
		ui.tableWidget2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    }

    ui.tableWidget1->setRowCount(tagMap.size());
    QMap<QString,QString> ::iterator it1=tagMap.begin();
    i=0;
    for(it1;it1!=tagMap.end();++it1,++i)
    {
        QTableWidgetItem* item=new QTableWidgetItem(it1.key());
        int tmp = (int)item->flags();
        tmp &= ~(abs( Qt::ItemIsEditable ));
        item->setFlags((Qt::ItemFlags)tmp );
        ui.tableWidget1->setItem(i,0,item);
        ui.tableWidget1->setItem(i,1,new QTableWidgetItem(it1.value()));
		ui.tableWidget1->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    }

    connect(this,SIGNAL(accepted()),this,SLOT(OnAccepted()));
    connect(ui.replaceBtn,SIGNAL(clicked()),this,SLOT(OnReplaceClicked()));

}

ReplaceDlg::~ReplaceDlg()
{

}

void ReplaceDlg::Fliter(QGraphicsItem * item)
{
    QString tagInfo="";
    CBaseData* pdata=const_cast<CBaseData*>(g_dataPtr(item));
    if(pdata )
    {
        tagInfo=pdata->GetUserData();
        QStringList taglist;
        QVector<CAnimation > anims = CAnimation::ParseJsonStr(tagInfo,pdata);
        for(int i=0;i<anims.size();i++)
        {
            QVector<CTag>& tags=anims[i].GetTag();
            for(int j=0;j<tags.size();j++)
            {
                taglist<<tags[j].ChannelName();
            }
			if (taglist.size()>0)
			{
				tagInfo = taglist.join(",");
				m_AnimTag.insert(tagInfo, anims[i]);
			}
        }

    }


    if (item->type()==Hmi::Text )//|| item->type()==Hmi::GraphicsText)
    {
        QString txt=((QGraphicsSimpleTextItem*)item)->text();
        m_ItemText.insertMulti(txt,(QGraphicsSimpleTextItem*)item);
    }
    foreach(QGraphicsItem *subitem,item->childItems())
    {
        Fliter(subitem);
    }


}

void ReplaceDlg::OnReplaceClicked()
{

    QString before=ui.lineEdit1->text();
    QString after=ui.lineEdit2->text();
    Qt::CaseSensitivity cs = ( ui.matchCase->isChecked())?(Qt::CaseSensitive):(Qt::CaseInsensitive);
    if (before.isEmpty() || after.isEmpty())
    {
        return;
    }
    if (ui.tabWidget->currentWidget()->objectName()=="tab1")
    {
        for(int i=0;i<ui.tableWidget1->rowCount();i++)
        {
            QString oldtag=ui.tableWidget1->item(i,0)->text();
            QString newtag = oldtag;
            newtag.replace( before, after, cs);
            if(newtag!=oldtag) ui.tableWidget1->item(i,1)->setText(newtag);
        }
    }
    else
    {
        for(int i=0;i<ui.tableWidget2->rowCount();i++)
        {
            QString oldtag=ui.tableWidget2->item(i,0)->text();
            QString newtag = oldtag;
            newtag.replace( before, after, cs);
            if(newtag!=oldtag) ui.tableWidget2->item(i,1)->setText(newtag);
        }
    }

}

void ReplaceDlg::OnAccepted()
{
   /* if (m_pScene->selectedItems().first()->type()==Hmi::Icon)
    {
        CIconData* pdata=(CIconData*)g_dataPtr(m_pScene->selectedItems().first());
        if (pdata==NULL)
        {
            return;
        }

        QMap<QString,QString> tmpmap;
        for(int i=0;i<ui.tableWidget1->rowCount();i++)
        {
            QTableWidgetItem *item=ui.tableWidget1->item(i,1);
            if (item && !item->text().isEmpty())
            {
                QString newtag=item->text();
                QString oldtag=ui.tableWidget1->item(i,0)->text();
                tmpmap[oldtag]=newtag;
            }
        }
        pdata->SetTagRefMap(tmpmap);

        tmpmap.clear();
        for(int i=0;i<ui.tableWidget2->rowCount();i++)
        {
            QTableWidgetItem *item=ui.tableWidget2->item(i,1);
            if (item && !item->text().isEmpty())
            {
                QString newtag=item->text();
                QString oldtag=ui.tableWidget2->item(i,0)->text();
                tmpmap[oldtag]=newtag;
            }
        }
        pdata->SetTxtRefMap(tmpmap);
        return;
    }*/


    for(int i=0;i<ui.tableWidget1->rowCount();i++)
    {
        QTableWidgetItem *item=ui.tableWidget1->item(i,1);
        if (item && !item->text().isEmpty())
        {
            QString newtag=item->text();
            QString oldtag=ui.tableWidget1->item(i,0)->text();
            QList<CAnimation > anims=m_AnimTag.values(oldtag);
            foreach(CAnimation anim,anims)
            {
                QVector<CTag> tags=anim.GetTag();
				for(int k=0;k<tags.size();k++)
                {
					if(tags[k].tag_name==oldtag)
                    {
                        tags[k].tag_name=newtag;
                    }
                }
				anim.SetTag(tags);
				//ÐÞ¸Äuserdata
				CBaseData* pdata = anim.GetBaseData();
				if (pdata)
				{
					QString data = pdata->GetUserData();
					data.replace(oldtag, newtag);
					pdata->SetUserData(data);
				}
            }
        }
    }

    for(int i=0;i<ui.tableWidget2->rowCount();i++)
    {
        QTableWidgetItem *item=ui.tableWidget2->item(i,1);
        if (item && !item->text().isEmpty())
        {
            QList<QGraphicsSimpleTextItem*> tmpitems=m_ItemText.values(ui.tableWidget2->item(i,0)->text());
            foreach(QGraphicsSimpleTextItem* txtItem,tmpitems)
            {
                g_dataPtr(txtItem)->SetProperty("text",item->text());
            }
        }
    }


}
