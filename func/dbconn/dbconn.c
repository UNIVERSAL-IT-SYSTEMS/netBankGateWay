
/*
** Generated code begins here.
*/
# line 1 "dbconn.cp"

/*
** This file was generated on Tue Oct 30 16:32:48 2001
**  by Sybase Embedded SQL Preprocessor Sybase ESQL/C Precompiler/11.1/P-EBF755
** 6/rs6000/AIX 4.1.4/1/Fri Oct  3 08:34:05 PDT 1997

*/
# line 1 "dbconn.cp"
# line 1 "dbconn.cp"
#define _SQL_SCOPE extern
# line 1 "dbconn.cp"
#include <sybhesql.h>

/*
** Generated code ends here.
*/
# line 1 "dbconn.cp"

#include <sybtesql.h>


/*
** SQL STATEMENT: 1
** EXEC SQL INCLUDE SQLCA;

*/
# line 4 "dbconn.cp"
# line 4 "dbconn.cp"
SQLCA sqlca;

/*
** Generated code ends here.
*/
# line 4 "dbconn.cp"

/* EXEC SQL INCLUDE "../include/sybase.h"; */

#define SQLERRLOG  "sqlerr.log"
#define OK  0
#define ERROR_LEVEL	0

static	char	err_msg[1000];

int dbconn(char *user1, char *passwd1, char *db1)
{
	
           /*
           ** SQL STATEMENT: 1
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 15 "dbconn.cp"


	CS_CHAR	user[20];
	CS_CHAR	passwd[20];
	CS_CHAR db[20];

	
           /*
           ** SQL STATEMENT: 2
           ** EXEC SQL END DECLARE SECTION;

           */
# line 21 "dbconn.cp"

           /*
           ** Generated code ends here.
           */
# line 21 "dbconn.cp"


	strcpy(user, user1);
	strcpy(passwd, passwd1);
	strcpy(db, db1);

	
           /*
           ** SQL STATEMENT: 3
           ** EXEC SQL CONNECT :user IDENTIFIED BY :passwd;
           */
# line 27 "dbconn.cp"
# line 27 "dbconn.cp"
           {
# line 27 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 27 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 27 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 27 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 27 "dbconn.cp"
               {
# line 27 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 27 "dbconn.cp"
                   _sql->stmttype = SQL_NONANSI_CONNECT;
# line 27 "dbconn.cp"
                   _sql->connName.lnlen = 7;
# line 27 "dbconn.cp"
                   strcpy(_sql->connName.last_name, "DEFAULT");
# line 27 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 27 "dbconn.cp"
                   {
# line 27 "dbconn.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 27 "dbconn.cp"
                       {
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_USERNAME, user, CS_NULLTERM, NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_PASSWORD, passwd, CS_NULLTERM, NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = _sqlctdiag(_sql, CS_CLEAR, 
# line 27 "dbconn.cp"
                                   CS_UNUSED);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_capability(_sql->conn.connection, CS_SET,
# line 27 "dbconn.cp"
                                    CS_CAP_RESPONSE, CS_RES_NOSTRIPBLANKS, 
# line 27 "dbconn.cp"
                                   &_sql->cstrue);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_EXTRA_INF, &_sql->cstrue, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_ANSI_BINDS, &_sql->cstrue, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_connect(_sql->conn.connection, NULL, 0);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_con_props(_sql->conn.connection, CS_GET, 
# line 27 "dbconn.cp"
                                   CS_TDS_VERSION, &_sql->temp_int, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   &_sql->outlen);
# line 27 "dbconn.cp"
                               if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                               {
# line 27 "dbconn.cp"
                                   if (_sql->temp_int < CS_TDS_50)
# line 27 "dbconn.cp"
                                   {
# line 27 "dbconn.cp"
                                       _sqlsetintrerr(_sql, (CS_INT) 
# line 27 "dbconn.cp"
                                           _SQL_INTRERR_25013);
# line 27 "dbconn.cp"
                                   }
# line 27 "dbconn.cp"
                                   
# line 27 "dbconn.cp"
                               }
# line 27 "dbconn.cp"
                               
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_OPT_ANSINULL, &_sql->cstrue, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_OPT_ANSIPERM, &_sql->cstrue, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   NULL);
# line 27 "dbconn.cp"
                               _sql->retcode = CS_SUCCEED;
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_OPT_STR_RTRUNC, &_sql->cstrue, CS_UNUSED,
# line 27 "dbconn.cp"
                                    NULL);
# line 27 "dbconn.cp"
                               _sql->retcode = CS_SUCCEED;
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_OPT_ISOLATION, &_sql->Level3, CS_UNUSED, 
# line 27 "dbconn.cp"
                                   NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 27 "dbconn.cp"
                           {
# line 27 "dbconn.cp"
                               _sql->retcode = 
# line 27 "dbconn.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 27 "dbconn.cp"
                                   CS_OPT_QUOTED_IDENT, &_sql->cstrue, 
# line 27 "dbconn.cp"
                                   CS_UNUSED, NULL);
# line 27 "dbconn.cp"
                           }
# line 27 "dbconn.cp"
                           
# line 27 "dbconn.cp"
                           _sql->retcode = _sqlepilog(_sql);
# line 27 "dbconn.cp"
                       }
# line 27 "dbconn.cp"
                       
# line 27 "dbconn.cp"
                   }
