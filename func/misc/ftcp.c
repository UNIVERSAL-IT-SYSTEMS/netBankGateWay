/*-------------------------------------
 *
 * SOCKET通讯库函数
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>
#include "error.h"

#define MAX_CONNECTION 20

#ifdef SCO_PLAT
extern	int	errno;			/* Global error number */
extern	int	h_errno;		/* Global error number */
#endif
static	char	errmsg[300];

/*-----------------------------------------------------------------
 * tcp_err : Return the error message when socket operate
 *----------------------------------------------------------------*/
char *
tcp_err(void)
{
	return errmsg;
}

/*-----------------------------------------------------------------
 * tcp_cli_open : Establish the connect to server
 * hostname : remote system name or ip address (defined locally)
 * portname : remote port name or port number  (defined locally)
 * attention: the hostname and portname must be defined in 
 * 		/etc/hosts and /etc/services
 * return : socket descriptor 
 *		< 0 error
 *----------------------------------------------------------------*/
int
tcp_cli_open(char *hostname, char *portname)
{
	struct hostent  	*h;
	struct servent		*s;
	struct sockaddr_in	sin;
	int	sock;

	if (hostname ==  NULL) {
		strcpy(errmsg, "\"host\" must NOT be null!");
		return EC_TCP_NULL_HOST_ERROR;
	}
	if (portname == NULL) {
		strcpy(errmsg, "\"port\" must NOT be null!");
		return EC_TCP_NULL_PORT_ERROR;
	}

	memset(&sin, 0, sizeof(sin));
	
	h = gethostbyname(hostname);
	if (h == NULL) {
		/* inet_aton(hostname, &sin.sin_addr.s_addr); */
		/* 输入的hostname是一个点分型的IP地址 */
		sin.sin_addr.s_addr = inet_addr(hostname);
	}
	else
		memcpy(&sin.sin_addr, h->h_addr, h->h_length);

	s = getservbyname(portname, "tcp");
	if (s == NULL)
		sin.sin_port = htons((short)atoi(portname));
	else
		sin.sin_port = s->s_port;
	sin.sin_family = AF_INET;

	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		sprintf(errmsg, "socket : %s", strerror(errno));
		return EC_TCP_SOCKET_ERROR; 
	}

	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		close(sock);
		sprintf(errmsg, "connect : %s", strerror(errno));
		return EC_TCP_CONNECT_ERROR;
	}

	return sock;
}

/*------------------------------------------------------------------
 * tcp_cli_send : Send message to server
 * sock : opened socket return by tcp_cli_open 
 * mesg : message
 * len  : message length
 * return : 0  - success
 *          <0 - failed
 *------------------------------------------------------------------*/
int
tcp_cli_send(int sock, char *mesg, int len, int timeout)
{
	int	ret;
	int	nfds	= 1;
	struct	timeval	tv;
	fd_set	writefds;

	/* 设置超时时间 */
	if (timeout <= 0) {
		tv.tv_sec  = 0;
		tv.tv_usec = 0;
	} else {
		tv.tv_sec = timeout;
		tv.tv_usec = 0;
	}

	/* 设置nfds = 1， 检查当前sock */
	nfds = sock + 1;

	/* 初始化writefds, 并将当前sock加入 */
	FD_ZERO(&writefds);
	FD_SET(sock, &writefds);

	ret = select(nfds, NULL, &writefds, NULL, &tv);
	if (ret < 0) {
		sprintf(errmsg, "select : %s", strerror(errno));
		return EC_TCP_SELECT_ERROR;
	} else if (ret == 0) {		/* 超时时间到 */
		sprintf(errmsg, "select : 超时时间到");
		return EC_TCP_TIME_OUT_ERROR;
	}
	
	/* 异常错误 */
	if (!FD_ISSET(sock, &writefds)) {
		sprintf(errmsg, "select : 异常错误");
		return EC_TCP_ABNORMAL_ERROR;
	}

	ret = write(sock, mesg, len);

	if (ret != len) {
		sprintf(errmsg, "write : %s", strerror(errno));
		return EC_TCP_WRITE_ERROR;
	}

	return ret;
}

