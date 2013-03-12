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
#include <time.h>
#include <unistd.h>
#include "miscfunc.h"
#include "error.h"
#include "netbank_mid.h"

/*
extern	int	LOG_LEVEL;
extern	char	LOG_FILE_NAME[100];
extern	int	BUF_LEVEL;
extern	char	BUF_FILE_NAME[100];
*/

int IntToStr( unsigned char *bp, unsigned int s, int len )
{
    register int i;

    for ( i = len - 1; i >= 0; i -- )
      {
        bp[i] = ( unsigned char )( s % 10 ) + '0';
        s = s / 10;
      }
    return ( s );
}

int
GetTime( char *bp )
{
    long t;
    struct tm *tbp;

    time( ( long * )&t );
    tbp = localtime( &t );
    IntToStr( bp, tbp->tm_hour, 2 );
    bp[2] = ':';
    IntToStr( bp + 3, tbp->tm_min, 2 );
    bp[5] = ':';
    IntToStr( bp + 6, tbp->tm_sec, 2 );
    bp[8] = '\0';
}

int
GetDate( char *bp )
{
    long t;
    struct tm *tbp;

    time( ( long * )&t );
    tbp = localtime( &t );
    IntToStr( bp, tbp->tm_year + 1900, 4 );
    IntToStr( bp + 4, tbp->tm_mon + 1, 2 );
    IntToStr( bp + 6, tbp->tm_mday, 2 );
    bp[8] = '\0';
}

void ErrLog( char *file, int line, char *fmt, ... )
{
    va_list ap;
    FILE   *fp;
    int    fd;
    char timebuf[20];
    char datebuf[20];
		char log_name[100];

		memset( log_name, 0, sizeof( log_name ) ) ;
		memset( datebuf, 0, sizeof( datebuf ) ) ;
		GetDate( datebuf );
		strcpy( log_name, LOG_FILE_NAME ) ;
		strcat( log_name, "." ) ;
		strcat( log_name, datebuf ) ;

    if ( (fp=fopen( log_name, "a+")) == NULL ) {
        fprintf(stderr, "open %s file error.\n", LOG_FILE_NAME);
        return;
    }
    fd = fileno(fp);
    lockf (fd, F_LOCK, 0l);
    GetTime( timebuf );
    fprintf (fp, "[%s] ", timebuf );
    fprintf (fp, "[%s line %d] :\n", file, line);
    va_start( ap, fmt );
    vfprintf( fp, fmt, ap );
		fprintf(fp, "\n");
    va_end( ap );
    lockf(fd, F_ULOCK, 0l);
    fclose(fp);
    return;
}

void
flog(int level, char *fmt, ...)
{
	FILE *fp;
	va_list	args;
	int		fd;
	char	timebuf[20];
  char datebuf[20];
	char log_name[100];

	memset( log_name, 0, sizeof( log_name ) ) ;
	memset( datebuf, 0, sizeof( datebuf ) ) ;
	GetDate( datebuf );
	strcpy( log_name, LOG_FILE_NAME ) ;
	strcat( log_name, "." ) ;
	strcat( log_name, datebuf ) ;

	if ((fp = fopen( log_name, "a+" ) ) == NULL)
		return;

	if (level <= LOG_LEVEL) {
    fd = fileno(fp);
    lockf (fd, F_LOCK, 0l);
    GetTime( timebuf );
    fprintf (fp, "%s ", timebuf );
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
    lockf(fd, F_ULOCK, 0l);
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
