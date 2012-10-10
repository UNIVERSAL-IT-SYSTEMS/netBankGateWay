/*
 *	FILENAME:	"TRNFLW.h"
 *	CREATED DATE:	Wed Dec  5 17:01:15 2001
 *	CREATED BY:	tool--tsql v1.0 for Sybase DBS
 *	SOURCE FILE:	"TRNFLW.txt".
 */

#ifndef _TRNFLW_H_
#define _TRNFLW_H_

typedef struct {
	CS_CHAR		TFT_DTE[9];	/*	日期	*/
	CS_CHAR		TFT_BATNO[9];	/*	批次号	*/
	CS_CHAR		TFT_FLWNO[9];	/*	流水号	*/
	CS_CHAR		TFT_TRNCOD[7];	/*	交易代码	*/
	CS_CHAR		TFT_TRFTYP[2];	/*	转帐交易类型	*/
	CS_CHAR		TFT_ACCBRA[4];	/*	付款帐号开户分行	*/
	CS_CHAR		TFT_ACCBRANME[61];/*	付款帐号开户行名	*/
	CS_CHAR		TFT_ACCBNKNO[7];/*	付款帐号联行号	*/
	CS_CHAR		TFT_ACCBNKNME[61];/*	付款帐号联行名	*/
	CS_CHAR		TFT_CRYTYP[3];	/*	付款帐号币种	*/
	CS_CHAR		TFT_CAHRMTFLG[2];/*	付款帐号钞汇标志	*/
	CS_CHAR		TFT_CSTACC[19];	/*	付款帐号	*/
	CS_CHAR		TFT_CSTACCNME[61];/*	付款帐号户名	*/
	CS_DECIMAL	TFT_ACCBAL;	/*	付款帐号余额	*/
	CS_DECIMAL	TFT_TRNAMT;	/*	交易金额	*/
	CS_CHAR		TFT_RCVACC[31];	/*	收款帐号	*/
	CS_CHAR		TFT_RCVACCBRA[4];/*	收款帐号开户分行	*/
	CS_CHAR		TFT_RCVCRYTYP[3];/*	收款帐号币种	*/
	CS_CHAR		TFT_RCVCAHRMTFLG[2];/*	收款帐号钞汇标志	*/
	CS_CHAR		TFT_RCVACCBNK[61];/*	收款帐号开户行名	*/
	CS_CHAR		TFT_RCVACCBNKNO[7];/*	收款帐号联行号	*/
	CS_CHAR		TFT_RCVACCBNKNME[61];/*	收款帐号联行名	*/
	CS_CHAR		TFT_RCVACCNME[61];/*	收款帐号户名	*/
	CS_CHAR		TFT_SPDFLG[2];	/*	普通加急标志	*/
	CS_CHAR		TFT_TRNFLG[2];	/*	预约交易标志	*/
	CS_CHAR		TFT_ABS[201];	/*	交易摘要用途	*/
	CS_CHAR		TFT_NTE[201];	/*	备注	*/
	CS_CHAR		TFT_EXPDTE[9];	/*	期望交易日	*/
	CS_CHAR		TFT_SMTTIM[15];	/*	提交时间	*/
	CS_CHAR		TFT_TRNTIM[15];	/*	交易时间	*/
	CS_CHAR		TFT_STT[3];	/*	状态	*/
	CS_CHAR		TFT_COMSTT[3];	/*	通讯状态	*/
	CS_CHAR		TFT_HSTFLW[7];	/*	主机流水号	*/
	CS_INT		TFT_QRYNUM;	/*	查证次数	*/
	CS_INT		TFT_RETNUM;	/*	返回次数	*/
	CS_CHAR		TFT_TRNMSGCOD[8];/*	交易信息码	*/
	CS_CHAR		TFT_RCVADDCOD[11];/*	收款附加代码	*/
	CS_CHAR		TFT_RES1[21];	/*	预留一	*/
	CS_CHAR		TFT_RES2[21];	/*	预留二	*/
	CS_CHAR		TFT_TELLER_1[11];/*	授权员	*/
	CS_CHAR		TFT_TELLER_2[11];/*	落地员	*/
        } TRNFLW_t;

typedef struct {
	CS_SMALLINT	iTFT_TRFTYP;	/*	转帐交易类型	*/
	CS_SMALLINT	iTFT_ACCBRA;	/*	付款帐号开户分行	*/
	CS_SMALLINT	iTFT_ACCBRANME;	/*	付款帐号开户行名	*/
	CS_SMALLINT	iTFT_ACCBNKNO;	/*	付款帐号联行号	*/
	CS_SMALLINT	iTFT_ACCBNKNME;	/*	付款帐号联行名	*/
	CS_SMALLINT	iTFT_CRYTYP;	/*	付款帐号币种	*/
	CS_SMALLINT	iTFT_CAHRMTFLG;	/*	付款帐号钞汇标志	*/
	CS_SMALLINT	iTFT_CSTACC;	/*	付款帐号	*/
	CS_SMALLINT	iTFT_CSTACCNME;	/*	付款帐号户名	*/
	CS_SMALLINT	iTFT_ACCBAL;	/*	付款帐号余额	*/
	CS_SMALLINT	iTFT_TRNAMT;	/*	交易金额	*/
	CS_SMALLINT	iTFT_RCVACC;	/*	收款帐号	*/
	CS_SMALLINT	iTFT_RCVACCBRA;	/*	收款帐号开户分行	*/
	CS_SMALLINT	iTFT_RCVCRYTYP;	/*	收款帐号币种	*/
	CS_SMALLINT	iTFT_RCVCAHRMTFLG;/*	收款帐号钞汇标志	*/
	CS_SMALLINT	iTFT_RCVACCBNK;	/*	收款帐号开户行名	*/
	CS_SMALLINT	iTFT_RCVACCBNKNO;/*	收款帐号联行号	*/
	CS_SMALLINT	iTFT_RCVACCBNKNME;/*	收款帐号联行名	*/
	CS_SMALLINT	iTFT_RCVACCNME;	/*	收款帐号户名	*/
	CS_SMALLINT	iTFT_SPDFLG;	/*	普通加急标志	*/
	CS_SMALLINT	iTFT_TRNFLG;	/*	预约交易标志	*/
	CS_SMALLINT	iTFT_ABS;	/*	交易摘要用途	*/
	CS_SMALLINT	iTFT_NTE;	/*	备注	*/
	CS_SMALLINT	iTFT_EXPDTE;	/*	期望交易日	*/
	CS_SMALLINT	iTFT_SMTTIM;	/*	提交时间	*/
	CS_SMALLINT	iTFT_TRNTIM;	/*	交易时间	*/
	CS_SMALLINT	iTFT_STT;	/*	状态	*/
	CS_SMALLINT	iTFT_COMSTT;	/*	通讯状态	*/
	CS_SMALLINT	iTFT_HSTFLW;	/*	主机流水号	*/
	CS_SMALLINT	iTFT_QRYNUM;	/*	查证次数	*/
	CS_SMALLINT	iTFT_RETNUM;	/*	返回次数	*/
	CS_SMALLINT	iTFT_TRNMSGCOD;	/*	交易信息码	*/
	CS_SMALLINT	iTFT_RCVADDCOD;	/*	收款附加代码	*/
	CS_SMALLINT	iTFT_RES1;	/*	预留一	*/
	CS_SMALLINT	iTFT_RES2;	/*	预留二	*/
	CS_SMALLINT	iTFT_TELLER_1;	/*	授权员	*/
	CS_SMALLINT	iTFT_TELLER_2;	/*	落地员	*/
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
