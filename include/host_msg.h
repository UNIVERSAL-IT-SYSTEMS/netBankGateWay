/*
 *	FILENAME:	"host_msg.h"
 *	CREATED DATE:	Wed Oct 31 17:43:42 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"host_msg.txt".
 */

#ifndef _HOST_MSG_H_
#define _HOST_MSG_H_




typedef struct {
	CS_SMALLINT	hmt_host_no;	/*	业务系统编号	*/
	CS_CHAR		hmt_host_name[21];/*	业务系统名称	*/
	CS_SMALLINT	hmt_host_type;	/*	业务系统类型	*/
	CS_SMALLINT	hmt_time_out;	/*	超时秒数	*/
	CS_SMALLINT	hmt_net_status;	/*	网络状态	*/
        } host_msg_t;



int host_msg_SelectBy_hmt_host_no(
	CS_SMALLINT		hmt_host_no,
	host_msg_t	*_host_msg_data);
int host_msg_UpdateBy_hmt_host_no(
	CS_SMALLINT		hmt_host_no,
	host_msg_t	*_host_msg_data);

#endif	 /* _HOST_MSG_H_ */
