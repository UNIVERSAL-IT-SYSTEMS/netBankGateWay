/*
 *	FILENAME:	"TRNFLW.h"
 *	CREATED DATE:	Wed Dec  5 17:01:15 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"TRNFLW.txt".
 */

#ifndef _TRNFLW_H_
#define _TRNFLW_H_

typedef struct {
	CS_CHAR		TFT_DTE[9];	/*	����	*/
	CS_CHAR		TFT_BATNO[9];	/*	���κ�	*/
	CS_CHAR		TFT_FLWNO[9];	/*	��ˮ��	*/
	CS_CHAR		TFT_TRNCOD[7];	/*	���״���	*/
	CS_CHAR		TFT_TRFTYP[2];	/*	ת�ʽ�������	*/
	CS_CHAR		TFT_ACCBRA[4];	/*	�����ʺſ�������	*/
	CS_CHAR		TFT_ACCBRANME[61];/*	�����ʺſ�������	*/
	CS_CHAR		TFT_ACCBNKNO[7];/*	�����ʺ����к�	*/
	CS_CHAR		TFT_ACCBNKNME[61];/*	�����ʺ�������	*/
	CS_CHAR		TFT_CRYTYP[3];	/*	�����ʺű���	*/
	CS_CHAR		TFT_CAHRMTFLG[2];/*	�����ʺų����־	*/
	CS_CHAR		TFT_CSTACC[19];	/*	�����ʺ�	*/
	CS_CHAR		TFT_CSTACCNME[61];/*	�����ʺŻ���	*/
	CS_DECIMAL	TFT_ACCBAL;	/*	�����ʺ����	*/
	CS_DECIMAL	TFT_TRNAMT;	/*	���׽��	*/
	CS_CHAR		TFT_RCVACC[31];	/*	�տ��ʺ�	*/
	CS_CHAR		TFT_RCVACCBRA[4];/*	�տ��ʺſ�������	*/
	CS_CHAR		TFT_RCVCRYTYP[3];/*	�տ��ʺű���	*/
	CS_CHAR		TFT_RCVCAHRMTFLG[2];/*	�տ��ʺų����־	*/
	CS_CHAR		TFT_RCVACCBNK[61];/*	�տ��ʺſ�������	*/
	CS_CHAR		TFT_RCVACCBNKNO[7];/*	�տ��ʺ����к�	*/
	CS_CHAR		TFT_RCVACCBNKNME[61];/*	�տ��ʺ�������	*/
	CS_CHAR		TFT_RCVACCNME[61];/*	�տ��ʺŻ���	*/
	CS_CHAR		TFT_SPDFLG[2];	/*	��ͨ�Ӽ���־	*/
	CS_CHAR		TFT_TRNFLG[2];	/*	ԤԼ���ױ�־	*/
	CS_CHAR		TFT_ABS[201];	/*	����ժҪ��;	*/
	CS_CHAR		TFT_NTE[201];	/*	��ע	*/
	CS_CHAR		TFT_EXPDTE[9];	/*	����������	*/
	CS_CHAR		TFT_SMTTIM[15];	/*	�ύʱ��	*/
	CS_CHAR		TFT_TRNTIM[15];	/*	����ʱ��	*/
	CS_CHAR		TFT_STT[3];	/*	״̬	*/
	CS_CHAR		TFT_COMSTT[3];	/*	ͨѶ״̬	*/
	CS_CHAR		TFT_HSTFLW[7];	/*	������ˮ��	*/
	CS_INT		TFT_QRYNUM;	/*	��֤����	*/
	CS_INT		TFT_RETNUM;	/*	���ش���	*/
	CS_CHAR		TFT_TRNMSGCOD[8];/*	������Ϣ��	*/
	CS_CHAR		TFT_RCVADDCOD[11];/*	�տ�Ӵ���	*/
	CS_CHAR		TFT_RES1[21];	/*	Ԥ��һ	*/
	CS_CHAR		TFT_RES2[21];	/*	Ԥ����	*/
	CS_CHAR		TFT_TELLER_1[11];/*	��ȨԱ	*/
	CS_CHAR		TFT_TELLER_2[11];/*	���Ա	*/
        } TRNFLW_t;