# line 27 "dbconn.cp"
                   
# line 27 "dbconn.cp"
               }
# line 27 "dbconn.cp"
               
# line 27 "dbconn.cp"
           }
# line 27 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 27 "dbconn.cp"

	if(sqlca.sqlcode)
	{
		return -1;
	}
	
	
           /*
           ** SQL STATEMENT: 4
           ** EXEC SQL USE :db;
           */
# line 33 "dbconn.cp"
# line 33 "dbconn.cp"
           {
# line 33 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 33 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 33 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 33 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 33 "dbconn.cp"
               {
# line 33 "dbconn.cp"
                   _sql->stmtIdlen = CS_UNUSED;
# line 33 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 33 "dbconn.cp"
                   _sql->stmttype = SQL_MISC;
# line 33 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 33 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 33 "dbconn.cp"
                   {
# line 33 "dbconn.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 33 "dbconn.cp"
                           CS_LANG_CMD, "USE @sql0_db ", 13, CS_UNUSED);
# line 33 "dbconn.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 33 "dbconn.cp"
                       {
# line 33 "dbconn.cp"
                           _sql->dfmtNULLCHAR.count = 0;
# line 33 "dbconn.cp"
                           _sql->dfmtNULLCHAR.maxlength = 
# line 33 "dbconn.cp"
                           _sql_MIN(256,20);
# line 33 "dbconn.cp"
                           _sql->dfmtNULLCHAR.format = CS_FMT_NULLTERM;
# line 33 "dbconn.cp"
                           _sql->dfmtNULLCHAR.status = CS_INPUTVALUE;
# line 33 "dbconn.cp"
                           _sql->retcode = ct_param(_sql->conn.command, 
# line 33 "dbconn.cp"
                               &_sql->dfmtNULLCHAR, 
# line 33 "dbconn.cp"
                           SQLNULLSTR(db), (CS_INT) CS_NULLTERM, (CS_SMALLINT) 
# line 33 "dbconn.cp"
                               0);
# line 33 "dbconn.cp"
                           _sql->dfmtNULLCHAR.status = 0;
# line 33 "dbconn.cp"
                       }
# line 33 "dbconn.cp"
                       
# line 33 "dbconn.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 33 "dbconn.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 33 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 33 "dbconn.cp"
                   }
# line 33 "dbconn.cp"
                   
# line 33 "dbconn.cp"
               }
# line 33 "dbconn.cp"
               
# line 33 "dbconn.cp"
           }
# line 33 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 33 "dbconn.cp"

	if(sqlca.sqlcode)
	{
		return -2;
	}

	return 0;

}

