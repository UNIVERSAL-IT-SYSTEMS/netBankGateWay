/*
 *	FILENAME:	"send_packet.h"
 *	CREATED DATE:	Wed Oct 31 12:33:20 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"send_packet.txt".
 */

#ifndef _SEND_PACKET_H_
#define _SEND_PACKET_H_




typedef struct {
	CS_CHAR		spt_tr_date[11];/*	��������	*/
	CS_CHAR		spt_tr_time[9];	/*	����ʱ��	*/
	CS_INT		spt_tr_serial;	/*	��ˮ��	*/
	CS_TEXT		spt_xml_packet[3000];	/*	XML����	*/
        } send_packet_t;

typedef struct {
	CS_SMALLINT	ispt_xml_packet;/*	XML����	*/
        } i_send_packet_t;



int send_packet_Insert( 
	send_packet_t	*_send_packet_data,
	i_send_packet_t	*_i_send_packet_data);
int send_packet_SelectBy_spt_tr_serial(
	long		spt_tr_serial,
	send_packet_t	*_send_packet_data,
	i_send_packet_t	*_i_send_packet_data);

#endif	 /* _SEND_PACKET_H_ */
