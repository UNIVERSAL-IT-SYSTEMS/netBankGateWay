/****************************************
 *程序名:subtrans461191.c
 *功  能:公务员卡明细查询
 *日  期:2007.12.19
 ****************************************/

#include        <stdio.h>
#include        <stdlib.h>
#include        <memory.h>
#include        <signal.h>
#include        <sys/types.h>
#include        <time.h>
#include        <errno.h>
#include        "trans_macro.h"
#include        "trans_struct.h"
#include        "netbank_mid.h"
#include        "error.h"


int ics_proc_461191(char *send_buff,char *recv_buff)
{
  /*说明：send_buff-上传报文；
          recv_buff-下传报文;
          ics_send_buff-与后台通讯的发送串;
          ics_recv_buff-与后台通讯的接收串;
 */

  int			i;	
  int 			len;
  int     		ret;
  int			offset;
  int			i_biz_id;
  int			iRecNum;	

/* 此交易没有报文头
  ICS_DEF_TIA		*pICS_TIA;
  ICS_DEF_TOA		*pICS_TOA;
*/
  ICS_DEF_461191_I	*pICS_461191_I;
  ICS_DEF_461191_O	*pICS_461191_O;
  ICS_DEF_461191_G	*pICS_461191_G;

  char			tmp_send_buff[LEN_ICS_PROC_BUF];
  char			ics_send_buff[LEN_ICS_PROC_BUF];
  char			ics_recv_buff[LEN_ICS_PROC_BUF];

  char			ics_461191i_buff[99];
  char			ics_461191o_buff[70];
  char			ics_461191g_buff[292];

/* 此交易没有报文头
  char			ics_tia_buff[171];
  char			ics_toa_buff[114];
*/
  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			display_str[LEN_ICS_PROC_BUF];
  char			tmpvalue[LEN_TMP_VAL_STR];/*从上传报文中取得的某项值*/
  char			sLen[8];
  char			sLeft[14];
  char			sRight[3];
  char			ics_port[6];
  char			batch_buff[LEN_ICS_PROC_BUF];
  char			tmp_batch_buff[LEN_TMP_VAL_STR];

  FILE 			*fp;

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */

  pICS_461191_I=(ICS_DEF_461191_I *)ics_461191i_buff;
  pICS_461191_O=(ICS_DEF_461191_O *)ics_461191o_buff;
  pICS_461191_G=(ICS_DEF_461191_G *)ics_461191g_buff;

/* 此交易没有报文头
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;
*/

	memset(ics_461191i_buff,'\0',sizeof(ics_461191i_buff));
	memset(ics_461191o_buff,'\0',sizeof(ics_461191o_buff));
	memset(ics_461191g_buff,'\0',sizeof(ics_461191g_buff));

	memset(tmp_send_buff,'\0',sizeof(tmp_send_buff));
	memset(ics_send_buff,'\0',sizeof(ics_send_buff));
	memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));

/* 此交易没有报文头
	memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
	memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));
*/

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(display_str,'\0',sizeof(display_str));
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  
/*
fp=fopen("./461191.log","a");
fprintf(fp,"上传串send_buff=[%s]\n",send_buff);
fclose(fp);
*/

 /* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
 /* STEP1-2:填上传串的固定头 */
