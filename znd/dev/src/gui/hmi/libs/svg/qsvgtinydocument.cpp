/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt SVG module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qsvgtinydocument_p.h"

#include "qsvghandler_p.h"
#include "qsvgfont_p.h"

#include "qpainter.h"
#include "qfile.h"
#include "qbuffer.h"
#include "qbytearray.h"
#include "qqueue.h"
#include "qstack.h"
#include "qdebug.h"


#include "GroupItem.h"
#include "ItemFactory.h"
#include "GFunc.h"
#include "WidgetItem.h"
#include "CQScriptWrap.h"
#include "GChartItem.h"
#include "IconMng.h"
#include "eco/SimpleIni.h"
#include "sys/eproc.h"
#include <QGraphicsItemGroup>

#ifndef QT_NO_COMPRESS
#include <zlib.h>
#endif

QT_BEGIN_NAMESPACE

int ICON_SIZE = 50;

static QString m_dir = "";////////导入图形目录 即存放svgimp.ini文件的目录////////

///////////////////////svgimp.ini配置信息////////////////////////
QString QSvgTinyDocument::m_planeSeparateChar = "";
int QSvgTinyDocument::m_symbolIdL = 0;
bool QSvgTinyDocument::m_cb_change_status = false;
QVariantMap QSvgTinyDocument::m_measureNameMap;
QMultiMap<QString, QString> QSvgTinyDocument::m_layer2tableMap;
QVariantMap QSvgTinyDocument::m_layer2columnMap ;
QVariantMap QSvgTinyDocument::m_psr2rdfidMap ;
QVariantMap QSvgTinyDocument::m_node2item ;
QVariantMap QSvgTinyDocument::m_attr2child;
QStringList QSvgTinyDocument::m_hideLayer ;
QString QSvgTinyDocument::m_dmName ;
QString QSvgTinyDocument::m_sysName;
RTDB_ClientBase* QSvgTinyDocument::m_pRTDBCli = NULL;
DbClient* QSvgTinyDocument::m_pDBCli = NULL;
DBSync* QSvgTinyDocument::m_pSyncWriteCli = NULL;
bool QSvgTinyDocument::m_useDB = false;
QFile* QSvgTinyDocument::m_logFile = NULL;
QTextStream* QSvgTinyDocument::out = NULL;
SysRun* QSvgTinyDocument::m_pSysRun = NULL;

QSvgTinyDocument::QSvgTinyDocument()
    : QSvgStructureNode(0)
    , m_widthPercent(false)
    , m_heightPercent(false)
    , m_animated(false)
    , m_animationDuration(0)
    , m_fps(30)
{
	m_pScene=NULL;
	m_pSysRun == NULL;
	if (m_dir == "")
	    InitSetting();
}

QSvgTinyDocument::~QSvgTinyDocument()
{
	if (m_pRTDBCli)
	{
		delete m_pRTDBCli;
		m_pRTDBCli = NULL;
	}
	if (m_pDBCli)
	{
		delete m_pDBCli;
		m_pDBCli = NULL;
	}
	if (m_pSysRun)
	{
		delete m_pSysRun;
		m_pSysRun = NULL;
	}
	if (m_pSyncWriteCli)
	{
		delete m_pSyncWriteCli;
		m_pSyncWriteCli = NULL;
	}
	if (out)
	{
		delete out;
		out = NULL;
	}
	if (m_logFile)
	{
		delete m_logFile;
		m_logFile = NULL;
	}
	m_layer2tableMap.clear();
	m_measureNameMap.clear();
	m_layer2columnMap.clear();
	m_psr2rdfidMap.clear();
	m_node2item.clear();
	m_attr2child.clear();
	m_hideLayer.clear();
}

#ifndef QT_NO_COMPRESS
#   ifdef QT_BUILD_INTERNAL
Q_AUTOTEST_EXPORT QByteArray qt_inflateGZipDataFrom(QIODevice *device);
#   else
static QByteArray qt_inflateGZipDataFrom(QIODevice *device);
#   endif

QByteArray qt_inflateGZipDataFrom(QIODevice *device)
{
    if (!device)
        return QByteArray();

    if (!device->isOpen())
        device->open(QIODevice::ReadOnly);

    Q_ASSERT(device->isOpen() && device->isReadable());

    static const int CHUNK_SIZE = 4096;
    int zlibResult = Z_OK;

    QByteArray source;
    QByteArray destination;

    // Initialize zlib stream struct
    z_stream zlibStream;
    zlibStream.next_in = Z_NULL;
    zlibStream.avail_in = 0;
    zlibStream.avail_out = 0;
    zlibStream.zalloc = Z_NULL;
    zlibStream.zfree = Z_NULL;
    zlibStream.opaque = Z_NULL;

    // Adding 16 to the window size gives us gzip decoding
    if (inflateInit2(&zlibStream, MAX_WBITS + 16) != Z_OK) {
        qWarning("Cannot initialize zlib, because: %s",
                (zlibStream.msg != NULL ? zlibStream.msg : "Unknown error"));
        return QByteArray();
    }

    bool stillMoreWorkToDo = true;
    while (stillMoreWorkToDo) {

        if (!zlibStream.avail_in) {
            source = device->read(CHUNK_SIZE);

            if (source.isEmpty())
                break;

            zlibStream.avail_in = source.size();
            zlibStream.next_in = reinterpret_cast<Bytef*>(source.data());
        }

        do {
            // Prepare the destination buffer
            int oldSize = destination.size();
            destination.resize(oldSize + CHUNK_SIZE);
            zlibStream.next_out = reinterpret_cast<Bytef*>(
                    destination.data() + oldSize - zlibStream.avail_out);
            zlibStream.avail_out += CHUNK_SIZE;

            zlibResult = inflate(&zlibStream, Z_NO_FLUSH);
            switch (zlibResult) {
                case Z_NEED_DICT:
                case Z_DATA_ERROR:
                case Z_STREAM_ERROR:
                case Z_MEM_ERROR: {
                    inflateEnd(&zlibStream);
                    qWarning("Error while inflating gzip file: %s",
                            (zlibStream.msg != NULL ? zlibStream.msg : "Unknown error"));
                    destination.chop(zlibStream.avail_out);
                    return destination;
                }
            }

        // If the output buffer still has more room after calling inflate
        // it means we have to provide more data, so exit the loop here
        } while (!zlibStream.avail_out);

        if (zlibResult == Z_STREAM_END) {
            // Make sure there are no more members to process before exiting
            if (!(zlibStream.avail_in && inflateReset(&zlibStream) == Z_OK))
                stillMoreWorkToDo = false;
        }
    }

    // Chop off trailing space in the buffer
    destination.chop(zlibStream.avail_out);

    inflateEnd(&zlibStream);
    return destination;
}
#endif

QSvgTinyDocument * QSvgTinyDocument::load(const QString &fileName)
{
	log_info("--import::begin load svg----%s", fileName.toLocal8Bit().data());
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
		gError("Cannot open file '%s', because: %s",
			fileName.toLocal8Bit().data(), file.errorString().toLocal8Bit().data());
        return 0;
    }

#ifndef QT_NO_COMPRESS
    if (fileName.endsWith(QLatin1String(".svgz"), Qt::CaseInsensitive)
            || fileName.endsWith(QLatin1String(".svg.gz"), Qt::CaseInsensitive)) {
        return load(qt_inflateGZipDataFrom(&file));
    }
#endif
	if (m_dir == ""){//init 
		m_dir = QFileInfo(file).absolutePath();
		if (!InitDBPtr())
			return 0;
		//InitErrorLog();
	}
	if (m_measureNameMap.size() == 0){
		InitSetting();
	}
    QSvgTinyDocument *doc = 0;
    QSvgHandler handler(&file);
    if (handler.ok()) {
        doc = handler.document();
        doc->m_animationDuration = handler.animationDuration();
    } else {
        gError("Cannot read file '%s', because: %s (line %d)",
			fileName.toLocal8Bit().data(), handler.errorString().toLocal8Bit().data(), handler.lineNumber());
    }
	
    return doc;
}

QSvgTinyDocument * QSvgTinyDocument::load(const QByteArray &contents)
{
#ifndef QT_NO_COMPRESS
    // Check for gzip magic number and inflate if appropriate
    if (contents.startsWith("\x1f\x8b")) {
        QBuffer buffer(const_cast<QByteArray *>(&contents));
        return load(qt_inflateGZipDataFrom(&buffer));
    }
#endif

    QSvgHandler handler(contents);

    QSvgTinyDocument *doc = 0;
    if (handler.ok()) {
        doc = handler.document();
        doc->m_animationDuration = handler.animationDuration();
    }
    return doc;
}

QSvgTinyDocument * QSvgTinyDocument::load(QXmlStreamReader *contents)
{
    QSvgHandler handler(contents);

    QSvgTinyDocument *doc = 0;
    if (handler.ok()) {
        doc = handler.document();
        doc->m_animationDuration = handler.animationDuration();
    }
    return doc;
}


/////转图并可执行一段脚本script//////
int QSvgTinyDocument::toSmartsys(const QString &file, const QString &outfile, const QMap<QString, QObject*>& appQSobject, const QString &script)
{
    int ret=-1;
    UnqFunc()->TmRestart();
    UnqFunc()->TmDebug("----SvgTinyDocument::load--start");
    QSvgTinyDocument *doc = QSvgTinyDocument::load(file);
    UnqFunc()->TmDebug("----SvgTinyDocument::load--over");

    if (doc){
        CGraphScene scene(0);
        CScriptEngine* pScriptEngine=scene.GetScriptEngine();
        QMap<QString, QObject*>::const_iterator i ;
        for(i = appQSobject.constBegin();i!=appQSobject.constEnd();++i)
        {
            pScriptEngine->AddObject(i.value(),i.key());
        }
        pScriptEngine->AddObject(&scene,"Me");
		UnqFunc()->GetGraphNameByGraphPathName(outfile, doc->m_curFileName);
        ret=doc->ToGraphics(&scene);

        scene.FileSave(outfile);
    }
    UnqFunc()->TmDebug("----SvgTinyDocument::ToGraphics--over");
    return ret;
}

