#include <cics_api.h>
#include <cics_eib.h>

/* ����������CICS Server����дTDQ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "misc.h"
#include "netbank.h"

extern	int	errno;
static	int	base_level = -1;

char*	exec_cics_msg(unsigned long respCode);

int write_tdq(char* tdq, int level, char* fmt, ...)
{
	int	len;
	int	ret;
	ulong	resp;
	va_list	args;
	char	msg[ MESSAGE_LENGTH ];
	char	message[ MESSAGE_LENGTH ];

	/* ȡ�����ļ����ݣ����ʧ�ܣ�������־�ȼ� -2 */
	if (base_level < 0) {
		ret = get_config_value(CONFIG_FILE_NAME, LOG_LEVEL, message);
		if (ret != 0) { 
			if (base_level != -2)
				fprintf(stderr, 
					"-->Get config file [%s] error [%s]!\n",
					CONFIG_FILE_NAME, strerror(errno));
			base_level = -2;
		}
		else
			base_level = atoi(message);
	}

	/* ������־��¼���� */
	va_start(args, fmt);
	vsprintf(msg, fmt, args);
	va_end(args);
	sprintf(message, "-->Netbank : %s", msg);

	/* ����޷�ȡ�������ļ��е���־�ȼ�������Ϣ�������׼������ */
	if (base_level < 0) {
		/* fprintf(stderr, "%s\n", message); */
		fprintf(stderr, "-->>Netbank : �޷�д��־�ļ�");
		return 0;
	}

	/* ����־������бȽ� */
	if (level > base_level)
		return 0;

	/* ����־���ݼ�¼��TDQ�� */
	len = strlen(message);
	/* EXEC CICS WRITEQ TD QUEUE (tdq) FROM (message) LENGTH (len) RESP (resp); */ \
    { \
	cics_api_strncpy(CicsArgs.ArgData[9].StringValue, tdq, (short)4); \
	CicsArgs.ArgData[4].DataArea = message; \
	CicsArgs.ArgData[2].ShortValue = len; \
	CicsArgs.ArgMask = 0x20000214; \
	CicsArgs.FnCode = 106; \
	CicsArgs.DebugLine = -1; \
	cics_api_exec_c(&CicsArgs); \
	resp = dfheiptr->eibresp; \
    }

	return check_respcode(resp);
}

/* ���EXEC CICS���õķ����� */
int check_respcode(ulong respCode)
{
	if (respCode == 0)
		return 0;
	else 
		fprintf(stderr, "-->>Error [%s] occured [%s] [%d]!\n", 
			exec_cics_msg(respCode), __FILE__, __LINE__);
	
	return -1;
}

/* ����EXEC CICS���÷����룬ȷ�����÷���״̬ */
static char*	exec_cics_msg(unsigned long code)
{
	static	char	msg[MESSAGE_LENGTH];

	/* while "EXEC CICS ADDRESS" */
	if      (code == 0) 	sprintf(msg, "NORMAL");
	else if (code == 17) 	sprintf(msg, "IOERR");
	else if (code == 54)	sprintf(msg, "ISCINVREQ");
	else if (code == 22)	sprintf(msg, "LENGERR");
	else if (code == 18)	sprintf(msg, "NOSPACE");
	else if (code == 70)	sprintf(msg, "NOTAUTH");
	else if (code == 19)	sprintf(msg, "NOTOPEN");
	else if (code == 44)	sprintf(msg, "QIDERR");
	else if (code == 53)	sprintf(msg, "SYSIDERR");

	/* while "EXEC CICS LINK" */
	else if (code == 16)	sprintf(msg, "INVREQ");
	else if (code == 27)	sprintf(msg, "PGMIDERR");
	else if (code == 82)	sprintf(msg, "ROLLEDBACK");
	else if (code == 81)	sprintf(msg, "TERMERR");
	/* else if (code == DFHRESP(LENGERR))	sprintf(msg, "LENGERR"); */
	/* else if (code == DFHRESP(NOTAUTH))	sprintf(msg, "NOTAUTH"); */
	/* else if (code == DFHRESP(SYSIDERR))	sprintf(msg, "SYSIDERR"); */

	/* while "EXEC CICS SYNCPOINT" */
	/* else if (code == DFHRESP(INVREQ))	sprintf(msg, "INVREQ"); */
	/* else if (code == DFHRESP(ROLLEDBACK)) sprintf(msg, "ROLLEDBACK"); */

	/* Add more here */
	else					sprintf(msg, "Unknown");

	return msg;
}
