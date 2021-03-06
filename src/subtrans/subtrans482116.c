/****************************************
 *程序名:subtrans482116.c
 *功  能:缴车船税(缴费)
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


int ics_proc_482116(char *send_buff,char *recv_buff)
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
  ICS_DEF_482116_I  *pICS_482116_I;
  ICS_DEF_482116_N  *pICS_482116_N;
  ICS_DEF_482116_E  *pICS_482116_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482116i_buff[383];
  char      ics_482116n_buff[129];
  char      ics_482116e_buff[71];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*从上传报文中取得的某项值*/
  
  char			s_CDNO[LEN_CDNO]; /* 卡号 */
  char			s_PSWD[21]; /* 密码 */
  
  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      ics_port[6];

	char      sCarType[32];
	char 			sCar[32];
	char 			sTCusNm[32];
	char 			sTxnCnl[32];
	
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
  memset(ics_482116i_buff,'\0',sizeof(ics_482116i_buff));
  memset(ics_482116n_buff,'\0',sizeof(ics_482116n_buff));
  memset(ics_482116e_buff,'\0',sizeof(ics_482116e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482116_I=(ICS_DEF_482116_I *)ics_482116i_buff;
  pICS_482116_N=(ICS_DEF_482116_N *)ics_482116n_buff;
  pICS_482116_E=(ICS_DEF_482116_E *)ics_482116e_buff;
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
  memset(sErrMsg, '\0', sizeof( sErrMsg ) ) ;
	memset(s_CDNO, '\0', sizeof(s_CDNO));
	memset(s_PSWD, '\0', sizeof(s_PSWD));

	memset(sCarType, 0, sizeof(sCarType));
	memset(sCar, 0, sizeof(sCar));
	memset(sTCusNm, 0, sizeof(sTCusNm));
	memset(sTxnCnl, '\0', sizeof(sTxnCnl));

flog( STEP_LEVEL,"--482116 接收[%s]------------------------------",send_buff);

  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
  strcpy(pICS_TIA->TTxnCd,"482116");
  strcpy(pICS_TIA->FeCod,"482116");
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
  strcpy(pICS_482116_I->RsFld1,"P002"); /*第三方交易码(缴费)*/
  strcpy(pICS_482116_I->RsFld2, "0065"); /*第三方业务类型*/

  /* 缴费号码就是车牌号 */
  getValueOfStr(send_buff,"CarNo", tmpvalue); /*缴费号码*/
  strcpy(pICS_482116_I->TCusID, tmpvalue);

  getValueOfStr(send_buff,"STxnAmt", tmpvalue); /*交易金额*/
  memset(tmp_val_str2, 0, sizeof(tmp_val_str2));
  strcpy(tmp_val_str2, "000");
  strcat(tmp_val_str2, tmpvalue);
  strcpy(pICS_482116_I->TxnAmt,tmp_val_str2);
  
  strcpy(pICS_482116_I->ActTyp,"4");	/*帐号类型*/

	memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"CDNO", tmpvalue); /*代扣帐号*/
  strcpy(s_CDNO, tmpvalue);
  strcpy(pICS_482116_I->ActNo, tmpvalue);
    
  memset(tmpvalue, 0, sizeof(tmpvalue));  
  getValueOfStr(send_buff,"CarType", tmpvalue); /*车辆类型*/
  strcpy(pICS_482116_I->CarTyp, tmpvalue);
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

  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"CarNo", tmpvalue); /* 车牌序列号  */
  strcpy(pICS_482116_I->CarNo, tmpvalue);

  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"LoSeq", tmpvalue); /* 地税流水号  */
  strcpy(pICS_482116_I->LoSeq, tmpvalue);

  memset(tmpvalue, 0, sizeof(tmpvalue)); 
  flog( STEP_LEVEL,"send_buff[%s]",send_buff);
  getValueOfStr(send_buff,"TCusNm", tmpvalue); /*客户姓名*/
  flog( STEP_LEVEL,"客户姓名[%s]",tmpvalue);
  strcpy(pICS_482116_I->Rsfld3, tmpvalue);  
  strcpy(sTCusNm, tmpvalue);
  
  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"PSWD",tmpvalue); /*密码*/
  strcpy(s_PSWD,tmpvalue);
  strcpy(pICS_482116_I->PinBlk,tmpvalue);

  /* 校验密码 modify by ylw for 异地卡 20120211
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
 */ 
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

  len=sizeof(ICS_DEF_482116_I);
  for(i=0;i<len;i++)
  {
    if(ics_482116i_buff[i]==0)
      ics_482116i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482116i_buff,len);
  offset=offset+sizeof(ICS_DEF_482116_I);

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