int dbsetconn(char *conn, char *db)
{
	
           /*
           ** SQL STATEMENT: 4
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 45 "dbconn.cp"


	CS_CHAR	dbconn[30];
	CS_CHAR dbname[20];

	
           /*
           ** SQL STATEMENT: 5
           ** EXEC SQL END DECLARE SECTION;

           */
# line 50 "dbconn.cp"

           /*
           ** Generated code ends here.
           */
# line 50 "dbconn.cp"


	strcpy(dbconn, conn);
	if(db != NULL)
		strcpy(dbname, db);

	
           /*
           ** SQL STATEMENT: 6
           ** EXEC SQL SET CONNECTION :dbconn;
           */
# line 56 "dbconn.cp"
# line 56 "dbconn.cp"
           {
# line 56 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 56 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 56 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 56 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 56 "dbconn.cp"
               {
# line 56 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 56 "dbconn.cp"
                   _sql->stmttype = SQL_SET_CONNECTION;
# line 56 "dbconn.cp"
                   _sql->connName.lnlen = CS_NULLTERM;
# line 56 "dbconn.cp"
                   strcpy(_sql->connName.last_name, dbconn);
# line 56 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 56 "dbconn.cp"
                   {
# line 56 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 56 "dbconn.cp"
                   }
# line 56 "dbconn.cp"
                   
# line 56 "dbconn.cp"
               }
# line 56 "dbconn.cp"
               
# line 56 "dbconn.cp"
           }
# line 56 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 56 "dbconn.cp"

	if(sqlca.sqlcode) {
		/* write_tdq("STEP", ERROR_LEVEL, "[%d][%s]",
			sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
		*/
		return -1;
	}

	if(db != NULL) {
		
           /*
           ** SQL STATEMENT: 7
           ** EXEC SQL USE :dbname;
           */
# line 65 "dbconn.cp"
# line 65 "dbconn.cp"
           {
# line 65 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 65 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 65 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 65 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 65 "dbconn.cp"
               {
# line 65 "dbconn.cp"
                   _sql->stmtIdlen = CS_UNUSED;
# line 65 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 65 "dbconn.cp"
                   _sql->stmttype = SQL_MISC;
# line 65 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 65 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 65 "dbconn.cp"
                   {
# line 65 "dbconn.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 65 "dbconn.cp"
                           CS_LANG_CMD, "USE @sql0_dbname ", 17, CS_UNUSED);
# line 65 "dbconn.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 65 "dbconn.cp"
                       {
# line 65 "dbconn.cp"
                           _sql->dfmtNULLCHAR.count = 0;
# line 65 "dbconn.cp"
                           _sql->dfmtNULLCHAR.maxlength = 
# line 65 "dbconn.cp"
                           _sql_MIN(256,20);
# line 65 "dbconn.cp"
                           _sql->dfmtNULLCHAR.format = CS_FMT_NULLTERM;
# line 65 "dbconn.cp"
                           _sql->dfmtNULLCHAR.status = CS_INPUTVALUE;
# line 65 "dbconn.cp"
                           _sql->retcode = ct_param(_sql->conn.command, 
# line 65 "dbconn.cp"
                               &_sql->dfmtNULLCHAR, 
# line 65 "dbconn.cp"
                           SQLNULLSTR(dbname), (CS_INT) CS_NULLTERM, 
# line 65 "dbconn.cp"
                               (CS_SMALLINT) 0);
# line 65 "dbconn.cp"
                           _sql->dfmtNULLCHAR.status = 0;
# line 65 "dbconn.cp"
                       }
# line 65 "dbconn.cp"
                       
# line 65 "dbconn.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 65 "dbconn.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 65 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 65 "dbconn.cp"
                   }
# line 65 "dbconn.cp"
                   
# line 65 "dbconn.cp"
               }
# line 65 "dbconn.cp"
               
# line 65 "dbconn.cp"
           }
# line 65 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 65 "dbconn.cp"

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
	
           /*
           ** SQL STATEMENT: 8
           ** EXEC SQL DISCONNECT ALL;

           */
# line 79 "dbconn.cp"
# line 79 "dbconn.cp"
           {
# line 79 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 79 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 79 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 79 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 79 "dbconn.cp"
               {
# line 79 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 79 "dbconn.cp"
                   _sql->stmttype = SQL_DISCONNECT_ALL;
# line 79 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 79 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 79 "dbconn.cp"
                   {
# line 79 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 79 "dbconn.cp"
                   }
# line 79 "dbconn.cp"
                   
# line 79 "dbconn.cp"
               }
# line 79 "dbconn.cp"
               
# line 79 "dbconn.cp"
           }
# line 79 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 79 "dbconn.cp"

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
	
           /*
           ** SQL STATEMENT: 9
           ** EXEC SQL BEGIN TRANSACTION;

           */
# line 101 "dbconn.cp"
# line 101 "dbconn.cp"
           {
# line 101 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 101 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 101 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 101 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 101 "dbconn.cp"
               {
# line 101 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 101 "dbconn.cp"
                   _sql->stmttype = SQL_TRANS;
# line 101 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 101 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 101 "dbconn.cp"
                   {
# line 101 "dbconn.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 101 "dbconn.cp"
                           CS_LANG_CMD, "BEGIN TRANSACTION", 17, CS_UNUSED);
# line 101 "dbconn.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 101 "dbconn.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 101 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 101 "dbconn.cp"
                   }
# line 101 "dbconn.cp"
                   
# line 101 "dbconn.cp"
               }
# line 101 "dbconn.cp"
               
# line 101 "dbconn.cp"
           }
