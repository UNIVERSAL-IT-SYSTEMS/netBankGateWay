/****************************************
 *������:subtrans482135.c
 *��  ��:����ͨ--��ƱԤ���ɷ�
 *��  ��:2009-2-23
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


int ics_proc_482135(char *send_buff,char *recv_buff)
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
  ICS_DEF_482135_I  *pICS_482135_I;
  ICS_DEF_482135_N  *pICS_482135_N;
  ICS_DEF_482135_E  *pICS_482135_E;

  char      ics_send_buff[LEN_ICS_PROC_BUF];
  char      ics_recv_buff[LEN_ICS_PROC_BUF];
  char      ics_482135i_buff[556];
  char      ics_482135n_buff[257];
  char      ics_482135e_buff[71];
  char      ics_tia_buff[171];
  char      ics_toa_buff[114];
  char      tmp_val_str[LEN_TMP_VAL_STR];
  char      tmp_val_str2[LEN_TMP_VAL_STR];
  char      display_str[LEN_ICS_PROC_BUF];
  char      display_log_str[LEN_ICS_PROC_BUF];
  char      tmpvalue[256];  /*���ϴ�������ȡ�õ�ĳ��ֵ*/

  char			s_CDNO[LEN_CDNO]; /* ���� */
  char			s_PSWD[21]; /* ���� */

  char      sLen[8];
  char      sLeft[14];
  char      sRight[3];
  char      sTranNo[16];
  char      sTranDate[11];
  char      sTellerNo[8];
  char      sErrMsg[64];
  char      ics_port[6];

	char  Product_Code[13]; 			  /*��Ʊ����*/
	char  Retail_Price1[15]; 			  /*���м�*/
	char  E_Discount_Price1[15]; 	  /*�����Żݼ�*/
	char  Reserve_Amoun[5];         /*Ԥ����Ʒ����*/
	char  Mobile_Phone_Number[12];  /*�ֻ�����*/
	char  Begin_Date[9];            /*ʹ������*/
	char  Message_Type[3];          /*��������*/
	char  Amount1[15];              /*�ܽ��*/
	char  Scence_Code[13];         	/*��������*/
	char  Scence_Name[61];         	/*��������*/
	char  Product_Name[51];         /*��Ʊ����*/
  char  Remark1[161];             /*��ע*/
	char  Valid_Days[4];            /*��Ч����*/

	char  TCUSNM[13];               /*�������*/
	char  ThdKey[19];               /*���н�����ˮ��*/
	char  TXNAMT[15];               /**/
	char  Return_Code[4];           /*������*/
	char  PB_Return_Code_Msg[31];   /*��������Ϣ*/
	char  TckNo[12];                /*�����ˮ*/
	char 	sTxnCnl[32];

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
  memset(ics_482135i_buff,'\0',sizeof(ics_482135i_buff));
  memset(ics_482135n_buff,'\0',sizeof(ics_482135n_buff));
  memset(ics_482135e_buff,'\0',sizeof(ics_482135e_buff));
  memset(ics_tia_buff,'\0',sizeof(ics_tia_buff));
  memset(ics_toa_buff,'\0',sizeof(ics_toa_buff));

  pICS_482135_I=(ICS_DEF_482135_I *)ics_482135i_buff;
  pICS_482135_N=(ICS_DEF_482135_N *)ics_482135n_buff;
  pICS_482135_E=(ICS_DEF_482135_E *)ics_482135e_buff;
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
	memset(sTxnCnl, '\0', sizeof(sTxnCnl));