flog( STEP_LEVEL,"FROM ICS: [%s]",ics_recv_buff);

  /*--------------------通讯后处理:组成回传报文------------------*/

  memcpy(ics_toa_buff,ics_recv_buff,sizeof(ics_toa_buff));

RETURN:

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*成功*/
  {
    /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
    /* 注意，<br>是页面显示的换行符号 */

    memcpy(ics_482116n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482116n_buff));

		sprintf(tmp_val_str,"<table><tr><td>车辆类型： </td><td>%s  </td></tr>", sCar);
    strcat(display_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->TCusID,sizeof(pICS_482116_N->TCusID));
    sprintf(tmp_val_str,"<tr><td>车牌号码（粤A）： </td><td>%s  </td></tr>", tmp_val_str2);
    strcat(display_str,tmp_val_str);

    /*memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->Rsfld3,sizeof(pICS_482116_N->Rsfld3));*/
    sprintf(tmp_val_str,"<tr><td>客户姓名： </td><td>%s  </td></tr>", sTCusNm);
    strcat(display_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->RcvAmt,sizeof(pICS_482116_N->RcvAmt));
    memset(sLeft,0,sizeof(sLeft));
    memset(sRight,0,sizeof(sRight));
    memcpy(sLeft,tmp_val_str2,13);
    memcpy(sRight,tmp_val_str2+13,2);
    sprintf(tmp_val_str,"<tr><td>缴费金额： </td><td>%d.%s  </td></tr>",atoi(sLeft),sRight);
    strcat(display_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->TckNo,sizeof(pICS_482116_N->TckNo));
    sprintf(tmp_val_str,"<tr><td>会计流水： </td><td>%s  </td></tr></table>", tmp_val_str2);
    strcat(display_str,tmp_val_str);

		sprintf(tmp_val_str,"温馨提示： %s  ", "我行与地税系统实时联网，您在本机成功缴税后，即可办理年审。如您需要完税凭证，可24小时后通过市内交费易多媒体终端“客户服务”完成补打，也可通过交费易POS终端完成补打，交费易咨询电话38883320!<br>");
    strcat(display_str,tmp_val_str);

    strcat(display_str,"<b>交费成功! 请及时查询结果。</b><br>");

    /* STEP3-1-1 在日志中记录有关数据备查 begin*/
    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_I->TCusID,sizeof(pICS_482116_I->TCusID));
    sprintf(tmp_val_str,"代理代码：[%s] ",tmp_val_str2);
    strcat(display_log_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->TckNo,sizeof(pICS_482116_N->TckNo));
    sprintf(tmp_val_str,"会计流水：[%s] ",tmp_val_str2);
    strcat(display_log_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
    memcpy(tmp_val_str2,pICS_482116_N->RcvAmt,sizeof(pICS_482116_N->RcvAmt));
    sprintf(tmp_val_str,"交费金额：[%s] ",tmp_val_str2);
    strcat(display_log_str,tmp_val_str);

    setValueOfStr(recv_buff,"display_zone",display_str);

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }
  else
  { /*失败*/
    if( memcmp( pICS_TOA->RspCod, "PC5012", 6 ) == 0 )
        strcpy( sErrMsg, "密码不符" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5012", 6 ) == 0 )
        strcpy( sErrMsg, "密码不符" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5100", 6 ) == 0 )
        strcpy( sErrMsg, "借记卡可用余额不足" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PC3254", 6 ) == 0 )
        strcpy( sErrMsg, "此交易不允许透支" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5044", 6 ) == 0 )
       strcpy( sErrMsg, "密码错误次数超过限制" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "TC2051", 6 ) == 0 )
        strcpy( sErrMsg, "密码校验错" ) ;
    else
        memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

    memcpy(ics_482116e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482116e_buff));

    strcpy(tmp_val_str,"<font color=ff0000><b>--->交费失败！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
    strcat(display_str,tmp_val_str);

    sprintf(tmp_val_str,"--->失败原因：[%s] <br>",sErrMsg);
    strcat(display_str,tmp_val_str);

    setValueOfStr(recv_buff,"display_zone",display_str);

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }

flog( STEP_LEVEL,"**482116 返回[%s]******************************",recv_buff);

  return 0;
}
