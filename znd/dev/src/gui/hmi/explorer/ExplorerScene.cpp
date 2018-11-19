#include "ExplorerScene.h"
#include "AnimateDriver.h"
#include "CQScriptWrap.h"
#include "GraphItem.h"
#include "WidgetItem.h"
#include "CommunicatePluginMng.h"

CGExplorerScene::CGExplorerScene(QObject *parent):CGraphScene( parent)
{
    m_Driver = new CAnimateDriver(this);
}

CGExplorerScene::~CGExplorerScene()
{
    delete m_Driver;
}

void CGExplorerScene::Reset()
{
    CGraphScene::Reset();
    m_Driver->Reset();
	m_app = "";
}

int CGExplorerScene::FileOpen(const QString& fileName, QString replace_info, QString currentApp)
{
    int ret=0;
	if (fileName.right(4) == PICBINARYSUFFIX)
	{
        ret=CGraphScene::FileOpen(fileName, true);
	}
	else
        ret=CGraphScene::FileOpen(fileName);

	m_Driver->InitDriver(fileName,currentApp,replace_info);
    foreach(QGraphicsItem *item, items())
    {
        item->setFlag(QGraphicsItem::ItemIsMovable, false);
        if (item->type()==Hmi::Pin)
        {
            item->hide();
        }
    }
    return ret;
}

bool CGExplorerScene::ChangeApp(QString currentApp)
{
	//turn to currentApp, modify tags
	if (currentApp.isEmpty() || m_app == currentApp)
		return false;
	m_app = currentApp;
	QList<QGraphicsItem*> objLst = Items(true, false);
	foreach(QGraphicsItem *item, objLst)
	{
		if (g_dataPtr(item) == NULL)
			continue;

		QString orgStr = g_dataPtr(item)->GetUserData();
		if (orgStr != "")
		{
			orgStr.replace('!', '"');
			QJsonParseError error;
			QJsonDocument jsonDoc = QJsonDocument::fromJson(orgStr.toUtf8(), &error);
			if (error.error == QJsonParseError::NoError) {
				if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
					if (jsonDoc.isObject())
					{
						QJsonObject jobj = jsonDoc.object();
						QString tags = jobj["tags"].toString();
						QStringList taglist = tags.split(",", QString::SkipEmptyParts);
						for (int i = 0; i < taglist.size(); i++)
						{
							QStringList lst = taglist[i].split(".");
							if (lst.length() > 1)
								taglist[i].replace(taglist[i].split(".").at(1), currentApp);
						}
						jobj["tags"] = taglist.join(",");
						orgStr = QString(QJsonDocument(jobj).toJson().data()).replace('"', '!');

					}
					else if (jsonDoc.isArray())
					{
						QJsonArray jsonArrays = jsonDoc.array();
						for (int i = 0; i < jsonArrays.size(); i++)
						{
							QJsonObject jobj = jsonArrays[i].toObject();
							QString tags = jobj["tags"].toString();
							QStringList taglist = tags.split(",", QString::SkipEmptyParts);
                            for (int j = 0; j < taglist.size(); j++)
							{
                                QStringList lst = taglist[j].split(".");
								if (lst.length()>4)
                                    taglist[j].replace(taglist[j].split(".").at(1), currentApp);
							}
							jobj["tags"] = taglist.join(",");
							jsonArrays[i] = jobj;
						}
						orgStr = QString(QJsonDocument(jsonArrays).toJson().data()).replace('"', '!');
					}
				}
			}
			g_dataPtr(item)->SetUserData(orgStr);
		}
	}
	return true;
}

void CGExplorerScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    CGraphScene::mousePressEvent(mouseEvent);
    QGraphicsItem * item = itemAt(mouseEvent->scenePos(), QTransform());
    m_Driver->Operate(item,mouseEvent);

}
void CGExplorerScene::mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    QGraphicsItem * item=mouseGrabberItem();
    if (item)
    {
        while (item->parentItem())
            item = item->parentItem();

        //item->setFlags(item->flags() & ~QGraphicsItem::ItemIsMovable);

        m_Driver->Operate(item, mouseEvent);
    }
	CGraphScene::mouseMoveEvent(mouseEvent);



}

void CGExplorerScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QGraphicsItem * item = itemAt(mouseEvent->scenePos(), QTransform());
    m_Driver->Operate(item, mouseEvent);
    CGraphScene::mousePressEvent(mouseEvent);
}
int CGExplorerScene::Advance(long time_ms)
{
    int retcode=-1;






    return retcode;
}