int QSvgTinyDocument::toSmartsysBat(const QString &dir )
{

	QDir qdir(dir);
	if (!qdir.exists())
	{
		log_error("	dir:%s not exist ", dir.toLocal8Bit().data());
		return -1;
	}
	int ret = 0;
	if (m_dir == ""){
		m_dir = dir;
		if (!InitDBPtr())
			return 0;
		//InitErrorLog();
    }
	
	qdir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
	QFileInfoList list = qdir.entryInfoList();

	for (int i = 0; i < list.size(); ++i) {
		QFileInfo fileInfo = list.at(i);
		if (fileInfo.isFile() && fileInfo.fileName().right(4) == PICSUFFIX)
		{
			QString inFile = fileInfo.filePath();
			QDir globalDir(m_dir);
			QString outFile = globalDir.relativeFilePath(fileInfo.filePath());
			UnqFunc()->GetGraphPathNameByGraphName(outFile, outFile);
            ret += toSmartsys(inFile, outFile );
		}
		else if (fileInfo.isDir())
		{
			QString childDir = fileInfo.absoluteFilePath();
			ret += toSmartsysBat(childDir);
		}
	}
	m_logFile->close();
	return ret;
}

void QSvgTinyDocument::draw(QPainter *p, const QRectF &bounds)
{
    if (m_time.isNull()) {
        m_time.start();
    }

    if (displayMode() == QSvgNode::NoneMode)
        return;

    p->save();
    //sets default style on the painter
    //### not the most optimal way
    mapSourceToTarget(p, bounds);
    QPen pen(Qt::NoBrush, 1, Qt::SolidLine, Qt::FlatCap, Qt::SvgMiterJoin);
    pen.setMiterLimit(4);
    p->setPen(pen);
    p->setBrush(Qt::black);
    p->setRenderHint(QPainter::Antialiasing);
    p->setRenderHint(QPainter::SmoothPixmapTransform);
    QList<QSvgNode*>::iterator itr = m_renderers.begin();
    applyStyle(p, m_states);
    while (itr != m_renderers.end()) {
        QSvgNode *node = *itr;
        if ((node->isVisible()) && (node->displayMode() != QSvgNode::NoneMode))
            node->draw(p, m_states);
        ++itr;
    }
    revertStyle(p, m_states);
    p->restore();
}


void QSvgTinyDocument::draw(QPainter *p, const QString &id,
                            const QRectF &bounds)
{
    QSvgNode *node = scopeNode(id);

    if (!node) {
        qDebug("Couldn't find node %s. Skipping rendering.", qPrintable(id));
        return;
    }
    if (m_time.isNull()) {
        m_time.start();
    }

    if (node->displayMode() == QSvgNode::NoneMode)
        return;

    p->save();

    const QRectF elementBounds = node->transformedBounds();

    mapSourceToTarget(p, bounds, elementBounds);
    QTransform originalTransform = p->worldTransform();

    //XXX set default style on the painter
    QPen pen(Qt::NoBrush, 1, Qt::SolidLine, Qt::FlatCap, Qt::SvgMiterJoin);
    pen.setMiterLimit(4);
    p->setPen(pen);
    p->setBrush(Qt::black);
    p->setRenderHint(QPainter::Antialiasing);
    p->setRenderHint(QPainter::SmoothPixmapTransform);

    QStack<QSvgNode*> parentApplyStack;
    QSvgNode *parent = node->parent();
    while (parent) {
        parentApplyStack.push(parent);
        parent = parent->parent();
    }

    for (int i = parentApplyStack.size() - 1; i >= 0; --i)
        parentApplyStack[i]->applyStyle(p, m_states);

    // Reset the world transform so that our parents don't affect
    // the position
    QTransform currentTransform = p->worldTransform();
    p->setWorldTransform(originalTransform);

    node->draw(p, m_states);

    p->setWorldTransform(currentTransform);

    for (int i = 0; i < parentApplyStack.size(); ++i)
        parentApplyStack[i]->revertStyle(p, m_states);

    //p->fillRect(bounds.adjusted(-5, -5, 5, 5), QColor(0, 0, 255, 100));

    p->restore();
}


QSvgNode::Type QSvgTinyDocument::type() const
{
    return DOC;
}

void QSvgTinyDocument::setWidth(int len, bool percent)
{
    m_size.setWidth(len);
    m_widthPercent = percent;
}

void QSvgTinyDocument::setHeight(int len, bool percent)
{
    m_size.setHeight(len);
    m_heightPercent = percent;
}

void QSvgTinyDocument::setViewBox(const QRectF &rect)
{
    m_viewBox = rect;
}

void QSvgTinyDocument::addSvgFont(QSvgFont *font)
{
    m_fonts.insert(font->familyName(), font);
}

QSvgFont * QSvgTinyDocument::svgFont(const QString &family) const
{
    return m_fonts[family];
}

void QSvgTinyDocument::addNamedNode(const QString &id, QSvgNode *node)
{
    m_namedNodes.insert(id, node);
}

QSvgNode *QSvgTinyDocument::namedNode(const QString &id) const
{
    return m_namedNodes.value(id);
}

void QSvgTinyDocument::addNamedStyle(const QString &id, QSvgFillStyleProperty *style)
{
    m_namedStyles.insert(id, style);
}

QSvgFillStyleProperty *QSvgTinyDocument::namedStyle(const QString &id) const
{
    return m_namedStyles.value(id);
}

void QSvgTinyDocument::restartAnimation()
{
    m_time.restart();
}

bool QSvgTinyDocument::animated() const
{
    return m_animated;
}

void QSvgTinyDocument::setAnimated(bool a)
{
    m_animated = a;
}

void QSvgTinyDocument::draw(QPainter *p)
{
    draw(p, QRectF());
}

void QSvgTinyDocument::draw(QPainter *p, QSvgExtraStates &)
{
    draw(p);
}

void QSvgTinyDocument::mapSourceToTarget(QPainter *p, const QRectF &targetRect, const QRectF &sourceRect)
{
    QRectF target = targetRect;
    if (target.isNull()) {
        QPaintDevice *dev = p->device();
        QRectF deviceRect(0, 0, dev->width(), dev->height());
        if (deviceRect.isNull()) {
            if (sourceRect.isNull())
                target = QRectF(QPointF(0, 0), size());
            else
                target = QRectF(QPointF(0, 0), sourceRect.size());
        } else {
            target = deviceRect;
        }
    }

    QRectF source = sourceRect;
    if (source.isNull())
        source = viewBox();

    if (source != target && !source.isNull()) {
        QTransform transform;
        transform.scale(target.width() / source.width(),
                  target.height() / source.height());
        QRectF c2 = transform.mapRect(source);
        p->translate(target.x() - c2.x(),
                     target.y() - c2.y());
        p->scale(target.width() / source.width(),
                 target.height() / source.height());
    }
}

QRectF QSvgTinyDocument::boundsOnElement(const QString &id) const
{
    const QSvgNode *node = scopeNode(id);
    if (!node)
        node = this;
    return node->transformedBounds();
}

bool QSvgTinyDocument::elementExists(const QString &id) const
{
    QSvgNode *node = scopeNode(id);

    return (node!=0);
}

QMatrix QSvgTinyDocument::matrixForElement(const QString &id) const
{
    QSvgNode *node = scopeNode(id);

    if (!node) {
        qDebug("Couldn't find node %s. Skipping rendering.", qPrintable(id));
        return QMatrix();
    }

    QTransform t;

    node = node->parent();
    while (node) {
        if (node->m_style.transform)
            t *= node->m_style.transform->qtransform();
        node = node->parent();
    }
    
    return t.toAffine();
}

int QSvgTinyDocument::currentFrame() const
{
    double runningPercentage = qMin(m_time.elapsed()/double(m_animationDuration), 1.);

    int totalFrames = m_fps * m_animationDuration;

    return int(runningPercentage * totalFrames);
}

void QSvgTinyDocument::setCurrentFrame(int frame)
{
    int totalFrames = m_fps * m_animationDuration;
    double framePercentage = frame/double(totalFrames);
    double timeForFrame = m_animationDuration * framePercentage; //in S
    timeForFrame *= 1000; //in ms
    int timeToAdd = int(timeForFrame - m_time.elapsed());
    m_time = m_time.addMSecs(timeToAdd);
}

void QSvgTinyDocument::setFramesPerSecond(int num)
{
    m_fps = num;
}

