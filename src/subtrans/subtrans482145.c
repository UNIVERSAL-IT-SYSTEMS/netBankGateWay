/****************************************
 *������:trans482145.c
 *��  ��:������ʷ��¼��ѯ
 *��  ��:2007.05.21
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


int ics_proc_482145(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          ics_send_buff-���̨ͨѶ�ķ��ʹ�;
          ics_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int			i;	
  int 			len;
  int                   ret;
  int			offset;
  int			i_biz_id;

  ICS_DEF_TIA		*pICS_TIA;
  ICS_DEF_TOA		*pICS_TOA;
  ICS_DEF_482145_I	*pICS_482145_I;
  ICS_DEF_482145_N	*pICS_482145_N;
  ICS_DEF_482145_E	*pICS_482145_E;

  char			ics_send_buff[LEN_ICS_PROC_BUF];
  char			ics_recv_buff[LEN_ICS_PROC_BUF];
  char			ics_482145i_buff[34];
  char			ics_482145n_buff[167];
  char			ics_482145e_buff[71];
  char			ics_tia_buff[171];
  char			ics_toa_buff[114];
  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			tmp_val_str3[LEN_TMP_VAL_STR];
  char 			display_str[LEN_ICS_PROC_BUF];
  char                  tmpvalue[40]; 	/*���ϴ�������ȡ�õ�ĳ��ֵ*/
  char			sLen[8];
  char			sLeft[14];
  char			sRight[3];
  char			ics_port[6];
  
  char      sJflx[3];
  char      sRecNum[32];
  int				iRecNum;
  char			sTCusID[30+1];
  char			sRsFld3[60+1];
  char			sTxnAmt[15+1];
  char 			sTckNo[11+1];
  char			sFtxntm[30+1];
  char			tmp_buf[LEN_ICS_PROC_BUF];

  FILE 			*fp;

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */

        pICS_482145_I=(ICS_DEF_482145_I *)ics_482145i_buff;
        pICS_482145_N=(ICS_DEF_482145_N *)ics_482145n_buff;
        pICS_482145_E=(ICS_DEF_482145_E *)ics_482145e_buff;
        pICS_TIA=(ICS_DEF_TIA *)ics_tia_buff;
        pICS_TOA=(ICS_DEF_TOA *)ics_toa_buff;

	memset(ics_send_buff,'\0',sizeof(ics_send_buff));
	memset(ics_recv_buff,'\0',sizeof(ics_recv_buff));
	memset(ics_482145i_buff,'\0',sizeof(ics_482145i_buff));
	memset(ics_482145n_buff,'\0',sizeof(ics_482145n_buff));
	memset(ics_482145e_buff,'\0',sizeof(ics_482145e_buff));
	memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
	memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
        memset(tmp_val_str3,'\0',sizeof(tmp_val_str3));
        memset(display_str,'\0',sizeof(display_str));
        memset(tmpvalue,'\0',sizeof(tmpvalue));
  
  memset(tmp_buf,'\0',sizeof(tmp_buf));
  memset(sJflx,'\0',sizeof(sJflx));
  memset(sRecNum,'\0',sizeof(sRecNum));/**/
  memset(sTCusID,'\0',sizeof(sTCusID));/*�ɷѺ���*/
  memset(sRsFld3,'\0',sizeof(sRsFld3));/*�ͻ�����*/
  memset(sTckNo,'\0',sizeof(sTckNo));/*�����ˮ��*/
	memset(sTxnAmt,'\0',sizeof(sTxnAmt));/*���*/
