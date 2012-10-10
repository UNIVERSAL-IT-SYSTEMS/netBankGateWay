/****************************************
 *程序名:trans482159.c
 *功  能:历史记录查询
 *日  期:2009.05.21
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


int ics_proc_482159(char *send_buff,char *recv_buff)
{
  /*说明：send_buff-上传报文；
          recv_buff-下传报文;
          ics_send_buff-与后台通讯的发送串;
          ics_recv_buff-与后台通讯的接收串;
 */

  int			i;	
  int 			len;
  int                   ret;
  int			offset;
  int			i_biz_id;

  ICS_DEF_TIA		*pICS_TIA;
  ICS_DEF_TOA		*pICS_TOA;
  ICS_DEF_482159_I	*pICS_482159_I;
  ICS_DEF_482159_N	*pICS_482159_N;
  ICS_DEF_482159_E	*pICS_482159_E;

  char			ics_send_buff[LEN_ICS_PROC_BUF];
  char			ics_recv_buff[LEN_ICS_PROC_BUF];
  char			ics_482159i_buff[21];
  char			ics_482159n_buff[21];
  char			ics_482159e_buff[71];
  char			ics_tia_buff[171];
  char			ics_toa_buff[114];
  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			tmp_val_str3[LEN_TMP_VAL_STR];
  char 			display_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[40]; 	/*从上传报文中取得的某项值*/
  char			sLen[8];
  char			sLeft[14];
  char			sRight[3];
  char    	sTranNo[16];
	char			sTranDate[11];
  char    	sTellerNo[8];
  char			ics_port[6];    
  char			tmp_buf[LEN_ICS_PROC_BUF];
  time_t    cur_time;

  struct tm   *my_tm;

  FILE 			*fp;

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */

  pICS_482159_I=(ICS_DEF_482159_I *)ics_482159i_buff;
  pICS_482159_N=(ICS_DEF_482159_N *)ics_482159n_buff;
  pICS_482159_E=(ICS_DEF_482159_E *)ics_482159e_buff;
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

	memset(ics_send_buff,'\0',sizeof(ics_send_buff));
	memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
	memset(ics_482159i_buff,'\0',sizeof(ics_482159i_buff));
	memset(ics_482159n_buff,'\0',sizeof(ics_482159n_buff));
	memset(ics_482159e_buff,'\0',sizeof(ics_482159e_buff));
	memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
	memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(tmp_val_str3,'\0',sizeof(tmp_val_str3));
  memset(display_str,'\0',sizeof(display_str));
  memset(sTranNo,'\0',sizeof(sTranNo));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
  memset(tmpvalue,'\0',sizeof(tmpvalue));

	memset(tmp_buf,'\0',sizeof(tmp_buf));

flog( STEP_LEVEL,"--482159 接收[%s]-------------------------------",send_buff);

 	/* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
 	 /* STEP1-2:填上传串的固定头 */
 	 
  strcpy(pICS_TIA->CCSCod,"TLU6");   /* CICS交易代码 */
  strcpy(pICS_TIA->TTxnCd,"482159");
  strcpy(pICS_TIA->FeCod,"482159");
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
  strcpy(pICS_TIA->NodNo,"441200");
  strcpy(pICS_TIA->OprLvl," ");
  strcpy(pICS_TIA->TrmVer,"v0000001");
  strcpy(pICS_TIA->OutSys," ");
  strcpy(pICS_TIA->Fil,"  ");

  /* STEP1-3: 填上传串中的固定元素值*/
  getValueOfStr(send_buff,"CDNO",tmpvalue); /*卡号*/
  strcpy(pICS_482159_I->ActNo,tmpvalue);

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

  len=sizeof(ICS_DEF_482159_I);
  for(i=0;i<len;i++)
  {
  	if(ics_482159i_buff[i]==0)
   		ics_482159i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482159i_buff,len);
  offset=offset+sizeof(ICS_DEF_482159_I);

  /*发往ICS需加8位报文长度在头*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
   /* 与ICS通讯 */
   memset(ics_port,'\0',sizeof(ics_port));

   ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_YCT", ics_port);
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

	memcpy(tmp_buf,ics_recv_buff+sizeof(ICS_DEF_TOA)+21,strlen(ics_recv_buff)-sizeof(ICS_DEF_TOA)-21);
		
	/* 调用setValueOf函数填充 */
	setValueOfStr(recv_buff,"display_zone",tmp_buf);
    	
	setValueOfStr(recv_buff, "MGID", "000000");/*返回码*/
		
 /* STEP3-2 处理页面隐含要素: 这里填写的字段，就是在页面作为隐含input的要素 */
 /* 注意，1.这里设置参数的顺序必须和数据库中参数的顺序一致，否则回出错！ 
          2.返回码字段名定义注意与WEB上一致*/ 
  }
  else
  {	/*失败*/
	memcpy(pICS_482159_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482159_E));
	strcpy(tmp_val_str,"<font color=ff0000>--->查询历史交易记录失败</font><br>");
	strcat(display_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
	sprintf(tmp_val_str,"--->失败原因：[%s] ",tmp_val_str2);
	strcat(display_str,tmp_val_str);

    memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482159_E->RspMsg,sizeof(pICS_482159_E->RspMsg));
	sprintf(tmp_val_str,"[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

   	setValueOfStr(recv_buff,"display_zone",display_str);

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
 	setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/
  }
flog( STEP_LEVEL,"**482159 返回[%s]******************************",recv_buff);

  return 0;
}


