/****************************************
 *������:trans8082.c
 *��  ��:�麣�н�ίֱ����Сѧѧ�ѽ���
 *��  ��:2003.11.21
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


int mid_proc_8082(char *send_buff,char *recv_buff)
{
  /*˵����send_buff-�ϴ����ģ�
          recv_buff-�´�����;
          mid_send_buff-���̨ͨѶ�ķ��ʹ�;
          mid_recv_buff-���̨ͨѶ�Ľ��մ�;
 */

  int 			len,i;	
  int                   ret,outlen,en_ret;

  MID_DEF_8082_I	*pMID_8082_I;
  MID_DEF_8082_O	*pMID_8082_O;
  char	mgid[5];

  char    mid_send_buff[LEN_MID_PROC_BUF];
  char    mid_recv_buff[LEN_MID_PROC_BUF];
  FILE 			*fp;

  char 			tmp_val_str[LEN_TMP_VAL_STR];
  char 			tmp_val_str2[LEN_TMP_VAL_STR];
  char 			display_str[LEN_MID_PROC_BUF];
  char 			display_log_str[LEN_MID_PROC_BUF];

  char                  tmpvalue[256]; 	/*���ϴ�������ȡ�õ�ĳ��ֵ*/

  char s_CDNO[LEN_CDNO]; 		/* ̫ƽ�󿨺� */
  char s_PSWD[LEN_PSWD]; 		/* ̫ƽ������ */

  void *pComplibhandle; /* Handle to shared lib file */ 
  int (*pCompfunchandle)(); /* Pointer to loaded routine */ 

  /*-------------------STEP1:ͨѶǰ����-����ϴ���--------------------*/

  /* STEP1-1:����ṹ�ͱ��� */
	memset(mid_send_buff,'\0',sizeof(mid_send_buff));
	memset(mid_recv_buff,'\0',sizeof(mid_recv_buff));
	memset(mgid,'\0',sizeof(mgid));
        pMID_8082_I=(MID_DEF_8082_I *)mid_send_buff;
        pMID_8082_O=(MID_DEF_8082_O *)mid_recv_buff;

        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memset(tmp_val_str2,'\0',sizeof(tmp_val_str2));
        memset(display_str,'\0',sizeof(display_str));
        memset(display_log_str,'\0',sizeof(display_log_str));
        memset(tmpvalue,'\0',sizeof(tmpvalue));
        memset(s_CDNO,'\0',sizeof(s_CDNO));
        memset(s_PSWD,'\0',sizeof(s_PSWD));

  /* ע�⣺���������ð��սṹ�����Ⱥ�˳������������ݸ������� */
  /* STEP1-2:���ϴ����Ĺ̶�ͷ */
  strcpy(pMID_8082_I->TRCD,"8082");   /* ���״��� */
  strcpy(pMID_8082_I->RGCD,AreaCode); /* �������� */
  strcpy(pMID_8082_I->OGCD,ORGCode);  /* �������� */
  strcpy(pMID_8082_I->TLNO,AUTLCode); /* �������� */
  strcpy(pMID_8082_I->AUTL,AUTLCode); /* ��Ȩ��Ա */        
  strcpy(pMID_8082_I->TTYN,TTYNCode); /* �����ն˺�*/

  /* STEP1-3: ���ϴ����еĹ̶�Ԫ��ֵ*/
  strcpy(pMID_8082_I->DLDR,"808201"); /* �м�ҵ������ */
  strcpy(pMID_8082_I->TRMD,OPTPCode); /* ҵ������*/
  strcpy(pMID_8082_I->DLMD,"1"); /* �ɷѷ�ʽ ���ɷ� 1 */

  /* �������������˿ɲ������ʵ���� */
  strcpy(pMID_8082_I->NAME,"qqqqqqqqqqqqqqqqqqqq"); /*�ͻ����� */
  /*strcpy(pMID_8082_I->IDTP,"q"); ֤������*/
  strcpy(pMID_8082_I->IDNO,"qqqqqqqqqqqqqqqqqqqq"); /*���֤���� */

  /* STEP1-4: ��WEB�ϴ������л������ֵ-��getValueOf����*/
  getValueOfStr(send_buff,"CDNO",tmpvalue);/*����*/
  strcpy(s_CDNO,tmpvalue);
  strcpy(pMID_8082_I->CDNO,tmpvalue);

  /* �������������˿ɲ������ʵ���� */
  strcpy(pMID_8082_I->ACNO,"qqqqqqqqqqqqqqqqqqqq"); /*�ʺ�*/
  strcpy(pMID_8082_I->ACID,"qqqqqqqqqqqqqqqqqqqq"); /* �����ʺ� */

  strcpy(pMID_8082_I->WDMD,"0"); /*ȡ�ʽ ƾ����ȡ�� 0 */

  strcpy(pMID_8082_I->TRPS,"qqqqqq"); /*���������� �����˿ɲ������ʵ���� */

  getValueOfStr(send_buff,"TPNB",tmpvalue); /*ѧ������*/
  strcpy(pMID_8082_I->TPNB,tmpvalue);


  /* ����ACNM�з�ѧ������ �Ժ�̨���ô� �����ڷ��ؽ��׳ɹ�ʱ����ҳ��ʾ*/
  getValueOfStr(send_buff,"bb",tmpvalue); 
  strcpy(pMID_8082_I->ACNM,tmpvalue);

  getValueOfStr(send_buff,"jyje",tmpvalue); /*�ɷ��ܽ��*/
  strcpy(pMID_8082_I->AMLM,tmpvalue);

  /*�������tmpvalue->s_PSWD begin ������ ���Գɹ�*/
  getValueOfStr(send_buff,"PSWD",tmpvalue);
  flog(INFO_LEVEL,"����ǰȡPSWD=[%s]�ɹ�",tmpvalue);
  if((pComplibhandle = dlopen("libencrytrps.so", RTLD_LAZY)) == NULL)
  {
  	flog(INFO_LEVEL,"%s,%s,%s,%s","ִ�ж�̬ʧ��", dlerror(), "libencrytrps.so","encry_trps");
  	return -1;
  }

  if((pCompfunchandle=(int (*)())dlsym(pComplibhandle, "encry_trps"))== NULL)
  {
        dlclose(pComplibhandle);
        flog(INFO_LEVEL,"%s,%s,%s,%s","ִ�ж�̬ʧ��",dlerror(), "libencrytrps.so","encry_trps");
        return -1;
   }

  if((en_ret=(*pCompfunchandle)("8082",AreaCode,ORGCode,AUTLCode,s_CDNO,tmpvalue,s_PSWD)) != 0 )
  {
        dlclose(pComplibhandle);
        flog(INFO_LEVEL,"%s,%s,%s,%s,%d","ִ�ж�̬ʧ��",dlerror(), "libencrytrps.so","encry_trps",en_ret);
        return -1;
  }
  strcpy(pMID_8082_I->DESP,s_PSWD);
  flog(INFO_LEVEL,"%s,%s,%d","ִ�ж�̬�ɹ�", "libencrytrps.so",en_ret);

  if ( dlclose(pComplibhandle))
  {
        flog(INFO_LEVEL,"%s,%s,%s,%s","ִ�ж�̬ʧ��",dlerror(),"libencrytrps.so","encry_trps");
        return -1;
  }

  /*20040831 wusf midify ����һЩ����Ŀ�����������ܺ��̨�޷���������,�ؼ����� �����������⣬������������������ĵ����һ����������ӿո� */
  /*���ļӿո�start*/
  /*���ļӿո�end*/

  /*�������tmpvalue->s_PSWD ������ end*/

    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"�麣�н�ίֱ����Сѧѧ�ѽ���\n--->STEP1:ͨѶǰ����-����ϴ���-->send_buff=[%s]\n",send_buff);
    fclose(fp);

  /*STEP1-4:�ѽṹ�еĽ������滻Ϊ�ո��ϴ���ĩβ�ӽ�����.*/
  len=sizeof(MID_DEF_8082_I);
  for(i=0;i<len;i++)
  {
  	if(mid_send_buff[i]==0)
   		mid_send_buff[i]=' ';
  }
  mid_send_buff[len] = '\0';  


  /*----------------------STEP2:���м�ҵ��ǰ�û�ͨѶ-----------------*/
    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"--->STEP2:���м�ҵ��ǰ�û�ͨѶmid_send_buff=[%s]\n",mid_send_buff);
    fclose(fp);
  
 /* ������м�ҵ��ƽ̨ͨѶ */
    ret=clienths( mid_send_buff,mid_recv_buff );
	if(ret != RETURN_OK)
		return(-1);
    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"--->STEP2:���м�ҵ��ǰ�û�ͨѶmid_recv_buff=[%s]\n",mid_recv_buff);
    fclose(fp);


  /*--------------------STEP3:ͨѶ����:��ɻش�����------------------*/

  if(memcmp(pMID_8082_O->MGID,TRANSOK,sizeof(pMID_8082_O->MGID))==0)/*�ɹ�*/
  {
  /* STEP3-1����ҳ����ʾҪ��: ��������д���ֶΣ�������ҳ������ʾ���ֶ� */
  /* ע�⣬<br>��ҳ����ʾ�Ļ��з��� */

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"ѧ�����룺[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->ACNM,sizeof(pMID_8082_I->ACNM));
	sprintf(tmp_val_str,"ѧ��������[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"���ѽ�[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);
        strcat(display_str,"<b>���ѳɹ�!</b><br>");

        /* STEP3-1-1 ����־�м�¼�й����ݱ��� begin*/
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"ѧ�����룺[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_O->TRDT,sizeof(pMID_8082_O->TRDT));
	sprintf(tmp_val_str,"�������ڣ�[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_O->TLCS,sizeof(pMID_8082_O->TLCS));
	sprintf(tmp_val_str,"��Ա��ˮ��[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"���ѽ�[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        fp=fopen("/tmp/8082.log","a");
    	fprintf(fp,"STEP3:ͨѶ����-->���ѳɹ�! {%s}\n*********************************\n",display_log_str);
    	fclose(fp);
        /* STEP3-1-1 ����־�м�¼�й����ݱ��� end*/

	/* ����setValueOf������� */
    	setValueOfStr(recv_buff,"display_zone",display_str);

  /* STEP3-2 ����ҳ������Ҫ��: ������д���ֶΣ�������ҳ����Ϊ����input��Ҫ�� */
 /* ע�⣬�������ò�����˳���������ݿ��в�����˳��һ�£�����س��� */
        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memcpy(tmp_val_str,pMID_8082_O->MGID,sizeof(pMID_8082_O->MGID));
        setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/


  } else {	/*ʧ��*/
	strcpy(tmp_val_str,"<font color=ff0000><b>--->����ʧ�ܣ�<br>--->�������ʣ��뼰ʱ�뿪��������ϵ��</b></font><br>");
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"--->ʧ�ܴ��룺[%s] <br>",pMID_8082_O->MGID);
	strcat(display_str,tmp_val_str);

    	setValueOfStr(recv_buff,"display_zone",display_str);
	
        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memcpy(tmp_val_str,pMID_8082_O->MGID,sizeof(pMID_8082_O->MGID));
        setValueOfStr(recv_buff,"MGID",tmp_val_str);/*������*/

       /* ����־�м�¼�й����ݱ��� begin*/
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"ѧ�����룺[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"���ѽ�[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        fp=fopen("/tmp/8082.log","a");
    	fprintf(fp,"STEP3:ͨѶ����-->����ʧ��! ע�����Ƿ��̨�ѿ���,�����м�ҵ��ƽ̨δ���ѽ��ѱ�־��{%s %s}\n*****************************\n",display_str,display_log_str);
    	fclose(fp);
       /* ����־�м�¼�й����ݱ��� end*/

	return 0;

  }
}
