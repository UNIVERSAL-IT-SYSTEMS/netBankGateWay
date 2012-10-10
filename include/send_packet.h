/*
 *	FILENAME:	"send_packet.h"
 *	CREATED DATE:	Wed Oct 31 12:33:20 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"send_packet.txt".
 */

#ifndef _SEND_PACKET_H_
#define _SEND_PACKET_H_




typedef struct {
	CS_CHAR		spt_tr_date[11];/*	交易日期	*/
	CS_CHAR		spt_tr_time[9];	/*	交易时间	*/
	CS_INT		spt_tr_serial;	/*	流水号	*/
	CS_TEXT		spt_xml_packet[3000];	/*	XML报文	*/
        } send_packet_t;

typedef struct {
	CS_SMALLINT	ispt_xml_packet;/*	XML报文	*/
        } i_send_packet_t;



int send_packet_Insert( 
	send_packet_t	*_send_packet_data,
	i_send_packet_t	*_i_send_packet_data);
int send_packet_SelectBy_spt_tr_serial(
	long		spt_tr_serial,
	send_packet_t	*_send_packet_data,
	i_send_packet_t	*_i_send_packet_data);

#endif	 /* _SEND_PACKET_H_ */
