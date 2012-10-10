/****************************************
 *程序名:trans928460.c
 *功  能:密码验证
 *日  期:
 ****************************************/

#include        <stdio.h>
#include        <stdlib.h>
#include        <memory.h>
#include        <signal.h>
#include        <sys/types.h>
#include        <time.h>
#include        <errno.h>
#include        <dlfcn.h>
#include        "trans_macro.h"
#include        "trans_struct.h"
#include        "netbank_mid.h"
#include        "error.h"


extern int Encrypt_Pin( const char*, const char*, const char*, const char*, const char*, const char*, char *pinBlk );


int ics_proc_928460(channel_type, account_no, password_type, password, rspcod )
	char	*channel_type;
	char	*account_no;
	char	*password_type;
	char	*password;
	char	*rspcod;
{
	ICS_DEF_TIA           *pICS_TIA;
	ICS_DEF_TOA           *pICS_TOA;
	ICS_DEF_928460_I      *pICS_928460_I;

	char                  send_buff[LEN_ICS_PROC_BUF];
	char                  recv_buff[LEN_ICS_PROC_BUF];
	char                  ics_928460i_buff[94];
	char                  tia_buff[171];
	char                  toa_buff[114];
	char                  n_buff[256];
	char                  e_buff[256];

	FILE                  *fp;

	int	i;
	int	ret;
	int	len;
	int	offset;
	char	sLen[8];
	char	sTranNo[16];
	char	sTranDate[11];
	char	sTellerNo[8];
	char	ics_port[6];
	time_t	cur_time;
	struct	tm*my_tm;

	char	PINBlock[20];

	memset(send_buff,0,sizeof(send_buff));
	memset(recv_buff,0,sizeof(recv_buff));
	memset(tia_buff,0,sizeof(tia_buff));
	memset(toa_buff,0,sizeof(toa_buff));
	memset(ics_928460i_buff,0,sizeof(ics_928460i_buff));

	pICS_928460_I=(ICS_DEF_928460_I *)ics_928460i_buff;
  pICS_TIA=(ICS_DEF_TIA *)tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)toa_buff;

  memset(sLen,'\0',sizeof(sLen));
  memset(sTranNo,'\0',sizeof(sTranNo));
  memset(sTranDate,'\0',sizeof(sTranDate));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
	memset(ics_port,'\0',sizeof(ics_port));
	memcpy(sLen,'\0',8);

  memset(PINBlock,'\0',sizeof(PINBlock));

	/* fill the HSTTIA */
	strcpy(pICS_TIA->CCSCod,"TLU6");   /* CICS交易代码 */
	strcpy(pICS_TIA->TTxnCd,"928460");
	strcpy(pICS_TIA->FeCod,"928460");
	strcpy(pICS_TIA->TrmNo,"DVID");
	strcpy(pICS_TIA->TxnSrc,"T0001");

	time(&cur_time);
	my_tm = localtime(&cur_time);
	sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
	sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);

	strcpy(pICS_TIA->NodTrc,sTranNo);

	ret = get_config_value(CONFIG_FILE_NAME, "TELLER_NO", sTellerNo);
	if (ret != RETURN_OK)
		return -4;

	strcpy(pICS_TIA->TlrId,sTellerNo);
	strcpy(pICS_TIA->TIATyp,"T");
	strcpy(pICS_TIA->AthLvl,"00");
	strcpy(pICS_TIA->Sup1Id," ");
	strcpy(pICS_TIA->Sup2Id," ");
	strcpy(pICS_TIA->Sup1Pw," ");
	strcpy(pICS_TIA->Sup2Pw," ");
	strcpy(pICS_TIA->Sup1Dv," ");
	strcpy(pICS_TIA->Sup2Dv," ");
	strcpy(pICS_TIA->AthTbl," ");
	strcpy(pICS_TIA->AthLog," ");
	strcpy(pICS_TIA->HLogNo," ");
	strcpy(pICS_TIA->CprInd,"0");
	strcpy(pICS_TIA->EnpInd,"0");
	strcpy(pICS_TIA->NodNo,"441200");
	strcpy(pICS_TIA->OprLvl," ");
	strcpy(pICS_TIA->TrmVer,"v0000001");
	strcpy(pICS_TIA->OutSys," ");
	strcpy(pICS_TIA->Fil," ");

	/* 调用加密函数 */
  /*****
	ret = Encrypt_Pin("18","30","",password,account_no,"441",PINBlock);
	if( ret < 0 )
	{
		flog( STEP_LEVEL,"调用加密函数失败[%d]",ret);
		return -1;
	}
	strcat( PINBlock, "3000" );
  *****/
  strcpy( PINBlock, password );

	/* fill 928460 message */
	strcpy(pICS_928460_I->TxnCnl,channel_type);
	strcpy(pICS_928460_I->ActNo,account_no);
	strcpy(pICS_928460_I->CusId," ");
	strcpy(pICS_928460_I->PINTyp,password_type);
	strcpy(pICS_928460_I->PINDat,PINBlock);
	strcpy(pICS_928460_I->InqFlg,"0"); /*客户信息查询标志:0-不查询;1-查询*/
	strcpy(pICS_928460_I->Trk2Dat,"                                     ");

	/* pack send buffer */
	offset=0;
	offset=offset+8;

	len=sizeof(ICS_DEF_TIA);
	flog( STEP_LEVEL,"ICS_DEF_TIA len=[%d]",len);
	for(i=0;i<len;i++)
	{
		if(tia_buff[i]==0)
      tia_buff[i]=' ';
	}
	memcpy(send_buff+offset,tia_buff,len);
	flog( STEP_LEVEL,"928460 len=[%d] tia_buff=[%s]",len,tia_buff);
	
	offset=offset+sizeof(ICS_DEF_TIA);

	len=sizeof(ICS_DEF_928460_I);
	flog( STEP_LEVEL,"ICS_DEF_928460_I len=[%d]",len);
	for(i=0;i<len;i++)
	{
		if(ics_928460i_buff[i]==0)
      ics_928460i_buff[i]=' ';
	}
	memcpy(send_buff+offset,ics_928460i_buff,len);
	offset=offset+sizeof(ICS_DEF_928460_I);
 
	sprintf(sLen,"%08d",offset-8);
	memcpy(send_buff,sLen,8);

	send_buff[offset] = '\0';
	flog( STEP_LEVEL,"928460 send_buff=[%s]",send_buff);

	/* communicate with ics */
	ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_CHKPW", ics_port);
	if (ret != RETURN_OK)
		return -5;

	ret=clientics( send_buff, recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
     return -3;

	/* read the HSTTIA and return */
	memcpy(toa_buff,recv_buff,sizeof(toa_buff));

	memcpy( rspcod, pICS_TOA->RspCod, 6 );

	if( memcmp( rspcod, "000000", 6 ) ==0 )
	{
		memcpy(n_buff,recv_buff+sizeof(toa_buff),256);
	}

	return 0;
}
