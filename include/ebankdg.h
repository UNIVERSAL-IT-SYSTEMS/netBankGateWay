

#ifndef _EBANKDG_H
#define _EBANKDG_H

#ifdef	WIN32_CPP

#define _EBDCL	extern "C"

#else

#define _EBDCL	extern

#endif

_EBDCL char *EBGetErrmsg();		

typedef char	EBANKDG;

/*
 *	������װ���� 
 */

/* ����һ���µ�EBANK���� */
_EBDCL EBANKDG *EBankNewDG(int max_siz, char* pRootTag);

/* Ϊ��һ�����ӵ�����һ������ */
_EBDCL int EBankAssignAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue);

/* ��ǰEBANK����λ������һ���ֶ� */
_EBDCL int EBankAppendField( EBANKDG *pDG, char *pName, char *pValue);

/* ��ʼһ���µĶ� */
_EBDCL int EBankStartSegment( EBANKDG *pDG, char *pName );

/* ������һ���� */
_EBDCL int EBankEndSegment( EBANKDG *pDG );

/* ��ʼһ���µ��б� */
_EBDCL int EBankStartList( EBANKDG *pDG, char *pName );

/* ��ǰ���б�������һ���еĶ��� */
_EBDCL int EBankAppendListColumn( EBANKDG *pDG, char *pFieldName, char *pColName );

/* ��ǰ���б�������һ�������� */
_EBDCL int EBankAppendListRow( EBANKDG *pDG, char *pBuf ); 

/* ������ǰ���б� */
_EBDCL int EBankEndList( EBANKDG *pDG );

/* ����EBANK���� */
_EBDCL int EBankEndDG( EBANKDG *pDG, char *pDGBuf, int *pLen );

/* �쳣����½���EBANK���� */
_EBDCL int EBankDestroyDG( EBANKDG *pDG );

_EBDCL int comlogfile(char *file, ...);


/* 
 *	���ķ�������
 */

/* ��һ�����ģ����ַ����ж������� */
_EBDCL EBANKDG *EBankOpenDG(char *pDGBuf, int pLen, char* pRootTag);

/* �ӵ�ǰ�Ķ��еõ�һ��ָ���ֶε�ֵ�����û�д򿪵ĶΣ�������������еõ��� */
_EBDCL int EBankGetField( EBANKDG *pDG, char *pName, char *pValue);

/* �ӵ�ǰ�Ķ��еõ�һ�����һ�����ԣ����û�е�ǰ�Σ�Ĭ��Ϊ�������ģ�*/
_EBDCL int EBankGetAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue);

/* �ӵ�ǰ�Ķ��еõ���ǰλ����һ�����ֵ�����û�е�ǰ�Σ�Ĭ��Ϊ�������ģ�*/
_EBDCL int EBankGetNextField( EBANKDG *pDG, char *pName, char *pValue);

/* ��һ���� */
_EBDCL int EBankOpenSegment( EBANKDG *pDG, char *pName );

/* �ر���һ��һ�򿪵Ķ� */
_EBDCL int EBankCloseSegment( EBANKDG *pDG );

/* ��һ���б� */
_EBDCL int EBankOpenList( EBANKDG *pDG, char *pName );

/* �ӵ�ǰ���б���˳��õ�һ���еĶ��� */
_EBDCL int EBankGetListColumn( EBANKDG *pDG, char *pName, char *iManLen );

/* �ӵ�ǰ���б���˳��õ�һ�����ݵ�ֵ */
_EBDCL int EBankGetListRow( EBANKDG *pDG, char *pBuf );  

/* �ر��Ѵ򿪵��б� */
_EBDCL int EBankCloseList( EBANKDG *pDG );

/* �ر��Ѵ򿪵�EBANK���� */
_EBDCL int EBankCloseDG( EBANKDG *pDG );

/* �õ�������Ϣ */
_EBDCL char *EBankGetErrmsg();

/* Added by Friar BEGIN */
/* �޸ı�����ĳ�ֶε�ֵ */
_EBDCL int EBankUpdateField( EBANKDG *pDG, char *pFieldName, char *pNewValue);
/* Added by Friar END   */

#endif	/* _EBANKDG_H */
