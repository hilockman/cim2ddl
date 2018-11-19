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

#ifndef QSVGTINYDOCUMENT_P_H
#define QSVGTINYDOCUMENT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include "qsvgstructure_p.h"
#include "qtsvgglobal_p.h"
#include "rtdb/rtdb_client_base.h"
#include "db_com/db_client.h"
#include "qsvgstyle_p.h"
#include "qsvgfont_p.h"
#include "GraphScene.h"
#include "GraphItem.h"
#include "sys/sysrun.h"
#include "db_com/dbsync.h"

class QPainter;
class QByteArray;
class QSvgFont;

class Q_SVG_PRIVATE_EXPORT QSvgTinyDocument : public QSvgStructureNode
{
public:
    static QSvgTinyDocument * load(const QString &file);
    static QSvgTinyDocument * load(const QByteArray &contents);
    static QSvgTinyDocument * load(QXmlStreamReader *contents);
	int ToGraphics(QGraphicsScene* pscene);
	static int toSmartsys(const QString &file, const QString &outfile, const QMap<QString, QObject *> &appQSobject = QMap<QString, QObject *>(), const QString &script = "");
	static int toSmartsysBat(const QString &dir);

	///////////////////////svgimp.ini配置信息////////////////////////
	static QString m_planeSeparateChar;///////图元的图层分隔符  如Breaker_4030010@0 和Breaker_4030010@1  分隔符前是图元名称 后面是状态（即图层号）/////////////
	static int m_symbolIdL;///////如Breaker_4030010@0和Breaker_4030011@1是一种图元的两个状态，但分隔符前的名称最后一个不同 图元名称需去掉最后一字符 (-m_symbolIdL)表示需要去掉的字符个数  /////// ///////
	static bool m_cb_change_status;///////开断类图元的开合状态，是否需要转换，默认FALSE，0=开，1=合/////////////
	static QMultiMap<QString, QString> m_layer2tableMap;//cim psrType can into many table ////如cim::substation可能如station表和compositeswitch表//////
	static QVariantMap m_layer2columnMap;///////每种设备关联到图形上的列 如pos_value或p_value///////
	static QVariantMap m_measureNameMap;////量测名称的对应////////
	static QVariantMap m_psr2rdfidMap;//////设备rdfid的处理 比如 有的用psr_ref的object_id 有的是object_name, rdfid找id读DB还是RTDB，默认RTDB(db是模糊查询)////////
	static QVariantMap m_attr2child;///////父图元的属性，要附加到子图元上处理，如text关联量测点，需要把父图元g上的PSR_Ref、prefix等属性设置到子图元text上，父图元从scene上删除///////////////
	static QVariantMap m_node2item;///////改变图元类型，如关联measurement的polygon改为text////////
	static QStringList m_hideLayer;///////默认不显示的图层///////////
	static QString m_dmName;
	static QString m_sysName;
	static RTDB_ClientBase* m_pRTDBCli;
	static DbClient* m_pDBCli;
	static DBSync* m_pSyncWriteCli;
	static bool m_useDB;
	static QFile* m_logFile;
	static QTextStream* out;
	static SysRun* m_pSysRun;
public:
    QSvgTinyDocument();
    ~QSvgTinyDocument();
    Type type() const;

    QSize size() const;
    void setWidth(int len, bool percent);
    void setHeight(int len, bool percent);
    int width() const;
    int height() const;
    bool widthPercent() const;
    bool heightPercent() const;

    bool preserveAspectRatio() const;

    QRectF viewBox() const;
    void setViewBox(const QRectF &rect);

    virtual void draw(QPainter *p, QSvgExtraStates &);//from the QSvgNode

    void draw(QPainter *p);
    void draw(QPainter *p, const QRectF &bounds);
    void draw(QPainter *p, const QString &id,
              const QRectF &bounds=QRectF());
	
    QMatrix matrixForElement(const QString &id) const;
    QRectF boundsOnElement(const QString &id) const;
    bool   elementExists(const QString &id) const;

    void addSvgFont(QSvgFont *);
    QSvgFont *svgFont(const QString &family) const;
    void addNamedNode(const QString &id, QSvgNode *node);
    QSvgNode *namedNode(const QString &id) const;
    void addNamedStyle(const QString &id, QSvgFillStyleProperty *style);
    QSvgFillStyleProperty *namedStyle(const QString &id) const;

    void restartAnimation();
    int currentElapsed() const;
    bool animated() const;
    void setAnimated(bool a);
    int animationDuration() const;
    int currentFrame() const;
    void setCurrentFrame(int);
    void setFramesPerSecond(int num);

	void addExtendedNode(QJsonObject obj){ m_extendedNodeArray.append(obj); }
	QJsonArray ExtendedNode(){ return m_extendedNodeArray; }
	void replaceExtendedNode(int index, QJsonObject obj){ m_extendedNodeArray.replace(index, obj); }
    bool SetUserData(CBaseData *itemData, QString rdfID, QString source);
	bool SetGISMeasUserData(CBaseData *itemData, QString psrMRID, QString measName);

private:
    void mapSourceToTarget(QPainter *p, const QRectF &targetRect, const QRectF &sourceRect = QRectF());

	QGraphicsItem* ParseGNode(QSvgNode* node);
	QGraphicsItem* ToItem(QSvgNode* node);
	void LoadBaseProperty(QGraphicsItem* pitem, QSvgNode* node);
	void LoadProperty2Child(QGraphicsItem* pGItem, QSvgNode* node, QGraphicsItem* item);
	QGraphicsItem* ParseSymbol(QSvgNode* node);
	QString CheckIconFileName(QString typeName);
	static bool InitDBPtr();
	static void InitSetting();
	static bool InitErrorLog();
private:
    QSize  m_size;
    bool   m_widthPercent;
    bool   m_heightPercent;

    mutable QRectF m_viewBox;

    QHash<QString, QSvgRefCounter<QSvgFont> > m_fonts;
    QHash<QString, QSvgNode *> m_namedNodes;
    QHash<QString, QSvgRefCounter<QSvgFillStyleProperty> > m_namedStyles;

    QTime m_time;
    bool  m_animated;
    int   m_animationDuration;
    int   m_fps;

    QSvgExtraStates m_states;

	CGraphScene* m_pScene;
	QJsonArray m_extendedNodeArray;
	QString m_curLayer;
	QStringList m_errorLogSqls;
	QString m_curFileName;
};

inline QSize QSvgTinyDocument::size() const
{
    if (m_size.isEmpty()) {
        return viewBox().size().toSize();
    } else {
        return m_size;
    }
}

inline int QSvgTinyDocument::width() const
{
    return size().width();
}

inline int QSvgTinyDocument::height() const
{
    return size().height();
}

inline bool QSvgTinyDocument::widthPercent() const
{
    return m_widthPercent;
}

inline bool QSvgTinyDocument::heightPercent() const
{
    return m_heightPercent;
}

inline QRectF QSvgTinyDocument::viewBox() const
{
    if (m_viewBox.isNull())
        m_viewBox = transformedBounds();

    return m_viewBox;
}

inline bool QSvgTinyDocument::preserveAspectRatio() const
{
    return false;
}

inline int QSvgTinyDocument::currentElapsed() const
{
    return m_time.elapsed();
}

inline int QSvgTinyDocument::animationDuration() const
{
    return m_animationDuration;
}



#endif // QSVGTINYDOCUMENT_P_H
