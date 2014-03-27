/****************************************
 *������:subtrans482171.c
 *��  ��:�û�״̬��ѯ
 *��  ��:2008-10-24
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


int ics_proc_482171(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          ics_send_buff-���̨ͨѶ�ķ��ʹ�;
          ics_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int     i;
  int     len;
  int     ret;
  int     offset;
  int     i_biz_id;

  ICS_DEF_TIA   *pICS_TIA;
  ICS_DEF_TOA   *pICS_TOA;
  ICS_DEF_482171_I  *pICS_482171_I;
  ICS_DEF_482171_N  *pICS_482171_N;
  ICS_DEF_482171_E  *pICS_482171_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482171i_buff[20];
  char      ics_482171n_buff[31];
  char      ics_482171e_buff[71];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*���ϴ�������ȡ�õ�ĳ��ֵ*/

  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      ics_port[6];
  char      sTxnCnl[32];
  
  char      User_status[3];
  char 			sStatus[16];

  time_t    cur_time;

  struct tm   *my_tm;

  FILE      *fp;

/*
  void *pComplibhandle; * Handle to shared lib file *
  int (*pCompfunchandle)(); * Pointer to loaded routine */

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */

  memset(ics_send_buff,'\0',sizeof(ics_send_buff));
  memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
  memset(ics_482171i_buff,'\0',sizeof(ics_482171i_buff));
  memset(ics_482171n_buff,'\0',sizeof(ics_482171n_buff));
  memset(ics_482171e_buff,'\0',sizeof(ics_482171e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482171_I=(ICS_DEF_482171_I *)ics_482171i_buff;
  pICS_482171_N=(ICS_DEF_482171_N *)ics_482171n_buff;
  pICS_482171_E=(ICS_DEF_482171_E *)ics_482171e_buff;
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

  flog( STEP_LEVEL,"--482171 ����[%s]------------------------------",send_buff);

  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");
	strcpy(pICS_TIA->TTxnCd,"482171");
  strcpy(pICS_TIA->FeCod,"482171");
  
  strcpy(pICS_TIA->TrmNo,"DVID");
  
  /*���ն˵Ľ���������ֵ����*/
  /* ���TXNSRCֵû������,Ĭ��ʹ��WE441 */
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  if(strstr(send_buff,"TXNSRC")){
    getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*��������*/
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

  /* STEP1-3: ���ϴ�����Ԫ��ֵ*/
  getValueOfStr(send_buff,"CTSQ", tmpvalue);   /* �ɷѺ��� */
  strcpy(pICS_482171_I->user_number, tmpvalue);

  /*����ICS���8λ���ĳ���*/
  offset=0;
  offset=offset+8;

  /*STEP1-4:�ѽṹ�еĽ������滻Ϊ�ո��ϴ���ĩβ�ӽ�����.*/
  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_tia_buff,len);
  offset=offset+sizeof(ICS_DEF_TIA);

  len=sizeof(ICS_DEF_482171_I);
  for(i=0;i<len;i++)
  {
    if(ics_482171i_buff[i]==0)
      ics_482171i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482171i_buff,len);
  offset=offset+sizeof(ICS_DEF_482171_I);

  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

    /* ��ICSͨѶ */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_MOBL", ics_port);
  if (ret != RETURN_OK)
        return ret;

  flog( STEP_LEVEL,"TO ICS: [%s]",ics_send_buff);

  ret=clientics( ics_send_buff, ics_recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
    return(-1);

  flog( STEP_LEVEL,"FROM ICS: [%s]",ics_recv_buff);

  /*--------------------ͨѶ����:��ɻش�����------------------*/

  memcpy(ics_toa_buff,ics_recv_buff,sizeof(ics_toa_buff));

RETURN:
  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*�ɹ�*/
  {
  /* STEP3-1����ҳ����ʾҪ��: ��������д���ֶΣ�������ҳ������ʾ���ֶ� */
  /* ע�⣬<br>��ҳ����ʾ�Ļ��з��� */

      memcpy(ics_482171n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482171n_buff));

      memset(User_status, 0, sizeof(User_status));

      memcpy(User_status,pICS_482171_N->User_status,sizeof(pICS_482171_N->User_status));
      trim(User_status);
      if(memcmp(User_status,"00",2)==0)
      {
      	memset(tmpvalue,0,sizeof(tmpvalue));
      	memcpy(tmpvalue,pICS_482171_I->user_number,sizeof(pICS_482171_I->user_number));
      	sprintf(tmp_val_str,"�ֻ����룺 %s  <br>", tmpvalue);
	      strcat(display_str,tmp_val_str);
	
	      setValueOfStr(recv_buff,"display_zone",display_str);
	
	      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
	      setValueOfStr(recv_buff, "MGID", tmp_val_str);/*������*/
	
				setValueOfStr(recv_buff, "User_status", User_status);/*�ֻ�״̬��*/
				memset(tmp_val_str,'\0',sizeof(tmp_val_str));
				memcpy(tmp_val_str,pICS_482171_I->user_number,sizeof(pICS_482171_I->user_number));
				trim(tmp_val_str);
				setValueOfStr(recv_buff, "CTSQ", tmp_val_str);
      }
      else
      {
      	memset(sStatus,0,sizeof(sStatus));
      	switch(atoi(User_status))
      	{
      		case 1:
      			strcpy(sStatus,"����ͣ��");
      			break;
      		case 2:
      			strcpy(sStatus,"�ֻ���ͣ��");
      			break;
      		case 3:
      			strcpy(sStatus,"Ԥ����");
      			break;
      		case 4:
      			strcpy(sStatus,"�ֻ�������");
      			break;
      		default:
      			strcpy(sStatus,"״̬������");
      			break;
      	}
      	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      	sprintf(tmp_val_str,"<font color=ff0000><b>--->�ֻ�״̬�� %s  <br></font><br>",sStatus);
      	strcat(display_str,tmp_val_str); 
	
	      setValueOfStr(recv_buff,"display_zone",display_str);
	      setValueOfStr(recv_buff, "MGID", "000001");/*������*/
	
				memset(tmp_val_str,'\0',sizeof(tmp_val_str));
				memcpy(tmp_val_str,pICS_482171_I->user_number,sizeof(pICS_482171_I->user_number));
				trim(tmp_val_str);
				setValueOfStr(recv_buff, "CTSQ", tmp_val_str);
			}
  }
  else
  { /*ʧ��*/

      memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482171e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482171e_buff));

      strcpy(tmp_val_str,"<font color=ff0000><b>--->��ѯ�ֻ�״̬ʧ�ܣ�<br>--->�������ʣ��뼰ʱ�뿪��������ϵ��</b></font><br>");
      strcat(display_str,tmp_val_str);

      sprintf(tmp_val_str,"--->ʧ��ԭ��[%s] <br>",sErrMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/
  }

  flog( STEP_LEVEL,"**482171 ����[%s]******************************",recv_buff);

  return 0;
}
