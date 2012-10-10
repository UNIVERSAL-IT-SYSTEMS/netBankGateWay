/*
 *	FILENAME:	"recv_packet.h"
 *	CREATED DATE:	Wed Oct 31 12:33:20 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"recv_packet.txt".
 */

#ifndef _RECV_PACKET_H_
#define _RECV_PACKET_H_




typedef struct {
	CS_CHAR		rpt_tr_date[11];/*	交易日期	*/
	CS_CHAR		rpt_tr_time[9];	/*	交易时间	*/
	CS_INT		rpt_tr_serial;	/*	流水号	*/
	CS_TEXT		rpt_xml_packet[3000];	/*	XML报文	*/
        } recv_packet_t;

typedef struct {
	CS_SMALLINT	irpt_xml_packet;/*	XML报文	*/
        } i_recv_packet_t;



int recv_packet_Insert( 
	recv_packet_t	*_recv_packet_data,
	i_recv_packet_t	*_i_recv_packet_data);
int recv_packet_SelectBy_rpt_tr_serial(
	long		rpt_tr_serial,
	recv_packet_t	*_recv_packet_data,
	i_recv_packet_t	*_i_recv_packet_data);

#endif	 /* _RECV_PACKET_H_ */
