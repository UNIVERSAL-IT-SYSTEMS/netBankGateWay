/*-------------------------------------
 *
 * ��Ϣ����ʹ�ú���
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <signal.h>
#include <sys/msg.h>
#include "error.h"

#define IPC_WAIT	0		/* ���õȴ���ʽ */

/*----------------------------------------------------------------------
 * set_msgid : ����һ����Ϣ���л򷵻�һ����Ϣ���еı��
 * key_t key : Ҫ���ɻ�ȡ�õ���Ϣ���еı��
 * ����ֵ    : ������Ϣ���е��ڲ�ID
 *---------------------------------------------------------------------*/
int
start_msg(long key)
{
	return msgget((key_t)key, IPC_CREAT | 0666);
}

/*----------------------------------------------------------------------
 * send_msg   : ����һ������Ϊmtype����Ϣ
 * char *msg  : Ҫ���͵���Ϣ�ַ���
 * long mtype : Ҫ���͵���Ϣ�ַ�������(��ʶ)
 * int  msgid : ��get_msgid()���ص���Ϣ����ID
 * ����ֵ : 0 �ɹ�
 *         -1 ʧ��
 *---------------------------------------------------------------------*/
int
send_msg(char *msg, long mtype, int msgid)
{
	struct	msgbuf	msgs;

	msgs.mtype = mtype;
	strcpy(msgs.mtext, msg);
	return msgsnd(msgid, &msgs, strlen(msg), IPC_NOWAIT);
}

/*----------------------------------------------------------------------
 * read_msg : ����һ������Ϊmtype����Ϣ
 * char *msg  : �����ַ����Ļ�����
 * long mtype : Ҫ���յ���Ϣ�ַ�������(��ʶ)
 * int  msgid : ��get_msgid()���ص���Ϣ����ID
 * ����ֵ :>0 �յ����ַ����ĳ���
 *         -1 ʧ��
 *---------------------------------------------------------------------*/
int
read_msg(char *msg, long mtype, int msgid)
{
	struct	msgbuf	msgs;
	int	ret;

	memset(&msgs, 0, sizeof(msgs));

	msgs.mtype = mtype;
	ret = msgrcv(msgid, &msgs, 1000, mtype, MSG_NOERROR | IPC_WAIT );
	strcpy(msg, msgs.mtext);

	return ret;
}

/*-----------------------------------------------------------------------
 * close_msg : �ر�һ����Ϣ����
 * int msgid : ��get_msgid()���ص���Ϣ����ID
 *----------------------------------------------------------------------*/
void
close_msg(int msgid)
{
	msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);

	return ;
}
