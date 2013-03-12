/****************************************
 *������:subtrans461503_pnta.c
 *��  ��:������ͨ��˰&���ݽ�ͨ����--���Ͳ�������
 *��  ��:2013.2.20
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


int ics_proc_461503_pnta(char *send_buff,char *recv_buff)
{
  /*
  ˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          ics_send_buff-���̨ͨѶ�ķ��ʹ�;
          ics_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int     i;  
  int     len;
  int     ret;
  int     offset;
  int     i_biz_id;

  ICS_DEF_TIA       *pICS_TIA;
  ICS_DEF_TOA       *pICS_TOA;
  ICS_DEF_461503_I_PNTA  *pICS_461503_I;
  ICS_DEF_461503_N_PNTA  *pICS_461503_N;
  ICS_DEF_461503_E_PNTA  *pICS_461503_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_461503i_buff[42];
  char      ics_461503n_buff[9];
  char      ics_461503e_buff[75];

  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      tmp_val_str3[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[300];   /*���ϴ�������ȡ�õ�ĳ��ֵ*/

  char			s_CDNO[LEN_CDNO]; /* ���� */
  char			s_PSWD[20]; /* ���� */

  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      ics_port[6];
  char      sTxnCnl[32];
  char      sErrMsg[64];
  char      sTellerNo[8];
  time_t    cur_time;
  struct tm   *my_tm;

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */

  pICS_461503_I=(ICS_DEF_461503_I_PNTA *)ics_461503i_buff;
  pICS_461503_N=(ICS_DEF_461503_N_PNTA *)ics_461503n_buff;
  pICS_461503_E=(ICS_DEF_461503_E_PNTA *)ics_461503e_buff;
  pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
  pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

  memset(ics_send_buff,'\0',sizeof(ics_send_buff));
  memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
  memset(ics_461503i_buff,'\0',sizeof(ics_461503i_buff));
  memset(ics_461503n_buff,'\0',sizeof(ics_461503n_buff));
  memset(ics_461503e_buff,'\0',sizeof(ics_461503e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  memset(tmp_val_str,'\0',sizeof(tmp_val_str));
  memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
  memset(tmp_val_str3,'\0',sizeof(tmp_val_str3));
  memset(display_str,'\0',sizeof(display_str));
  memset(tmpvalue,'\0',sizeof(tmpvalue));
  memset(sTranNo,'\0',sizeof(sTranNo));
	memset(s_CDNO, '\0', sizeof(s_CDNO));
	memset(s_PSWD, '\0', sizeof(s_PSWD));
  memset(sTxnCnl, '\0', sizeof(sTxnCnl));
  memset(sTellerNo,'\0',sizeof(sTellerNo));
  memset(sTranDate,'\0',sizeof(sTranDate));

  flog( STEP_LEVEL,"--461503 ����[%s]-------------------------------",send_buff);

 /* ע�⣺���������ð��սṹ�����Ⱥ�˳������������ݸ������� */
  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");            /* CICS���״��� */
  strcpy(pICS_TIA->TTxnCd,"461503");
  strcpy(pICS_TIA->FeCod,"461503");
  strcpy(pICS_TIA->TrmNo,"DVID");

  getValueOfStr(send_buff,"TXNSRC", sTxnCnl); /*��������*/
  strcpy(pICS_TIA->TxnSrc,sTxnCnl);

  time(&cur_time);
  my_tm = localtime(&cur_time);
  sprintf(sTranNo,"%d%d%d%d%d%d11", my_tm->tm_year+1900, my_tm->tm_mon+1, my_tm->tm_mday, my_tm->tm_hour, my_tm->tm_min, my_tm->tm_sec);
  sprintf(sTranDate,"%d-%d-%d",my_tm->tm_year+1900,my_tm->tm_mon+1,my_tm->tm_mday);

  strcpy(pICS_TIA->NodTrc,sTranNo);           /*��Ա��*/

  ret = get_config_value(CONFIG_FILE_NAME, "TELLER_NO", sTellerNo);
  if (ret != RETURN_OK)
    return ret;

  strcpy(pICS_TIA->TlrId,sTellerNo);          /*��Ա��*/
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

  /* STEP1-3: ���ϴ����еĹ̶�Ԫ��ֵ*/
  /* ��ʽ: strcpy(pICS_461503_I->RsFld1,"P001"); ������������(��ѯ)*/ 
  /* STEP1-4: ���ϴ������л������ֵ-��getValueOf����*/
 
  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"AdnKnd",tmpvalue);      /*֪ͨ������ 1��ͨ�� 2���ܵ� 3������ 4�����ۿ�*/    
  trim(tmpvalue);
  strcpy(pICS_461503_I->AdnKnd,tmpvalue);
  
  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"AdnCod",tmpvalue);     /* �������� */
  trim(tmpvalue);
  strcpy(pICS_461503_I->AdnCod,tmpvalue);
  
  memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"RgnFlg",tmpvalue);     /*�����ʶ 0���ؼ� 1�м�*/  
  trim(tmpvalue);
  strcpy(pICS_461503_I->RgnFlg,tmpvalue);

  /*STEP1-4:�ѽṹ�еĽ������滻Ϊ�ո��ϴ���ĩβ�ӽ�����.*/
  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
  }

  /* У������ */
  /*
  flog( STEP_LEVEL,"----У������----\n");
  ret = ics_proc_928460( "1", s_CDNO, "1", s_PSWD, pICS_TOA->RspCod ) ;
  if ( ret < 0 )
  {
		flog( STEP_LEVEL,"CALL 928460 Fail [%d]",ret);
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

  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
    if(ics_tia_buff[i]==0)
      ics_tia_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_tia_buff,len);
  offset=offset+sizeof(ICS_DEF_TIA);

  len=sizeof(ICS_DEF_461503_I_PNTA);
  for(i=0;i<len;i++)
  {
    if(ics_461503i_buff[i]==0)
      ics_461503i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_461503i_buff,len);
  offset=offset+sizeof(ICS_DEF_461503_I_PNTA);

  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:���м�ҵ��ǰ�û�ͨѶ-----------------*/
   /* ��ICSͨѶ */
   memset(ics_port,'\0',sizeof(ics_port));

   ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_PNTA", ics_port);

   if (ret != RETURN_OK)
   {
       return -2;
   }
   /*-- ��ӡ���ͱ�����˿� --*/
   flog( STEP_LEVEL,"--����ics����--[%s][%s]",ics_send_buff,ics_port);
   /*-- ���ͽ��׵�ICS�������ܷ��� --*/
   ret=clientics( ics_send_buff,ics_recv_buff, atoi(ics_port) );

   if(ret != RETURN_OK)
       return -1;
   memcpy(pICS_TOA,ics_recv_buff,sizeof(ICS_DEF_TOA));

