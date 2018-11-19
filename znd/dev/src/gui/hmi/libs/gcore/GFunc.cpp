#include "GFunc.h"
#include "IconMng.h"
#include <time.h>
#ifdef WIN32
#include <process.h>
#else
#include <unistd.h>
#include <signal.h>
#endif


const double PI = 3.1415926535;
#define Q_PI PI

CGFunc * UnqFunc()
{
    static CGFunc _name_instance;
    return &_name_instance;
}

QtAwesome* UnqAwe()
{
    static QtAwesome* _awe_instance=new QtAwesome( qApp );
    return _awe_instance;
}

char CGFunc::m_temp[] = { 0 };

CGFunc::CGFunc(QObject *parent , const char *name ): QObject( parent )
{
	memset(m_temp, 0, 1024);
//	m_curLocale = setlocale(LC_ALL, NULL);
//	setlocale(LC_ALL, "chs");

    setObjectName("Func");
    m_pSettings=new QSettings("SF","PGRAPH");
    m_Spt=QDir::separator();
    QString sys_home = qgetenv(SYS_HOME.toLocal8Bit().data());
    if(sys_home.isEmpty())
    {
        QDir tmpdir=QCoreApplication::applicationFilePath();
        tmpdir.cd("../../");
        sys_home=tmpdir.absolutePath();

    }

    SetSysHome( sys_home);
    //SetProjectHome(sys_home+m_Spt+"data"+m_Spt);
    m_DomainId =-1;
    m_TestTime.start();
}

CGFunc::~CGFunc()
{
//	setlocale(LC_ALL, m_curLocale.c_str());
    delete m_pSettings;
}

void CGFunc::QSleep(int msec)
{
#ifdef WIN32
        Sleep(msec);
#else
        sleep(msec/1000);
#endif
}

void CGFunc::SetSysHome(const QString & sys_home)
{
    if (sys_home.isEmpty())
    {
        return;
    }
    m_SysHome=QDir::toNativeSeparators(sys_home);

    QString appDir=QCoreApplication::applicationDirPath();
    QChar spt=m_Spt;
    m_PathTypeNameMap[PATH_TYPE_BIN] = appDir+spt;
    m_PathTypeNameMap[PATH_TYPE_DLL] = appDir+spt;
    m_PathTypeNameMap[PATH_TYPE_ICONSET] = GetSysHome()+spt+"res"+spt+"ico"+spt;
    m_PathTypeNameMap[PATH_TYPE_ITEMICON] = GetSysHome()+spt+"res"+spt+"ico"+spt+"items"+spt;
    m_PathTypeNameMap[PATH_TYPE_ACTIONICON] = GetSysHome()+spt+"res"+spt+"ico"+spt+"actions"+spt;
    m_PathTypeNameMap[PATH_TYPE_ETC] = GetSysHome()+spt+"data"+spt+"etc"+spt;
    m_PathTypeNameMap[PATH_TYPE_CONF] = GetSysHome()+spt+"conf"+spt;
    m_PathTypeNameMap[PATH_TYPE_RES] = GetSysHome()+spt+"res"+spt;

    SetProjectHome(sys_home+m_Spt+"data"+m_Spt);

}

void CGFunc::SetProjectHome(const QString & project_home)
{
    if (project_home.isEmpty())
    {
        return;
    }
	m_ProjectHome = QDir::toNativeSeparators(QDir::cleanPath(project_home));

    QChar spt=m_Spt;
    QDir dir;

    m_PathTypeNameMap[PATH_TYPE_PIC] = GetProjectHome()+spt+"pic"+spt;
    m_PathTypeNameMap[PATH_TYPE_ICON] = GetProjectHome()+spt+"icon"+spt;
    m_PathTypeNameMap[PATH_TYPE_PIXMAP] = GetProjectHome()+spt+"images"+spt;
    m_PathTypeNameMap[PATH_TYPE_HELP] = GetProjectHome()+spt+"html"+spt;
    m_PathTypeNameMap[PATH_TYPE_SCRIPT] = GetProjectHome()+spt+"script"+spt;
    m_PathTypeNameMap[PATH_TYPE_SOUND] = GetProjectHome()+spt+"sound"+spt;
    m_PathTypeNameMap[PATH_TYPE_CSS] = GetProjectHome()+spt+"css"+spt;
    m_PathTypeNameMap[PATH_TYPE_DATA] = GetProjectHome()+spt;

    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_PIC]);
    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_ICON]);
    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_PIXMAP]);
    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_HELP]);
    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_SCRIPT]);
    dir.mkpath(m_PathTypeNameMap[PATH_TYPE_SOUND]);
    m_PicPaths.clear();
    m_PicPaths.push_back(m_PathTypeNameMap[PATH_TYPE_PIC]);
}

void CGFunc::TmDebug(const QString& log)
{
    gDebug("---Time elapsed--%s: %d ms",log.toLocal8Bit().data(),m_TestTime.elapsed());//qDebug
	m_TestTime.restart();
}

QString CGFunc::LoadFile(const QString &name )
{
    QString file_path_name=name;
    if(!QDir::isAbsolutePath(name))
    {
        GetFilePathName(PATH_TYPE_PIC, name, file_path_name);
    }
    QFile file( file_path_name );
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug( "Can't open file %s",file_path_name.toLocal8Bit().data() );
        return QString();
    }
    QTextStream str( &file );
    return str.readAll();
}

int CGFunc::SaveFile(const QString &name,const QString& buf )
{
    QString file_path_name=name;
    if(!QDir::isAbsolutePath(name))
    {
        GetFilePathName(PATH_TYPE_PIC, name, file_path_name);
    }
    QFile file( file_path_name );
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug( "Can't open file %s",file_path_name.data() );
        return -1;
    }
    file.resize(0);
    QTextStream out( &file );
    out << buf;
    file.close();
    return 1;
}

QString CGFunc::LoadBinaryFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        gError("Cannot open %s for writing", filePath.toStdString().c_str());
        return "";
    }
    QByteArray fileData;
    while (!file.atEnd())
    {
        fileData.append(file.readLine());
    }
    if (fileData.size() != file.size())
    {
        gError("Read filesize is not equal with original file size");
        return "";
    }
    return fileData.toBase64();
}

int CGFunc::SaveBinaryFile(QString filePath, QString fileStr)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        gError("Cannot open %s for writing", filePath.toStdString().c_str());
        return -1;
    }

    QByteArray fileData = QByteArray::fromBase64(fileStr.toUtf8());
    qint64 length = file.write(fileData);
    if (length != fileData.size())
    {
        gError("Failed to write all data to %s", filePath.toStdString().c_str());
        return -2;
    }
    return 0;
}


void CGFunc::SetVar(const QString & key, const QVariant & value )
{
    if (key.indexOf("loc.")==0)
    {
        m_pSettings->setValue( "GRAPH_VAR/"+key, value );

    }
    else
    {

    }
}

QVariant CGFunc::GetVar(const QString & key, const QVariant & def , bool * ok )
{
    if (key.indexOf("loc.")==0)
    {
        QVariant str=m_pSettings->value("GRAPH_VAR/"+key,def).toString();
        return str;
    }
    else
    {

    }
}

void CGFunc::SetMemVar(const QString & key, const QVariant & value)
{

    m_LocalMemVars[key]=value;
}

QVariant CGFunc::GetMemVar( const QString & key, const QVariant & def, bool * ok )
{
    if(key.isEmpty() || key=="*")
        return m_LocalMemVars;
    QVariantMap::iterator it;
    it=m_LocalMemVars.find(key);
    if (it!=m_LocalMemVars.end())
    {
        return it.value();
    }
    else
        return QVariant();
}

QString CGFunc::GetDateTime(QString format)
{
    if (format=="time_t")
    {
        QString ret=QString("%1").arg(time(NULL));
        return ret;
    }
    else
        return QDateTime::currentDateTime().toString(format);
}

QStringList CGFunc::EntryList(QString dir, const QStringList & nameFilters,int filters,int sort)
{
    QStringList ret;
    QString path=dir;
    if (QDir::isRelativePath(dir))
    {
        path=UnqFunc()->GetSysHome()+QDir::separator()+dir;
    }
    QDir tmp_dir(path);

    QDir::Filters filter1(-1);
    switch (filters)
    {
    case 0:
        filter1=QDir::Files;
        break;
    case 1:
        filter1=QDir::AllDirs;
        break;
    case 2:
        filter1=QDir::AllEntries;
        break;

    }
    ret=tmp_dir.entryList(nameFilters, filter1,(QDir::SortFlags)sort);
    return ret;
}

