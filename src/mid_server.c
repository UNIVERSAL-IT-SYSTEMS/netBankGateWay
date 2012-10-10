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

/* ������Ϊ������ɫҵ��ģ��ļ��������� */
int main(void)
{
	int	i,ret,len,recv_len;
	int	sock,timeout;
	char	sock_port[30],sock_timeout[30];
	char	send_buff[LEN_ICS_PROC_BUF],recv_buff[LEN_ICS_PROC_BUF];
        char    tmpbuf[10];

	return_flag = 0;

/*
	flog(STEP_LEVEL, "ȡsocket������Ϣ");
	flog(STEP_LEVEL, "ȡ������Ŀ[MID_PORT]");
*/
	ret = get_config_value(CONFIG_FILE_NAME, "MID_PORT", sock_port);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "ȡ������Ϣ[MID_PORT]ʧ��[%s][%d]",
			__FILE__, __LINE__);
		return ret;
	}
/*
	flog(STEP_LEVEL, "MID_PORT = [%s]", sock_port);
	flog(STEP_LEVEL, "ȡ������Ŀ[SOCKET_TIMEOUT]");
*/
	ret = get_config_value(CONFIG_FILE_NAME,"SOCKET_TIMEOUT",sock_timeout);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "ȡ������Ϣ[SOCKET_TIMEOUT]ʧ��[%s][%d]",
			__FILE__, __LINE__);
		return ret;
	}
/*
	flog(STEP_LEVEL, "SOCKET_TIMEOUT = [%s]", sock_timeout);
*/

	timeout = atoi(sock_timeout);

/*
	flog(STEP_LEVEL, "ȡ������Ϣ���");
*/

	signal(SIGCLD,  SIG_IGN);
	signal(SIGHUP,  SIG_IGN);
	signal(SIGINT,  SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	setpgrp();

	/* ������̨���� */
	if (fork() > 0)
		exit(0);

	flog(STEP_LEVEL, "����������ɫҵ����ģ��");
	sock = tcp_svr_open(NULL, sock_port);
	if (sock < 0) {
		flog(ERROR_LEVEL, "����������ɫҵ����ģ��ʧ��[%s][%d] [%s]", __FILE__, __LINE__, tcp_err());
		return sock;
	}

	newsock = 0;

	for (;;) {
		return_flag = 0;
		flog(STEP_LEVEL, "�ȴ����������ɫҵ����");
		newsock = tcp_svr_accept(sock);
		if (newsock < 0) {
			flog(ERROR_LEVEL,"�ȴ��ͻ�������ʧ��[%s][%d] [%s]", __FILE__, __LINE__, tcp_err());
			exit(newsock);
		}
		if (fork() != 0) {
			tcp_svr_close(newsock);
			continue;
		}

		memset(send_buff, '\0', sizeof(send_buff));
/*
		flog(STEP_LEVEL, "���շ�����ɫҵ������");
*/		
                memset(tmpbuf,0,sizeof(tmpbuf));
		len = tcp_svr_recv(newsock, tmpbuf, sizeof(char)*4, timeout);
                tmpbuf[4]=0;
		if (len < 0) {
			flog(ERROR_LEVEL,"���տͻ�������ʧ��1[%s][%s][%d] [%s]",tmpbuf, __FILE__, __LINE__, tcp_err());
			exit(len);
		}
                
		len = tcp_svr_recv(newsock, send_buff, atoi(tmpbuf), timeout);
		if (len < 0) {
			flog(ERROR_LEVEL,"���տͻ�������ʧ��2[%s][%s][%d] [%s]", send_buff,__FILE__, __LINE__, tcp_err());
			exit(len);
		}
		/* zxz 20030701 */
		strcat(send_buff,"|");

		return_flag = 1;
/*
		flog(STEP_LEVEL, "mid_server.c -->��ʼ���з�����ɫҵ����");
		flog(STEP_LEVEL, "�������ݿ�");
*/
/*
		ret = connect_db();
		if (ret != RETURN_OK) {
			flog(ERROR_LEVEL,"�������ݿ�ʧ�� [%s][%d]", __FILE__, __LINE__);
			return ret;
		}
		flog(STEP_LEVEL, "�������ݿ�ɹ�");
*/

		/* ���÷�����ɫҵ����ģ�� */

		flog( STEP_LEVEL,"--start_mid_process send_buff=[%s]------------------------------",send_buff);
		ret = start_mid_process(send_buff,recv_buff);
		flog( STEP_LEVEL,"--start_mid_process recv_buff=[%s]------------------------------",recv_buff);
		if (ret != RETURN_OK) {
 			setValueOfStr(recv_buff,"MGID","BBBBBBB");/*������*/

        		setValueOfStr(recv_buff,"display_zone","�����쳣�жϣ�����ϵ������!");

        		/* �쳣�жϣ������к������� */

			flog(STEP_LEVEL, "������ɫҵ�����쳣�ж�!\n*****************************\n");
                        sprintf(tmpbuf,"%04d",strlen(recv_buff));
		} else {
/*
			flog(STEP_LEVEL, "mid_server.c ������ɫҵ������� [%s]",recv_buff);
*/
			flog(STEP_LEVEL, "mid_server.c -->������ɫҵ�������\n******************************************\n");
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

	/*	dbdisconn();*/
		tcp_svr_close(newsock);
		exit(0);
	}
	return 0;
}

/* End of this file */
