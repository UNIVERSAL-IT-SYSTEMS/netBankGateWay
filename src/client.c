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
	flog(ERROR_LEVEL, "ȡ������Ϣ[ICS_ADDR]ʧ��[%s][%d]", __FILE__, __LINE__);
	return ret;
    }
    if( 0 > ri_tcpconnect((int*) &sock, ics_ip, tcp_port) )
    {
    	flog(STEP_LEVEL,"����[%s,%d]ʧ��", ics_ip, tcp_port ) ;
        sleep(20);
    }
/*
    flog(STEP_LEVEL,"����[%s,%d]!!!", ics_ip, tcp_port ) ;
*/

    len = strlen(send_buffer);
    if( ri_tcpwrite(sock, send_buffer, len) < 0 )
    {
        flog( STEP_LEVEL, "д����ʧ��!!" ) ;
	return -1;
    }
    flog( STEP_LEVEL, "д����[%s][%d]!!", send_buffer, len ) ;

    lRet = ri_tcpread(sock, szLen, 8, TIMEOUT);
    if(lRet < 0)
    {
        flog ( STEP_LEVEL, "Sock[%ld]��ȡ���ĳ���ʧ��[%d]\n", sock, lRet);
	return -1;
    }
/*
    flog ( STEP_LEVEL, "���ĳ���[%s]\n", szLen);
*/
    lLen = atol(szLen);

    lRet = ri_tcpread(sock, recv_buffer, lLen, TIMEOUT);
    if(lRet < 0) {
        flog ( STEP_LEVEL, "��ȡ����ʧ��[%d]\n",  lRet);
	return -1;
    }
/*
    flog ( STEP_LEVEL, "����[%d]����[%s]\n", lLen, recv_buffer);
*/

    close(sock);

    flog(STEP_LEVEL,"client.c ��ICS���ա�[%s]\n",recv_buffer);
    return 0;
}
