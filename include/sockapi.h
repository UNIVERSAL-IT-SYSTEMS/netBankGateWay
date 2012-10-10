/* SOCKAPI.H

	һ��TCP/IP socket��̽ӿڵļ��׽ӿں�����
	       (C)Copyright XWB, 1995-97
	    (SCO UNIX/XENIX, PCTCP for DOS)
	       (C)Copyright JJS, 1996-99
	    (SCO UNIX/XENIX, PCTCP for DOS, Lan WorkPlace for DOS)

   !! ������ʱ����ʹ��ALARM����, �⽫��Ӧ�ó����ALARM��ͻ !!
   !! ��������M_XENIX�����Ƿ�ΪDOS�汾.
   !!! ��������NOVELL_TCPIP4DOS�����Ƿ�ΪLan WorkPlace for DOS�汾.

   Update History:

     ����ʥ  1998.02.19
	   1) ���itcp_calln()����, ����״̬��99
	   2) ���set_reuseaddr()����
	   3) �޸�itcp_poll()����, ���ϵ���set_reuseaddr

     ����ʥ  1998.05.17 Ӱ��itcp_send��itcp_recv����
	   1) ��Ӻ�   NOVELL_TCPIP4DOS  -  Novell Lan WorkPlace for DOS
		 (��Ҫ�Ǻ��� read -> soread,  write -> sowrite
			     close -> soclose, ioctl -> soioctl,
		  ��ͷ�ļ��ı仯)
	   2) ��ӱ��� int  _use_ns = 1;   //�Ƿ��������ֽ�˳���ʾ����
		       static char sync_buffer[MAX_SYNCCHAR]; //ͬ���ַ�������
		       static int  sync_buflen;               //ͬ�����峤��
	   3) ��Ӻ��� void itcp_setsync(int len, char *buffer);
     ����ʥ  1998.08.25 Ӱ��itcp_send��itcp_recv����
	   1) ��ӱ��� int _nohead = 0;   //û�����ݰ�ͷ(ͬ���ַ�+����)
*/

#if !defined (__SOCKAPI_H)
#define __SOCKAPI_H

#include <sys/types.h>

#ifdef NOVELL_TCPIP4DOS
#include "socket.h"
#endif
extern int _use_ns;        /* ���ݰ������Ƿ�ʹ�������ֽ�˳�� */
extern int _nohead;        /* û�����ݰ�ͷ(ͬ���ַ�+����) */

#ifndef M_XENIX
/* ��װ�Զ���hook����.
 * ��ִ��һ��blocking����ʱ,�����hook���������ϵر�����.
 * ��ʽ: int hook( int state );   state=0:polling, 10-reading, 11-writing 99-calling(n)
 *   ����: 0-����,����-�жϵ�ǰ�����õĺ���,�����ظ�ֵ.
 */
void itcp_sethook(void *funcptr);
#endif

/* ����ͬ���ַ���������ͬ���ַ����������� */
void itcp_setsync(int len, char *buffer);

/* ����Ӧ�ó�����ӿڵ����ӱ���, Ӧ�ó���������ȵ��øú���.
 * port ...... �˿ں�, Ӧ�ó������ʹ���ض��Ķ˿ںŷſɽ���ͨ��.
 * sockvar ... ���socket����ı���ָ��.
 */
void itcp_setenv(int port, int *sockvar);


/* ��ָ������������������.
 * ע  : ����Ϊ������hosts�е���������IP��ַ��.
 * ����:  0 - ���ӳɹ�, ���Խ���ͨ��. socket����Ŵ����Ӧ�ó�������ı�����;
 *       -1 - ������������;
 *       -2 - ���Ӳ��ɹ�.
 * ���Ӳ��ɹ�, �Զ��ر����뵽��socket.
 */
int itcp_call(char *remotehost);


/* �����Ƿ�����������. ע: �����inetd����Ӧ�ó���, ���ܵ��ñ�����.
 * ����: 0-��һ��������;
 *	-1-��ʼ��ʧ��. (һ���������س���, ��TCP/IPδ����)
 */
int itcp_poll(void);


/* Ӧ��һ����������. ����һ���պ���, ʵ����, Ӧ�����Զ���ɵ� */
int itcp_accept(void);


/* ����һ������. ����TCP/IPΪ������, �����޷��������ݷֽ�, �����ǲ���4������
 * �ַ�, �Է���Ӧ�ó�����.
 * byte0-1=ͬ���ַ�, byte2-3=��������(������4�������ַ�)
 *	buffer ....... �����͵Ļ�����ָ��;
 *	len .......... ���峤��;
 *	maxtime ...... ��ʱֵ(��), 0-��Զ�ȴ�,ֱ��������ϻ�socket���ر�.
 * ����: 0-�ɹ�, -1-socket���ر�, -3-��ʱ.
 */
int itcp_send(char *buffer, int len, int maxtime);


/* ����һ������. ������itcp_send���͵İ�, ���������޷�����.
 *	buffer ....... ����ŵĻ�����ָ��;
 *      maxlen ........��󻺳峤��(_nohead == 1ʱΪʵ�ʻ��峤��);
 *	maxtime ...... ��ʱֵ(��), 0-��Զ�ȴ�,ֱ���յ������İ���socket���ر�.
 * ����: -1-socket���ر�, -3-��ʱ, >0-�յ��İ����ֽ���.
 */
int itcp_recv(char *buffer, int maxlen, int maxtime);


/* ��ʹcloseһ��socket,�ں���Ȼ��δ�ͳ�����Ϣ���ͳ�ȥ.
 * ���������õ��ر�һ���׽���ʱ�����ͷŻ���,���δ�ͳ�������������ʧ.
 * (DOS�汾: ������socketʱ,�������Զ�����)
 */
void itcp_setlinger(void);


/* �ر�socket */
void itcp_clear(void);


/* ������ͨ�������ӽ�����(��poll����), ���ڹر�ԭ��(listen)��socket */
void itcp_closelisten(void);

/* ����������socket�ĵ�ַ(0:����, ��0:�Է�) */
u_long itcp_getaddr(int side);

#ifdef M_XENIX
/* ����������ָ����ָ�������Ƿ���ͨ. ����: 1-��ͨ, 0-�Ͽ�, -1-������������ */
int itcp_testhost(char *host);
#endif

/* ������ָ������������������.
 * ע  : ����Ϊ������hosts�е���������IP��ַ��. nΪcall�Ĵ���(<=0Ϊ��ѭ��)
 * ����:  0 - ���ӳɹ�, ���Խ���ͨ��. socket����Ŵ����Ӧ�ó�������ı�����;
 *       -1 - ������������;
 *       -2 - ���Ӳ��ɹ�.
 * ���Ӳ��ɹ�, �Զ��ر����뵽��socket.
 */
int itcp_calln(char *remotehost, int times);

#endif
