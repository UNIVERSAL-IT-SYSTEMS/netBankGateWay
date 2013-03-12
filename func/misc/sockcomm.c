/**********************************************************
 Sockcomm.c
   This API is used in UNIX
 Modified by helen at 07/21/1998
***********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "sockcomm.h"
#include <varargs.h>

#include <fcntl.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf tohere1;

static void alrm1( void )
{
   longjmp( tohere1, 1 );
}

/*****************************************************************************
 Function    :   create a socket for server 
 Param In    : 
    sinPort  :   socket port 
 Param Out   :   none
 Return Code :
    >=0      :   OK, return a descriptor referencing socket  
    <0       :   sockOpenFail
                 sockBindFail
                 sockGetSockName
*****************************************************************************/ 
int sockServerOpen( int sinPort )
{
   int sHandle;
   int iLen;
   struct sockaddr_in server;

   if( ( sHandle = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) 
   {
      return (sockOpenFail);
   }

   server.sin_family = AF_INET;
   server.sin_addr.s_addr = htonl(INADDR_ANY);
   server.sin_port = htons(sinPort);

   if( bind( sHandle, ( struct sockaddr * )&server, sizeof(server) ) < 0 ) 
   {
      return (sockBindFail);
   }


   iLen = sizeof( server );
   if( getsockname( sHandle,( struct sockaddr * )&server, &iLen ) < 0 ) 
   {
      return (sockGetSockName);
   }

   listen( sHandle, 5 );

   return (sHandle);
}

/*****************************************************************************
 Function    :   create a socket for client 
 Param In    : 
    pszHost  :   server's name for connecting 
    sinPort  :   server's socket port 
 Param Out   :   none
 Return Code :
    >=0      :   OK, return a descriptor referencing socket  
    <0       :   sockOpenFail
                 sockUnknowHost
                 sockConnectFail
*****************************************************************************/ 
int sockClientOpen( char *pszHost, int sinPort )
{
   int sHandle;
   struct sockaddr_in server;
   struct hostent *hp,*gethostbyname();

   if( ( sHandle = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) 
   {
      return (sockOpenFail);
   }

   server.sin_family=AF_INET;
   if( ( hp = gethostbyname( pszHost ) ) == NULL ) 
   {
      if( ( hp = gethostbyaddr(pszHost,strlen(pszHost),SOCK_STREAM) ) == NULL )
      {
         return (sockUnknowHost);
      }
   }
   memcpy( (char *)&server.sin_addr, (char *)hp->h_addr, hp->h_length );
   server.sin_port = htons(sinPort);

   if( connect( sHandle, (struct sockaddr *)&server, sizeof(server) ) < 0 ) 
   {
      return (sockConnectFail);
   }
   return( sHandle );
}


/*****************************************************************************
 Function    :   close a socket 
 Param In    : 
    sHandle  :   a descriptor referencing socket
 Param Out   :   none
 Return Code :
    =0       :   OK
*****************************************************************************/ 
int sockClose( int sHandle )
{
   close( sHandle );
   return( 0 );
}


/*****************************************************************************
Function     :   send information through a socket by connecting 
Param In     : 
   sHandle   :   a descriptor referencing socket
   psBuf     :   information by sent
   uiLength  :   size of information
 Param Out   :   none
 Return Code :
    =0       :   OK
    <0       :   sockSendFail
*****************************************************************************/ 
int sockSendBuf( int sHandle, char *psBuf, uint uiLength )
{
   int iRet;
   iRet = send( sHandle, psBuf, uiLength, 0 );
   if( iRet < 0 )  return( sockSendFail );
   return( 0 );

}


/*****************************************************************************
Function     :   receive information through a socket by connecting 
Param In     : 
   sHandle   :   a descriptor referencing socket
   uiMaxLen  :   max size of information
 Param Out   :   
   psBuf     :   information by sent
 Return Code :
    >=0      :   OK, return size of information by received
    <0       :   sockRecvTimeOut
                 sockRecvFail
*****************************************************************************/ 
int sockRecvBuf( int sHandle, char *psBuf, uint uiMaxLen, uint uiTimeOut )
{
   
   int iLen;
   
   if( setjmp( tohere1 ) )   return (sockRecvTimeOut);
   signal( SIGALRM, alrm1 );
   alarm( uiTimeOut );

   memset(psBuf,'\0',uiMaxLen);
   iLen = recv( sHandle, psBuf, uiMaxLen,0 );
   
   printf("sockreclen  [%d]\n",iLen);
   
   if (iLen < 0 ) 
   {
      alarm( 0 );
      return (sockRecvFail);
   }
   alarm(0);
   return (iLen);
}


/*****************************************************************************
Function     :   accept a connection on a socket for server 
Param In     : 
   sHandle   :   a descriptor referencing socket
 Param Out   :   none 
 Return Code :
    >=0      :   OK, return a descriptor for the accepted socket 
    <0       :   sockAcceptFail
*****************************************************************************/ 
int sockListen( int sHandle )
{
   int iSock;

   iSock = accept( sHandle, ( struct sockaddr * )NULL, ( int * )NULL );
   if ( iSock == -1 ) 
   {
      return(sockAcceptFail);
   }
   return (iSock);
}


void vPrtErrMsg( va_alist )
{
   FILE *fp;
   char *fmt;
   va_list args;

   fp = fopen( "errorlog.dat", "a+" );
  
   va_start( args );
   fmt = va_arg( args, char * );
   ( void )   vfprintf( fp, fmt, args );
   va_end( args );
   fclose( fp );
}