/*-------------------------------------------------------------------
 * tcp_cli_recv : Receive message from server
 * sock : opened socket return by tcp_cli_open
 * mesg : message
 * len  : expect length
 * return :>0 - success
 *         <0 - failed
 *------------------------------------------------------------------*/
int
tcp_cli_recv(int sock, char *mesg, int len, int timeout)
{
	int	ret;
	int	i;
	int	nfds	= 1;
	struct	timeval	tv;
	fd_set	readfds;
	int	readlen = 0; 

	/* 设置超时时间 */
	if (timeout <= 0) {
		tv.tv_sec  = 0;
		tv.tv_usec = 0;
	} else {
		tv.tv_sec = timeout;
		tv.tv_usec = 0;
	}
	
	while (1) {
		/* 设置nfds = 1， 检查当前sock */
		nfds = sock + 1;

		/* 初始化readfds, 并将当前sock加入 */
		FD_ZERO(&readfds);
		FD_SET(sock, &readfds);

		ret = select(nfds, &readfds, NULL, NULL, &tv);
		if (ret < 0) {
			sprintf(errmsg, "select : %s", strerror(errno));
			return EC_TCP_SELECT_ERROR;
		} else if (ret == 0) {		/* 超时时间到 */
			sprintf(errmsg, "select : 超时时间到");
			return EC_TCP_TIME_OUT_ERROR;
		}
		
		/* 异常错误 */
		if (!FD_ISSET(sock, &readfds)) {
			sprintf(errmsg, "select : 异常错误");
			return EC_TCP_ABNORMAL_ERROR;
		}

		/* 开始接收数据包 */
		ret = read(sock, mesg, len - readlen);

		if (ret == -1) {
			sprintf(errmsg, "read : %s", strerror(errno));
			return EC_TCP_READ_ERROR;
		}
		readlen += ret;

		if (readlen == len)
			break;
	}

	return ret;
}

/*---------------------------------------------------------------
 * tcp_cli_close : 关闭 socket 连接
 *--------------------------------------------------------------*/
void
tcp_cli_close(int sock)
{
	close(sock);
	return;
}

/*-----------------------------------------------------------------
 * tcp_svr_open : Establish the connect to server
 * portname : remote port name or port number  (defined locally)
 * attention: portname must be defined in /etc/services
 * return : socket descriptor 
 *		< 0 error
 *----------------------------------------------------------------*/
int
tcp_svr_open(char *hostname, char *portname)
{
	struct	hostent		*h;
	struct	servent		*s;
	struct	sockaddr_in	ssvr;
	int	sock;

	if (portname == NULL) {
		strcpy(errmsg, "\"port\" must NOT be null!");
		return EC_TCP_NULL_PORT_ERROR;
	}

	memset(&ssvr, 0, sizeof(ssvr));
	
	if (hostname != NULL) {
		h = gethostbyname(hostname);
		if (h == NULL) {
			/* 输入的hostname是一个点分型的IP地址 */
			ssvr.sin_addr.s_addr = inet_addr(hostname);
		}
		else
			memcpy(&ssvr.sin_addr, h->h_addr, h->h_length);
	}
	else
		ssvr.sin_addr.s_addr = INADDR_ANY;	/* 本机IP */	

	s = getservbyname(portname, "tcp");
	if (s == NULL)
		ssvr.sin_port = htons(atoi(portname));
	else
		ssvr.sin_port = s->s_port;
	ssvr.sin_family = AF_INET;

	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		sprintf(errmsg, "socket : %s", strerror(errno));
		return EC_TCP_SOCKET_ERROR;
	}

	if (bind(sock, (struct sockaddr *)&ssvr, sizeof(struct sockaddr)) < 0) {
		close(sock);
		sprintf(errmsg, "bind : %s", strerror(errno));
		return EC_TCP_BIND_ERROR;
	}

	if (listen(sock, MAX_CONNECTION) < 0) {
		close(sock);
		sprintf(errmsg, "listen : %s", strerror(errno));
		return EC_TCP_LISTEN_ERROR;
	}

	return sock;
}

/*------------------------------------------------------------------
 * tcp_svr_accept : listening client
 * return : 0  - success
 *          <0 - failed
 *------------------------------------------------------------------*/