int QSvgTinyDocument::ToGraphics(QGraphicsScene* pscene)
{ 
	CGraphScene* cgScene = (CGraphScene*)pscene;
	if (cgScene == NULL)
		return -1;
	m_pScene = cgScene;
	cgScene->SetLinkMode(Hmi::Normal);
	cgScene->SetFileType(0); 
	cgScene->SetPlaneNums(1);
	cgScene->SetFitViewMode(1);
    cgScene->SetEnableScale(true);
	cgScene->SetTopoFlag(1);
	bool initLayer = true;
	qreal x = 0;
	qreal y = 0;
	qreal width = this->width();
	qreal height = this->height();
	QRect layRect(x, y, width, height);

	m_curLayer = "";

	//insert log to table model_error_object
	QString sqlStr = QString("select id from model_error_object where description = '%1'").arg(m_curFileName);
	TwoDimArray result;
	int sret = m_pDBCli->SelectBySQL(sqlStr.toLocal8Bit().data(), result);
	if (sret < 0 || result.Row() == 0){
		//insert new
		QString sql = QString("insert into model_error_object (id,description) values (get_maxid_by_tablename('model_error_object','id',1),'%1');").arg(m_curFileName);
		int sret = m_pSyncWriteCli->ExecSQL(sql.toLocal8Bit().data(), "import svg");
		if (sret < 0)
		{
			log_error("--QModifySql--Execute SQL :%s failed.Er:%d,ErMsg:%s\n", sql.toLocal8Bit().data(), sret, m_pSyncWriteCli->last_er_msg.c_str());
		}
		else{
			TwoDimArray result;
			int ssret = m_pDBCli->SelectBySQL(sqlStr.toLocal8Bit().data(), result);
			if (ssret < 0 || result.Row() == 0){
				m_curFileName = -1;
			}
			else
				m_curFileName = QString::fromStdString(result[0][0].ToStr());
		}
	}
	else{
		m_curFileName = QString::fromStdString(result[0][0].ToStr());
		//delete old 
		QString delStr = QString("delete from model_error_object where parent_id = %1").arg(m_curFileName);
		int ssret = m_pSyncWriteCli->ExecSQL(delStr.toLocal8Bit().data(), "import svg");
		if (ssret < 0)
		{
			log_error("--QModifySql--Execute SQL :%s failed.Er:%d,ErMsg:%s\n", delStr.toLocal8Bit().data(), sret, m_pSyncWriteCli->last_er_msg.c_str());
		}
	}
	////log end


	QList<QSvgNode*> topNode = m_renderers;
	QList<QSvgNode*>::iterator itr = topNode.begin();//Top node��defs>?g id="*_Layer">
	while (itr != topNode.end()) {
		QSvgNode *node = *itr;
		if ((node->isVisible()) && (node->displayMode() != QSvgNode::NoneMode))
		{
			//scene->createItem, setProperty		
			int nodeType = node->type();
			switch (nodeType)
			{
			case Type::DEFS:
			{
							   QSvgDefs* defsNode = (QSvgDefs*)node;
							   if (defsNode == NULL)
								   return -1;
							   QList<QSvgNode*> childen = defsNode->renderers();//symbol same as g
							   QList<QSvgNode*>::iterator childItr = childen.begin();
							   while (childItr != childen.end()) {
								   QSvgNode *child = *childItr;
								   int childType = child->type();
								   switch (childType)
								   {
								   case Type::G://symbol
									   ParseSymbol(child);
									   break;
								   default:
									   break;
								   }
								   ++childItr;
							   }
							   break;
			}
			case Type::G:   //_Layer node
			{
								if (node->nodeTag()=="symbol")//just for nr svg; TODO
								{
									ParseSymbol(node);
								}
								else{
								QString nodeId = node->nodeId();
								QSvgG* gNode = (QSvgG*)node;
								if (gNode == NULL)
									return -1;
								int oldNum = cgScene->GetPlaneNums();
								if (nodeId.endsWith("_Layer"))//new plane
								{
									m_curLayer = nodeId;
									if (initLayer){
										cgScene->SetPlaneNames(nodeId);
										cgScene->SetShowPlanes("1");
										cgScene->SetLayoutRect(layRect);
										initLayer = false;
									}
									else{
										oldNum++;
										cgScene->SetPlaneNums(oldNum);
										cgScene->SetPlaneNames(cgScene->GetPlaneNames() + "," + nodeId);
										QString showCur = ",1";
										if (m_hideLayer.contains(m_curLayer))
											showCur = ",0";
										cgScene->SetShowPlanes(cgScene->GetShowPlanesStr() + showCur);
									}
									
								}

								QList<QSvgNode*> childen = gNode->renderers();//childen: g\rect\....
								QList<QSvgNode*>::iterator childItr = childen.begin();
								if (nodeId == "whole_graph")//do nothing
								{
									itr = childItr;
									topNode = childen;
									continue;
								}
								while (childItr != childen.end()) {
									QSvgNode *child = *childItr;
									if ((child->isVisible()) && (child->displayMode() != QSvgNode::NoneMode))
									{
										QGraphicsItem* newItem = ToItem(child);
										if (newItem)
										    g_dataPtr(newItem)->SetPlane(oldNum-1);

									}
									++childItr;
								}
								}
								break;
			}
			default:
			{
					   ToItem(node);
					   break;
			}
			}
		}
		++itr;
	}

	//svg viewbox
	QRectF rct = this->viewBox();
	if (rct.x() != 0 || rct.y() !=0)
	{
		foreach(QGraphicsItem* item , cgScene->Items(true, false))
		{
			item->moveBy(-rct.x(), -rct.y());
		}
	}

    //add to script AddObject
    foreach(QGraphicsItem* item , cgScene->Items(true, false))
    {
        CBaseData* pdata=g_dataPtr(item);
        QString name=pdata->GetName();
        cgScene->GetScriptEngine()->AddObject(pdata,name);
    }
   // cgScene->GetScriptEngine()->LoadFile(QString("hmiConvert.js"));

	//insert log to table model_error_object
	if (m_errorLogSqls.size() > 0)
	{
		int ret = m_pSyncWriteCli->ExecSQL(m_errorLogSqls.join("").toLocal8Bit().data(), "import svg");
		if (ret < 0)
		{
			log_error("--QModifySql--Execute SQL :%s failed.Er:%d,ErMsg:%s\n", m_errorLogSqls.join("").toLocal8Bit().data(), ret, m_pSyncWriteCli->last_er_msg.c_str());
			return -1;
		}
	}
	//extended Node demo
	/*for (int i = 0; i < m_extendedNodeArray.size();i++)
	{
		QJsonObject nodeObj = m_extendedNodeArray[i].toObject();
		QString NodeType = nodeObj["nodeType"].toString();
		if (NodeType == "metadata")
		{		
			QString parentNodeID = nodeObj["parentNodeID"].toString();
			if (parentNodeID.isEmpty())
				continue;
	
			bool beDev = false;
			QString rdfID;

			QJsonValue val = nodeObj["children"];
			if (val.type() == QJsonValue::Array)
			{
				QJsonArray value = val.toArray();
				for (int j = 0; j < value.size(); j++)
				{
					QJsonObject childObj= value[j].toObject();		
					if (childObj["nodeType"].toString() == "PSR_Ref")
					{
						beDev = true;
						rdfID = childObj["ObjectID"].toString();
						break;
					}
					if (!beDev && childObj["nodeType"].toString() == "Meas_Ref")
					{
						rdfID = childObj["ObjectID"].toString();
						break;
					}
				}		
			}
			if (rdfID.isEmpty())
			    continue;
			SetUserData(parentNodeID, rdfID);
		}
	}*/
	//extended node demo end
	return 0;
}
QGraphicsItem* QSvgTinyDocument::ParseSymbol(QSvgNode* node)
{
	QSvgG* gNode = (QSvgG*)node;
	if (gNode == NULL)
		return NULL;

    //add to ICONMng \save to file (gtoolbox.xml need added manually  )
	QString typeName = node->nodeId();
	int planeNo = 0;
	bool beTransFormer = false;
	if (typeName.startsWith("Transformer", Qt::CaseInsensitive))
		beTransFormer = true; // Transformer: every winding is a symbol, a transformer is a group

	if (!m_planeSeparateChar.isEmpty() && !beTransFormer)
	{
		if (typeName.contains(m_planeSeparateChar))//plane/state
		{
			QStringList sl = typeName.split(m_planeSeparateChar);
			planeNo = sl.last().toInt();
			if (m_cb_change_status &&(typeName.contains("break", Qt::CaseInsensitive) || typeName.contains("disconnector", Qt::CaseInsensitive)))
				planeNo = 1-planeNo;////////////////开断类图元的开合状态，是否需要转换，plane_0=开，plane_1=合//////////
			typeName = typeName.left(typeName.lastIndexOf(m_planeSeparateChar) + m_symbolIdL);
		}
		else//last char is plane num:begin from 0
		{
			planeNo = typeName.right(-m_symbolIdL).toInt();
			typeName = typeName.left(typeName.length() + m_symbolIdL);
		}
	}
	else if (m_planeSeparateChar.isEmpty() && !beTransFormer)
	{		
		QStringList sepChars;
		sepChars << "@" << "_" << "-";
		foreach (QString sep, sepChars)
		{
			if (typeName.contains(sep))
			{
				QStringList sl = typeName.split(sep);
				if (sl.last().length() == 1)
				{
					planeNo = sl.last().toInt();
					if (m_cb_change_status && (typeName.contains("break", Qt::CaseInsensitive) || typeName.contains("disconnector", Qt::CaseInsensitive)))
						planeNo = 1 - planeNo;////////////////开断类图元的开合状态，是否需要转换，plane_0=开，plane_1=合//////////
					typeName = typeName.left(typeName.lastIndexOf(sep) + m_symbolIdL);
					m_planeSeparateChar = sep;
					break;
				}
			}
			else//last char is plane num:begin from 0
			{
				planeNo =  typeName.right(-m_symbolIdL).toInt();
				typeName = typeName.left(typeName.length() + m_symbolIdL);
			}
		}
	}

	QString fileName = CheckIconFileName(typeName);
	typeName = ICONPREFIX + fileName;

	CIconItem* pIconItem = NULL;
	CIconItem* symbol = (CIconItem*)(UnqIconMng()->Icon(typeName));
	if (symbol == NULL)
		pIconItem = (CIconItem*)ItemFactory::CreateItem(typeName, 0, m_pScene);
	else
	{
		bool needParsed = ((CIconData*)g_dataPtr(symbol))->IsNullPlane(planeNo);
		if (needParsed)
			pIconItem = dynamic_cast<CIconItem*>(g_dataPtr(symbol)->Clone()); //to add plane 
		else
			return symbol;
		//int planeNum = ((CIconData*)g_dataPtr(symbol))->GetPlaneNums();
		//if (planeNum >= (planeNo + 1))
		//	return symbol;//no need to modify icon 判断当前图层有图元
		//else
		   // pIconItem = dynamic_cast<CIconItem*>(g_dataPtr(symbol)->Clone()); //to add plane 
	}
	bool hasNewItem = false;
	if (pIconItem)
	{
		QList<QSvgNode*> childen = gNode->renderers();
		QList<QSvgNode*>::iterator childItr = childen.begin();
		while (childItr != childen.end()) {
			QSvgNode *child = *childItr;
			if ((child->isVisible()) && (child->displayMode() != QSvgNode::NoneMode))
			{
				int childType = child->type();
				QGraphicsItem* item = NULL;
				if (childType == Type::G)
					item = ParseGNode(child);
				else
					item = ToItem(child);
				
				if (item)
				{
					hasNewItem = true;
					if (item->type() == Hmi::Icon){/////////////PMS2.0中，图元里的terminal是用use图元引用的方式，A5000里图元内嵌套图元，状态处理有问题/////////////////
						foreach(QGraphicsItem *citem, item->childItems())
						{
							CBaseData* cd_ptr = g_dataPtr(citem);
							if (cd_ptr){
								cd_ptr->SetPlane(planeNo);
								cd_ptr->SetState(planeNo);
								pIconItem->addToGroup(citem);
							}
						}
					}
					else{
						g_dataPtr(item)->SetPlane(planeNo);
						g_dataPtr(item)->SetState(planeNo);
						pIconItem->addToGroup(item);
					}
				}
			}
			++childItr;
		}
		if (!hasNewItem)
			return pIconItem;
		CIconData* iconData = (CIconData*)(g_dataPtr(pIconItem));
		if (iconData)
		{
			int oldNum = iconData->GetPlaneNums();
			int newNum = oldNum >= (planeNo + 1) ? oldNum : (planeNo + 1);
			iconData->SetPlaneNums(newNum);
			iconData->SetStateNums(newNum);
            iconData->SetTemplateName(typeName);
			iconData->SetIconType(210);
			//To viewbox:reserveAspectRatio of symbol 
			//<symbol id="Substation_PD_���� viewbox="0 0 64 64" preserveAspectRatio="xMidYMid meet" MetaW="48" MetaH="40" minL="8" minT="12">
			
			//minL\minT\MetaW\MetaH  to repair the problem that boundingbox is too big 
			QVariantMap extendedAttr = node->extendedAttributes();
			QVariantMap::const_iterator itr = extendedAttr.constBegin();
			while (itr != extendedAttr.constEnd()) {
				if (itr.value().canConvert(QMetaType::QString))
				{
					iconData->setProperty(itr.key().toLocal8Bit().data(), itr.value().toString());
				}
				++itr;
			}
			m_pScene->SetLayoutRect(QRect(0, 0, ICON_SIZE, ICON_SIZE));
		}
		
		UnqIconMng()->AddIcon(pIconItem, typeName);
		UnqFunc()->GetIconPathNameByIconCoreName(fileName, fileName);
		m_pScene->IconSaveToFile(pIconItem, fileName);
	}
	return pIconItem;
}

