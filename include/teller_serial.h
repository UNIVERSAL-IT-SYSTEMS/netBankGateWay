/*
 *	FILENAME:	"teller_serial.h"
 *	CREATED DATE:	Mon Dec  3 14:01:01 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"teller_serial.txt".
 */

#ifndef _TELLER_SERIAL_H_
#define _TELLER_SERIAL_H_

typedef struct {
	CS_CHAR		teller_no[11];	/*	柜员号	*/
	CS_CHAR		teller_status[3];/*	柜员状态	*/
	CS_INT		teller_serial;	/*	柜员流水号	*/
        } teller_serial_t;

int teller_serial_SelectBy_teller_no(
	CS_CHAR		*teller_no,
	teller_serial_t	*_teller_serial_data);
int teller_serial_Insert( 
	teller_serial_t	*_teller_serial_data);
int teller_serial_UpdateBy_teller_no(
	CS_CHAR		*teller_no,
	teller_serial_t	*_teller_serial_data);
int teller_serial_Reset(void);
int teller_serial_Increase_teller_serial(CS_CHAR* teller_no);

#endif	 /* _TELLER_SERIAL_H_ */