QVariantList CGFunc::EntryInfoList(QString dir, const QStringList & nameFilters, int filters, int sort)
{
	QVariantList ret;
    QString path=dir;
    if (QDir::isRelativePath(dir))
    {
        path = UnqFunc()->GetSysHome() + QDir::separator() + dir;
    }
	QDir tmp_dir(path);

	QDir::Filters filter1(-1);
	switch (filters)
	{
	case 0:
		filter1 = QDir::Files;
		break;
	case 1:
		filter1 = QDir::AllDirs;
		break;
	case 2:
		filter1 = QDir::AllEntries;
		break;

	}

	QFileInfoList infos = tmp_dir.entryInfoList(nameFilters, filter1, (QDir::SortFlags)sort);
	for (int i = 0; i < infos.length(); i++) {
		QVariantMap rec;
		QFileInfo info = infos[i];
		rec["fileName"] = info.fileName();
		rec["baseName"] = info.baseName();
		rec["absolutePath"] = info.absolutePath();
		rec["absoluteFilePath"] = info.absoluteFilePath();
		rec["suffix"] = info.suffix();
		rec["created"] = info.created();
		rec["lastModified"] = info.lastModified();
		ret.push_back(rec);
	}
	return ret;
}

bool CGFunc::FileExists(QString file)
{
    QString path=file;
    if (QDir::isRelativePath(file))
    {
        path=UnqFunc()->GetSysHome()+QDir::separator()+file;
    }

    return QFile::exists(path);

}

int CGFunc::LoadIconInfo()
{
    UnqIconMng()->Init();
    return 0;
}

float CGFunc::CalcAngle(float x, float y) const
{
    float angle;
    if (fabs(x) < 0.0001 && fabs(y) < 0.0001)
    {
        return 0;
    }
    if (fabs(x) < 0.0001 && y > 0)
    {
        return 270;
    }
    else if (fabs(x) < 0.0001 && y < 0 )
    {
        return 90;
    }
    else if (fabs(y) < 0.0001 && x > 0 )
    {
        return 0;
    }
    else if (fabs(y) < 0.0001 && x < 0)
    {
        return 180;
    }
    angle = (float)atan2(-y, x) * 180.0 / PI;
    if (angle < 0)
    {
        angle += 360.0;
    }
    return angle;
}
int CGFunc::GetGraphCoreNameByGraphPathName(const QString graph_path_name, QString& graph_core_name)
{
    int idx1 = graph_path_name.lastIndexOf('/');
    int idx1tmp = graph_path_name.lastIndexOf('\\');
	idx1 = idx1>idx1tmp ? idx1 : idx1tmp;

    int idx2 = graph_path_name.lastIndexOf('.');
    if( idx2 < 0 )
    {
        idx2 = graph_path_name.length();
    }

    graph_core_name = graph_path_name.mid(idx1+1, idx2-idx1-1);
    return 0;
}

int CGFunc::GetGraphNameByGraphPathName(const QString graph_path_name, QString& graph_name)
{ 
    graph_name=graph_path_name;
	int idx1 = graph_path_name.lastIndexOf('/');
	int idx1tmp = graph_path_name.lastIndexOf('\\');
	idx1 = idx1>idx1tmp ? idx1 : idx1tmp;

	if (idx1 > 0)
	{
        graph_name = graph_path_name.mid(idx1 + 1 );
		return 0;
	}
	else
		return -1;
}

int CGFunc::GetGraphNaviNameByGraphPathName(const QString graph_path_name, QString& graph_navi_name)
{
    graph_navi_name=graph_path_name.left(graph_path_name.length()-4)+".png";
    return 0;
}

int CGFunc::GetGraphCoreNameByGraphName(const QString graph_name, QString& graph_core_name)
{
    int idx1 = graph_name.indexOf('.');
    if( idx1 < 0 )
    {
        graph_core_name = graph_name;
        return -1;
    }
    else
    {
        graph_core_name = graph_name.left(idx1);
    }
    return 0;
}

int CGFunc::GetGraphPathNameByGraphName(const QString graph_name, QString& graph_path_name, bool is_case_status)
{
    QString tmp_graph_name=graph_name;
	if (QDir::isAbsolutePath(tmp_graph_name))
	{
		if (QFile::exists(tmp_graph_name))
		{
			graph_path_name = tmp_graph_name;
			return 0;
		}
		else
			return -1;
	}

    for(int i=0;i<m_PicPaths.size();i++)
    {
        graph_path_name = m_PicPaths[i] + tmp_graph_name;
        if (QFile::exists ( graph_path_name ) )
            return 0;
    }
    return 0;
}


int CGFunc::GetFilePathName(int path_type, QString file_name, QString &file_path_name)
{
   if(  QDir::isAbsolutePath(file_name) ){
       gInfo("%s-- is isAbsolutePath",file_name.toLocal8Bit().data());
       file_path_name=file_name;
       return 0;
   }
    QString path_name=GetDir((PATH_TYPE)path_type);
    file_path_name = path_name + file_name;
    return 0;
}

int CGFunc::GetIconNaviNameByIconPathName(const QString icon_path_name, QString& icon_navi_name)
{
    icon_navi_name = icon_path_name+".png";
    return 0;
}
int CGFunc::GetIconIDByIconPathName(const QString& iconPahtName,QString& iconID)
{
    int idxOfSuf = iconPahtName.lastIndexOf(ICONSUFFIX);
    if(!iconPahtName.endsWith(ICONSUFFIX))
        return -1;

    int idx1 = iconPahtName.lastIndexOf('/');
    if(idx1 < 0 )
        idx1 = iconPahtName.lastIndexOf('\\');

    if( idx1 > 0 )
    {
        iconID = ICONPREFIX + iconPahtName.mid(idx1+1,idxOfSuf-idx1-1);
        return 0;
    }
    else
        return -1;
}

int CGFunc::GetNaviNameByPathName(const QString path_name, QString& navi_name)
{

    return GetGraphNaviNameByGraphPathName(path_name, navi_name);
}

int CGFunc::GetIconPathNameByIconCoreName(const QString icon_name, QString& icon_path_name)
{
    int idx1 = icon_name.lastIndexOf('/');
    if(idx1 < 0 )
        idx1 = icon_name.lastIndexOf('\\');
    if( idx1 > 0 )
    {
        QString tmp_icon_name(icon_name.mid(idx1+1));
        icon_path_name = m_PathTypeNameMap[PATH_TYPE_ICON]  + tmp_icon_name;
    }
    else
        icon_path_name = m_PathTypeNameMap[PATH_TYPE_ICON]  + icon_name;
    icon_path_name=icon_path_name+ICONSUFFIX;
    return 0;

}



void CGFunc::SetDisplayName(const QString & display_name)
{
    m_DisplayName = display_name;
}

int CGFunc::GetDisplayName(QString & display_name)
{
    display_name = m_DisplayName;
    return 0;
}

int CGFunc::GetDisplayNo()
{
#ifndef WIN32
    if(m_DisplayName.isEmpty())
        return -1;
    int index = m_DisplayName.lastIndexOf('.');
    bool ok;
    int display_no = m_DisplayName.mid(index+1, 1).toInt(&ok);
    qDebug("CGFunc::GetDisplayNo ------------ m_DisplayName = %s; display_no = %d",m_DisplayName.data(), display_no);
    if(ok)
        return display_no;
#endif
    return -1;
}

int CGFunc::GetAnotherDisplayNo(std::vector<int> *allow_screen_vec, int index)
{
#ifndef WIN32
    int screen_num = GetScreenNums();
    if(screen_num<=1)
        return -1;

    int cur_display_no = GetDisplayNo();
    if(cur_display_no == -1)
        cur_display_no = 0;
    if(allow_screen_vec)
    {
        int allow_screen_num = allow_screen_vec->size();
        if(allow_screen_num > 0)
        {
            if(index<=0)
                index = 0;
            if(index>=allow_screen_num)
                index = allow_screen_num;
            for(int i = index; i < allow_screen_num; i++)
            {
                if((*allow_screen_vec)[i] != cur_display_no)
                    return (*allow_screen_vec)[i];
            }
            for(int i =0; i<index; i++)
            {
                if((*allow_screen_vec)[i] != cur_display_no)
                    return (*allow_screen_vec)[i];
            }
        }
        return cur_display_no;
    }
    else
    {
        if(cur_display_no +1 >=screen_num)
            return 0;
        else
            return cur_display_no +1;
    }
#endif
    return -1;
}

int CGFunc::GetCmdRegisterName(const QString &cmd, QString & register_name)
{
    if(m_DisplayName.isEmpty())
        register_name = cmd;
    else
        register_name = cmd + "_" + m_DisplayName;
    return 0;
}

int CGFunc::GetScreenNums()
{

    int terminal_sum=1;
    return terminal_sum;
}

QString CGFunc::GetRegName()
{
    int nProcessId = -1;
    QString reg_name;

#ifdef WIN32
    nProcessId = _getpid();
#else
    nProcessId = getpid();
#endif

    reg_name = QString("ge_%1").arg(nProcessId);
    return reg_name;
}

