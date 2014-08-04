#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netbank_mid.h"
#include "trans_macro.h"

/*
 * get info from the buff string with id
 * NOT XML
 */

int getValueOfInt(char *str1, char *str2)
{
	char tmp_str[LEN_MID_PROC_BUF];
	char str3[5];

	memset(tmp_str,'\0',sizeof(tmp_str));
	memset(str3,'\0',sizeof(str3));

	strcpy(tmp_str,strstr(str1,str2));
	memcpy(str3,tmp_str+strlen(str2)+1,strstr(tmp_str,"|")-strstr(tmp_str,str2)-strlen(str2)-1);

	return(atoi(str3));
}

void setValueOfInt(char *str1, char *str2, int i_val)
{
	char s_val[5];
        FILE *fp;
        
	memset(s_val,'\0',sizeof(s_val));
	sprintf(s_val,"%d",i_val);

	strcat(str1,str2);
	strcat(str1,",");
	strcat(str1,s_val);
	strcat(str1,"|");

}

void getValueOfStr(char *str1, char *str2, char *str3)
{
	char tmp_str[LEN_MID_PROC_BUF];
        int len;
        FILE *fp;

	memset(tmp_str,'\0',sizeof(tmp_str));

	strcpy(tmp_str,strstr(str1,str2));
        len=strstr(tmp_str,"|")-strstr(tmp_str,",")-1;
	memcpy(str3, tmp_str+strlen(str2)+1,len);
        str3[len]=0;
        /*
                fp=fopen("/tmp/zxz1.log","a");
                fprintf(fp,"str2=[%s]str3=[%s]1[%d]2[%d]\n",str2,str3,strstr(tmp_str,"|")-strstr(tmp_str,str2)-strlen(str2)-1,strstr(tmp_str,"|")-strstr(tmp_str,",")-1);
                fclose(fp);
        */
	flog(STEP_LEVEL,"str3 = [%s]\n",str3);

}

void setValueOfStr(char *str1, char *str2, char *str3)
{
	strcat(str1,str2);
	strcat(str1,",");
	strcat(str1,str3);
	strcat(str1,"|");
}

