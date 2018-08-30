#include "stdafx.h"
#include <Windows.h>
#include "../3rdParty/oci/include/occi.h"

//#define		_INDEBUG

OCIEnv     	*m_pEnvHandle;	//环境句柄
OCIError   	*m_pErrHandle;	//错误句柄
OCIServer  	*m_pSrvHandle;	//服务器句柄
OCISvcCtx  	*m_pSvcHandle;	//服务句柄
OCISession 	*m_pSessionHandle;	//会话句柄
OCIStmt    	*m_pStmtExec;
OCIStmt    	*m_pStmtAll;

static	void Log(char* pformat, ...)
{
	va_list args;
	va_start( args, pformat );

	char	szTempPath[260], szFileName[260];
	FILE*	fp;

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
	GetTempPath(260, szTempPath);
#else
	strcpy(szTempPath, "/tmp");
#endif

	sprintf(szFileName, "%s/OracleOci.log", szTempPath);
	fp=fopen(szFileName, "a");
	if (fp != NULL)
	{
		vfprintf(fp, pformat, args);

		fflush(fp);
		fclose(fp);
	}

	va_end(args);
}

int InitOracleDBEnviroment(const char* lpszDBServer, const char* lpszDBUserName, const char* lpszDBPassWord)
{
#ifdef	_INDEBUG
	return 1;
#endif

	//初始化进程
	sword		sRet;
	sb4			nLen;

	sRet=OCIInitialize((OCI_THREADED | OCI_OBJECT), 
		(dvoid*)0, 
		(dvoid *(*)(dvoid *, size_t))0, 
		(dvoid *(*)(dvoid*, dvoid*, size_t))0, 
		(void (*)(dvoid *, dvoid *))0);
	if (sRet)
	{
		Log("初始化进程失败!: %d\n", sRet);
		return 0;
	}
	else
	{
		Log("进程初始化成功\n");
	}
	//初始化环境
	sRet=OCIEnvInit((OCIEnv**)&m_pEnvHandle, OCI_DEFAULT, (size_t)0, (dvoid **)0);
	if (sRet)
	{
		Log("初始化环境失败!: %d\n", sRet);
		return 0;
	}
	else
	{
		Log("环境初始化成功\n");
	}
	//分配句柄
	if (OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pErrHandle, OCI_HTYPE_ERROR, (size_t)0, (dvoid**)0) ||
		OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pSrvHandle, OCI_HTYPE_SERVER, (size_t)0, (dvoid**)0) ||
		OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pSvcHandle, OCI_HTYPE_SVCCTX, (size_t)0, (dvoid**)0))
	{
		Log("分配句柄错误!\n");
		return 0;
	}
	else
	{
		Log("分配句柄成功\n");
	}
	//连接服务
	nLen=(sb4)strlen(lpszDBServer);
	sRet=OCIServerAttach(m_pSrvHandle, m_pErrHandle, (text*)lpszDBServer, nLen, 0);
	if (sRet)
	{
		char errbuf[256];
		sb4  errcode;
		OCIErrorGet(m_pErrHandle, (ub4)1, (text *)NULL, &errcode, (text *)errbuf, (ub4)sizeof(errbuf), OCI_HTYPE_ERROR);
		Log("连接服务错误(OCIServerAttach):%s\n", errbuf);
		return 0;
	}
	else
	{
		Log("服务连接成功\n");
	}
	//Set attribute server context in the service context
	if (OCIAttrSet((dvoid*)m_pSvcHandle, OCI_HTYPE_SVCCTX, (dvoid*)m_pSrvHandle, (ub4)0, OCI_ATTR_SERVER, (OCIError*)m_pErrHandle) ||
		OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pSessionHandle, OCI_HTYPE_SESSION, (size_t)0, (dvoid**)0) ||
		OCIAttrSet((dvoid*)m_pSessionHandle, OCI_HTYPE_SESSION, (dvoid*)lpszDBUserName, (ub4)strlen(lpszDBUserName), OCI_ATTR_USERNAME, m_pErrHandle) ||
		OCIAttrSet((dvoid*)m_pSessionHandle, OCI_HTYPE_SESSION, (dvoid*)lpszDBPassWord, (ub4)strlen(lpszDBPassWord), OCI_ATTR_PASSWORD, m_pErrHandle))
	{
		Log("Set attribute错误!\n");
		return 0;
	}
	else
	{
		Log("Set attribute成功\n");
	}
	//开始会话