/* 此交易没有报文头
  strcpy(pICS_TIA->CCSCod,"TLU6");   * CICS交易代码 *
  strcpy(pICS_TIA->TTxnCd,"461191");
  strcpy(pICS_TIA->FeCod,"461191");
  strcpy(pICS_TIA->TrmNo,"DVID");
  strcpy(pICS_TIA->TxnSrc,"T0001");   
  strcpy(pICS_TIA->NodTrc,"200704100044191");
  strcpy(pICS_TIA->TlrId,"AFAM020");
  strcpy(pICS_TIA->TIATyp,"T");
  strcpy(pICS_TIA->AthLvl,"00");
  strcpy(pICS_TIA->Sup1Id,"       ");
  strcpy(pICS_TIA->Sup2Id,"       ");
  strcpy(pICS_TIA->Sup1Pw,"      ");
  strcpy(pICS_TIA->Sup2Pw,"      ");
  strcpy(pICS_TIA->Sup1Dv," ");
  strcpy(pICS_TIA->Sup2Dv," ");
  strcpy(pICS_TIA->AthTbl,"                                                            ");
  strcpy(pICS_TIA->AthLog," ");
  strcpy(pICS_TIA->HLogNo,"         ");
  strcpy(pICS_TIA->CprInd,"0");
  strcpy(pICS_TIA->EnpInd,"0");
  strcpy(pICS_TIA->NodNo,"444086");
  strcpy(pICS_TIA->OprLvl," ");
  strcpy(pICS_TIA->TrmVer,"v0000001");
  strcpy(pICS_TIA->OutSys," ");
  strcpy(pICS_TIA->Fil,"  ");
*/

  offset=0;

  strcpy(pICS_461191_I->TxnCod,"461191");	/*交易码*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->TxnCod, 6 );
  offset += 6;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"PfaSub",tmpvalue);
  strcpy(pICS_461191_I->PfaSub,tmpvalue);			

  memcpy( tmp_send_buff + offset, pICS_461191_I->PfaSub, 3 );
  offset += 3;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"BCusId",tmpvalue);
  strcpy(pICS_461191_I->BCusId,tmpvalue);		/*预算单位编码*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->BCusId, 18 );
  offset += 18;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"CardNo",tmpvalue);
  strcpy(pICS_461191_I->CardNo,tmpvalue);		/*卡号*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->CardNo, 19 );
  offset += 19;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"BgnDat",tmpvalue);
  strcpy(pICS_461191_I->BgnDat,tmpvalue);		/*起始日期*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->BgnDat, 8 );
  offset += 8;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"EndDat",tmpvalue);
  strcpy(pICS_461191_I->EndDat,tmpvalue);		/*终止日期*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->EndDat, 8 );
  offset += 8;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"MinAmt",tmpvalue);
  strcpy(pICS_461191_I->MinAmt,tmpvalue);		/*最低金额*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->MinAmt, 15 );
  offset += 15;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"MaxAmt",tmpvalue);
  strcpy(pICS_461191_I->MaxAmt,tmpvalue);		/*最高金额*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->MaxAmt, 15 );
  offset += 15;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"Dtlsts",tmpvalue);
  strcpy(pICS_461191_I->Dtlsts,tmpvalue);		/*状态*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->Dtlsts, 1 );
  offset += 1;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"MaxPNm",tmpvalue);
  strcpy(pICS_461191_I->MaxPNm,tmpvalue);		/*查询最大笔数*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->MaxPNm, 4 );
  offset += 4;

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"PageNm",tmpvalue);
  strcpy(pICS_461191_I->PageNm,tmpvalue);		/*查询页号*/

  memcpy( tmp_send_buff + offset, pICS_461191_I->PageNm, 2 );
  offset += 2;

  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/

/*
fp=fopen("./461191.log","a");
fprintf(fp,"BEFORE CLEAR: [%s]\n",ics_461191i_buff);
fclose(fp);
*/

  /*发往ICS需加8位报文长度*/

  offset=0;
  offset=offset+8;

  len=sizeof(ICS_DEF_461191_I);
  for(i=0;i<len;i++)
  {
    if(ics_461191i_buff[i]==0)
	ics_461191i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_461191i_buff,len);
  offset=offset+sizeof(ICS_DEF_461191_I);

/*
  len = strlen( tmp_send_buff );
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",len);
  memcpy(ics_send_buff,sLen,8);

  memcpy(ics_send_buff+8,tmp_send_buff,len);
*/

  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[len+8] = '\0';

  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
   /* 与ICS通讯 */
   memset(ics_port,'\0',sizeof(ics_port));

   ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_GWY", ics_port);
   if (ret != RETURN_OK)
		return -2;

/*
fp=fopen("./461191.log","a");
fprintf(fp,"TO ICS: [%s]\n",ics_send_buff);
fclose(fp);
*/

   ret=clientics( ics_send_buff,ics_recv_buff, atoi(ics_port) );
   if(ret != RETURN_OK)
	return -1;

/*
fp=fopen("./461191.log","a");
fprintf(fp,"FROM ICS: [%s]\n",ics_recv_buff);
fclose(fp);
*/

/* 此交易没有报文头
    memcpy(pICS_TOA,ics_recv_buff,sizeof(ICS_DEF_TOA));

fp=fopen("/app/ics/DEVP/Gz/txzz/log/461191.log","a");
fprintf(fp,"TOA=[%s]\nRspCod=[%s]\n",pICS_TOA,pICS_TOA->RspCod);
fclose(fp);
*/

  /*--------------------STEP3:通讯后处理:组成回传报文------------------*/

/* 返回接口不唯一
*/
fp=fopen("./461191.log","a");
fprintf(fp,"==================================\n");
fclose(fp);
	memcpy(pICS_461191_O,ics_recv_buff,sizeof(ICS_DEF_461191_O));

fp=fopen("./461191.log","a");
fprintf(fp,"222==================================\n");
fclose(fp);
	memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	memcpy( tmpvalue, pICS_461191_O->RspCod, sizeof(pICS_461191_O->RspCod));
	setValueOfStr( recv_buff, "ret_code", tmpvalue );
