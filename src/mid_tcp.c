#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <signal.h>

#include <time.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define  PACKET            256             /*传送一次的长度*/
#define  COMM_LEN          4096            /*和网点通讯传送长度*/
#define  TA_DATA           2
#define  TA_ACK            3
#define  TA_CTL            4
#define  TCP_READ_TIMEOUT  30             /*TCP接收数据最大延迟秒数*/

void tcp_close(int fd)
{
   struct linger  Linger;

   Linger.l_onoff = 1;
   Linger.l_linger = 0;
   setsockopt(fd, SOL_SOCKET, SO_LINGER, (char *)&Linger,
             sizeof(Linger));
   close(fd);
}

long longchg(long l)
  {
  char *sl;
  long x;
  char c;

  x = l;
  sl = (char *)&x; 
  c = sl[0];
  sl[0] = sl[3];
  sl[3] = c;
  c = sl[1];
  sl[1] = sl[2];
  sl[2] = c;
  return(x);
  }
int mid_tcp( char * ipaddr,int port,char * mgid,char  *inbuf,int inlen,char  *outbuf,int * outlen)
   {
   int    clientfd;

   /*建立连接*/
   clientfd = tcp_client_init(ipaddr ,(int ) port);
   if (clientfd < 0)
      {
      printf("tcp_client_init error!\n");
      memcpy(mgid,"0001",4);
      return(-1);
      }

   if (writesock(clientfd,inbuf,inlen) != inlen)
     {
      printf("writesock error!\n");
      memcpy(mgid,"0002",4);
      tcp_close(clientfd);
      return(-2) ;
     }

  *outlen = readsock(clientfd,outbuf); 
  if (*outlen < 0) 
     {
      printf("readsock error! return[%d]\n",*outlen);
      memcpy(mgid,"0003",4);
      tcp_close(clientfd);
      return(-3);
     }

   /*close tcp connect*/
   memcpy(mgid,"0000",4);
   tcp_close(clientfd);
   return(0);
   }


int tcp_client_init(char *seraddr, int port)
  {
  struct sockaddr_in serv_addr;
  int    socketfd;
  
  memset((char *)&serv_addr,0,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(seraddr);
  serv_addr.sin_port   = htons(port);
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
      {
      return(-2);
      }
  
  if (connect(socketfd, (struct sockaddr *)&serv_addr,
                             sizeof(serv_addr)) < 0)
     {
     tcp_close(socketfd);
     return(-3);
     }
   return(socketfd);
   }

int  tcp_write(int fd, char *buf, int len)
  {
  int n, k, i;

  n = 0;
  while (1)
    {
    k = len - n;
    if (k == 0)
        break;
    i = send(fd, &buf[n], k, 0);
    if (i < 0)
       {
       n = -1;
       break;
       }
    n = n + i;
    }
  return(n);
  }

int  tcp_read(int fd, char *buf, unsigned long len, long timeout)
  {
  int n, k, i;

  n = 0;
  while (1)
    {
    k = (int)len - n;
    if (k == 0)
        break;
    i = recv(fd, &buf[n], k, 0);
    if (i <= 0)
       {
       break;
       }
    n = n + i;
    }
  return(n);
 }

int	readline (fd,ptr, maxlen)
	int    fd;
	char   *ptr;
	int	maxlen;
{
	int	n,rc ;
	char    c;

	for (n=1; n <= maxlen; n++) {

/*		if ((rc=read(fd,&c,1)) ==1) {*/
		if ((rc=recv(fd,&c,1,0)) ==1) {
			*ptr++ = c;
			if (c == '\n')
			   break ;
		}else if (rc == 0) {
		      if (n == 1)
			return (0) ;
		      else
			break;
		}else
			return(-1) ;
	}
	*ptr='\0';
	return(n-1);
}
int writesock(int sock, char *buf, int len)
{
    int ptr, k, l;
    char lbuf[PACKET+10];
    long len1;
    FILE *fp;

    ptr = 0;

    lbuf[0] = TA_DATA;
    while (len)
    {
        if (len > PACKET)
           k = PACKET;
        else
           k = len;
        /*
        len1 = longchg(len);
        */
        len1 = htonl(len);
        memcpy(&lbuf[1], &len1, sizeof(long));
        memcpy(&lbuf[1 + sizeof(long)], buf + ptr, k);
        l = 1 + sizeof(long) + k;
        fp=fopen("/tmp/8581.log","a");
        fprintf(fp,"tcp=[%s]\n",lbuf);
        fclose(fp);
        if(tcp_write(sock, lbuf, l) != l)
            return -1;
        len -= k;
        ptr += k;
    }
    return(ptr);
}

int readsock(int sock,char *buf)
{
    char  c;
    int   ptr,k,len, len1;

    ptr = 0;
    len = PACKET + 1;
    while(len > PACKET)
       {
        k = tcp_read(sock,&c,1, TCP_READ_TIMEOUT);
        if ((k != 1) || (c != TA_DATA))
            {
            printf("read_first char(%d)(%x)\n", k, c);
            return -1;
            }
        k = tcp_read(sock,(char *)&len,sizeof(long), TCP_READ_TIMEOUT);
        if (k < sizeof(long))
            {
            printf("read long(%d)\n", k);
            return -2;
            }
        /*
        len = longchg(len);
        */
        len = ntohl(len);
        if(len > COMM_LEN)
          return -3;
        if (len > PACKET)
           len1 = PACKET;
        else
           len1 = len;
        k = tcp_read(sock, buf + ptr, len1, TCP_READ_TIMEOUT);
        if (k != len1)
           return -4;
        ptr += k;
     }
  return(ptr);
}
