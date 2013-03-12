/*-------------------------------------
 *
 * ����Сдת��
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define TRUE	1
#define	FALSE	0

/*------------------------------------------------------------
 * covmoney : �����ת��Ϊ��д
 *-----------------------------------------------------------*/
char	*covmoney(double money, int *length)
{
	static	char	str[61];
	char	buf[16],power[3];
	int	i,position,flag0;

	position = 0;
	sprintf(buf,"%15.2f",money);
	for(i = 0; i < 60; i++)
		str[i] = ' ';
	str[60] = NULL;
	for(i = 0; buf[i] == ' '; i++)
		;
	while(i <= 14)
	{
		flag0 = TRUE;
		switch(i)
		{
			case 0: case 4: case 8:
				sprintf(power,"Ǫ");
				break;
			case 1: case 5: case 9:
				sprintf(power,"��");
				break;
			case 2: case 6: case 10:
				sprintf(power,"ʰ");
				break;
			case 3:
				sprintf(power,"��");
				if(buf[i] == '0')
				{
					str[position] = power[0];
					str[position+1] = power[1];
					position += 2;
					goto	next;
				}
				break;
			case 7:
				sprintf(power,"��");
				if(buf[i] == '0')
				{
					str[position] = power[0];
					str[position+1] = power[1];
					position += 2;
					goto	next;
				}
				break;
			case 11:
				sprintf(power,"Ԫ");
				if(buf[i] == '0' && position != 0)
				{
					str[position] = power[0];
					str[position+1] = power[1];
					position += 2;
					goto	next;
				}
				break;
			case 12:
				flag0 = FALSE;
				if(buf[i+1] == '0' && buf[i+2]=='0')
				{
					sprintf(power,"��");
					str[position] = power[0];
					str[position+1] = power[1];
					position += 2;
					goto	outloop;
				}
				break;
			case 13:
				sprintf(power,"��");
				break;
			case 14:
				if(buf[i] == '0')
					goto	outloop;
				sprintf(power,"��");
				break;
		}
		if(flag0 == TRUE)
		    if(i > 0)
			position += covmoney_join(str, power, buf[i], \
				buf[i+1], position);
		    else
			position += covmoney_join(str, power, buf[i], \
				buf[i], position);
	next:
		i++;
	}
outloop:
	str[position] = NULL;
	if(length != (int *)NULL)
		*length = position;
	return(str);
}

covmoney_join(char *buff, char *string, char digit, char nextdig, int pos)
{
	char	dig[3];
	int	flag0;

	flag0 = TRUE;
	switch(digit)
	{
		case '0':
			if(nextdig != '0')
				sprintf(dig,"��");
			else
				flag0 = FALSE;
			break;
		case '1': sprintf(dig,"Ҽ"); break;
		case '2': sprintf(dig,"��"); break;
		case '3': sprintf(dig,"��"); break;
		case '4': sprintf(dig,"��"); break;
		case '5': sprintf(dig,"��"); break;
		case '6': sprintf(dig,"½"); break;
		case '7': sprintf(dig,"��"); break;
		case '8': sprintf(dig,"��"); break;
		case '9': sprintf(dig,"��"); break;
	}
	if(digit == '0')
	{
		if(flag0 == TRUE)
		{
			buff[pos] = dig[0];
			buff[pos + 1] = dig[1];
			return(2);
		}
		else
			return(0);
	}
	else
	{
		buff[pos] = dig[0];
		buff[pos + 1] = dig[1];
		buff[pos + 2] = string[0];
		buff[pos + 3] = string[1];
		return(4);
	}
}
