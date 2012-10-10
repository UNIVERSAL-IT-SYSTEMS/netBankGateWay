#ifndef _ERROR_H
#define _ERROR_H

#define BASE_ERR 			-9000		/* ��������ֵ */

/* �Ϸ��Լ�鷵��ֵ */
#define RETURN_YES			1		/* �� */
#define RETURN_NOT			0		/* �� */

/* ����ֵ */
#define RETURN_OK			0
#define FIELD_NOT_FOUND			-2		/* ��������û���ҵ� */

/* EC : Error Code */
#define EC_NO_ERROR			0		/* û�д���	*/

#define EC_NULL_PARA_ERROR		(BASE_ERR -  1)	/* ����Ϊ��	*/
#define EC_OPEN_FILE_ERROR		(BASE_ERR -  2)	/* ���ļ�ʧ��	*/
#define EC_UNDEF_SYM_ERROR		(BASE_ERR -  3)	/* δ������Ŀ	*/

#define	EC_TCP_NULL_HOST_ERROR		(BASE_ERR -  4)	/* ������Ϊ��	*/
#define EC_TCP_NULL_PORT_ERROR		(BASE_ERR -  5)	/* �˿ں�Ϊ��	*/
#define EC_TCP_SOCKET_ERROR		(BASE_ERR -  6) /* socket����	*/
#define EC_TCP_CONNECT_ERROR		(BASE_ERR -  7) /* connect����	*/
#define EC_TCP_SELECT_ERROR		(BASE_ERR -  8) /* select����	*/
#define EC_TCP_TIME_OUT_ERROR		(BASE_ERR -  9) /* ��ʱ����	*/
#define EC_TCP_ABNORMAL_ERROR		(BASE_ERR - 10) /* �쳣����	*/
#define EC_TCP_WRITE_ERROR		(BASE_ERR - 11) /* write����	*/
#define EC_TCP_READ_ERROR		(BASE_ERR - 12) /* read����	*/
#define EC_TCP_BIND_ERROR		(BASE_ERR - 13) /* bind����	*/
#define EC_TCP_LISTEN_ERROR		(BASE_ERR - 14) /* listen����	*/
#define EC_TCP_ACCEPT_ERROR		(BASE_ERR - 15) /* accept����	*/

#define EC_ADDRESS_EIB_ERROR		(BASE_ERR - 17)	/* ����CICS���� */
#define EC_ADDRESS_COMMAREA_ERROR	(BASE_ERR - 18)	/* ȡCICS���ݴ� */
#define EC_SYNCPOINT_ERROR		(BASE_ERR - 19) /* SYNCPOINT���� */
#define EC_CICS_LINK_ERROR		(BASE_ERR - 20) /* ����LINK���� */

#define EC_DECODE_DG_ERROR		(BASE_ERR - 30)	/* �������ĳ��� */
#define EC_CREATE_DG_ERROR		(BASE_ERR - 31) /* �������ĳ��� */
#define EC_DG_LENGTH_ERROR		(BASE_ERR - 32)	/* ���ĳ��Ȳ��� */
#define EC_DG_FIELD_LENGTH_ERROR	(BASE_ERR - 33) /* �ֶγ��Ȳ��� */
#define EC_INVALID_DG_TYPE		(BASE_ERR - 34) /* �������ʹ� */
#define EC_INVALID_BUSI_NO_ERROR	(BASE_ERR - 35) /* ��������δ֪ */

#define EC_CONNECT_DB_ERROR		(BASE_ERR - 101) /* �������ݿ�� */
#define EC_DB_SELECT_ERROR		(BASE_ERR - 102) /* ���ݿ��ѯ���� */
#define EC_DB_INSERT_ERROR		(BASE_ERR - 103) /* ���ݿ������� */
#define EC_DB_UPDATE_ERROR		(BASE_ERR - 104) /* ���ݿ��޸ĳ��� */
#define EC_DB_DECLARE_ERROR		(BASE_ERR - 105) /* �α��������� */
#define EC_DB_OPEN_ERROR		(BASE_ERR - 106) /* �α�򿪳��� */
#define EC_DB_FETCH_ERROR		(BASE_ERR - 107) /* �α�ߢȡ���� */
#define EC_DB_CONVERT_ERROR		(BASE_ERR - 108) /* decimalת������ */
#define EC_DB_NOTFOUND_ERROR		(BASE_ERR - 109) /* ��ѯδ�ҵ���¼ */
#define EC_DB_BEGIN_TRAN_ERROR		(BASE_ERR - 110) /* ��������ʧ�� */
#define EC_DB_ROLLBACK_TRAN_ERROR	(BASE_ERR - 111) /* �ع�����ʧ�� */
#define EC_DB_COMMIT_TRAN_ERROR		(BASE_ERR - 112) /* �ύ����ʧ�� */

#define EC_BRT_SYS_TYPE_ERROR		(BASE_ERR - 150) /* �������ͳ��� */
#define EC_BRT_NET_STATUS_ERROR		(BASE_ERR - 151) /* ����״̬��ͨ */
#define EC_BRT_NBANK_FLAG_ERROR		(BASE_ERR - 152) /* ����ϵͳδ�� */
#define EC_BRT_BSN_STAT_ERROR		(BASE_ERR - 153) /* ҵ��ϵͳδ�� */

#define EC_STRING_LENGTH_ERROR		(BASE_ERR - 300) /* �ַ������Ȳ��� */

/* ���в����� */
#define EC_SMT_SYS_STATUS_ERROR		(BASE_ERR - 500) /* ϵͳ��ǰ������ */
#define EC_DAY_END_CHECK_ERROR		(BASE_ERR - 501) /* ���ն���ʧ�� */
#define EC_CAN_NOT_QUERY_ERROR		(BASE_ERR - 502) /* ����ִ�в�ѯ���� */


/* ����Ϊ����������ʱ�� */
#define EC_UNKNOWN_TRANS_CODE_ERROR	(BASE_ERR - 601) /* ����δ֪�������� */
#define EC_TP_CALL_INIT_ERROR		(BASE_ERR - 602) /* ����ͨѶ��ʼ��ʧ�� */
#define EC_TP_CALL_ERROR		(BASE_ERR - 603) /* ������ͨѶʧ�� */

/* ��Ȩ����ش����� */
#define EC_WAIT_AUDIT			 9999		/* �ȴ���Ȩ���� */
#define EC_WAIT_SUPPLY			 8888		/* �ȴ���ش��� */

#endif
