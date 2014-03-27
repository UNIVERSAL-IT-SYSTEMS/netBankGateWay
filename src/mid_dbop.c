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

	flog(INFO_LEVEL, "读配置文件，取数据库配置信息");
	flog(STEP_LEVEL, "取配置项目[USER_NAME]");
	ret = get_config_value(CONFIG_FILE_NAME, "USER_NAME", user_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "取配置项目[USER_NAME]失败"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
	flog(STEP_LEVEL, "USER_NAME = [%s]", user_name);

	flog(STEP_LEVEL, "取配置项目[PASS_WORD]");
	ret = get_config_value(CONFIG_FILE_NAME, "PASS_WORD", pass_word);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "取配置项目[PASS_WORD]失败"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
	flog(STEP_LEVEL, "PASS_WORD  = [%s]", pass_word);

	flog(STEP_LEVEL, "取配置项目[DB_NAME]");
	ret = get_config_value(CONFIG_FILE_NAME, "DB_NAME", db_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "取配置项目[DB_NAME]失败"
			" [%s][%d]", __FILE__, __LINE__);
		return ret;
	}
	flog(STEP_LEVEL, "DB_NAME  = [%s]", db_name);

	ret = dbconn(user_name, pass_word, db_name);
	if (ret != RETURN_OK) {
		flog(ERROR_LEVEL, "联接数据库失败"
			" [%s][%d]", __FILE__, __LINE__);
		return EC_CONNECT_DB_ERROR;
	}

	return RETURN_OK;
}

/* End of this file */
