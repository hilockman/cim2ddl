#include "stdafx.h"
#include <windows.h>
#include <math.h>
#include "string.h"
#include "stdlib.h"
#include "NumericFormular.h"

namespace	NumericFormular
{
	static	char*	lpszLogFileName="NumericFormular.log";
	CNumericFormular::CNumericFormular(void)
	{
	}

	CNumericFormular::~CNumericFormular(void)
	{
	}

	void	CNumericFormular::ClearLog()
	{
		char	szTempPath[260], szFileName[260];

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		GetTempPathA(260, szTempPath);
#else
		strcpy(szTempPath, "/tmp");
#endif

		sprintf(szFileName, "%s/%s", szTempPath, lpszLogFileName);
		FILE*	fp=fopen(szFileName, "w");
		fflush(fp);
		fclose(fp);
	}

	void	CNumericFormular::Log(char* pformat, ...)
	{
#ifdef	_DEBUG
		va_list args;
		va_start( args, pformat );


		char	szTempPath[260], szFileName[260];
		FILE*	fp;

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		GetTempPath(260, szTempPath);
#else
		strcpy(szTempPath, "/tmp");
#endif

		sprintf(szFileName, "%s/%s", szTempPath, lpszLogFileName);
		fp=fopen(szFileName, "a");
		if (fp != NULL)
		{
			vfprintf(fp, pformat, args);

			fflush(fp);
			fclose(fp);
		}

		va_end(args);
#endif
	}


	int CNumericFormular::SetFormular(const std::string strFormular)
	{
		int		bRet=0;

		m_strFormular=strFormular;

		m_OperatorArray.clear();
		m_VariableArray.clear();

		if (CheckValidate(strFormular) != 0)
		{
			Log("Error CheckValidate Expression=%s\n", strFormular.c_str());
			return bRet;
		}

		bRet=ResolveOperator();
		if (!bRet)
		{
			Log("解析Operator错误\n");
			return 0;
		}

		bRet=ResolveVariable();
		if (!bRet)
		{
			Log("解析Variable错误\n");
			return 0;
		}

		// 	register int	i;
		// 	if (bRet)
		// 	{
		// 		for (i=0; i<(int)m_OperatorArray.size(); i++)
		// 		{
		// 			TRACE("        OperatorStack[%d/%d]=%s\n", i, m_OperatorArray.size(), m_OperatorArray[i].strOperator.c_str());
		// 		}
		// 	}
		// 	TRACE("    %s\n", m_strFormular.c_str());
		// 	if (bRet)
		// 	{
		// 		for (i=0; i<(int)m_VariableArray.size(); i++)
		// 		{
		// 			TRACE("        Variable[%d/%d]=%s\n", i, m_VariableArray.size(), m_VariableArray[i].strVariable.c_str());
		// 		}
		// 	}
		//	Sleep(10);

		return 1;
	}

	int CNumericFormular::CheckValidate(const std::string strExpression)
	{
		register int	i;
		int	bRet=0;

		std::stack<char> szStack;
		while (!szStack.empty())	szStack.pop();
		for (i=0; i<(int)strExpression.length(); i++)
		{
			if (strExpression[i] == '(')
			{
				szStack.push('(');
			}
			if (strExpression[i]==')')
			{
				if (szStack.empty())
				{
					return 1;	//right bracket if more.
				}
				else
				{
					szStack.pop();
				}
			}
		}
		if (!szStack.empty())
		{
			while (!szStack.empty())	szStack.pop();
			return 2;	//left bracket is more.
		}
		return bRet;
	}

