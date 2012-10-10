/****************************************
 *程序名:trans8087.c
 *功  能:珠海市教委直属中小学学费查询
 *日  期:2003.10.25
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
  /*说明：send_buff-上传报文；
          recv_buff-下传报文;
          mid_send_buff-与后台通讯的发送串;
          mid_recv_buff-与后台通讯的接收串;
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

  char                  tmpvalue[40]; 	/*从上传报文中取得的某项值*/
  char                  tmppwd[40]; 	/*从上传报文中取得的密码*/

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */
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
  
 /* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
  /* STEP1-2:填上传串的固定头 */
  strcpy(pMID_8087_I->TRCD,"8087");   /* 交易代码 */
  strcpy(pMID_8087_I->RGCD,AreaCode); /* 地区代号 */
  strcpy(pMID_8087_I->OGCD,ORGCode);  /* 机构代号 */
  strcpy(pMID_8087_I->TLNO,AUTLCode); /* 柜员号 */
  strcpy(pMID_8087_I->AUTL,AUTLCode); /* 授权柜员 */        
  strcpy(pMID_8087_I->TTYN,TTYNCode); /* 网银终端号*/

  /* STEP1-3: 填上传串中的固定元素值*/
  strcpy(pMID_8087_I->DLDR,"808701"); /* 中间业务交易码 */
  strcpy(pMID_8087_I->TRMD,OPTPCode); /* 业务类型*/

  /* STEP1-4: 从上传报文中获得其余值-用getValueOf函数*/
  getValueOfStr(send_buff,"TPNB",tmpvalue); /* 学籍编码 */
  strcpy(pMID_8087_I->TPNB,tmpvalue);
  getValueOfStr(send_buff,"PSWD",tmppwd); /* 学籍编码 */

    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"珠海市教委直属中小学学费查询\n--->STEP1:通讯前处理-组成上传串send_buff=[%s] 学籍编码=[%s]\n",send_buff,tmpvalue);
    fclose(fp);

  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/
  len=sizeof(MID_DEF_8087_I);
  for(i=0;i<len;i++)
  {
  	if(mid_send_buff[i]==0)
   		mid_send_buff[i]=' ';
  }
  mid_send_buff[len] = '\0';  

  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"--->STEP2:与中间业务前置机通讯mid_send_buff=[%s]\n",mid_send_buff);
    fclose(fp);
  
    /* 与恒生中间业务平台通讯 */
    ret=clienths( mid_send_buff,mid_recv_buff );
    if(ret != RETURN_OK)
	return(-1);
    fp=fopen("/tmp/8087.log","a");
    fprintf(fp,"--->STEP2:与中间业务前置机通讯mid_recv_buff=[%s]\n***************************************************\n",mid_recv_buff);
    fclose(fp);
  /*--------------------STEP3:通讯后处理:组成回传报文------------------*/

  if(memcmp(pMID_8087_O->xym,TRANSOK,sizeof(pMID_8087_O->xym))==0)/*成功*/
  {
  /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
  /* 注意，<br>是页面显示的换行符号 */

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_I->TPNB,sizeof(pMID_8087_I->TPNB));
	sprintf(tmp_val_str,"<b>学籍编码：</b>[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bb,sizeof(pMID_8087_O->bb));
	sprintf(tmp_val_str,"学生姓名：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bm,sizeof(pMID_8087_O->bm));
	sprintf(tmp_val_str,"学校：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bl,sizeof(pMID_8087_O->bl));
	sprintf(tmp_val_str,"年级：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->bxh,sizeof(pMID_8087_O->bxh));
	sprintf(tmp_val_str,"班级：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->czdm,sizeof(pMID_8087_O->czdm));
	sprintf(tmp_val_str,"学号：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->jyje,sizeof(pMID_8087_O->jyje));
	sprintf(tmp_val_str,"<b>缴费总金额：</b>[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxgha,sizeof(pMID_8087_O->dxgha));
	sprintf(tmp_val_str,"明细如下：<br>普通生学(书)杂费：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxghb,sizeof(pMID_8087_O->dxghb));
	sprintf(tmp_val_str,"借读生学(书)杂费：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf1,sizeof(pMID_8087_O->dxqf1));
	sprintf(tmp_val_str,"住宿费：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

/*
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf2,sizeof(pMID_8087_O->dxqf2));
	sprintf(tmp_val_str,"择校费：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8087_O->dxqf3,sizeof(pMID_8087_O->dxqf3));
	sprintf(tmp_val_str,"其他费用：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);
*/

	/* 调用setValueOf函数填充 */
    	setValueOfStr(recv_buff,"display_zone",display_str);

  /* STEP3-2 处理页面隐含要素: 这里填写的字段，就是在页面作为隐含input的要素 */
 /* 注意，1.这里设置参数的顺序必须和数据库中参数的顺序一致，否则回出错！ 
          2.返回码字段名定义注意与WEB上一致*/ 
	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->xym,sizeof(pMID_8087_O->xym));
	setValueOfStr(recv_buff,"MGID",tmp_val_str); /*返回码*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_I->TPNB,sizeof(pMID_8087_I->TPNB));
	setValueOfStr(recv_buff,"TPNB",tmp_val_str);/*学籍编码*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->bb,sizeof(pMID_8087_O->bb));
	setValueOfStr(recv_buff,"bb",tmp_val_str);/* 学生姓名 */

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->jyje,sizeof(pMID_8087_O->jyje));
	setValueOfStr(recv_buff,"jyje",tmp_val_str);/*缴费总金额*/ 

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	setValueOfStr(recv_buff,"passWord",tmppwd);/*银行卡交易密码*/ 

  } else {	/*失败*/
	strcpy(tmp_val_str,"<font color=ff0000>--->交易失败</font><br>");
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"--->失败代码：[%s] <br>",pMID_8087_O->xym);
	strcat(display_str,tmp_val_str);

    	setValueOfStr(recv_buff,"display_zone",display_str);

    	fp=fopen("/tmp/8087.log","a");
    	fprintf(fp,"失败!返回网页显示信息为[%s]\n***************************************************\n",display_str);
    	fclose(fp);

	memset(tmp_val_str,'\0',sizeof(tmp_val_str));
	memcpy(tmp_val_str,pMID_8087_O->xym,sizeof(pMID_8087_O->xym));
 	setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/


	return 0;

  }
}