# line 101 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 101 "dbconn.cp"

	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);	
}


int committran()
{
	
           /*
           ** SQL STATEMENT: 10
           ** EXEC SQL COMMIT TRANSACTION;

           */
# line 113 "dbconn.cp"
# line 113 "dbconn.cp"
           {
# line 113 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 113 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 113 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 113 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 113 "dbconn.cp"
               {
# line 113 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 113 "dbconn.cp"
                   _sql->stmttype = SQL_TRANS;
# line 113 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 113 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 113 "dbconn.cp"
                   {
# line 113 "dbconn.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 113 "dbconn.cp"
                           CS_LANG_CMD, "COMMIT TRANSACTION", 18, CS_UNUSED);
# line 113 "dbconn.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 113 "dbconn.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 113 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 113 "dbconn.cp"
                   }
# line 113 "dbconn.cp"
                   
# line 113 "dbconn.cp"
               }
# line 113 "dbconn.cp"
               
# line 113 "dbconn.cp"
           }
# line 113 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 113 "dbconn.cp"

	if(sqlca.sqlcode)
	{
		return(-1);
	}
	else
		return(0);	
}

int rollbacktran()
{
	
           /*
           ** SQL STATEMENT: 11
           ** EXEC SQL ROLLBACK TRANSACTION;

           */
# line 124 "dbconn.cp"
# line 124 "dbconn.cp"
           {
# line 124 "dbconn.cp"
                _SQL_CT_HANDLES * _sql;
# line 124 "dbconn.cp"
               _sqlinitctx(&_sql, CS_VERSION_110, CS_TRUE, &sqlca, (long 
# line 124 "dbconn.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 124 "dbconn.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 124 "dbconn.cp"
               {
# line 124 "dbconn.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 124 "dbconn.cp"
                   _sql->stmttype = SQL_TRANS;
# line 124 "dbconn.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 124 "dbconn.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 124 "dbconn.cp"
                   {
# line 124 "dbconn.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 124 "dbconn.cp"
                           CS_LANG_CMD, "ROLLBACK TRANSACTION", 20, CS_UNUSED);
# line 124 "dbconn.cp"
                       
# line 124 "dbconn.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 124 "dbconn.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 124 "dbconn.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 124 "dbconn.cp"
                   }
# line 124 "dbconn.cp"
                   
# line 124 "dbconn.cp"
               }
# line 124 "dbconn.cp"
               
# line 124 "dbconn.cp"
           }
# line 124 "dbconn.cp"
           

           /*
           ** Generated code ends here.
           */
# line 124 "dbconn.cp"

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

           /*
           ** Generated code begins here.
           */
# line 224 "dbconn.cp"

           /*
           ** Generated code ends here.
           */
# line 224 "dbconn.cp"

