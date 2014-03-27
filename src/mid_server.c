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
	char	send_buff[LEN_MID_PROC_BUF],recv_buff[LEN_MID_PROC_BUF];
        char    tmpbuf[10];

	return_flag = 0;

	flog(STEP_LEVEL, "取socket配置信息");
	flog(STEP_LEVEL, "取配置项目[MID_PORT]");
	ret = get_config_value(CONFIG_FILE_NAME, "MID_PORT", sock_port);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "取配置信息[MID_PORT]失败[%s][%d]",
			__FILE__, __LINE__);
		return ret;
	}
	flog(STEP_LEVEL, "MID_PORT = [%s]", sock_port);

	flog(STEP_LEVEL, "取配置项目[SOCKET_TIMEOUT]");
	ret = get_config_value(CONFIG_FILE_NAME,"SOCKET_TIMEOUT",sock_timeout);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "取配置信息[SOCKET_TIMEOUT]失败[%s][%d]",
			__FILE__, __LINE__);
		return ret;
	}
	flog(STEP_LEVEL, "SOCKET_TIMEOUT = [%s]", sock_timeout);

	timeout = atoi(sock_timeout);

	flog(STEP_LEVEL, "取配置信息完成");

	signal(SIGCLD,  SIG_IGN);
	signal(SIGHUP,  SIG_IGN);
	signal(SIGINT,  SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	setpgrp();

	/* 创建后台进程 */
	if (fork() > 0)
		exit(0);

	flog(STEP_LEVEL, "启动分行特色业务处理模块");
	sock = tcp_svr_open(NULL, sock_port);
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

		memset(send_buff, '\0', sizeof(send_buff));

		flog(STEP_LEVEL, "接收分行特色业务请求");
                memset(tmpbuf,0,sizeof(tmpbuf));
		len = tcp_svr_recv(newsock, tmpbuf, sizeof(char)*4, timeout);
                tmpbuf[4]=0;
		if (len < 0) {
			flog(ERROR_LEVEL,"接收客户端数据失败1[%s][%s][%d] [%s]",tmpbuf, __FILE__, __LINE__, tcp_err());
			exit(len);
		}
                
		len = tcp_svr_recv(newsock, send_buff, atoi(tmpbuf), timeout);
		if (len < 0) {
			flog(ERROR_LEVEL,"接收客户端数据失败2[%s][%s][%d] [%s]", send_buff,__FILE__, __LINE__, tcp_err());
			exit(len);
		}
		/* zxz 20030701 */
		strcat(send_buff,"|");

		return_flag = 1;

		flog(STEP_LEVEL, "mid_server.c -->开始进行分行特色业务处理");

		flog(STEP_LEVEL, "连接数据库");
		ret = connect_db();
		if (ret != RETURN_OK) {
			flog(ERROR_LEVEL,"连接数据库失败 [%s][%d]", __FILE__, __LINE__);
			return ret;
		}
		flog(STEP_LEVEL, "连接数据库成功");

		/* 调用分行特色业务处理模块 */

		ret = start_mid_process(send_buff,recv_buff);
		if (ret != RETURN_OK) {
 			setValueOfStr(recv_buff,"MGID","BBBBBBB");/*返回码*/

        		setValueOfStr(recv_buff,"display_zone","交易异常中断，请联系开户行!");

        		/* 异常中断，不进行后续处理 */

			flog(STEP_LEVEL, "分行特色业务处理异常中断!\n*****************************\n");
                        sprintf(tmpbuf,"%04d",strlen(recv_buff));
		} else {
/*
			flog(STEP_LEVEL, "mid_server.c 分行特色业务处理完成 [%s]",recv_buff);
*/
			flog(STEP_LEVEL, "mid_server.c -->分行特色业务处理完成\n******************************************\n");
                        sprintf(tmpbuf,"%04d",strlen(recv_buff));
		}

		ret=tcp_write(newsock,tmpbuf,sizeof(char)*4);
   		if(ret<0) {
			flog(STEP_LEVEL,"tcp_write len error! ret=[%d]",ret);
    			close(newsock);
    			exit(-1);
   		}
   		ret=tcp_write(newsock,recv_buff,strlen(recv_buff));
   		if(ret<0) {
			flog(STEP_LEVEL,"tcp_write recv_buff error! ret=[%d]",ret);
    			close(newsock);
    			exit(0);
   		}

		dbdisconn();
		tcp_svr_close(newsock);
		exit(0);
	}
	return 0;
}

/* End of this file */
