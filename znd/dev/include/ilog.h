#ifndef iLOG_HEADER______________
#define iLOG_HEADER______________
#include "zndexp.h"


#include "log.h"

#ifdef DEBUG 
#define  log_trace(__LOG_FORMAT__,...) eco::log_out_t(0,LOG_TRACE,__FILE__,__FUNCTION__,__LINE__,__LOG_FORMAT__,##__VA_ARGS__)  

/*Informational events most useful for developers to debug application.  By default information will be print to terminal(display).*/
#define  log_debug(__LOG_FORMAT__,...)  eco::log_out_t(0,LOG_DEBUG,__FILE__,__FUNCTION__,__LINE__,__LOG_FORMAT__,##__VA_ARGS__)  
#else
#define  log_trace(__LOG_FORMAT__,...) 
#define  log_debug(__LOG_FORMAT__,...)
#endif

/*Mainly useful to represent current progress of application.*/
#define  log_info(__LOG_FORMAT__,...)  eco::log_out_t(0,LOG_INFO,__FILE__,__FUNCTION__,__LINE__,__LOG_FORMAT__,##__VA_ARGS__)  

/*Information representing errors in application but application will keep running.*/
#define  log_warn(__LOG_FORMAT__,...)  eco::log_out_t(0,LOG_WARN,__FILE__,__FUNCTION__,__LINE__,__LOG_FORMAT__,##__VA_ARGS__)  

/*Error information but will continue application to keep running.*/
#define  log_error(__LOG_FORMAT__,...)  eco::log_out_t(0,LOG_ERROR,__FILE__,__FUNCTION__,__LINE__,__LOG_FORMAT__,##__VA_ARGS__)  

#ifndef WIN32
#include <signal.h>
inline void elog_comman_on_exit(int sgval)
{
	log_info("Capture kill singnal:%d !", sgval);
#ifdef _IBM_GCC
	_exit(0);
#else
	exit(0);
#endif

}

inline int elog_comman_reg_unix(int argc, char **argv, const char *date, const char *time)
{
#ifndef _IBM 
#ifndef _IBM_GCC
	signal(SIGINT, elog_comman_on_exit);
	signal(SIGTERM, elog_comman_on_exit);
#endif
#endif

	return  eco::log_reg(argc, argv, date, time);
}


inline void elog_comman_on__exit_(int sgval)
{
	log_info("Capture kill singnal:%d !", sgval);
	_exit(0);
}

inline int elog_comman_reg_unix__exit_(int argc, char **argv, const char *date, const char *time)
{
#ifndef _IBM 
#ifndef _IBM_GCC
	signal(SIGINT, elog_comman_on__exit_);
	signal(SIGTERM, elog_comman_on__exit_);
#endif
#endif

	return  eco::log_reg(argc, argv, date, time);
}

#define  log_reg(argc,argv)  elog_comman_reg_unix(argc,argv,__DATE__,__TIME__)
#define  log_reg_nosignal(argc,argv) elog_comman_reg_unix__exit_(argc,argv,__DATE__,__TIME__)
#else
#define  log_reg(argc,argv)  eco::log_reg(argc,argv,__DATE__,__TIME__)
#define  log_reg_nosignal(argc,argv)  eco::log_register(argc,argv,__DATE__,__TIME__)
#endif



#define  log_reg_v2(argc,argv,STD_OUT_LEVEL)    eco::log_reg_v2(argc,argv,__DATE__,__TIME__,STD_OUT_LEVEL)

#endif