int CGFunc::SysCmd(const QString & op,const QString & srcfile,const QString & desfile,bool is_local, const QString & machine_name )
{
    QString command;
    bool is_win32=false;
#ifdef WIN32
    is_win32=true;
#endif
    if (op=="mv")
    {
        if (is_win32)
        {
            command = srcfile + " " + desfile;
            QString tmp_command = command;
            command = tmp_command.replace('/','\\').toLocal8Bit().data();
            command = "move /Y " + command;
        }
        else
        {
            command = "mv  " + srcfile + " " + desfile;
            QString tmp_command = command;
            command = tmp_command.replace('\\','/').toLocal8Bit().data();
        }
    }
    else if (op=="cp")
    {
        if (is_win32)
        {
            command = "copy " + srcfile + " " + desfile;
            QString tmp_command = command;
			command = tmp_command.replace('/', '\\').toLocal8Bit().data();
			command =  command+"  /y  ";
        }
        else
        {
            command = "cp  " + srcfile + " " + desfile;
            QString tmp_command = command;
            command = tmp_command.replace('\\','/').toLocal8Bit().data();
        }
    }
    else if (op=="rm")
    {
        if (is_win32)
        {
            command = "del " + srcfile ;
            QString tmp_command = command;
            command = tmp_command.replace('/','\\').toLocal8Bit().data();
        }
        else
        {
            command = "rm  " + srcfile ;
            QString tmp_command = command;
            command = tmp_command.replace('\\','/').toLocal8Bit().data();
        }

    }
    else
    {
        command = op ;

    }
    if (!is_local)
    {
        command= "remote_exe "+ machine_name +"  "+ command;
    }
    command = command + " & ";


    int ret=system(command.toLocal8Bit().data());

    return ret;
}

QString CGFunc::SysExec(const QString & command, bool hasConsole,int waitForFinishedMsecs , int which_screen, int show_type)
{
    int ret_code = -1;

#ifdef WIN32
    if ( show_type == 0 )
    {   
        STARTUPINFOA si;
        PROCESS_INFORMATION pi;
        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        si.wShowWindow = SW_HIDE;
        ZeroMemory( &pi, sizeof(pi) );
        char *tmp_command=( char * )command.data();
        ret_code = CreateProcess( NULL , tmp_command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi ) ;
        if ( ret_code==0 )
        {
            ret_code = -1;

        }
        else
        {
            CloseHandle(pi.hThread);
            WaitForSingleObject(pi.hProcess, INFINITE);
            DWORD exitCode=0;
            if (GetExitCodeProcess(pi.hProcess, &exitCode))
            {
                ret_code = exitCode;
            }
            CloseHandle(pi.hProcess);
        }
        return QString("{\"retcode\":\"%1\"}").arg(ret_code);
    }
#endif

    QString tmp_command=command;
#ifndef WIN32
    if (tmp_command.indexOf(".bat")>0)
    {
        tmp_command.replace(".bat",".sh");
    }
#endif
    QProcess* prc = new QProcess();
    if (hasConsole)
        prc->startDetached(tmp_command);//startDetached : has console
    else
        prc->start(tmp_command);//start : no console
    bool beok = connect(prc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(OnSysExecFinished(int, QProcess::ExitStatus)));
    if(waitForFinishedMsecs>0)
        prc->waitForFinished(waitForFinishedMsecs);

	if (prc->exitStatus() != QProcess::NormalExit)
		ret_code = -1;
	else
		ret_code = prc->exitCode();
	QString result = QString("{\"retcode\":\"%1\",\"data\":\"%2\"}").arg(ret_code).arg(QString(prc->readAllStandardOutput())
		.append(prc->readAllStandardError()).remove('\r').replace("\t", " ").replace("\\", "/").replace("\n", " "));
    return result;
}


void CGFunc::OnSysExecFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	QProcess *pProces = (QProcess *)sender();
	emit SysExecFinished(pProces->program(), exitCode, (int)exitStatus);
}

int CGFunc::ExitApp( )
{
#ifdef WIN32
    QTimer::singleShot(500, qApp, SLOT(quit()));
#else
    kill(getpid(), SIGKILL);
#endif
    return 0;
}


//
//jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]","[attribute!=value]","[attribute$=value]"
QObjectList CGFunc::Selector(const QString& selector,const QList<QGraphicsItem *>& items)
{
	QList<QObject*> ret; 
	QString selector_flag = selector.left(1);
	QString selector_cxt = selector.right(selector.length() - 1);
	QString propName = "";
	QString propValue = "";
	QString op1 = "=";
	QString op2 = "!=";
	QString op3 = "$=";
	QString opflag = "";


	if (selector_flag == "[")
	{
		selector_cxt = selector_cxt.left(selector_cxt.length() - 1);
		if (selector_cxt.indexOf(op2) >= 0)
			opflag = op2;
		else if (selector_cxt.indexOf(op3) >= 0)
			opflag = op3;
		else if (selector_cxt.indexOf(op1) >= 0)
			opflag = op1;

		if (opflag == "")
			propName = selector_cxt;
		else{
			QStringList slist = selector_cxt.split(opflag);
			if (slist.size() > 0)
				propName = slist[0];
			if (slist.size() > 1)
				propValue = slist[1];
		}
	}

	foreach(QGraphicsItem* item, items)
	{
		CBaseData* pdata = g_dataPtr(item);
		if (pdata == NULL)
			continue;

        if(selector_flag == "*" ){
            ret.append(pdata);
        }
        else if (selector_flag == "#" && pdata->GetName() == selector_cxt)
		{
			ret.append(pdata);
		}
		else if (selector_flag == "." ) 
		{
			if ((pdata->TypeName() == selector_cxt) || ((selector_cxt == "ui" || selector_cxt == "icon") && pdata->TypeName().startsWith(selector_cxt)))
				ret.append(pdata);
		}
		else if (selector_flag == "[")
		{
			bool allprop = true;
			if (propName.startsWith("CP::")){
				allprop = false;
				propName = propName.mid(4);
			}
				
			QVariant value = pdata->Property(propName,allprop);
			if (value.isValid())
			{
				if (opflag == "")
				{
					ret.append(pdata);
				}
				else
				{
					QString vstr = value.toString();
					if (vstr.length() == 0) vstr = "";
					if (opflag == op1 &&  propValue == vstr)
						ret.append(pdata);
					else if (opflag == op2 &&  propValue != vstr)
						ret.append(pdata);
					else if (opflag == op3 &&  propValue.contains(vstr, Qt::CaseInsensitive))
						ret.append(pdata);
				}
			}

		}
	}
	return ret;
}

void CGFunc::ProcessBrush(const QRectF &rect,QBrush & fillbrush)
{
    const QGradient * fillgrad = fillbrush.gradient();

    switch (fillbrush.style())
    {
    case Qt::LinearGradientPattern:
    {
        const QLinearGradient *linearGradient = static_cast<const QLinearGradient*>(fillgrad);
        QLinearGradient lgrad;
		QPointF sp = QPointF(linearGradient->start().x()*rect.width() + rect.left(),linearGradient->start().y()*rect.height() + rect.top());
		QPointF fp = QPointF(linearGradient->finalStop().x()*rect.width() + rect.left(), linearGradient->finalStop().y()*rect.height() + rect.top());
        lgrad.setStart(sp);
        lgrad.setFinalStop(fp );
        lgrad.setSpread(linearGradient->spread());
        lgrad.setStops(linearGradient->stops());
        fillbrush = QBrush(lgrad);
        break;
    }
    case Qt::RadialGradientPattern:
    {
        const QRadialGradient *radialGradient = static_cast<const QRadialGradient*>(fillgrad);
        QRadialGradient rgrad;
        QPointF cp = QPointF(rect.width() * radialGradient->center().x() + rect.left(),rect.height() * radialGradient->center().y() + rect.top());
        QPointF cf = QPointF(rect.width() * radialGradient->focalPoint().x() + rect.left(),rect.height() * radialGradient->focalPoint().y() + rect.top());
        qreal cr = (rect.width());
        if(cr>rect.height()) cr = rect.height();
        rgrad.setCenter(cp);
        rgrad.setFocalPoint(cf);
        rgrad.setRadius(cr/2);
        rgrad.setSpread(radialGradient->spread());
        rgrad.setStops(radialGradient->stops());
        fillbrush = QBrush(rgrad);
        break;
    }
    case Qt::ConicalGradientPattern:
    {
        const QConicalGradient *conicalGradient = static_cast<const QConicalGradient*>(fillgrad);
        QConicalGradient cgrad;
        QPointF cp = QPointF(rect.width() * conicalGradient->center().x() + rect.left(),rect.height() * conicalGradient->center().y() + rect.top());
        cgrad.setCenter(cp);
        cgrad.setAngle(conicalGradient->angle());
        cgrad.setSpread(conicalGradient->spread());
        cgrad.setStops(conicalGradient->stops());
        fillbrush = QBrush(cgrad);
        break;
    }
    }
    return;
}

