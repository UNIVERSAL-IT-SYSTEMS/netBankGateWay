/*
 *	XML报文解析C库函数
 *	Coding By WangXiancheng 
 *	at 2000-11-10 21:49、 2000-11-12 16:10、 
 *	   2001-01-03 11:34、 2001-01-15 11:26 
 *	Modified by Friar
 *	at ????-03-31		增加函数 : EBankUpdateField
 *	   2001-10-24		增加报文标识根元素	
 *	   2001-10-27		增加组装报文的缩进格式
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <varargs.h>

#define ERRORLOGFILE "/tmp/ebdebug.log"	/* 错误日志文件 */
#define COMMLOGFILE  "/tmp/ebcomm.log"	/* 通讯日志文件 */
#define DISP_LEVEL 	9			/* 显示级别 */

#define TAG_LEN		100

/* 报文定义 */

typedef char	EBANKDG;

/* #define WINDOWSDLL */

#ifdef	WINDOWSDLL
#define _EBDCL  __declspec(dllexport)
#else
#define _EBDCL
#endif

static int cur_pos=0;		/* 当前位置 */
static int in_packet=0;		/* 是否在报文中（组装） */
static int in_packet2=0;		/* 是否在报文中（解析） */
static int in_col=0;		/* 是否在列表中 */
static int max_dg_size=0;	/* 报文的最大大小 */
static int col_num = 0;		/* 列数目 */
static int row_num = 0;		/* 行数目 */

static	char	con_dg_root[TAG_LEN + 1];	/* 组装报文根元素 */
static	char	dec_dg_root[TAG_LEN + 1];	/* 解析报文根元素 */	

#define MAX_SEG  5		/* 最大的段层数 */
#define MAX_COL_DEF	20	/* 最大的列定义数 */
#define DELIMITER	','	/* 列定义中的分割符 */

static char LastSegment[MAX_SEG][41];	/* 当前段的位置信息 */
static int  cur_seg = 0;		/* 当前的段层数 */
static char LastListName[41]="";	/* 当前列表的名称 */
static char LastSegmentName[41]="";		/* 当前段的名称 */
static char ColName[MAX_COL_DEF][21];	/* 列的名称定义 */

static char ebdgerror[101];		/* 错误信息缓冲区 */
typedef struct {
	char	FieldName[31];
	char	AttrName[31];
	char	AttrValue[31];
} EBankFieldAttr;

static EBankFieldAttr	FldAttr[10];
static FldAttrNum;


/* 
 * 开始和结束的字符位置指针
 * pb0, pe0: 开始和结束的位置；
 * pb,  pe : 当前位置范围；
 * pcur    : 当前位置
 * pb1, pe1: 当前有效的位置范围
 * pbs, pes: 各段的位置范围
 * col_b, col_e: 列定义的位置范围
 * row_b, row_e: 行的位置范围
 */
static char *pb0, *pe0, *pb, *pe, *pb1, *pe1;
static char *pbs[5], *pes[5];	
static char *col_b, *col_e;
static char *row_b, *row_e;
static char *pcur, *pcur2;

/* Added by Friar BEGIN */
static	char	*pprev;		/* 保留前一次的位置 */
static	int	indent;		/* 缩进位置 */
static	int	i;
/* Added by Friar END   */


static char *col_cur;		/* 当前列的指针 */
static char *row_cur;		/* 当前行的指针 */



/*
 *	报文组装函数
 */

/* 产生一个新的EBANK报文 */
_EBDCL EBANKDG *EBankNewDG(int max_size, char* root_element);

/* 为下一个增加的域赋予一个属性 */
_EBDCL int EBankAssignAttribute( EBANKDG *pDG, char *pName, char *pAttrName, char *pAttrValue);

/* 向当前EBANK报文位置增加一个域 */
_EBDCL int EBankAppendField( EBANKDG *pDG, char *pName, char *pValue);

/* 开始一个新的段 */
_EBDCL int EBankStartSegment( EBANKDG *pDG, char *pName );

/* 结束上一个段 */
_EBDCL int EBankEndSegment( EBANKDG *pDG );

/* 开始一个新的列表 */
_EBDCL int EBankStartList( EBANKDG *pDG, char *pName );

/* 向当前的列表中增加一个列的定义 */
_EBDCL int EBankAppendListColumn( EBANKDG *pDG, char *pFieldName, char *pColname );

/* 向当前的列表中增加一个行数据 */
_EBDCL int EBankAppendListRow( EBANKDG *pDG, char *pBuf ); 

/* 结束当前的列表 */
_EBDCL int EBankEndList( EBANKDG *pDG );

/* 结束EBANK报文 */
_EBDCL int EBankEndDG( EBANKDG *pDG, char *pDGBuf, int *pLen);

/* 异常情况下删除EBANK报文 */
_EBDCL int EBankDestroyDG( EBANKDG *pDG);

/* 
 *	报文分析函数
 */

/* 打开一个报文，从字符串中读入数据 */
_EBDCL EBANKDG *EBankOpenDG(char *pDGBuf, int pLen, char* root_element);

/* 从当前的段中得到一个指定域的值（如果没有打开的段，则从整个报文中得到） */
_EBDCL int EBankGetField( EBANKDG *pDG, char *pName, char *pValue);

/* 从当前的段中得到当前位置下一个域的值（如果没有当前段，默认为整个报文） */
_EBDCL int EBankGetNextField( EBANKDG *pDG, char *pName, char *pValue);

/* 打开一个段 */
_EBDCL int EBankOpenSegment( EBANKDG *pDG, char *pName );

/* 关闭上一个一打开的段 */
_EBDCL int EBankCloseSegment( EBANKDG *pDG );

/* 打开一个列表 */
_EBDCL int EBankOpenList( EBANKDG *pDG, char *pName );

