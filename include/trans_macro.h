/***************************************************************
 DATE:	2003-06-07 chongqing 
 NOTE:  分行个人网络银行宏定义 
***************************************************************/

/*交易要素宏定义*/
#define  AreaCode       "078"        /*分行地区码*/
#define  ORGCode        "001"        /*本地机构码*/
#define  TTYNCode       "W0010926"   /*网上银行终端号*/ 
#define  OPTPCode       "07"          /*业务类型*/ 

/* 分行个人网络银行参数定义 */
#define  LEN_ICS_PROC_BUF       8192
#define  LEN_POST_MID_PROC_BUF  4096
#define  LEN_MID_PROC_BUF  	4096
#define  LEN_TMP_VAL_STR        256
#define  LEN_TMP_VAL_BUF        1024

#define  LEN_MOBILE_NO		11+1
#define  LEN_PAY_AMT		14+1
#define  LEN_CARD_NO		17+1
#define  LEN_PSSD_NO		6+1


/* 注意,TLNO and AUTL 两者都用相同号码,且程序中设定为AUTL,
   网上银行代理业务柜员号和授权柜员号是0926 */
#define  AUTLCode       "0926"          /*网上银行柜员号*/ 

/*数据库字段长度宏定义*/
/*储蓄系统数据库*/
#define A1               1           /*CICS方式LEN+1*/
#define A0               0           /*TCPIP方式LEN+0*/
#define LEN_RGCD         3           /*地区代号*/
#define LEN_CDST         4           /*地区代号*/

#define LEN_ACOPTM       14          /*开户时间*/
#define LEN_CTOPTM       14          /*证书下载时间*/
#define LEN_CTEDTM       14          /*证书截止时间*/
#define LEN_NCTOPTM      14          /*新证书下载时间*/
#define LEN_NCTEDTM      14          /*新证书截止时间*/ 
#define LEN_TRDTTM       14          /*交易时间*/

#define LEN_CTSQ	 12
#define LEN_CTEL	 15
#define LEN_USNM	 60
#define LEN_NAME	 60		/*客户姓名*/
#define LEN_DEPH	 10
#define LEN_USPH	 10
#define LEN_DEMT	  2
#define LEN_AMT1	 13
#define LEN_AMT2	 13
#define LEN_AMT3	 13
#define LEN_AMT4	 13
#define LEN_AMT5	 13
#define LEN_AMT6	 13
#define LEN_AMNT	 13
#define LEN_SCTF	 13 
#define LEN_BCJF	 13
#define LEN_JFZE	 13
#define LEN_SC03	 82
#define LEN_ZHFY	 13
#define LEN_SYQF	 13
#define LEN_ZUJE	 13
#define LEN_PKQF	 13
#define LEN_ZNJE	 13
#define LEN_ZFZZ	 13
#define LEN_SYJY	 13 







