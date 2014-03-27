/****************************************
 *程序名:trans482103.c
 *功  能:体彩查询投注情况
 *日  期:2010.06.21
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


int ics_proc_482103_tc(char *send_buff,char *recv_buff)
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

  ICS_DEF_TIA       *pICS_TIA;
  ICS_DEF_TOA       *pICS_TOA;
  ICS_DEF_482103_I_TC  *pICS_482103_I;
  ICS_DEF_482103_N_TC  *pICS_482103_N;
  ICS_DEF_482103_E_TC  *pICS_482103_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482103i_buff[38];
  char      ics_482103n_buff[118];
  char      ics_482103e_buff[75];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      tmp_val_str3[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[200];   /*从上传报文中取得的某项值*/
  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      ics_port[6];
  char      sTxnCnl[32];
  char      sTellerNo[8];
  time_t    cur_time;
  struct tm   *my_tm;

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */

  pICS_482103_I=(ICS_DEF_482103_I_TC *)ics_482103i_buff;
  pICS_482103_N=(ICS_DEF_482103_N_TC *)ics_482103n_buff;
  pICS_482103_E=(ICS_DEF_482103_E_TC *)ics_482103e_buff;
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

  memset(ics_send_buff,'\0',sizeof(ics_send_buff));
  memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
  memset(ics_482103i_buff,'\0',sizeof(ics_482103i_buff));
  memset(ics_482103n_buff,'\0',sizeof(ics_482103n_buff));
  memset(ics_482103e_buff,'\0',sizeof(ics_482103e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(tmp_val_str3,'\0',sizeof(tmp_val_str3));
  memset(display_str,'\0',sizeof(display_str));
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  memset(sTranNo,'\0',sizeof(sTranNo));
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
  memset(sTranDate,'\0',sizeof(sTranDate));
  
flog( STEP_LEVEL,"--482103 接收[%s]-------------------------------",send_buff);

 /* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");   /* CICS交易代码 */
  strcpy(pICS_TIA->TTxnCd,"482103");
  strcpy(pICS_TIA->FeCod,"482103");
  strcpy(pICS_TIA->TrmNo,"DVID");

  /*将终端的交易渠道赋值进来*/
  /* 如果TXNSRC值没有上送,默认使用WE441 */
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  if(strstr(send_buff,"TXNSRC")){
    getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*交易渠道*/
  }else{
    strcpy(sTxnCnl, "WE441");
  }
  strcpy(pICS_TIA->TxnSrc, sTxnCnl);
  
  
  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);

  strcpy(pICS_TIA->NodTrc,sTranNo);           /*柜员号*/

  ret = get_config_value(CONFIG_FILE_NAME, "TELLER_NO", sTellerNo);
  if (ret != RETURN_OK)
    return ret;

  strcpy(pICS_TIA->TlrId,sTellerNo);          /*柜员号*/
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

  /* STEP1-3: 填上传串中的固定元素值*/
  /* 格式: strcpy(pICS_482103_I->RsFld1,"P001"); 第三方交易码(查询)*/

  /* STEP1-4: 从上传报文中获得其余值-用getValueOf函数*/
  getValueOfStr(send_buff,"TLogNo",tmpvalue); /*购彩流水号*/
  strcpy(pICS_482103_I->TLogNo,tmpvalue);

  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/
  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
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

  len=sizeof(ICS_DEF_482103_I_TC);
  for(i=0;i<len;i++)
  {
    if(ics_482103i_buff[i]==0)
      ics_482103i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482103i_buff,len);
  offset=offset+sizeof(ICS_DEF_482103_I_TC);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
   /* 与ICS通讯 */
   memset(ics_port,'\0',sizeof(ics_port));

   ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_TC", ics_port);

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
    /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
    /* 注意，<br>是页面显示的换行符号 */
  
    memcpy(pICS_482103_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482103_N_TC));
  
    /* 调用setValueOf函数填充 */
      /*格式:setValueOfStr(recv_buff,"display_zone",display_str);*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str); /*返回码*/ 

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->TmpDat,sizeof(pICS_482103_N->TmpDat));
      setValueOfStr(recv_buff,"TmpDat",tmp_val_str);/*包体长度*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->ApCode,sizeof(pICS_482103_N->ApCode));
      setValueOfStr(recv_buff,"ApCode",tmp_val_str);/*格式码'SC'*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->OFmtCd,sizeof(pICS_482103_N->OFmtCd));
      setValueOfStr(recv_buff,"OFmtCd",tmp_val_str);/*格式码'D04'*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->TRspCd,sizeof(pICS_482103_N->TRspCd));
      setValueOfStr(recv_buff,"TRspCd",tmp_val_str);/*状态*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->TrmCod,sizeof(pICS_482103_N->TrmCod));
      setValueOfStr(recv_buff,"TrmCod",tmp_val_str);/*期号*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->SigDup,sizeof(pICS_482103_N->SigDup));
      setValueOfStr(recv_buff,"SigDup",tmp_val_str);/*单复式类型*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->LotTyp,sizeof(pICS_482103_N->LotTyp));
      setValueOfStr(recv_buff,"LotTyp",tmp_val_str);/*彩票类型*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->TLogNo,sizeof(pICS_482103_N->TLogNo));
      setValueOfStr(recv_buff,"TLogNo",tmp_val_str);/*购彩流水号*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->LotNum,sizeof(pICS_482103_N->LotNum));
      setValueOfStr(recv_buff,"LotNum",tmp_val_str);/*投注号码*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->NotNum,sizeof(pICS_482103_N->NotNum));
      setValueOfStr(recv_buff,"NotNum",tmp_val_str);/*注数*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_N->TxnAmt,sizeof(pICS_482103_N->TxnAmt));
      setValueOfStr(recv_buff,"TxnAmt",tmp_val_str);/*金额*/

    /* STEP3-2 处理页面隐含要素: 这里填写的字段，就是在页面作为隐含input的要素 */
    /* 注意，1.这里设置参数的顺序必须和数据库中参数的顺序一致，否则回出错！ 
            2.返回码字段名定义注意与WEB上一致*/ 

  }
  else
  { /*失败*/
      /*获得错误返回包*/
      memcpy(pICS_482103_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482103_E_TC));
  
      /* 调用setValueOf函数填充 */
      /*格式:setValueOfStr(recv_buff,"display_zone",display_str);*/
      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_E->RspCod,sizeof(pICS_482103_E->RspCod));
      setValueOfStr(recv_buff,"RspCod",tmp_val_str);/*返回码       */

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_482103_E->RspMsg,sizeof(pICS_482103_E->RspMsg));
      setValueOfStr(recv_buff,"RspMsg",tmp_val_str);/*返回码       */
  }
  flog( STEP_LEVEL,"**482103 返回[%s]******************************",recv_buff);
  return 0;

}