QGraphicsItem* QSvgTinyDocument::ParseGNode(QSvgNode* node)
{
	QGraphicsItem* groupItem = NULL;

	QSvgG* gNode = (QSvgG*)node;
	if (gNode == NULL)
		return NULL;
	//////设备类图元处理: childNodes含有use类的gNode, 只保留use//////////
	QList<QSvgNode*> childen = gNode->renderers();
	QList<QSvgNode*>::iterator childItr = childen.begin();
	bool hasUse = false;
	while (childItr != childen.end()) {
		QSvgNode *child = *childItr;
		if (child->type() == Type::USE){
			hasUse = true;
			break;
		}
		++childItr;
	}
	if (hasUse){
		childItr = childen.begin();
		while (childItr != childen.end()) {
			QSvgNode *child = *childItr;
			if (child->type() != Type::USE){
				gNode->RemoveChild(child);/////////gnode 删除子节点./////////////
			}
			++childItr;
		}
	}
	childen = gNode->renderers();
	///////////////////////
	if (childen.size() > 1)
	{
		groupItem = ItemFactory::CreateItem("g", 0, m_pScene);
	}
	
	childItr = childen.begin();	
	while (childItr != childen.end()) {
		QSvgNode *child = *childItr;
		if ((child->isVisible()) && (child->displayMode() != QSvgNode::NoneMode))
		{
			int childType = child->type();
			if (childType == Type::G)
			{
				QGraphicsItem* item = ParseGNode(child);
				if (item)
				{
					if (groupItem)
						((CGroupItem*)groupItem)->addToGroup(item);
					else
						groupItem = item;
				}
			}
			else
			{
				QGraphicsItem* item = ToItem(child);
				if (item)
				{
					if (groupItem)
						((CGroupItem*)groupItem)->addToGroup(item);
					else{
						groupItem = item;
					}
				}
			}
		}
		++childItr;
	}

	/////g上的属性处理, 连接线连接信息///////
	if (g_dataPtr(groupItem)){
		QVariantMap extendedAttr = node->extendedAttributes();
		QVariantMap::const_iterator itr = extendedAttr.constBegin();
		while (itr != extendedAttr.constEnd()) {
			if (itr.key() == "BeginDevName" || itr.key() == "EndDevName")
			{
				QString str = itr.value().toString();
				if (str.isEmpty() || str == "NULL"){
					itr++;
					continue;
				}
				/*QString pre = "";
				if (itr.key() == "BeginDevName")
					pre = "BeginDevType";
				else if (itr.key() == "EndDevName")
					pre = "EndDevType";

				if (!pre.isEmpty()){
					QString layer = extendedAttr.value(pre).toString().append("_Layer");
					layer = layer.replace(0, 1, layer.at(0).toUpper());
					QString pre = m_psr2rdfidMap.value(layer).toString();
					str = pre.append(str);*/

					QString linkStr = g_dataPtr(groupItem)->Property("link").toString();
					if (linkStr.isEmpty())
						linkStr.append(str);
					else
						linkStr.append("," + str);
					g_dataPtr(groupItem)->setProperty("link", linkStr);

				//}
			}
			else if (itr.key() == "gid")
			{
				QString str = itr.value().toString();
				if (str.isEmpty() || str == "NULL"){
					itr++;
					continue;
				}
				g_dataPtr(groupItem)->setProperty("gid", str);
			}
			itr++;
		}
	}

	return groupItem;
}
QGraphicsItem* QSvgTinyDocument::ToItem(QSvgNode* node)
{
	int nodeType = node->type();
	QGraphicsItem* pGItem = NULL;
	CBaseData* pdata = NULL;
	QString typeName;

	switch (nodeType)
	{
	case Type::G:
	{
		QGraphicsItem* gnode = ParseGNode(node);
		pGItem = gnode;
		pdata = g_dataPtr(pGItem);//need loadBasProperty  处理g设备图元 的颜色 位置 rdfid  图模关联  等//////
		typeName = "g";
		break;
	}
	case Type::SWITCH:
	{
						 // ??
						 break;
	}
	case Type::ARC:
	{
		QSvgArc* arcNode = (QSvgArc*)node;
		if (arcNode == NULL)
			return pGItem;
		typeName = "path";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CPathItem* pItem = (CPathItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setPath(arcNode->GetPath());
		}
		break;
	}
	case Type::CIRCLE:
	{
		QSvgCircle* circleNode = (QSvgCircle*)node;
		if (circleNode == NULL)
			return pGItem;
		typeName = "ellipse";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CEllipseItem* pItem = (CEllipseItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setRect(circleNode->GetBounds());
		}
		break;
	}
	case Type::ELLIPSE:
	{
		QSvgEllipse* ellipseNode = (QSvgEllipse*)node;
		if (ellipseNode == NULL)
			return pGItem;
		typeName = "ellipse";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CEllipseItem* pItem = (CEllipseItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setRect(ellipseNode->GetBounds());
		}
		break;
	}
	case Type::IMAGE:
	{
		QSvgImage* imageNode = (QSvgImage*)node;
		if (imageNode == NULL)
			return pGItem;
		typeName = "image";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CPixmapItem* pItem = (CPixmapItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setPixmap(QPixmap::fromImage(imageNode->GetImage()));
		}
		break;
	}
	case Type::LINE:
	{
		QSvgLine* lineNode = (QSvgLine*)node;
		if (lineNode == NULL)
			return pGItem;
		typeName = "line";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CLineItem* pItem = (CLineItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setLine(lineNode->GetLine());
		}
		break;
	}
	case Type::PATH:
	{
		QSvgPath* pathNode = (QSvgPath*)node;
		if (pathNode == NULL)
			return pGItem;
		typeName = "path";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CPathItem* pItem = (CPathItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setPath(*(pathNode->qpath()));

			int cnt = pathNode->qpath()->elementCount();
			for (int i = 0; i < cnt; i++)
				pItem->AppendInflexion(pathNode->qpath()->elementAt(i), false);
		}
		break;
	}
	case Type::POLYGON:
	{
		QSvgPolygon* polygonNode = (QSvgPolygon*)node;
		if (polygonNode == NULL)
			return pGItem;
		typeName = "polygon";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CPolygonItem* pItem = (CPolygonItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property 
			pItem->setPolygon(polygonNode->GetPolygon());

		}
		break;
	}
	case Type::POLYLINE:
	{
		QSvgPolyline* polylineNode = (QSvgPolyline*)node;
		if (polylineNode == NULL)
			return pGItem;

		if (m_curLayer == "ConnectLine_Layer" || m_curLayer == "ConnLine_Layer" || m_curLayer == "ACLineSegment_Layer" || m_curLayer == "ACLine_Layer" || m_curLayer == "PowerLine_Layer")//link
		{
			typeName = "link";
			pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
			if (pGItem)
			{
				CLinkLineItem* pItem = (CLinkLineItem*)pGItem;
				pdata = g_dataPtr(pItem);
				//property 
				pItem->setPolygon(polylineNode->GetPolygon());
			}
		}
		else if (m_curLayer == "BusbarSection_Layer" || m_curLayer == "BusSection_Layer" || m_curLayer == "Bus_Layer")//bus
		{
			typeName = "bus";
			pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
			if (pGItem)
			{
				CBusItem* pItem = (CBusItem*)pGItem;
				pdata = g_dataPtr(pItem);
				//property 
				QPolygonF gon = polylineNode->GetPolygon();
				pItem->setLine(QLineF(gon.first(),gon.last()));
			}
		}
		else
		{				  
			typeName = "polyline";
			pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
			if (pGItem)
			{
				CPolylineItem* pItem = (CPolylineItem*)pGItem;
				pdata = g_dataPtr(pItem);
				//property 
				pItem->setPolygon(polylineNode->GetPolygon());
			}
		}
		
		break;
	}
	case Type::RECT:
	{
		QSvgRect* rectNode = (QSvgRect*)node;
		if (rectNode == NULL)
			return pGItem;
		typeName = "rect";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CRectItem* pItem = (CRectItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property
			QRectF rf = rectNode->GetRect();
			pItem->setRect(rf);
			//pdata->SetProperty("postion", rf.topLeft());
			//pdata->SetProperty("width", rf.width());
			//pdata->SetProperty("height", rf.height());
			if (rectNode->parent() && rectNode->parent()->nodeId() == "Head_Layer")
			{
				QRect sceneRect = m_pScene->GetLayoutRect();
				if (sceneRect.width() < rf.width() || sceneRect.height() < rf.height())
				{
					sceneRect.setWidth(rf.width());
					sceneRect.setHeight(rf.height());
					m_pScene->SetLayoutRect(sceneRect);
				}
			}
		}
		break;
	}
	case Type::TEXT:
	{
		QSvgText* textNode = (QSvgText*)node;
		if (textNode == NULL)
			return pGItem;

		QVector<QSvgTspan*>  vecTspan = textNode->GetTspans();
		if (vecTspan.size() == 1)
		{
			if ((vecTspan[0]->isVisible()) && (vecTspan[0]->displayMode() != QSvgNode::NoneMode))
			{
				return ToItem(vecTspan[0]);

			}
		}
		else
		{
			CGroupItem* groupItem = (CGroupItem*)ItemFactory::CreateItem("g", 0, m_pScene);
			for (int i = 0; i < vecTspan.size(); i++)
			{
				if ((vecTspan[i]->isVisible()) && (vecTspan[i]->displayMode() != QSvgNode::NoneMode))
				{
					QGraphicsItem* tspanItem = ToItem(vecTspan[i]);
					if (tspanItem)
						groupItem->addToGroup(tspanItem);
				}

			}
			pGItem = groupItem;
			pdata = g_dataPtr(pGItem);
			//return groupItem;
		}
		
		break;
	}
	case Type::TEXTAREA:
	{
		QSvgText* textNode = (QSvgText*)node;
		if (textNode == NULL)
			return pGItem;
		return ToItem(textNode);
						   
		break;
	}
	case Type::TSPAN:
	{
		QSvgTspan* tspanNode = (QSvgTspan*)node;
		if (tspanNode == NULL || tspanNode->text().isEmpty())
			return pGItem;
		typeName = "text";
		pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
		if (pGItem)
		{
			CTextItem* pItem = (CTextItem*)pGItem;
			pdata = g_dataPtr(pItem);
			//property

			QString strText="";

			/*if (tspanNode == NULL)
				strText.append("\n");
			else*/
			    strText.append(tspanNode->text());
                        ((CTextData*)pdata)->SetTextDirect(0);
                        ((CTextData*)pdata)->SetOrgText(strText);
			QVariantMap exAtr = tspanNode->extendedAttributes();
			QVariantMap::iterator itr = exAtr.find("x");
			QPointF coord;
			if (itr != exAtr.end())
			{
				coord = QPointF(itr.value().toReal(), exAtr["y"].toReal());
			}
			else
			{
				QSvgText* parentNode = (QSvgText*)(tspanNode->parent());
				if (parentNode)
				{
					coord = parentNode->GetCoord();
				}
				QVariantMap exAtr = parentNode->extendedAttributes();
				QString writingMode = exAtr["writing-mode"].toString();
				if (writingMode == "tb")///////////垂直显示///////////////////
				{
					((CTextData*)pdata)->SetTextDirect(1);
				}
			}
			QSvgFontStyle* fontStyle = (QSvgFontStyle*)(node->styleProperty(QSvgStyleProperty::FONT));
			if (fontStyle)
			{
				Qt::Alignment anchor = fontStyle->GetAnchor();//alignment
				if (anchor==Qt::AlignRight)
					coord = coord - QPointF(fontStyle->qfont().pointSizeF()*strText.size(), 0);
				else if (anchor == Qt::AlignHCenter)
					coord = coord - QPointF(fontStyle->qfont().pointSizeF()*strText.size()*0.5, 0);


				pItem->setPos(coord - QPointF(0, fontStyle->qfont().pointSizeF()*1.25)); //coord in svg is the bottomleft position
			}
			
			pGItem = pItem;
		}
		break;
	}
	case Type::USE:
	{
		QSvgUse* iconNode = (QSvgUse*)node;
		if (iconNode == NULL)
			return pGItem;

		QSvgNode* linkNode = iconNode->GetLinkNode();
		QPointF startPoint = iconNode->GetStartPoint();
		QString typeName;
		if (linkNode)
		{
			typeName = linkNode->nodeId();
		}
		else
		{
			QVariantMap exAtr = iconNode->extendedAttributes();
			QVariantMap::iterator itr = exAtr.find("xlink:href");
			if (itr != exAtr.end())
			{
				QString linkID = itr.value().toString();
				int idx = linkID.lastIndexOf("#");
				typeName = linkID.mid(idx+1);
			}
		}
			bool beTransFormer = false;
			if (typeName.startsWith("Transformer", Qt::CaseInsensitive))
				beTransFormer = true;// Transformer 
			if (!m_planeSeparateChar.isEmpty() && !beTransFormer )//plane/state
			{
				if (typeName.contains(m_planeSeparateChar))
				{
					QStringList sl = typeName.split(m_planeSeparateChar);
					typeName = typeName.left(typeName.lastIndexOf(m_planeSeparateChar) + m_symbolIdL);
				}
			    else//last char is plane num:begin from 0
				{
					typeName = typeName.left(typeName.length() + m_symbolIdL);
				}
			}
			QString fileName = CheckIconFileName(typeName);
			typeName = ICONPREFIX + fileName;

			CIconItem* citem = (CIconItem*)UnqIconMng()->DupIcon(typeName);
			if (citem)
            {
                pdata = g_dataPtr(citem);
               ((CIconData*)pdata)->SetTemplateName(typeName);
				((CIconData*)pdata)->SetIfRef(true);
				citem->setPos(startPoint);				
				pGItem = citem;
			}
		
		/*else
		{
			// special for nr svg, TODO: 
			QVariantMap exAtr = iconNode->extendedAttributes();
			QVariantMap::iterator itr = exAtr.find("xlink:href");
			if (itr != exAtr.end())
			{
				QString linkID = itr.value().toString();
				int idx = linkID.lastIndexOf("#");
				int iconPlaneNo = linkID.mid(idx).toInt();
				QString iconSvgFile = linkID.left(idx).replace(".svg", "").replace("symbol/","");
				if (!iconSvgFile.isEmpty())
				{
					QString fileName = CheckIconFileName(iconSvgFile);
					typeName = ICONPREFIX + fileName;
					CIconItem* citem = (CIconItem*)UnqIconMng()->DupIcon(typeName);
					if (citem)
					{
                        pdata = g_dataPtr(citem);                      
						pGItem = citem;
					}
					else
					{
						pGItem = ItemFactory::CreateItem(typeName, 0, m_pScene);
						if (pGItem)
						{
							CIconItem* citem = (CIconItem*)pGItem;
							pdata = g_dataPtr(citem);
						}
					}
					((CIconData*)pdata)->SetTemplateName(typeName);
					((CIconData*)pdata)->SetIfRef(true);
					pGItem->setPos(startPoint);
				}
			}
		}*/

		break;
	}
	case Type::VIDEO:
	{
						// ??
						break;
	}
	default:
	{
			   break;
	}
	}
	if (pGItem)
	{	
		if (typeName == "g")
		{
			QVariantMap::iterator itr = m_attr2child.find(m_curLayer + "/" + typeName);////////////父图元的属性，要附加到子图元上处理，如text关联量测点，需要把父图元g上的PSR_Ref、prefix等属性设置到子图元text上，父图元从scene上删除//////////
			if (itr != m_attr2child.end()){
				QString childType = itr.value().toString();
				QList<QGraphicsItem* > childs = pGItem->childItems();
				QGraphicsItem* item;
				if (childs.size() == 0 && pdata->TypeName() == childType)////parseGNode() if (childen.size() > 1) createItem("g")
				{
					item = pGItem;
					LoadProperty2Child(pGItem, node, item);
				}
				else
				{
					foreach(item, childs)
					{
						CBaseData* data = g_dataPtr(item);
						if (data && data->TypeName() == childType)
							break;
					}
					if (item)
					{
						LoadProperty2Child(pGItem, node, item);
						((QGraphicsItemGroup*)pGItem)->removeFromGroup(item);
						delete pGItem;
					}
				}
				m_pScene->addItem(item);
				return item;
			}
		}

		QVariantMap::iterator itr = m_node2item.find(m_curLayer + "/" + typeName);////////////改变图元类型，如关联measurement的polygon改为text//////////
		if (itr != m_node2item.end())
		{
			typeName = itr.value().toString();
			if (typeName.isEmpty() || typeName=="null")//////////////不绘制的图元/////[node-item]里的value设置空或者null///////////////
				return NULL;
			QGraphicsItem* item = ItemFactory::CreateItem(typeName, 0, m_pScene);
			if (item)
			{
				QPointF pt = pGItem->boundingRect().topRight() + QPointF(0, pGItem->boundingRect().height() / 4);
				item->setPos(pt);
				CBaseData* tdata = g_dataPtr(item);
				tdata->SetFont(QFont("Arial", pGItem->boundingRect().height()/2, QFont::Normal));
				tdata->SetFillColor(Qt::white);

				pGItem = item;
				pdata = tdata;
				pdata->setProperty("changed",true);
			}
		}
			

		pGItem->setZValue(0);
		pGItem->setFlag(QGraphicsItem::ItemIsMovable, true);
		pGItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
		m_pScene->addItem(pGItem);
		if (pdata)
		{
			LoadBaseProperty(pGItem, node);
			QString name = pdata->GetName();
			if (!name.isEmpty() && pGItem->parentItem() == NULL)
			{
				if (typeName.startsWith(ICONPREFIX))
					pGItem->setZValue(99);

				if (typeName.startsWith(UIPREFIX))
				{
					CWidgetItem *pwidget = dynamic_cast<CWidgetItem *>(pGItem);
					m_pScene->GetScriptEngine()->AddObject(pwidget->Widget(), name);
				}
				else if (typeName == ("qtChart"))
				{
					m_pScene->GetScriptEngine()->AddObject((CGChartItem*)pGItem, name);
				}
				else
				{
					m_pScene->GetScriptEngine()->AddObject(pdata, name);
				}
			}
	    }
	}
	return pGItem;
}