RETURN:

  /*--------------------STEP3:ͨѶ����:��ɻش�����------------------*/

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0
     ||memcmp(pICS_TOA->RspCod,"SC0000",sizeof(pICS_TOA->RspCod))==0)/*�ɹ�*/
  {
    /* STEP3-1����ҳ����ʾҪ��: ��������д���ֶΣ�������ҳ������ʾ���ֶ� */
    /* ע�⣬<br>��ҳ����ʾ�Ļ��з��� */
  
      memcpy(pICS_461503_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_461503_N_PNTA));
  
      /* ����setValueOf������� */
      /*��ʽ:setValueOfStr(recv_buff,"display_zone",display_str);*/

      setValueOfStr(recv_buff,"MGID","000000");  /*������*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_N->TmpDat,sizeof(pICS_461503_N->TmpDat));
      setValueOfStr(recv_buff,"TmpDat",tmp_val_str);/*���峤��*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_N->ApCode,sizeof(pICS_461503_N->ApCode));
      setValueOfStr(recv_buff,"ApCode",tmp_val_str);/*��ʽ��'SC'*/

      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_N->OFmtCd,sizeof(pICS_461503_N->OFmtCd));
      setValueOfStr(recv_buff,"OFmtCd",tmp_val_str);/*��ʽ��'D04'*/

      /* STEP3-2 ����ҳ������Ҫ��: ������д���ֶΣ�������ҳ����Ϊ����input��Ҫ�� */
      /* ע�⣬1.�������ò�����˳���������ݿ��в�����˳��һ�£�����س��� 
               2.�������ֶ�������ע����WEB��һ��*/ 

  }
  else
  { /*ʧ��*/
      /*��ô��󷵻ذ�*/
      memcpy(pICS_461503_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_461503_E_PNTA));
  
      /* ����setValueOf������� */
      /*��ʽ:setValueOfStr(recv_buff,"display_zone",display_str);*/
      /*memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_E->RspCod,sizeof(pICS_461503_E->RspCod));
      setValueOfStr(recv_buff,"RspCod",tmp_val_str);*//*������       */

      /* �ֻ����з��ز��� */
      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
      setValueOfStr(recv_buff,"RspCod",tmp_val_str);  /*������*/ 


      /* �ֻ����з��ز��� */
      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_E->RspMsg,sizeof(pICS_461503_E->RspMsg));
      setValueOfStr(recv_buff,"RspMsg",tmp_val_str);/*������       */

      /* �����������ز��� */
      memset(tmp_val_str,'\0',sizeof(tmp_val_str));
      memcpy(tmp_val_str,pICS_461503_E->RspMsg,sizeof(pICS_461503_E->RspMsg));
      setValueOfStr(recv_buff,"PB_Return_Code_Msg",tmp_val_str);/*������       */
  }
  flog( STEP_LEVEL,"**461503 ����[%s]******************************",recv_buff);
  return 0;

}
