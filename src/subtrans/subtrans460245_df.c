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


int ics_proc_460245_df(char *send_buff,char *recv_buff)
{
  /*说明：send_buff-上传报文；
          recv_buff-下传报文;
          ics_send_buff-与后台通讯的发送串;
          ics_recv_buff-与后台通讯的接收串;
 */

  int     i;
  int     len;
  int     ret;
  int     offset;
  int     i_biz_id;

  ICS_DEF_TIA   *pICS_TIA;
  ICS_DEF_TOA   *pICS_TOA;
  ICS_DEF_460245_I  *pICS_460245_I;
  ICS_DEF_460245_N  *pICS_460245_N;
  ICS_DEF_460245_E  *pICS_460245_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_460245i_buff[140];
  char      ics_460245n_buff[33];
  char      ics_460245e_buff[97];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*从上传报文中取得的某项值*/
  
  char      s_CDNO[LEN_CDNO]; /* 卡号 */
  char      s_PSWD[21]; /* 密码 */
  char      sTxnAmt[15];/*金额*/
  char      sphone[20];/*手机号码*/
    
  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      ics_port[6];
  

  time_t    cur_time;

  struct tm   *my_tm;

  FILE      *fp;

/*
  void *pComplibhandle; * Handle to shared lib file *
  int (*pCompfunchandle)(); * Pointer to loaded routine */

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */

  memset(ics_send_buff,'\0',sizeof(ics_send_buff));
  memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
  memset(ics_460245i_buff,'\0',sizeof(ics_460245i_buff));
  memset(ics_460245n_buff,'\0',sizeof(ics_460245n_buff));
  memset(ics_460245e_buff,'\0',sizeof(ics_460245e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_460245_I=(ICS_DEF_460245_I *)ics_460245i_buff;
  pICS_460245_N=(ICS_DEF_460245_N *)ics_460245n_buff;
  pICS_460245_E=(ICS_DEF_460245_E *)ics_460245e_buff;
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(display_str,'\0',sizeof(display_str));
  memset(display_log_str,'\0',sizeof(display_log_str));
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  memset(sTranNo,'\0',sizeof(sTranNo));
  memset(sErrMsg,'\0',sizeof(sErrMsg));
  memset(sTranDate,'\0',sizeof(sTranDate));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
  memset(s_CDNO, '\0', sizeof(s_CDNO));
  memset(s_PSWD, '\0', sizeof(s_PSWD));
  memset(sTxnAmt, '\0', sizeof(sTxnAmt));
  memset(sphone, '\0', sizeof(sphone));
  
  


flog( STEP_LEVEL,"--460245 接收[%s]------------------------------",send_buff);

   /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
  strcpy(pICS_TIA->TTxnCd,"460245");
  strcpy(pICS_TIA->FeCod,"460245");
  strcpy(pICS_TIA->TrmNo,"DVID");
  strcpy(pICS_TIA->TxnSrc,"WB441");

  /*交易编号和交易日期*/
  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);
  
  strcpy(pICS_TIA->NodTrc,sTranNo);   /*柜员号*/

  ret = get_config_value(CONFIG_FILE_NAME, "TELLER_NO", sTellerNo);
  if (ret != RETURN_OK)
    return ret;

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

  /* STEP1-3: 填上传串的元素值*/
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"ActNo", tmpvalue);
  strcpy(pICS_460245_I->ActNo,tmpvalue);
  strcpy(s_CDNO, tmpvalue);  

  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"TCusId", tmpvalue);
  strcpy(pICS_460245_I->TCusId, tmpvalue);
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"TCusNm", tmpvalue);
  strcpy(pICS_460245_I->TCusNm, tmpvalue);
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"LChkTm", tmpvalue);
  strcpy(pICS_460245_I->LChkTm, tmpvalue);
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"DptTyp", tmpvalue);
  strcpy(pICS_460245_I->DptTyp, tmpvalue);
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"TxnAmt", tmpvalue);
  strcpy(pICS_460245_I->TxnAmt, tmpvalue);
  
  memset(tmpvalue, '0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"Fee", tmpvalue);
  strcpy(pICS_460245_I->Fee, tmpvalue);
  
  memset(tmpvalue, '0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"VchTyp", tmpvalue);
  strcpy(pICS_460245_I->VchTyp, tmpvalue);
  
  memset(tmpvalue, '0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"VchNo", tmpvalue);
  strcpy(pICS_460245_I->VchNo, tmpvalue);
  
  memset(tmpvalue, '0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"BilDat", tmpvalue);
  strcpy(pICS_460245_I->BilDat, tmpvalue);
  
  memset(tmpvalue, '\0', sizeof(tmpvalue));
  getValueOfStr(send_buff,"PSWD",tmpvalue); /*密码*/
  strcpy(pICS_460245_I->PinBlk,tmpvalue);
  strcpy(s_PSWD,tmpvalue);

  
  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/

  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
  }

  /* 校验密码 */
  flog( STEP_LEVEL,"----校验密码----\n");
  ret = ics_proc_928460( "1", s_CDNO, "1", s_PSWD, pICS_TOA->RspCod ) ;
  if ( ret < 0 )
  {
                flog( STEP_LEVEL,"CALL 928460 Fail [%d]",ret);
                sprintf( sErrMsg, "密码校验失败![%d]", ret );
                goto RETURN;
  }
  if( memcmp( pICS_TOA->RspCod, "000000", 6 ) != 0 )
  {
                flog( STEP_LEVEL,"928460 return [%s]", pICS_TOA->RspCod ) ;
                goto RETURN;
  }

  /*发往ICS需加8位报文长度*/
  offset=0;
  offset=offset+8;

  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_tia_buff,len);
  offset=offset+sizeof(ICS_DEF_TIA);

  len=sizeof(ICS_DEF_460245_I);
  for(i=0;i<len;i++)
  {
    if(ics_460245i_buff[i]==0)
      ics_460245i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_460245i_buff,len);
  offset=offset+sizeof(ICS_DEF_460245_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

 
   /*----------------------STEP2:与中间业务前置机通讯-----------------*/


  /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_GJDW", ics_port);
  if (ret != RETURN_OK)
        return -2;


  ret=clientics( ics_send_buff, ics_recv_buff, atoi(ics_port) );

  if(ret != RETURN_OK)
    return (-1);
 
 memcpy(pICS_TOA,ics_recv_buff,sizeof(ICS_DEF_TOA));


RETURN:

 /*--------------------通讯后处理:组成回传报文------------------*/

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*成功*/
  {
    /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
    /* 注意，<br>是页面显示的换行符号 */

    memcpy(pICS_460245_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_460245_N));
   
    /* 调用setValueOf函数填充 */
    /*格式:setValueOfStr(recv_buff,"display_zone",display_str);*/



    memset(tmp_val_str,'\0',sizeof(tmp_val_str));   /*置空了*/
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str); /*返回码*/ 
   
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->TmpDat,sizeof(pICS_460245_N->TmpDat));
    setValueOfStr(recv_buff,"TmpDat",tmp_val_str);/*包体长度*/

 
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->ApCode,sizeof(pICS_460245_N->ApCode));
    setValueOfStr(recv_buff,"ApCode",tmp_val_str);/*SC*/
        
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->OFmtCd,sizeof(pICS_460245_N->OFmtCd));
    setValueOfStr(recv_buff,"OFmtCd",tmp_val_str);/*D04*/


    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->TLogNo,sizeof(pICS_460245_N->TLogNo));
    setValueOfStr(recv_buff,"TLogNo",tmp_val_str);/*供电公司系统参考号*/ 
        
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->TckNo,sizeof(pICS_460245_N->TckNo));
    setValueOfStr(recv_buff,"TckNo",tmp_val_str);/*会计业务流水号*/ 
        
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_N->TActDt,sizeof(pICS_460245_N->TActDt));
    setValueOfStr(recv_buff,"TActDt",tmp_val_str);/*供电公司清算日期*/ 
  }
  else
  { /*失败*/
    memcpy(pICS_460245_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_460245_E));

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"RspCod",tmp_val_str);  /*返回码*/
   
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460245_E->RspMsg,sizeof(pICS_460245_E->RspMsg));
    setValueOfStr(recv_buff,"RspMsg",tmp_val_str);/*返回码  */
  }

  flog( STEP_LEVEL,"**460245 返回[%s]******************************",recv_buff);

  return 0;
}
