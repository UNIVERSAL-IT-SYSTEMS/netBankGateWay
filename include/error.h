#ifndef _ERROR_H
#define _ERROR_H

#define BASE_ERR 			-9000		/* 错误代码基值 */

/* 合法性检查返回值 */
#define RETURN_YES			1		/* 是 */
#define RETURN_NOT			0		/* 否 */

/* 返回值 */
#define RETURN_OK			0
#define FIELD_NOT_FOUND			-2		/* 解析报文没有找到 */

/* EC : Error Code */
#define EC_NO_ERROR			0		/* 没有错误	*/

#define EC_NULL_PARA_ERROR		(BASE_ERR -  1)	/* 参数为空	*/
#define EC_OPEN_FILE_ERROR		(BASE_ERR -  2)	/* 打开文件失败	*/
#define EC_UNDEF_SYM_ERROR		(BASE_ERR -  3)	/* 未定义项目	*/

#define	EC_TCP_NULL_HOST_ERROR		(BASE_ERR -  4)	/* 主机名为空	*/
#define EC_TCP_NULL_PORT_ERROR		(BASE_ERR -  5)	/* 端口号为空	*/
#define EC_TCP_SOCKET_ERROR		(BASE_ERR -  6) /* socket出错	*/
#define EC_TCP_CONNECT_ERROR		(BASE_ERR -  7) /* connect出错	*/
#define EC_TCP_SELECT_ERROR		(BASE_ERR -  8) /* select出错	*/
#define EC_TCP_TIME_OUT_ERROR		(BASE_ERR -  9) /* 超时错误	*/
#define EC_TCP_ABNORMAL_ERROR		(BASE_ERR - 10) /* 异常错误	*/
#define EC_TCP_WRITE_ERROR		(BASE_ERR - 11) /* write出错	*/
#define EC_TCP_READ_ERROR		(BASE_ERR - 12) /* read出错	*/
#define EC_TCP_BIND_ERROR		(BASE_ERR - 13) /* bind出错	*/
#define EC_TCP_LISTEN_ERROR		(BASE_ERR - 14) /* listen出错	*/
#define EC_TCP_ACCEPT_ERROR		(BASE_ERR - 15) /* accept出错	*/

#define EC_ADDRESS_EIB_ERROR		(BASE_ERR - 17)	/* 联接CICS出错 */
#define EC_ADDRESS_COMMAREA_ERROR	(BASE_ERR - 18)	/* 取CICS数据错 */
#define EC_SYNCPOINT_ERROR		(BASE_ERR - 19) /* SYNCPOINT出错 */
#define EC_CICS_LINK_ERROR		(BASE_ERR - 20) /* 程序LINK出错 */

#define EC_DECODE_DG_ERROR		(BASE_ERR - 30)	/* 解析报文出错 */
#define EC_CREATE_DG_ERROR		(BASE_ERR - 31) /* 创建报文出错 */
#define EC_DG_LENGTH_ERROR		(BASE_ERR - 32)	/* 报文长度不对 */
#define EC_DG_FIELD_LENGTH_ERROR	(BASE_ERR - 33) /* 字段长度不对 */
#define EC_INVALID_DG_TYPE		(BASE_ERR - 34) /* 报文类型错 */
#define EC_INVALID_BUSI_NO_ERROR	(BASE_ERR - 35) /* 交易类型未知 */

#define EC_CONNECT_DB_ERROR		(BASE_ERR - 101) /* 连接数据库错 */
#define EC_DB_SELECT_ERROR		(BASE_ERR - 102) /* 数据库查询出错 */
#define EC_DB_INSERT_ERROR		(BASE_ERR - 103) /* 数据库插入出错 */
#define EC_DB_UPDATE_ERROR		(BASE_ERR - 104) /* 数据库修改出错 */
#define EC_DB_DECLARE_ERROR		(BASE_ERR - 105) /* 游标声明出错 */
#define EC_DB_OPEN_ERROR		(BASE_ERR - 106) /* 游标打开出错 */
#define EC_DB_FETCH_ERROR		(BASE_ERR - 107) /* 游标撷取出错 */
#define EC_DB_CONVERT_ERROR		(BASE_ERR - 108) /* decimal转换出错 */
#define EC_DB_NOTFOUND_ERROR		(BASE_ERR - 109) /* 查询未找到记录 */
#define EC_DB_BEGIN_TRAN_ERROR		(BASE_ERR - 110) /* 启动事务失败 */
#define EC_DB_ROLLBACK_TRAN_ERROR	(BASE_ERR - 111) /* 回滚事务失败 */
#define EC_DB_COMMIT_TRAN_ERROR		(BASE_ERR - 112) /* 提交事务失败 */

#define EC_BRT_SYS_TYPE_ERROR		(BASE_ERR - 150) /* 分行类型出错 */
#define EC_BRT_NET_STATUS_ERROR		(BASE_ERR - 151) /* 网络状态不通 */
#define EC_BRT_NBANK_FLAG_ERROR		(BASE_ERR - 152) /* 网银系统未用 */
#define EC_BRT_BSN_STAT_ERROR		(BASE_ERR - 153) /* 业务系统未用 */

#define EC_STRING_LENGTH_ERROR		(BASE_ERR - 300) /* 字符串长度不对 */

/* 分行部分用 */
#define EC_SMT_SYS_STATUS_ERROR		(BASE_ERR - 500) /* 系统当前不可用 */
#define EC_DAY_END_CHECK_ERROR		(BASE_ERR - 501) /* 日终对帐失败 */
#define EC_CAN_NOT_QUERY_ERROR		(BASE_ERR - 502) /* 不能执行查询交易 */


/* 以下为与主机交易时用 */
#define EC_UNKNOWN_TRANS_CODE_ERROR	(BASE_ERR - 601) /* 主机未知交易类型 */
#define EC_TP_CALL_INIT_ERROR		(BASE_ERR - 602) /* 主机通讯初始化失败 */
#define EC_TP_CALL_ERROR		(BASE_ERR - 603) /* 与主机通讯失败 */

/* 授权与落地处理码 */
#define EC_WAIT_AUDIT			 9999		/* 等待授权处理 */
#define EC_WAIT_SUPPLY			 8888		/* 等待落地处理 */

#endif