flog( STEP_LEVEL,"--482135 ����[%s]------------------------------",send_buff);

  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pICS_TIA->CCSCod,"TLU6");
  strcpy(pICS_TIA->TTxnCd,"482135");
  strcpy(pICS_TIA->FeCod,"482135");
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

  strcpy(pICS_482135_I->ActTyp,"4");	/*�ʺ�����*/

	memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"CDNO", tmpvalue); /*�����ʺ�*/
  trim(tmpvalue);
  strcpy(s_CDNO, tmpvalue);
  strcpy(pICS_482135_I->ActNo, tmpvalue);

	memset(tmpvalue, 0, sizeof(tmpvalue));
  getValueOfStr(send_buff,"PSWD",tmpvalue); /*����*/
  trim(tmpvalue);
  strcpy(s_PSWD,tmpvalue);
  strcpy(pICS_482135_I->PinBlk,tmpvalue);

	memset(Product_Code, 0, sizeof(Product_Code));
	memset(Retail_Price1, 0, sizeof(Retail_Price1));
	memset(E_Discount_Price1, 0, sizeof(E_Discount_Price1));
	memset(Reserve_Amoun, 0, sizeof(Reserve_Amoun));
	memset(Mobile_Phone_Number, 0, sizeof(Mobile_Phone_Number));
	memset(Begin_Date, 0, sizeof(Begin_Date));
	memset(Message_Type, 0, sizeof(Message_Type));
	memset(Amount1, 0, sizeof(Amount1));
	memset(Scence_Code, 0, sizeof(Scence_Code));
	memset(Scence_Name, 0, sizeof(Scence_Name));
	memset(Product_Name, 0, sizeof(Product_Name));
	memset(Remark1, 0, sizeof(Remark1));
	memset(Valid_Days, 0, sizeof(Valid_Days));

	getValueOfStr(send_buff,"Product_Code", Product_Code);

	memset(tmpvalue, 0, sizeof(tmpvalue));
	getValueOfStr(send_buff,"Retail_Price1", tmpvalue);
	sprintf(Retail_Price1, "%14.2f", atof(tmpvalue));

	memset(tmpvalue, 0, sizeof(tmpvalue));
	getValueOfStr(send_buff,"E_Discount_Price1", tmpvalue);
	sprintf(E_Discount_Price1, "%014.2f", atof(tmpvalue));

	getValueOfStr(send_buff,"Reserve_Amoun", Reserve_Amoun);
	getValueOfStr(send_buff,"Mobile_Phone_Number", Mobile_Phone_Number);

	memset(tmpvalue, 0, sizeof(tmpvalue));
	getValueOfStr(send_buff,"Begin_Date", tmpvalue);
	strncpy(Begin_Date, tmpvalue, 4);
	if(strlen(tmpvalue) == 10){
		strncpy(Begin_Date+4, tmpvalue+5, 2);
		strncpy(Begin_Date+6, tmpvalue+8, 2);
	}else{
		if(tmpvalue[6] == '-'){
			Begin_Date[4] = '0';
			Begin_Date[5] = tmpvalue[5];
			if(strlen(tmpvalue) == 9){
				strncpy(Begin_Date+6, tmpvalue+7, 2);
			}else{
				Begin_Date[6] = '0';
				Begin_Date[7] = tmpvalue[7];			
			}
		}else{
			strncpy(Begin_Date+4, tmpvalue+5, 2);
		}
	  if(tmpvalue[7] == '-'){
			Begin_Date[6] = '0';
			Begin_Date[7] = tmpvalue[8];
	  }
	}
	getValueOfStr(send_buff,"Message_Type", Message_Type);
	
	memset(tmpvalue, 0, sizeof(tmpvalue));
	getValueOfStr(send_buff,"Amount1", tmpvalue);
	sprintf(Amount1, "%014.2f", atof(tmpvalue));

	getValueOfStr(send_buff,"Scence_Code", Scence_Code);
	getValueOfStr(send_buff,"Scence_Name", Scence_Name);
	getValueOfStr(send_buff,"Product_Name", Product_Name);
	getValueOfStr(send_buff,"Remark1", Remark1);
	getValueOfStr(send_buff,"Valid_Days", Valid_Days);

	memcpy(pICS_482135_I->Product_Code, Product_Code, 12);
	memcpy(pICS_482135_I->Retail_Price1, Retail_Price1, 14);
	memcpy(pICS_482135_I->E_Discount_Price1, E_Discount_Price1, 14);
	memcpy(pICS_482135_I->Reserve_Amoun, Reserve_Amoun, 4);
	memcpy(pICS_482135_I->Mobile_Phone_Number, Mobile_Phone_Number, 11);
	memcpy(pICS_482135_I->Begin_Date, Begin_Date, 8);
	memcpy(pICS_482135_I->Message_Type, Message_Type, 2);
	memcpy(pICS_482135_I->Amount1, Amount1, 14);
	memcpy(pICS_482135_I->Scence_Code, Scence_Code, 12);
	memcpy(pICS_482135_I->Scence_Name, Scence_Name, 60);
	memcpy(pICS_482135_I->Product_Name, Product_Name, 50);
	memcpy(pICS_482135_I->Remark1, Remark1, 160);
	memcpy(pICS_482135_I->Valid_Days, Valid_Days, 3);

  flog( STEP_LEVEL,"----У������----\n");
  /* У������ modify by ylw for ��ؿ� 20120211
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

  flog( STEP_LEVEL,"----����ICS-----\n");
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

  len=sizeof(ICS_DEF_482135_I);
  for(i=0;i<len;i++)
  {
    if(ics_482135i_buff[i]==0)
      ics_482135i_buff[i]=' ';
  }
  memcpy(ics_send_buff+offset,ics_482135i_buff,len);
  offset=offset+sizeof(ICS_DEF_482135_I);

  /*����ICS���8λ���ĳ�����ͷ*/
  memcpy(sLen,'\0',8);
  sprintf(sLen,"%08d",offset-8);
  memcpy(ics_send_buff,sLen,8);

  ics_send_buff[offset] = '\0';

  /* ��ICSͨѶ */
  memset(ics_port,'\0',sizeof(ics_port));

  ret = get_config_value(CONFIG_FILE_NAME, "ICS_PORT_YLT", ics_port);
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

    memcpy(ics_482135n_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482135n_buff));

		memset(TCUSNM, 0, sizeof(TCUSNM));
		memset(ThdKey, 0, sizeof(ThdKey));
		memset(TXNAMT, 0, sizeof(TXNAMT));
		memset(Return_Code, 0, sizeof(Return_Code));
		memset(PB_Return_Code_Msg, 0, sizeof(PB_Return_Code_Msg));
		memset(TckNo, 0, sizeof(TckNo));

		memcpy(TCUSNM, pICS_482135_N->TCUSNM, 12);
		memcpy(ThdKey, pICS_482135_N->ThdKey, 18);
		memcpy(TXNAMT, pICS_482135_N->TXNAMT, 14);
		memcpy(Return_Code, pICS_482135_N->Return_Code, 3);
		memcpy(PB_Return_Code_Msg, pICS_482135_N->PB_Return_Code_Msg, 30);
		memcpy(TckNo, pICS_482135_N->TckNo, 11);

	  trim(TCUSNM);
	  trim(ThdKey);
	  trim(TXNAMT);
	  trim(Return_Code);
	  trim(PB_Return_Code_Msg);
	  trim(TckNo);
    setValueOfStr(recv_buff,"TCUSNM",TCUSNM);
    setValueOfStr(recv_buff,"ThdKey",ThdKey);
    setValueOfStr(recv_buff,"TXNAMT",TXNAMT);
    setValueOfStr(recv_buff,"Return_Code",Return_Code);
    setValueOfStr(recv_buff,"PB_Return_Code_Msg",PB_Return_Code_Msg);
    setValueOfStr(recv_buff,"TckNo",TckNo);

    setValueOfStr(recv_buff,"display_zone",display_str);

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/

  }
  else
  { /*ʧ��*/
    memcpy(ics_482135e_buff,ics_recv_buff+sizeof(ics_toa_buff),sizeof(ics_482135e_buff));

    if( memcmp( pICS_TOA->RspCod, "PC5012", 6 ) == 0 )
        strcpy( sErrMsg, "���벻��" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5012", 6 ) == 0 )
        strcpy( sErrMsg, "���벻��" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5100", 6 ) == 0 )
        strcpy( sErrMsg, "��ǿ���������" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PC3254", 6 ) == 0 )
        strcpy( sErrMsg, "�˽��ײ�����͸֧" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "PD5044", 6 ) == 0 )
       strcpy( sErrMsg, "������������������" ) ;
    else
    if( memcmp( pICS_TOA->RspCod, "TC2051", 6 ) == 0 )
        strcpy( sErrMsg, "����У���" ) ;
    else
        /*memcpy( sErrMsg, pICS_TOA->RspCod, 6 ) ;*/
        strcpy(sErrMsg, pICS_482135_E->RspMsg);

		trim(sErrMsg);

    strcpy(tmp_val_str,"<font color=ff0000><b>--->����ʧ�ܣ�<br>--->�������ʣ��뼰ʱ�뿪��������ϵ��</b></font><br>");
    strcat(display_str,tmp_val_str);

    sprintf(tmp_val_str,"--->ʧ��ԭ��[%s] <br>",sErrMsg);
    strcat(display_str,tmp_val_str);

    setValueOfStr(recv_buff,"display_zone",display_str);

    memset(tmp_val_str,'\0',sizeof(tmp_val_str));
    memcpy(tmp_val_str,pICS_TOA->RspCod,sizeof(pICS_TOA->RspCod));
    setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/
    setValueOfStr(recv_buff,"PB_Return_Code_Msg",sErrMsg);
  }

flog( STEP_LEVEL,"**482135 ����[%s]******************************",recv_buff);

  return 0;
}