/* 从当前的列表中顺序得到一个列的定义 */
_EBDCL int EBankGetListColumn( EBANKDG *pDG, char *pFieldName, char *pColName );

/* 从当前的列表中顺序得到一行数据的值 */
_EBDCL int EBankGetListNextRow( EBANKDG *pDG, char *pBuf );  

/* 关闭已打开的列表 */
_EBDCL int EBankCloseList( EBANKDG *pDG );

/* 关闭已打开的EBANK报文 */
_EBDCL int EBankCloseDG( EBANKDG *pDG );

/* 拷贝指定位置的字符 */
static int xmlcpy(char *dst, char *pb, char *pe);

/* Added by Friar BEGIN */
/* 修改指定域的内容 */
_EBDCL int EBankUpdateField(EBANKDG *pDG, char *pFieldName, char *pNewValue);
/* Added by Friar END   */

/*
 *	EBankNewDG:	产生一个新的EBANK报文
 *	输入参数：	max_size: 最大的报文大小
 *	输出：		返回值: NULL -- 失败
 *				!NULL-- 成功,指向EBANK报文的指针
 */

_EBDCL EBANKDG *EBankNewDG(int max_size, char* root_element)
{
	EBANKDG *buf;
	char	tmp[100];
	int 	tmplen=0;
	
	
	if(in_packet) {
		sprintf(ebdgerror, "报文已经存在");
		return NULL;
	}
	
	cur_pos=0;		/* 当前位置 */
	in_col=0;		/* 不在列表中 */
	max_dg_size=0;		/* 报文的最大大小 */
	
	memset(LastSegment, 0, sizeof(LastSegment));	/* 当前段的位置信息 */
	cur_seg = 0;		/* 当前的段层数 */
	memset(LastListName, 0, sizeof(LastListName));	/* 当前列表的名称 */
	memset(ColName, 0, sizeof(ColName));		/* 列的名称定义 */
	col_num = 0;		/* 当前列表的列数 */
	row_num = 0;
	pcur = NULL;
	/* Added by Friar */
	pprev = NULL;
	indent = 1;
	/* Added by Friar */	
	

	if(max_size < 10) {
		sprintf(ebdgerror, "报文太小");
		return NULL;
	}
			
	buf = (EBANKDG *) calloc(max_size, sizeof(EBANKDG));
	if(buf==NULL) {
		sprintf(ebdgerror, "分配报文缓冲区错误");
		return(NULL);
	}
	memset(buf, 0, max_size);
	max_dg_size = max_size;
	memset(buf, 0, max_size);

	if (strlen(root_element) > TAG_LEN) {
		sprintf(ebdgerror, "报文根元素定义太长");
		return (NULL);
	}
	if (strlen(root_element) == 0 || root_element == NULL) {
		sprintf(ebdgerror, "报文根元素不能为空");
		return (NULL);
	}
	strcpy(con_dg_root, root_element);
	sprintf(tmp, "<?xml version=\"1.0\" encoding=\"gb2312\"?>\n<%s>\n",
		root_element);

	tmplen=strlen(tmp);
	if((cur_pos + tmplen) >= max_dg_size) {
		free(buf);
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return(NULL);
	}
	strcat(buf, tmp);
	 
	cur_pos += tmplen ;
	in_packet = 1;
	
	return(buf);
}

/*
 *	EBankAppendField:	为下一个增加的域赋予一个属性
 *	输入参数：		pDG:	报文指针	
 *				pFieldName:	域的名称
 *				pAttrName:	属性的名称
 *				pAttrValue:	属性的值
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankAssignAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue)
{
	if((pDG == NULL) || (pFieldName == NULL) || (pAttrName == NULL) || (pAttrValue == NULL) ) {
		sprintf(ebdgerror, "有参数地址为空");
		return(-1);
	}
	if(!strcmp(pFieldName, "")) {
		sprintf(ebdgerror, "域名为空");
		return(-1);
	}
	if(!strcmp(pAttrName, "")) {
		sprintf(ebdgerror, "属性名为空");
		return(-1);
	}
	if(!strcmp(pAttrValue, "")) {
		sprintf(ebdgerror, "属性值为空");
		return(-1);
	}
	if(FldAttrNum >= 10) {
		sprintf(ebdgerror, "赋予的属性超过最大值");
		return(-1);
	}

	strcpy(FldAttr[FldAttrNum].FieldName, pFieldName);
	strcpy(FldAttr[FldAttrNum].AttrName, pAttrName);
	strcpy(FldAttr[FldAttrNum].AttrValue, pAttrValue);
	FldAttrNum ++;
	
	return 0;	
}


/*
 *	EBankAppendField:	向当前的EBANK报文中增加一个域
 *	输入参数：		pDG:	报文指针	
 *				pName:	域的名称
 *				pValue:	域的值
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankAppendField( EBANKDG *pDG, char *pName, char *pValue)
{
	char	tmp[300];
	char	tmp2[200];
	char	*p;
	int 	tmplen=0;
	int	i;
	
	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "域名不能为空");
		return -1;
	}
	
	if(cur_seg) {
		sprintf(tmp, "<%s>", LastSegment[cur_seg-1]);
		p = strstr(pDG, tmp);
	}
	else	p = pDG;
	sprintf(tmp, "<%s>", pName);
	if(strstr(p, tmp) != NULL) {
		sprintf(ebdgerror, "域名[%s]在当前段内重复", pName);
		return -1;
	}
	sprintf(tmp, "<%s ", pName);
	if(strstr(p, tmp) != NULL) {
		sprintf(ebdgerror, "域名[%s]在当前段内重复", pName);
		return -1;
	}
	sprintf(tmp, "<%s", pName);
	
	for(i=0; i < FldAttrNum; i++) {

		if(!strcmp(pName, FldAttr[i].FieldName)) {
			sprintf(tmp2, " %s=\"%s\"", FldAttr[i].AttrName, FldAttr[i].AttrValue );
			strcat(tmp, tmp2);
			memset(tmp2, 0, sizeof(tmp2));
		}

	}

	sprintf(tmp2, ">%s</%s>\n",pValue,pName);
	strcat(tmp, tmp2);

	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
	memset(FldAttr, 0, sizeof(FldAttr));
	FldAttrNum = 0;
	return 0;
}

/*
 *	EBankStartSegment:	产生一个新的段
 *	输入参数：		pDG:	报文指针	
 *				pName:	段的名称
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *	注意：			各个段的名称不能重复
 */