void CGFunc::DrawArrowPline(QPainter *painter,const QPolygonF &polygon, int arrow_type1, int arrow_size1,
                            int arrow_type2, int arrow_size2,const QStyleOptionGraphicsItem *option)
{
    if(polygon.size()<2) return;

    painter->drawPolyline( polygon );

    for (int i = 0; i < 2; i++)
    {
        QPointF dp = (i==0 ? polygon.at(1) - polygon.at(0): polygon.last() - polygon.at(polygon.length() - 2) );
        float angle = UnqFunc()->CalcAngle(dp.x(), dp.y());

        QPointF ps = (i==0 ? polygon.first():polygon.last());
       // QPointF ps = (i==0 ? ps1:ps2);

		int arrowSize = (i == 0 ? arrow_size1 : arrow_size2);
		int arrowHeight = 8;
		int arrowWidth = 10;
		switch (arrowSize)
		{
		case Hmi::ARROW_SIZE_10_8:
		   break;
		case Hmi::ARROW_SIZE_10_10:
		{
            arrowHeight = 12;
            arrowWidth = 12;
		}
			break;
		case Hmi::ARROW_SIZE_10_12:
		{
            arrowHeight = 14;
            arrowWidth = 12;
		}
			break;
		default:
			break;
		}

        int arrowType = (i == 0 ? arrow_type1 : arrow_type2);
        if(arrowType<=Hmi::ARROW_NULL)
            continue;

        QColor lineColor = painter->pen().color();
        QPolygonF poly=CreateArrow( ps, arrowType, arrowHeight,arrowWidth);


        QMatrix m;
        m.translate(ps.x(),ps.y());
        m.rotate(-angle);
        m.translate(-ps.x(), -ps.y());


        painter->save();
        painter->drawPolygon(poly*m);

		switch (arrowType)
		{
		case Hmi::ARROW_SOLID_ARROW:
		case Hmi::ARROW_SOLID_BACKARROW:
		case Hmi::ARROW_SOLID_DIAMOND:
		case Hmi::ARROW_SOLID_RECT:
		{
			QPainterPath path;
			path.addPolygon(poly*m);
			painter->fillPath(path, QBrush(lineColor));
		}
			break;
		}

        painter->restore();
    }
}

QPolygonF CGFunc::CreateArrow(const QPointF& ps, int arrowType, int arrowHeight,int arrowWidth)
{
    QPolygonF poly;
    if (arrowType == 0) return poly;
    int i = 0;

    switch (arrowType)
    {
    case Hmi::ARROW_SOLID_ARROW:
    case Hmi::ARROW_HOLLOW_ARROW:
    {
        poly << ps << QPoint(ps.x() + arrowHeight, ps.y() - arrowWidth / 2.0) << QPoint(ps.x() + arrowHeight, ps.y() + arrowWidth / 2.0);
    }
        break;
    case Hmi::ARROW_SOLID_BACKARROW:
    {
        poly << QPoint(ps.x()-arrowHeight, ps.y() - arrowWidth / 2.0) << QPoint(ps.x()-arrowHeight, ps.y() + arrowWidth / 2.0) << ps;

    }
        break;
    case Hmi::ARROW_SOLID_DIAMOND:
    case Hmi::ARROW_HOLLOW_DIAMOND:
    {
        poly << ps << QPoint(ps.x() + arrowHeight / 2.0, ps.y() - arrowWidth / 2.0) << QPoint(ps.x() + arrowHeight, ps.y()) << QPoint(ps.x() + arrowHeight / 2.0, ps.y() + arrowWidth / 2.0);
    }
        break;
    case Hmi::ARROW_SOLID_RECT:
    case Hmi::ARROW_HOLLOW_RECT:
    {
        poly = QPolygonF(QRectF(QPointF(ps.x(), ps.y() - arrowWidth / 2.0), QSize(arrowHeight, arrowWidth)));
    }
        break;
    }

    return poly;

}

QObject* CGFunc::CreateAnimate(QObject * target, const QString & propertyName,const QVariant& startval,const QVariant& endval,int duration,int loop)
{
    QPropertyAnimation *animation;
    if(propertyName!="path")
    {
        animation = new QPropertyAnimation(target,propertyName.toLocal8Bit(),target);
        animation->setStartValue(startval);
        animation->setEndValue(endval);
    }
    else
    {
        QPainterPath path;
        animation = new CPathAnimation(target);
        animation->setTargetObject(target);
        animation->setPropertyName("pos");
		animation->setEndValue(path.pointAtPercent(1));
        ((CPathAnimation*)animation)->SetPath( path );
    }
    animation->setDuration(duration);
    animation->setLoopCount(loop);
    animation->start();
    return animation;
}

CPathAnimation* CGFunc::CreatePathAnimate(QGraphicsItem * pathitem, int direct,int duration,int loop)
{
    CPathAnimation* animation = new CPathAnimation();
    CPolygonItem* animteitem = new CPolygonItem();

    int type=pathitem->type();
    QPointF ps=QPointF(0,0);
    QPainterPath path;
    if(type==Hmi::Path)
    {
        path=((CPathItem*)pathitem)->path();
		if (direct == 1){
			path=path.toReversed();
		}
    }
    else if(type==Hmi::Polygon || type==Hmi::Polyline ||type==Hmi::Link)
    {
        QVector<QPointF> points;
        QPolygonF polygon=((QGraphicsPolygonItem*)pathitem)->polygon();


        for (int i = 0; i < polygon.size(); i++)
        {
			points.push_back(direct == 0 ? polygon.at(i) - ps + QPointF(4, 0) : polygon.at(polygon.size() - 1 - i) - ps + QPointF(4, 0));
        }
        path.addPolygon(points);
    }

    QPolygonF poly=UnqFunc()->CreateArrow( ps,Hmi::ARROW_SOLID_BACKARROW, 10,10);
    animteitem->setPolygon(poly);
    animteitem->setTransformOriginPoint(ps);
    animteitem->setParentItem(pathitem);
    QColor lineColor = g_dataPtr(pathitem)->GetLineColor();
    animteitem->setBrush( QBrush( lineColor, Qt::SolidPattern) );
    animteitem->setPen(  lineColor );
    animation->setTargetObject(g_dataPtr(animteitem));
    animation->setPropertyName("pos");
    animation->SetPath( path );
	animation->setEndValue(path.pointAtPercent(1));
    animation->setDuration(duration);
    animation->setLoopCount(loop);
    animation->setParent(g_dataPtr(pathitem));
    animation->start();
    return animation;


}



static QString styleSheetFillName(const QGradient &gradient)
{
    QString result;

    switch (gradient.type()) {
    case QGradient::LinearGradient:
        result += QLatin1String("qlineargradient");
        break;
    case QGradient::RadialGradient:
        result += QLatin1String("qradialgradient");
        break;
    case QGradient::ConicalGradient:
        result += QLatin1String("qconicalgradient");
        break;
    default:
        qWarning() << "QtGradientUtils::styleSheetFillName(): gradient type" << gradient.type() << "not supported!";
        break;
    }

    return result;
}

static QStringList styleSheetParameters(const QGradient &gradient)
{
    QStringList result;

    if (gradient.type() != QGradient::ConicalGradient)
    {
        QString spread;
        switch (gradient.spread())
        {
        case QGradient::PadSpread:
            spread = QLatin1String("pad");
            break;
        case QGradient::ReflectSpread:
            spread = QLatin1String("reflect");
            break;
        case QGradient::RepeatSpread:
            spread = QLatin1String("repeat");
            break;
        default:
            qWarning() << "QtGradientUtils::styleSheetParameters(): gradient spread" << gradient.spread() << "not supported!";
            break;
        }
        result << QLatin1String("spread:") + spread;
    }

    switch (gradient.type()) {
    case QGradient::LinearGradient: {
        const QLinearGradient *linearGradient = static_cast<const QLinearGradient*>(&gradient);
        result << QLatin1String("x1:") + QString::number(linearGradient->start().x())
               << QLatin1String("y1:") + QString::number(linearGradient->start().y())
               << QLatin1String("x2:") + QString::number(linearGradient->finalStop().x())
               << QLatin1String("y2:") + QString::number(linearGradient->finalStop().y());
        break;
    }
    case QGradient::RadialGradient: {
        const QRadialGradient *radialGradient = static_cast<const QRadialGradient*>(&gradient);
        result << QLatin1String("cx:") + QString::number(radialGradient->center().x())
               << QLatin1String("cy:") + QString::number(radialGradient->center().y())
               << QLatin1String("radius:") + QString::number(radialGradient->radius())
               << QLatin1String("fx:") + QString::number(radialGradient->focalPoint().x())
               << QLatin1String("fy:") + QString::number(radialGradient->focalPoint().y());
        break;
    }
    case QGradient::ConicalGradient: {
        const QConicalGradient *conicalGradient = static_cast<const QConicalGradient*>(&gradient);
        result << QLatin1String("cx:") + QString::number(conicalGradient->center().x())
               << QLatin1String("cy:") + QString::number(conicalGradient->center().y())
               << QLatin1String("angle:") + QString::number(conicalGradient->angle());
        break;
    }
    default:
        qWarning() << "QtGradientUtils::styleSheetParameters(): gradient type" << gradient.type() << "not supported!";
        break;
    }

    return result;
}

static QStringList styleSheetStops(const QGradient &gradient)
{
    QStringList result;
    foreach (const QGradientStop &stop, gradient.stops())
    {
        const QColor color = stop.second;

        const QString stopDescription = QLatin1String("stop:") + QString::number(stop.first) + QLatin1String(" rgba(")
                + QString::number(color.red()) + QLatin1String(", ")
                + QString::number(color.green()) + QLatin1String(", ")
                + QString::number(color.blue()) + QLatin1String(", ")
                + QString::number(color.alpha()) + QLatin1Char(')');
        result << stopDescription;
    }

    return result;
}

