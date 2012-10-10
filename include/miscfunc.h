#ifndef _LIB_MISC_H
#define _LIB_MISC_H

/* fstring.c */
extern	void	zmemcpy	(char *s1,  char *s2, int len);
extern	char*	ltrimlen(char *str, int len);
extern	char*	rtrimlen(char *str, int len);
extern	char*	trimlen (char *str, int len);
extern	char*	ltrim   (char *str);
extern	char*	rtrim	(char *str);
extern	char*	trim	(char *str);


/* fipc.c */
extern	int	start_msg(long key);
extern	int	send_msg (char *msg, long mtype, int msgid);
extern	int	read_msg (char *msg, long mtype, int msgid);
extern	void	close_msg(int msgid);

/* ftcp.c */
extern	int	tcp_cli_open  (char *hostname, char *portname);
extern	int	tcp_cli_send  (int sock, char *mesg, int len, int timeout);
extern	int	tcp_cli_recv  (int sock, char *mesg, int len, int timeout);
extern	int	tcp_cli_close (int sock);
extern	int	tcp_svr_open  (char *hostname, char *portname);
extern	int	tcp_svr_accept(int sock);
extern	int	tcp_svr_send  (int newsock, char *mesg, int len,int timeout);
extern	int	tcp_svr_recv  (int newsock, char *mesg, int len,int timeout);
extern	int	tcp_svr_close (int sock);
extern	char*	tcp_err(void);

/* fmoney.c */
extern	char*	covmoney(double	money, int *length);

/* ffile.c */
extern	long	fp_length(FILE *fp);
extern	long	fn_length(char *fn);
extern	int	file_is_exist(const char *filename);

/* ftime.c */
extern	int	date_is_valid(long date);
extern	int	time_is_valid(long time);
extern	long	get_sys_date(void);
extern	long	get_sys_time(void);
extern	long	diff_date(char *date, int day);
extern	long	date_interval(char *d1, char *d2);
extern	char*	get_str_date(void);
extern	char*	get_str_time(void);

/* fconfig.c */
extern	int	get_config_value(char *fn, char *cn, char *cv);

/* ferror.c */
extern	char*	get_errcode_msg(int errcode);

/* flog.c */
extern	void	flog(int level, char *fmt, ...);
extern	void	fhlog(char *str, int len);

#endif