void QSvgTinyDocument::LoadBaseProperty(QGraphicsItem* pitem, QSvgNode* node)
{
	CBaseData* pdata = g_dataPtr(pitem);
	if (pitem && pdata && node)
	{
		//basedata property
		if (!pdata->property("changed").toBool()){////////////未改变图元类型，如关联measurement的polygon改为text//////////
			QSvgOpacityStyle* opacityStyle = (QSvgOpacityStyle*)(node->styleProperty(QSvgStyleProperty::OPACITY));
			if (opacityStyle)
				pitem->setOpacity(opacityStyle->GetOpacity());
			QSvgTransformStyle* transformStyle = (QSvgTransformStyle*)(node->styleProperty(QSvgStyleProperty::TRANSFORM));
			if (transformStyle)
			{
				QTransform svgTrans = transformStyle->qtransform();
				if (node->type() == QSvgNode::USE) {
					QPointF p = ((QSvgUse*)node)->GetStartPoint();
					svgTrans.translate(p.x(), p.y());
				}
				else{
					QPointF f = pitem->pos();
					svgTrans.translate(f.x(), f.y());
				}

				pitem->setTransformOriginPoint(pitem->boundingRect().topLeft());
				pitem->setTransform(svgTrans, true);
				if (node->type() == QSvgNode::USE) {
					QPointF p = ((QSvgUse*)node)->GetStartPoint();
					pitem->moveBy(-p.x(), -p.y());
				}
				else{
					QPointF f = pitem->pos();
					pitem->moveBy(-f.x(), -f.y());
				}
			}

		//	if (node->type() != QSvgNode::USE)////////////图元改为记录实例的颜色，不用图元定义的颜色/////////ems图元定义都是黑色，实例里用class属性定义颜色////////////////////////////
			{
				QSvgFillStyle* fillStyle = (QSvgFillStyle*)(node->styleProperty(QSvgStyleProperty::FILL));
				if (fillStyle)
				{
					if (pitem->type() == Hmi::GraphicsText)
						pdata->SetLineColor(fillStyle->qbrush().color());
					else
						pdata->SetBrush(fillStyle->qbrush());
				}

				QSvgStrokeStyle* strokeStyle = (QSvgStrokeStyle*)(node->styleProperty(QSvgStyleProperty::STROKE));
				if (strokeStyle)
				{
					pdata->SetLineColor(strokeStyle->stroke().brush().color());
					Qt::PenStyle penstyle = strokeStyle->stroke().style();
					pdata->SetLineStyle(penstyle);
					if (penstyle == Qt::CustomDashLine)
					{
						QPen pen = pdata->Pen();
						pen.setDashPattern(strokeStyle->stroke().dashPattern());
						pdata->SetPen(pen);
					}
					if (pitem->type() == Hmi::GraphicsText)
						pdata->SetLineWidth(-1);
					else{
						pdata->SetLineWidth(strokeStyle->width());//width==0 pen.setStyle(Qt::NoPen);
					}

					if (m_curLayer == "Substation_Layer")/////////////////////湘潭 dms  环网柜的线宽0.2 不明显///////////////////////
						pdata->SetLineWidth(1);
				}

				QSvgFontStyle* fontStyle = (QSvgFontStyle*)(node->styleProperty(QSvgStyleProperty::FONT));
				if (fontStyle)
				{
					pdata->SetFont(fontStyle->qfont());
				}
			}
			QSvgAnimateTransform* animateStyle = (QSvgAnimateTransform*)(node->styleProperty(QSvgStyleProperty::ANIMATE_TRANSFORM));
			if (animateStyle)
			{
				//??
			}
		}

		//name and rdfid
		QSvgNode* itemNode = node;
		QString itemName = node->nodeId();
		if (itemName.isEmpty())
			return;             
		/*while (itemName.isEmpty())
		{
			if (itemNode->parent())
			{
				itemNode = itemNode->parent();
				itemName = itemNode->nodeId();
			}
			else
			{
				itemNode = node;
				break;
			}
		}*/
		pdata->SetName(itemName);

		//extended attribute demo: to setUserData

		QVariantMap extendedAttr = itemNode->extendedAttributes();

        QVariantMap::const_iterator itr = extendedAttr.constBegin();
        QString rdfID="";
        bool beok = false;
		if (!m_layer2columnMap.contains(m_curLayer))
			beok = true;

        while (itr != extendedAttr.constEnd()) {

			QString str = itr.value().toString();
			if (itr.value().canConvert(QMetaType::QStringList))
				str = itr.value().toStringList().join(",");
			pdata->setProperty(itr.key().toLocal8Bit().data(), str);	

			if (!beok && itr.key() == "PSR_Ref"){
				 if (m_curLayer == "Measurement_Layer")//measurement in gis: gisXml no measurement, so use GlobeID=MRID of dev to search, ObjectName is measurement type
				 {
					 QString mrid = extendedAttr.value("GlobeID").toString();
					 QString mType = extendedAttr.value("ObjectName").toString();
					 SetGISMeasUserData(pdata, mrid, mType);
				 }
				 else
				 {	
					 rdfID = itr.value().toString();
					 if (!rdfID.isEmpty()){
						 //start with 306\307, need modify rdfid to search in dig\ana
						 /*if (rdfID.startsWith("306"))
						 {
							 rdfID = "0" + rdfID + "0010";
							 SetUserData(pdata, rdfID, "Meas_Ref");
						 }
						 else if (rdfID.startsWith("307"))
						 {

							 rdfID = "0" + rdfID.replace(":M", "") + "0010" + ":M";
							 SetUserData(pdata, rdfID, "Meas_Ref");
						 }
						 else*/
							 SetUserData(pdata, rdfID, "PSR_Ref");
					 }
				 }
				 beok = true;
             }
    
             ++itr;
         }

		if (!beok)
		{
			itr = extendedAttr.find("ObjectName");//itr = extendedAttr.find("Meas_Ref");
			if (itr != extendedAttr.end())
			    rdfID = itr.value().toString();
			if (!rdfID.isEmpty())			
                SetUserData(pdata, rdfID, "Meas_Ref");
		}
	}
}