QString styleSheetCode(const QGradient &gradient)
{
    QStringList gradientParameters;
    gradientParameters << styleSheetParameters(gradient) << styleSheetStops(gradient);

    return styleSheetFillName(gradient) + QLatin1Char('(') + gradientParameters.join(QLatin1String(", ")) + QLatin1Char(')');
}

typedef struct
{
    qreal pos;
    QColor color;
} GRAD_STRU;

static QGradient::Type stringToGradientType(const QString &name)
{
    if (name == QLatin1String("LinearGradient"))
        return QGradient::LinearGradient;
    if (name == QLatin1String("RadialGradient"))
        return QGradient::RadialGradient;
    if (name == QLatin1String("ConicalGradient"))
        return QGradient::ConicalGradient;
    return QGradient::NoGradient;
}
static QGradient::Spread stringToGradientSpread(const QString &name)
{
    if (name == QLatin1String("PadSpread"))
        return QGradient::PadSpread;
    if (name == QLatin1String("RepeatSpread"))
        return QGradient::RepeatSpread;
    if (name == QLatin1String("ReflectSpread"))
        return QGradient::ReflectSpread;
    return QGradient::PadSpread;
}
static QGradient::CoordinateMode stringToGradientCoordinateMode(const QString &name)
{
    if (name == QLatin1String("LogicalMode"))
        return QGradient::LogicalMode;
    if (name == QLatin1String("StretchToDeviceMode"))
        return QGradient::StretchToDeviceMode;
    if (name == QLatin1String("ObjectBoundingMode"))
        return QGradient::ObjectBoundingMode;
    return QGradient::StretchToDeviceMode;
}
static GRAD_STRU getPosColorFromStr(const QString & pstr)
{
    GRAD_STRU grad_stru;
    QString posval = pstr.mid(0,pstr.indexOf("rgba"));
    grad_stru.pos = posval.trimmed().toDouble();
    posval = pstr.mid(pstr.indexOf('(')+1,pstr.indexOf(')')-pstr.indexOf('(')-1);
    QStringList vallist = posval.split(QLatin1String(", "));
    int r,g,b,a;
    r = vallist.at(0).toInt();
    g = vallist.at(1).toInt();
    b = vallist.at(2).toInt();
    a = 255;
    grad_stru.color = QColor(qRgba(r,g,b,a));
    return grad_stru;
}

int brushStyleToIndex(Qt::BrushStyle st)
{
    switch (st)
    {
    case Qt::NoBrush: return 0;
    case Qt::SolidPattern: return 1;
    case Qt::Dense1Pattern: return 2;
    case Qt::Dense2Pattern: return 3;
    case Qt::Dense3Pattern: return 4;
    case Qt::Dense4Pattern: return 5;
    case Qt::Dense5Pattern: return 6;
    case Qt::Dense6Pattern: return 7;
    case Qt::Dense7Pattern: return 8;
    case Qt::HorPattern: return 9;
    case Qt::VerPattern: return 10;
    case Qt::CrossPattern: return 11;
    case Qt::BDiagPattern: return 12;
    case Qt::FDiagPattern: return 13;
    case Qt::DiagCrossPattern: return 14;
    case Qt::LinearGradientPattern: return 15;
    case Qt::RadialGradientPattern: return 16;
    case Qt::ConicalGradientPattern: return 17;
    case Qt::TexturePattern: return 24;
    default: break;
    }
    return 0;
}

Qt::BrushStyle brushStyleIndexToStyle(int brushStyleIndex)
{
    switch (brushStyleIndex)
    {
    case 0: return Qt::NoBrush;
    case 1: return Qt::SolidPattern;
    case 2: return Qt::Dense1Pattern;
    case 3: return Qt::Dense2Pattern;
    case 4: return Qt::Dense3Pattern;
    case 5: return Qt::Dense4Pattern;
    case 6: return Qt::Dense5Pattern;
    case 7: return Qt::Dense6Pattern;
    case 8: return Qt::Dense7Pattern;
    case 9: return Qt::HorPattern;
    case 10: return Qt::VerPattern;
    case 11: return Qt::CrossPattern;
    case 12: return Qt::BDiagPattern;
    case 13: return Qt::FDiagPattern;
    case 14: return Qt::DiagCrossPattern;
    case 15: return Qt::LinearGradientPattern;
    case 16: return Qt::RadialGradientPattern;
    case 17: return Qt::ConicalGradientPattern;
    case 24: return Qt::TexturePattern;
    case 100:return Qt::LinearGradientPattern;
    default: break;
    }
    return Qt::NoBrush;
}

QGradient stringToGradient(const QString &prostr)
{
    QGradient gradient = QLinearGradient();
	if (!prostr.contains('('))
		return gradient;

    QString gradtype = "LinearGradient";
    QString gradset = prostr.mid(prostr.indexOf('(') + 1,prostr.indexOf("stop") - prostr.indexOf('(')-1);
    QString colorset = prostr.mid(prostr.indexOf("stop")+5,prostr.lastIndexOf(')') - prostr.indexOf("stop")-1);
    QString spreadstr = "PadSpread";
    QStringList gradlist = gradset.split(QLatin1String(", "));
    QStringList colorlist = colorset.split("stop:");

    if(prostr.left(prostr.indexOf('(')).trimmed() == "qlineargradient")
        gradtype = "LinearGradient";
    else if (prostr.left(prostr.indexOf('(')).trimmed() == "qradialgradient")
        gradtype = "RadialGradient";
    else if (prostr.left(prostr.indexOf('(')).trimmed() == "qconicalgradient")
        gradtype = "ConicalGradient";


    if(gradlist.at(0).trimmed().contains("pad"))
        spreadstr = "PadSpread";
	else if (gradlist.at(0).trimmed().contains("repeat"))
        spreadstr = "RepeatSpread";
	else if (gradlist.at(0).trimmed().contains("reflect"))
        spreadstr = "ReflectSpread";

    const QGradient::Type type = stringToGradientType(gradtype);
    const QGradient::Spread spread = stringToGradientSpread(spreadstr);
    const QGradient::CoordinateMode mode = stringToGradientCoordinateMode("StretchToDeviceMode");

    if (type == QGradient::LinearGradient)
    {
        QLinearGradient g;
        g.setStart(gradlist.at(1).mid(gradlist.at(1).indexOf(':')+1).toDouble(), gradlist.at(2).mid(gradlist.at(2).indexOf(':')+1).toDouble());
        g.setFinalStop(gradlist.at(3).mid(gradlist.at(3).indexOf(':')+1).toDouble(), gradlist.at(4).mid(gradlist.at(4).indexOf(':')+1).toDouble());
        gradient = g;
    } else if (type == QGradient::RadialGradient)
    {
        QRadialGradient g;
        g.setCenter(gradlist.at(1).mid(gradlist.at(1).indexOf(':')+1).toDouble(), gradlist.at(2).mid(gradlist.at(2).indexOf(':')+1).toDouble());
        g.setFocalPoint(gradlist.at(3).mid(gradlist.at(3).indexOf(':')+1).toDouble(), gradlist.at(4).mid(gradlist.at(4).indexOf(':')+1).toDouble());
        g.setRadius(gradlist.at(5).mid(gradlist.at(5).indexOf(':')+1).toDouble());
        gradient = g;
    } else if (type == QGradient::ConicalGradient)
    {
        QConicalGradient g;
        g.setCenter(gradlist.at(0).mid(gradlist.at(0).indexOf(':')+1).toDouble(), gradlist.at(1).mid(gradlist.at(1).indexOf(':')+1).toDouble());
        g.setAngle(gradlist.at(2).mid(gradlist.at(2).indexOf(':')+1).toDouble());
        gradient = g;
    }
    GRAD_STRU grdpos;
    for (QStringList::size_type idx = 0;idx < colorlist.size();idx++)
    {
        grdpos = getPosColorFromStr(colorlist.at(idx));
        gradient.setColorAt(grdpos.pos,grdpos.color);
    }

    gradient.setSpread(spread);
    gradient.setCoordinateMode(mode);

    return gradient;
}

QString CGFunc::GetBrushStyleText(const QBrush &brush,const QString &pic_name )
{
    QStringList styleText;
    styleText.clear();

    styleText.push_back(QString("QBrushPPT::styleIndex:%1").arg(brushStyleToIndex(brush.style())));

    QColor color = brush.color();
    styleText.push_back(QString("Color[%1,%2,%3]").arg(color.red()).arg(color.green()).arg(color.blue()));

    styleText.push_back(QString("back_pixmap:%1").arg(pic_name));

    Qt::BrushStyle stylev = brush.style();
    if((stylev == Qt::LinearGradientPattern) || (stylev == Qt::RadialGradientPattern) || (stylev == Qt::ConicalGradientPattern))
        styleText.push_back(styleSheetCode(*brush.gradient()));
    else
    {
        styleText.push_back("Gradient");
    }

    QString textStr = styleText.join(";");
    return textStr;
}