_EBDCL int EBankStartSegment( EBANKDG *pDG, char *pName )
{
	char	tmp[100];
	int 	tmplen=0;
	
	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "段名不能为空");
		return -1;
	}
	sprintf(tmp, "<%s>\n", pName);
	if(strstr(pDG, tmp) != NULL) {
		sprintf(ebdgerror, "段名[%s]在报文内重复", pName);
		return -1;
	}

	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	if(cur_seg>=MAX_SEG) {
		sprintf(ebdgerror, "打开的段层数太多");
		return -1;
	}
	
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
		
	indent ++;
	
	strcpy(LastSegment[cur_seg], pName);
	cur_seg ++;
	
	return 0;
	
}

/*
 *	EBankEndSegment:	结束上一个段
 *	输入参数：		pDG:	报文指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankEndSegment( EBANKDG *pDG )
{
	char	tmp[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
		
	if((cur_seg==0) || (cur_seg > MAX_SEG)){
		sprintf(ebdgerror, "没有可以结束的段");
		return -1;
	}
				
	sprintf(tmp, "</%s>\n", LastSegment[cur_seg-1]);
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	
	indent --;

	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
	
	memset(LastSegment[cur_seg], 0, sizeof(LastSegment[0]));
	
	cur_seg --;
	
	return 0;	
}

/*
 *	EBankStartList:		开始产生一个列表
 *	输入参数：		pDG:	报文指针	
 *				pName:	列表的名称
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankStartList( EBANKDG *pDG, char *pName )
{
	char	tmp[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "段名不能为空");
		return -1;
	}
	if(in_col) {
		sprintf(ebdgerror, "列表不能嵌套，请先结束当前表");
		return -1;
	}
	col_num = 0;
	row_num = 0;
	
	sprintf(tmp, "<%s>\n", pName);
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	indent ++;
	cur_pos += tmplen;
	
	strcpy(LastListName, pName);
	in_col = 1;
	
	return 0;
	
}

/*
 *	EBankAppendListColumn:	向当前的列表中增加一个列的定义
 *	输入参数：		pDG:	报文指针	
 *				pName:	列的名称
 *				iMaxLen:列的最大长度
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankAppendListColumn( EBANKDG *pDG, char *pFieldName, char *pColName )
{
	char	tmp[100], tmp1[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!strcmp(pFieldName, "")) {
		sprintf(ebdgerror, "域名不能为空");
		return -1;
	}
	if(!strcmp(pColName, "")) {
		sprintf(ebdgerror, "列名不能为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "请首先开始一个列表");
		return -1;
	}
	
	memset(tmp, 0, sizeof(tmp));
	
	if(col_num==0) {
		sprintf(tmp, "<gCols>\n");
		/* Added for indent 20011027 by Friar */
		for (i = 0; i < indent + 1; i ++)
			strcat(tmp, "\t");
		/* Added for indent 20011027 by Friar */
	}
	else
		strcat(tmp, "\t");
	
	sprintf(tmp1, "<%s>%s</%s>\n", pFieldName, pColName, pFieldName );
	strcat(tmp, tmp1);
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	
	
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
	col_num ++;
			
	return 0;
}

/*
 *	EBankAppendListRow:	向当前的列表中增加一行数据
 *	输入参数：		pDG:	报文指针	
 *				pBuf:	行数据的内容
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankAppendListRow( EBANKDG *pDG, char *pBuf )
{
	char	tmp[100], tmp1[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!strcmp(pBuf, "")) {
		sprintf(ebdgerror, "行值不能为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "请首先开始一个列表");
		return -1;
	}

	memset(tmp, 0, sizeof(tmp));
	if((col_num != 0) && (row_num == 0)) {
		/* sprintf(tmp, "</gCols>\n<gRows>\n"); */
		sprintf(tmp, "</gCols>\n");
		/* Added for indent 20011027 by Friar */
		for (i = 0; i < indent; i ++)
			strcat(tmp, "\t");
		/* Added for indent 20011027 by Friar */
		strcat(tmp, "<gRows>\n");
		for (i = 0; i < indent; i ++)
			strcat(tmp, "\t");
	} 
	else if ((col_num == 0) && (row_num == 0)) {
		sprintf(tmp, "<gRows>\n");
		/* Added for indent 20011027 by Friar */
		for (i = 0; i < indent; i ++)
			strcat(tmp, "\t");
		/* Added for indent 20011027 by Friar */
	}
		
	sprintf(tmp1, "<row>%s</row>\n",pBuf);
	strcat(tmp, "\t");
	strcat(tmp, tmp1);
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
	row_num ++;
	
	return 0;	
}

