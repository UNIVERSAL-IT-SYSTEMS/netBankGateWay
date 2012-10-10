/****************************************
 *������:trans482184.c
 *��  ��:�㶫ʡ����ֱ����ֵ�û����Դ�����ѯ
 *��  ��:2011.3.11
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


int ics_proc_482184(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          ics_send_buff-���̨ͨѶ�ķ��ʹ�;
          ics_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int			i;	
  int 		len;
  int     ret;
  int			offset;
  int			i_biz_id;

  ICS_DEF_TIA		*pICS_TIA;
  ICS_DEF_TOA		*pICS_TOA;
  ICS_DEF_482184_I	*pICS_482184_I;
  ICS_DEF_482184_N	*pICS_482184_N;
  ICS_DEF_482184_E	*pICS_482184_E;

  char			ics_send_buff[LEN_ICS_PROC_BUF];
  char			ics_recv_buff[LEN_ICS_PROC_BUF];
  char			ics_482184i_buff[38];
  char			ics_482184n_buff[118];
  char			ics_482184e_buff[75];
  char			ics_tia_buff[171];
  char			ics_toa_buff[114];
  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			tmp_val_str3[LEN_TMP_VAL_STR];
  char 			display_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[40]; 	/*���ϴ�������ȡ�õ�ĳ��ֵ*/
  char			sLen[8];
  char			sLeft[14];
  char			sRight[3];
  char			ics_port[6];

  FILE 			*fp;

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */

	pICS_482184_I=(ICS_DEF_482184_I *)ics_482184i_buff;
	pICS_482184_N=(ICS_DEF_482184_N *)ics_482184n_buff;
	pICS_482184_E=(ICS_DEF_482184_E *)ics_482184e_buff;
	pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
	pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

	memset(ics_send_buff,'\0',sizeof(ics_send_buff));
	memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
	memset(ics_482184i_buff,'\0',sizeof(ics_482184i_buff));
	memset(ics_482184n_buff,'\0',sizeof(ics_482184n_buff));
	memset(ics_482184e_buff,'\0',sizeof(ics_482184e_buff));
	memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
	memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
	memset(tmp_val_str3,'\0',sizeof(tmp_val_str3));
	memset(display_str,'\0',sizeof(display_str));
	memset(tmpvalue,'\0',sizeof(tmpvalue));
  