void QSvgTinyDocument::LoadProperty2Child(QGraphicsItem* pGItem, QSvgNode* node, QGraphicsItem* item)
{
	CBaseData* pgdata = g_dataPtr(pGItem);
	CBaseData* pdata = g_dataPtr(item);
	if (pgdata && pdata && node)////////////////////////如果pGItem 有PSR_Ref属性，则把父图元pGItem的模型关联信息 关联到当前图元item上///////////////
	{
		//name and rdfid
		QString itemName = pdata->GetName();
		if (itemName.isEmpty() )
			pdata->SetName( node->nodeId() );

		//extended attribute demo: to setUserData

		QVariantMap extendedAttr = node->extendedAttributes();

		QVariantMap::const_iterator itr = extendedAttr.constBegin();
		QString rdfID = "";
		bool beok = false;
		if (!m_layer2columnMap.contains(m_curLayer))
			beok = true;

		while (itr != extendedAttr.constEnd()) {

			QString str = itr.value().toString();
			if (itr.value().canConvert(QMetaType::QStringList))
				str = itr.value().toStringList().join(",");
			if (itr.key() == "prefix")
				pdata->SetProperty("prefix", str);
			else if (itr.key() == "appendix")
				pdata->SetProperty("suffix", str);
			else
				pdata->setProperty(itr.key().toLocal8Bit().data(), str);

			if (!beok && itr.key() == "PSR_Ref"){
				if (m_curLayer == "Measurement_Layer")//measurement in dms: dms model Xml no measurement, so use GlobeID=MRID of dev to search, ObjectName is measurement type
				{
					QString mrid = extendedAttr.value("GlobeID").toString();
					QString mType = extendedAttr.value("ObjectName").toString();
					SetGISMeasUserData(pdata, mrid, mType);
				}
				else
				{
					rdfID = itr.value().toString();
					if (!rdfID.isEmpty()){
						//start with 306\307, need modify rdfid to search in dig\ana
						if (rdfID.startsWith("306"))
						{
							rdfID = "0" + rdfID + "0010";
							SetUserData(pdata, rdfID, "Meas_Ref");
						}
						else if (rdfID.startsWith("307"))
						{

							rdfID = "0" + rdfID.replace(":M", "") + "0010" + ":M";
							SetUserData(pdata, rdfID, "Meas_Ref");
						}
						else
							SetUserData(pdata, rdfID, "PSR_Ref");
					}
				}
				beok = true;
			}

			++itr;
		}

		if (!beok)
		{
			itr = extendedAttr.find("ObjectName");////湘潭ems不用Meas_Ref，meas_ref比点表里rdfid多了前缀， 用ObjectName中冒号前部分作为rdfid匹配查找点ID/////////
			if (itr != extendedAttr.end())
				rdfID = itr.value().toString();
			if (!rdfID.isEmpty())
				SetUserData(pdata, rdfID, "Meas_Ref");
		}
	}
}

