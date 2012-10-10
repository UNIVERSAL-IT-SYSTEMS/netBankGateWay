#include <stdio.h>
#include <stdlib.h>
#include "sockapi.h"
#include "error.h"
#include "netbank_mid.h"


int clientics (char * send_buffer,char * recv_buffer, int tcp_port)
{  
    int ret,ret2;
    int sock,len,lLen,lRet;
    char ics_ip[16];
    char szLen[9] = "\0";

    memset(ics_ip,'\0',sizeof(ics_ip));
    ret = get_config_value(CONFIG_FILE_NAME, "ICS_ADDR", ics_ip);
    if (ret != RETURN_OK)
    {
	flog(ERROR_LEVEL, "取配置信息[ICS_ADDR]失败[%s][%d]", __FILE__, __LINE__);
	return ret;
    }
    if( 0 > ri_tcpconnect((int*) &sock, ics_ip, tcp_port) )
    {
    	flog(STEP_LEVEL,"连接[%s,%d]失败", ics_ip, tcp_port ) ;
        sleep(20);
    }
/*
    flog(STEP_LEVEL,"连接[%s,%d]!!!", ics_ip, tcp_port ) ;
*/

    len = strlen(send_buffer);
    if( ri_tcpwrite(sock, send_buffer, len) < 0 )
    {
        flog( STEP_LEVEL, "写数据失败!!" ) ;
	return -1;
    }
    flog( STEP_LEVEL, "写数据[%s][%d]!!", send_buffer, len ) ;

    lRet = ri_tcpread(sock, szLen, 8, TIMEOUT);
    if(lRet < 0)
    {
        flog ( STEP_LEVEL, "Sock[%ld]读取报文长度失败[%d]\n", sock, lRet);
	return -1;
    }
/*
    flog ( STEP_LEVEL, "报文长度[%s]\n", szLen);
*/
    lLen = atol(szLen);

    lRet = ri_tcpread(sock, recv_buffer, lLen, TIMEOUT);
    if(lRet < 0) {
        flog ( STEP_LEVEL, "读取报文失败[%d]\n",  lRet);
	return -1;
    }
/*
    flog ( STEP_LEVEL, "长度[%d]报文[%s]\n", lLen, recv_buffer);
*/

    close(sock);

    flog(STEP_LEVEL,"client.c 从ICS接收∶[%s]\n",recv_buffer);
    return 0;
}