// 	if (OCISessionBegin(m_pSvcHandle, m_pErrHandle, m_pSessionHandle, OCI_CRED_RDBMS, (ub4)OCI_DEFAULT) ||
// 		OCIAttrSet((dvoid*)m_pSvcHandle, (ub4)OCI_HTYPE_SVCCTX, (dvoid *)m_pSessionHandle, (ub4)0, (ub4)OCI_ATTR_SESSION, m_pErrHandle) ||
// 		OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pStmtExec, OCI_HTYPE_STMT, (size_t)0, (dvoid **)0) ||
// 		OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pStmtAll, OCI_HTYPE_STMT, (size_t)0, (dvoid**)0))
// 	{
// 		Log("会话出错!\n");
// 		return 0;
// 	}
	if (OCISessionBegin(m_pSvcHandle, m_pErrHandle, m_pSessionHandle, OCI_CRED_RDBMS, (ub4)OCI_DEFAULT))
	{
		Log("OCISessionBegin出错!\n");
		return 0;
	}
	if (OCIAttrSet((dvoid*)m_pSvcHandle, (ub4)OCI_HTYPE_SVCCTX, (dvoid *)m_pSessionHandle, (ub4)0, (ub4)OCI_ATTR_SESSION, m_pErrHandle))
	{
		Log("OCIAttrSet出错!\n");
		return 0;
	}
	if (OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pStmtExec, OCI_HTYPE_STMT, (size_t)0, (dvoid **)0))
	{
		Log("OCIHandleAlloc Exec出错!\n");
		return 0;
	}
	if (OCIHandleAlloc((dvoid*)m_pEnvHandle, (dvoid**)&m_pStmtAll, OCI_HTYPE_STMT, (size_t)0, (dvoid **)0))
	{
		Log("OCIHandleAlloc All出错!\n");
		return 0;
	}

	Log("数据库连接成功\n");

	return 1;
}
//SIMPLIFIED CHINESE_CHINA.ZHS16GBK
void ExitOracleDBEnviroment(void)
{
#ifdef	_INDEBUG
	return;
#endif
	// 结束会话 ...
	OCISessionEnd(m_pSvcHandle, m_pErrHandle, m_pSessionHandle, (ub4)0);
	OCIServerDetach(m_pSrvHandle, m_pErrHandle, (ub4)OCI_DEFAULT);

	if (m_pStmtExec)
		OCIHandleFree((dvoid *)m_pStmtExec, OCI_HTYPE_STMT);
	if (m_pStmtAll)
		OCIHandleFree((dvoid *)m_pStmtAll, OCI_HTYPE_STMT);

	// 释放句柄 ...
	if (m_pSrvHandle)
		OCIHandleFree((dvoid*)m_pSrvHandle, (ub4)OCI_HTYPE_SERVER);
	if (m_pSvcHandle)
		OCIHandleFree((dvoid*)m_pSvcHandle, (ub4)OCI_HTYPE_SVCCTX);
	if (m_pErrHandle)
		OCIHandleFree((dvoid*)m_pErrHandle, (ub4)OCI_HTYPE_ERROR);
	if (m_pSessionHandle)
		OCIHandleFree((dvoid*)m_pSessionHandle, (ub4)OCI_HTYPE_SESSION);
	if (m_pEnvHandle)
		OCIHandleFree((dvoid*)m_pEnvHandle, (ub4)OCI_HTYPE_ENV);
}

