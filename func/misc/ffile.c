/*-------------------------------------
 *
 * 文件操作函数
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "error.h"

long
fp_length(FILE *fp)
{
	long	offset;
	long	length;

	offset = ftell(fp);
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	fseek(fp, offset, SEEK_SET);

	return length;
}

long
fn_length(char *filename)
{
	long	length;
	FILE	*fp;

	if (filename == NULL)
		return -1;
	
	if ((fp = fopen(filename, "r")) == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	length = ftell(fp);

	fclose(fp);

	return length;
}

int
file_is_exist(const char *filename)
{
	if (access(filename, F_OK | W_OK) == 0)
		return RETURN_YES;
	else
		return RETURN_NOT;
}
