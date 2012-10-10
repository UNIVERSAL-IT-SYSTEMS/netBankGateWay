#include	<sys/types.h>
#include	<sys/timeb.h>
#include	<stdio.h>
#include	<stdlib.h>
#include 	<stdarg.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/ipc.h>
#include	<sys/msg.h>
#include	<sys/shm.h>
#include	<sys/errno.h>
#include	<sys/socket.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<netdb.h>
#include	<signal.h>
#include	<errno.h>
#include	<time.h>
#include	<math.h>
#include 	<setjmp.h>

#define		SA		struct sockaddr
#define		TIMEOUT	120


#define 	DATE_ONLY	1
#define		TIME_ONLY	2

#define	 YBSLOG	__FILE__,__LINE__

#define	SUCC	0
#define FAIL	-1
#ifndef _S_TOOL_H_
#define _S_TOOL_H_

#ifdef  __cplusplus
extern  "C"
{
#endif


int YbsLog( char *fname, int fline, const char *format, ... );

#ifdef  __cplusplus
}
#endif


#endif