/*
 *	EBankEndList:		结束已打开的列表
 *	输入参数：		pDG:	报文指针	
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankEndList( EBANKDG *pDG )
{
	char	tmp[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "请首先开始一个列表");
		return -1;
	}

	memset(tmp, 0, sizeof(tmp));
	if(row_num != 0) {
		char	temp1[100];

		memset(temp1, 0, sizeof(temp1));
		for (i = 0; i < indent - 1; i ++)
			strcat(temp1, "\t");
		sprintf(tmp, "</gRows>\n%s</%s>\n", temp1, LastListName);
	}
	else if(col_num != 0)  {
		char	temp1[100];

		memset(temp1, 0, sizeof(temp1));
		for (i = 0; i < indent - 1; i ++)
			strcat(temp1, "\t");
		sprintf(tmp, "</gCols>\n%s</%s>\n", temp1, LastListName);
	} 
	else {
		char	temp1[100];

		memset(temp1, 0, sizeof(temp1));
		for (i = 0; i < indent - 1; i ++)
			strcat(temp1, "\t");
		sprintf(tmp, "%s</%s>\n", temp1, LastListName);
	}
	
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}
	/* Added for indent 20011027 by Friar */
	for (i = 0; i < indent; i ++)
		strcat(pDG, "\t");
	indent --;
	/* Added for indent 20011027 by Friar */

	strcat(pDG, tmp);
	cur_pos += tmplen;
	
	memset(LastListName, 0, sizeof(LastListName));
	in_col = 0;
	
	return 0;
		
	
	
}

/*
 *	EBankEndDG:		结束EBANK报文，将EBANK报文中的数据拷贝到字符缓冲区中
 *	输入参数：		pDG:	报文指针	
 *				pDGBuf:	字符缓冲区指针
 *				pLen:	字符缓冲区的大小
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *				pLen:	字符缓冲区中字符串的长度
 */

_EBDCL int EBankEndDG( EBANKDG *pDG, char *pDGBuf, int *pLen )
{
	char	tmp[100];
	int 	tmplen=0;

	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	if(pDGBuf==NULL) {
		sprintf(ebdgerror, "字符串缓冲区没有分配");
		return -1;
	}	
	if(in_col) {
		sprintf(ebdgerror, "列表没有关闭");
		return -1;
	}
	if(strcmp(LastSegment[1], "")) {
		sprintf(ebdgerror, "有段没有关闭");
		return -1;
	}
	
	sprintf(tmp, "</%s>\n", con_dg_root);
	
	tmplen=strlen(tmp);
	
	if((cur_pos + tmplen) >= max_dg_size) {
		sprintf(ebdgerror, "报文缓冲区太小，已经越界");
		return -1;
	}

	indent --;
	
	strcat(pDG, tmp);
	cur_pos += tmplen;
	

	if(*pLen <= cur_pos) {
		sprintf(ebdgerror, "字符串缓冲区太小，已经越界");
		return -1;
	}
		
	strcpy(pDGBuf, pDG);

	*pLen = cur_pos;
	free(pDG);
	in_packet = 0;
			
	return 0;
		
}

/*
 *	EBankDestroy:		删除EBANK报文（异常退出时使用）
 *	输入参数：		pDG:	报文指针	
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankDestroyDG( EBANKDG *pDG )
{
	if(pDG==NULL) {
		sprintf(ebdgerror, "报文缓冲区没有分配");
		return -1;
	}
	
	in_packet = 0;
	in_packet2 = 0;

	free(pDG);
		
	return 0;
		
}

/* 以下是EBANK报文解析函数 */


/*
 *	EBankOpenDG:	产生一个EBANK报文，将字符串中的内容放入EBANK报文中进行解析
 *	输入参数：	pDG:	报文指针	
 *			max_size:报文的最大大小
 *	输出：		返回值: !NULL -- 成功(EBANK报文的指针）
 *				NULL  -- 失败
 */

_EBDCL EBANKDG *EBankOpenDG(char *pDGBuf, int max_size, char* root_element)
{
	EBANKDG *buf;
	char	start_tag[TAG_LEN];
	char	end_tag[TAG_LEN];
	
	
	if(in_packet2) {
		sprintf(ebdgerror, "报文已经存在");
		return NULL;
	}

	if (root_element == NULL || strlen(root_element) == 0) {
		sprintf(ebdgerror, "报文根元素不能为空");
		return NULL;
	}

	if (strlen(root_element) > TAG_LEN) {
		sprintf(ebdgerror, "报文根元素定义太长");
		return NULL;
	}
	
	cur_pos=0;		/* 当前位置 */
	in_col=0;		/* 不在列表中 */
	max_dg_size=0;		/* 报文的最大大小 */
	
	memset(LastSegment, 0, sizeof(LastSegment));	/* 当前段的位置信息 */
	cur_seg = 0;		/* 当前的段层数 */
	memset(LastListName, 0, sizeof(LastListName));	/* 当前列表的名称 */
	memset(ColName, 0, sizeof(ColName));		/* 列的名称定义 */
	col_num = 0;		/* 当前列表的列数 */
	row_num = 0;
	

	if(max_size <= (int)strlen(pDGBuf)) {
		sprintf(ebdgerror, "报文太小");
		return NULL;
	}
			
	buf = (EBANKDG *) calloc(max_size, sizeof(EBANKDG));
	if(buf==NULL) {
		sprintf(ebdgerror, "分配报文缓冲区错误");
		return(NULL);
	}
	max_dg_size = max_size;
	strcpy(buf, pDGBuf);

	strcpy(dec_dg_root, root_element);
	sprintf(start_tag, "<%s>",  root_element);
	sprintf(end_tag,   "</%s>", root_element);

	pb0 = strstr(buf, start_tag);
	pe0 = strstr(buf, end_tag);
	if((pb0==NULL) || (pe0==NULL)) {
		sprintf(ebdgerror, "报文规范错误");
		free(buf);
		return(NULL);
	}

	pb1 = pb0;
	pe1 = pe0;
	pcur = pb0 + 6;
	pprev = pcur;
	
	in_packet2 = 1;
	
	return(buf);
}


/*
 *	EBankGetField:	从当前的段中得到指定域的值（如果没有当前段，默认为整个报文）
 *	输入参数：	pDG:	报文指针	
 *			pName:	域的名称
 *			pValue:	存放域值的指针
 *	输出：		返回值: 0  -- 成功
 *				-1 -- 失败
 *				-2 -- 没有找到该域
 *			*pValue:域的值
 */

