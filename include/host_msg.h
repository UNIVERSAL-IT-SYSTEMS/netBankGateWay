/*
 *	FILENAME:	"host_msg.h"
 *	CREATED DATE:	Wed Oct 31 17:43:42 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"host_msg.txt".
 */

#ifndef _HOST_MSG_H_
#define _HOST_MSG_H_




typedef struct {
	CS_SMALLINT	hmt_host_no;	/*	ҵ��ϵͳ���	*/
	CS_CHAR		hmt_host_name[21];/*	ҵ��ϵͳ����	*/
	CS_SMALLINT	hmt_host_type;	/*	ҵ��ϵͳ����	*/
	CS_SMALLINT	hmt_time_out;	/*	��ʱ����	*/
	CS_SMALLINT	hmt_net_status;	/*	����״̬	*/
        } host_msg_t;



int host_msg_SelectBy_hmt_host_no(
	CS_SMALLINT		hmt_host_no,
	host_msg_t	*_host_msg_data);
int host_msg_UpdateBy_hmt_host_no(
	CS_SMALLINT		hmt_host_no,
	host_msg_t	*_host_msg_data);

#endif	 /* _HOST_MSG_H_ */
