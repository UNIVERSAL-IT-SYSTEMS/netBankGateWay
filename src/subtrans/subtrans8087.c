/****************************************
 *������:trans8087.c
 *��  ��:�麣�н�ίֱ����Сѧѧ�Ѳ�ѯ
 *��  ��:2003.10.25
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


int mid_proc_8087(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          mid_send_buff-���̨ͨѶ�ķ��ʹ�;
          mid_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int 			len,i;	
  int                   ret,outlen;

  MID_DEF_8087_I	*pMID_8087_I;
  MID_DEF_8087_O	*pMID_8087_O;
  char	mgid[5];
  char    mid_send_buff[LEN_MID_PROC_BUF],mid_recv_buff[LEN_MID_PROC_BUF];
  FILE 			*fp;

  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			display_str[LEN_MID_PROC_BUF];

  char                  tmpvalue[40]; 	/*���ϴ�������ȡ�õ�ĳ��ֵ*/
  char                  tmppwd[40]; 	/*���ϴ�������ȡ�õ�����*/

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */
	memset(mid_send_buff,'\0',sizeof(mid_send_buff));
	memset(mid_recv_buff,'\0',sizeof(mid_recv_buff));
	memset(mgid,'\0',sizeof(mgid));
        pMID_8087_I=(MID_DEF_8087_I *)mid_send_buff;
        pMID_8087_O=(MID_DEF_8087_O *)mid_recv_buff;

        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
        memset(display_str,'\0',sizeof(display_str));
        memset(tmpvalue,'\0',sizeof(tmpvalue));
        memset(tmppwd,'\0',sizeof(tmppwd));
  
 /* ע�⣺���������ð��սṹ�����Ⱥ�˳������������ݸ������� */
  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pMID_8087_I->TRCD,"8087");   /* ���״��� */
  strcpy(pMID_8087_I->RGCD,AreaCode); /* �������� */
  strcpy(pMID_8087_I->OGCD,ORGCode);  /* �������� */
  strcpy(pMID_8087_I->TLNO,AUTLCode); /* ��Ա�� */
  strcpy(pMID_8087_I->AUTL,AUTLCode); /* ��Ȩ��Ա */        
  strcpy(pMID_8087_I->TTYN,TTYNCode); /* �����ն˺�*/

  /* STEP1-3: ���ϴ����еĹ̶�Ԫ��ֵ*/
  strcpy(pMID_8087_I->DLDR,"808701"); /* �м�ҵ������ */
  strcpy(pMID_8087_I->TRMD,OPTPCode); /* ҵ������*/

  /* STEP1-4: ���ϴ������л������ֵ-��getValueOf����*/
  getValueOfStr(send_buff,"TPNB",tmpvalue); /* ѧ������ */
  strcpy(pMID_8087_I->TPNB,tmpvalue);
  getValueOfStr(send_buff,"PSWD",tmppwd); /* ѧ������ */

    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"�麣�н�ίֱ����Сѧѧ�Ѳ�ѯ\n--->STEP1:ͨѶǰ����-����ϴ���send_buff=[%s] ѧ������=[%s]\n",send_buff,tmpvalue);
    fclose(fp);

  /*STEP1-4:�ѽṹ�еĽ������滻Ϊ�ո��ϴ���ĩβ�ӽ�����.*/
  len=sizeof(MID_DEF_8087_I);
  for(i=0;i<len;i++)
  {
  	if(mid_send_buff[i]==0)
   		mid_send_buff[i]=' ';
  }
  mid_send_buff[len] = '\0';  

  /*----------------------STEP2:���м�ҵ��ǰ�û�ͨѶ-----------------*/
    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"--->STEP2:���м�ҵ��ǰ�û�ͨѶmid_send_buff=[%s]\n",mid_send_buff);
    fclose(fp);
  
    /* ������м�ҵ��ƽ̨ͨѶ */
    ret=clienths( mid_send_buff,mid_recv_buff );
    if(ret != RETURN_OK)
	return(-1);
    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"--->STEP2:���м�ҵ��ǰ�û�ͨѶmid_recv_buff=[%s]\n***************************************************\n",mid_recv_buff);
    fclose(fp);
  /*--------------------STEP3:ͨѶ����:��ɻش�����------------------*/

  if(memcmp(pMID_8087_O->xym,TRANSOK,sizeof(pMID_8087_O->xym))==0)/*�ɹ�*/
  {
  /* STEP3-1����ҳ����ʾҪ��: ��������д���ֶΣ�������ҳ������ʾ���ֶ� */
  /* ע�⣬<br>��ҳ����ʾ�Ļ��з��� */

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_I->TPNB,sizeof(pMID_8087_I->TPNB));
	sprintf(tmp_val_str,"<b>ѧ�����룺</b>[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bb,sizeof(pMID_8087_O->bb));
	sprintf(tmp_val_str,"ѧ��������[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bm,sizeof(pMID_8087_O->bm));
	sprintf(tmp_val_str,"ѧУ��[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bl,sizeof(pMID_8087_O->bl));
	sprintf(tmp_val_str,"�꼶��[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bxh,sizeof(pMID_8087_O->bxh));
	sprintf(tmp_val_str,"�༶��[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->czdm,sizeof(pMID_8087_O->czdm));
	sprintf(tmp_val_str,"ѧ�ţ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->jyje,sizeof(pMID_8087_O->jyje));
	sprintf(tmp_val_str,"<b>�ɷ��ܽ�</b>[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxgha,sizeof(pMID_8087_O->dxgha));
	sprintf(tmp_val_str,"��ϸ���£�<br>��ͨ��ѧ(��)�ӷѣ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxghb,sizeof(pMID_8087_O->dxghb));
	sprintf(tmp_val_str,"�����ѧ(��)�ӷѣ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf1,sizeof(pMID_8087_O->dxqf1));
	sprintf(tmp_val_str,"ס�޷ѣ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

/*
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf2,sizeof(pMID_8087_O->dxqf2));
	sprintf(tmp_val_str,"��У�ѣ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf3,sizeof(pMID_8087_O->dxqf3));
	sprintf(tmp_val_str,"�������ã�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);
*/

	/* ����setValueOf������� */
    	setValueOfStr(recv_buff,"display_zone",display_str);

  /* STEP3-2 ����ҳ������Ҫ��: ������д���ֶΣ�������ҳ����Ϊ����input��Ҫ�� */
 /* ע�⣬1.�������ò�����˳���������ݿ��в�����˳��һ�£�����س��� 
          2.�������ֶ�������ע����WEB��һ��*/ 
	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->xym,sizeof(pMID_8087_O->xym));
	setValueOfStr(recv_buff,"MGID",tmp_val_str); /*������*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_I->TPNB,sizeof(pMID_8087_I->TPNB));
	setValueOfStr(recv_buff,"TPNB",tmp_val_str);/*ѧ������*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->bb,sizeof(pMID_8087_O->bb));
	setValueOfStr(recv_buff,"bb",tmp_val_str);/* ѧ������ */

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->jyje,sizeof(pMID_8087_O->jyje));
	setValueOfStr(recv_buff,"jyje",tmp_val_str);/*�ɷ��ܽ��*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	setValueOfStr(recv_buff,"passWord",tmppwd);/*���п���������*/ 

  } else {	/*ʧ��*/
	strcpy(tmp_val_str,"<font color=ff0000>--->����ʧ��</font><br>");
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"--->ʧ�ܴ��룺[%s] <br>",pMID_8087_O->xym);
	strcat(display_str,tmp_val_str);

    	setValueOfStr(recv_buff,"display_zone",display_str);

    	fp=fopen("/tmp/8087.log","a");
    	fprintf(fp,"ʧ��!������ҳ��ʾ��ϢΪ[%s]\n***************************************************\n",display_str);
    	fclose(fp);

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->xym,sizeof(pMID_8087_O->xym));
 	setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/


	return 0;

  }
}
