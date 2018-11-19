



#ifndef GFUNC_H
#define GFUNC_H 

#include "Global.h"
#include "../QtAwesome/QtAwesome.h"
class QtAwesome;
DLL_CLASS QtAwesome* UnqAwe();

class DLL_CLASS CPathAnimation : public QPropertyAnimation {
public:

    CPathAnimation(QObject * parent = 0)
        : QPropertyAnimation(parent)
    {
        m_path = QPainterPath();
        m_easingCurveType = QEasingCurve::Linear;
    }
    virtual ~CPathAnimation(){stop();};
    void SetPath(QPainterPath path)
    {
        m_path = path;
    }
    void SetEasingCurveType(int type)
    {
        m_easingCurveType = type;
        setEasingCurve(CreateEasingCurve((QEasingCurve::Type)type));
        setCurrentTime(0);
    }
    QEasingCurve CreateEasingCurve(QEasingCurve::Type curveType)
    {
        QEasingCurve curve(curveType);

        if (curveType == QEasingCurve::BezierSpline) {
            curve.addCubicBezierSegment(QPointF(0.4, 0.1), QPointF(0.6, 0.9), QPointF(1.0, 1.0));

        }
        else if (curveType == QEasingCurve::TCBSpline) {
            curve.addTCBSegment(QPointF(0.0, 0.0), 0, 0, 0);
            curve.addTCBSegment(QPointF(0.3, 0.4), 0.2, 1, -0.2);
            curve.addTCBSegment(QPointF(0.7, 0.6), -0.2, 1, 0.2);
            curve.addTCBSegment(QPointF(1.0, 1.0), 0, 0, 0);
        }

        return curve;
    }
    void updateCurrentTime(int currentTime) Q_DECL_OVERRIDE
    {
        if (!m_path.isEmpty()) {
            int dura = duration();
            const qreal progress = ((dura == 0) ? 1 : ((((currentTime - 1) % dura) + 1) / qreal(dura)));

            qreal easedProgress = easingCurve().valueForProgress(progress);
            if (easedProgress > 1.0) {
                easedProgress -= 1.0;
            }
            else if (easedProgress < 0) {
                easedProgress += 1.0;
            }
            QPointF pt = m_path.pointAtPercent(easedProgress);

            double angel = m_path.angleAtPercent(easedProgress);
			if (direction() == QAbstractAnimation::Backward)
				angel += 180;
            targetObject()->setProperty("rotate", -angel);

            updateCurrentValue(pt);
            emit valueChanged(pt);
        }
        else {
            QPropertyAnimation::updateCurrentTime(currentTime);
        }
    }

    QPainterPath m_path;
    int m_easingCurveType;
};

class DLL_CLASS CGFunc : public QObject
{
    Q_OBJECT
public:
    enum PATH_TYPE
    {
        PATH_TYPE_SOUND = 0,
        PATH_TYPE_PIC ,
        PATH_TYPE_ICON ,
        PATH_TYPE_PIXMAP,
        PATH_TYPE_ICONSET,
        PATH_TYPE_ETC ,
        PATH_TYPE_BIN ,
        PATH_TYPE_DLL ,
        PATH_TYPE_HELP ,
        PATH_TYPE_SCRIPT,
        PATH_TYPE_ITEMICON,
        PATH_TYPE_ACTIONICON ,
        PATH_TYPE_RES,
        PATH_TYPE_CONF,
        PATH_TYPE_CSS,
        PATH_TYPE_DATA
    };
public:
    CGFunc(QObject *parent = 0, const char *name = 0);
    ~CGFunc();

public slots:
    void QSleep(int msec);


    int TmRestart(){return m_TestTime.restart();};
    void TmDebug(const QString& log);


    void SetVar(const QString & key, const QVariant & value);


    QVariant GetVar( const QString & key, const QVariant & def = QVariant(0), bool * ok = 0 );
    QString GetDateTime(QString format);


    void SetMemVar(const QString & key, const QVariant & value);
    QVariant GetMemVar( const QString & key, const QVariant & def =QVariant(0), bool * ok = 0 );

    int ExitApp();

    QStringList EntryList(QString dir, const QStringList & nameFilters,int filters=-1,int sort=-1) ;

	QVariantList EntryInfoList(QString dir, const QStringList & nameFilters, int filters = -1, int sort = -1);

    bool FileExists(QString file);

    QString LoadFile(const QString &name );
    int SaveFile(const QString &name,const QString& buf );
    QString LoadBinaryFile(QString filePath);
    int SaveBinaryFile(QString filePath, QString fileStr);

    int LoadIconInfo();
    float CalcAngle(float x, float y) const;
    int GetGraphCoreNameByGraphPathName(const QString graph_path_name, QString& graph_core_name);
    int GetGraphNameByGraphPathName(const QString graph_path_name, QString& graph_name);
    int GetGraphNaviNameByGraphPathName(const QString graph_path_name, QString& graph_navi_name);

