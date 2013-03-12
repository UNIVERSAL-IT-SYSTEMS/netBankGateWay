
/*
 *	CICS客户端使用的库函数
 *	Coding By WangXiancheng at 00-11-11
 *	Modified By WangXiancheng at 00-11-14 08:53下午
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cics_eci.h>

#define MAX_SERVER	50	/* 最大的CICS Server数目 */

#define ECI_SYNC_SIZE 20000	/* 最大的通讯区长度 */

static int	wcutspace(char *);
char 	*Response(short Ret);
static	char ebcli_errmsg[101];
char	*get_ebcli_errmsg();

/*
 *	eci_call:	CICS客户端通讯发送和接收函数
 *	输入参数：	servername -- CICS server的名称
 *			commbuf -- 通讯缓冲区字符串（指针）
 *			len -- 通讯缓冲区中的字符串实际长度
 *			prg -- 被调用的CICS server中的程序名
 *			timeout -- 超时时间（秒）
 *	输出：		返回值 -- 0：成功
 *			         -1：失败
 *			commbuf -- 当调用成功时，服务器返回的报文字符串
 */
int eci_call(char *servername,char *commbuf, cics_sshort_t len,
cics_char_t *prg, cics_sshort_t timeout)
{

   CICS_EciSystem_t servers[MAX_SERVER];   /*Servers from CICS_EciListSystems */
   cics_ushort_t    serverCount = MAX_SERVER;/*Length counter for above list  */
   cics_char_t      chosenServer[CICS_ECI_SYSTEM_MAX +1];/*Selected servername*/
   ECI_PARMS        EciParms;                /*The ECI Parameter block */

	char	UserID[9] = "CICSUSER"; 
	char	PassWd[9] = "        ";

	short	ret;                 
	int	i = 0;
	int	loop = 0;
	int	flag = 0;

	if(len>ECI_SYNC_SIZE) {
		sprintf(ebcli_errmsg, "commbuf is too long");
		return(-1);
	}
	
	ret = CICS_EciListSystems(NULL,&serverCount,servers);
	if (ret == ECI_NO_ERROR) {

		for (i=0; i<serverCount;i++) {
            		strcpy(chosenServer,servers[i].SystemName);  	    	
      	    		wcutspace(chosenServer);
      	    		if(strcmp(chosenServer, servername)==0) {
            			strcpy(chosenServer,servers[i].SystemName);
            			flag = 1;
            			break;
            		}
		}
		if(!flag) {
			sprintf(ebcli_errmsg, "No server found");
			return(-1);
		}
        
/**************************************************************************/
/* Set up the ECI Parameter block                                         */
/**************************************************************************/
		memset(&EciParms, 0, sizeof(ECI_PARMS));
		EciParms.eci_version                           = ECI_VERSION_1;
		EciParms.eci_call_type                         = ECI_SYNC;
		memcpy(&EciParms.eci_program_name, prg,          8);
		memcpy(&EciParms.eci_userid,       UserID,       8);
		memcpy(&EciParms.eci_password,     PassWd,       8);
		memcpy(&EciParms.eci_system_name,  chosenServer, 8);
		EciParms.eci_commarea                          = commbuf;
		EciParms.eci_commarea_length                   = ECI_SYNC_SIZE;
		EciParms.eci_extend_mode                       = ECI_NO_EXTEND;
		EciParms.eci_luw_token                         = ECI_LUW_NEW;
		EciParms.eci_timeout                           = timeout;

/**************************************************************************/
/* Call the chosen server with the given parameters                       */
/**************************************************************************/
		ret = CICS_ExternalCall (&EciParms);
		if (ret == ECI_NO_ERROR) {
			return(0);
		} else {
			strcpy(ebcli_errmsg, Response(ret));
			return ret;
		}

	} else {
		strcpy(ebcli_errmsg, Response(ret));
		return -1;
	}

	return 0;
}