#define LEN_CUID         13          /*客户号*/
#define LEN_NOTP	 1
#define LEN_FISQ	 4
#define LEN_PSWD	 8
#define LEN_NUTP	 1
#define LEN_PYNU	 20
#define LEN_OMSG	 20
#define LEN_AUNO         8           /*授权号*/ 
#define LEN_IDNO         32          /*身份证号码*/
#define LEN_IDTP         1           /*身份证类别*/
#define LEN_CUNM         20          /*客户姓名*/
#define LEN_OPTP         1           /*业务类别*/
#define LEN_CANO         20          /*卡、帐户号码*/
#define LEN_CTNO         10          /*证书号*/
#define LEN_CTST         1           /*证书状态*/
#define LEN_EMAL         32          /*EMAIL地址*/
#define LEN_TEL1         32          /*电话号码*/
#define LEN_TEL		 32          
#define LEN_OGCD         3           /*机构代号*/
#define LEN_TLNO         4           /*柜员代号*/
#define LEN_TTYN         8           /*终端号*/
#define LEN_MGID         7           /*信息码*/
#define LEN_TRCD         4           /*交易代码*/
#define LEN_OANO         20          /*转出帐户*/        
#define LEN_IANO         20          /*转入帐户*/
#define LEN_TRAM         15          /*交易金额*/
#define LEN_AMN0	 15	     /*应收金额*/
#define LEN_AMN1	 15	     /*应收金额*/
#define LEN_AMN2	 15	     /*应收金额*/
#define LEN_ACBL         17          /*帐户余额*/ 
#define LEN_CACO         2           /*帐户个数*/
#define LEN_STNM         8           /*日志流水号*/
#define LEN_CTEF         2           /*证书有效期*/
#define LEN_RFPS         6           /*密码*/ 
#define LEN_AUD2         8           /*授权终止日期*/
#define LEN_CACK         1           /*标志位，区分下载和更新*/
#define LEN_RGCD         3           /*地区代号*/
#define LEN_CDNO         19          /*卡号*/
#define LEN_TRDT         8           /*交易日期*/
#define LEN_TRTM         6           /*交易时间*/
#define LEN_TLCS         8           /*柜员流水号*/
#define LEN_INTT         15          /*累计利息*/
#define LEN_DESP         8           /*DES密码*/
#define LEN_DSMK         1           /*查余额标志*/
#define LEN_ACUR         3           /*重复次数*/
#define LEN_PACUR         3          /*重复次数*/
#define LEN_USEB         17          /*可用余额*/
#define LEN_INAM         15          /*利息*/
#define LEN_PIDNO        20          /*证件号码*/
#define LEN_AUTL         4           /*授权柜员*/
#define LEN_ASAM         15          /*申请金额*/
#define LEN_JYDM         40          /*交易地点中文名称*/
#define LEN_SPTP         1           /*特约商号类型*/
#define LEN_SPCD         4           /*特约商号*/
#define LEN_ACNO         20          /*帐号*/
#define LEN_SPNM         40          /*商户名称*/
#define LEN_BVNM         20          /*网点名称*/
#define LEN_LNAC         20          /*贷款帐号*/
#define LEN_TOBL         17          /*转出帐户余额*/  
#define LEN_TIBL         17          /*转入帐户余额*/
#define LEN_AUNB         6           /*授权号*/
#define LEN_RFPD         6           /*新资金帐户密码*/
#define LEN_CUNB         13          /*客户号*/
#define LEN_SVPD         3           /*存期*/
#define LEN_EXDT         8           /*到期日期*/
#define LEN_INRT         11          /*利率*/
#define LEN_INOV         15          /*到期利息*/
#define LEN_SRNO         3           /*小序号*/
#define LEN_OTCD         3           /*业务代号,填"218"*/
#define LEN_BTMT         2           /*取息间隔*/
#define LEN_INEP         15          /*每次付息金额*/
#define LEN_OGNM         30          /*开户机构名称*/
#define LEN_BLAM         17          /*备用金余额*/
#define LEN_EVAM         15          /*每月存额*/
#define LEN_DGCD         4           /*摘要代码*/
#define LEN_TRFG         1           /*交易标志，'0'：开户，'1'：续存*/
#define LEN_DLTP         1
#define LEN_INTX         15          /*利息税*/
#define LEN_ONAM         15          /*本金*/
#define LEN_TTAM         17          /*总计金额*/
#define LEN_PRFG         1           /*提前支取标志，'0'：到期，'1'：提前*/
#define LEN_INPD         15          /*已付利息*/
#define LEN_ARIN         15          /*本次利息*/
#define LEN_MVIN         15          /*保值利息*/
#define LEN_RLAM         15          /*实际金额*/
#define LEN_ISDT         8           /*起息日期*/
#define LEN_RCNB         8           /*凭证号码*/
#define LEN_CDOU         17          /*转出卡号*/
#define LEN_CDIN         17          /*转入卡号*/
#define LEN_CAOU         20          /*转出卡、帐号*/
#define LEN_CAIN         20          /*转入卡、帐号*/
#define LEN_OGNB         4           /*单位编号*/
#define LEN_TRPS         6           /*交易密码*/
#define LEN_STRN         6           /*起始记录号*/
#define LEN_RCAM         6           /*记录条数*/
#define LEN_CYTP         2           /*货币种类*/
#define LEN_IDDT         8           /*开户日期*/
#define LEN_ISDT         8           /*起息日期*/
#define LEN_IDTL         4           /*开户柜员*/
#define LEN_CFQT         8           /*计费数量*/
#define LEN_AUCR         10          /*重复次数*/
#define LEN_ACFG         1           /*标志（'0'：开户，'1'：追加卡*/
                                     /* '2'：删卡，'3'：删户）*/
#define LEN_SADT         8           /*结算日期*/
#define LEN_ITSG         1           /*科目存储，1：活期 2：定期 3：定活*/
                                     /*4：存本 5：零整 6：通知*/
#define LEN_HMAR         60          /*家庭地址*/
#define LEN_OGAR         60          /*单位地址*/
#define LEN_HMTN         20          /*家庭电话*/
#define LEN_BPNB         20          /*呼机号码*/
#define LEN_OFTN         20          /*办公电话*/
#define LEN_PEMAL        60          /*柜台上传的EMALE长度 */
#define LEN_TRPW         8           /*密码*/ 
#define LEN_TMP          4096
#define LEN_CANO_SIGN    1           /*account sign 1-信用卡，2-借记卡，3-储蓄帐号
                                       4-外汇宝（未用）*/ 
