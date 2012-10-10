/****************************************
 *������:subtransConfirm.c
 *��  ��:����
 *��  ��:2007-05
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


int ics_proc_confirm(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          ics_send_buff-���̨ͨѶ�ķ��ʹ�;
          ics_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int			i;	
  int 			len;
  int                   ret;
  int                   offset;
  int                   i_biz_id;

/*
  ICS_DEF_TIA		*pICS_TIA;
  ICS_DEF_TOA		*pICS_TOA;
  ICS_DEF_482102_I	*pICS_482102_I;
  ICS_DEF_482102_N	*pICS_482102_N;
  ICS_DEF_482102_E	*pICS_482102_E;

  char			ics_send_buff[LEN_ICS_PROC_BUF];
  char			ics_recv_buff[LEN_ICS_PROC_BUF];
  char			ics_482102i_buff[245];
  char			ics_482102n_buff[125];
  char			ics_482102e_buff[71];
  char			ics_tia_buff[171];
  char			ics_toa_buff[114];
*/
  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			display_str[LEN_ICS_PROC_BUF];
  char 			display_log_str[LEN_ICS_PROC_BUF];
  char                  tmpvalue[256];	/*���ϴ�������ȡ�õ�ĳ��ֵ*/
  char			s_CDNO[LEN_CDNO]; /* ���� */
  char			s_PSWD[20]; /* ���� */
  char                  sLen[8];
  char                  sLeft[14];
  char                  sRight[3];
  char                  sTranNo[16];
  char                  sTranDate[11];
  char                  sTellerNo[8];
  char                  sTitle[30];
  char                  sErrMsg[64];
  char			ics_port[6];

  time_t		cur_time;   

  struct tm		*my_tm;

  FILE 			*fp;

/*
  void *pComplibhandle; * Handle to shared lib file *
  int (*pCompfunchandle)(); * Pointer to loaded routine */ 

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

 	/* STEP1-1:����ṹ�ͱ��� */

/*
	memset(ics_send_buff,'\0',sizeof(ics_send_buff));
	memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
	memset(ics_482102i_buff,'\0',sizeof(ics_482102i_buff));
	memset(ics_482102n_buff,'\0',sizeof(ics_482102n_buff));
	memset(ics_482102e_buff,'\0',sizeof(ics_482102e_buff));
	memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
	memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

        pICS_482102_I=(ICS_DEF_482102_I *)ics_482102i_buff;
        pICS_482102_N=(ICS_DEF_482102_N *)ics_482102n_buff;
        pICS_482102_E=(ICS_DEF_482102_E *)ics_482102e_buff;
        pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
        pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;
*/

        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
        memset(display_str,'\0',sizeof(display_str));
        memset(display_log_str,'\0',sizeof(display_log_str));
        memset(tmpvalue,'\0',sizeof(tmpvalue));
        memset(s_CDNO,'\0',sizeof(s_CDNO));
        memset(s_PSWD,'\0',sizeof(s_PSWD));
        memset(sTranNo,'\0',sizeof(sTranNo));
        memset(sTitle,'\0',sizeof(sTitle));
        memset(sErrMsg,'\0',sizeof(sErrMsg));
        memset(sTranDate,'\0',sizeof(sTranDate));
        memset(sTellerNo,'\0',sizeof(sTellerNo));
	memset( sErrMsg, '\0', sizeof( sErrMsg ) ) ;

flog( STEP_LEVEL,"--482102 ����[%s]------------------------------",send_buff);

  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
/*
  strcpy(pICS_TIA->CCSCod,"TLU6"); 
  strcpy(pICS_TIA->TTxnCd,"482102");
  strcpy(pICS_TIA->FeCod,"482102");
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
*/

  /* STEP1-3: ���ϴ�����Ԫ��ֵ*/
