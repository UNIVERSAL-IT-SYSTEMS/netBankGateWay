#ifndef _CICSFUNC_H
#define _CICSFUNC_H

/*---------------------------------------------------
 * ������CICS Server�����м�¼TDQ
 *	char*	tdq:	TDQ����
 *	int	level:	��־��¼����
 *	char*	fmt:	��ʽ��
 *	va_del	:	��ѡ����
 *   ����ֵ��
 *		0	�ɹ�
 *		-1	ʧ��
 *-------------------------------------------------*/
extern	int	write_tdq(char* tdq, int level, char* fmt, ...);

extern	int	check_respcode(unsigned long respcode);

#endif