int
tcp_svr_accept(int sock)
{
	int	newsock;
	int	len;
	struct	sockaddr_in	sin;

	len = sizeof(struct sockaddr_in);
	newsock = accept(sock, (struct sockaddr *)&sin, (unsigned long*)(&len));
	if (newsock < 0) {
		sprintf(errmsg, "accept : %s", strerror(errno));
		return EC_TCP_ACCEPT_ERROR;
	}

	return newsock;
}

/*------------------------------------------------------------------
 * tcp_svr_send : Send message to server
 * new_sock : opened socket return by tcp_svr_accept 
 * mesg : message
 * len  : message length
 * return : 0  - success
 *          <0 - failed
 *------------------------------------------------------------------*/
int
tcp_svr_send(int newsock, char *mesg, int len, int timeout)
{
	int	ret;
	int	nfds	= 1;
	struct	timeval	tv;
	fd_set	writefds;

	/* 设置超时时间 */
	if (timeout <= 0) {
		tv.tv_sec  = 0;
		tv.tv_usec = 0;
	} else {
		tv.tv_sec = timeout;
		tv.tv_usec = 0;
	}

	/* 设置nfds = 1， 检查当前sock */
	nfds = newsock + 1;

	/* 初始化writefds, 并将当前sock加入 */
	FD_ZERO(&writefds);
	FD_SET(newsock, &writefds);

	ret = select(nfds, NULL, &writefds, NULL, &tv);
	if (ret < 0) {
		sprintf(errmsg, "select : %s", strerror(errno));
		return EC_TCP_SELECT_ERROR;
	} else if (ret == 0) {		/* 超时时间到 */
		sprintf(errmsg, "select : 超时时间到");
		return EC_TCP_TIME_OUT_ERROR;
	}
	
	/* 异常错误 */
	if (!FD_ISSET(newsock, &writefds)) {
		sprintf(errmsg, "select : 异常错误");
		return EC_TCP_ABNORMAL_ERROR;
	}

	ret = write(newsock, mesg, len);
	if (ret != len) {
		sprintf(errmsg, "write : %s", strerror(errno));
		return EC_TCP_WRITE_ERROR;
	}

	return ret;
}

/*-------------------------------------------------------------------
 * tcp_svr_recv : Receive message from server
 * sock : opened socket return by tcp_svr_accept
 * mesg : message
 * len  : expect length
 * return :>0 - success
 *         <0 - failed
 *------------------------------------------------------------------*/
int
tcp_svr_recv(int newsock, char *mesg, int len, int timeout)
{
	int	ret;
	int	i;
	int	nfds	= 1;
	struct	timeval	tv;
	fd_set	readfds;
	int	readlen = 0;

	/* 设置超时时间 */
	if (timeout <= 0) {
		tv.tv_sec  = 0;
		tv.tv_usec = 0;
	} else {
		tv.tv_sec = timeout;
		tv.tv_usec = 0;
	}

	readlen = 0;

	while (1) {
		/* 设置nfds = 1， 检查当前sock */
		nfds = newsock + 1;

		/* 初始化readfds, 并将当前sock加入 */
		FD_ZERO(&readfds);
		FD_SET(newsock, &readfds);

		ret = select(nfds, &readfds, NULL, NULL, &tv);
		if (ret < 0) {
			sprintf(errmsg, "select : %s", strerror(errno));
			return EC_TCP_SELECT_ERROR;
		} else if (ret == 0) {		/* 超时时间到 */
			sprintf(errmsg, "select : 超时时间到");
			return EC_TCP_TIME_OUT_ERROR;
		}
	
		/* 异常错误 */
		if (!FD_ISSET(newsock, &readfds)) {
			sprintf(errmsg, "select : 异常错误");
			return EC_TCP_ABNORMAL_ERROR;
		}

		/* 开始接收数据包 */
		ret = read(newsock, mesg, len - readlen);
		if (ret == -1) {
			sprintf(errmsg, "read : %s", strerror(errno));
			return EC_TCP_READ_ERROR;
		}
		readlen += ret;

		if (readlen == len)
			break;
	}

	return readlen;
}

/*---------------------------------------------------------------
 * tcp_svr_close : 关闭 socket 连接
 *--------------------------------------------------------------*/
void
tcp_svr_close(int sock)
{
	close(sock);
	return;
}