/*
  strcpy(pICS_482102_I->RsFld1,"P002"); /*������������(�ɷ�)*/

  getValueOfStr(send_buff,"biz_id",tmpvalue); /*������ҵ������*/
  i_biz_id = atoi(tmpvalue);
  switch(i_biz_id)
  {
    case 1:	/*���л���*/
	strcpy(pICS_482102_I->RsFld2,"0001");
	strcpy(sTitle,"�ɵ��Ź̻�Ƿ��");
	break;
    case 2:	/*С��ͨԤ���ѳ�ֵ*/
	strcpy(pICS_482102_I->RsFld2,"0064");
	strcpy(sTitle,"����С��ͨ��ֵ");
	break;
    case 3:	/*����16300������*/
	strcpy(pICS_482102_I->RsFld2,"0010");
	strcpy(sTitle,"����16300������");
	break;
    case 4:	/*����ADSL������*/
	strcpy(pICS_482102_I->RsFld2,"0013");
	strcpy(sTitle,"����ADSL������");
	break;
    case 5:	/*����Ԥ�ɷѿ���ֵ*/
	strcpy(pICS_482102_I->RsFld2,"0046");
	strcpy(sTitle,"����Ԥ�ɷѿ���ֵ");
	break;
    case 6:	/*���ſ��Ԥ�ɷ�*/
	strcpy(pICS_482102_I->RsFld2,"0071");
	strcpy(sTitle,"���ſ��Ԥ�ɷ�");
	break;
    default:
	break;
  }
*/

  getValueOfStr(send_buff,"CTSQ",tmpvalue); /*�ɷѺ���*/
  strcpy(s_CTSQ,tmpvalue);

  getValueOfStr(send_buff,"AMT1",tmpvalue); /*�ɷѽ��*/
  strcpy(s_AMT1,tmpvalue);

  getValueOfStr(send_buff,"CDNO",tmpvalue); /*����*/
  strcpy(s_CDNO,tmpvalue);

  getValueOfStr(send_buff,"PSWD",tmpvalue); /*����*/
  strcpy(s_PSWD,tmpvalue);


/*
flog( STEP_LEVEL, "ret=[%d]", ret ) ;
goto RETURN;
*/

  /*����ICS���8λ���ĳ���*
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

  len=sizeof(ICS_DEF_482102_I);
  for(i=0;i<len;i++)
  {
  	if(ics_482102i_buff[i]==0)
   		ics_482102i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482102i_buff,len);
  offset=offset+sizeof(ICS_DEF_482102_I);

  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  
  *����ICS���8λ���ĳ�����ͷ*/

    /* ��ICSͨѶ */
/*
    memset(ics_port,'\0',sizeof(ics_port));

    ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_TRANS", ics_port);
    if (ret != RETURN_OK)
        return ret;

flog( STEP_LEVEL,"TO ICS: [%s]",ics_send_buff);

    ret=clientics( ics_send_buff, ics_recv_buff, atoi(ics_port) );
	if(ret != RETURN_OK)
		return(-1);

flog( STEP_LEVEL,"FROM ICS: [%s]",ics_recv_buff);
*/

  /*--------------------ͨѶ����:��ɻش�����------------------*/


	sprintf(tmp_val_str,"ҵ�����ͣ� %s  <br>",sTitle);
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"�������ڣ� %s  <br>",sTranDate);
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"�ɷѿ��ţ� %s  <br>",s_CDNO);
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"�绰���룺 %s  <br>", s_CTSQ );
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_N->TCusNm,sizeof(pICS_482102_N->TCusNm));
	sprintf(tmp_val_str,"�ͻ������� %s  <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_I->TxnAmt,sizeof(pICS_482102_I->TxnAmt));
	memset(sLeft,0,sizeof(sLeft));
	memset(sRight,0,sizeof(sRight));
	memcpy(sLeft,tmp_val_str2,13);
	memcpy(sRight,tmp_val_str2+13,2);
	if(i_biz_id==2)
	    sprintf(tmp_val_str,"��ֵ�� %d.%s  <br>",atoi(sLeft),sRight);
	else
	    sprintf(tmp_val_str,"�ɷѽ� %d.%s  <br>",atoi(sLeft),sRight);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_N->TckNo,sizeof(pICS_482102_N->TckNo));
	sprintf(tmp_val_str,"������ţ� %s  <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        strcat(display_str,"<b>���ѳɹ�! �뼰ʱ��ѯ�����</b><br>");

        /* STEP3-1-1 ����־�м�¼�й����ݱ��� begin*/
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_I->TCusID,sizeof(pICS_482102_I->TCusID));
	sprintf(tmp_val_str,"�绰���룺[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_N->TckNo,sizeof(pICS_482102_N->TckNo));
	sprintf(tmp_val_str,"�����ˮ��[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482102_I->TxnAmt,sizeof(pICS_482102_I->TxnAmt));
	sprintf(tmp_val_str,"���ѽ�[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

    	setValueOfStr(recv_buff,"display_zone",display_str);

        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
        setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/

flog( STEP_LEVEL,"**confirm ����[%s]******************************",recv_buff);

  return 0;
}
