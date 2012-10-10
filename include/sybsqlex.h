/************************************************************
 *                                                          *
 *  sybsqlex.h -   header file for Embedded SQL/C programs  *
 *                                                          *
************************************************************/
#ifndef _SQLOK
#define	_SQLOK	0
#endif

#ifndef SQLOK
#define SQLOK	( sqlca.sqlcode == _SQLOK )
#endif

#ifndef SQLERR
#define SQLERR	(( sqlca.sqlcode != _SQLOK )&&(sqlca.sqlcode!=100))
#endif

#ifndef SQLCODE
#define SQLCODE	(sqlca.sqlcode)
#endif

/*#define SQLNOTFOUND ( SQLCODE == 100 )*/
#ifndef DEBUG 
#define DEBUG 1
#endif