    int GetGraphCoreNameByGraphName(const QString graph_name, QString& graph_core_name);
    int GetGraphPathNameByGraphName(const QString graph_name, QString& graph_path_name, bool is_case_status = false);



    int GetIconNaviNameByIconPathName(const QString icon_path_name, QString& icon_navi_name);
    int GetIconPathNameByIconCoreName(const QString icon_name, QString& icon_path_name);
    int GetIconIDByIconPathName(const QString& iconPahtName,QString& iconID);
    QString GetDir(PATH_TYPE pathType) const {return m_PathTypeNameMap.value(pathType, "");};
    int GetFilePathName(int path_type, QString file_name, QString &file_path_name);
    int GetNaviNameByPathName(const QString path_name, QString& navi_name);

    void SetDisplayName(const QString & display_name);
    int GetDisplayName(QString & display_name);
    int GetDisplayNo();
    int GetAnotherDisplayNo(std::vector<int> *allow_screen_vec= NULL, int index=-1);
    int GetCmdRegisterName(const QString &cmd, QString & register_name);

    int GetScreenNums();
    void SetLocalDmId(int domain_id) {m_DomainId=domain_id;};
    int GetLocalDmId() {return m_DomainId;};
    QString GetRegName();
    QString GetProcessName() {return "hmi";};
    void SetPicPaths(std::vector<QString> paths){ if (paths.size()>0) m_PicPaths=paths; };
    QString GetSysHome() const {return QDir::cleanPath(m_SysHome);};
    QString GetItemIconName(const QString& iconName) const {return m_PathTypeNameMap[PATH_TYPE_ITEMICON]+iconName;};
    void SetSysHome(const QString & sys_home) ;
    void SetProjectHome(const QString & project_home);
	QString GetProjectHome() const { return QDir::cleanPath(m_ProjectHome); };

    int SysCmd(const QString & op,const QString & srcfile="",const QString & desfile="",bool is_local=true,const QString & machine_name="");

    QString SysExec(const QString & command, bool hasConsole = true,int waitForFinishedMsecs=0 , int which_screen=0, int show_type =1);

    QString GetBrushStyleText(const QBrush &brush,const QString &pic_name = "");
    QBrush SetBrushByText(const QString & text);
    QString GetTextureFileName(const QString &text);
	QObjectList Selector(const QString& selector, const QList<QGraphicsItem *>& items);
    QPolygonF CreateArrow(const QPointF& ps,int arrowType,int arrowHeight,int arrowWidth);
    CPathAnimation* CreatePathAnimate(QGraphicsItem * pathitem, int direct,int duration=5000,int loop=-1);
    QObject* CreateAnimate(QObject * target, const QString & propertyName,const QVariant& startval="",const QVariant& endval="",int duration=5000,int loop=-1 );
    void DrawArrowPline(QPainter *painter, const QPolygonF &polygon, int arrow_type1, int arrow_size1,
                        int arrow_type2, int arrow_size2, const QStyleOptionGraphicsItem *option);

    QObject* Awe(){return UnqAwe();};
signals:
	void SysExecFinished(QString programName, int exitCode, int exitStatus);

public:
    QJsonObject Str2Json(const QString& jsonStr);
    QJsonArray  Str2JsonArray(const QString& jsonStr);
    QString Json2Str(const QJsonObject &jsonObj,QJsonDocument::JsonFormat format=QJsonDocument::Compact);
	QString Json2Str(const QJsonArray &jsonArray, QJsonDocument::JsonFormat format = QJsonDocument::Compact);
    bool ParsePathData(const QStringRef &dataStr, QPainterPath &path);
    void ProcessBrush(const QRectF &rect,QBrush & fillbrush);
    QVector<qreal> parseNumbersList(const QChar *&str);
    QMatrix parseTransformationMatrix(const QStringRef &value);
    QImage ConvertColor(const QString &pix, uint srcColor=0xFFFFFFFF, const QString& desColor="transparent");

	static std::string getPinyinFromUTF8(const char* strName);

private slots:
void OnSysExecFinished(int, QProcess::ExitStatus);

private:
	static int FirstLetter(int nCode, std::string &strLetter);
	static std::string getPinyinFromAnsi(const std::string strName);
	std::string m_curLocale;
	static char m_temp[1024];

private:
    int m_DomainId;
    QMap<int,QString> m_PathTypeNameMap;
    QString m_SysHome;
    QString m_ProjectHome;
    QString m_DisplayName;
    std::vector<QString> m_PicPaths;
    QSettings *m_pSettings;
    QVariantMap m_LocalMemVars;
    QChar m_Spt;
    QTime m_TestTime;

} ;
DLL_CLASS CGFunc * UnqFunc();



#endif
