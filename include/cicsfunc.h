#ifndef _CICSFUNC_H
#define _CICSFUNC_H

/*---------------------------------------------------
 * 用于在CICS Server程序中记录TDQ
 *	char*	tdq:	TDQ名称
 *	int	level:	日志记录级别
 *	char*	fmt:	格式串
 *	va_del	:	可选参数
 *   返回值：
 *		0	成功
 *		-1	失败
 *-------------------------------------------------*/
extern	int	write_tdq(char* tdq, int level, char* fmt, ...);

extern	int	check_respcode(unsigned long respcode);

#endif
