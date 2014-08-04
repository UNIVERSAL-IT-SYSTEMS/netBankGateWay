/****************************************
 *程序名:trans460621.c
 *功  能:联通缴费前查询
 *日  期:2014-06
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


int ics_proc_460621_uncc(char *send_buff,char *recv_buff)
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
  ICS_DEF_460621_I  *pICS_460621_I;
  ICS_DEF_460621_N  *pICS_460621_N;
  ICS_DEF_460621_E  *pICS_460621_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_460621i_buff[27];
  char      ics_460621n_buff[39];
  char      ics_460621e_buff[75];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*从上传报文中取得的某项值*/

  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sTxnCnl[32];
  char      sErrMsg[64];
  char      ics_port[6];
  
  char      User_status[3];
  char      sStatus[16];

  time_t    cur_time;

  struct tm  *my_tm;

  FILE      *fp;
  
  
  
  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */

  memset(ics_send_buff,'\0',sizeof(ics_send_buff));
  memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
  memset(ics_460621i_buff,'\0',sizeof(ics_460621i_buff));
  memset(ics_460621n_buff,'\0',sizeof(ics_460621n_buff));
  memset(ics_460621e_buff,'\0',sizeof(ics_460621e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));


  pICS_460621_I=(ICS_DEF_460621_I *)ics_460621i_buff;
  pICS_460621_N=(ICS_DEF_460621_N *)ics_460621n_buff;
  pICS_460621_E=(ICS_DEF_460621_E *)ics_460621e_buff;
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(display_str,'\0',sizeof(display_str));
  memset(display_log_str,'\0',sizeof(display_log_str));
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  memset(sTranNo,'\0',sizeof(sTranNo));
  memset(sTranDate,'\0',sizeof(sTranDate));
  memset(sErrMsg,'\0',sizeof(sErrMsg));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
  memset( sErrMsg, '\0', sizeof( sErrMsg ) ) ;
  memset(sTxnCnl, '\0', sizeof(sTxnCnl)); 
  flog( STEP_LEVEL,"--460621 接收[%s]-------------------------------",send_buff);

 /* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
  strcpy(pICS_TIA->TTxnCd,"460621");
  strcpy(pICS_TIA->FeCod,"460621");
  strcpy(pICS_TIA->TrmNo,"DVID");

  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);


  strcpy(pICS_TIA->NodTrc,sTranNo);
  
  
  getValueOfStr(send_buff,"TXNSRC",sTxnCnl); /*交易渠道*/
  flog( STEP_LEVEL,"--TXNSRC 接收[%s]------------------------------",sTxnCnl);
  strcpy(pICS_TIA->TxnSrc,sTxnCnl);

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
  
  /* STEP1-3: 填上传串中的固定元素值*/
 
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));    /*给tempvalue重新置空*/
  getValueOfStr(send_buff,"YwLei", tmpvalue);   /* 业务类型 */
  strcpy(pICS_460621_I->BusiType, tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));    /*给tempvalue重新置空*/
  getValueOfStr(send_buff,"TelNum",tmpvalue); /*电话号码*/
  strcpy(pICS_460621_I->TelNo, tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));    /*给tempvalue重新置空*/
  getValueOfStr(send_buff,"ZdanNy",tmpvalue); /*账单月份*/
  strcpy(pICS_460621_I->ZdanNy, tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));    /*给tempvalue重新置空*/
  
  /*发往ICS需加8位报文长度*/
  offset=0;
  offset=offset+8;

  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/
  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
       ics_tia_buff[i]=' ';
  }
  
  memcpy(ics_send_buff+offset,ics_tia_buff,len);
  offset=offset+sizeof(ICS_DEF_TIA);

  len=sizeof(ICS_DEF_460621_I);
  for(i=0;i<len;i++)
  {
    if(ics_460621i_buff[i]==0)
       ics_460621i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_460621i_buff,len);
  offset=offset+sizeof(ICS_DEF_460621_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);
  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
  
   /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_UNCC", ics_port);
  if (ret != RETURN_OK)
  {
    return -2;
  }

  ret=clientics( ics_send_buff,ics_recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
  return -1;

  memcpy(pICS_TOA,ics_recv_buff,sizeof(ICS_DEF_TOA));

  /*--------------------STEP3:通讯后处理:组成回传报文------------------*/

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*成功*/
  {
    /* STEP3-1 处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */

    memcpy(pICS_460621_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_460621_N));
   
    /* 调用setValueOf函数填充 */
    /*格式:setValueOfStr(recv_buff,"display_zone",display_str);*/



    memset(tmp_val_str,'\0',sizeof(tmp_val_str));   /*置空了*/
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str); /*返回码*/ 
   
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_N->TmpDat,sizeof(pICS_460621_N->TmpDat));
    setValueOfStr(recv_buff,"TmpDat",tmp_val_str);/*包体长度*/

 
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_N->ApCode,sizeof(pICS_460621_N->ApCode));
    setValueOfStr(recv_buff,"ApCode",tmp_val_str);/*SC*/
        
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_N->OFmtCd,sizeof(pICS_460621_N->OFmtCd));
    setValueOfStr(recv_buff,"OFmtCd",tmp_val_str);/*D04*/





    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_N->FfNo,sizeof(pICS_460621_N->FfNo));
    setValueOfStr(recv_buff,"FfNo",tmp_val_str);/*付费账号*/ 
        
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_N->MonSum,sizeof(pICS_460621_N->MonSum));
    setValueOfStr(recv_buff,"MonSum",tmp_val_str);/*欠费合计*/ 
        
    
    
  }
  else
  {  /*失败*/
    memcpy(pICS_460621_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_460621_E));
    
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));   /*置空了*/
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str); /*返回码*/ 

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"RspCod",tmp_val_str);/*返回码       */
    
    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_460621_E->RspMsg,sizeof(pICS_460621_E->RspMsg));
    setValueOfStr(recv_buff,"RspMsg",tmp_val_str);/*返回理由*/
  }
flog( STEP_LEVEL,"**460621 返回[%s]******************************",recv_buff);

  return 0;
}