QBrush CGFunc::SetBrushByText(const QString & text)
{
    QBrush brush;
    if(!text.startsWith("QBru")) return brush;

    QStringList styleText = text.split(";");
    if(styleText.size()<4) return brush;

    QString styleIdxStr = styleText.at(0);
    styleIdxStr=styleIdxStr.right(styleIdxStr.length()-22);//replace("QBrushPPT::styleIndex:","");
    if(styleIdxStr.length()<1) styleIdxStr = "0";
    Qt::BrushStyle stylev = brushStyleIndexToStyle(styleIdxStr.toInt());    

    if((stylev == Qt::LinearGradientPattern) || (stylev == Qt::RadialGradientPattern) || (stylev == Qt::ConicalGradientPattern))
        return QBrush(stringToGradient(styleText.at(3)));
    else if (stylev == Qt::TexturePattern)
    {
        QString picName = styleText.at(2);
        picName=picName.right(picName.length()-12);//replace("back_pixmap:","");
        if(picName.trimmed().length()>1)
        {
            GetFilePathName(PATH_TYPE_PIXMAP,picName,picName);
            return QBrush(QPixmap(picName));
        }
    }
	else{
		brush.setStyle(stylev);
	}
    QString colorText = styleText.at(1);
    if(colorText.split(",").size() <3)
        return brush;
    else
    {
        colorText=colorText.right(colorText.length()-6);//.replace("Color[","");
        colorText.chop(1);
        QStringList colorRgb = colorText.split(",");
        if(colorRgb.size() < 3) return brush;
        brush.setColor(QColor::fromRgb(colorRgb.at(0).toInt(),colorRgb.at(1).toInt(),colorRgb.at(2).toInt()));
    }

    return brush;
}

QString CGFunc::GetTextureFileName(const QString &text)
{
    QStringList styleText = text.split(";");
    if(styleText.size() <4) return "";

    QString picName = styleText.at(2);
	picName = picName.right(picName.length() - 12);
    //picName.replace("back_pixmap:","");
    return picName;
}

QString CGFunc::Json2Str(const QJsonObject &jsonObj,QJsonDocument::JsonFormat format)
{
    QJsonDocument jdoc(jsonObj);
    return jdoc.toJson(format);
}

QString CGFunc::Json2Str(const QJsonArray &jsonArray, QJsonDocument::JsonFormat format)
{
	QJsonDocument jdoc(jsonArray);
	return jdoc.toJson(format);
}

QJsonObject CGFunc::Str2Json(const QString& jsonStr)
{
    QJsonObject jobj;
    QJsonParseError error;
    if(jsonStr.isEmpty()) return jobj;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
            if (jsonDoc.isObject())
            {
                jobj = jsonDoc.object();
            }
            else if (jsonDoc.isArray())
            {
                QJsonArray jsonArrays = jsonDoc.array();
                foreach(QJsonValue jsonv, jsonArrays)
                {
                    jobj = jsonv.toObject();
                }
            }
        }
    }
    else {
        gError("---Str2Json--error--%s",jsonStr.toLocal8Bit().data());
    }
    return jobj;
}

QJsonArray CGFunc::Str2JsonArray(const QString& jsonStr)
{
    QJsonObject jobj;
    QJsonArray jsonArrays;
    QJsonParseError error;
    if(jsonStr.isEmpty()) return jsonArrays;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
            if (jsonDoc.isObject())
            {
                jobj = jsonDoc.object();
                jsonArrays.append(jobj);
            }
            else if (jsonDoc.isArray())
            {
                jsonArrays = jsonDoc.array();
            }
        }
    }
    else {
        gError("---Str2Json--error--%s",jsonStr.toLocal8Bit().data());
    }
    return jsonArrays;
}



//////////////

Q_CORE_EXPORT double qstrtod(const char *s00, char const **se, bool *ok);

static inline bool isDigit(ushort ch)
{
    static quint16 magic = 0x3ff;
    return ((ch >> 4) == 3) && (magic >> (ch & 15));
}

static qreal toDouble(const QChar *&str)
{
    const int maxLen = 255;
    char temp[maxLen+1];
    int pos = 0;

    if (*str == QLatin1Char('-')) {
        temp[pos++] = '-';
        ++str;
    } else if (*str == QLatin1Char('+')) {
        ++str;
    }
    while (isDigit(str->unicode()) && pos < maxLen) {
        temp[pos++] = str->toLatin1();
        ++str;
    }
    if (*str == QLatin1Char('.') && pos < maxLen) {
        temp[pos++] = '.';
        ++str;
    }
    while (isDigit(str->unicode()) && pos < maxLen) {
        temp[pos++] = str->toLatin1();
        ++str;
    }
    bool exponent = false;
    if ((*str == QLatin1Char('e') || *str == QLatin1Char('E')) && pos < maxLen) {
        exponent = true;
        temp[pos++] = 'e';
        ++str;
        if ((*str == QLatin1Char('-') || *str == QLatin1Char('+')) && pos < maxLen) {
            temp[pos++] = str->toLatin1();
            ++str;
        }
        while (isDigit(str->unicode()) && pos < maxLen) {
            temp[pos++] = str->toLatin1();
            ++str;
        }
    }

    temp[pos] = '\0';

    qreal val;
    if (!exponent && pos < 10) {
        int ival = 0;
        const char *t = temp;
        bool neg = false;
        if(*t == '-') {
            neg = true;
            ++t;
        }
        while(*t && *t != '.') {
            ival *= 10;
            ival += (*t) - '0';
            ++t;
        }
        if(*t == '.') {
            ++t;
            int div = 1;
            while(*t) {
                ival *= 10;
                ival += (*t) - '0';
                div *= 10;
                ++t;
            }
            val = ((qreal)ival)/((qreal)div);
        } else {
            val = ival;
        }
        if (neg)
            val = -val;
    } else {
        bool ok = false;
        val = qstrtod(temp, 0, &ok);
    }
    return val;

}
static qreal toDouble(const QString &str, bool *ok = NULL)
{
    const QChar *c = str.constData();
    qreal res = toDouble(c);
    if (ok) {
        *ok = ((*c) == QLatin1Char('\0'));
    }
    return res;
}

static qreal toDouble(const QStringRef &str, bool *ok = NULL)
{
    const QChar *c = str.constData();
    qreal res = toDouble(c);
    if (ok) {
        *ok = (c == (str.constData() + str.length()));
    }
    return res;
}

void pathArcSegment(QPainterPath &path,
                    qreal xc, qreal yc,
                    qreal th0, qreal th1,
                    qreal rx, qreal ry, qreal xAxisRotation)
{
    qreal sinTh, cosTh;
    qreal a00, a01, a10, a11;
    qreal x1, y1, x2, y2, x3, y3;
    qreal t;
    qreal thHalf;

    sinTh = qSin(xAxisRotation * (Q_PI / 180.0));
    cosTh = qCos(xAxisRotation * (Q_PI / 180.0));

    a00 = cosTh * rx;
    a01 = -sinTh * ry;
    a10 = sinTh * rx;
    a11 = cosTh * ry;

    thHalf = 0.5 * (th1 - th0);
    t = (8.0 / 3.0) * qSin(thHalf * 0.5) * qSin(thHalf * 0.5) / qSin(thHalf);
    x1 = xc + qCos(th0) - t * qSin(th0);
    y1 = yc + qSin(th0) + t * qCos(th0);
    x3 = xc + qCos(th1);
    y3 = yc + qSin(th1);
    x2 = x3 + t * qSin(th1);
    y2 = y3 - t * qCos(th1);

    path.cubicTo(a00 * x1 + a01 * y1, a10 * x1 + a11 * y1,
                 a00 * x2 + a01 * y2, a10 * x2 + a11 * y2,
                 a00 * x3 + a01 * y3, a10 * x3 + a11 * y3);
}

inline void parseNumbersArray(const QChar *&str, QVarLengthArray<qreal, 8> &points)
{
    while (str->isSpace())
        ++str;
    while (isDigit(str->unicode()) ||
           *str == QLatin1Char('-') || *str == QLatin1Char('+') ||
           *str == QLatin1Char('.')) {

        points.append(toDouble(str));

        while (str->isSpace())
            ++str;
        if (*str == QLatin1Char(','))
            ++str;


        while (str->isSpace())
            ++str;
    }
}