_EBDCL int EBankGetField( EBANKDG *pDG, char *pName, char *pValue)
{
	char	btag[31], etag[31];


	if((pDG==NULL) || (pName==NULL) || (pValue==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "域名不能为空");
		return -1;
	}
	sprintf(btag, "<%s>", pName);
	sprintf(etag, "</%s>", pName);
	
	pb = strstr(pb1, btag);
	if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
		sprintf(btag, "<%s ", pName);
		pb = strstr(pb1, btag);
		if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
			sprintf(ebdgerror, "没有找到域[%s]", pName);
			return -2;
		}
	}
	pe = strstr(pb1, etag);
	if((pe == NULL) || (pe < pb1) || (pe > pe1)) {
		sprintf(ebdgerror, "没有找到域[%s]的结束符", pName);
		return -1;
	} 
	if(pe <= pb) {
		sprintf(ebdgerror, "域[%s]定义错误", pName);
		return -1;
	}
	pcur = pe + strlen(pName) + 3;
	
	xmlcpy(pValue, strstr(pb, ">")+1 , pe);
	return 0;
}

/*
 *	EBankGetNextField:	从当前的段中得到当前位置下一个域的值（如果没有当前段，默认为整个报文）
 *	输入参数：	pDG:	报文指针	
 *			pName:	域名称的地址
 *			pValue:	存放域值的指针
 *	输出：		返回值: 0  -- 成功
 *				-1 -- 失败
 *				-2 -- 没有找到下一个域
 *			*pName:域的名称
 *			*pValue:域的值
 */

_EBDCL int EBankGetNextField( EBANKDG *pDG, char *pName, char *pValue)
{
	char	btag[31], etag[31];
	char 	*ptmp, *ptmp2;
	int	i;
	char	end_tag[TAG_LEN];


	if((pDG==NULL) || (pName==NULL) || (pValue==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	
	sprintf(btag, "<");
	sprintf(etag, "</");
	
	pb = strstr(pcur, btag);
	if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
		sprintf(ebdgerror, "没有找到下一个域");
		return -8;
	}
	ptmp = strstr(pb, ">");
	ptmp2 = strstr(pb, " ");
	if(ptmp == NULL) {
		sprintf(ebdgerror, "域定义错误[%d]", __LINE__);
		return -1;
	}
	if((ptmp < ptmp2) || (ptmp2 == NULL))
		xmlcpy(pName, pb+1, ptmp);
	else
		xmlcpy(pName, pb+1, ptmp2);
		
	if(pName[0] == 'g') {
		sprintf(ebdgerror, "遇到一个段的开始");
		strcpy(LastSegmentName, pName);
		pcur = pb + strlen(pName) + 2;			
		return -2;
	}
	if(pName[0] == 'l') {
		sprintf(ebdgerror, "遇到一个列表的开始");
		pcur = pb + strlen(pName) + 2;	
		return -4;
	}

	if(pName[0] == '/') {
		if(pName[1] == 'g') {
			sprintf(ebdgerror, "遇到一个段的结束");
			pcur = pb + strlen(pName) + 3;		
			for(i=0; i<=strlen(pName); i++)
				pName[i] = pName[i+1];
			return -3;
		}
		if(pName[1] == 'l') {
			sprintf(ebdgerror, "遇到一个列表的结束");
			pcur = pb + strlen(pName) + 3;
			for(i=0; i<=strlen(pName); i++)
				pName[i] = pName[i+1];
			return -5;			
		}
		sprintf(end_tag, "/%s", dec_dg_root);
		if(!strncmp(pName, end_tag, 6)) {
/*			pcur = pb + strlen(pName) + 3;		*/
			sprintf(ebdgerror, "遇到报文结束");
			for(i=0; i<=strlen(pName); i++)
				pName[i] = pName[i+1];
			return -9;
		}
		
		fprintf(stdout, "pName = [%s]\n", pName);

		sprintf(ebdgerror, "报文解析错误");
		return -1;		
	}
		
	sprintf(etag, "</%s>", pName);

	pe = strstr(pcur, etag);
	
	if((pe == NULL) || (pe < pb1) || (pe > pe1)) {
		sprintf(ebdgerror, "没有找到域[%s]的结束符",pName);
		return -1;
	} 
	if(pe <= pb) {
		sprintf(ebdgerror, "域定义错误[%d]", __LINE__);
		return -1;
	}
	
	/* Added by Friar */
	pprev = pcur;
	/* Added by Friar */
	pcur = pe + strlen(pName) + 3;
	
	xmlcpy(pValue, ptmp+1, pe);
		
	return 0;
}

/*
 *	EBankGetAttribute:	从当前的段中得到一个域的一个属性（如果没有当前段，默认为整个报文）
 *	输入参数：	pDG:	报文指针	
 *			*pFieldName:	域名称
 *			*pAttrName:	属性名称
 *			pAttrValue:	存储属性值的指针
 *	输出：		返回值: 0  -- 成功
 *				-1 -- 失败
 *				-2 -- 没有找到域或属性
 *			*pAttrValue:属性的值
 */

_EBDCL int EBankGetAttribute( EBANKDG *pDG, char *pFieldName, char *pAttrName, char *pAttrValue)
{
	char	btag[31], etag[31];
	char	*pp;


	if((pDG==NULL) || (pFieldName==NULL) || (pAttrName == NULL) || (pAttrValue==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!strcmp(pFieldName, "")) {
		sprintf(ebdgerror, "域名不能为空");
		return -1;
	}
	if(!strcmp(pAttrName, "")) {
		sprintf(ebdgerror, "属性名不能为空");
		return -1;
	}
	sprintf(btag, "<%s ", pFieldName);
	sprintf(etag, "</%s>", pFieldName);
	
	pb = strstr(pb1, btag);
	if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
		sprintf(btag, "<%s>", pFieldName);
		pb = strstr(pb1, btag);
		if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
			sprintf(ebdgerror, "没有找到域[%s]", pFieldName);
			return -2;
		} else {
			sprintf(ebdgerror, "域[%s]没有属性", pFieldName);
			return -2;
		}
	}
	pe = strstr(pb1, etag);
	if((pe == NULL) || (pe < pb1) || (pe > pe1)) {
		sprintf(ebdgerror, "没有找到域[%s]的结束符", pFieldName);
		return -1;
	} 
	if(pe <= pb) {
		sprintf(ebdgerror, "域[%s]定义错误", pFieldName);
		return -1;
	}
	pcur = pe + strlen(pFieldName) + 2;
	sprintf(btag, "%s=", pAttrName);
	pp = strstr(pb, btag);
	if(pp!=NULL)
		pb = pp;
	if((pp == NULL) || (pp < pb1) || (pp > pe)) {
		sprintf(btag, "%s ", pAttrName);
		pp = strstr(pb, btag);
		if(pp!=NULL)
			pb = pp;
		if((pp == NULL) || (pp < pb1) || (pp > pe)) {
			sprintf(ebdgerror, "没有找到属性[%s]", pAttrName);
			return -2;
		}
		
	}
	pp = strstr(pb, "=");
	pp = strstr(pp, "\"");
	xmlcpy(pAttrValue, pp+1 , strstr(pp+1, "\""));
	return 0;
}


