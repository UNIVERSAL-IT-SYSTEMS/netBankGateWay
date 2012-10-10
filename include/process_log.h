/*
 *	FILENAME:	"process_log.h"
 *	CREATED DATE:	Wed Oct 31 12:33:20 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"process_log.txt".
 */

#ifndef _PROCESS_LOG_H_
#define _PROCESS_LOG_H_




typedef struct {
	CS_NUMERIC	plt_tr_seq;	/*	��־˳���	*/
	CS_CHAR		plt_tr_date[11];/*	��������	*/
	CS_CHAR		plt_tr_time[9];	/*	����ʱ��	*/
	CS_INT		plt_tr_serial;	/*	��ˮ��	*/
	CS_CHAR		plt_prg_name[21];/*	���������	*/
	CS_SMALLINT	plt_last_status;/*	�ϴ�״̬	*/
	CS_SMALLINT	plt_cur_status;	/*	��ǰ״̬	*/
	CS_CHAR		plt_note[101];	/*	��ע��Ϣ	*/
        } process_log_t;

typedef struct {
	CS_SMALLINT	iplt_note;	/*	��ע��Ϣ	*/
        } i_process_log_t;



int process_log_Insert( 
	process_log_t	*_process_log_data,
	i_process_log_t	*_i_process_log_data);
int process_log_SelectCursorBy_plt_tr_serial(
	long	plt_tr_serial,
	process_log_t	*_process_log_data,
	i_process_log_t	*_i_process_log_data);
int process_log_CloseCursor( );

#endif	 /* _PROCESS_LOG_H_ */
