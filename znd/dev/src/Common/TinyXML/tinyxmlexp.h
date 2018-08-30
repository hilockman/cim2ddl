#ifndef TINYXMLEXP_H
#define TINYXMLEXP_H

#if defined(WIN32) && defined(TINYXML_EXPORTS)
#define TINYXML_EXP __declspec(dllexport)
#else
#define TINYXML_EXP
#endif
#define TIXML_USE_STL
#endif