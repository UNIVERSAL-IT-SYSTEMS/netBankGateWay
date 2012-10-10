/****************************************
 *程序名:subtrans482140.c
 *功  能:羊城通帐户查询
 *日  期:2009-2-27
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


int ics_proc_482140(char *send_buff,char *recv_buff)
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
  ICS_DEF_482140_I  *pICS_482140_I;
  ICS_DEF_482140_N  *pICS_482140_N;
  ICS_DEF_482140_E  *pICS_482140_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482140i_buff[32];
  char      ics_482140n_buff[570];
  char      ics_482140e_buff[74];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*从上传报文中取得的某项值*/
  
  char			s_CDNO[LEN_CDNO]; /* 卡号 */
  
  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      ics_port[6];
  
	char  IDTyp[3];
	char  IDNo[31];
	char  ActNam[61];
	
		
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
  memset(ics_482140i_buff,'\0',sizeof(ics_482140i_buff));
  memset(ics_482140n_buff,'\0',sizeof(ics_482140n_buff));
  memset(ics_482140e_buff,'\0',sizeof(ics_482140e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482140_I=(ICS_DEF_482140_I *)ics_482140i_buff;
  pICS_482140_N=(ICS_DEF_482140_N *)ics_482140n_buff;
  pICS_482140_E=(ICS_DEF_482140_E *)ics_482140e_buff;
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

flog( STEP_LEVEL,"--482140 接收[%s]------------------------------",send_buff);

  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
  strcpy(pICS_TIA->TTxnCd,"482140");
  strcpy(pICS_TIA->FeCod,"482140");
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

  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"CDNO", tmpvalue); /*代扣帐号*/
  trim(tmpvalue);
	strcpy(pICS_482140_I->ActNo, tmpvalue);
	strcpy(pICS_482140_I->Ccy, "CNY");
	memcpy(pICS_482140_I->InFlg, "4", 1);
	strcpy(pICS_482140_I->BusTyp, "");
	strcpy(pICS_482140_I->AcSeq, "");	
  
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

  len=sizeof(ICS_DEF_482140_I);
  for(i=0;i<len;i++)
  {
    if(ics_482140i_buff[i]==0)
      ics_482140i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482140i_buff,len);
  offset=offset+sizeof(ICS_DEF_482140_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

  /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_YCT", ics_port);
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
		memcpy(ics_482140n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482140n_buff));
    
    memset(IDTyp, 0, sizeof(IDTyp));
    memset(IDNo, 0, sizeof(IDNo));
    memset(ActNam, 0, sizeof(ActNam));
    
    memcpy(IDTyp, pICS_482140_N->IDTyp, sizeof(pICS_482140_N->IDTyp));
    memcpy(IDNo, pICS_482140_N->IDNo, sizeof(pICS_482140_N->IDNo));
    memcpy(ActNam, pICS_482140_N->ActNam, sizeof(pICS_482140_N->ActNam));
    trim(IDTyp);
    trim(IDNo);
    trim(ActNam);

		memset(tmpvalue, 0, sizeof(tmpvalue));
		if(strcmp(IDTyp ,"20") == 0){
			strcpy(tmpvalue, "3");         /*3-护照*/
		}else if(strcmp(IDTyp ,"17") == 0 || strcmp(IDTyp ,"18") == 0){
			strcpy(tmpvalue, "2");         /*2-军官证*/
		}
		else{
			strcpy(tmpvalue, "1");         /*1-身份证*/
		}	
		setValueOfStr(recv_buff, "IDTyp", tmpvalue);
		
		setValueOfStr(recv_buff, "IDNo", IDNo);
		setValueOfStr(recv_buff, "ActNam", ActNam);
		
		if(pICS_482140_N->ActSts[0] == '0'){
			setValueOfStr(recv_buff, "ActSts", "正常");
		}else if(pICS_482140_N->ActSts[0] == '1'){
			setValueOfStr(recv_buff, "ActSts", "异常");
		}else if(pICS_482140_N->ActSts[0] == '2'){
			setValueOfStr(recv_buff, "ActSts", "抹账");
		}else if(pICS_482140_N->ActSts[0] == '3'){
			setValueOfStr(recv_buff, "ActSts", "销卡/户");
		}

		if(pICS_482140_N->CrdTyp[0] == '0'){
			setValueOfStr(recv_buff, "CrdTyp", "借记卡");
		}else if(pICS_482140_N->CrdTyp[0] == '1'){
			setValueOfStr(recv_buff, "CrdTyp", "准贷记卡");
		}else if(pICS_482140_N->CrdTyp[0] == '2'){
			setValueOfStr(recv_buff, "CrdTyp", "储蓄卡");
		}
		
		setValueOfStr(recv_buff,"display_zone","");
		    
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

    memcpy(ics_482140e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482140e_buff));

    strcpy(tmp_val_str,"<font color=ff0000><b>--->羊城通帐户查询签约信息！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
    strcat(display_str,tmp_val_str);

    sprintf(tmp_val_str,"--->失败原因：[%s] <br>",sErrMsg);
    strcat(display_str,tmp_val_str);

    setValueOfStr(recv_buff,"display_zone",display_str);

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }

flog( STEP_LEVEL,"**482140 返回[%s]******************************",recv_buff);

  return 0;
}
