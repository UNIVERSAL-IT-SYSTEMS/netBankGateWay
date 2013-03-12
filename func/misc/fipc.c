/*-------------------------------------
 *
 * 消息队列使用函数
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

#define IPC_WAIT	0		/* 设置等待方式 */

/*----------------------------------------------------------------------
 * set_msgid : 创建一个消息队列或返回一个消息队列的编号
 * key_t key : 要生成或取得的消息队列的编号
 * 返回值    : 返回消息队列的内部ID
 *---------------------------------------------------------------------*/
int
start_msg(long key)
{
	return msgget((key_t)key, IPC_CREAT | 0666);
}

/*----------------------------------------------------------------------
 * send_msg   : 发送一个类型为mtype的消息
 * char *msg  : 要发送的消息字符串
 * long mtype : 要发送的消息字符串类型(标识)
 * int  msgid : 由get_msgid()返回的消息队列ID
 * 返回值 : 0 成功
 *         -1 失败
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
 * read_msg : 接收一个类型为mtype的消息
 * char *msg  : 接收字符串的缓冲区
 * long mtype : 要接收的消息字符串类型(标识)
 * int  msgid : 由get_msgid()返回的消息队列ID
 * 返回值 :>0 收到的字符串的长度
 *         -1 失败
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
 * close_msg : 关闭一个消息队列
 * int msgid : 由get_msgid()返回的消息队列ID
 *----------------------------------------------------------------------*/
void
close_msg(int msgid)
{
	msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);

	return ;
}