fp=fopen("./461191.log","a");
fprintf(fp,"RspCod=[%s]\n",tmpvalue);
fclose(fp);

	memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	memcpy( tmpvalue, pICS_461191_O->RspMsg, sizeof(pICS_461191_O->RspMsg));
	setValueOfStr( recv_buff, "ret_msg", trim( tmpvalue ) ) ;

	memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	memcpy( tmpvalue, pICS_461191_O->RecNum, sizeof(pICS_461191_O->RecNum));
	setValueOfStr( recv_buff, "rec_cnt", trim( tmpvalue ) );
fp=fopen("./461191.log","a");
fprintf(fp,"RecNum=[%s]\n",tmpvalue);
fclose(fp);

	iRecNum = atoi( tmpvalue );

	memset( batch_buff, '\0', sizeof( batch_buff ) );
	for ( i = 0 ; i < iRecNum ; i ++ )
	{
	  memset( ics_461191g_buff, '\0', sizeof( ics_461191g_buff ) ) ;
	  memcpy( pICS_461191_G, ics_recv_buff + sizeof( ICS_DEF_461191_O ) + sizeof( ICS_DEF_461191_G )*i, sizeof( ICS_DEF_461191_G ) ) ;

	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "rec_id,%d;", i + 1 );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf( fp, "第条[%d]记录\n", i + 1 ) ;
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->CardNo,sizeof(pICS_461191_G->CardNo));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "CardNo,%s;", trim( tmpvalue ) );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"CardNo=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->CardNm,sizeof(pICS_461191_G->CardNm));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "CardNm,%s;", trim( tmpvalue ) );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"CardNm=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->TxnDat,sizeof(pICS_461191_G->TxnDat));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "TxnDat,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"TxnDat=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->TxnTim,sizeof(pICS_461191_G->TxnTim));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "TxnTim,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"TxnTim=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->MerId ,sizeof(pICS_461191_G->MerId ));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "MerId,%s;", trim( tmpvalue ) ) ;
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"MerId =[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->TermId,sizeof(pICS_461191_G->TermId));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "TermId,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"TermId=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->MerNam,sizeof(pICS_461191_G->MerNam));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "MerNam,%s;", trim( tmpvalue ) ) ;
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"MerNam=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->TLogNo,sizeof(pICS_461191_G->TLogNo));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "TLogNo,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"TLogNo=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->DtlAmt,sizeof(pICS_461191_G->DtlAmt));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "DtlAmt,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"DtlAmt=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->CcyCod,sizeof(pICS_461191_G->CcyCod));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "Ccycod,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"CcyCod=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->ThdCod,sizeof(pICS_461191_G->ThdCod));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "ThdCod,%s;", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"ThdCod=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->AuthCd,sizeof(pICS_461191_G->AuthCd));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "AuthCd,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"AuthCd=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->HActDt,sizeof(pICS_461191_G->HActDt));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "HActDt,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"HActDt=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->SelVal,sizeof(pICS_461191_G->SelVal));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "SelVal,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"SelVal=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->SeqNo ,sizeof(pICS_461191_G->SeqNo ));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "SeqNo,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"SeqNo =[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->PfaSub,sizeof(pICS_461191_G->PfaSub));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "PfaSub,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"PfaSub=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->BCusId,sizeof(pICS_461191_G->BCusId));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "BCusId,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"BCusId=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->Year  ,sizeof(pICS_461191_G->Year  ));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "Year,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"Year  =[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->SubCod,sizeof(pICS_461191_G->SubCod));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "SubCod,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"SubCod=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->PrjCod,sizeof(pICS_461191_G->PrjCod));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "PrjCod,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"PrjCod=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->EConTp,sizeof(pICS_461191_G->EConTp));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "EConTp,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"EConTp=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->DptCod,sizeof(pICS_461191_G->DptCod));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "DptCod,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"DptCod=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->BokAmt,sizeof(pICS_461191_G->BokAmt));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "BokAmt,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"BokAmt=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->BchNo ,sizeof(pICS_461191_G->BchNo ));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "BchNo,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"BchNo =[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->TActDt,sizeof(pICS_461191_G->TActDt));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "TActDt,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"TActDt=[%s]\n",tmpvalue);
fclose(fp);

	  memset( tmpvalue, '\0', sizeof( tmpvalue ) );
	  memcpy( tmpvalue,pICS_461191_G->AVchNo,sizeof(pICS_461191_G->AVchNo));
	  memset( tmp_batch_buff, '\0', sizeof( tmp_batch_buff ) );
	  sprintf( tmp_batch_buff, "AVchNo,%s|", tmpvalue );
	  strcat( batch_buff, tmp_batch_buff ) ;
fp=fopen("./461191.log","a");
fprintf(fp,"AVchNo=[%s]\n",tmpvalue);
fclose(fp);
	}
fclose(fp);

	strcat( recv_buff, batch_buff );

/*
fp=fopen("./461191.log","a");
fprintf(fp,"recv_buff=[%s]\n",recv_buff);
fclose(fp);
*/

  return 0;
}
