/*
 *	FILENAME:	"return_flow.h"
 *	CREATED DATE:	Wed Oct 31 12:33:20 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"return_flow.txt".
 */

#ifndef _XML_FLOW_H_
#define _XML_FLOW_H_




typedef struct {
	CS_INT		rft_flow_no;	/*	��ˮ��	*/
	CS_SMALLINT	rft_flow_status;/*	��ˮ״̬	*/
	CS_INT		rft_flow_length;/*	��ˮ����	*/
	CS_SMALLINT	rft_flow_failed;/*	ʧ�ܴ���	*/
	CS_TEXT		rft_flow_buffer[3000];/*	��ˮ����	*/
        } return_flow_t;

typedef struct {
	CS_SMALLINT	irft_flow_buffer;/*	��ˮ����	*/
        } i_return_flow_t;



int return_flow_Insert( 
	return_flow_t	*_return_flow_data,
	i_return_flow_t	*_i_return_flow_data);
int return_flow_SelectBy_rft_flow_no(
	long		rft_flow_no,
	return_flow_t	*_return_flow_data,
	i_return_flow_t	*_i_return_flow_data);
int return_flow_UpdateBy_rft_flow_no(
	long		rft_flow_no,
	return_flow_t	*_return_flow_data,
	i_return_flow_t	*_i_return_flow_data);
int return_flow_SelectCursorBy_rft_flow_status(
	CS_SMALLINT	rft_flow_status,
	return_flow_t	*_return_flow_data,
	i_return_flow_t	*_i_return_flow_data);
int return_flow_FetchCursor( return_flow_t	*_return_flow_data ,i_return_flow_t	*_i_return_flow_data	);
int return_flow_UpdateByLock(
	return_flow_t	*_return_flow_data ,
	i_return_flow_t	*_i_return_flow_data );
int return_flow_CloseCursor( );

#endif	 /* _XML_FLOW_H_ */