#define LEN_ERR          100          /*错误信息*/

#define LEN_DTTP         1           /*存取标志*/
#define LEN_NOTP         1           /*网点类型*/
#define LEN_SSTP         1           /*资金帐户类型*/
#define LEN_NGPS         8           /*证券资金存取密码*/

#define LEN_BDAC         18          /*资金帐户*/
#define LEN_CUNM         20          /*客户姓名*/
#define LEN_GDCD         10          /*股东代码*/ 

#define LEN_SSTP         1           /*资金帐户类型*/
/*CGI交易代码宏定义*/
/*柜面交易代码宏定义*/
#define AcctOpen         1101        /*柜面开户*/
#define AcctAdd          1102        /*柜面追加帐号*/ 
#define AcctDel          1103        /*单个帐户销户*/ 
#define TLCancel         1104        /*柜面客户号作废*/       
#define Query            1105        /*查询客户号*/  

/*网上交易代码宏定义*/
#define Login            1201        /*客户网上登录*/
#define NetAdd           1202        /*网上追加帐号*/
#define NetDel           1203        /*网上单个帐户销户*/
#define NetCancel        1204        /*网上客户号作废*/
#define QueryTransDetail 1206        /*查询交易名明细*/    

/*CA类交易代码宏定义*/
#define CustomCheck      1301        /*验证客户信息*/
#define CustomFillCIDB   1302        /*回填CIDB证书号*/
#define CustomUpdateCheck 1303       /*客户更新验证信息*/
#define BankCancel       1304        /*银行主动作废*/ 
#define BlackList        1305        /*写黑名单列表*/




/*业务交易代码宏定义*/
#define Trans1101        "1101"
#define Trans1102        "1102"
#define Trans1103        "1103"
#define Trans1104        "1104"
#define Trans1105        "1105"
#define Trans1106        "1106"
#define Trans1201        "1201"
#define Trans1202        "1202"
#define Trans1203        "1203"
#define Trans1204        "1204"
#define Trans1205        "1205"
#define Trans1206        "1206"
#define Trans1301        "1301"
#define Trans1302        "1302"
#define Trans1303        "1303"
#define Trans1304        "1304"
#define Trans1305        "1305"
#define Trans1306        "1306"
#define Trans1307        "1307"
#define Trans1401        "1401"
#define Trans1402        "1402"
#define Trans4620        "4620"
#define Trans4628        "4628"
#define Trans4637        "4637"
#define Trans4690        "4690"
#define Trans4751        "4751"
#define Trans4752        "4752"
#define Trans4755        "4755"
#define Trans4756        "4756"
#define Trans4791        "4791"
#define Trans6101        "6101"
#define Trans6102        "6102"
#define Trans6103        "6103"
#define Trans6105        "6105"
#define Trans6110        "6110"
#define Trans6111        "6111"
#define Trans6112        "6112"
#define Trans6113        "6113"
#define Trans6114        "6114"
#define Trans6115        "6115"
#define Trans6124        "6124"
#define Trans6125        "6125"
#define Trans6126        "6126"
#define Trans6127        "6127"
#define Trans6128        "6128"
#define Trans6129        "6129"
#define Trans6130        "6130"
#define Trans6131        "6131"
#define Trans6132        "6132"
#define Trans6133        "6133"
#define Trans6134        "6134"
#define Trans6135        "1101-1104"  
#define Trans6136	 "1105"
#define Trans6137        "6137"
#define Trans6138        "6138"
#define Trans6139        "6139"
#define Trans8993        "8993"
#define Trans8501        "8501"
#define Trans8585        "8585"
#define Trans8581        "8581"
#define Trans8582        "8582"
#define Trans8701        "8701"
#define Trans8561        "8561"
#define Trans8997        "8997"
#define Trans8993        "8993"
#define Trans8996        "8996"

#define Logtrcd1         "1401" 
#define Logtrcd2         "1402"
/*重庆分行特色业务begin*/
/*1.质押贷款*/
#define Trans8480        "8480"
/*重庆分行特色业务end*/


/*信息代码宏定义*/
#define TRCDNOEXIST      -1000
#define TRANSOVER         0
#define TRANSOK          "AAAAAAA"

#define TRANERRHEAD      "1234567"
#define TRANERRBODY      "系统错"

#define DBACCESSERRDAT   "./dat/dbaccesserr.dat"
#define ERRORLOGDAT      "./dat/errorlog.dat"
#define DBLOGDAT         "./dat/dblog.dat"

#define DEBUG 
#define IO_DEBUG 
#define ACCESS_DEBUG 
#define LOG_DEBUG 

#define TRANQDLX "4"
#define TRANQYBM "8888"
#define TRAM_DHHM "D"
#define TRAN_DHHTH "H"
