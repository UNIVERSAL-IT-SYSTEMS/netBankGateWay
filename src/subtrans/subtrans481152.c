/****************************************
 *程序名:subtrans481152.c
 *功  能:售卡交易查询
 *日  期:2009-1-8
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


int ics_proc_481152(char *send_buff,char *recv_buff)
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
  ICS_DEF_481152_I  *pICS_481152_I;
  ICS_DEF_481152_N  *pICS_481152_N;
  ICS_DEF_481152_E  *pICS_481152_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_481152i_buff[12];
  char      ics_481152n_buff[49];
  char      ics_481152e_buff[71];
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
  char      sErrMsg[64];
  char      ics_port[6];
  char      sTxnCnl[32];

	int iRecNum;
	int iRecIdx;

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
  memset(ics_481152i_buff,'\0',sizeof(ics_481152i_buff));
  memset(ics_481152n_buff,'\0',sizeof(ics_481152n_buff));
  memset(ics_481152e_buff,'\0',sizeof(ics_481152e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_481152_I=(ICS_DEF_481152_I *)ics_481152i_buff;
  pICS_481152_N=(ICS_DEF_481152_N *)ics_481152n_buff;
  pICS_481152_E=(ICS_DEF_481152_E *)ics_481152e_buff;
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
  

  flog( STEP_LEVEL,"--481152 接收[%s]------------------------------",send_buff);

  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
	strcpy(pICS_TIA->TTxnCd,"481152");
  strcpy(pICS_TIA->FeCod,"481152");

  strcpy(pICS_TIA->TrmNo,"DVID");
  

  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);

  strcpy(pICS_TIA->NodTrc,sTranNo);

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
  
  /*将终端的交易渠道赋值进来*/
  /* 如果TXNSRC值没有上送,默认使用WE441 */
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  if(strstr(send_buff,"TXNSRC")){
    getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*交易渠道*/
  }else{
    strcpy(sTxnCnl, "WE441");
  }
  strcpy(pICS_TIA->TxnSrc, sTxnCnl);
  
  
  /* STEP1-3: 填上传串的元素值*/
  strcpy(pICS_481152_I->TxnDat, "20090108");    /*日期*/
  strcpy(pICS_481152_I->AbuTyp, "0002");        /*卡类*/

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

  len=sizeof(ICS_DEF_481152_I);
  for(i=0;i<len;i++)
  {
    if(ics_481152i_buff[i]==0)
      ics_481152i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_481152i_buff,len);
  offset=offset+sizeof(ICS_DEF_481152_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

    /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_LTYKC", ics_port);
  if (ret != RETURN_OK)
        return ret;

  flog( STEP_LEVEL,"TO ICS: [%s]",ics_send_buff);

/*
  ret=clientics( ics_send_buff, ics_recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
    return(-1);
*/

  flog( STEP_LEVEL,"FROM ICS: [%s]",ics_recv_buff);

  /*--------------------通讯后处理:组成回传报文------------------*/

strcpy(ics_recv_buff,"   N00000064020224         000000   20090108      20090108                     00484022  00                   0117011748D4200013018充值卡有效卡种浏览008查询内容2  031小灵通30        000000000003000031小灵通50        000000000005000");
  
  memcpy(ics_toa_buff,ics_recv_buff,sizeof(ics_toa_buff));


RETURN:

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*成功*/
  {
  /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
  /* 注意，<br>是页面显示的换行符号 */

			char tempBuff[1024];
			char strBusNam[17];
			char strTxnAmt[16];
			
			memset(tempBuff, 0, sizeof(tempBuff));			
      memcpy(ics_481152n_buff, ics_recv_buff+sizeof(ics_toa_buff), sizeof(ICS_DEF_481152_N));
      memcpy(tempBuff, ics_recv_buff+sizeof(ics_toa_buff)+sizeof(ICS_DEF_481152_N), strlen(ics_recv_buff)-sizeof(ics_toa_buff)-sizeof(ICS_DEF_481152_N));
/*
      printf("%s\n", tempBuff);
      iRecNum = atoi(trim(pICS_481152_N->RecNum));
      
      printf("[%s][%d]\n", pICS_481152_N->RecNum, iRecNum);
      
      for(iRecIdx = 0; iRecIdx < iRecNum; iRecIdx++)
      {
				memset(strBusNam, 0, sizeof(strBusNam));
				memset(strTxnAmt, 0, sizeof(strTxnAmt));      	
      	strncpy(strBusNam, tempBuff+3+iRecIdx*34, 16);
      	strncpy(strTxnAmt, tempBuff+19+iRecIdx*34, 15);
      	trim(strBusNam);
      	trim(strTxnAmt);
      	
      	sprintf(tmp_val_str, "<input onClick=\"form1.BusNam.value='%s';form1.TxnAmt.value='%s';\" type=\"radio\" name=\"radiobutton\" value=\"%s\">%s<br>", strBusNam, strTxnAmt, strBusNam, strBusNam);
				strcat(display_str,tmp_val_str);
      }           
*/      
      setValueOfStr(recv_buff,"display_zone",tempBuff);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff, "MGID", tmp_val_str);/*返回码*/        
  }
  else
  { /*失败*/

      memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_481152e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_481152e_buff));

      strcpy(tmp_val_str,"<font color=ff0000><b>--->查询缴费信息失败！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
      strcat(display_str,tmp_val_str);

      sprintf(tmp_val_str,"--->失败原因：[%s] <br>",sErrMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }

  flog( STEP_LEVEL,"**481152 返回[%s]******************************",recv_buff);

  return 0;
}
