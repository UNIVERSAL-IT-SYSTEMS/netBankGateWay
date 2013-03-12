/*-------------------------------------
 *
 * ȡ�����ļ���������Ŀ����
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

/* ������fstring.c�ļ��� */
extern	char*	trim(char *);

/*---------------------------------------------------------------------
 * get_config_vlaue : �������ļ���ȡ��ĳ������Ŀ������
 *--------------------------------------------------------------------*/
int
get_config_value(char *config_file_name, char *config_name, char *config_value)
{
	int	ret;
	char	line[300];
	FILE*	fp;
	char	flag;

	/* ���������Ϊ��ʱ,��������,���� */
	if (config_file_name == NULL || config_name == NULL ||
	    config_value == NULL     || strlen(config_name) == 0)
		return EC_NULL_PARA_ERROR;
	
	/* �������ļ� */
	if ((fp = fopen(config_file_name, "r")) == NULL) 
		return EC_OPEN_FILE_ERROR;
	
	flag = '0';
	fgets(line, 300, fp);
	while (!feof(fp)) {
		delnote(line);
		if (memcmp(line, config_name, strlen(config_name)) == 0) {
			get_item_value(line, config_value);
			flag = '1';
			break;
		}
		fgets(line, 300, fp);
	}

	fclose(fp);
	if (flag == '0')
		return EC_UNDEF_SYM_ERROR;
	else	
		return 0;
}

static int
delnote(char *line)
{
	int	len;
	int	i;

	len = strlen(line);
	for (i = 0; i < len; i ++) {
		if (*(line + i) == '#') {
			*(line + i) = 0;
			break;
		}
	}

	return RETURN_OK;
}

static int
get_item_value(char *line, char *dest)
{
	int	i;
	int	len;

	len = strlen(line);
	for (i = 0; i < len; i ++)
		if (*(line + i) == '=')
			break;
	
	strcpy(dest, line + i + 1);
	trim(dest);

	return RETURN_OK;
}