/*
 *	EBankOpenSegment:	打开指定的段，该段成为当前段
 *	输入参数：		pDG:	报文指针	
 *				pName:	段的名称
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *					-2 -- 没有找到该段
 */

_EBDCL int EBankOpenSegment( EBANKDG *pDG, char *pName )
{
	char	btag[31], etag[31];


	if((pDG==NULL) || (pName==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "段名不能为空");
		return -1;
	}
	if(cur_seg==MAX_SEG) {
		sprintf(ebdgerror, "打开的段太多");
		return -1;
	}
	if(in_col) {
		sprintf(ebdgerror, "已在列表中，请首先关闭列表");
		return -1;
	}
		
	sprintf(btag, "<%s>", pName);
	sprintf(etag, "</%s>", pName);
	
	pb = strstr(pb1, btag);
	if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
		sprintf(ebdgerror, "没有找到段名[%s]", pName);
		return -2;
	}
	pe = strstr(pb1, etag);
	if((pe == NULL) || (pe < pb1) || (pe > pe1)) {
		sprintf(ebdgerror, "没有找到段[%s]的结束符", pName);
		return -1;
	} 
	if(pe <= pb) {
		sprintf(ebdgerror, "段[%s]定义错误", pName);
		return -1;
	}
	pe += strlen(pName) + 3;
	pbs[cur_seg] = pb;
	pes[cur_seg] = pe;
	
	pb1 = pb;
	pe1 = pe;
	pcur = pb + strlen(pName) + 2;
	/* Added by Friar */
	pprev = pcur;
	/* Added by Friar */
	
	cur_seg ++;
	
	return 0;	
}

/*
 *	EBankCloseSegment:	关闭当前的段，关闭之后当前段为上一次之前打开的段或整个报文
 *	输入参数：		pDG:	报文指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankCloseSegment( EBANKDG *pDG )
{

	if(pDG==NULL) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(cur_seg==0) {
		sprintf(ebdgerror, "没有段已打开");
		return -1;
	}
	
	cur_seg --;
	if(cur_seg == 0) {
/*		pcur = pe1 + 2;		*/
		pb1 = pb0;
		pe1 = pe0;
	}
	else {
		pb1 = pbs[cur_seg-1];
		pe1 = pes[cur_seg-1];
	}
	pcur += strlen(LastSegmentName) + 3;
	
	return 0;	
}

/*
 *	EBankOpenList:		打开指定的列表
 *	输入参数：		pDG:	报文指针	
 *				pName:	列表的名称
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *					-2 -- 没有找到列表
 */

