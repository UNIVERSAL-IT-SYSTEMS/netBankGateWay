/****************************************
 *程序名:subtrans482115.c
 *功  能:缴车船税(查询)
 *日  期:2008-10-10
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


int ics_proc_482115(char *send_buff,char *recv_buff)
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
  ICS_DEF_482115_I  *pICS_482115_I;
  ICS_DEF_482115_N  *pICS_482115_N;
  ICS_DEF_482115_E  *pICS_482115_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482115i_buff[66];
  char      ics_482115n_buff[226];
  char      ics_482115e_buff[71];
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

  char			sSTxnAmt[32];
  char			sTCusNm[32];
  char			sLoSeq[32];
  char      sCarType[32];
  char      sCarNo[32];
  char      sCar[32];
  char			sRsfld[32];

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
  memset(ics_482115i_buff,'\0',sizeof(ics_482115i_buff));
  memset(ics_482115n_buff,'\0',sizeof(ics_482115n_buff));
  memset(ics_482115e_buff,'\0',sizeof(ics_482115e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482115_I=(ICS_DEF_482115_I *)ics_482115i_buff;
  pICS_482115_N=(ICS_DEF_482115_N *)ics_482115n_buff;
  pICS_482115_E=(ICS_DEF_482115_E *)ics_482115e_buff;
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

  flog( STEP_LEVEL,"--482115 接收[%s]------------------------------",send_buff);

  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
	strcpy(pICS_TIA->TTxnCd,"482115");
  strcpy(pICS_TIA->FeCod,"482115");

  strcpy(pICS_TIA->TrmNo,"DVID");
  strcpy(pICS_TIA->TxnSrc,"T0001");

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

  /* STEP1-3: 填上传串的元素值*/
  strcpy(pICS_482115_I->RsFld1, "P001");        /*第三方交易码*/
  strcpy(pICS_482115_I->RsFld2, "0065");        /*第三方业务类型*/

  /* 缴费号码就是车牌号 */
  getValueOfStr(send_buff,"CarNo", tmpvalue);   /* 缴费号码 */
  strcpy(pICS_482115_I->TCusID, tmpvalue);

  getValueOfStr(send_buff,"CDNO", tmpvalue);   /* 帐号 */
  strcpy(pICS_482115_I->ActNo, tmpvalue);

	memset(sCarType, 0, sizeof(sCarType));
	memset(sCarNo, 0, sizeof(sCarNo));
	memset(sCar, 0, sizeof(sCar));
      
  getValueOfStr(send_buff,"CarType", tmpvalue);  /* 车辆类型 */
  strcpy(pICS_482115_I->CarTyp, tmpvalue);
  strcpy(sCarType, tmpvalue);
  if(strcmp(sCarType,"A1")==0)
  	 strcpy(sCar,"大型汽车");
  if(strcmp(sCarType,"A2")==0)
  	 strcpy(sCar,"小型汽车");
  if(strcmp(sCarType,"A5")==0)
  	 strcpy(sCar,"挂车");
  if(strcmp(sCarType,"A6")==0)
  	 strcpy(sCar,"拖拉机");
  if(strcmp(sCarType,"A7")==0)
  	 strcpy(sCar,"农用运输车");
  if(strcmp(sCarType,"C1")==0)
  	 strcpy(sCar,"外籍汽车");


  getValueOfStr(send_buff,"CarNo", tmpvalue);   /* 车牌序列号  */
  strcpy(pICS_482115_I->CarNo, tmpvalue);
  strcpy(sCarNo, tmpvalue);


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

  len=sizeof(ICS_DEF_482115_I);
  for(i=0;i<len;i++)
  {
    if(ics_482115i_buff[i]==0)
      ics_482115i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482115i_buff,len);
  offset=offset+sizeof(ICS_DEF_482115_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

    /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_TRANS", ics_port);
  if (ret != RETURN_OK)
        return ret;

  flog( STEP_LEVEL,"TO ICS: [%s]",ics_send_buff);

  ret=clientics( ics_send_buff, ics_recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
    return(-1);

/*
memcpy(ics_recv_buff, "   N000000    CJW          000000                 20091129                     00441200  00                   0170017048D06TT66R                         周子荣                                                      000000003256   2288120000040                            000000000000   ",284);
*/
  flog( STEP_LEVEL,"FROM ICS: [%s]",ics_recv_buff);

  /*--------------------通讯后处理:组成回传报文------------------*/

  memcpy(ics_toa_buff,ics_recv_buff,sizeof(ics_toa_buff));

RETURN:

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*成功*/
  {
  /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
  /* 注意，<br>是页面显示的换行符号 */

      memcpy(ics_482115n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482115n_buff));

      memset(sTCusNm, 0, sizeof(sTCusNm));
      memset(sSTxnAmt, 0, sizeof(sSTxnAmt));
      memset(sLoSeq, 0, sizeof(sLoSeq));
      memset(sRsfld, 0, sizeof(sRsfld));

      sprintf(tmp_val_str,"<table><tr><td>车&nbsp;&nbsp;辆&nbsp;&nbsp;&nbsp;类&nbsp;&nbsp;型：</td><td>%s</td></tr>", sCar);
      strcat(display_str,tmp_val_str);
     
      sprintf(tmp_val_str,"<tr><td>车牌号码（粤A）： </td><td>%s  <br>", sCarNo);
      strcat(display_str,tmp_val_str);
      
      memcpy(sTCusNm,pICS_482115_N->TCusNm,sizeof(pICS_482115_N->TCusNm));
      trim(sTCusNm);
      sprintf(tmp_val_str,"<tr><td>客&nbsp;&nbsp;户&nbsp;&nbsp;&nbsp;姓&nbsp;&nbsp;名： </td><td>%s</td></tr>", sTCusNm);
      strcat(display_str,tmp_val_str);

      memcpy(sLoSeq,pICS_482115_N->LoSeq,sizeof(pICS_482115_N->LoSeq));
      trim(sLoSeq);
      sprintf(tmp_val_str,"<tr><td>地&nbsp;&nbsp;税&nbsp;流&nbsp;水&nbsp;号： </td><td>%s</td></tr>",sLoSeq);
      strcat(display_str,tmp_val_str);

      memcpy(sRsfld,pICS_482115_N->Rsfld3,sizeof(pICS_482115_N->Rsfld3));
      /*trim(sRsfld);*/
      flog( STEP_LEVEL,"sRsfld[%s]",sRsfld);

      memcpy(sSTxnAmt,pICS_482115_N->STxnAmt,sizeof(pICS_482115_N->STxnAmt));
      trim(sSTxnAmt);
      memset(sLeft,0,sizeof(sLeft));
      memset(sRight,0,sizeof(sRight));
      memcpy(sLeft,sSTxnAmt,10);
      memcpy(sRight,sSTxnAmt+10,2);
      sprintf(tmp_val_str,"<tr><td>缴&nbsp;&nbsp;费&nbsp;&nbsp;&nbsp;金&nbsp;&nbsp;额： </td><td>%d.%s</td></tr>",atoi(sLeft),sRight);
      strcat(display_str,tmp_val_str);
      
      strcat(display_str,"<tr><td>温&nbsp;&nbsp;馨&nbsp;&nbsp;&nbsp;提&nbsp;&nbsp;示： </td><td>确认缴费提交后，将无法退款，请仔细核对您的缴费信息!</td></tr></table>");
           
      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff, "MGID", tmp_val_str);/*返回码*/


      setValueOfStr(recv_buff, "CarType", sCarType); /*车牌类型*/
      setValueOfStr(recv_buff, "CarNo", sCarNo); /*车牌号*/
      setValueOfStr(recv_buff, "TCusNm", sRsfld);/*客户姓名*/
      setValueOfStr(recv_buff, "STxnAmt", sSTxnAmt); /*金额*/
      setValueOfStr(recv_buff, "LoSeq", sLoSeq);/*地税流水号*/
      
  }
  else if(memcmp(pICS_TOA->RspCod,"482199",sizeof(pICS_TOA->RspCod))==0)
  	{
  		memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482115e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482115e_buff));

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      strcpy(tmp_val_str,pICS_482115_E->RspMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  	}
  else
  { /*失败*/

      memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482115e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482115e_buff));

      strcpy(tmp_val_str,"<font color=ff0000><b>--->查询缴费信息失败！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
      strcat(display_str,tmp_val_str);

      sprintf(tmp_val_str,"--->失败原因：[%s] <br>",sErrMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }

  flog( STEP_LEVEL,"**482115 返回[%s]******************************",recv_buff);

  return 0;
}
