#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "error.h"
#include "miscfunc.h"
#include "cicsfunc.h"
#include "netbank_mid.h"
#include "trans_macro.h"

extern	int	return_flag;
extern	int	newsock;

void	return_info(int newsock, char* fmt, ...)
{
	int	ret;
	va_list	args;
	char	msg[MESSAGE_LENGTH];

	va_start(args, fmt);
	vsprintf(msg, fmt, args);
	va_end(args);

	ret = tcp_svr_send(newsock, msg, strlen(msg), 10);
/*
	ret = tcp_svr_recv(newsock, msg, 4, 10);
*/

	return ;
}

void	write_log(int level, char* fmt, ...)
{
	int	len;
	va_list	args;
	char	msg[LEN_MID_PROC_BUF];
/*
        return;
*/
	va_start(args, fmt);
	vsprintf(msg, fmt, args);
	va_end(args);

	flog(level, msg);

	fprintf(stderr, "%s\n", msg);
/*

	if (return_flag == 1)
		return_info(newsock, msg);
*/
	return;
}

/* End of this file */