_EBDCL int EBankOpenList( EBANKDG *pDG, char *pName )
{
	char	btag[31], etag[31];


	if((pDG==NULL) || (pName==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!strcmp(pName, "")) {
		sprintf(ebdgerror, "段名不能为空");
		return -1;
	}
	if(in_col) {
		sprintf(ebdgerror, "已在列表中");
		return -1;
	}
	
	sprintf(btag, "<%s>", pName);
	sprintf(etag, "</%s>", pName);
	
	pb = strstr(pb1, btag);
	if((pb == NULL) || (pb < pb1) || (pb > pe1)) {
		sprintf(ebdgerror, "没有找到列表名[%s]", pName);
		return -2;
	}
	pe = strstr(pb1, etag);
	if((pe == NULL) || (pe < pb1) || (pe > pe1)) {
		sprintf(ebdgerror, "没有找到列表[%s]的结束符", pName);
		return -1;
	} 
	if(pe <= pb) {
		sprintf(ebdgerror, "列表[%s]定义错误", pName);
		return -1;
	}
	pe += strlen(pName) + 3;

	pb1 = pb;
	pe1 = pe;
/*	pcur = NULL;		*/
	pcur += strlen(pName) + 2;
	pcur2 = NULL;
	
	pb = strstr(pb1, "<gCols>");
	if((pb != NULL) && (pb < pe1)) {
		col_b = pb;
		col_cur = pb;
		pe = strstr(pb, "</gCols>");
		if((pe != NULL) && (pe < pe1)) {
			col_e = pe;
			pcur = pb + 7;
		}
		else {
			sprintf(ebdgerror, "列定义错误");
			return -1;
		}
	}
	else {
		col_cur = NULL;
		col_b = NULL;	/* 没有列定义 */
		col_e = NULL;
	}
	
	pb = strstr(pb1, "<gRows>");
	if((pb != NULL) && (pb < pe1)) {
		row_b = pb;
		row_cur = pb;
		pe = strstr(pb, "</gRows>");
		if((pe != NULL) && (pe < pe1)) {
			row_e = pe;
			pcur2 = pb + 7;
		}
		else {
			sprintf(ebdgerror, "行定义错误");
			return -1;
		}
	}
	else {
		row_cur = NULL;
		row_b = NULL;	/* 没有行数据 */
		row_e = NULL;
	}
		
	
	in_col = 1;
	row_num = 0;
	
	return 0;
}

/*
 *	EBankGetListColumn:	顺序地得到列表中列的定义
 *	输入参数：		pDG:	报文指针	
 *				pFieldName:	存放列表中域的名称的指针
 *				pColName:存放该域值的指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *					-2 -- 没有列的定义
 *				*pFieldName:	列的名称
 *				*pColName:列的长度
 */

_EBDCL int EBankGetListColumn( EBANKDG *pDG, char *pFieldName, char *pColName )
{
	char	btag[31], etag[31];
	char	tmp[256];
	char	*ptmp;


	if((pDG==NULL) || (pFieldName==NULL) || (pColName==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "没有打开列表");
		return -1;
	}
	if(col_cur == NULL) {
		sprintf(ebdgerror, "没有列定义");
		return -2;
	}
		
	sprintf(btag, "<");
	sprintf(etag, "</");
	
	pb = strstr(pcur, btag);
	if((pb == NULL) || (pb >= col_e)) {
		sprintf(ebdgerror, "没有列定义数据");
		return -2;
	}
	ptmp = strstr(pcur, ">");
	if(ptmp == NULL) {
		sprintf(ebdgerror, "没有列定义数据");
		return -2;
	}
	xmlcpy(pFieldName, pb+1, ptmp);
	sprintf(etag, "</%s>", pFieldName);
	pe = strstr(col_cur, etag);
	if((pe == NULL) || (pe > col_e)) {
		sprintf(ebdgerror, "没有找到列定义的结束符");
		return -1;
	}
		
	xmlcpy(pColName, pb+strlen(pFieldName)+2, pe);
	col_cur = pe + strlen(pFieldName) + 3;
	pcur = pe + strlen(pFieldName) + 3;	
	return 0;	
}

/*
 *	EBankGetListRow:	得到指定行的数据
 *	输入参数：		pDG:	报文指针	
 *				pBuf:	存放行数据的指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *					-2 -- 没有行数据
 *				*pBuf:	行数据
 */
/*
_EBDCL int EBankGetListRow( EBANKDG *pDG, int iRowNum, char *pBuf )
{
	char	btag[31], etag[31];

	if((pDG==NULL) || (pBuf==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "没有打开列表");
		return -1;
	}
	if(row_cur == NULL) {
		sprintf(ebdgerror, "没有行数据");
		return -2;
	}
		
	sprintf(btag, "<r%d>", iRowNum);
	sprintf(etag, "</r%d>", iRowNum);
	
	pb = strstr(row_cur, btag);
	if((pb == NULL) || (pb > row_e)) {
		sprintf(ebdgerror, "没有行数据");
		return -2;
	}
	pe = strstr(row_cur, etag);
	if((pe == NULL) || (pe > row_e)) {
		sprintf(ebdgerror, "没有找到行数据的结束符");
		return -1;
	}
	 
	
	xmlcpy(pBuf, pb+5, pe);
	row_cur = pe + 6;
	row_num = iRowNum;
	
	return 0;		
}
*/

/*
 *	EBankGetListNextRow:	顺序地得到行数据
 *	输入参数：		pDG:	报文指针	
 *				pBuf:	存放行数据的指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *					-2 -- 没有行数据
 *				*pBuf:	行数据
 */

_EBDCL int EBankGetListNextRow( EBANKDG *pDG, char *pBuf )
{
	char	btag[31], etag[31];

	if((pDG==NULL) || (pBuf==NULL)) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "没有打开列表");
		return -1;
	}
	if(row_cur == NULL) {
		sprintf(ebdgerror, "没有行数据");
		return -2;
	}
/*		
	sprintf(btag, "<r%d>", row_num+1);
	sprintf(etag, "</r%d>", row_num+1);
*/
	sprintf(btag, "<row>");
	sprintf(etag, "</row>");
	
	pb = strstr(row_cur, btag);
	if((pb == NULL) || (pb > row_e)) {
		sprintf(ebdgerror, "没有行数据");
		return -2;
	}
	pe = strstr(row_cur, etag);
	if((pe == NULL) || (pe > row_e)) {
		sprintf(ebdgerror, "没有找到行数据的结束符");
		return -1;
	}
	 
	
	xmlcpy(pBuf, pb+5, pe);
	row_cur = pe + 6;
	row_num ++;
	
	return 0;		
}

/*
 *	EBankCloseList:		关闭已打开的列表
 *	输入参数：		pDG:	报文指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankCloseList( EBANKDG *pDG )
{
	if(pDG==NULL) {
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}
	if(!in_col) {
		sprintf(ebdgerror, "没有列表已打开");
		return -1;
	}
	
	if(cur_seg == 0) {
		pb1 = pb0;
		pe1 = pe0;
	}
	else {
		pb1 = pbs[cur_seg-1];
		pe1 = pes[cur_seg-1];
	}
	
	in_col = 0;
	
	return 0;		
}

/*
 *	EBankCloseDG:		关闭EBANK报文，释放内存空间
 *	输入参数：		pDG:	报文指针
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int EBankCloseDG( EBANKDG *pDG )
{
	if(!in_packet2) {
		sprintf(ebdgerror, "报文不存在");
		return -1;
	}
	
	if(pDG==NULL) {
		sprintf(ebdgerror, "报文地址为空");
		return(-1);
	}

	in_packet2 = 0;
	cur_seg = 0;
	in_col = 0;
	free(pDG);

	return(0);	
}


/*
 *	xmlcpy:			将位于pb和pe之间的字符拷贝到dst
 *	输入参数：		dst:	目的字符串地址	
 *				pb:	源字符串起始地址
 *				pe:	源字符串结束地址
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 *				*dst:	字符串内容
 */

