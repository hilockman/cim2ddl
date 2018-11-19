

#ifndef EXPORT_P_H
#define EXPORT_P_H 


#ifndef G_DECL_EXPORT
# ifdef WIN32
#define G_DECL_EXPORT __declspec(dllexport)
# else
#define G_DECL_EXPORT 
# endif
#endif

#ifndef G_DECL_IMPORT
# ifdef WIN32
#define G_DECL_IMPORT __declspec(dllimport)
# else
#define G_DECL_IMPORT 
# endif
#endif


#ifdef DLL_OUT
#define DLL_CLASS G_DECL_EXPORT
#else
#define DLL_CLASS G_DECL_IMPORT
#endif


#endif
