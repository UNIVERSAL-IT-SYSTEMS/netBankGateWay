

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
 *	报文组装函数 
 */

/* 产生一个新的EBANK报文 */
_EBDCL EBANKDG *EBankNewDG(int max_siz, char* pRootTag);

/* 为下一个增加的域赋予一个属性 */
_EBDCL int EBankAssignAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue);

/* 向当前EBANK报文位置增加一个字段 */
_EBDCL int EBankAppendField( EBANKDG *pDG, char *pName, char *pValue);

/* 开始一个新的段 */
_EBDCL int EBankStartSegment( EBANKDG *pDG, char *pName );

/* 结束上一个段 */
_EBDCL int EBankEndSegment( EBANKDG *pDG );

/* 开始一个新的列表 */
_EBDCL int EBankStartList( EBANKDG *pDG, char *pName );

/* 向当前的列表中增加一个列的定义 */
_EBDCL int EBankAppendListColumn( EBANKDG *pDG, char *pFieldName, char *pColName );

/* 向当前的列表中增加一个行数据 */
_EBDCL int EBankAppendListRow( EBANKDG *pDG, char *pBuf ); 

/* 结束当前的列表 */
_EBDCL int EBankEndList( EBANKDG *pDG );

/* 结束EBANK报文 */
_EBDCL int EBankEndDG( EBANKDG *pDG, char *pDGBuf, int *pLen );

/* 异常情况下结束EBANK报文 */
_EBDCL int EBankDestroyDG( EBANKDG *pDG );

_EBDCL int comlogfile(char *file, ...);


/* 
 *	报文分析函数
 */

/* 打开一个报文，从字符串中读入数据 */
_EBDCL EBANKDG *EBankOpenDG(char *pDGBuf, int pLen, char* pRootTag);

/* 从当前的段中得到一个指定字段的值（如果没有打开的段，则从整个报文中得到） */
_EBDCL int EBankGetField( EBANKDG *pDG, char *pName, char *pValue);

/* 从当前的段中得到一个域的一个属性（如果没有当前段，默认为整个报文）*/
_EBDCL int EBankGetAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue);

/* 从当前的段中得到当前位置下一个域的值（如果没有当前段，默认为整个报文）*/
_EBDCL int EBankGetNextField( EBANKDG *pDG, char *pName, char *pValue);

/* 打开一个段 */
_EBDCL int EBankOpenSegment( EBANKDG *pDG, char *pName );

/* 关闭上一个一打开的段 */
_EBDCL int EBankCloseSegment( EBANKDG *pDG );

/* 打开一个列表 */
_EBDCL int EBankOpenList( EBANKDG *pDG, char *pName );

/* 从当前的列表中顺序得到一个列的定义 */
_EBDCL int EBankGetListColumn( EBANKDG *pDG, char *pName, char *iManLen );

/* 从当前的列表中顺序得到一行数据的值 */
_EBDCL int EBankGetListRow( EBANKDG *pDG, char *pBuf );  

/* 关闭已打开的列表 */
_EBDCL int EBankCloseList( EBANKDG *pDG );

/* 关闭已打开的EBANK报文 */
_EBDCL int EBankCloseDG( EBANKDG *pDG );

/* 得到错误信息 */
_EBDCL char *EBankGetErrmsg();

/* Added by Friar BEGIN */
/* 修改报文中某字段的值 */
_EBDCL int EBankUpdateField( EBANKDG *pDG, char *pFieldName, char *pNewValue);
/* Added by Friar END   */

#endif	/* _EBANKDG_H */