bool QSvgTinyDocument::SetUserData(CBaseData* itemData, QString rdfID, QString source)
{
//	QGraphicsItem* item = m_pScene->GetElementById(itemID);
//	if (item == NULL)
//		return false;
//	CBaseData* itemData = g_dataPtr(item);
	if (itemData == NULL)
		return false;

	QString measName;
	QString colorCfg;
	QString tableName;
	QString id ;
	if (source == "PSR_Ref")
	{
		//dev-rdfid -to-id
		if (rdfID.contains(":"))
		{
			QStringList lst = rdfID.split(":");
			rdfID = lst.first();
			if (rdfID.contains("/"))
				rdfID = rdfID.split("=").last();
			measName = lst.last();
			QMap<QString, QVariant>::iterator itr = m_measureNameMap.find(measName);
			if (itr != m_measureNameMap.end())
				measName = itr.value().toString();

			measName += "_value";
		}
		else
		{
			/*QMap<QString, QVariant>::iterator itr = m_psr2rdfidMap.find(m_curLayer);
			if (itr != m_psr2rdfidMap.end()){
				QString pre = itr.value().toString();
				rdfID = pre.append(rdfID);
			}*////////改为不加前缀用模糊查询从商用库查找，svgimp.ini配置[attr-rdfid] 下useDB=DB; 因前缀不确定，如同一个switch_layer的前缀可能是DK-/GDK/BK/////////////

			measName = m_layer2columnMap.value(m_curLayer).toString();
		}
		if (measName=="pos_value")
			colorCfg = "di_color";
		else
			colorCfg = "qcolor";

		QList<QString> values = m_layer2tableMap.values(m_curLayer);
		if (values.size() == 0)
			values.append("obj_dev");
		for (int ti = 0; ti < values.size(); ti++)
		{
			QString psrTable = values[ti];
			QString cols = (psrTable == "obj_dev") ? "id,filter" : "id";
			TwoDimArray result;
			if (m_useDB)
			{
				QString sqlStr = QString("select %1 from %2 where rdf_id like '%3'").arg(cols).arg(psrTable).arg("%" + rdfID);/////模糊查询，可加前缀///////
				
				int ret = m_pDBCli->SelectBySQL(sqlStr.toLocal8Bit().data(), result);
				if (ret < 0 || result.Row() == 0){
					QString log = QObject::tr("select dev id by rdfid error . rdfid:%1 ,table:%2, layer:%3").arg(rdfID).arg(psrTable).arg(m_curLayer);
					log_error(log.toLocal8Bit().data());
					//*out << log+"\n";
					QString eType = QObject::tr("noDevError");
					m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
					continue;
				}
			}
			else
			{
				QString whereStr = QString("rdf_id = %1").arg(rdfID);
				int ret = m_pRTDBCli->Select(psrTable.toLocal8Bit().data(), cols.toLocal8Bit().data(), whereStr.toLocal8Bit().data(), result, "dev rdfid to id");
				if (ret < 0 || result.Row() == 0)
				{
					QString log = QObject::tr("select dev id by rdfid error . rdfid:%1 ,table:%2, layer:%3").arg(rdfID).arg(psrTable).arg(m_curLayer);
					log_error(log.toLocal8Bit().data());
					//*out << log + "\n";
					QString eType = QObject::tr("noDevError");
					m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
				    continue;
				}
			}
		
			id = QString::fromLocal8Bit(result[0][0].ToStr().c_str());
			if (result.Column()>1)
				tableName = QString::fromLocal8Bit(result[0][1].ToStr().c_str());

			if (tableName.isEmpty())
				tableName = psrTable;

			for (ti; ti > 0;ti--)/////////errorLog修复//////////////
				m_errorLogSqls.removeLast();
			break;
			
		}
		if (id.isEmpty())
		{
			////////模型拼接导致的模型RDFID合并，去商用库dms_ems_mapping表查询ems_rdfid，然后去obj_dev表查id///////////
			QString sqlStr = QString("select ems_rdfid,obj_type from dms_ems_mapping where dms_rdfid = '%1'").arg(rdfID);
			TwoDimArray result;
			int ret = m_pDBCli->SelectBySQL(sqlStr.toLocal8Bit().data(), result);
			if (ret < 0 || result.Row() == 0){
				QString log = QObject::tr("select dev id by rdfid error . rdfid:%1 ,table:%2, layer:%3").arg(rdfID).arg("dms_ems_mapping").arg(m_curLayer);
				log_error(log.toLocal8Bit().data());
				//*out << log + "\n";
				QString eType = QObject::tr("noDevError");
				m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
				return false;
			}
			for (int ti = 0; ti < values.size(); ti++)/////////errorLog修复//////////////
				m_errorLogSqls.removeLast();

			QString rid = QString::fromLocal8Bit(result[0][0].ToStr().c_str());
			QString objType = QString::fromLocal8Bit(result[0][1].ToStr().c_str());
			QString conTable = "";
			QString whereStr = "";
			if (objType == "1"){
				tableName = "breaker";
				conTable = "obj_dev";
				whereStr = QString("rdf_id = %1, filter=%2").arg(rid).arg(tableName);

				TwoDimArray idret;
				ret = m_pRTDBCli->Select(conTable.toLocal8Bit().data(), "id", whereStr.toLocal8Bit().data(), idret, "dms_ems_mapping name to id");
				if (ret < 0 || idret.Row() == 0){
					QString log = QObject::tr("select id by dms_ems_mapping rdfid error . ems_rdfid:%1 ,table:%2, layer:%3").arg(rid).arg(conTable).arg(m_curLayer);
					log_error(log.toLocal8Bit().data());
					//*out << log + "\n";
					QString eType = QObject::tr("noDevError");
					m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
					return false;
				}
				id = QString::fromLocal8Bit(idret[0][0].ToStr().c_str());
			}
			///////
			if (id.isEmpty()){
				QString log = QObject::tr("select dev id by rdfid error . rdfid:%1 ,table:%2, layer:%3").arg(rdfID).arg(tableName).arg(m_curLayer);
				log_error(log.toLocal8Bit().data());
				//*out << log + "\n";
				QString eType = QObject::tr("noDevError");
				m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
				return false;
			}
		}
		//select rtdb end

	}
	else if (source == "Meas_Ref")
	{
		//dig/ana rdfid -to-id
		if (rdfID.contains(":"))
		{
			QStringList lst = rdfID.split(":");
			rdfID = lst.first();
			if (rdfID.contains("/"))
				rdfID = rdfID.split("=").last();
		}
		colorCfg = "ai_color";
		tableName = "pnt_ana";

#if 0
		else//text is linked to ana
		{
			colorCfg = "di_color";
			tableName = "pnt_dig";

		}
#endif
		QString whereStr = QString("rdfid = %1").arg(rdfID);
		TwoDimArray result;
		int ret = m_pRTDBCli->Select(tableName.toLocal8Bit().data(), "id", whereStr.toLocal8Bit().data(), result, "pnt rdfid to id");
		if (ret < 0 || result.Row() == 0)
		{
			QString log = QObject::tr("select pnt id by rdfid .Er:%1, rdfid:%2,table:%3,layer:%4").arg(ret).arg(rdfID).arg(tableName).arg(m_curLayer);
			log_error(log.toLocal8Bit().data());
			//*out << log + "\n";
			QString eType = QObject::tr("noPointError");
			m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
			return false;
		}
		id = QString::fromLocal8Bit(result[0][0].ToStr().c_str());
		//select rtdb end
	}
	
	if (id.isEmpty() || tableName.isEmpty())
	{
		return false;
	}
	QString app = QString::fromStdString(EProc::GetApp());
	if (app.isEmpty())
		app = "scada";
	if (source == "PSR_Ref")
	{
		if (measName=="")
			id = QString("%1.%2.%3.%4.qcolor").arg(m_dmName).arg(app).arg(tableName).arg(id);
		else
			id = QString("%1.%2.%3.%4.%5").arg(m_dmName).arg(app).arg(tableName).arg(id).arg(measName);
	}
	else
		id = QString("%1.%2.%3.%4.value").arg(m_dmName).arg(app).arg(tableName).arg(id);
	QString userDatastr = QString("[{\"attr\":\"0,0,0,0,0,-1\",\"attrType\":0,\"byValue\":1,\"colorcfg\":\"%1\",\"flag\":0,\"script\":\"\",\"tags\":\"%2\"}]").arg(colorCfg).arg(id);
	itemData->SetUserData(userDatastr);
	if (itemData->TypeName() == "text")
		(CTextData*)itemData->SetProperty("disp-type",3);/////小数显示，控制小数位数//////
	return true;
}

