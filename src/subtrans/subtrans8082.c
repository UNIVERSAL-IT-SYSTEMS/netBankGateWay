/****************************************
 *程序名:trans8082.c
 *功  能:珠海市教委直属中小学学费交费
 *日  期:2003.11.21
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
  /*说明：send_buff-上传报文；
          recv_buff-下传报文;
          mid_send_buff-与后台通讯的发送串;
          mid_recv_buff-与后台通讯的接收串;
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

  char                  tmpvalue[256]; 	/*从上传报文中取得的某项值*/

  char s_CDNO[LEN_CDNO]; 		/* 太平洋卡号 */
  char s_PSWD[LEN_PSWD]; 		/* 太平洋密码 */

  void *pComplibhandle; /* Handle to shared lib file */ 
  int (*pCompfunchandle)(); /* Pointer to loaded routine */ 

  /*-------------------STEP1:通讯前处理-组成上传串--------------------*/

  /* STEP1-1:清理结构和变量 */
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

  /* 注意：填充数据最好按照结构定义先后顺序，以免出现数据覆盖问题 */
  /* STEP1-2:填上传串的固定头 */
  strcpy(pMID_8082_I->TRCD,"8082");   /* 交易代码 */
  strcpy(pMID_8082_I->RGCD,AreaCode); /* 地区代号 */
  strcpy(pMID_8082_I->OGCD,ORGCode);  /* 机构代号 */
  strcpy(pMID_8082_I->TLNO,AUTLCode); /* 机构代号 */
  strcpy(pMID_8082_I->AUTL,AUTLCode); /* 授权柜员 */        
  strcpy(pMID_8082_I->TTYN,TTYNCode); /* 网银终端号*/

  /* STEP1-3: 填上传串中的固定元素值*/
  strcpy(pMID_8082_I->DLDR,"808201"); /* 中间业务交易码 */
  strcpy(pMID_8082_I->TRMD,OPTPCode); /* 业务类型*/
  strcpy(pMID_8082_I->DLMD,"1"); /* 缴费方式 卡缴费 1 */

  /* 以下域在网银端可不填充真实数据 */
  strcpy(pMID_8082_I->NAME,"qqqqqqqqqqqqqqqqqqqq"); /*客户名称 */
  /*strcpy(pMID_8082_I->IDTP,"q"); 证件类型*/
  strcpy(pMID_8082_I->IDNO,"qqqqqqqqqqqqqqqqqqqq"); /*身份证号码 */

  /* STEP1-4: 从WEB上传报文中获得其余值-用getValueOf函数*/
  getValueOfStr(send_buff,"CDNO",tmpvalue);/*卡号*/
  strcpy(s_CDNO,tmpvalue);
  strcpy(pMID_8082_I->CDNO,tmpvalue);

  /* 以下域在网银端可不填充真实数据 */
  strcpy(pMID_8082_I->ACNO,"qqqqqqqqqqqqqqqqqqqq"); /*帐号*/
  strcpy(pMID_8082_I->ACID,"qqqqqqqqqqqqqqqqqqqq"); /* 银行帐号 */

  strcpy(pMID_8082_I->WDMD,"0"); /*取款方式 凭密码取款 0 */

  strcpy(pMID_8082_I->TRPS,"qqqqqq"); /*非密文密码 网银端可不填充真实数据 */

  getValueOfStr(send_buff,"TPNB",tmpvalue); /*学籍编码*/
  strcpy(pMID_8082_I->TPNB,tmpvalue);


  /* 在域ACNM中放学生姓名 对后台无用处 仅用于返回交易成功时在网页显示*/
  getValueOfStr(send_buff,"bb",tmpvalue); 
  strcpy(pMID_8082_I->ACNM,tmpvalue);

  getValueOfStr(send_buff,"jyje",tmpvalue); /*缴费总金额*/
  strcpy(pMID_8082_I->AMLM,tmpvalue);

  /*密码加密tmpvalue->s_PSWD begin 网银版 调试成功*/
  getValueOfStr(send_buff,"PSWD",tmpvalue);
  flog(INFO_LEVEL,"加密前取PSWD=[%s]成功",tmpvalue);
  if((pComplibhandle = dlopen("libencrytrps.so", RTLD_LAZY)) == NULL)
  {
  	flog(INFO_LEVEL,"%s,%s,%s,%s","执行动态失败", dlerror(), "libencrytrps.so","encry_trps");
  	return -1;
  }

  if((pCompfunchandle=(int (*)())dlsym(pComplibhandle, "encry_trps"))== NULL)
  {
        dlclose(pComplibhandle);
        flog(INFO_LEVEL,"%s,%s,%s,%s","执行动态失败",dlerror(), "libencrytrps.so","encry_trps");
        return -1;
   }

  if((en_ret=(*pCompfunchandle)("8082",AreaCode,ORGCode,AUTLCode,s_CDNO,tmpvalue,s_PSWD)) != 0 )
  {
        dlclose(pComplibhandle);
        flog(INFO_LEVEL,"%s,%s,%s,%s,%d","执行动态失败",dlerror(), "libencrytrps.so","encry_trps",en_ret);
        return -1;
  }
  strcpy(pMID_8082_I->DESP,s_PSWD);
  flog(INFO_LEVEL,"%s,%s,%d","执行动态成功", "libencrytrps.so",en_ret);

  if ( dlclose(pComplibhandle))
  {
        flog(INFO_LEVEL,"%s,%s,%s,%s","执行动态失败",dlerror(),"libencrytrps.so","encry_trps");
        return -1;
  }

  /*20040831 wusf midify 由于一些特殊的卡号与密码加密后后台无法正常解密,特加以下 代码解决该问题，解决方法是在密码密文的最后一个结束符后加空格 */
  /*密文加空格start*/
  /*密文加空格end*/

  /*密码加密tmpvalue->s_PSWD 网银版 end*/

    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"珠海市教委直属中小学学费交费\n--->STEP1:通讯前处理-组成上传串-->send_buff=[%s]\n",send_buff);
    fclose(fp);

  /*STEP1-4:把结构中的结束符替换为空格，上传串末尾加结束符.*/
  len=sizeof(MID_DEF_8082_I);
  for(i=0;i<len;i++)
  {
  	if(mid_send_buff[i]==0)
   		mid_send_buff[i]=' ';
  }
  mid_send_buff[len] = '\0';  


  /*----------------------STEP2:与中间业务前置机通讯-----------------*/
    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"--->STEP2:与中间业务前置机通讯mid_send_buff=[%s]\n",mid_send_buff);
    fclose(fp);
  
 /* 与恒生中间业务平台通讯 */
    ret=clienths( mid_send_buff,mid_recv_buff );
	if(ret != RETURN_OK)
		return(-1);
    fp=fopen("/tmp/8082.log","a");
    fprintf(fp,"--->STEP2:与中间业务前置机通讯mid_recv_buff=[%s]\n",mid_recv_buff);
    fclose(fp);


  /*--------------------STEP3:通讯后处理:组成回传报文------------------*/

  if(memcmp(pMID_8082_O->MGID,TRANSOK,sizeof(pMID_8082_O->MGID))==0)/*成功*/
  {
  /* STEP3-1处理页面显示要素: 在这里填写的字段，就是在页面上显示的字段 */
  /* 注意，<br>是页面显示的换行符号 */

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"学籍编码：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->ACNM,sizeof(pMID_8082_I->ACNM));
	sprintf(tmp_val_str,"学生姓名：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"交费金额：[%s] <br>",tmp_val_str2);
	strcat(display_str,tmp_val_str);
        strcat(display_str,"<b>交费成功!</b><br>");

        /* STEP3-1-1 在日志中记录有关数据备查 begin*/
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"学籍编码：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_O->TRDT,sizeof(pMID_8082_O->TRDT));
	sprintf(tmp_val_str,"交易日期：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_O->TLCS,sizeof(pMID_8082_O->TLCS));
	sprintf(tmp_val_str,"柜员流水：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"交费金额：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        fp=fopen("/tmp/8082.log","a");
    	fprintf(fp,"STEP3:通讯后处理-->交费成功! {%s}\n*********************************\n",display_log_str);
    	fclose(fp);
        /* STEP3-1-1 在日志中记录有关数据备查 end*/

	/* 调用setValueOf函数填充 */
    	setValueOfStr(recv_buff,"display_zone",display_str);

  /* STEP3-2 处理页面隐含要素: 这里填写的字段，就是在页面作为隐含input的要素 */
 /* 注意，这里设置参数的顺序必须和数据库中参数的顺序一致，否则回出错！ */
        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memcpy(tmp_val_str,pMID_8082_O->MGID,sizeof(pMID_8082_O->MGID));
        setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/


  } else {	/*失败*/
	strcpy(tmp_val_str,"<font color=ff0000><b>--->交费失败！<br>--->如有疑问，请及时与开户银行联系！</b></font><br>");
	strcat(display_str,tmp_val_str);

	sprintf(tmp_val_str,"--->失败代码：[%s] <br>",pMID_8082_O->MGID);
	strcat(display_str,tmp_val_str);

    	setValueOfStr(recv_buff,"display_zone",display_str);
	
        memset(tmp_val_str,'\0',sizeof(tmp_val_str));
        memcpy(tmp_val_str,pMID_8082_O->MGID,sizeof(pMID_8082_O->MGID));
        setValueOfStr(recv_buff,"MGID",tmp_val_str);/*返回码*/

       /* 在日志中记录有关数据备查 begin*/
        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->TPNB,sizeof(pMID_8082_I->TPNB));
	sprintf(tmp_val_str,"学籍编码：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        memset(tmp_val_str2,0,sizeof(tmp_val_str2));
	memcpy(tmp_val_str2,pMID_8082_I->AMLM,sizeof(pMID_8082_I->AMLM));
	sprintf(tmp_val_str,"交费金额：[%s] ",tmp_val_str2);
	strcat(display_log_str,tmp_val_str);

        fp=fopen("/tmp/8082.log","a");
    	fprintf(fp,"STEP3:通讯后处理-->交费失败! 注意检查是否后台已扣账,但是中间业务平台未置已交费标志！{%s %s}\n*****************************\n",display_str,display_log_str);
    	fclose(fp);
       /* 在日志中记录有关数据备查 end*/

	return 0;

  }
}