flog( STEP_LEVEL,"--482145 ����[%s]-------------------------------",send_buff);

 /* ע�⣺���������ð��սṹ�����Ⱥ�˳������������ݸ������� */
  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");   /* CICS���״��� */
  strcpy(pICS_TIA->TTxnCd,"482145");
  strcpy(pICS_TIA->FeCod,"482145");
  strcpy(pICS_TIA->TrmNo,"DVID");
  strcpy(pICS_TIA->TxnSrc,"T0001");   
  strcpy(pICS_TIA->NodTrc,"200704100044191");
  strcpy(pICS_TIA->TlrId,"AFAM020");
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
  strcpy(pICS_TIA->NodNo,"444086");
  strcpy(pICS_TIA->OprLvl," ");
  strcpy(pICS_TIA->TrmVer,"v0000001");
  strcpy(pICS_TIA->OutSys," ");
  strcpy(pICS_TIA->Fil,"  ");

  /* STEP1-3: ���ϴ����еĹ̶�Ԫ��ֵ*/
  getValueOfStr(send_buff,"CDNO",tmpvalue); /*����*/
  strcpy(pICS_482145_I->ActNo,tmpvalue);
  
  getValueOfStr(send_buff,"Jflx",tmpvalue); /*ҵ������*/
  strncpy(sJflx,tmpvalue,2);
  flog( STEP_LEVEL,"**sJflx [%s]******************************",sJflx);
  strncpy(pICS_482145_I->Jflx,tmpvalue, 2);

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

  len=sizeof(ICS_DEF_482145_I);
  for(i=0;i<len;i++)
  {
  	if(ics_482145i_buff[i]==0)
   		ics_482145i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482145i_buff,len);
  offset=offset+sizeof(ICS_DEF_482145_I);

  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';  

  /*----------------------STEP2:���м�ҵ��ǰ�û�ͨѶ-----------------*/
   /* ��ICSͨѶ */
   memset(ics_port,'\0',sizeof(ics_port));

   ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_TRANS", ics_port);
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

	memcpy(pICS_482145_N,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482145_N));
	/*memcpy(sRecNum,pICS_482145_N->RecNum,sizeof(pICS_482145_N->RecNum));
	trim(sRecNum);
	*/
	iRecNum=atoi(trim(pICS_482145_N->RecNum));
	memcpy(tmp_buf,ics_recv_buff+sizeof(ICS_DEF_TOA)+sizeof(ICS_DEF_482145_N),strlen(ics_recv_buff)-sizeof(ICS_DEF_TOA)-sizeof(ICS_DEF_482145_N));

    if( memcmp(pICS_482145_I->Jflx,"02",2 ) == 0 || memcpy(pICS_482145_I->Jflx,"03", 2) == 0)
  	{
  		  sprintf(tmp_val_str,"%s","<table><tr><td>�ɷѺ���</td><td>�ɷѽ��</td><td>�����ˮ��</td><td>����ʱ��</td></tr>");
			  strcat(display_str,tmp_val_str);
			  
			  for(i=0;i<iRecNum;i++)
			  {
			  	memset(sTCusID,'\0',sizeof(sTCusID));/*�ɷѺ���*/
				  memset(sRsFld3,'\0',sizeof(sRsFld3));/*�ͻ�����*/
				  memset(sTckNo,'\0',sizeof(sTckNo));/*�����ˮ��*/
					memset(sTxnAmt,'\0',sizeof(sTxnAmt));/*���*/
					memset(sFtxntm,'\0',sizeof(sFtxntm));
					
			  	memcpy(sTCusID,tmp_buf+7+i*157,30);
			  	trim(sTCusID);
			  	sprintf(tmp_val_str,"<tr><td>%s</td><td>",sTCusID);
			  	strcat(display_str,tmp_val_str);
			  	/*
			  	memcpy(sRsFld3,tmp_buf+37+i*157,60);
			  	trim(sRsFld3);
			  	sprintf(tmp_val_str,"%s</td><td>",sRsFld3);
			  	strcat(display_str,tmp_val_str);
			  	*/
			  	memcpy(sTxnAmt,tmp_buf+97+i*157,15);
			  	trim(sTxnAmt);
			  	memset(sLeft,0,sizeof(sLeft));
			    memset(sRight,0,sizeof(sRight));
			    memcpy(sLeft,sTxnAmt,13);
			    memcpy(sRight,sTxnAmt+13,2);
			    sprintf(tmp_val_str,"%d.%s</td><td>",atoi(sLeft),sRight);      
			  	strcat(display_str,tmp_val_str);
			  	
			  	memcpy(sTckNo,tmp_buf+112+i*157,11);
			  	trim(sTckNo);
			  	sprintf(tmp_val_str,"%s</td><td>",sTckNo);
			  	strcat(display_str,tmp_val_str); 
			  	
			  	memcpy(sFtxntm,tmp_buf+127+i*157,30);
			  	trim(sFtxntm);
			  	sprintf(tmp_val_str,"%s</td><td></tr>",sFtxntm);
			  	strcat(display_str,tmp_val_str); 	
			  }
  	}
  	else
  		{
				  sprintf(tmp_val_str,"%s","<table><tr><td>�ɷѺ���</td><td>�ͻ�����</td><td>�ɷѽ��</td><td>�����ˮ��</td><td>����ʱ��</td></tr>");
				  strcat(display_str,tmp_val_str);
				  
				  for(i=0;i<iRecNum;i++)
				  {
				  	memset(sTCusID,'\0',sizeof(sTCusID));/*�ɷѺ���*/
					  memset(sRsFld3,'\0',sizeof(sRsFld3));/*�ͻ�����*/
					  memset(sTckNo,'\0',sizeof(sTckNo));/*�����ˮ��*/
						memset(sTxnAmt,'\0',sizeof(sTxnAmt));/*���*/
						memset(sFtxntm,'\0',sizeof(sFtxntm));
						
				  	memcpy(sTCusID,tmp_buf+7+i*157,30);
				  	trim(sTCusID);
				  	sprintf(tmp_val_str,"<tr><td>%s</td><td>",sTCusID);
				  	strcat(display_str,tmp_val_str);
				  	
				  	memcpy(sRsFld3,tmp_buf+37+i*157,60);
				  	trim(sRsFld3);
				  	sprintf(tmp_val_str,"%s</td><td>",sRsFld3);
				  	strcat(display_str,tmp_val_str);
				  	
				  	memcpy(sTxnAmt,tmp_buf+97+i*157,15);
				  	trim(sTxnAmt);
				  	memset(sLeft,0,sizeof(sLeft));
				    memset(sRight,0,sizeof(sRight));
				    memcpy(sLeft,sTxnAmt,13);
				    memcpy(sRight,sTxnAmt+13,2);
				    sprintf(tmp_val_str,"%d.%s</td><td>",atoi(sLeft),sRight);      
				  	strcat(display_str,tmp_val_str);
				  	
				  	memcpy(sTckNo,tmp_buf+112+i*157,11);
				  	trim(sTckNo);
				  	sprintf(tmp_val_str,"%s</td><td>",sTckNo);
				  	strcat(display_str,tmp_val_str); 
				  	
				  	memcpy(sFtxntm,tmp_buf+127+i*157,30);
				  	trim(sFtxntm);
				  	sprintf(tmp_val_str,"%s</td><td></tr>",sFtxntm);
				  	strcat(display_str,tmp_val_str); 	
				  }  
			}   
	/*strcat(display_str,tmp_buf);*/
	sprintf(tmp_val_str,"%s","</table>");
  strcat(display_str,tmp_val_str);

	/* ����setValueOf������� */
    	setValueOfStr(recv_buff,"display_zone",display_str);
    	
		setValueOfStr(recv_buff, "MGID", "111111");/*������*/
		
 /* STEP3-2 ����ҳ������Ҫ��: ������д���ֶΣ�������ҳ����Ϊ����input��Ҫ�� */
 /* ע�⣬1.�������ò�����˳���������ݿ��в�����˳��һ�£�����س��� 
          2.�������ֶ�������ע����WEB��һ��*/ 
  }
  else
  {	/*ʧ��*/
	memcpy(pICS_482145_E,ics_recv_buff+sizeof(ICS_DEF_TOA),sizeof(ICS_DEF_482145_E));
	strcpy(tmp_val_str,"<font color=ff0000>--->�޴˽������ͽ��׼�¼</font><br>");
	strcat(display_str,tmp_val_str);

  /*      memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
	sprintf(tmp_val_str,"--->ʧ��ԭ��[%s] ",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pICS_482145_E->RspMsg,sizeof(pICS_482145_E->RspMsg));
	sprintf(tmp_val_str,"[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);
  */
    	setValueOfStr(recv_buff,"display_zone",display_str);

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
 	setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/
  }
flog( STEP_LEVEL,"**482145 ����[%s]******************************",recv_buff);

  return 0;
}

