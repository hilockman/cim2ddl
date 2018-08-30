#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <jni.h>

//	将C字符转为JAVA字符，其中在OnLoad中的SetLocal十分关键
jstring CString2JString( JNIEnv * env, const char* lpszInStrCpp)
{
	jsize	nLen;
	wchar_t	wszBuf[65536];

	nLen=(jsize)mbstowcs(NULL, lpszInStrCpp, 0);
	mbstowcs(wszBuf, lpszInStrCpp, nLen);
	return env->NewString((jchar*)wszBuf, nLen);
}

//	将JAVA字符转为C字符，其中在OnLoad中的SetLocal十分关键
int JString2CString(JNIEnv * env, jstring jstrInJava, char* lpszOutStrCpp)
{
	unsigned char	bRet=0;

	const	jchar* lpszStr = env -> GetStringChars(jstrInJava, &bRet );
	wcstombs(lpszOutStrCpp, (wchar_t*)lpszStr, 65535);
	env -> ReleaseStringChars(jstrInJava, lpszStr );

	return 1;
}