	int CNumericFormular::ResolveOperator(void)
	{
		int				nChar, nCharFlag, nLevel;
		tagSFOperator	oprBuf;

		InitializeSFOperator(oprBuf);

		m_OperatorArray.clear();

		nLevel=nChar=nCharFlag=0;
		while (nChar < (int)m_strFormular.length())
		{
			if (m_strFormular[nChar] == '\'')
			{
				if (nCharFlag == 0)
					nCharFlag=1;
				else
					nCharFlag=0;

				nChar++;
			}
			else if (m_strFormular[nChar] == '(')
			{
				nLevel += FormularBracketsDepth;
				m_strFormular[nChar++]='[';
			}
			else if (m_strFormular[nChar] == ')')
			{
				nLevel -= FormularBracketsDepth;
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && (stricmp(m_strFormular.substr(nChar, 2).c_str(), "&&") == 0 || stricmp(m_strFormular.substr(nChar, 2).c_str(), "||") == 0))
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel;
				oprBuf.strOperator=m_strFormular.substr(nChar, 2);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 5).c_str(), " and ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel;
				oprBuf.strOperator="&&";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), " or ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel;
				oprBuf.strOperator="||";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 8).c_str(), " is not ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel;
				oprBuf.strOperator="!=";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), " is ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel;
				oprBuf.strOperator="==";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && 
				(stricmp(m_strFormular.substr(nChar, 2).c_str(), ">=") == 0 ||
				stricmp(m_strFormular.substr(nChar, 2).c_str(), "<=") == 0 ||
				stricmp(m_strFormular.substr(nChar, 2).c_str(), "==") == 0 ||
				stricmp(m_strFormular.substr(nChar, 2).c_str(), "!=") == 0 ||
				stricmp(m_strFormular.substr(nChar, 2).c_str(), "<>") == 0))
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+1;
				oprBuf.strOperator=m_strFormular.substr(nChar, 2);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && m_strFormular[nChar] == '=')
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+1;
				oprBuf.strOperator="==";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && m_strFormular[nChar] == '!')
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+1;
				oprBuf.strOperator="!";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && (m_strFormular[nChar] == '>' || m_strFormular[nChar] == '<'))
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+1;
				oprBuf.strOperator=m_strFormular.substr(nChar, 1);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && (m_strFormular[nChar] == '+' || m_strFormular[nChar] == '-'))
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+2;
				oprBuf.strOperator=m_strFormular.substr(nChar, 1);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && (m_strFormular[nChar] == '*' || m_strFormular[nChar] == '/'))
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+3;
				oprBuf.strOperator=m_strFormular.substr(nChar, 1);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
			}
			else if (stricmp(m_strFormular.substr(nChar, 3).c_str(), "sin") == 0 ||
				stricmp(m_strFormular.substr(nChar, 3).c_str(), "cos") == 0 ||
				stricmp(m_strFormular.substr(nChar, 3).c_str(), "tan") == 0 ||
				stricmp(m_strFormular.substr(nChar, 3).c_str(), "log") == 0 ||
				stricmp(m_strFormular.substr(nChar, 3).c_str(), "abs") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator=m_strFormular.substr(nChar, 3);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "sqrt") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator=m_strFormular.substr(nChar, 4);
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), "not ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+1;
				oprBuf.strOperator="!";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';

				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 5).c_str(), "like ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="like";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 9).c_str(), "substring") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="substring";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';

				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
				m_strFormular[nChar++]='[';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 6).c_str(), "exists") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="exists";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 8).c_str(), " not in ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="notin";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), " in ") == 0)
			{
				oprBuf.nOperatorType=SFormular_TwoVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="in";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
				m_strFormular[nChar++]=']';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 5).c_str(), "case ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="case";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='@';
				m_strFormular[nChar++]='@';
				m_strFormular[nChar++]='@';
				m_strFormular[nChar++]='@';
				m_strFormular[nChar++]='@';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 6).c_str(), "count ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="count";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='$';
				m_strFormular[nChar++]='C';
				m_strFormular[nChar++]='N';
				m_strFormular[nChar++]='T';
				m_strFormular[nChar++]=' ';
				m_strFormular[nChar++]=' ';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), "avg ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="avg";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='$';
				m_strFormular[nChar++]='A';
				m_strFormular[nChar++]='V';
				m_strFormular[nChar++]='G';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), "sum ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="avg";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='$';
				m_strFormular[nChar++]='S';
				m_strFormular[nChar++]='U';
				m_strFormular[nChar++]='M';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), "min ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="avg";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='$';
				m_strFormular[nChar++]='M';
				m_strFormular[nChar++]='I';
				m_strFormular[nChar++]='N';
			}
			else if (nCharFlag == 0 && stricmp(m_strFormular.substr(nChar, 4).c_str(), "max ") == 0)
			{
				oprBuf.nOperatorType=SFormular_OneVarOperator;
				oprBuf.nLevel=nLevel+5;
				oprBuf.strOperator="avg";
				m_OperatorArray.push_back(oprBuf);

				m_strFormular[nChar++]='$';
				m_strFormular[nChar++]='M';
				m_strFormular[nChar++]='A';
				m_strFormular[nChar++]='X';
			}
			else
			{
				nChar++;
			}
		}

		return 1;
	}

	int CNumericFormular::ResolveVariable(void)
	{
		int				nChar, nFlag;
		tagSFVariable	varBuf;

		varBuf.bNull=0;
		varBuf.bConstDigit=0;
		varBuf.bConstString=0;
		varBuf.nVartype=0;
		varBuf.nDataType=VariableType_None;
		varBuf.strVariable.clear();
		varBuf.strValue.clear();
		varBuf.strValueArray.clear();

		m_VariableArray.clear();

		nChar=nFlag=0;
		while (nChar < (int)m_strFormular.length())
		{
			if (m_strFormular[nChar] == '\'')
			{
				nFlag=(nFlag == 0) ? 1 : 0;
				nChar++;
			}
			else if (m_strFormular[nChar] == ' ' && nFlag == 0)
			{
				m_strFormular.erase(nChar, 1);
			}
			else
			{
				nChar++;
			}
		}
		//	以上是格式化公式，消除空格

		nChar=0;
		nFlag=SFormular_NormalVariable;
		while (nChar < (int)m_strFormular.length())
		{
			if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "$cnt") == 0)
			{
				nFlag=SFormular_FuncVariable;
				varBuf.nDataType=VariableType_Numeric;
				nChar += 4;
			}
			else if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "$avg") == 0)
			{
				varBuf.nDataType=VariableType_Numeric;
				nFlag=SFormular_FuncVariable;
				nChar += 4;
			}
			else if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "$sum") == 0)
			{
				varBuf.nDataType=VariableType_Numeric;
				nFlag=SFormular_FuncVariable;
				nChar += 4;
			}
			else if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "$max") == 0)
			{
				varBuf.nDataType=VariableType_Numeric;
				nFlag=SFormular_FuncVariable;
				nChar += 4;
			}
			else if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "$min") == 0)
			{
				varBuf.nDataType=VariableType_Numeric;
				nFlag=SFormular_FuncVariable;
				nChar += 4;
			}
			else if (m_strFormular[nChar] == '[')	//	运算符或括号
			{
				nFlag=SFormular_NormalVariable;
				nChar++;
			}
			else if (m_strFormular[nChar] == '@')	//	运算符或括号
			{
				nFlag=SFormular_CaseVariable;
				nChar++;
			}
			else if (m_strFormular[nChar] == ']')	//	运算符或括号
			{
				nFlag=SFormular_VectorVariable;
				nChar++;
			}
			else
			{
				int		nVarChar;
				char	szVarChar[1024];

				memset(szVarChar, 0, 1024);

				varBuf.bNull=0;
				varBuf.bConstDigit=0;
				varBuf.bConstString=0;
				varBuf.nVartype=0;
				varBuf.nDataType=VariableType_String;
				varBuf.strVariable.clear();
				varBuf.strValue.clear();
				varBuf.strValueArray.clear();

				if (stricmp(m_strFormular.substr(nChar, 4).c_str(), "NULL") == 0)
				{
					varBuf.bNull=1;
					nChar+=4;

					varBuf.strVariable="NULL";
					varBuf.strValue=varBuf.strVariable;
					varBuf.nVartype=0;
					m_VariableArray.push_back(varBuf);
				}
				else if (m_strFormular[nChar] == '\'')
				{
					varBuf.nDataType=VariableType_String;
					varBuf.bConstString=1;
					nChar++;

					nVarChar=0;
					while (nChar < (int)m_strFormular.length() && m_strFormular[nChar] != '\'')
					{
						if (nVarChar < 1024)
							szVarChar[nVarChar++] = m_strFormular[nChar];
						nChar++;
					}
					if (nVarChar < 1024)
						szVarChar[nVarChar++] = '\0';

					nChar++;
					varBuf.strVariable=szVarChar;
					varBuf.strValue=varBuf.strVariable;
					varBuf.nVartype=nFlag;
					m_VariableArray.push_back(varBuf);
				}
				else if (m_strFormular[nChar] != ' ')
				{
					if (nFlag == SFormular_NormalVariable || nFlag == SFormular_VectorVariable)
					{
						if (isdigit(m_strFormular[nChar]))
						{
							varBuf.bConstDigit=1;
							varBuf.nDataType=VariableType_Numeric;
						}

						nVarChar=0;
						while (nChar < (int)m_strFormular.length() && m_strFormular[nChar] != '[' && m_strFormular[nChar] != ']' && m_strFormular[nChar] != ' ')
						{
							if (varBuf.bConstDigit && !isdigit(m_strFormular[nChar]) && (m_strFormular[nChar] != '.'))
							{
								varBuf.bConstDigit=0;
								varBuf.nDataType=VariableType_String;
							}
							if (nVarChar < 1024)
								szVarChar[nVarChar++] = m_strFormular[nChar];
							nChar++;
						}
						if (nVarChar < 1024)
							szVarChar[nVarChar++] = '\0';

						varBuf.strVariable=szVarChar;
						varBuf.strValue=varBuf.strVariable;
						varBuf.nVartype=nFlag;
						m_VariableArray.push_back(varBuf);
					}
					else if (nFlag == SFormular_CaseVariable)
					{
						nVarChar=0;
						while (nChar < (int)m_strFormular.length() && m_strFormular[nChar] != '[' && m_strFormular[nChar] != ']' && m_strFormular[nChar] != ' ')
						{
							if (nVarChar < 1024)
								szVarChar[nVarChar++] = m_strFormular[nChar];
							nChar++;
						}
						if (nVarChar < 1024)
							szVarChar[nVarChar++] = '\0';

						varBuf.strVariable=szVarChar;
						varBuf.strValue=varBuf.strVariable;
						varBuf.nVartype=nFlag;
						m_VariableArray.push_back(varBuf);
					}
					else if (nFlag == SFormular_FuncVariable)
					{
						nVarChar=0;
						while (nChar < (int)m_strFormular.length() && m_strFormular[nChar] != '[' && m_strFormular[nChar] != ']' && m_strFormular[nChar] != ' ')
						{
							if (nVarChar < 1024)
								szVarChar[nVarChar++] = m_strFormular[nChar];
							nChar++;
						}
						if (nVarChar < 1024)
							szVarChar[nVarChar++] = '\0';

						varBuf.strVariable=szVarChar;
						varBuf.strValue=varBuf.strVariable;
						varBuf.nVartype=nFlag;
						m_VariableArray.push_back(varBuf);
					}
					else
					{
						nChar++;
					}
				}
				else
				{
					nChar++;
				}
			}
		}
		return 1;
	}

	std::string	CNumericFormular::Calculate()
	{
		register int	i;
		std::stack<tagSFOperator>	OperatorStack;
		std::stack<tagSFVariable>	VariableStack;

		while (!OperatorStack.empty())	OperatorStack.pop();
		while (!VariableStack.empty())	VariableStack.pop();

		for (i=0; i<(int)m_OperatorArray.size(); i++)
			OperatorStack.push(m_OperatorArray[i]);
		for (i=0; i<(int)m_VariableArray.size(); i++)
			VariableStack.push(m_VariableArray[i]);

		std::string	strRet=Calculate(OperatorStack, VariableStack);

		while (!OperatorStack.empty())	OperatorStack.pop();
		while (!VariableStack.empty())	VariableStack.pop();

		return strRet;
	}

	std::string CNumericFormular::Calculate(std::stack<tagSFOperator>& OperatorStack, std::stack<tagSFVariable>& VariableStack)
	{
		std::string	strReturn;
		tagSFVariable	varBuf;

		strReturn.clear();

		if (OperatorStack.empty())
		{
			if (VariableStack.size() == 1)
			{
				varBuf=VariableStack.top();
				return varBuf.strValue;
			}
			else
			{
				while (!VariableStack.empty())
				{
					varBuf=VariableStack.top();
					VariableStack.pop();
				}
				Log("    OperatorStack Empty VarStack No Variable\n");
				return strReturn;
			}
		}

		std::stack<tagSFOperator>	tmpOprStack;
		tagSFOperator	oprBuf1, oprBuf2;

		std::stack<tagSFVariable>	tmpVarStack;
		tagSFVariable	varBuf1, varBuf2;

		oprBuf1=OperatorStack.top();						//	获得第一个运算符
		OperatorStack.pop();
		if (!OperatorStack.empty())
		{
			oprBuf2=OperatorStack.top();					//	获得第二个运算符
			while (oprBuf2.nLevel >= oprBuf1.nLevel)			//	比较运算符级别
			{
				tmpOprStack.push(oprBuf1);
				if (oprBuf1.nOperatorType == SFormular_TwoVarOperator)		//		如果是二元运算符，则该运算符后运算变量伴随运算符
				{
					if (!VariableStack.empty())
					{
						varBuf1=VariableStack.top();
						VariableStack.pop();
						tmpVarStack.push(varBuf1);
					}
				}

				memcpy(&oprBuf1, &oprBuf2, sizeof(tagSFOperator));

				OperatorStack.pop();
				if (!OperatorStack.empty())
				{
					oprBuf2=OperatorStack.top();
				}
				else
				{
					break;
				}
			}
		}

		if (oprBuf1.nOperatorType == SFormular_OneVarOperator)
		{
			if (VariableStack.empty())
			{
				Log("    Calculate 1Val VarStack No Variable\n");
				return strReturn;
			}
			varBuf1=VariableStack.top();
			VariableStack.top().strValue=Computing(oprBuf1, varBuf1);
		}
		else
		{
			if (VariableStack.empty())
			{
				Log("    Calculate 2Val-Left VarStack No Variable\n");
				return strReturn;
			}
			varBuf2=VariableStack.top();
			VariableStack.pop();
			if (VariableStack.empty())
			{
				Log("    Calculate 2Val-Right VarStack No Variable\n");
				return strReturn;
			}
			varBuf1=VariableStack.top();

			VariableStack.top().strValue=Computing(oprBuf1, varBuf1, varBuf2);
		}
		while (!tmpOprStack.empty())
		{
			oprBuf1=tmpOprStack.top();
			tmpOprStack.pop();
			OperatorStack.push(oprBuf1);
		}
		while (!tmpVarStack.empty())
		{
			varBuf1=tmpVarStack.top();
			tmpVarStack.pop();
			VariableStack.push(varBuf1);
		}

		while (!tmpOprStack.empty())	tmpOprStack.pop();
		while (!tmpVarStack.empty())	tmpVarStack.pop();

		return Calculate(OperatorStack, VariableStack);
	}

	std::string CNumericFormular::Computing(const tagSFOperator& Operator, const tagSFVariable& Variable)
	{
		char	szReturn[gnSQLCharLen];

		if (stricmp(Variable.strValue.c_str(), "NULL") == 0)
			return "NULL";

		double	fVal=atof(Variable.strValue.c_str());
		double	fRet=atof(Variable.strValue.c_str());

		if (stricmp(Operator.strOperator.c_str(), "-") == 0)
		{
			fRet=-fVal;
		}
		else if (stricmp(Operator.strOperator.c_str(), "!") == 0 || stricmp(Operator.strOperator.c_str(), "not") == 0)
		{
			fRet=((int)fVal == 0) ? 1 : 0;
		}
		else if (stricmp(Operator.strOperator.c_str(), "sin") == 0)
		{
			fRet=sin(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "cos") == 0)
		{
			fRet=cos(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "tan") == 0)
		{
			fRet=tan(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "log") == 0)
		{
			fRet=log10(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "sqrt") == 0)
		{
			fRet=sqrt(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "abs") == 0)
		{
			fRet=fabs(fVal);
		}
		else if (stricmp(Operator.strOperator.c_str(), "substring") == 0)
		{
			strcpy(szReturn, Variable.strValue.c_str());
			if (strstr(Variable.strVariable.c_str(), ", ") != NULL)
			{
				register int	i;
				char*	lpszToken;
				std::vector<std::string>	strEleArray;
				int		nIniChar, nCharNum;

				strcpy(szReturn, Variable.strVariable.c_str());

				strEleArray.clear();
				lpszToken=strtok(szReturn, ", ");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, ", ");
				}

				if (strEleArray.size() == 3)
				{
					nIniChar=gnCharSetLen*(atoi(strEleArray[1].c_str())-1);
					if (nIniChar < 0)	nIniChar=0;
					nCharNum=gnCharSetLen*atoi(strEleArray[2].c_str());

					i=0;
					while (i < nCharNum && (int)Variable.strValue.length() > i+nIniChar)
					{
						szReturn[i]=Variable.strValue[i+nIniChar];
						i++;
					}
					szReturn[i]='\0';

					return szReturn;
				}
			}

			return szReturn;
		}
		else if (stricmp(Operator.strOperator.c_str(), "exists") == 0)
		{
			fRet=(int)Variable.strValueArray.size();
		}
		else if (stricmp(Operator.strOperator.c_str(), "case") == 0 ||
			stricmp(Operator.strOperator.c_str(), "count") == 0 ||
			stricmp(Operator.strOperator.c_str(), "avg") == 0 ||
			stricmp(Operator.strOperator.c_str(), "sum") == 0 ||
			stricmp(Operator.strOperator.c_str(), "max") == 0 ||
			stricmp(Operator.strOperator.c_str(), "min") == 0)
		{
			return Variable.strValue;
		}

		sprintf(szReturn, "%f", fRet);
		return szReturn;
	}

	std::string CNumericFormular::Computing(const tagSFOperator& Operator, const tagSFVariable& VarL, const tagSFVariable& VarR)
	{
		register int	i;
		int		nReturn;
		char	szReturn[gnSQLCharLen];
		double	fCal;
		double	fLeft, fRight;

		fCal=0;
		fLeft =atof(VarL.strValue.c_str());
		fRight=atof(VarR.strValue.c_str());
		if (stricmp(Operator.strOperator.c_str(), "&&") == 0 || stricmp(Operator.strOperator.c_str(), "and") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=(fLeft != 0 && fRight != 0) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "||") == 0 || stricmp(Operator.strOperator.c_str(), "or") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=(fLeft != 0 || fRight != 0) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "=") == 0 || stricmp(Operator.strOperator.c_str(), "==") == 0)
		{
			if (VarL.bNull || VarR.bNull)
			{
				fCal=(VarL.strValue == VarR.strValue) ? 1 : 0;
			}
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft == fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue == VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "!=") == 0 || stricmp(Operator.strOperator.c_str(), "<>") == 0)
		{
			if (VarL.bNull || VarR.bNull)
			{
				fCal=(VarL.strValue != VarR.strValue) ? 1 : 0;
			}
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft != fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue != VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), ">=") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft >= fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue >= VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "<=") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft <= fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue <= VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), ">") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft > fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue > VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "<") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (VarL.nDataType == VariableType_Numeric || VarR.nDataType == VariableType_Numeric)
					fCal=(fLeft < fRight) ? 1 : 0;
				else
					fCal=(VarL.strValue < VarR.strValue) ? 1 : 0;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "^") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=pow(fLeft, fRight);
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "+") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=fLeft+fRight;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "-") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=fLeft-fRight;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "*") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				fCal=fLeft*fRight;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "/") == 0)
		{
			if (VarL.bNull || VarR.bNull)
				return "NULL";
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				if (fabs(fRight) > 0.0000001)
				{
					fCal=fLeft/fRight;
				}
				else
				{
					fCal=0;
				}
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "like") == 0)
		{
			if (VarL.bNull || VarR.bNull)
			{
				return "NULL";
			}
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				int		nChar, nReturn;
				char	szChar1[1024], szChar2[1024];

				memset(szReturn, 0, gnSQLCharLen);
				if (VarR.strValue.empty() || VarL.strValue.empty())
					return szReturn;

				strcpy(szChar1, VarL.strValue.c_str());
				strlwr(szChar1);

				if (VarR.strValue[0] == '%' && VarR.strValue[VarR.strValue.length()-1] == '%')
				{
					nChar=0;
					for (i=1; i<(int)VarR.strValue.length()-1; i++)
					{
						szChar2[nChar++]=VarR.strValue[i];
					}
					szChar2[nChar]='\0';
					strlwr(szChar2);

					if (strstr(szChar1, szChar2) != NULL)
					{
						strcpy(szReturn, "1");
					}
					else
					{
						strcpy(szReturn, "0");
					}
					return szReturn;
				}
				else if (VarR.strValue[0] == '%')
				{
					strcpy(szChar2, VarR.strValue.c_str());
					strlwr(szChar2);

					nReturn=1;
					for (i=0; i<(int)strlen(szChar2); i++)
					{
						if (szChar2[strlen(szChar2)-1-i] == '%')
							break;
						if (strlen(szChar1)-1-i < 0 || strlen(szChar2)-1-i < 0)
						{
							nReturn=0;
							break;
						}
						if (szChar1[strlen(szChar1)-1-i] != szChar2[strlen(szChar2)-1-i])
						{
							nReturn=0;
							break;
						}
					}

					sprintf(szReturn, "%d", nReturn);
					return szReturn;
				}
				else if (VarR.strValue[VarR.strValue.length()-1] == '%')
				{
					strcpy(szChar2, VarR.strValue.c_str());
					strlwr(szChar2);

					nReturn=1;
					for (i=0; i<(int)strlen(szChar2); i++)
					{
						if (szChar2[i] == '%')
							break;

						if (i >= (int)strlen(szChar1) || i >= (int)strlen(szChar2))
						{
							nReturn=0;
							break;
						}
						if (szChar1[i] != szChar2[i])
						{
							nReturn=0;
							break;
						}
					}

					sprintf(szReturn, "%d", nReturn);
					return szReturn;
				}
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "in") == 0)
		{
			if (VarL.bNull || VarR.bNull)
			{
				return "NULL";
			}
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				nReturn=0;
				for (i=0; i<(int)VarR.strValueArray.size(); i++)
				{
					if (VarL.strValue == VarR.strValueArray[i])
					{
						nReturn=1;
						break;
					}
				}
				sprintf(szReturn, "%d", nReturn);
				return szReturn;
			}
		}
		else if (stricmp(Operator.strOperator.c_str(), "notin") == 0)
		{
			if (VarL.bNull || VarR.bNull)
			{
				return "NULL";
			}
			else
			{
				if (stricmp(VarL.strValue.c_str(), "NULL") == 0 || stricmp(VarR.strValue.c_str(), "NULL") == 0)
					return "NULL";

				nReturn=1;
				for (i=0; i<(int)VarR.strValueArray.size(); i++)
				{
					if (VarL.strValue == VarR.strValueArray[i])
					{
						nReturn=0;
						break;
					}
				}
				sprintf(szReturn, "%d", nReturn);
				return szReturn;
			}
		}

		sprintf(szReturn, "%f", fCal);
		return szReturn;
	}

	int CNumericFormular::ResolveFormularType(void)
	{
		register int	i;
		for (i=0; i<(int)m_VariableArray.size(); i++)
		{
			if (m_VariableArray[i].bConstDigit)
				return VariableType_Numeric;
			else if (m_VariableArray[i].bConstString)
				return VariableType_String;
		}
		for (i=0; i<(int)m_OperatorArray.size(); i++)
		{
			if (stricmp(m_OperatorArray[i].strOperator.c_str(), "substring") == 0)
				return VariableType_String;
			else if (m_VariableArray[i].bConstString)
				return VariableType_Numeric;
		}
		return 0;
	}
}