void pathArc(QPainterPath &path,
             qreal rx,
             qreal ry,
             qreal x_axis_rotation,
             int large_arc_flag,
             int sweep_flag,
             qreal x,
             qreal y,
             qreal curx, qreal cury)
{
    qreal sin_th, cos_th;
    qreal a00, a01, a10, a11;
    qreal x0, y0, x1, y1, xc, yc;
    qreal d, sfactor, sfactor_sq;
    qreal th0, th1, th_arc;
    int i, n_segs;
    qreal dx, dy, dx1, dy1, Pr1, Pr2, Px, Py, check;

    rx = qAbs(rx);
    ry = qAbs(ry);

    sin_th = qSin(x_axis_rotation * (Q_PI / 180.0));
    cos_th = qCos(x_axis_rotation * (Q_PI / 180.0));

    dx = (curx - x) / 2.0;
    dy = (cury - y) / 2.0;
    dx1 = cos_th * dx + sin_th * dy;
    dy1 = -sin_th * dx + cos_th * dy;
    Pr1 = rx * rx;
    Pr2 = ry * ry;
    Px = dx1 * dx1;
    Py = dy1 * dy1;

    check = Px / Pr1 + Py / Pr2;
    if (check > 1) {
        rx = rx * qSqrt(check);
        ry = ry * qSqrt(check);
    }

    a00 = cos_th / rx;
    a01 = sin_th / rx;
    a10 = -sin_th / ry;
    a11 = cos_th / ry;
    x0 = a00 * curx + a01 * cury;
    y0 = a10 * curx + a11 * cury;
    x1 = a00 * x + a01 * y;
    y1 = a10 * x + a11 * y;

    d = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    sfactor_sq = 1.0 / d - 0.25;
    if (sfactor_sq < 0) sfactor_sq = 0;
    sfactor = qSqrt(sfactor_sq);
    if (sweep_flag == large_arc_flag) sfactor = -sfactor;
    xc = 0.5 * (x0 + x1) - sfactor * (y1 - y0);
    yc = 0.5 * (y0 + y1) + sfactor * (x1 - x0);


    th0 = qAtan2(y0 - yc, x0 - xc);
    th1 = qAtan2(y1 - yc, x1 - xc);

    th_arc = th1 - th0;
    if (th_arc < 0 && sweep_flag)
        th_arc += 2 * Q_PI;
    else if (th_arc > 0 && !sweep_flag)
        th_arc -= 2 * Q_PI;

    n_segs = qCeil(qAbs(th_arc / (Q_PI * 0.5 + 0.001)));

    for (i = 0; i < n_segs; i++) {
        pathArcSegment(path, xc, yc,
                       th0 + i * th_arc / n_segs,
                       th0 + (i + 1) * th_arc / n_segs,
                       rx, ry, x_axis_rotation);
    }
}

bool CGFunc::ParsePathData(const QStringRef &dataStr, QPainterPath &path)
{
    qreal x0 = 0, y0 = 0;
    qreal x = 0, y = 0;
    char lastMode = 0;
    QPointF ctrlPt;
    const QChar *str = dataStr.constData();
    const QChar *end = str + dataStr.size();

    while (str != end) {
        while (str->isSpace())
            ++str;
        QChar pathElem = *str;
        ++str;
        QChar endc = *end;
        *const_cast<QChar *>(end) = 0;
        QVarLengthArray<qreal, 8> arg;
        parseNumbersArray(str, arg);
        *const_cast<QChar *>(end) = endc;
        if (pathElem == QLatin1Char('z') || pathElem == QLatin1Char('Z'))
            arg.append(0);
        const qreal *num = arg.constData();
        int count = arg.count();
        while (count > 0) {
            qreal offsetX = x;
            qreal offsetY = y;
            switch (pathElem.unicode()) {
            case 'm': {
                if (count < 2) {
                    num++;
                    count--;
                    break;
                }
                x = x0 = num[0] + offsetX;
                y = y0 = num[1] + offsetY;
                num += 2;
                count -= 2;
                path.moveTo(x0, y0);
                pathElem = QLatin1Char('l');
            }
                break;
            case 'M': {
                if (count < 2) {
                    num++;
                    count--;
                    break;
                }
                x = x0 = num[0];
                y = y0 = num[1];
                num += 2;
                count -= 2;
                path.moveTo(x0, y0);

                pathElem = QLatin1Char('L');
            }
                break;
            case 'z':
            case 'Z': {
                x = x0;
                y = y0;
                count--;
                num++;
                path.closeSubpath();
            }
                break;
            case 'l': {
                if (count < 2) {
                    num++;
                    count--;
                    break;
                }
                x = num[0] + offsetX;
                y = num[1] + offsetY;
                num += 2;
                count -= 2;
                path.lineTo(x, y);

            }
                break;
            case 'L': {
                if (count < 2) {
                    num++;
                    count--;
                    break;
                }
                x = num[0];
                y = num[1];
                num += 2;
                count -= 2;
                path.lineTo(x, y);
            }
                break;
            case 'h': {
                x = num[0] + offsetX;
                num++;
                count--;
                path.lineTo(x, y);
            }
                break;
            case 'H': {
                x = num[0];
                num++;
                count--;
                path.lineTo(x, y);
            }
                break;
            case 'v': {
                y = num[0] + offsetY;
                num++;
                count--;
                path.lineTo(x, y);
            }
                break;
            case 'V': {
                y = num[0];
                num++;
                count--;
                path.lineTo(x, y);
            }
                break;
            case 'c': {
                if (count < 6) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c1(num[0] + offsetX, num[1] + offsetY);
                QPointF c2(num[2] + offsetX, num[3] + offsetY);
                QPointF e(num[4] + offsetX, num[5] + offsetY);
                num += 6;
                count -= 6;
                path.cubicTo(c1, c2, e);
                ctrlPt = c2;
                x = e.x();
                y = e.y();
                break;
            }
            case 'C': {
                if (count < 6) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c1(num[0], num[1]);
                QPointF c2(num[2], num[3]);
                QPointF e(num[4], num[5]);
                num += 6;
                count -= 6;
                path.cubicTo(c1, c2, e);
                ctrlPt = c2;
                x = e.x();
                y = e.y();
                break;
            }
            case 's': {
                if (count < 4) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c1;
                if (lastMode == 'c' || lastMode == 'C' ||
                        lastMode == 's' || lastMode == 'S')
                    c1 = QPointF(2*x-ctrlPt.x(), 2*y-ctrlPt.y());
                else
                    c1 = QPointF(x, y);
                QPointF c2(num[0] + offsetX, num[1] + offsetY);
                QPointF e(num[2] + offsetX, num[3] + offsetY);
                num += 4;
                count -= 4;
                path.cubicTo(c1, c2, e);
                ctrlPt = c2;
                x = e.x();
                y = e.y();
                break;
            }
            case 'S': {
                if (count < 4) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c1;
                if (lastMode == 'c' || lastMode == 'C' ||
                        lastMode == 's' || lastMode == 'S')
                    c1 = QPointF(2*x-ctrlPt.x(), 2*y-ctrlPt.y());
                else
                    c1 = QPointF(x, y);
                QPointF c2(num[0], num[1]);
                QPointF e(num[2], num[3]);
                num += 4;
                count -= 4;
                path.cubicTo(c1, c2, e);
                ctrlPt = c2;
                x = e.x();
                y = e.y();
                break;
            }
            case 'q': {
                if (count < 4) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c(num[0] + offsetX, num[1] + offsetY);
                QPointF e(num[2] + offsetX, num[3] + offsetY);
                num += 4;
                count -= 4;
                path.quadTo(c, e);
                ctrlPt = c;
                x = e.x();
                y = e.y();
                break;
            }
            case 'Q': {
                if (count < 4) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF c(num[0], num[1]);
                QPointF e(num[2], num[3]);
                num += 4;
                count -= 4;
                path.quadTo(c, e);
                ctrlPt = c;
                x = e.x();
                y = e.y();
                break;
            }
            case 't': {
                if (count < 2) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF e(num[0] + offsetX, num[1] + offsetY);
                num += 2;
                count -= 2;
                QPointF c;
                if (lastMode == 'q' || lastMode == 'Q' ||
                        lastMode == 't' || lastMode == 'T')
                    c = QPointF(2*x-ctrlPt.x(), 2*y-ctrlPt.y());
                else
                    c = QPointF(x, y);
                path.quadTo(c, e);
                ctrlPt = c;
                x = e.x();
                y = e.y();
                break;
            }
            case 'T': {
                if (count < 2) {
                    num += count;
                    count = 0;
                    break;
                }
                QPointF e(num[0], num[1]);
                num += 2;
                count -= 2;
                QPointF c;
                if (lastMode == 'q' || lastMode == 'Q' ||
                        lastMode == 't' || lastMode == 'T')
                    c = QPointF(2*x-ctrlPt.x(), 2*y-ctrlPt.y());
                else
                    c = QPointF(x, y);
                path.quadTo(c, e);
                ctrlPt = c;
                x = e.x();
                y = e.y();
                break;
            }
            case 'a': {
                if (count < 7) {
                    num += count;
                    count = 0;
                    break;
                }
                qreal rx = (*num++);
                qreal ry = (*num++);
                qreal xAxisRotation = (*num++);
                qreal largeArcFlag = (*num++);
                qreal sweepFlag = (*num++);
                qreal ex = (*num++) + offsetX;
                qreal ey = (*num++) + offsetY;
                count -= 7;
                qreal curx = x;
                qreal cury = y;
                pathArc(path, rx, ry, xAxisRotation, int(largeArcFlag),
                        int(sweepFlag), ex, ey, curx, cury);

                x = ex;
                y = ey;
            }
                break;
            case 'A': {
                if (count < 7) {
                    num += count;
                    count = 0;
                    break;
                }
                qreal rx = (*num++);
                qreal ry = (*num++);
                qreal xAxisRotation = (*num++);
                qreal largeArcFlag = (*num++);
                qreal sweepFlag = (*num++);
                qreal ex = (*num++);
                qreal ey = (*num++);
                count -= 7;
                qreal curx = x;
                qreal cury = y;
                pathArc(path, rx, ry, xAxisRotation, int(largeArcFlag),
                        int(sweepFlag), ex, ey, curx, cury);

                x = ex;
                y = ey;
            }
                break;
            default:
                return false;
            }
            lastMode = pathElem.toLatin1();
        }
    }
    return true;
}


