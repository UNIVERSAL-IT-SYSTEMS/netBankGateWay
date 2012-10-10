#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sybhesql.h>
#include "error.h"
#include "TRNFLW.h"
#include "ebankdg.h"
#include "miscfunc.h"
#include "netbank_mid.h"

int	connect_db(void)
{
	int	ret;
	char	user_name[100];
	char	pass_word[100];
	char	db_name[100];

/*
	flog(INFO_LEVEL, "�������ļ���ȡ���ݿ�������Ϣ");
	flog(STEP_LEVEL, "ȡ������Ŀ[USER_NAME]");
*/
	ret = get_config_value(CONFIG_FILE_NAME, "USER_NAME", user_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "ȡ������Ŀ[USER_NAME]ʧ��"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
/*
	flog(STEP_LEVEL, "USER_NAME = [%s]", user_name);
	flog(STEP_LEVEL, "ȡ������Ŀ[PASS_WORD]");
*/
	ret = get_config_value(CONFIG_FILE_NAME, "PASS_WORD", pass_word);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "ȡ������Ŀ[PASS_WORD]ʧ��"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
/*
	flog(STEP_LEVEL, "PASS_WORD  = [%s]", pass_word);
	flog(STEP_LEVEL, "ȡ������Ŀ[DB_NAME]");
*/
	ret = get_config_value(CONFIG_FILE_NAME, "DB_NAME", db_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "ȡ������Ŀ[DB_NAME]ʧ��"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
/*
	flog(STEP_LEVEL, "DB_NAME  = [%s]", db_name);
*/

	ret = dbconn(user_name, pass_word, db_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "�������ݿ�ʧ��"
			" [%s][%d]", __FILE__, __LINE__);
		return EC_CONNECT_DB_ERROR;
	}

	return RETURN_OK;
}