flog( STEP_LEVEL,"--482184 ����[%s]-------------------------------",send_buff);

 /* ע�⣺���������ð��սṹ�����Ⱥ�˳������������ݸ������� */
  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");   /* CICS���״��� */
  strcpy(pICS_TIA->TTxnCd,"482184");
  strcpy(pICS_TIA->FeCod,"482184");
  strcpy(pICS_TIA->TrmNo,"DVID");
  strcpy(pICS_TIA->TxnSrc,"T0001");   
  strcpy(pICS_TIA->NodTrc,"200704100044191");
  strcpy(pICS_TIA->TlrId,"ABIA041");
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
  strcpy(pICS_TIA->NodNo,"441800");
  strcpy(pICS_TIA->OprLvl," ");
  strcpy(pICS_TIA->TrmVer,"v0000001");
  strcpy(pICS_TIA->OutSys," ");
  strcpy(pICS_TIA->Fil,"  ");

  /* STEP1-3: ���ϴ����еĹ̶�Ԫ��ֵ*/
  /*strcpy(pICS_482180_I->MsgType,"1129"); ��Ϣ���(��ѯ�û�����)*/

  /* STEP1-4: ���ϴ������л������ֵ-��getValueOf����*/
  getValueOfStr(send_buff,"biz_id",tmpvalue); /*������ҵ������*/
  i_biz_id = atoi(tmpvalue);

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"CTSQ",tmpvalue); /*�ɷѺ���*/
  strcpy(pICS_482184_I->TCusID,tmpvalue);

  memset(tmpvalue,'\0',sizeof(tmpvalue));
  getValueOfStr(send_buff,"DestAttr",tmpvalue); /*����ѯ�û�����(0:�̻� 1:С��ͨ��2:�ƶ���3:ADSL��4:���ܹ�����5:�����ǿգ�6:�������˻�)*/
  strcpy(pICS_482184_I->DestAttr,tmpvalue);

  /*STEP1-4:�ѽṹ�еĽ������滻Ϊ�ո��ϴ���ĩβ�ӽ�����.*/
  len=sizeof(ICS_DEF_TIA);
  for(i=0;i<len;i++)
  {
  	if(ics_tia_buff[i]==0)
   		ics_tia_buff[i]=' ';
  }

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

  len=sizeof(ICS_DEF_482184_I);
  for(i=0;i<len;i++)
  {
  	if(ics_482184i_buff[i]==0)
   		ics_482184i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482184i_buff,len);
  offset=offset+sizeof(ICS_DEF_482184_I);

  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:���м�ҵ��ǰ�û�ͨѶ-----------------*/
   /* ��ICSͨѶ */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_DXCZ", ics_port);
  if (ret != RETURN_OK)
  {
		return -2;
  }

  ret=clientics( ics_send_buff,ics_recv_buff, atoi(ics_port) );
  if(ret != RETURN_OK)
		return -1;

  memcpy(pICS_TOA,ics_recv_buff,sizeof(ICS_DEF_TOA));

  /*--------------------STEP3:ͨѶ����:��ɻش�����------------------*/

  if(memcmp(pICS_TOA->RspCod,"000000",sizeof(pICS_TOA->RspCod))==0)/*�ɹ�*/
  {
  /* STEP3-1����ҳ����ʾҪ��: ��������д���ֶΣ�������ҳ������ʾ���ֶ� */
  /* ע�⣬<br>��ҳ����ʾ�Ļ��з��� */

		memcpy(pICS_482184_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482184_N));

  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_482184_N->Balance,sizeof(pICS_482184_N->Balance));
		memset(sLeft,0,sizeof(sLeft));
		memset(sRight,0,sizeof(sRight));
		memcpy(sLeft,tmp_val_str2,10);
		memcpy(sRight,tmp_val_str2+10,2);
		sprintf(tmp_val_str,"������ %d.%s  <br>",atoi(sLeft),sRight);
		strcat(display_str,tmp_val_str);
  	
  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_482184_N->EffTime,8);
		sprintf(tmp_val_str,"�����Ч�ڿ�ʼʱ�䣺 %s <br>",tmp_val_str2);
		strcat(display_str,tmp_val_str);
		
  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_482184_N->ExpireTime,8);
		sprintf(tmp_val_str,"����ʱ�䣺 %s <br>",tmp_val_str2);
		strcat(display_str,tmp_val_str);
  	
  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_482184_N->DqCode,sizeof(pICS_482184_N->DqCode));
		sprintf(tmp_val_str,"������������ţ� %s <br>",tmp_val_str2);
		strcat(display_str,tmp_val_str);
  	
		/* ����setValueOf������� */
  	setValueOfStr(recv_buff,"display_zone",display_str);
  	
 		/* STEP3-2 ����ҳ������Ҫ��: ������д���ֶΣ�������ҳ����Ϊ����input��Ҫ�� */
 		/* ע�⣬1.�������ò�����˳���������ݿ��в�����˳��һ�£�����س��� 
  	        2.�������ֶ�������ע����WEB��һ��*/ 
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
		setValueOfStr(recv_buff,"MGID",tmp_val_str); /*������*/ 

		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->BalTyp,sizeof(pICS_482184_N->BalTyp));
		setValueOfStr(recv_buff,"BalTyp",tmp_val_str);/*�������*/ 
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->Balance,sizeof(pICS_482184_N->Balance));
		setValueOfStr(recv_buff,"Balance",tmp_val_str);/*�������*/ 
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->EffTime,sizeof(pICS_482184_N->EffTime));
		setValueOfStr(recv_buff,"EffTime",tmp_val_str);/*�����Ч�ڿ�ʼʱ��*/ 
		
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->ExpireTime,sizeof(pICS_482184_N->ExpireTime));
		setValueOfStr(recv_buff,"ExpireTime",tmp_val_str);/*����ʱ��*/
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->BillMode,sizeof(pICS_482184_N->BillMode));
		setValueOfStr(recv_buff,"BillMode",tmp_val_str);/*�û���������*/ 
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->DestAttr,sizeof(pICS_482184_N->DestAttr));
		setValueOfStr(recv_buff,"DestAttr",tmp_val_str);/*�û�����*/ 
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->DqCode,sizeof(pICS_482184_N->DqCode));
		setValueOfStr(recv_buff,"DqCode",tmp_val_str);/*�������������*/ 

		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->objectHome,sizeof(pICS_482184_N->objectHome));
		setValueOfStr(recv_buff,"objectHome",tmp_val_str);/*�������ƽ̨*/ 
		
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_482184_N->TCusID,sizeof(pICS_482184_N->TCusID));
		setValueOfStr(recv_buff,"CTSQ",tmp_val_str);/*����ֵ����*/ 
		
  }
  else
  {	/*ʧ��*/
		memcpy(pICS_482184_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482184_E));
		strcpy(tmp_val_str,"<font color=ff0000>--->����ʧ��</font><br>");
		strcat(display_str,tmp_val_str);
  	
  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
		sprintf(tmp_val_str,"--->ʧ��ԭ��[%s] ",tmp_val_str2);
		strcat(display_str,tmp_val_str);
  	
  	memset(tmp_val_str2,0,sizeof(tmp_val_str2));
		memcpy(tmp_val_str2,pICS_482184_E->RspMsg,sizeof(pICS_482184_E->RspMsg));
		sprintf(tmp_val_str,"[%s] <br>",tmp_val_str2);
		strcat(display_str,tmp_val_str);
  	
  	setValueOfStr(recv_buff,"display_zone",display_str);
  	
		memset(tmp_val_str,'\0',sizeof(tmp_val_str));
		memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
 		setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/
  }
flog( STEP_LEVEL,"**482184 ����[%s]******************************",recv_buff);

  return 0;
}