/*********************************************************************/
/* Function: Response                                                */
/*                                                                   */
/* Purpose:  return the immediate response code from an ECI call    */
/*********************************************************************/
char	*Response(short Rc)
{
   char *p;

   switch (Rc) {
   case ECI_NO_ERROR:                p = "ECI_NO_ERROR               ";break;
   case ECI_ERR_INVALID_DATA_LENGTH: p = "ECI_ERR_INVALID_DATA_LENGTH";break;
   case ECI_ERR_INVALID_EXTEND_MODE: p = "ECI_ERR_INVALID_EXTEND_MODE";break;
   case ECI_ERR_NO_CICS:             p = "ECI_ERR_NO_CICS            ";break;
   case ECI_ERR_CICS_DIED:           p = "ECI_ERR_CICS_DIED          ";break;
   case ECI_ERR_REQUEST_TIMEOUT:     p = "ECI_ERR_REQUEST_TIMEOUT    ";break;
   case ECI_ERR_RESPONSE_TIMEOUT:    p = "ECI_ERR_RESPONSE_TIMEOUT   ";break;
   case ECI_ERR_TRANSACTION_ABEND:   p = "ECI_ERR_TRANSACTION_ABEND  ";break;
   case ECI_ERR_EXEC_NOT_RESIDENT:   p = "ECI_ERR_EXEC_NOT_RESIDENT  ";break;
   case ECI_ERR_SYSTEM_ERROR:        p = "ECI_ERR_SYSTEM_ERROR       ";break;
   case ECI_ERR_NULL_WIN_HANDLE:     p = "ECI_ERR_NULL_WIN_HANDLE    ";break;
   case ECI_ERR_NULL_MESSAGE_ID:     p = "ECI_ERR_NULL_MESSAGE_ID    ";break;
   case ECI_ERR_THREAD_CREATE_ERROR: p = "ECI_ERR_THREAD_CREATE_ERROR";break;
   case ECI_ERR_INVALID_CALL_TYPE:   p = "ECI_ERR_INVALID_CALL_TYPE  ";break;
   case ECI_ERR_ALREADY_ACTIVE:      p = "ECI_ERR_ALREADY_ACTIVE     ";break;
   case ECI_ERR_RESOURCE_SHORTAGE:   p = "ECI_ERR_RESOURCE_SHORTAGE  ";break;
   case ECI_ERR_NO_SESSIONS:         p = "ECI_ERR_NO_SESSIONS        ";break;
   case ECI_ERR_NULL_SEM_HANDLE:     p = "ECI_ERR_NULL_SEM_HANDLE    ";break;
   case ECI_ERR_INVALID_DATA_AREA:   p = "ECI_ERR_INVALID_DATA_AREA  ";break;
   case ECI_ERR_INVALID_VERSION:     p = "ECI_ERR_INVALID_VERSION    ";break;
   case ECI_ERR_UNKNOWN_SERVER:      p = "ECI_ERR_UNKNOWN_SERVER     ";break;
   case ECI_ERR_CALL_FROM_CALLBACK:  p = "ECI_ERR_CALL_FROM_CALLBACK ";break;
   case ECI_ERR_INVALID_TRANSID:     p = "ECI_ERR_INVALID_TRANSID    ";break;
   case ECI_ERR_MORE_SYSTEMS:        p = "ECI_ERR_MORE_SYSTEMS       ";break;
   case ECI_ERR_NO_SYSTEMS:          p = "ECI_ERR_NO_SYSTEMS         ";break;
   case ECI_ERR_SECURITY_ERROR:      p = "ECI_ERR_SECURITY_ERROR     ";break;
   case ECI_ERR_MAX_SYSTEMS:         p = "ECI_ERR_MAX_SYSTEMS        ";break;
   case ECI_ERR_MAX_SESSIONS:        p = "ECI_ERR_MAX_SESSIONS       ";break;
   case ECI_ERR_ROLLEDBACK:          p = "ECI_ERR_ROLLEDBACK         ";break;
   default:
      {
         p = "!!!Unknown!!!";
      }
      break;
   }

	return p;
} 

static int	wcutspace(char *str)
{
	int	len, i;

	len = strlen(str);
	i = len-1;
	while(*(str+i) == ' ') {
		*(str+i) = '\0';
		i --;
	}
	return(0);
}

/*
 *	get_ebcli_errmsg:	当ebcli_send_and_recv调用失败时，使用本函数得到CICS错误信息
 *	输入参数：		无
 *	输出：			返回值 -- 错误信息指针（仅当上面的函数返回-1时，返回的信息才有意义）
 */
char	*get_eci_call_err()
{
	return ebcli_errmsg;
}