bool QSvgTinyDocument::SetGISMeasUserData(CBaseData *itemData, QString psrMRID, QString measName)
{
	QString tableName;
	QString id;

	QString whereStr = QString("mrid = %1").arg(psrMRID);
	TwoDimArray result;
	int ret = m_pRTDBCli->Select("obj_dev", "id,filter", whereStr.toLocal8Bit().data(), result, "dev mrid to id");
	if (ret < 0 || result.Row() == 0){
		QString log = QObject::tr("select obj_dev id by mrid error . mrid:%1 ,layer:%2").arg(psrMRID).arg(m_curLayer);
		log_error(log.toLocal8Bit().data());
		//*out << log + "\n";
		QString eType = QObject::tr("noDevError");
		m_errorLogSqls.append(QString("insert into model_error_object (id,description,detail,parent_id) values (get_maxid_by_tablename('model_error_object','id',1),'%1','%2','%3');").arg(eType).arg(log).arg(m_curFileName));
		return false;
	}
	else{
		id = QString::fromLocal8Bit(result[0][0].ToStr().c_str());
		if (result.Column()>1)
			tableName = QString::fromLocal8Bit(result[0][1].ToStr().c_str());
		if (tableName.isEmpty())
			tableName = "obj_dev";
	}
	//select rtdb end
	measName = m_measureNameMap.value(measName).toString();
	QString tag;
	QString colorCfg = "ai_color";
	if (measName == ""){
		tag = QString("%1.%2.%3.%4.ia_value").arg(m_dmName).arg(tableName).arg(id);
	}
	else{
		QString app = QString::fromStdString(EProc::GetApp());
		if (app.isEmpty())
			app = "scada";
		tag = QString("%1.%2.%3.%4.%5_value").arg(m_dmName).arg(app).arg(tableName).arg(id).arg(measName);
    }
	QString userDatastr = QString("[{\"attr\":\"0,0,0,0,0,-1\",\"attrType\":0,\"byValue\":true,\"colorcfg\":\"%1\",\"flag\":0,\"script\":\"\",\"tags\":\"%2\"}]").arg(colorCfg).arg(tag);
	itemData->SetUserData(userDatastr);
	if (itemData->TypeName() == "text")
		(CTextData*)itemData->SetProperty("disp-type", 3);/////小数显示，控制小数位数///////
	return true;
}

void QSvgTinyDocument::InitSetting()
{
	m_planeSeparateChar = "";
	m_symbolIdL = 0;
	m_measureNameMap.clear();
	m_layer2tableMap.clear();
	m_layer2columnMap.clear();
	m_psr2rdfidMap.clear();
	m_node2item.clear();
	m_attr2child.clear();
	m_hideLayer.clear();

	QString cfgFile = m_dir + "/svgimp.ini";

	CSimpleIni app_ini;
	app_ini.SetUnicode(true);
	int er = app_ini.LoadFile(cfgFile.toLocal8Bit().data());
	if (er != SI_OK)
	{
		QString log = QString("Load ini config file failed.File path:%1,Er:%2\n").arg(cfgFile).arg(er);
		log_error(log.toLocal8Bit().data());
		//*out << log;
		return;
	}
	CSimpleIni::TNamesDepend groups;
	app_ini.GetAllSections(groups);
	CSimpleIni::TNamesDepend::iterator iter = groups.begin();
	for (; iter != groups.end(); ++iter)
	{
		QString curGroup = iter->pItem;
		CSimpleIni::TNamesDepend keylist;
		app_ini.GetAllKeys(curGroup.toLocal8Bit().data(), keylist);

		CSimpleIni::TNamesDepend::iterator keyIter = keylist.begin();
		for (; keyIter != keylist.end(); ++keyIter)
		{
			const char * cur_key = keyIter->pItem;
			QString value = app_ini.GetValue(curGroup.toLocal8Bit().data(), cur_key, "");
			if (curGroup == "symbol")
			{
				if (QString(cur_key) == "separator")
					m_planeSeparateChar = value;
				else if (QString(cur_key) == "id_length")
					m_symbolIdL = value.toInt();
				else if (QString(cur_key) == "cb_open_status_plane")
					m_cb_change_status = value.toInt();
			}
			else if (curGroup == "measurement-type")
			{
				m_measureNameMap.insert(cur_key, value);
			}
			else if (curGroup == "layer-table")
			{
				QStringList tables = value.split("/");
				foreach(QString table, tables)
					m_layer2tableMap.insert(cur_key, table);//layer --table default is obj_dev
			}
			else if (curGroup == "layer-column")
			{
				m_layer2columnMap.insert(cur_key, value);//layer--point column
			}
			else if (curGroup == "attr-rdfid")
			{
				m_psr2rdfidMap.insert(cur_key, value);
				/*	//xiangtan ems special cfg, could no setting, default rdfid==ObjectID, setting.cfg in dir of graph to import
				m_psr2rdfidMap["PSR_Ref"] = "ObjectName";//xiangtan ems svg: dev psr_ref need  ObjectName==rdfid
				m_psr2rdfidMap["MEAS_Ref"] = "ObjectID";//xiangtan ems svg: dev psr_ref need  prefix +ObjectName== rdfid*/
			}
			else if (curGroup == "attr-child")
			{
				m_attr2child.insert(cur_key, value);
			}
			else if (curGroup == "node-item")
			{
				m_node2item.insert(cur_key, value);
			}
			else if (curGroup == "hide-layer")
			{
				m_hideLayer.append(cur_key);
			}
		}
	}
	///////////////rdfid 图形中需加不同前缀才能映射到模型中，实时库无法模糊查找，所以从商用库查询id, svgimp.ini配置[attr-rdfid] 下useDB=DB/////////////////
	QMap<QString, QVariant>::iterator itr = m_psr2rdfidMap.find("useDB");
	if (itr != m_psr2rdfidMap.end()){
		if (itr.value().toString().compare("DB", Qt::CaseInsensitive) == 0)
			m_useDB = true;
	}
}

bool QSvgTinyDocument::InitDBPtr()
{
	if (m_pDBCli == NULL)
	{
		m_pDBCli = new DbClient();
		int erCode = m_pDBCli->ConnectDuty();
		if (erCode < 0)
		{
			log_info(" DbClient.ConnectDuty()  fail retcode : %d", erCode);
			return false;
		}
	}
	if (m_pRTDBCli == NULL)
	{

		m_pRTDBCli = new RTDB_ClientBase();
		QString ctxapp = QString::fromStdString(EProc::GetCtxApp());
		if (ctxapp.isEmpty() || ctxapp == "#")
			ctxapp = "real#scada";
		int ret = m_pRTDBCli->Connect(EProc::GetSys().c_str(), ctxapp.toStdString().c_str());
		if (ret < 0)
		{
			QString log = QString("rtdb Connect failed.Er:%1,sys: test ,ctxapp: %2 \n").arg(ret).arg(ctxapp.toStdString().c_str());
			log_error(log.toLocal8Bit().data());
			//*out << log;
			return false;
		}
	}
	if (m_dmName.isEmpty())
	{
		m_pSysRun = new SysRun();
		if (m_pSysRun == NULL)
		{
			log_error("BaseSrv----  m_pSysRun is NULL");
			return false;
		}
		else{
			int erCode = m_pSysRun->Init();
			if (erCode < 0)
			{
				delete m_pSysRun;
				m_pSysRun = NULL;
				log_error("BaseSrv---- m_pSysRun->Init failed erCode: %d", erCode);
				return false;
			}
		}
		std::vector<std::string> domain_list;
		m_sysName = m_pSysRun->GetLocalSys();
		int ret = m_pSysRun->GetSysDomain(m_sysName.toLocal8Bit().data(), domain_list);
		if (ret < 0 || domain_list.size() == 0)
		{
			log_error(" BaseSrv---- GetDomainList  fail, sys:%s, ret_code:%d", m_sysName.toLocal8Bit().data(), ret);
			return false;
		}
		m_dmName = QString::fromStdString(domain_list[0]);
		if (m_dmName.isEmpty())
			m_dmName = "power";
	}
	if (m_pSyncWriteCli == NULL)
	{
		m_pSyncWriteCli = new DBSync();
		m_pSyncWriteCli->Connect(m_sysName.toLocal8Bit().data());
	}
	return true;
}

bool QSvgTinyDocument::InitErrorLog()
{
	QDateTime dt = QDateTime::currentDateTime();
	QString dstr = dt.toString("yyyyMMddhhmmss");
	QString log_file = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC) + "/impError_" + dstr + ".log";
	m_logFile = new QFile(log_file);
	if (!m_logFile->open(QIODevice::WriteOnly | QIODevice::Text))
		return false;	
	out = new QTextStream(m_logFile);
}

QString QSvgTinyDocument::CheckIconFileName(QString typeName)
{
	QString fileName = typeName;
	if (typeName.startsWith(ICONPREFIX))
		fileName = typeName.right(typeName.length() - ICONPREFIX.length());
	QRegExp rx("[\\/:*?\"<>|]");
	int pos = 0;
	while ((pos = rx.indexIn(fileName, pos)) != -1) {
		fileName.replace(pos, 1, "");
		pos += rx.matchedLength();
	}
	return fileName;
}

QT_END_NAMESPACE
