/* -lcclaix */

#ifndef _EBCCLI_H
#define _EBCCLI_H

#define CICS_AIX
#include <cics_eci.h>

#define _EBCCLI extern

/*
 *	eci_call:	CICS�ͻ���ͨѶ���ͺͽ��պ���
 *	���������	servername -- CICS server������
 *			commbuf -- ͨѶ�������ַ�����ָ�룩
 *			len -- ͨѶ�������е��ַ���ʵ�ʳ���
 *			prg -- �����õ�CICS server�еĳ�����
 *			timeout -- ��ʱʱ�䣨�룩
 *	�����		����ֵ -- 0���ɹ�
 *			         -1��ʧ��
 *			commbuf -- �����óɹ�ʱ�����������صı����ַ���
 */

_EBCCLI int eci_call(	char *servername,
			char *commbuf, 
			cics_sshort_t len,
			cics_char_t *prg, 
			cics_sshort_t timeout);


/*
 *	get_ebcli_errmsg:������ĵ���ʧ��ʱ��ʹ�ñ������õ�CICS������Ϣ
 *	���������	��
 *	�����	����ֵ -- ������Ϣ��������ĺ�������-1ʱ�����ص���Ϣ�������壩
 */

_EBCCLI char	*get_eci_call_err();

#endif
