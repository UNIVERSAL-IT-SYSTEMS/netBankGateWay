#ifndef _MYSOCK
#define _MYSOCK

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#ifndef _UCHAR
#define _UCHAR
typedef unsigned char uchar;
#endif

#ifndef _UINT
#define _UINT
typedef unsigned int uint;
#endif

#ifndef _ULONG
#define _ULONG
typedef unsigned long ulong;
#endif

#define sockOpenFail	-201
#define sockBindFail	-202
#define sockGetSockName	-203
#define sockSendFail	-204
#define sockRecvFail	-205
#define sockUnknowHost 	-206
#define sockConnectFail	-207
#define sockAcceptFail	-208
#define sockRecvTimeOut -209
#define sockWriteFail   -210  
#define sockReadFail    -211
#define DBCONNECTERR    -220
#define CICSWRITEERR    -222
#define DBACCESSERR     -277
#define DBACCESSTRCDERR -289
#define PASSWDERR       -299
 
#define CIDBHost         "localhost"
#define STOCKHost        "localhost"
#define iCGISockPort     3777   /*’˝ Ω3777 ≤‚ ‘3666*/
#define iDBSockPort      3490
#define iSTOCKSockPort 3977
#define iBuffSize        4096
#define iServerLen       64
#define MIDAD "182.59.26.211"
#define MIDPT 7396
#define WHADD "182.59.26.29"
#define WHPT 1700
#define JJADD "182.59.26.44"
#define JJPT 7888

#define iTimeOut         20

#define psSaveHostAddr  "localhost"
#define psCIDBHostAddr  "localhost"

int sockServerOpen( int sinPort );
int sockClientOpen( char *pszHost, int sinPort );
int sockClose( int sHandle );
int sockSendBuf( int sHandle, char *psBuf, uint uiLen );
int sockRecvBuf( int sHandle, char *psBuf, uint uiMaxLen, uint uiTimeOut );
int sockListen( int sHandle );

#endif
