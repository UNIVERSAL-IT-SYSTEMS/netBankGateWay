/*-------------------------------------
 *
 * ×Ö·û´®²Ù×÷º¯Êý 
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define WHITES	" \n\t\r"

/*--------------------------------------------
 * zmemcpy : memcpy and put terminate char
 *-------------------------------------------*/
void
zmemcpy(char *s1, char *s2, int	len)
{
	memcpy(s1, s2, len);
	*(s1 + len) = 0;

	return;
}

/*-------------------------------------------
 * is_white : ¼ì²éÒ»×Ö·ûÊÇ·ñÊÇ¶¨ÒåµÄ¿Õ°××Ö·û
 *------------------------------------------*/
static int
is_white(char ch, char *whites)
{
	int	len = 0;

	while (*(whites + len)) {
		if (ch == *(whites + len))
			return 1;
		len ++;
	}
	
	return 0;
}

/*--------------------------------------------
 * ltrimlen : È¥³ýÒ»×Ö·û´®×ó±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
ltrimlen(char *str, int len)
{
	int	i = 0;
	char	temp[5000];
	
	while (is_white(*(str + i), WHITES) && i < len)
		i ++;

	if (i == len) {
		*str = 0;
		return NULL;
	} else {
		zmemcpy(temp, str + i, len -i);
		strcpy(str, temp);
		return str;
	}
}

/*--------------------------------------------
 * rtrimlen : È¥³ýÒ»×Ö·û´®ÓÒ±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
rtrimlen(char *str, int len)
{
	int	i = len - 1;
	
	while (is_white(*(str + i), WHITES) && i >= 0) 
		i --;

	if (i == -1) {
		*str = 0;
		return NULL;
	} else {
		*(str + i + 1) = 0;
		return str;
	}
}

/*--------------------------------------------
 * trimlen : È¥³ýÒ»×Ö·û´®Á½±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
trimlen(char *str, int len)
{

	ltrimlen(str, len);
	rtrimlen(str, strlen(str));

	return str;
}

/*--------------------------------------------
 * trim: È¥³ýÒ»×Ö·û´®Á½±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
trim(char *str)
{
	ltrimlen(str, strlen(str));
	rtrimlen(str, strlen(str));

	return str;
}

/*--------------------------------------------
 * ltrim: È¥³ýÒ»×Ö·û´®×ó±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
ltrim(char *str)
{
	ltrimlen(str, strlen(str));

	return str;
}

/*--------------------------------------------
 * rtrim: È¥³ýÒ»×Ö·û´®ÓÒ±ßµÄ¿Õ×Ö·û
 *-------------------------------------------*/
char *
rtrim(char *str)
{
	rtrimlen(str, strlen(str));

	return str;
}
