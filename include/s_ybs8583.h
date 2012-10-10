/*
 * Name:	8583.h
 */
#include "ybs8583.h"

#ifndef _ybs8583
#define _ybs8583



#ifdef  __cplusplus
extern  "C"
{
#endif

/*
 * Name:	iso8583.c
 */

int YBSstrtoiso ( unsigned char * dstr , ISO_data * iso ) ;
int YBSisotostr ( unsigned char * dstr , ISO_data * iso ) ;
int YBSsetbit ( ISO_data * iso , int n , char * str , int len ) ;
int YBSgetbit ( ISO_data * iso , int n , char * str ) ;
void YBSclearbit ( ISO_data * iso ) ;
void YBSclearonebit ( ISO_data * iso, int bit ) ;

/*
 * Name:	iso8583_post.c
 */
/*
int strtoiso_post ( unsigned char * dstr , ISO_data * iso ) ;
int isotostr_post ( unsigned char * dstr , ISO_data * iso ) ;
int setbit_post ( ISO_data * iso , int n , char * str , int len ) ;
int getbit_post ( ISO_data * iso , int n , char * str ) ;
void clearbit_post ( ISO_data * iso ) ;
void clearonebit_post ( ISO_data * iso, int bit ) ;
*/
void YBSbcd_to_asc ( unsigned char* ascii_buf, unsigned char* bcd_buf,
        int conv_len, unsigned char type );

void YBSasc_to_bcd ( unsigned char* bcd_buf, unsigned char* ascii_buf,
        int conv_len, unsigned type );
#ifdef  __cplusplus
}
#endif

#endif
