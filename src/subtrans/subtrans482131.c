/****************************************
 *程序名:subtrans482131.c
 *功  能:银旅通--定单查询
 *日  期:2008-12-19
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


int ics_proc_482131(char *send_buff,char *recv_buff)
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
  ICS_DEF_482131_I  *pICS_482131_I;
  ICS_DEF_482131_N  *pICS_482131_N;
  ICS_DEF_482131_E  *pICS_482131_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482131i_buff[20];
  char      ics_482131n_buff[334];
  char      ics_482131e_buff[71];
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

	char  Reserve_Code[13];							/*服务商*/	
	char  Product_Name[201];      			/*预定内容*/
	char  Provide_Name[31];      				/*服务商*/
	char  Trans_Toal_Amount[15];      	/*总金额*/
	char  Paid_Amount[15];      				/*已付金额*/	
	char  Arrearage_Amount[15];      		/*欠费金额*/	
	char  Return_Code[4];      					/*处理结果*/		
	char  PB_Return_Code_Msg[51];      	/*处理结果信息*/	

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
  memset(ics_482131i_buff,'\0',sizeof(ics_482131i_buff));
  memset(ics_482131n_buff,'\0',sizeof(ics_482131n_buff));
  memset(ics_482131e_buff,'\0',sizeof(ics_482131e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482131_I=(ICS_DEF_482131_I *)ics_482131i_buff;
  pICS_482131_N=(ICS_DEF_482131_N *)ics_482131n_buff;
  pICS_482131_E=(ICS_DEF_482131_E *)ics_482131e_buff;
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
  memset(sTxnCnl, 0, sizeof(sTxnCnl));
  
  flog( STEP_LEVEL,"--482131 接收[%s]------------------------------",send_buff);

  /* STEP1-2:填上传串的固定头 */
  strcpy(pICS_TIA->CCSCod,"TLU6");
	strcpy(pICS_TIA->TTxnCd,"482131");
  strcpy(pICS_TIA->FeCod,"482131");

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
  
  getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*交易渠道*/
  strcpy(pICS_TIA->TxnSrc,sTxnCnl);

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
  memset(Reserve_Code, 0, sizeof(Reserve_Code));
  trim(Reserve_Code);
  getValueOfStr(send_buff,"Reserve_Code", Reserve_Code);   /* 定单号 */
  strcpy(pICS_482131_I->Reserve_Code, Reserve_Code);




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

  len=sizeof(ICS_DEF_482131_I);
  for(i=0;i<len;i++)
  {
    if(ics_482131i_buff[i]==0)
      ics_482131i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482131i_buff,len);
  offset=offset+sizeof(ICS_DEF_482131_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

    /* 与ICS通讯 */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_YLT", ics_port);
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

      memcpy(ics_482131n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482131n_buff));

      memset(Product_Name, 0, sizeof(Product_Name));
      memset(Provide_Name, 0, sizeof(Provide_Name));
      memset(Trans_Toal_Amount, 0, sizeof(Trans_Toal_Amount));
      memset(Paid_Amount, 0, sizeof(Paid_Amount));
      memset(Arrearage_Amount, 0, sizeof(Arrearage_Amount));

      memcpy(Product_Name,pICS_482131_N->Product_Name,sizeof(pICS_482131_N->Product_Name));
      trim(Product_Name);
      sprintf(tmp_val_str,"预定内容： %s  <br>", Product_Name);
      strcat(display_str,tmp_val_str);

      memcpy(Provide_Name,pICS_482131_N->Provide_Name,sizeof(pICS_482131_N->Provide_Name));
      trim(Provide_Name);
      sprintf(tmp_val_str,"服务商： %s  <br>", Provide_Name);
      strcat(display_str,tmp_val_str);

      memcpy(Trans_Toal_Amount,pICS_482131_N->Trans_Toal_Amount,sizeof(pICS_482131_N->Trans_Toal_Amount));
      trim(Trans_Toal_Amount);
      memset(sLeft,0,sizeof(sLeft));
      memset(sRight,0,sizeof(sRight));
      memcpy(sLeft,Trans_Toal_Amount,12);
      memcpy(sRight,Trans_Toal_Amount+12,2);      
      sprintf(tmp_val_str,"总金额： %d.%s  <br>",atoi(sLeft),sRight);
      strcat(display_str,tmp_val_str);

      memcpy(Paid_Amount,pICS_482131_N->Paid_Amount,sizeof(pICS_482131_N->Paid_Amount));
      trim(Paid_Amount);
      memset(sLeft,0,sizeof(sLeft));
      memset(sRight,0,sizeof(sRight));
      memcpy(sLeft,Paid_Amount,12);
      memcpy(sRight,Paid_Amount+12,2);      
      sprintf(tmp_val_str,"已付金额： %d.%s  <br>",atoi(sLeft),sRight);      
      strcat(display_str,tmp_val_str);

      memcpy(Arrearage_Amount,pICS_482131_N->Arrearage_Amount,sizeof(pICS_482131_N->Arrearage_Amount));
      trim(Arrearage_Amount);
      memset(sLeft,0,sizeof(sLeft));
      memset(sRight,0,sizeof(sRight));
      memcpy(sLeft,Arrearage_Amount,12);
      memcpy(sRight,Arrearage_Amount+12,2);      
      sprintf(tmp_val_str,"欠费金额： %d.%s  <br>",atoi(sLeft),sRight);      
      strcat(display_str,tmp_val_str);
                              
      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff, "MGID", tmp_val_str);/*返回码*/


			setValueOfStr(recv_buff, "Reserve_Code", Reserve_Code);
			setValueOfStr(recv_buff, "Product_Name", Product_Name);
      setValueOfStr(recv_buff, "Provide_Name", Provide_Name);
      setValueOfStr(recv_buff, "Trans_Toal_Amount", Trans_Toal_Amount);
      setValueOfStr(recv_buff, "Paid_Amount", Paid_Amount);
      setValueOfStr(recv_buff, "Arrearage_Amount", Arrearage_Amount);
  }
  else if(memcmp(pICS_TOA->RspCod,"482199",sizeof(pICS_TOA->RspCod))==0)/*订单号已缴清*/
  	{
  		memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482131e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482131e_buff));

      strcpy(tmp_val_str,"<font color=ff0000><b>--->订单号已缴清！<br>--->如有疑问或问题请咨询银旅通客户服务热线：4008-960-168</b></font><br>");
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  	}
  else
  { /*失败*/

      memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482131e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482131e_buff));

      strcpy(tmp_val_str,"<font color=ff0000><b>--->定单查询失败！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
      strcat(display_str,tmp_val_str);

      sprintf(tmp_val_str,"--->失败原因：[%s] <br>",sErrMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }

  flog( STEP_LEVEL,"**482131 返回[%s]******************************",recv_buff);

  return 0;
}
