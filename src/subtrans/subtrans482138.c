/****************************************
 *������:subtrans482138.c
 *��  ��:���ͨ���г�ֵǩԼ����
 *��  ��:2008-10-10
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


int ics_proc_482138(char *send_buff,char *recv_buff)
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
  ICS_DEF_482138_I  *pICS_482138_I;
  ICS_DEF_482138_N  *pICS_482138_N;
  ICS_DEF_482138_E  *pICS_482138_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482138i_buff[559];
  char      ics_482138n_buff[21];
  char      ics_482138e_buff[71];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*���ϴ�������ȡ�õ�ĳ��ֵ*/
  char      ics_482138o_buff[4096];

  char			s_CDNO[LEN_CDNO]; /* ���� */
  char			s_PSWD[21]; /* ���� */
  
  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      PB_Return_Code_Msg[64];
  char      ics_port[6];

  char			sSTxnAmt[32];
  char			sTCusNm[32];
  char			sLoSeq[32];
  char      sCarType[32];
  char      sCarNo[32];
  char      sTxnCnl[32];
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
  memset(ics_482138i_buff,'\0',sizeof(ics_482138i_buff));
  memset(ics_482138n_buff,'\0',sizeof(ics_482138n_buff));
  memset(ics_482138e_buff,'\0',sizeof(ics_482138e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));
  memset(ics_482138o_buff, 0, sizeof(ics_482138o_buff));

  pICS_482138_I=(ICS_DEF_482138_I *)ics_482138i_buff;
  pICS_482138_N=(ICS_DEF_482138_N *)ics_482138n_buff;
  pICS_482138_E=(ICS_DEF_482138_E *)ics_482138e_buff;
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
  memset( PB_Return_Code_Msg, '\0', sizeof( PB_Return_Code_Msg ) ) ;
  
  memset(s_CDNO, '\0', sizeof(s_CDNO));
	memset(s_PSWD, '\0', sizeof(s_PSWD));

  flog( STEP_LEVEL,"--482138 ����[%s]------------------------------",send_buff);
  
  /*���ն˵Ľ���������ֵ����*/
  /* ���TXNSRCֵû������,Ĭ��ʹ��WE441 */
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  if(strstr(send_buff,"TXNSRC")){
    getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*��������*/
  }else{
    strcpy(sTxnCnl, "WE441");
  }
  strcpy(pICS_TIA->TxnSrc, sTxnCnl);

  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");
	strcpy(pICS_TIA->TTxnCd,"482138");
  strcpy(pICS_TIA->FeCod,"482138");

  strcpy(pICS_TIA->TrmNo,"DVID");

  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);

  strcpy(pICS_TIA->NodTrc,sTranNo);


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
	
	flog( STEP_LEVEL,"TO ics_tia_buff: [%s]",ics_tia_buff);
	/* strcpy(pICS_482138_I->sign_flag,"3");ǩԼ���� 1���ֹ�ǩԼ 2���绰ǩԼ 3������ǩԼ */
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"sign_flag",tmpvalue); /*ǩԼ���� 1���ֹ�ǩԼ 2���绰ǩԼ 3������ǩԼ 4:�ֻ�����*/
  strcpy(pICS_482138_I->sign_flag,tmpvalue);
	strcpy(pICS_482138_I->inst_no,"��ͨ����");/*ǩԼ���� */
	strcpy(pICS_482138_I->live_flag,"1");/*�����־ 0-���� 1-δ���� */
	strcpy(pICS_482138_I->tran_flag,"1");/*���ױ�־ 0-������ 1-�������� */
	
	/*memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"acc_type",tmpvalue);*/ /*�ۿʽ 1:Ԥ�ۿ��û� 0:ʵʱ�ۿ��û� */
  strcpy(pICS_482138_I->acc_type,"0");
    
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"bank_acc",tmpvalue); /*�˺� */
  strcpy(pICS_482138_I->bank_acc,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"paper_no",tmpvalue); /*֤�����ͺ��� */
  strcpy(pICS_482138_I->paper_no,tmpvalue);
    
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"cust_name",tmpvalue); /*�û����� */
  strcpy(pICS_482138_I->cust_name,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"sex_code",tmpvalue); /*�Ա� */
  strcpy(pICS_482138_I->sex_code,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"phone_no",tmpvalue); /*�绰���� */
  strcpy(pICS_482138_I->phone_no,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"mobile_no",tmpvalue); /*�ֻ�����*/
  strcpy(pICS_482138_I->mobile_no,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"post_no",tmpvalue); /*�ʱ�*/
  strcpy(pICS_482138_I->post_no,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"address",tmpvalue); /*��ַ*/
  strcpy(pICS_482138_I->address,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"email",tmpvalue); /*email����*/
  strcpy(pICS_482138_I->email,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"card1",tmpvalue); /*���ͨ����1*/
  strcpy(pICS_482138_I->card1,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"card2",tmpvalue); /*���ͨ����2*/
  strcpy(pICS_482138_I->card2,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"card3",tmpvalue); /*���ͨ����3*/
  strcpy(pICS_482138_I->card3,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"card4",tmpvalue); /*���ͨ����4*/
  strcpy(pICS_482138_I->card4,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"limite",tmpvalue); /*���*/
  strcpy(pICS_482138_I->limite,tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"frequence",tmpvalue); /*Ƶ��*/
  strcpy(pICS_482138_I->frequence,tmpvalue);

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"bank_acc", tmpvalue); /*����*/
  strcpy(s_CDNO, tmpvalue);
  
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"PSWD",tmpvalue); /*����*/
  strcpy(s_PSWD,tmpvalue);
  strcpy(pICS_482138_I->PinBlk,tmpvalue);

  /* У������ modify by ylw 20120211 for ��ؿ�
  ret = ics_proc_928460( "1", s_CDNO, "1", s_PSWD, pICS_TOA->RspCod ) ;
  if ( ret < 0 )
  {
		flog( STEP_LEVEL,"CALL 928460 Fail [%d]",ret);
                strcpy(pICS_TOA->RspCod,"999460");
		sprintf( sErrMsg, "����У��ʧ��![%d]", ret );
		goto RETURN;
  }
  if( memcmp( pICS_TOA->RspCod, "000000", 6 ) != 0 )
  {
		flog( STEP_LEVEL,"928460 return [%s]", pICS_TOA->RspCod ) ;
		goto RETURN;
  } 
*/
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
  
  
  len=sizeof(ICS_DEF_482138_I);
  for(i=0;i<len;i++)
  {
  	if(ics_482138i_buff[i]==0)
   		ics_482138i_buff[i]=' ';
  }
  flog( STEP_LEVEL,"TO ics_482138i_buff: [%s]",ics_482138i_buff);
  memcpy(ics_send_buff+offset, ics_482138i_buff, len);
  offset=offset+len;


  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

    /* ��ICSͨѶ */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_YCT", ics_port);
  if (ret != RETURN_OK)
        return ret;

	flog( STEP_LEVEL,"TO ICS_PORT: [%s]",ics_send_buff);
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

      memcpy(ics_482138n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482138n_buff));

			memcpy(ics_482138o_buff, ics_recv_buff+sizeof(ics_toa_buff)+sizeof(ics_482138n_buff),  sizeof(ics_recv_buff)-sizeof(ics_toa_buff)-sizeof(ics_482138n_buff));
      
      setValueOfStr(recv_buff,"display_zone","");
      
      setValueOfStr(recv_buff,"jingquxingxi", ics_482138o_buff);

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff, "MGID", tmp_val_str);/*������*/
  }
  else
  { /*ʧ��*/



      memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;

      memcpy(ics_482138e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482138e_buff));

      memset(PB_Return_Code_Msg,'\0',sizeof(PB_Return_Code_Msg));
      memcpy(PB_Return_Code_Msg,pICS_482138_E->RspMsg,sizeof(pICS_482138_E->RspMsg));
      
      if( memcmp( pICS_TOA->RspCod, "PC5012", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "���벻��" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "PD5012", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "���벻��" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "PD5100", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "��ǿ���������" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "PC3254", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "�˽��ײ�����͸֧" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "PD5044", 6 ) == 0 )
         strcpy( PB_Return_Code_Msg, "������������������" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "TC2051", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "����У���" ) ;
      else
      if( memcmp( pICS_TOA->RspCod, "999460", 6 ) == 0 )
          strcpy( PB_Return_Code_Msg, "����У����ô���"); 
      else
          memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;
        
      /*
      strcpy(tmp_val_str,"<font color=ff0000><b>--->���ͨ���г�ֵǩԼʧ�ܣ�<br>--->�������ʣ��뼰ʱ�뿪��������ϵ��</b></font><br>");
      */
      strcat(display_str,tmp_val_str);

      sprintf(tmp_val_str,"--->ʧ��ԭ��[%s] <br>",sErrMsg);
      strcat(display_str,tmp_val_str);

      setValueOfStr(recv_buff,"display_zone",display_str);
      
      setValueOfStr(recv_buff,"PB_Return_Code_Msg",PB_Return_Code_Msg);/*������*/
      
      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/
  }

  flog( STEP_LEVEL,"**482138 ����[%s]******************************",recv_buff);

  return 0;
}

