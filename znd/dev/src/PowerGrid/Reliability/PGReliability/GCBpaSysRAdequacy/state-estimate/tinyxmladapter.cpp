#include "tinyxmladapter.h"
//#ifdef _WIN32
//#include "..\..\src\Win32_Interop\win32fixes.h"
//#endif
#ifdef _OFF_T_DEFINED
typedef long _off_t;                    /* file offset value */
#endif

#include <tinyxml.h>

TinyXmlAdapter::TinyXmlAdapter()
{
}


TinyXmlAdapter::~TinyXmlAdapter()
{
}


void TinyXmlAdapter::open(const char *fileName)
{

}

extern "C" TinyXmlAdapter *tx_create() {
	return new TinyXmlAdapter();
}

extern "C" void tx_destory(TinyXmlAdapter* p) {
	delete p;
}

extern "C" void tx_open(TinyXmlAdapter* p, const char *fileName) // wrapper function
{
	return p->open(fileName);
}

extern "C" TiXmlDocument *tx_load(const char *fileName) // wrapper function
{
	TiXmlDocument *doc = new TiXmlDocument();
	doc->LoadFile(fileName);
	return doc;
}