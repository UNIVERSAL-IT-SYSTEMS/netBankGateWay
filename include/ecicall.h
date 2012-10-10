/* -lcclaix */

#ifndef _EBCCLI_H
#define _EBCCLI_H

#define CICS_AIX
#include <cics_eci.h>

#define _EBCCLI extern

/*
 *	eci_call:	CICS客户端通讯发送和接收函数
 *	输入参数：	servername -- CICS server的名称
 *			commbuf -- 通讯缓冲区字符串（指针）
 *			len -- 通讯缓冲区中的字符串实际长度
 *			prg -- 被调用的CICS server中的程序名
 *			timeout -- 超时时间（秒）
 *	输出：		返回值 -- 0：成功
 *			         -1：失败
 *			commbuf -- 当调用成功时，服务器返回的报文字符串
 */

_EBCCLI int eci_call(	char *servername,
			char *commbuf, 
			cics_sshort_t len,
			cics_char_t *prg, 
			cics_sshort_t timeout);


/*
 *	get_ebcli_errmsg:当上面的调用失败时，使用本函数得到CICS错误信息
 *	输入参数：	无
 *	输出：	返回值 -- 错误信息（当上面的函数返回-1时，返回的信息才有意义）
 */

_EBCCLI char	*get_eci_call_err();

#endif
