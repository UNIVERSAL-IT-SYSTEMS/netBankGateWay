/*-------------------------------------
 *
 * Ê±¼äº¯Êý 
 * 	Coded by Friar 2001.
 * 	All rights reserved.
 *
 *------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "error.h"

int
date_is_valid(long date)
{
	int	year;
	int	month;
	int	day;

	if (date < 0)
		return RETURN_NOT;

	year  = (int)(date / 10000);
	month = (int)((date / 100) % 100);
	day   = (int)(date % 100);

	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)	return RETURN_NOT;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)	return RETURN_NOT;
			break;
		case 2:
			if (day > 29) 	return RETURN_NOT;
			else if (day == 29 && year % 400 != 0 && 
				(year % 4 != 0 || year % 100 == 0))
				return RETURN_NOT;
			break;
		default:
			return RETURN_NOT;
			break;
	}

	return RETURN_YES;
}

int
time_is_valid(long time)
{	
	int	hour;
	int	minute;
	int	second;

	if (time < 0)
		return RETURN_NOT;

	hour   = (int)(time / 10000);
	minute = (int)((time / 100) % 100);
	second = (int)(time % 100);

	if (minute > 59 || second > 59 || hour > 23)
		return RETURN_NOT;

	return RETURN_YES;
}

long
get_sys_date(void)
{
	time_t	tt;
	struct	tm 	*tim;
	long	ldate;

	time(&tt);
	tim = localtime(&tt);

	ldate =	(tim->tm_year + 1900) * 10000 + 
		(tim->tm_mon + 1) * 100  + 
		(tim->tm_mday);

	return ldate;
}

long
get_sys_time(void)
{
	time_t	tt;
	struct	tm	*tim;
	long	ltime;

	time(&tt);
	tim = localtime(&tt);

	ltime = (tim->tm_hour * 10000) +
		(tim->tm_min  * 100) +
		(tim->tm_sec);

	return ltime;
}

long
diff_date(char *strdate, int diffdays)
{
/*--------------------------------------
	struct	tm	tim;
	time_t	now;
---------------------------------------*/
	time_t	result;
	long	newdate;
	long	date;
	int	year;
	int	month;
	int	day;
	struct	tm	tim;

	date = atol(strdate);

	if (date_is_valid(date) != RETURN_YES) 
		return -1;

	year = (date / 10000);
	month = ((date / 100) % 100);
	day   = (date % 100);
	
	memset(&tim, 0, sizeof(tim));

	tim.tm_sec = 0;
	tim.tm_min = 0;
	tim.tm_hour = 0;
	/* tim.tm_mday = day - diffdays; */
	tim.tm_mday = day;
	tim.tm_mon = month - 1;
	tim.tm_year = year - 1900;
	
/*-----------------------------------------------
	time(&now);
	tim = *localtime(&now);
	tim.tm_mday = tim.tm_mday - diffdays;
------------------------------------------------*/

	if ((result = mktime(&tim)) != (time_t) -1) {
		result = result - diffdays * 3600 * 24;
		tim = *localtime(&result);
		newdate = (tim.tm_year + 1900) * 10000 +
			  (tim.tm_mon + 1) * 100 +
			  (tim.tm_mday);
		return newdate;
	}
	else
		return -1;
	
}

long
date_interval(char *date1, char *date2)
{
	struct	tm	t1;
	struct	tm	t2;
	long	d1;
	long	d2;
	int	year;
	int	month;
	int	day;
	time_t	tt1;
	time_t	tt2;
	long	interval;
	
	d1 = atol(date1);
	d2 = atol(date2);

	/*---------------------------------------------
	if (!date_is_valid(d1) || !date_is_valid(d2))
		return 0;
	 *--------------------------------------------*/
	memset(&t1, 0, sizeof(t1));
	memset(&t2, 0, sizeof(t2));
	
	year = (d1 / 10000);
	month = ((d1 / 100) % 100);
	day   = (d1 % 100);
	t1.tm_sec = 0;
	t1.tm_min = 0;
	t1.tm_hour = 0;
	t1.tm_mday = day;
	t1.tm_mon = month - 1;
	t1.tm_year = year - 1900;
	
	tt1 = mktime(&t1);

	year = (d2 / 10000);
	month = ((d2 / 100) % 100);
	day   = (d2 % 100);
	t2.tm_sec = 0;
	t2.tm_min = 0;
	t2.tm_hour = 0;
	t2.tm_mday = day;
	t2.tm_mon = month - 1;
	t2.tm_year = year - 1900;
	
	tt2 = mktime(&t2);

	interval = abs((long)tt1 - (long)tt2) / (3600 * 24);

	return interval;
}
