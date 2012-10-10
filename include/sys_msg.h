/*
 *	FILENAME:	"sys_msg.h"
 *	CREATED DATE:	Wed Nov 28 08:41:06 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"sys_msg.txt".
 */

#ifndef _SYS_MSG_H_
#define _SYS_MSG_H_


typedef struct {
	CS_INT		smt_bank_no;	/*	办理行代码	*/
	CS_CHAR		smt_bank_name[21];/*	办理行名称	*/
	CS_SMALLINT	smt_sys_status;	/*	系统当前状态	*/
	CS_CHAR		smt_stop_time[21];/*	日终时间	*/
	CS_DECIMAL	smt_amount_limit;/*	划款限额	*/
        } sys_msg_t;


int sys_msg_SelectBy_smt_bank_no(
	CS_INT		smt_bank_no,
	sys_msg_t	*_sys_msg_data);
int sys_msg_UpdateBy_smt_bank_no(
	CS_INT		smt_bank_no,
	sys_msg_t	*_sys_msg_data);

#endif	 /* _SYS_MSG_H_ */
