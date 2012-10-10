/*
 *	FILENAME:	"trade_msg.h"
 *	CREATED DATE:	Wed Oct 31 17:43:43 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"trade_msg.txt".
 */

#ifndef _TRADE_MSG_H_
#define _TRADE_MSG_H_




typedef struct {
	CS_CHAR		tmt_trade_id[31];/*	���ױ�ʶ	*/
	CS_CHAR		tmt_trade_name[51];/*	��������	*/
	CS_SMALLINT	tmt_tr_open_flag;/*	���׿�ͨ��־	*/
	CS_SMALLINT	tmt_tr_attr1;	/*	��������һ	*/
	CS_SMALLINT	tmt_tr_attr2;	/*	�������Զ�	*/
	CS_SMALLINT	tmt_tr_attr3;	/*	����������	*/
        } trade_msg_t;

typedef struct {
	CS_SMALLINT	itmt_tr_open_flag;/*	���׿�ͨ��־	*/
	CS_SMALLINT	itmt_tr_attr1;	/*	��������һ	*/
	CS_SMALLINT	itmt_tr_attr2;	/*	�������Զ�	*/
	CS_SMALLINT	itmt_tr_attr3;	/*	����������	*/
        } i_trade_msg_t;



int trade_msg_SelectBy_tmt_trade_id(
	CS_CHAR		*tmt_trade_id,
	trade_msg_t	*_trade_msg_data,
	i_trade_msg_t	*_i_trade_msg_data);

#endif	 /* _TRADE_MSG_H_ */