int CheckOCIError(sword swStatus)
{
	char errbuf[256];
	sb4  errcode;

	switch (swStatus)
	{
	case OCI_SUCCESS:
		return 0;
	case OCI_SUCCESS_WITH_INFO:
		if (m_pErrHandle) 
		{
			OCIErrorGet(m_pErrHandle, (ub4)1, (text *)NULL, &errcode, (text *)errbuf, (ub4)sizeof(errbuf), OCI_HTYPE_ERROR);
			Log("OCI信息(InfCode=%d) InfMesg=%s", errcode, errbuf);
		}
		break;
	case OCI_NEED_DATA:
		break;
	case OCI_NO_DATA:
		break;
	case OCI_ERROR:
		if (m_pErrHandle) 
		{
			OCIErrorGet(m_pErrHandle, (ub4)1, (text *)NULL, &errcode, (text *)errbuf, (ub4)sizeof(errbuf), OCI_HTYPE_ERROR);
			if (errcode == 1405)
			{
				//Log("OCI信息(InfCode=%d) InfMesg=%s", errcode, errbuf);
				swStatus=OCI_SUCCESS_WITH_INFO;
			}
			else
			{
				Log("OCI错误(ErrCode=%d) ErrMesg=%s", errcode, errbuf);
			}
		}
		break;
	case OCI_INVALID_HANDLE:
		break;
	case OCI_STILL_EXECUTING:
		break;
	case OCI_CONTINUE:
		break;
	default:
		break;
	}

	return swStatus;
}

int ExecuteSQL(const char *lpszSQL)
{
#ifdef	_INDEBUG
	Log("%s\n", lpszSQL);
	return 1;
#else
	Log("%s\n", lpszSQL);
#endif

	if (CheckOCIError(OCIStmtPrepare(m_pStmtExec, m_pErrHandle, (text*)lpszSQL, (ub4)strlen(lpszSQL), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT)) == OCI_ERROR)
	{
		Log("ExecuteSQL OCIStmtPrepare错误 [SQL=%s]", lpszSQL);
		return 0;
	}

	if (CheckOCIError(OCIStmtExecute( m_pSvcHandle, m_pStmtExec, m_pErrHandle, (ub4)1, (ub4)0, (CONST OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_COMMIT_ON_SUCCESS)) == OCI_ERROR)
	{
		Log("ExecuteSQL OCIStmtExecute错误 [SQL=%s]", lpszSQL);
		return 0;
	}

	return 1;
}

int CheckSQLExist(const char* lpszSQL)
{
	int			nRetCode;
	int			nValue;
	OCIDefine*  pSelDefine;

#ifdef	_INDEBUG
	return 0;
#endif

	nValue=0;

	if (CheckOCIError(OCIStmtPrepare(m_pStmtAll, m_pErrHandle, (text*)lpszSQL, (ub4)strlen(lpszSQL), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT)) == OCI_ERROR)
	{
		Log("CheckSQLExist OCIStmtPrepare错误 [SQL=%s]", lpszSQL);
		return -1;
	}

	if (CheckOCIError(OCIDefineByPos(m_pStmtAll, &pSelDefine, m_pErrHandle, 1, (dvoid*)&nValue,	(sb4)4,		(ub2)SQLT_INT,	(dvoid*)0, (ub2*)0, (ub2*)0, (ub4)OCI_DEFAULT)) == OCI_ERROR)
	{
		Log("CheckSQLExist OCIDefineByPos错误 [SQL=%s]", lpszSQL);
		return -1;
	}

	if (CheckOCIError(OCIStmtExecute(m_pSvcHandle, m_pStmtAll, m_pErrHandle, (ub4)0, (ub4)0, (OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_DEFAULT)) == OCI_ERROR)
	{
		Log("CheckSQLExist OCIStmtExecute错误 [SQL=%s]", lpszSQL);
		return -1;
	}

	do
	{
		nRetCode=CheckOCIError(OCIStmtFetch(m_pStmtAll, m_pErrHandle, (ub4)1, (ub4)OCI_FETCH_NEXT, (ub4)OCI_DEFAULT));
		if (nRetCode == OCI_ERROR)
		{
			Log("CheckSQLExist OCIStmtFetch错误 [SQL=%s]", lpszSQL);
			return -1;
		}
	}
	while (nRetCode != OCI_NO_DATA);

	return nValue;
}