QVector<qreal> CGFunc::parseNumbersList(const QChar *&str)
{
    QVector<qreal> points;
    if (!str)
        return points;
    points.reserve(32);

    while (str->isSpace())
        ++str;
    while (isDigit(str->unicode()) ||
           *str == QLatin1Char('-') || *str == QLatin1Char('+') ||
           *str == QLatin1Char('.')) {

        points.append(toDouble(str));

        while (str->isSpace())
            ++str;
        if (*str == QLatin1Char(','))
            ++str;

        //eat the rest of space
        while (str->isSpace())
            ++str;
    }

    return points;
}


QMatrix CGFunc::parseTransformationMatrix(const QStringRef &value)
{
    if (value.isEmpty())
        return QMatrix();

    QMatrix matrix;
    const QChar *str = value.constData();
    const QChar *end = str + value.length();

    while (str < end) {
        if (str->isSpace() || *str == QLatin1Char(',')) {
            ++str;
            continue;
        }
        enum State {
            Matrix,
            Translate,
            Rotate,
            Scale,
            SkewX,
            SkewY
        };
        State state = Matrix;
        if (*str == QLatin1Char('m')) {  //matrix
            const char *ident = "atrix";
            for (int i = 0; i < 5; ++i)
                if (*(++str) != QLatin1Char(ident[i]))
                    goto error;
            ++str;
            state = Matrix;
        } else if (*str == QLatin1Char('t')) { //translate
            const char *ident = "ranslate";
            for (int i = 0; i < 8; ++i)
                if (*(++str) != QLatin1Char(ident[i]))
                    goto error;
            ++str;
            state = Translate;
        } else if (*str == QLatin1Char('r')) { //rotate
            const char *ident = "otate";
            for (int i = 0; i < 5; ++i)
                if (*(++str) != QLatin1Char(ident[i]))
                    goto error;
            ++str;
            state = Rotate;
        } else if (*str == QLatin1Char('s')) { //scale, skewX, skewY
            ++str;
            if (*str == QLatin1Char('c')) {
                const char *ident = "ale";
                for (int i = 0; i < 3; ++i)
                    if (*(++str) != QLatin1Char(ident[i]))
                        goto error;
                ++str;
                state = Scale;
            } else if (*str == QLatin1Char('k')) {
                if (*(++str) != QLatin1Char('e'))
                    goto error;
                if (*(++str) != QLatin1Char('w'))
                    goto error;
                ++str;
                if (*str == QLatin1Char('X'))
                    state = SkewX;
                else if (*str == QLatin1Char('Y'))
                    state = SkewY;
                else
                    goto error;
                ++str;
            } else {
                goto error;
            }
        } else {
            goto error;
        }


        while (str < end && str->isSpace())
            ++str;
        if (*str != QLatin1Char('('))
            goto error;
        ++str;
        QVarLengthArray<qreal, 8> points;
        parseNumbersArray(str, points);
        if (*str != QLatin1Char(')'))
            goto error;
        ++str;

        if(state == Matrix) {
            if(points.count() != 6)
                goto error;
            matrix = matrix * QMatrix(points[0], points[1],
                                      points[2], points[3],
                                      points[4], points[5]);
        } else if (state == Translate) {
            if (points.count() == 1)
                matrix.translate(points[0], 0);
            else if (points.count() == 2)
                matrix.translate(points[0], points[1]);
            else
                goto error;
        } else if (state == Rotate) {
            if(points.count() == 1) {
                matrix.rotate(points[0]);
            } else if (points.count() == 3) {
                matrix.translate(points[1], points[2]);
                matrix.rotate(points[0]);
                matrix.translate(-points[1], -points[2]);
            } else {
                goto error;
            }
        } else if (state == Scale) {
            if (points.count() < 1 || points.count() > 2)
                goto error;
            qreal sx = points[0];
            qreal sy = sx;
            if(points.count() == 2)
                sy = points[1];
            matrix.scale(sx, sy);
        } else if (state == SkewX) {
            if (points.count() != 1)
                goto error;
            const qreal deg2rad = qreal(0.017453292519943295769);
            matrix.shear(qTan(points[0]*deg2rad), 0);
        } else if (state == SkewY) {
            if (points.count() != 1)
                goto error;
            const qreal deg2rad = qreal(0.017453292519943295769);
            matrix.shear(0, qTan(points[0]*deg2rad));
        }
    }
  error:
    return matrix;
}

////
QImage CGFunc::ConvertColor(const QString& pix, uint srcColor, const QString& desColor)
{
    //if(desColor=="transparent")
    QImage image(pix);
    image = image.convertToFormat(QImage::Format_ARGB32);
    union myrgb
    {
        uint rgba;
        uchar rgba_bits[4];
    };
    myrgb* mybits =(myrgb*) image.bits();
    int len = image.width()*image.height();
    while(len --> 0)
    {
        mybits->rgba_bits[3] = (mybits->rgba== srcColor)?0:255;
        mybits++;
    }
    return image;
}


std::string CGFunc::getPinyinFromUTF8(const char* strName)
{
	QString qstr = strName;
	QTextCodec *codec = QTextCodec::codecForName("GB18030");
	QByteArray ba = codec->fromUnicode(qstr);
	if (ba.size() > 0)
	{
		const char* sAnsi = ba.data();
		return getPinyinFromAnsi(sAnsi);
	}
	return "";
}

int CGFunc::FirstLetter(int nCode, std::string& strLetter)
{
	if (nCode >= 1601 && nCode < 1637) strLetter = "a";
	else if (nCode >= 1637 && nCode < 1833) strLetter = "b";
	else if (nCode >= 1833 && nCode < 2078) strLetter = "c";
	else if (nCode >= 2078 && nCode < 2274) strLetter = "d";
	else if (nCode >= 2274 && nCode < 2302) strLetter = "e";
	else if (nCode >= 2302 && nCode < 2433) strLetter = "f";
	else if (nCode >= 2433 && nCode < 2594) strLetter = "g";
	else if (nCode >= 2594 && nCode < 2787) strLetter = "h";
	else if (nCode >= 2787 && nCode < 3106) strLetter = "j";
	else if (nCode >= 3106 && nCode < 3212) strLetter = "k";
	else if (nCode >= 3212 && nCode < 3472) strLetter = "l";
	else if (nCode >= 3472 && nCode < 3635) strLetter = "m";
	else if (nCode >= 3635 && nCode < 3722) strLetter = "n";
	else if (nCode >= 3722 && nCode < 3730) strLetter = "o";
	else if (nCode >= 3730 && nCode < 3858) strLetter = "p";
	else if (nCode >= 3858 && nCode < 4027) strLetter = "q";
	else if (nCode >= 4027 && nCode < 4086) strLetter = "r";
	else if (nCode >= 4086 && nCode < 4390) strLetter = "s";
	else if (nCode >= 4390 && nCode < 4558) strLetter = "t";
	else if (nCode >= 4558 && nCode < 4684) strLetter = "w";
	else if (nCode >= 4684 && nCode < 4925) strLetter = "x";
	else if (nCode >= 4925 && nCode < 5249) strLetter = "y";
	else if (nCode >= 5249 && nCode < 5590) strLetter = "z";
	else return -1;
	return 0;
}
std::string CGFunc::getPinyinFromAnsi(std::string strName)
{
	std::string strResult;
	bool bStartByLetter = false;

	unsigned char ucHigh, ucLow;
	int  nCode;
	std::string strRet;

	strResult.clear();

	if (strName.size() == 0)
		return false;

	if ((unsigned char)strName[0] < 0x80)
	{
		bStartByLetter = true;
	}

	for (size_t i = 0; i < strName.size(); i++)
	{
		if ((unsigned char)strName[i] < 0x80)
		{
			strResult += strName[i];
			continue;
		}

		ucHigh = (unsigned char)strName[i];
		ucLow = (unsigned char)strName[i + 1];
		if (ucHigh < 0xa1 || ucLow < 0xa1)
			continue;
		else
			// Treat code by section-position as an int type parameter,  
			// so make following change to nCode.  
			nCode = (ucHigh - 0xa0) * 100 + ucLow - 0xa0;

		FirstLetter(nCode, strRet);
		strResult += strRet;
		i++;///一次跳过2个字符///
	}

	//return bStartByLetter;
	transform(strResult.begin(), strResult.end(), strResult.begin(), (int(*)(int))tolower);
	return strResult;
}