static int xmlcpy(char *dst, char *pb, char *pe)
{
	if(pe <= pb)
		return -1;
	memcpy(dst, pb, pe-pb);
	memset(dst+(pe-pb), 0, 1);
	return 0;	
}


/*
 *	CutSpace:	将字符串str中的尾部空格去掉
 *	输入参数：		str:	字符串地址
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int CutSpace(str)
char *str;
{
	int	len, i;

	len = strlen(str);
	i = len-1;
	while(*(str+i) == ' ') {
		*(str+i) = '\0';
		i --;
	}
	return(0);
}

/*
 *	dispmsg:		向跟踪日志文件中纪录跟踪信息
 *	输入参数：		disp_l:	跟踪的级别（级别为1-9，级别数小于指定级别的才纪录）	
 *				va_alist:	格式和数据
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int dispmsg(disp_l, va_alist)
int	disp_l;
va_dcl
{
	va_list	ap;
	char	*format;
	FILE	*fp;

	if(disp_l <= DISP_LEVEL) {
		fp = fopen( ERRORLOGFILE, "a+");
		if(fp == NULL)
			return -1;
		va_start(ap);
		format = va_arg(ap, char *);
		vfprintf(fp, format, ap);
		va_end(ap);
		fclose(fp);
	}

	return(0);
}

/*
 *	comlog:		向通讯日志文件中纪录通讯信息
 *	输入参数：	va_alist:	格式和数据
 *	输出：		返回值: 0  -- 成功
 *				-1 -- 失败
 */


_EBDCL int comlog(va_alist)
va_dcl
{
	va_list	ap;
	char	*format;
	FILE	*fp;

	fp = fopen( COMMLOGFILE, "a+");
	if(fp==NULL) {
		return -1;
	}
	
	va_start(ap);
	format = va_arg(ap, char *);
	vfprintf(fp, format, ap);
	va_end(ap);
	fclose(fp);
	
	return(0);
}

/*
 *	comlogfile:		向指定的日志文件中纪录信息
 *	输入参数：		file:		文件名
 *				va_alist:	格式和数据
 *	输出：			返回值: 0  -- 成功
 *					-1 -- 失败
 */

_EBDCL int comlogfile(file, va_alist)
char *file;
va_dcl
{
	va_list	ap;
	char	*format;
	FILE	*fp;

	fp = fopen( file, "a+");
	if(fp==NULL) {
		return -1;
	}
	
	va_start(ap);
	format = va_arg(ap, char *);
	vfprintf(fp, format, ap);
	va_end(ap);
	fclose(fp);
	
	return(0);
}

/*
 *	EBankGetErrmsg:		当错误发生时得到错误信息
 */

_EBDCL char *EBankGetErrmsg()
{
	return(ebdgerror);
}

/* Added by Friar BEGIN */
/* 
 *	EBankUpdateField	:	修改指定字段的值
 * 	参数	:	pDG: 		指向报文的指针
 *				pFieldName: 要修改的字段名
 *				pNewValue:	修改后的字段内容
 */
_EBDCL int EBankUpdateField(EBANKDG *pDG, char *pFieldName, char *pNewValue)
{
	char btag[31];
	char etag[31];
	char *tstr;
	char *pt;
	int  len;

	if ((pDG == NULL) || (pFieldName == 0))
	{
		sprintf(ebdgerror, "有参数地址为空");
		return -1;
	}

	if (!strcmp(pFieldName, ""))
	{
		sprintf(ebdgerror, "要修改的域名不能为空");
		return -1;
	}

	if (sizeof(etag) - strlen(pFieldName) < 4)
	{
		sprintf(ebdgerror, "要修改的域名太长");
		return -1;
	}

	sprintf(btag, "<%s>",  pFieldName);
	sprintf(etag, "</%s>", pFieldName);
	
	pb = strstr(pprev, btag);
	if ((pb == NULL) || (pb < pb1) || (pb > pe1))
	{
		sprintf(btag, "<%s", pFieldName);
		pb = strstr(pprev, btag);
		if ((pb == NULL) || (pb < pb1) || (pb > pe1))
		{
			sprintf(ebdgerror, "没有找到域[%s]", pFieldName);
			return -2;
		}
	}

	pe = strstr(pprev, etag);
	if ((pe == NULL) || (pe < pb1) || (pe > pe1))
	{
		sprintf(ebdgerror, "没有找到域[%s]的结束符", pFieldName);
		return -1;
	}

	if (pe <= pb)
	{
		sprintf(ebdgerror, "域[%s]定义错误", pFieldName);
		return -1;
	}
	
	len = strlen(pe);
	if (len == 0)
	{
		sprintf(ebdgerror, "报文格式出错");
		return -1;
	}

	tstr = (char *)calloc(len + 1, sizeof(char *));
	if (tstr == NULL)
	{
		sprintf(ebdgerror, "分配报文缓冲区失败");
		return -1;
	}

	strcpy(tstr, pe);
	pt = strstr(pb, ">");
	if ((pt == NULL) || (pt < pb1) || (pt > pe1))
	{
		free((void *)tstr);
		sprintf(ebdgerror, "域[%s]标签出错", EBankGetErrmsg());
		return -1;
	}
	*(pt + 1) = 0;
	strcat(pb1, pNewValue);
	strcat(pb1, tstr);

	free((void *)tstr);
	
	pcur = strstr(pt, "</");
	if ((pcur == NULL) || (pcur < pb1) || (pcur > pe1))
	{
		sprintf(ebdgerror, "未找到域[%s]的结束符", pFieldName);
		return -1;
	}
	pcur += strlen(pFieldName) + 3;

	return 0;
}
/* Added by Friar END  */
