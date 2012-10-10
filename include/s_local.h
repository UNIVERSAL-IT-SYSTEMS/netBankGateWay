#ifndef _S_LOCAL_H__
#define _S_LOCAL_H__

#ifdef  __cplusplus
extern  "C"
{
#endif


long rl_StopService(char *in_sProgName);
int rv_ParseCmdLine(int argc, char *argv[]);
short   ri_tcpconnect( int     *pi_sock, char    *ps_addr, ushort   pi_port);
short   ri_tcpread( int     pi_sock, char    *ps_str, short   pi_num, short   pi_timeout);
short   ri_tcpwrite( int     pi_sock, short   pi_num, char    *ps_str);



#ifdef  __cplusplus
}
#endif

#endif
