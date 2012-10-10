/******************************************************************************
		Copyright(C) Recency TechInfo Co., Ltd. All Right Reserved

		文 件 名:	s_tcpfunc.c                       
		版本信息:	version4.1.0
		编 写 者:	成都润信科技发展有限公司             
		时间地点:	200304	重庆
		
		程序功能:	socket通信的连接, 发送和接收

		开发历史:
******************************************************************************/

#define		EXTERN
#include	"s_tool.h"
#include	"netbank_mid.h"

/*****************************************************************************
	全局变量
*****************************************************************************/
int	g_isock = 0;


/*****************************************************************************
	函数定义区
*****************************************************************************/
void	rv_timeout();


/*****************************************************************************
	函数名称:	rv_timeout()
	函数功能:	读取企业返回数据时的超时处理
	入口参数:	
	出口参数:	
	
*****************************************************************************/
void	rv_timeout()
{
	close(g_isock);
}

/*****************************************************************************
	函数名称:	ri_tcpconnect()
	函数功能:	建立与指定地址,端口号的联接
	入口参数:	ps_addr, pi_port
	出口参数:	pi_sock
*****************************************************************************/

short	ri_tcpconnect(pi_sock, ps_addr, pi_port)
	int		*pi_sock;
	char	*ps_addr;
	ushort   pi_port;
{
	int		isock = 0;
	short	nret = 0;
	ulong	laddr = 0;
	struct	sockaddr_in	st_add;

	isock = socket(AF_INET, SOCK_STREAM, 0);
	if (isock < 0) {
		flog( YBSLOG, "打开套接字错:%d", errno);
		return (isock);
	}

	laddr = inet_addr(ps_addr);

	st_add.sin_family = AF_INET;
	memcpy(&st_add.sin_addr.s_addr, &laddr, sizeof(long));
	st_add.sin_port = htons(pi_port);		

flog(YBSLOG, "pi_port = %d", pi_port );

	nret = connect(isock, (struct sockaddr *) &st_add, sizeof st_add);
	if(nret<0) 
	{
		flog ( YBSLOG, "建立联接错:%d", errno ) ;
		close(isock);
		return ( nret ) ;
	}
	else 
	{
		*pi_sock = isock;
		flog(YBSLOG, "建立SOCK[%ld]成功", isock);
		return( 0 );
	}
}

/*****************************************************************************
	函数名称:	ri_tcpread()
	函数功能:	读指定字节数的流
	入口参数:	pi_sock, ps_str, pi_num
	出口参数:	ps_str
*****************************************************************************/

short	ri_tcpread(pi_sock, ps_str, pi_num, pi_timeout)
	int		pi_sock;
	char	*ps_str;
	short	pi_num;
	short	pi_timeout;
{
	short	ileft, iread;
	char	sztcp[11], szlog[1024];

	ileft = 0;
	iread = 0;
	memset(sztcp, 0, sizeof(sztcp));
	memset(szlog, 0, sizeof(szlog));

	g_isock = pi_sock;
	strcpy(sztcp, "tcp");		

	alarm(pi_timeout);
	signal(SIGALRM, (void(*)())rv_timeout);
	
	ileft = pi_num;
	while (ileft > 0) 
	{
		iread = read(pi_sock, ps_str, ileft);

		if(iread < 0 )
			return(iread);

		else 
			if(iread == 0)
		 		break;


		ileft -= iread;
		ps_str += iread;
	}
	alarm(0);

	if(ileft > 0)
		return(-1);

	return(0);
}

/*****************************************************************************
	函数名称:	ri_tcpwrite()
	函数功能:	写指定字节数的流
	入口参数:	pi_sock, ps_str, pi_num
	出口参数:	
*****************************************************************************/

short	ri_tcpwrite(pi_sock, ps_str, pi_num)
	int		pi_sock;
	short	pi_num;
	char	*ps_str;
{
	short	ileft, iwrite;
	
	ileft = 0;
	iwrite = 0;

	ileft = pi_num;
	while (ileft > 0) {
		iwrite = write(pi_sock, ps_str, ileft);
		if (iwrite < 0)
			return (iwrite); 

		ileft -= iwrite;
		ps_str += iwrite;
	}

	return (0);
}
