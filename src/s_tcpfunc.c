/******************************************************************************
		Copyright(C) Recency TechInfo Co., Ltd. All Right Reserved

		�� �� ��:	s_tcpfunc.c                       
		�汾��Ϣ:	version4.1.0
		�� д ��:	�ɶ����ſƼ���չ���޹�˾             
		ʱ��ص�:	200304	����
		
		������:	socketͨ�ŵ�����, ���ͺͽ���

		������ʷ:
******************************************************************************/

#define		EXTERN
#include	"s_tool.h"
#include	"netbank_mid.h"

/*****************************************************************************
	ȫ�ֱ���
*****************************************************************************/
int	g_isock = 0;


/*****************************************************************************
	����������
*****************************************************************************/
void	rv_timeout();


/*****************************************************************************
	��������:	rv_timeout()
	��������:	��ȡ��ҵ��������ʱ�ĳ�ʱ����
	��ڲ���:	
	���ڲ���:	
	
*****************************************************************************/
void	rv_timeout()
{
	close(g_isock);
}

/*****************************************************************************
	��������:	ri_tcpconnect()
	��������:	������ָ����ַ,�˿ںŵ�����
	��ڲ���:	ps_addr, pi_port
	���ڲ���:	pi_sock
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
		flog( YBSLOG, "���׽��ִ�:%d", errno);
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
		flog ( YBSLOG, "�������Ӵ�:%d", errno ) ;
		close(isock);
		return ( nret ) ;
	}
	else 
	{
		*pi_sock = isock;
		flog(YBSLOG, "����SOCK[%ld]�ɹ�", isock);
		return( 0 );
	}
}

/*****************************************************************************
	��������:	ri_tcpread()
	��������:	��ָ���ֽ�������
	��ڲ���:	pi_sock, ps_str, pi_num
	���ڲ���:	ps_str
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
		flog ( YBSLOG, "read sock[%ld] len:%d", pi_sock, iread);
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
	��������:	ri_tcpwrite()
	��������:	дָ���ֽ�������
	��ڲ���:	pi_sock, ps_str, pi_num
	���ڲ���:	
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
