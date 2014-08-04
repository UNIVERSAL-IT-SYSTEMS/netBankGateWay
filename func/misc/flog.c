/*-------------------------------------
 *
 * 打印调试信息
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "miscfunc.h"
#include "error.h"
#include "netbank_mid.h"

/*
extern	int	LOG_LEVEL;
extern	char	LOG_FILE_NAME[100];
extern	int	BUF_LEVEL;
extern	char	BUF_FILE_NAME[100];
*/

void
flog(int level, char *fmt, ...)
{
	FILE *fp;
	va_list	args;
	
	if ((fp = fopen(LOG_FILE_NAME, "a")) == NULL)
		return;

	if (level <= LOG_LEVEL) {
		va_start(args, fmt);
		vfprintf(fp, fmt, args);
		fprintf(fp, "\n");
		/*
		if (level == 0) {
			vfprintf(stderr, fmt, args);
			fprintf(stderr, "\n");
			fflush(stderr);
		}
		*/
		va_end(args);
	}

	fclose(fp);

	return;
}

/* 将BUFFER的内容以十六进制的格式打印出来 */
void
fhlog(char *buf, int len)
{
	int	ret;
	int	i;
	int	j;
	char	temp1[100];
	char	temp2[100];
	char	*p;
	int	offset;
	int	t1;
	int	t2;

	FILE*	fp;

	/* 如果不打印,退出 */
	if (BUF_LEVEL == 0)
		return;

	/* 如果文件未打开 */
	if ((fp = fopen(BUF_FILE_NAME, "a")) == NULL)
		return ;

	/* 初始化 */
	i = 0; 
	j = 0;
	memset(temp1, 0, sizeof(temp1));
	memset(temp2, 0, sizeof(temp2));


	fprintf(fp, "时间:[%08d] 时间:[%06d]\n", 
		get_sys_date(), get_sys_time());

	for (i = 0; i < len; i ++) {
		if ((i + 1) % 10 == 0 && (i + 1) % 20 != 0)
			sprintf(temp2, "%02X-", (unsigned char)(*(buf + i)));
		else 
			sprintf(temp2, "%02X ", (unsigned char)(*(buf + i)));
		strcat(temp1, temp2);
		if ((i + 1) % 20 == 0 && i != 0) {
			fprintf(fp, "%s", temp1);
			memset(temp1, 0, sizeof(temp1));
			zmemcpy(temp1, buf + j, 20);
			for (t1 = 0; t1 < 20; t1 ++) {
				if (!isprint(*(temp1 + t1)))
					*(temp1 + t1) = '.';
				fprintf(fp, "%c", *(temp1 + t1));
			}
			fprintf(fp, "\n");
			j = i + 1;
			memset(temp1, 0, sizeof(temp1));
		}
	}

	if ((i + 1) % 20 != 0) {
		fprintf(fp, "%-60s", temp1);
		zmemcpy(temp1, buf + j, len - j);
		for (t1 = 0; t1 < len - j; t1 ++) {
			if (!isprint(*(temp1 + t1)))
				*(temp1 + t1) = '.';
			fprintf(fp, "%c", *(temp1 + t1));
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "\n\n");

	fclose(fp);

	return;
}