typedef struct {
	CS_SMALLINT	iTFT_TRFTYP;	/*	ת�ʽ�������	*/
	CS_SMALLINT	iTFT_ACCBRA;	/*	�����ʺſ�������	*/
	CS_SMALLINT	iTFT_ACCBRANME;	/*	�����ʺſ�������	*/
	CS_SMALLINT	iTFT_ACCBNKNO;	/*	�����ʺ����к�	*/
	CS_SMALLINT	iTFT_ACCBNKNME;	/*	�����ʺ�������	*/
	CS_SMALLINT	iTFT_CRYTYP;	/*	�����ʺű���	*/
	CS_SMALLINT	iTFT_CAHRMTFLG;	/*	�����ʺų����־	*/
	CS_SMALLINT	iTFT_CSTACC;	/*	�����ʺ�	*/
	CS_SMALLINT	iTFT_CSTACCNME;	/*	�����ʺŻ���	*/
	CS_SMALLINT	iTFT_ACCBAL;	/*	�����ʺ����	*/
	CS_SMALLINT	iTFT_TRNAMT;	/*	���׽��	*/
	CS_SMALLINT	iTFT_RCVACC;	/*	�տ��ʺ�	*/
	CS_SMALLINT	iTFT_RCVACCBRA;	/*	�տ��ʺſ�������	*/
	CS_SMALLINT	iTFT_RCVCRYTYP;	/*	�տ��ʺű���	*/
	CS_SMALLINT	iTFT_RCVCAHRMTFLG;/*	�տ��ʺų����־	*/
	CS_SMALLINT	iTFT_RCVACCBNK;	/*	�տ��ʺſ�������	*/
	CS_SMALLINT	iTFT_RCVACCBNKNO;/*	�տ��ʺ����к�	*/
	CS_SMALLINT	iTFT_RCVACCBNKNME;/*	�տ��ʺ�������	*/
	CS_SMALLINT	iTFT_RCVACCNME;	/*	�տ��ʺŻ���	*/
	CS_SMALLINT	iTFT_SPDFLG;	/*	��ͨ�Ӽ���־	*/
	CS_SMALLINT	iTFT_TRNFLG;	/*	ԤԼ���ױ�־	*/
	CS_SMALLINT	iTFT_ABS;	/*	����ժҪ��;	*/
	CS_SMALLINT	iTFT_NTE;	/*	��ע	*/
	CS_SMALLINT	iTFT_EXPDTE;	/*	����������	*/
	CS_SMALLINT	iTFT_SMTTIM;	/*	�ύʱ��	*/
	CS_SMALLINT	iTFT_TRNTIM;	/*	����ʱ��	*/
	CS_SMALLINT	iTFT_STT;	/*	״̬	*/
	CS_SMALLINT	iTFT_COMSTT;	/*	ͨѶ״̬	*/
	CS_SMALLINT	iTFT_HSTFLW;	/*	������ˮ��	*/
	CS_SMALLINT	iTFT_QRYNUM;	/*	��֤����	*/
	CS_SMALLINT	iTFT_RETNUM;	/*	���ش���	*/
	CS_SMALLINT	iTFT_TRNMSGCOD;	/*	������Ϣ��	*/
	CS_SMALLINT	iTFT_RCVADDCOD;	/*	�տ�Ӵ���	*/
	CS_SMALLINT	iTFT_RES1;	/*	Ԥ��һ	*/
	CS_SMALLINT	iTFT_RES2;	/*	Ԥ����	*/
	CS_SMALLINT	iTFT_TELLER_1;	/*	��ȨԱ	*/
	CS_SMALLINT	iTFT_TELLER_2;	/*	���Ա	*/
        } i_TRNFLW_t;

int TRNFLW_Insert( 
	TRNFLW_t	*_TRNFLW_data,
	i_TRNFLW_t	*_i_TRNFLW_data);
int TRNFLW_SelectBy_TFT_FLWNO(
	CS_CHAR		*TFT_FLWNO,
	TRNFLW_t	*_TRNFLW_data,
	i_TRNFLW_t	*_i_TRNFLW_data);
int TRNFLW_UpdateBy_TFT_FLWNO(
	CS_CHAR		*TFT_FLWNO,
	TRNFLW_t	*_TRNFLW_data,
	i_TRNFLW_t	*_i_TRNFLW_data);
int TRNFLW_SelectCursorBy_TFT_COMSTT(
	CS_CHAR	*TFT_COMSTT_1,
	CS_CHAR *TFT_COMSTT_2,
	TRNFLW_t	*_TRNFLW_data,
	i_TRNFLW_t	*_i_TRNFLW_data);
int TRNFLW_FetchCursor( TRNFLW_t	*_TRNFLW_data ,i_TRNFLW_t	*_i_TRNFLW_data	);
int TRNFLW_UpdateByLock(TRNFLW_t	*_TRNFLW_data ,
	i_TRNFLW_t	*_i_TRNFLW_data );
int TRNFLW_CloseCursor( );
int TRNFLW_DeleteBy_TFT_FLWNO(
	CS_CHAR	*TFT_FLWNO	);

#endif	 /* _TRNFLW_H_ */
