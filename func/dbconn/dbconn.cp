
#include <sybtesql.h>

EXEC SQL INCLUDE SQLCA;
/* EXEC SQL INCLUDE "../include/sybase.h"; */

#define SQLERRLOG  "sqlerr.log"
#define OK  0
#define ERROR_LEVEL	0

static	char	err_msg[1000];

int dbconn(char *user1, char *passwd1, char *db1)
{
	EXEC SQL BEGIN DECLARE SECTION;

	CS_CHAR	user[20];
	CS_CHAR	passwd[20];
	CS_CHAR db[20];

	EXEC SQL END DECLARE SECTION;

	strcpy(user, user1);
	strcpy(passwd, passwd1);
	strcpy(db, db1);

	EXEC SQL CONNECT :user IDENTIFIED BY :passwd;
	if(sqlca.sqlcode)
	{
		return -1;
	}
	
	EXEC SQL USE :db;
	if(sqlca.sqlcode)
	{
		return -2;
	}

	return 0;

}

int dbsetconn(char *conn, char *db)
{
	EXEC SQL BEGIN DECLARE SECTION;

	CS_CHAR	dbconn[30];
	CS_CHAR dbname[20];

	EXEC SQL END DECLARE SECTION;

	strcpy(dbconn, conn);
	if(db != NULL)
		strcpy(dbname, db);

	EXEC SQL SET CONNECTION :dbconn;
	if(sqlca.sqlcode) {
		/* write_tdq("STEP", ERROR_LEVEL, "[%d][%s]",
			sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
		*/
		return -1;
	}

	if(db != NULL) {
		EXEC SQL USE :dbname;
		if(sqlca.sqlcode) {
			/* write_tdq("STEP", ERROR_LEVEL, "[%d][%s]",
				sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
			*/
			return -1;
		}
	}

	return 0;
}

int dbdisconn()
{
	EXEC SQL DISCONNECT ALL;
	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);
}

int getsqlcode()
{
	return(sqlca.sqlcode);
}

char*	getsqlerrmsg()
{
	strcpy(err_msg, sqlca.sqlerrm.sqlerrmc);
	return err_msg;
}

int begintran()
{
	EXEC SQL BEGIN TRANSACTION;
	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);	
}


int committran()
{
	EXEC SQL COMMIT TRANSACTION;
	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);	
}

int rollbacktran()
{
	EXEC SQL ROLLBACK TRANSACTION;
	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);	
}


/*
 * int dberrlog(char *, char *)
 * 
 *	Log sql error to a file defined by SQLERRLOG
 *
 */

int dberrlog(char *file, int line)
{
	long	tm;
	char	sqlfile[40], *home;
	FILE	*fp;

	if(sqlca.sqlcode < 0) {
		time(&tm);

		home = getenv("HOME");
		sprintf(sqlfile, "%s", SQLERRLOG);
		fp = fopen( sqlfile, "a+");
		if(fp==NULL) {
			printf("Can not open log file [%s]\n", sqlfile);
			return -1;
		}
		fprintf(fp, "** FILE: [%s] LINE: [%d] TIME: %s",
			file, line, ctime(&tm));
		fprintf(stderr, "** FILE: [%s] LINE: [%d] TIME: %s",
			file, line, ctime(&tm));

		fprintf(fp, "** SQLCODE=[%ld]\n", sqlca.sqlcode);
		fprintf(stderr, "** SQLCODE=[%ld]\n", sqlca.sqlcode);

		if (sqlca.sqlerrm.sqlerrml)
		{
			fprintf(fp, "** ERRMSG: %s", sqlca.sqlerrm.sqlerrmc);
			fprintf(stderr, "** ERRMSG: %s\n", sqlca.sqlerrm.sqlerrmc);
		}

		fprintf(fp, "\n\n");
		fclose(fp);
		fflush(stderr);
	}


	if(sqlca.sqlwarn[0] == 'W') {
		time(&tm);

		home = getenv("HOME");
		sprintf(sqlfile, "%s/log/%s", home, SQLERRLOG);
		fp = fopen( sqlfile, "a+");
		if(fp==NULL) {
			printf("Can not open log file [%s]\n", sqlfile);
			return -1;
		}

		fprintf(fp, "\n** FILE: [%s] LINE: [%d] TIME: %s",
			file, line, ctime(&tm));

		if (sqlca.sqlwarn[1] == 'W')
		{
			fprintf(fp, "\n** Data truncated.\n");
		}

		if (sqlca.sqlwarn[3] == 'W')
		{
			fprintf(fp, "\n** Insufficient host variables "
				"to store results.\n");
		}	
		fclose (fp);
		fflush(stderr);
	}
	if(sqlca.sqlcode < 0)
		return(sqlca.sqlcode);

	return(OK);
}


int	CutSpace(str)
char *str;
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
