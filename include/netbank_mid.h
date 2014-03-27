/* ���ļ����ڶ�������ϵͳ���õ��Ĳ��� */

#ifndef _NETBANK_H
#define _NETBANK_H

/* ��ȡ�����ļ�ʱ���ñ��� */
#define MESSAGE_LENGTH		10240
#define CONFIG_FILE_NAME	"/home/netbank_mid/config/netbank.cfg"
#define	LOG_LEVEL		6
#define BUF_LEVEL               0
#define LOG_FILE_NAME           "/tmp/netbank_mid_log.log"
#define BUF_FILE_NAME           "/tmp/netbank_mid_buf.log"


/* ͨѶ���� �麣�汾��������Ķ��� */
#define MID_ADD			"182.39.6.211" 
#define MID_PORT	 	3000	

/* ���ݿ� */
#define SQLNOTFOUND		100

/* ��־���� */
#define ERROR_LEVEL		0
#define STEP_LEVEL		2
#define INFO_LEVEL		4
#define DEBUG_LEVEL		6

/* �������� */
#define QUERY_TRANSACTION	1
#define TRANSFER_TRANSACTION	0

/* �������� */
#define REQUEST_DG		0
#define RESPONSE_DG		1

/* ��ش����ʶ */
#define NEED_SUPPLY		1			/* ��Ҫ��ش��� */
#define NEED_NOT_SUPPLY		0			/* ������ش��� */

/* ��־��¼���� */
#define WRITE_TO_TDQ		1			/* д��TDQ�� */
#define WRITE_TO_FILE		0			/* д���ļ��� */

/* д��ˮ��ʶ */
#define JNL_WRITED		1			/* �Ѽ�¼��ˮ */
#define JNL_NOT_WRITED		0			/* δ��¼��ˮ */

/* ���׻����ʶ */
#define TRANSACTION_SAVED	1			/* ���ױ����� */
#define TRANSACTION_NOT_SAVED	0			/* ���ײ������� */

#define TIMEOUT			120			/* ͨѶ��ʱ */
#define	ICS_ADDR 		"182.53.15.204"		/* ICS��ַ */
#define ICS_PORT		35850			/* ICS�˿� */

#endif
