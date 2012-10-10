#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "miscfunc.h"
#include "error.h"
#include "netbank_mid.h"
#include "trans_macro.h"

int	return_flag;
int	newsock;

/* 本程序为分行特色业务模块的监听处理部分 */
int main(void)
{
	int	i,ret,len,recv_len;
	int	sock,timeout;
	char	sock_port[30],sock_timeout[30];
	char	send_buff[LEN_ICS_PROC_BUF],recv_buff[LEN_ICS_PROC_BUF];
        char    tmpbuf[10];

	return_flag = 0;


	signal(SIGCLD,  SIG_IGN);
	signal(SIGHUP,  SIG_IGN);
	signal(SIGINT,  SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	setpgrp();

	/* 创建后台进程 */
	if (fork() > 0)
		exit(0);

	flog(STEP_LEVEL, "启动分行特色业务处理模块");
	sock = tcp_svr_open(NULL, "9999");
	if (sock < 0) {
		flog(ERROR_LEVEL, "启动分行特色业务处理模块失败[%s][%d] [%s]", __FILE__, __LINE__, tcp_err());
		return sock;
	}

	newsock = 0;

	for (;;) {
		return_flag = 0;
		flog(STEP_LEVEL, "等待发起分行特色业务处理");
		newsock = tcp_svr_accept(sock);
		if (newsock < 0) {
			flog(ERROR_LEVEL,"等待客户端请求失败[%s][%d] [%s]", __FILE__, __LINE__, tcp_err());
			exit(newsock);
		}
		if (fork() != 0) {
			tcp_svr_close(newsock);
			continue;
		}
printf("start connect\n");
		memset(send_buff, '\0', sizeof(send_buff));
/*
		flog(STEP_LEVEL, "接收分行特色业务请求");
*/		

	strcpy(sock_timeout, "30");
	
	memset(tmpbuf,0,sizeof(tmpbuf));                
		len = tcp_svr_recv(newsock, send_buff, 337, timeout);
		if (len < 0) {
			flog(ERROR_LEVEL,"接收客户端数据失败2[%s][%s][%d] [%s]", send_buff,__FILE__, __LINE__, tcp_err());
			exit(len);
		}
printf("===[%s]\n", send_buff);

		memset(recv_buff, 0, sizeof(recv_buff));
		strcpy(recv_buff,"01100070Z0901160142890710180319  20090305145754903230000333041FAEF1B5A");
		
		ret=tcp_write(newsock,recv_buff,strlen(recv_buff));
   		if(ret<0) {
			flog(STEP_LEVEL,"tcp_write len error! ret=[%d]",ret);
    			close(newsock);
    			exit(-1);
   		}
		tcp_svr_close(newsock);
		exit(0);
	}
	return 0;
}

/* End of this file */
