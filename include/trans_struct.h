/* 注意
  由于按长度取数据,
  这里的结构定义中域长度都没有考虑结束符\0
*/

/* HSTTIA */
typedef struct ICS_DEF_TIA{
    char CCSCod[4];
    char TTxnCd[6];
    char FeCod[6];
    char TrmNo[7];
    char TxnSrc[5];
    char NodTrc[15];
    char TlrId[7];
    char TIATyp[1];
    char AthLvl[2];
    char Sup1Id[7];
    char Sup2Id[7];
    char Sup1Pw[6];
    char Sup2Pw[6];
    char Sup1Dv[1];
    char Sup2Dv[1];
    char AthTbl[60];
    char AthLog[1];
    char HLogNo[9];
    char CprInd[1];
    char EnpInd[1];
    char NodNo[6];
    char OprLvl[1];
    char TrmVer[8];
    char OutSys[1];
    char Fil[2];
}ICS_DEF_TIA;

/* HSTTOA */
typedef struct ICS_DEF_TOA{
    char Fil1[3];
    char MsgTyp[1];
    char RspCod[6];
    char ErrFld[4];
    char TrmNo[7];
    char TrmSqn[6];
    char STxnCd[4];
    char SAplCd[2];
    char TxnSym[3];
    char TxnDat[8];
    char TxnTm[6];
    char ActDat[8];
    char HLogNo[9];
    char TckNo[11];
    char PagId[1];
    char CprInd[1];
    char EnpInd[1];
    char NodNo[6];
    char AthLog[1];
    char FinFlg[1];
    char AthLvl[2];
    char Sup1Id[7];
    char Sup2Id[7];
    char Fil2[5];
    char DatLen[4];
}ICS_DEF_TOA;

/*
 * 482101
 * 电信缴费前查询
 */

typedef struct ICS_DEF_482101_I{
    char RsFld1[4];        /*第三方交易码*/
    char RsFld2[4];        /*第三方业务类型*/
    char TCusID[30];       /*缴费号码*/
}ICS_DEF_482101_I;

typedef struct ICS_DEF_482101_N{
char  TmpDat[4];                   /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D03*/
char  TCusID[30];                 /*代理号码*/
char  TCusNm[60];                 /*客户姓名*/
char  TxnAmt[15];                  /*交易金额*/
char  RsFld2[4];                  /*业务类型*/
}ICS_DEF_482101_N;

typedef struct ICS_DEF_482101_E{
char  TmpDat[4];                   /*长度*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482101_E;

/*
 * 482102
 * 代收费
 */

typedef struct ICS_DEF_482102_I{
    char RsFld1[4];        /*第三方交易码*/
    char RsFld2[4];        /*第三方业务类型*/
    char TCusID[30];        /*代理号码*/
    char TxnAmt[15];                  /*交易金额*/
    char ActTyp[1];                  /*帐户类型*/
    char ActNo[21];                  /*代扣帐号*/
    char PinBlk[20];                  /*交易密码*/
    char TxCck2[40];                  /*第二磁道*/
    char TxCck3[110];                  /*第三磁道*/
    char  TCusNm[60];      /*客户姓名*//*new add20090104*/
}ICS_DEF_482102_I;

typedef struct ICS_DEF_482102_N{
char  TmpDat[4];                   /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D03*/
char  TCusID[30];                 /*代理号码*/
char  TCusNm[60];                 /*客户姓名*/
char  RcvAmt[15];                  /*交易金额*/
char  TckNo[11];                  /*会计流水*/
char  RsFld2[4];                  /**/
}ICS_DEF_482102_N;

typedef struct ICS_DEF_482102_E{
char  TmpDat[4];                   /*长度*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482102_E;

/*
 * 928460
 * 密码验证
 */

typedef struct ICS_DEF_928460_I{
    char TxnCnl[1];   /* 交易渠道:1-电话银行;2-网银;3-ATM/CDM/CRS;
                    4-POS;5-多媒体;6-手机 */
    char ActNo[21];   /* 帐号 */
    char CusId[13];   /* 客户号 */
    char PINTyp[1];   /* 密码类型 */
    char PINDat[20];    /* 旧密码 */
    char InqFlg[1];   /* 客户信息查询标志:0－不查询;1－查询 */
    char Trk2Dat[37];   /* 转出卡第二磁道信息 */
}ICS_DEF_928460_I;

typedef struct ICS_DEF_928460_N{
char  ApFmt[5];                 /*前端空格式码 48D03*/
char  TCusID[30];                 /*代理号码*/
char  TCusNm[60];                 /*客户姓名*/
char  RcvAmt[15];                  /*交易金额*/
char  TckNo[11];                  /*会计流水*/
char  RsFld2[4];                  /**/
}ICS_DEF_928460_N;

/*
 * 482108
 * 移动查询
 */

typedef struct ICS_DEF_482108_I{
    char RsFld1[4];        /*第三方交易码*/
    char RsFld2[4];        /*第三方业务类型*/
    char TCusID[30];       /*缴费号码*/
    char TxnPin[10];       /*移动密码*/
}ICS_DEF_482108_I;

typedef struct ICS_DEF_482108_N{
char  TmpDat[4];    /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D06*/
char  TCusID[30];               /*代理号码*/
char  TCusNm[60];               /*客户姓名*/
char  TxnAmt[15];               /*交易金额*/
char  RsFld2[4];                /*业务类型*/
}ICS_DEF_482108_N;

typedef struct ICS_DEF_482108_E{
char  TmpDat[4];                 /*长度*/
char  ApCode1[2];                /*SC*/
char  OFmtCd[3];                 /*D04*/
char  RspCod[6];                 /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                /*出错原因*/
}ICS_DEF_482108_E;

/*
 * 482110
 * 移动缴费
 */

typedef struct ICS_DEF_482110_I{
    char RsFld1[4];   /*第三方交易码*/
    char RsFld2[4];   /*第三方业务类型*/
    char TCusID[30];    /*代理号码*/
    char TxnAmt[15];    /*交易金额*/
    char ActTyp[1];   /*帐户类型*/
    char ActNo[21];   /*代扣帐号*/
    char PinBlk[20];    /*交易密码*/
    char TxCck2[40];    /*第二磁道*/
    char TxCck3[110];   /*第三磁道*/
    char TxnPin[10];    /*移动的密码*/
    char  TCusNm[60];                 /*客户姓名*//*new add20090104*/
}ICS_DEF_482110_I;

typedef struct ICS_DEF_482110_N{
char  TmpDat[4];                   /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D03*/
char  TCusID[30];                 /*代理号码*/
char  TCusNm[60];                 /*客户姓名*/
char  RcvAmt[15];                  /*交易金额*/
char  TckNo[11];                  /*会计流水*/
char  RsFld2[4];                  /**/
}ICS_DEF_482110_N;

typedef struct ICS_DEF_482110_E{
char  TmpDat[4];                   /*长度*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482110_E;

/*
 * 461191
 * 公务卡消费明细查询
 */

typedef struct ICS_DEF_461191_I{
char TxnCod[ 6];  /*交易码*/
char PfaSub[ 3];  /*财政代码*/
char BCusId[18];  /*预算单位编码*/
char CardNo[19];  /*卡号*/
char BgnDat[ 8];  /*起始日期*/
char EndDat[ 8];  /*终止日期*/
char MinAmt[15];  /*最低金额*/
char MaxAmt[15];  /*最高金额*/
char Dtlsts[ 1];  /*状态*/
char MaxPNm[ 2];  /*查询最大笔数*/
char PageNm[ 4];  /*查询页号*/    
}ICS_DEF_461191_I;

typedef struct ICS_DEF_461191_O{
char RspCod[ 6];  /*交易返回码*/
char RspMsg[60];  /*交易返回码中文*/
char RecNum[ 4];  /*笔数*/
}ICS_DEF_461191_O;

typedef struct ICS_DEF_461191_G{
char DtlSts[ 1];  /*状态*/
char CardNo[19];  /*公务员卡号*/
char CardNm[30];  /*公务员卡名*/
char TxnDat[ 8];  /*交易日期*/
char TxnTim[ 8];  /*交易时间*/
char MerId [15];  /*商户号*/
char TermId[ 8];  /*终端号*/
char MerNam[43];  /*商户名称*/
char TLogNo[ 6];  /*交易流水号*/
char DtlAmt[15];  /*交易金额*/
char CcyCod[ 3];  /*交易货币*/
char ThdCod[ 4];  /*交易码*/
char AuthCd[ 6];  /*授权号*/
char HActDt[ 8];  /*查询日期*/
char SelVal[ 8];  /*查询批次*/
char SeqNo [ 2];  /*小序号*/
char PfaSub[ 3];  /*财政代码*/
char BCusId[18];  /*预算单位编码*/
char Year  [ 4];  /*财政年度*/
char SubCod[12];  /*预算科目*/
char PrjCod[12];  /*预算项目*/
char EConTp[12];  /*经济分类*/
char DptCod[ 8];  /*业务处室*/
char BokAmt[15];  /*实销金额*/
char BchNo [ 8];  /*报销批次*/
char TActDt[ 8];  /*编制日期*/
char AVchNo[ 8];  /*授权凭证号码*/
}ICS_DEF_461191_G;

/*
 * 482111
 * 联通查询
 */

typedef struct ICS_DEF_482111_I{
    char RsFld1[4];        /*第三方交易码*/
    char RsFld2[4];        /*第三方业务类型*/
    char TCusID[30];       /*缴费号码*/
    char Feeflg[ 1];     /*充值缴费标志0欠费,1充值*/
    char Feefld[ 2];     /*联通业务类型*/
}ICS_DEF_482111_I;

typedef struct ICS_DEF_482111_N{
char  TmpDat[4];    /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D06*/
char  TCusID[30];               /*代理号码*/
char  TCusNm[60];               /*客户姓名*/
char  TxnAmt[15];               /*交易金额*/
char  Arefld[2];
char  BusId[20];
char  RsFld2[4];                /*业务类型*/
}ICS_DEF_482111_N;

typedef struct ICS_DEF_482111_E{
char  TmpDat[4];                 /*长度*/
char  ApCode1[2];                /*SC*/
char  OFmtCd[3];                 /*D04*/
char  RspCod[6];                 /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                /*出错原因*/
}ICS_DEF_482111_E;

/*
 * 482112
 * 联通缴费
 */

typedef struct ICS_DEF_482112_I{
    char RsFld1[4];        /*第三方交易码*/
    char RsFld2[4];        /*第三方业务类型*/
    char TCusID[30];        /*代理号码*/
    char TxnAmt[15];                  /*交易金额*/
    char ActTyp[1];                  /*帐户类型*/
    char ActNo[21];                  /*代扣帐号*/
    char PinBlk[20];                  /*交易密码*/
    char TxCck2[40];          /*第二磁道*/
    char TxCck3[110];     /*第三磁道*/
    char Feeflg[1];   /*充值缴费标志0欠费,1充值*/
    char Feefld[2];   /*联通业务类型*/
    /*char  TCusNm[60];                 客户姓名*//*new add20090104*/
    char Arefld[2];
    char BusId[20];
}ICS_DEF_482112_I;

typedef struct ICS_DEF_482112_N{
char  TmpDat[4];                   /*长度*/
char  ApFmt[5];                 /*前端空格式码 48D01*/
char  TCusID[30];                 /*代理号码*/
char  TCusNm[60];                 /*客户姓名*/
char  RcvAmt[15];                  /*交易金额*/
char  TckNo[11];                  /*会计流水*/
char  RsFld2[4];                  /**/
}ICS_DEF_482112_N;

typedef struct ICS_DEF_482112_E{
char  TmpDat[4];                   /*长度*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482112_E;


/** add by viatt lichen 2008-10-10 begin **/
/*
 * 482115
 * 车船税查询
 */

typedef struct ICS_DEF_482115_I{
  char  RsFld1[4];        /*第三方交易码*/
  char  RsFld2[4];        /*第三方业务类型*/
  char  TCusID[30];       /*缴费号码*/
  char  ActNo[21];        /*代扣帐号*/
  /*char  TxnAmt[15];*/       /*交易金额*/
  char  CarTyp[2];        /*车辆类型：A1大型汽车,A2小型汽车,A5挂车,A6拖拉机,A7农用运输车,C1外籍汽车*/
  /*char  PrvCod[2];*/        /*省份代码：01广东省(粤)*/
  /*char  CtyCod[1]; */       /*城市代码:A广州市*/
  char  CarNo[5];          /*车牌序列号*/
}ICS_DEF_482115_I;

typedef struct ICS_DEF_482115_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D06*/
  char  TCusID[30];      /*代理号码*/
  char  Rsfld3[60];      /*客户姓名*/
  char  STxnAmt[15];     /*金额*/
  char  LoSeq[11];       /*地税流水号*/
  char  PayAmt[15];      /*应缴的税款金额*/
  char  FeeAmt[15];      /*应缴的罚款金额*/
  char  LatAmt[15];      /*应缴的滞纳金金额*/
  char  TCusNm[60];      /*客户姓名*/
}ICS_DEF_482115_N;

typedef struct ICS_DEF_482115_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482115_E;

/*
 * 482116
 * 缴车船税
 */
typedef struct ICS_DEF_482116_I{
  char  RsFld1[4];       /*第三方交易码*/
  char  RsFld2[4];       /*第三方业务类型*/
  char  TCusID[30];      /*缴费号码*/
  char  TxnAmt[15];      /*交易金额*/
  char  ActTyp[1];       /*帐户类型*/
  char  ActNo[21];       /*代扣帐号*/
  char  PinBlk[20];      /*交易密码*/
  char  TxCck2[40];      /*第二磁道*/
  char  TxCck3[110];     /*第三磁道*/
  char  CarTyp[2];       /*车辆类型：A1大型汽车,A2小型汽车,A5挂车,A6拖拉机,A7农用运输车,C1外籍汽车*/
  /*char  PrvCod[2];*/       /*省份代码：01广东省(粤)*/
  /*char  CtyCod[1];*/       /*城市代码:A广州市*/
  char  CarNo[5];        /*车牌序列号*/
  char  LoSeq[11];       /*地税流水号*/
  char  Rsfld3[60];      /*客户姓名*/
  char  TCusNm[60];                 /*客户姓名*//*new add20090104*/
}ICS_DEF_482116_I;

typedef struct ICS_DEF_482116_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  TCusID[30];      /*代理号码*/
  char  TCusNm[60];      /*客户姓名*/
  char  RcvAmt[15];      /*交易金额*/
  char  TckNo[11];       /*会计流水*/
  char  RsFld2[4];       /**/
}ICS_DEF_482116_N;

typedef struct ICS_DEF_482116_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482116_E;

/*
 * 482118
 * 联通售卡
 */
typedef struct ICS_DEF_482118_I{
  char  RsFld1[4];       /*第三方交易码*/
  char  RsFld2[4];       /*第三方业务类型*/
  char  TCusID[30];      /*缴费号码*/
  char  TxnAmt[15];      /*交易金额*/
  char  ActTyp[1];       /*帐户类型*/
  char  ActNo[21];       /*代扣帐号*/
  char  PinBlk[20];      /*交易密码*/
  char  TxCck2[40];      /*第二磁道*/
  char  TxCck3[110];     /*第三磁道*/
  char  Cartyp[4];       /*购卡类型：50面值 0300,100面值 0301*/
  char  MobTel[60];      /*联系电话*/
}ICS_DEF_482118_I;

typedef struct ICS_DEF_482118_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  TCusID[30];      /*代理号码*/
  char  TCusNm[60];      /*客户姓名*/
  char  RcvAmt[15];      /*交易金额*/
  char  TypTel[12];       /*购卡类型+交费易序列号*/
  char  CarMes[60];       /*卡信息参考注释*/
}ICS_DEF_482118_N;
            
typedef struct ICS_DEF_482118_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482118_E;

/*
 * 482171
 * 广东移动用户状态查询
 */

typedef struct ICS_DEF_482171_I{
  char  user_number[20];        /*手机号码*/
}ICS_DEF_482171_I;

typedef struct ICS_DEF_482171_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  user_number[20]; /*手机号码*/
  char  User_status[2];  /*手机状态*/
}ICS_DEF_482171_N;

typedef struct ICS_DEF_482171_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482171_E;

/*
 * 482172
 * 用户应缴费用查询
 */

typedef struct ICS_DEF_482172_I{
  char  user_number[20];        /*手机号码*/
}ICS_DEF_482172_I;

typedef struct ICS_DEF_482172_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  user_number[20]; /*手机号码*/
  char  amount[12];      /*应缴金额*/
}ICS_DEF_482172_N;

typedef struct ICS_DEF_482172_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482172_E;

/*
 * 482173
 * 缴车船税
 */
typedef struct ICS_DEF_482173_I{
  char  user_number[20]; /*手机号码*/
  char  TxnAmt[15];      /*交易金额*/ 
  char  ActTyp[1];       /*帐户类型*/
  char  ActNo[21];       /*代扣帐号*/
  char  PinBlk[20];      /*交易密码*/
  char  TxCck2[40];      /*第二磁道*/
  char  TxCck3[110];     /*第三磁道*/
}ICS_DEF_482173_I;

typedef struct ICS_DEF_482173_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  user_number[20]; /*手机号码*/
  char  RcvAmt[15];      /*交易金额*/
  char  TckNo[11];       /*会计流水*/
}ICS_DEF_482173_N;

typedef struct ICS_DEF_482173_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482173_E;


/*
 * 
 * 银旅通
 */ 
typedef struct ICS_DEF_482131_I{
  char  Reserve_Code[12];   /*服务商*/  
  char  Member_id[8];       /*单位号*/  
}ICS_DEF_482131_I;

typedef struct ICS_DEF_482131_N{
  char  TmpDat[4];                    /*长度*/
  char  ApFmt[5];                     /*前端空格式码 48D01*/
  char  Product_Name[200];            /*预定内容*/
  char  Provide_Name[30];             /*服务商*/
  char  Trans_Toal_Amount[14];        /*总金额*/
  char  Paid_Amount[14];              /*已付金额*/  
  char  Arrearage_Amount[14];         /*欠费金额*/  
  char  Return_Code[3];               /*处理结果*/    
  char  PB_Return_Code_Msg[50];       /*处理结果信息*/      
}ICS_DEF_482131_N;

typedef struct ICS_DEF_482131_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482131_E;
 
typedef struct ICS_DEF_482132_I{
  char  TCusNm[12];         /*订单编号*/
  char  Member_id[8];       /*单位号*/
  char  ActTyp[1];          /*帐号类型*/
  char  ActNo[21];          /*代扣帐号*/
  char  PinBlk[20];         /*交易密码*/
  char  TxCck2[40];         /*第二磁道*/  
  char  TxCck3[110];        /*第三磁道*/  
  char  Trans_Amount1[14];  /*交易金额*/  
  char  Provide_Name[50];   /*服务商*/  
  char  Product_Name[60];   /*预定内容*/  
}ICS_DEF_482132_I;

typedef struct ICS_DEF_482132_N{
  char  TmpDat[4];                    /*长度*/
  char  ApFmt[5];                     /*前端空格式码 48D01*/
  char  TCusNm[12];                   /*订单编号*/
  char  ThdKey[18];                   /*银行交易流水号*/
  char  Return_Code[3];               /*处理结果*/
  char  PB_Return_Code_Msg[30];       /*处理结果信息*/
  char  TckNo[11];                      /*会计流水*/
}ICS_DEF_482132_N;

typedef struct ICS_DEF_482132_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482132_E;


typedef struct ICS_DEF_482133_I{
  char  PagIdx[6];      /*页号*/
}ICS_DEF_482133_I;

typedef struct ICS_DEF_482133_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  SumCnt[4];       /*总记录数*/
  char  PagNo[4];        /*页数*/
  char  RecNum[4];       /*条数*/
}ICS_DEF_482133_N;

typedef struct ICS_DEF_482133_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482133_E;

typedef struct ICS_DEF_482134_I{
  char  Provider_Code[12];      /*景区代码*/
}ICS_DEF_482134_I;

typedef struct ICS_DEF_482134_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  SumCnt[4];       /*总记录数*/
  char  PagNo[4];        /*页数*/
  char  RecNum[4];       /*条数*/
}ICS_DEF_482134_N;

typedef struct ICS_DEF_482134_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482134_E;

typedef struct ICS_DEF_482135_I{
  char  Product_Code[12];         /*门票代码*/
  char  Retail_Price1[14];        /*门市价*/
  char  E_Discount_Price1[14];    /*电子优惠价*/
  char  Reserve_Amoun[4];         /*预订产品数量*/
  char  Mobile_Phone_Number[11];  /*手机号码*/
  char  Begin_Date[8];            /*使用日期*/
  char  Message_Type[2];          /*短信类型*/
  char  Amount1[14];              /*总金额*/
  char  ActTyp[1];                /*帐号类型--NULLABLE*/
  char  ActNo[21];                /*代扣帐号*/
  char  PinBlk[20];               /*交易密码*/
  char  TxCck2[40];               /*第二磁道--NULLABLE*/
  char  TxCck3[110];              /*第三磁道--NULLABLE*/
  char  Scence_Code[12];          /*景区代码*/
  char  Scence_Name[60];          /*景区名称*/
  char  Product_Name[50];         /*门票名称*/
  char  Remark1[160];             /*备注*/
  char  Valid_Days[3];            /*有效天数*/            
}ICS_DEF_482135_I;

typedef struct ICS_DEF_482135_N{
  char  TmpDat[4];                /*长度*/
  char  ApFmt[5];                 /*前端空格式码 48D01*/
  char  TCUSNM[12];               /*订单编号*/
  char  ThdKey[18];               /*银行交易流水号*/
  char  TXNAMT[14];               /**/
  char  Return_Code[3];           /*处理结果*/
  char  PB_Return_Code_Msg[30];   /*处理结果信息*/
  char  Remark1[160];             /*备注*/
  char  TckNo[11];                /*会计流水*/
}ICS_DEF_482135_N;

typedef struct ICS_DEF_482135_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482135_E;


typedef struct ICS_DEF_482147_I{
  char  ActNo[21];
}ICS_DEF_482147_I;

typedef struct ICS_DEF_482147_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  SumCnt[4];       /*总记录数*/
  char  PagNo[4];        /*页数*/
}ICS_DEF_482147_N;

typedef struct ICS_DEF_482147_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482147_E;
/** add by viatt lichen 2008-10-10 end **/

/** add by viatt lichen 2009-01-07 begin **/
typedef struct ICS_DEF_481152_I{
  char  TxnDat[8];      /*日期*/
  char  AbuTyp[4];      /*卡类*/
}ICS_DEF_481152_I;

typedef struct ICS_DEF_481152_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  PagNo[4];        /*页数*/
  char  VarSize[1];      /*总数*/
  char  Ttl[21];         /*充值卡有效卡种浏览*/
  char  SubTtl[11];      /*查询内容*/
  char  RecNum[3];       /*条数*/
}ICS_DEF_481152_N;

typedef struct ICS_DEF_481152_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_481152_E;

typedef struct ICS_DEF_481143_I{
  char  TxnDat[8];        /*交易日期*/
  char  AbuTyp[4];        /*卡类*/
  char  BusNam[16];       /*卡种*/
  char  TxnAmt[15];       /*卡面值*/
  char  ActTyp[1];        /*帐号类型*/
  char  ActNo[21];        /*代扣帐号*/  
  char  PinBlk[20];       /*交易密码*/  
  char  TxCck2[40];       /*第二磁道*/  
  char  TxCck3[110];      /*第三磁道*/    
}ICS_DEF_481143_I;

typedef struct ICS_DEF_481143_N{
  char  TmpDat[4];        /*长度*/
  char  ApFmt[5];         /*前端空格式码 48D43*/
  char  AbuTyp[4];        /*卡类*/
  char  BusNam[16];       /*卡种*/
  char  TxnAmt[15];       /*卡面值*/
  char  MIdNo[30];        /*卡序列号*/
  char  VchNo[30];        /*充值卡号*/
  char  OpfPin[30];       /*充值卡密码*/
  char  TxnDat[8];        /*交易日期*/
  char  EndDat[8];        /*有效日期*/
  char  TckNo[11];        /*会计流水*/
  char  BilRmk[80];       /*充值方法*/
}ICS_DEF_481143_N;

typedef struct ICS_DEF_481143_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_481143_E;

typedef struct ICS_DEF_482145_I{
  char  ActNo[32];          /*代扣帐号*/
  char  Jflx[2];            /*业务类型*/
}ICS_DEF_482145_I;

typedef struct ICS_DEF_482145_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  SumCnt[4];       /*总数*/
  char  PagNo[4];        /*页数*/
  char  Stsxx[150];       /*温馨提示*/
  char  RecNum[4];       /*条数*/
}ICS_DEF_482145_N;

typedef struct ICS_DEF_482145_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482145_E;

typedef struct ICS_DEF_482140_I{
  char  ActNo[21];          /*帐号*/
  char  Ccy[3];             /*币种*/
  char  InFlg[1];           /*账卡标识*/
  char  BusTyp[3];          /*JJ码,外币时必输*/
  char  AcSeq[5];           /*帐号序号,账卡标识为一本通时，必输*/
}ICS_DEF_482140_I;

typedef struct ICS_DEF_482140_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  ActNo[21];
  char  CcyCod[3];
  char  ActTyp[1];
  char  Bal[15];
  char  HldAmt[15];
  char  ActSts[1];
  char  CrdTyp[1];
  char  VchCod[3];
  char  Vch[8];
  char  IDTyp[2];
  char  IDNo[30];
  char  CusNo[13];
  char  ActNam[60];
  char  ManFlg[1];
  char  CpFlg[1];
}ICS_DEF_482140_N;

typedef struct ICS_DEF_482140_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482140_E;
/** add by viatt lichen 2009-01-07 end **/

/*add by viatt linzw 2009-02-18 begin*/
typedef struct ICS_DEF_482149_I{
  char  bank_acc[32];           /*代扣帐号*/
}ICS_DEF_482149_I;

typedef struct ICS_DEF_482149_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  sign_flag[1];     /*签约类型 0-网银 1-自助通 */
  char  inst_no[9];       /*签约机构 */
  char  live_flag[1];     /*激活标志 0-激活 1-未激活 */
  char  tran_flag[1];     /*交易标志 0-允许交易 1-不允许交易 */
  char  acc_type[1];      /*扣款方式 1:预扣款用户 0:实时扣款用户 */
  char  yct_pwd[10];      /*羊城通密码 */
  char  bank_acc[30];     /*账号 */
  char  oper_tlr[3];      /*操作员 */
  char  tran_date[14];    /*交易日期 */
  char  sys_no[12];       /*系统参考号 */
  char  ret_code[2];      /*响应代码 */
  char  paper_no[21];     /*证件类型号码 */
  char  contact_no[20];   /*合同编号 */
  char  cust_name[30];    /*用户姓名 */
  char  sex_code[1];      /*性别 */
  char  phone_no[15];     /*电话号码 */
  char  mobile_no[15];    /*手机号码 */
  char  post_no[6];       /*邮编 */
  char  address[50];      /*地址 */
  char  email[50];        /*email邮箱 */
  char  card1[10];        /* 羊城通卡号1 */
  char  card2[10];        /* 羊城通卡号2 */
  char  card3[10];        /* 羊城通卡号3 */
  char  card4[10];        /* 羊城通卡号4 */
  char  limite[12];       /*额度 */
  char  frequence[4];     /*频度 */
  char  reg_date[4];      /*签约日期 */
  char  cncl_date[4];     /*解约日期 */
  char  cncl_flag[4];     /* 签解约标志 0 - 签约 1 - 解约 */
   /*char  address[50];     地址 */
  char  reserve1[30];     /*  预留字段1 */
  char  reserve2[30];     /*  预留字段2 */
  char  reserve3[30];     /*  预留字段3 */
  char  reserve4[60];     /*  预留字段4 */
  char  reserve5[60];     /*  预留字段5 */
}ICS_DEF_482149_N;

typedef struct ICS_DEF_482149_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482149_E;
/*签约*/
typedef struct ICS_DEF_482138_I{
    char  sign_flag[1];          /*签约类型 0-网银 1-自助通 */
    char  inst_no[9];            /*签约机构 */
    char  live_flag[1];            /*激活标志 0-激活 1-未激活 */
    char  tran_flag[1];            /*交易标志 0-允许交易 1-不允许交易 */
    char  acc_type[1];            /*扣款方式 1:预扣款用户 0:实时扣款用户 */
    char  yct_pwd[10];            /*羊城通密码 */
    char  bank_acc[19];           /*账号 */
    char  oper_tlr[3];           /*操作员 */
    char  tran_date[14];           /*交易日期 */
    char  sys_no[12];           /*系统参考号 */
    char  ret_code[2];           /*响应代码 */
    char  paper_no[21];           /*证件类型号码 */
    char  contact_no[20];           /*合同编号 */
    char  cust_name[30];           /*用户姓名 */
    char  sex_code[1];           /*性别 */
    char  phone_no[15];           /*电话号码 */
    char  mobile_no[15];           /*手机号码 */
    char  post_no[6];           /*邮编 */
    char  address[50];           /*地址 */
    char  email[50];           /*email邮箱 */
    char  card1[10];           /* 羊城通卡号1 */
    char  card2[10];           /* 羊城通卡号2 */
    char  card3[10];           /* 羊城通卡号3 */
    char  card4[10];           /* 羊城通卡号4 */
    char  limite[12];           /*额度 */
    char  frequence[4];           /*频度 */
    char  reg_date[4];           /*签约日期 */
    char  cncl_date[4];           /*解约日期 */
    char  cncl_flag[4];           /* 签解约标志 0 - 签约 1 - 解约 */
     /*char  address[50];          地址 */
    char  reserve1[30];           /*  预留字段1 */
    char  reserve2[30];           /*  预留字段2 */
    char  reserve3[30];           /*  预留字段3 */
    char  reserve4[60];           /*  预留字段4 */
    char  reserve5[60];           /*  预留字段5 */
    char  PinBlk[20];           /*  交易密码 */
}ICS_DEF_482138_I;

typedef struct ICS_DEF_482138_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  sys_no[12];    /*系统参考号码*/
}ICS_DEF_482138_N;

typedef struct ICS_DEF_482138_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482138_E;
/* 解约*/
typedef struct ICS_DEF_482139_I{
    char  sign_flag[1];     /*签约类型 0-网银 1-自助通 */
    char  inst_no[9];            /*签约机构 */
    char  bank_acc[19];           /*账号 */
    char  card1[10];           /* 解约羊城通卡号1 */
    char  card2[10];           /* 解约羊城通卡号2 */
    char  card3[10];           /* 解约羊城通卡号3 */
}ICS_DEF_482139_I;

typedef struct ICS_DEF_482139_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  sys_no[12];    /*系统参考号码*/
}ICS_DEF_482139_N;

typedef struct ICS_DEF_482139_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482139_E;
/* 激活*/
typedef struct ICS_DEF_482136_I{
    char  bank_acc[19];           /*账号 */
    char  card1[10];           /* 激活羊城通卡号1 */
}ICS_DEF_482136_I;

typedef struct ICS_DEF_482136_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/ 
  char  sys_no[12];    /*系统参考号码*/
}ICS_DEF_482136_N;

typedef struct ICS_DEF_482136_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482136_E;
typedef struct ICS_DEF_482159_I{
  char  ActNo[21];
}ICS_DEF_482159_I;

typedef struct ICS_DEF_482159_N{
  char  TmpDat[4];       /*长度*/
  char  ApFmt[5];        /*前端空格式码 48D01*/
  char  SumCnt[4];       /*总记录数*/
  char  PagNo[4];        /*页数*/
}ICS_DEF_482159_N;

typedef struct ICS_DEF_482159_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482159_E;
/*add by viatt linzw 2009-02-18 end*/

/*add by xuan for test */
typedef struct ICS_DEF_482999_I{
  char  Reserve_Code[12];   /*服务商*/  
  char  Member_id[8];       /*单位号*/  
}ICS_DEF_482999_I;

typedef struct ICS_DEF_482999_N{
  char  TmpDat[4];                    /*长度*/
  char  ApFmt[5];                     /*前端空格式码 48D01*/
  char  Product_Name[200];            /*预定内容*/
  char  Provide_Name[30];             /*服务商*/
  char  Trans_Toal_Amount[14];        /*总金额*/
  char  Paid_Amount[14];              /*已付金额*/  
  char  Arrearage_Amount[14];         /*欠费金额*/  
  char  Return_Code[3];               /*处理结果*/    
  char  PB_Return_Code_Msg[50];       /*处理结果信息*/      
}ICS_DEF_482999_N;

typedef struct ICS_DEF_482999_E{
  char  TmpDat[4];       /*长度*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*出错原因*/
}ICS_DEF_482999_E;

/*
 * 
 *程序名:体育彩票
 *日  期:2010.06.21
 */
/* 482101 体彩购彩交易*/
typedef struct ICS_DEF_482101_I_TC{
  char  CrdNo [30];                   /*卡号       */
  char  TxnAmt[15];                   /*交易金额   */
  char  TrmCod[15];                   /*期号       */
  char  TikMod[2];                    /*购票方式   */
  char  LotTyp[2];                    /*彩票类型   */
  char  SigDup[2];                    /*单复式区分 */
  char  NotNum[5];                    /*注数       */
  char  MulTip[2];                    /*倍数       */
  char  ExtNum[2];                    /*扩展号码   */
  char  LotNum[100];                  /*投注号码   */
  char  CntTel[20];                   /*手机号码   */
  char  PinBlk[20];                   /*交易密码   */
}ICS_DEF_482101_I_TC;

typedef struct ICS_DEF_482101_N_TC{
  char  TmpDat[4];                   /*返回包体长度*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*状态       */
  char  LogNo[14];                    /*交行流水号 */
  char  TLogNo[30];                   /*购彩流水号 */
  char  NotNum[5];                    /*注数       */
  char  LotNum1[20];                  /*注1        */
  char  LotNum2[20];                  /*注2        */
  char  LotNum3[20];                  /*注3        */
  char  LotNum4[20];                  /*注4        */
  char  LotNum5[20];                  /*注5        */
  char  LotNum6[100];                 /*复式注     */
  char  MulTip[2];                    /*倍数       */
  char  TrmCod[15];                   /*期号       */
}ICS_DEF_482101_N_TC;

typedef struct ICS_DEF_482101_E_TC{
  char  TmpDat[4];                    /*长度       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*错误码     */
  char  RspMsg[54];                   /*出错原因   */
}ICS_DEF_482101_E_TC;

/* 482102 体彩购彩号码校验*/
typedef struct ICS_DEF_482102_I_TC{
  char  TikMod[2];                    /*购票方式   */
  char  SigDup[2];                    /*单复式区分 */
  char  NotNum[5];                    /*机选注数   */
  char  LotNum[100];                  /*投注号码   */
  char  LotTyp[2];                    /*彩票类型   */
  char  MulTip[2];                    /*倍数       */
  char  ExtNum[2];                    /*扩展号码   */
}ICS_DEF_482102_I_TC;

typedef struct ICS_DEF_482102_N_TC{
  char  TmpDat[4];                   /*返回包体长度*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*状态       */
  char  NotNum[5];                    /*注数       */
  char  LotNum1[20];                  /*注1        */
  char  LotNum2[20];                  /*注2        */
  char  LotNum3[20];                  /*注3        */
  char  LotNum4[20];                  /*注4        */
  char  LotNum5[20];                  /*注5        */
  char  LotNum6[100];                 /*复式注     */
  char  TxnAmt[15];                   /*金额       */
  char  MulTip[2];                    /*倍数       */
  char  TrmCod[15];                   /*期号       */
}ICS_DEF_482102_N_TC;

typedef struct ICS_DEF_482102_E_TC{
  char  TmpDat[4];                    /*长度       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*错误码     */
  char  RspMsg[56];                   /*出错原因   */
}ICS_DEF_482102_E_TC;

/* 482103 体彩查询投注情况交易*/
typedef struct ICS_DEF_482103_I_TC{
  char  TLogNo[30];                   /*购彩流水号 */ 
}ICS_DEF_482103_I_TC;

typedef struct ICS_DEF_482103_N_TC{
  char  TmpDat[4];                   /*返回包体长度*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*状态       */
  char  TrmCod[15];                   /*期号       */
  char  SigDup[2];                    /*单复式类型 */
  char  LotTyp[2];                    /*彩票类型   */ 
  char  TLogNo[30];                   /*购彩流水号 */ 
  char  LotNum[150];                  /*投注号码     */
  char  NotNum[5];                    /*注数       */     
  char  TxnAmt[15];                   /*金额       */     
}ICS_DEF_482103_N_TC;

typedef struct ICS_DEF_482103_E_TC{
  char  TmpDat[4];                    /*长度       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*错误码     */
  char  RspMsg[56];                   /*出错原因   */
}ICS_DEF_482103_E_TC;

/*
 * 482180
 * 广东省电信查询号码归属地
 */

typedef struct ICS_DEF_482180_I{
    char TCusID[20];       /*缴费号码*/
}ICS_DEF_482180_I;

typedef struct ICS_DEF_482180_N{
  char  TmpDat[4];                  /*长度*/
  char  ApFmt[5];                   /*前端空格式码 48D03*/
  char  TCusID[20];									/*缴费号码*/
  char  DqCode[5];								/*地区号码*/
}ICS_DEF_482180_N;

typedef struct ICS_DEF_482180_E{
  char  TmpDat[4];                   /*长度*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482180_E;

/*
 * 482181
 * 广东省电信充值前查询
 */

typedef struct ICS_DEF_482181_I{
  char TCusID[20];       /*缴费号码*/
  char DestAttr[4];      /*用户属性*/
}ICS_DEF_482181_I;

typedef struct ICS_DEF_482181_N{
  char  TmpDat[4];                  /*长度*/
  char  ApFmt[5];                   /*前端空格式码 48D03*/
  char  BalTyp[8];                  /*余额类型*/
  char  Balance[12];                /*余额*/
  char  BalanceUnit[2];             /*余额单位*/
  char  EffTime[14];                /*余额有效期开始时间*/
  char	ExpireTime[14];             /*余额到期时间，YYYYMMDDHHMMSS*/
}ICS_DEF_482181_N;

typedef struct ICS_DEF_482181_E{
  char  TmpDat[4];                  /*长度*/
  char  ApCode1[2];                 /*SC*/
  char  OFmtCd[3];                  /*D04*/
  char  RspCod[6];                  /**/
  char  InPos[4];                   /*0001*/
  char  RspMsg[56];                 /*出错原因*/
}ICS_DEF_482181_E;

/*
 * 482182
 * 广东省电信用户属性查询
 */

typedef struct ICS_DEF_482182_I{
  char TCusID[20];       /*缴费号码*/
  char DestAttr[4];      /*用户属性*/
}ICS_DEF_482182_I;

typedef struct ICS_DEF_482182_N{
  char  TmpDat[4];                  /*长度*/
  char  ApFmt[5];                   /*前端空格式码 48D03*/
  char  BillMode[3];                 /*用户付费属性*/
  char  DestAttr[4];                /*被查询用户属性*/
  char  DqCode[5];             			/*号码归属地区号*/
  char  objectHome[2];              /*号码归属平台*/
}ICS_DEF_482182_N;

typedef struct ICS_DEF_482182_E{
  char  TmpDat[4];                   /*长度*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482182_E;

/*
 * 482183
 * 广东省电信用户属性查询带余额
 */

typedef struct ICS_DEF_482183_I{
  char TCusID[20];        /*缴费号码*/
  char TxnAmt[15];       /*交易金额*/
  char DestAttr[4];       /*用户属性*/
  char ActTyp[1];         /*帐户类型*/
  char ActNo[21];         /*代扣帐号*/
  char PinBlk[20];        /*交易密码*/
  char TxCck2[40];        /*第二磁道*/
  char TxCck3[110];       /*第三磁道*/
}ICS_DEF_482183_I;

typedef struct ICS_DEF_482183_N{
  char  TmpDat[4];                  /*长度*/
  char  ApFmt[5];                   /*前端空格式码 48D03*/
  char  BalTyp[8];                  /*余额类型*/
  char  Balance[12];                /*余额*/
  char  BalanceUnit[2];             /*余额单位*/
  char  EffTime[14];                /*余额有效期开始时间*/
  char	ExpireTime[14];             /*余额到期时间，YYYYMMDDHHMMSS*/
  char  TckNo[11];                  /*会计流水*/
}ICS_DEF_482183_N;

typedef struct ICS_DEF_482183_E{
  char  TmpDat[4];                   /*长度*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482183_E;

/*
 * 482184
 * 广东省电信用户属性带余额查询
 */

typedef struct ICS_DEF_482184_I{
  char TCusID[20];       /*缴费号码*/
  char DestAttr[4];      /*用户属性*/
}ICS_DEF_482184_I;

typedef struct ICS_DEF_482184_N{
  char  TmpDat[4];                  /*长度*/
  char  ApFmt[5];                   /*前端空格式码 48D03*/  
  char  BalTyp[8];                  /*余额类型*/
  char  Balance[12];                /*余额*/
  char  EffTime[14];                /*余额有效期开始时间*/
  char	ExpireTime[14];             /*余额到期时间，YYYYMMDDHHMMSS*/
  char  BillMode[3];                /*用户付费属性*/
  char  DestAttr[4];                /*被查询用户属性*/
  char  DqCode[5];             			/*号码归属地区号*/
  char  objectHome[2];              /*号码归属平台*/
  char 	TCusID[20];       					/*缴费号码*/
  char	Param1[40];									/*预留字段*/
}ICS_DEF_482184_N;

typedef struct ICS_DEF_482184_E{
  char  TmpDat[4];                   /*长度*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*出错原因*/
}ICS_DEF_482184_E;

/*
 * 460244
 * 电费缴费前查询
 */
typedef struct ICS_DEF_460244_I{
        char ActNo[21];   /*银行卡号*/
        char TCusId[21];     /*客户编号*/
        char LChkTm[8];  /*电费月份：99999999表示所有欠费，yyyymm99当月所有欠费*/
}ICS_DEF_460244_I;

typedef struct ICS_DEF_460244_N{
        char TmpDat[4];      /*package length*/ 
        char ApCode[2];     /*SC*/
        char OFmtCd[3];     /*D04*/
        char TxnAmt[15];   /*交易金额*/
        char ChkTim[10];   /*交易日期时间*/
        char DptTyp[4];    /*配营部类型*/
        char UsrNam[23];   /*用户姓名*/
        char UsrAdd[32];   /*用电地址*/
 }ICS_DEF_460244_N;

typedef struct ICS_DEF_460244_E{
        char TmpDat[4];     /*package length*/
        char ApCode[2];     /*SC*/
        char OFmtCd[3];     /*D04*/
        char  RspCod[6];    /* */
        char InPos[4];     /*0001*/
        char RspMsg[56];/*出错原因*/
}ICS_DEF_460244_E;

/*
 * 460245
 *电费缴纳实时缴费交易
 */
typedef struct ICS_DEF_460245_I{
        char ActNo[21];   /*主账号*/
        char TCusId[21];  /*客户编号*/
        char TCusNm[23];  /*用户姓名*/
        char LChkTm[8];   /*电费月份：99999999表示所有欠费，yyyymm99当月所有欠费*/
        char DptTyp[4];   /*配型部类型*/
        char TxnAmt[12];  /*交易金额*/
        char Fee[12];     /*交易手续费*/
        char VchTyp[3];   /*结算凭证*/
        char VchNo[8];    /*凭证号*/
        char BilDat[8];   /*凭证日期*/
        char PinBlk[20];  /*密码*/
}ICS_DEF_460245_I;

typedef struct  ICS_DEF_460245_N{
        char TmpDat[4];   /*package length*/
	char ApCode[2];   /*"SC"*/
        char OFmtCd[3];  /*"D04"*/
        char TLogNo[12];  /*供电公司系统参考号*/
        char TckNo[12];   /*会计业务流水号*/
        char TActDt[4];   /*供电公司清算日期*/
}ICS_DEF_460245_N;

typedef struct ICS_DEF_460245_E{
        char TmpDat[4];
	char ApCode[2];  /*"SC"*/
        char OFmtCd[3];  /*"D04"*/
        char RspCod[6];  /* */
        char InPos[4];   /*0001*/
        char RspMsg[56]; /* */
        char LogNo[14];  /*  */
        char TckNo[12];  /*  */
}ICS_DEF_460245_E;  

/*
 * 460501
 * 移动划扣充值业务签约交易
 */
typedef struct ICS_DEF_460501_I_MOB{
    char SigTyp[1];   /*签约类型*/
    char VchNO[8];  /*凭证号*/
    char ActTyp[1];  /*账号类型*/
    char ActNo[28];   /*银行账号*/
    char ActNam[32];   /*银行账号名称*/
    char IdTyp[02];  /*证件类型*/
    char IdNo[20];     /*证件号码*/
    char CusNam[32];   /*客户姓名*/
    char MstTel[20];    /*主手机号码*/
    char SigTel[20];   /*签约手机号码*/
    char SigFlg[1];  /*签约标记（主0/副1）*/
    char PINDat[20];  /*银行交易密码*/
}ICS_DEF_460501_I_MOB;

typedef struct  ICS_DEF_460501_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char MstTel[20];  /*主手机号码*/
    char SigTel[20];   /*签约手机号码*/
    char LogNo[30];   /*移动返回流水号*/
}ICS_DEF_460501_N_MOB;

typedef struct ICS_DEF_460501_E_MOB{
    char TmpDat[4];
    char ApCode[2];  /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char RspCod[6];  /* */
    char InPos[4];   /*0001*/
    char RspMsg[56]; /* */
}ICS_DEF_460501_E_MOB;  

/*
 * 460506
 * 移动划扣充值业务解约交易
 */
typedef struct ICS_DEF_460506_I_MOB{
    char  BisTyp  [1]   ; /*交易类型1：主号捆绑解除；2：全部签约号码解除*/
    char  ActTyp  [1]   ; /*账号类型*/
    char  ActNo   [28]  ; /*银行账号*/
    char  ActNam  [32]  ; /*银行账号名称*/
    char  VchNO   [8]   ; /*凭证号*/
    char  IdTyp   [2]   ; /*证件类型*/
    char  IdNo    [20]  ; /*证件号码*/
    char  CusNam  [32]  ; /*证件姓名*/
    char  MstTel  [20]  ; /*主手机号码*/
    char  PINDat  [20]  ; /*银行交易密码*/
}ICS_DEF_460506_I_MOB;

typedef struct  ICS_DEF_460506_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  ActTyp  [1]   ; /* 账号类型 */
    char  ActNo   [28]  ; /*银行账号*/
    char  IdTyp   [2]   ; /* 证件类型 */
    char  IdNo    [20]  ; /* 证件号码 */
    char  CusNam  [32]  ; /* 证件姓名 */
    char  MstTel  [20]  ; /* 主手机号码 */
}ICS_DEF_460506_N_MOB;

typedef struct ICS_DEF_460506_E_MOB{
    char TmpDat[4];
    char ApCode[2];  /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char RspCod[6];  /* */
    char InPos[4];   /*0001*/
    char RspMsg[56]; /* 错误信息 */
}ICS_DEF_460506_E_MOB;  

/*
 * 460511
 * 查询账户信息（嵌套）
 */
typedef struct ICS_DEF_460511_I_MOB{
    char  ActNo  [21]   ; /*帐号*/
}ICS_DEF_460511_I_MOB;

typedef struct  ICS_DEF_460511_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  IdTyp  [2]  ; /*证件种类*/
    char  IdNo   [20] ; /*证件号码*/
    char  ActNam [32] ; /*户名*/
    char  ActSts [1]  ; /*帐户状态*/
}ICS_DEF_460511_N_MOB;

typedef struct ICS_DEF_460511_E_MOB{
    char TmpDat[4];
    char ApCode[2];  /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char RspCod[6];  /* */
    char InPos[4];   /*0001*/
    char RspMsg[56]; /* 错误信息 */
}ICS_DEF_460511_E_MOB;  

/*
 * 通用错误
 */
typedef struct ICS_DEF_DEFAULT_E{
    char  TmpDat[4];
    char  ApCode[2];  /*SC*/
    char  OFmtCd[3];  /*D04*/
    char  RspCod[6];  /* */
    char  InPos[4];   /*0001*/
    char  RspMsg[56]; /* 错误信息 */
}ICS_DEF_DEFAULT_E;  


/*
 * 460601
 * 被充值号码验证(010201)
 */
typedef struct ICS_DEF_460601_I_MOB{
    char  TelNum  [20]   ; /*帐号*/
}ICS_DEF_460601_I_MOB;

typedef struct  ICS_DEF_460601_N_MOB{
    char  TmpDat  [4];   /*package length*/
    char  ApCode  [2];   /*SC*/
    char  OFmtCd  [3];  /*D04*/
    char  AreCod  [4]  ; /*地区号*/
}ICS_DEF_460601_N_MOB;

/*
 * 460602
 * 给被充值号码充值(010202)
 */
typedef struct ICS_DEF_460602_I_MOB{
    char  TelNum  [20];  /*被充值号码*/
    char  CrdNo   [21];  /*卡号*/
    char  TxnAmt  [15];  /*充值金额*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460602_N_MOB{
    char  TmpDat  [4];   /*package length*/
    char  ApCode  [2];   /*SC*/
    char  OFmtCd  [3];  /*D04*/
    char  ActDat  [8];  /*会计日期*/
    char  TckNo   [12];  /*会计流水号*/
    char  TLogNo  [20];  /*联通流水号*/
}ICS_DEF_460602_N_MOB;

/*
 * 460606
 * 通过卡号查询缴费会计流水号
 * TODO 研究拆包方式
 */
typedef struct ICS_DEF_460606_I_MOB{
    char  CrdNo  [15];    /*卡号*/
    char  PagIdx  [6];    /*页码编号*/
}ICS_DEF_460606_I_MOB;

typedef struct  ICS_DEF_460606_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*SC*/
    char OFmtCd[3];  /*D04*/
    char  SumCnt[4];       /*总记录数*/
    char  PagNo[4];        /*页数*/
    char  RecNum[4];       /*条数*/
}ICS_DEF_460606_N_MOB;

/*
 * 460604
 * 缴费记录查询(010204)
 */
typedef struct ICS_DEF_460604_I_MOB{
    char  ActDat  [8]   ; /*会计日期*/
    char  RsFld1  [20]  ; /*发起方流水号*/
}ICS_DEF_460604_I_MOB;

typedef struct  ICS_DEF_460604_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*SC*/
    char OFmtCd[3];  /*D04*/
    char TelNum[15]  ; /*被充值号码*/
    char LogNo[20]  ; /*充值流水号*/
    char TDatTim[20]  ; /*充值时间*/
    char TResult[2]  ; /*充值结构*/
    char TxnAmt[10]  ; /*充值金额*/
}ICS_DEF_460604_N_MOB;


/*
 * 461501
 * 查询 单笔非税应收信息
 * 非税业务广州
 */
typedef struct ICS_DEF_461501_I_PNTA{
    char AdnCod[20]   ; /*通知书编号*/
    char PBilTyp[10]  ; /*打印票据种类*/
    char PBilNo[20]   ; /*打印票据编号*/
    char HndFlg[1]    ; /*手写机打标志*/
    char UpdAdnFg[1]  ; /*0=正常获取 1=刷新获取*/  
    char RipFlg[1]    ; /*撕定额票标志 0否 1是*/
    char DitCod[6]    ; /*行政区划*/
}ICS_DEF_461501_I_PNTA;

typedef struct ICS_DEF_461501_N_PNTA{
	   char    TmpDat[4];      /*长度       */
     char    ApCode[2];     /*SC         */
     char    OFmtCd[3];      /*D04        */
	   char    AdnCod   [20];  /*通知书编号*/
     char    PBilTyp  [10];  /*打印票据种类*/
     char    PBilNo   [20];  /*打印票据编号*/
     char    LevFlg   [3];   /*征收方式*/
     char    WriDat   [8];   /*填制日期*/
     char    DitCod   [6];   /*行政区划*/
     char    ColUntCd [42];  /*执收单位编码*/
     char    ColUntNm [100]; /*执收单位名称*/
     char    CsgUntCd [42];  /*委托单位编码*/
     char    CsgUntNm [100]; /*委托单位名称*/
     char    XPayNam  [80];  /*书面付款人名*/
     char    XPayAct  [40];  /*书面付款账号*/
     char    XPayObk  [80];  /*书面付开户行*/
     char    XGatNam  [80];  /*书面收款人名*/
     char    XGatAct  [40];  /*书面收款账号*/
     char    XGatObk  [80];  /*书面收开户行*/
     char    AdnSmr   [240]; /*备注*/
     char    StpDat   [8];   /*缴款截止日期*/			  				 
     char    AdnMac   [4];   /*校验码*/	
     char    AdnAmt   [15];  /*应收总金额*/	 
     char    FinAccIn [21];  /*入账账号*/
     char    PntAmt   [15];  /*非税收入金额*/	 
     char    AgtAmt   [15];  /*代理代收金额*/	 
		 char    AgtFlg   [1];   /*代收标识*/
		 char    RgnFlg   [1];   /*区域标识*/
		 char    AdnTyp   [10];  /*通知书种类*/
}ICS_DEF_461501_N_PNTA;
     
typedef struct ICS_DEF_461501_E_PNTA{
    char  TmpDat[4];    /*长度       */
    char  ApCode1[2];   /*SC         */
    char  OFmtCd[3];    /*D04        */
    char  RspCod[6];    /*错误码     */
    char  InPos[4];     /*0001*/
    char  RspMsg[56];   /*出错原因   */
}ICS_DEF_461501_E_PNTA; 
     
/*   
 * 461502
 * 扣款 单笔非税扣款交易,同时也是交通罚款扣款交易
 * 非税业务广州
 */  
typedef struct ICS_DEF_461502_I_PNTA{   
		char   AdnCod[20];			 /*通知书编号*/                               				
		char   AgtFlg[1];			   /*代收标识*/                                 		
		char   OActFg[1]; 			 /*2存折 4太平洋借记卡 付款账户性质*/                             		
		char   TxnAmt[15];			 /*应收金额*/                                               		
		char   HiActNo[21];		   /*银行收款账号*/                            			
		char   HoActNo[21];		   /*银行扣款账号*/                            		
		char   HoActNm[60];		   /*银行扣款户名*/                            			
		char   VchTyp[3];			   /*凭证种类*/                                 	
		char   VchNo[30];			   /*凭证号码 */                                		
		char   UdwDat[8];			   /*签发日期 */                                				
		char   CclNo[12]; 			 /*销账号*/                                   				
		char   ThdKnd[1];	       /*通知书性质 1普通单 2汇总单 3交罚单 4批扣*/ 
}ICS_DEF_461502_I_PNTA;
     
typedef struct ICS_DEF_461502_N_PNTA{
    char  TmpDat[4];        /*package length*/
    char  ApCode[2];        /*SC*/
    char  OFmtCd[3];        /*D04*/
}ICS_DEF_461502_N_PNTA;

typedef struct ICS_DEF_461502_E_PNTA{
    char  TmpDat[4];       /*长度       */
    char  ApCode1[2];      /*SC         */
    char  OFmtCd[3];       /*D04        */
    char  RspCod[6];       /*错误码     */
    char  InPos[4];        /*0001*/
    char  RspMsg[56];      /*出错原因   */
}ICS_DEF_461502_E_PNTA;
      
      
 /*   
 * 461503
 * 上送 单笔非税上送财政交易 ,同时也是交通罚款上送交易      
 * 非税业务广州
 */   
typedef struct ICS_DEF_461503_I_PNTA{   
		char  AdnKnd[1];			/*通知书性质 1普通单 2汇总单 3交罚单 4批量扣款*/                               				
		char  AdnCod[40];			/*请求书编号*/                                 		
		char  RgnFlg[1]; 			/*区域标识 0区县级 1市级*/                             		
}ICS_DEF_461503_I_PNTA;
      
typedef struct ICS_DEF_461503_N_PNTA{
    char  TmpDat[4];       /*package length*/
    char  ApCode[2];       /*SC*/
    char  OFmtCd[3];       /*D04*/
}ICS_DEF_461503_N_PNTA;    
     
typedef struct ICS_DEF_461503_E_PNTA{
    char   TmpDat[4];      /*长度       */
    char   ApCode1[2];     /*SC         */
    char   OFmtCd[3];      /*D04        */
    char   RspCod[6];      /*错误码     */
    char   InPos[4];       /*0001*/
    char   RspMsg[56];     /*出错原因   */
}ICS_DEF_461503_E_PNTA;
     
     
     
     
/*   
 * 461509
 * 交通罚款应收信息查询
 * 交通罚款业务--广州
 */  
typedef struct ICS_DEF_461509_I_PNTA{   
		char AdnCod[20]   		  ;      /* 文书编号                               */        				
		char PBilTyp[10]  		  ;      /* 打印票据种类                           */
		char PBilNo[20]   		  ;      /* 打印票据编号                           */
		char HndFlg[1]          ;      /* 手工票标志                             */
		char UpdAdnFg[1]        ;      /* 0正常获取应收信息 1更新已存应收信息    */
		char RipFlg[1]          ;      /* 撕定额票标志 0否 1是                   */
}ICS_DEF_461509_I_PNTA;                                                     
                                                                           
typedef struct ICS_DEF_461509_N_PNTA{
	  char  TmpDat[4];     /*package length*/
    char  ApCode[2];     /*SC*/
    char  OFmtCd[3];     /*D04*/
    char  AdnCod[20]    ;/*文书编号     */
    char  PBilTyp[10]   ;/*打印票据种类 */
    char  PBilNo[20]    ;/*打印票据编号 */
    char  LevFlg[3]     ;/*征收方式     */
    char  DitCod[6]     ;/*行政区划     */
    char  ColUntCd[42]  ;/*执收单位编码 */
    char  ColUntNm[100] ;/*执收单位名称 */
    char  CsgUntNm[100] ;/*执罚单位名称 */
    char  XPayNam[80]   ;/*当事人       */
    char  XGatNam[80]   ;/*收款人名称   */
    char  AdnSmr[240]   ;/*违法信息备注*/
    char  AdnAmt[15]    ;/*应收总金额	  */
    char  FinAccIn[21]  ;/*入账账号     */
    char  PntAmt[15]    ;/*非税收入金额	*/ 
    char  AgtAmt[15]    ;/*代理代收金额	*/ 
    char  AgtFlg[1]     ;/*代收标识     */
    char  RgnFlg[1]     ;/*区域标识     */
    char  AdnTyp[10]    ;/*通知书种类   */
}ICS_DEF_461509_N_PNTA;   
     
typedef struct ICS_DEF_461509_E_PNTA{
    char  TmpDat[4];      /*长度       */
    char  ApCode1[2];     /*SC         */
    char  OFmtCd[3];      /*D04        */
    char  RspCod[6];      /*错误码     */ 
    char  InPos[4];       /*0001*/
    char  RspMsg[56];     /*出错原因   */
}ICS_DEF_461509_E_PNTA;                                


/*
 * 460411
 * 
 */
typedef struct ICS_DEF_460411_I_EFEK{
    char SFFS [3]; /*收费方式*/
    char FYLX [3]; /*费用类型*/
    char DWBM [8]; /*单位编码*/
    char JFH [20]; /*缴费号*/
    char JSHMC [64]; /*结算户名称*/
    char YDDZ [128]; /*用电地址*/
    char KKZH [32]; /*扣款账户*/
    char KKZHMC [128]; /*扣款账户名称*/
    char BFJFBZ [1]; /*部分缴费标志*/
    char ZWLSH [16]; /*账务流水号*/
    char DFNY [6]; /*电费年月*/
    char QFJE [16]; /*欠费金额*/
    char BJ [16]; /*本金*/
    char WYJ [16]; /*违约金*/
    char VchTyp [3]; /*结算凭证*/
    char VchNo [8]; /*凭证号*/
    char BilDat [8]; /*凭证日期*/
    char ActNo [21]; /*主账号*/
    char PinBlk [20]; /*密码*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460411_N_EFEK{
    char  TmpDat[4];       /*package length*/
    char ApCode [2]; /*SC*/
    char OFmtCd [3]; /*D04*/
    char WDMC [64]; /*网点名称*/
    char JYLSH [24]; /*交易流水号*/
    char JYRQ [8]; /*交易日期*/
    char JYSJ [6]; /*交易时间*/
    char YJYLSH [24]; /*原交易流水号*/
    char YJYRQ [8]; /*原交易日期*/
    char YJYSJ [6]; /*原交易时间*/
    char DWBM [8]; /*单位编码*/
    char JFH [20]; /*缴费号*/
    char DFNY [6]; /*电费年月*/
    char SKJE [16]; /*实扣金额*/
    char JFJGSM [128]; /*缴费结果说明*/
    char TckNo [12]; /*会计业务流水号*/
}ICS_DEF_460602_N_MOB;

/*
 * 460410
 * 
 */
typedef struct ICS_DEF_460410_I_EFEK{
    char JFH [20]; /*缴费号*/
    char DFNY [6]; /*电费年月*/
    char CXFS [1]; /*查询方式*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460410_N_EFEK{
    char  TmpDat[4];       /*package length*/
    char WDMC [64]; /*网点名称*/
    char JYLSH [24]; /*交易流水号*/
    char JYRQ [8]; /*交易日期*/
    char JYSJ [6]; /*交易时间*/
    char YJYLSH [24]; /*原交易流水号*/
    char YJYRQ [8]; /*原交易日期*/
    char YJYSJ [6]; /*原交易时间*/
    char SFFS [3]; /*收费方式*/
    char FYLX [3]; /*费用类型*/
    char RZYHDM [4]; /*入账银行代码*/
    char DWBM [8]; /*单位编码*/
    char JFH [20]; /*缴费号*/
    char JSHMC [64]; /*结算户名称*/
    char YDDZ [128]; /*用电地址*/
    char KKZH [32]; /*扣款账户*/
    char KKZHMC [128]; /*扣款账户名称*/
    char BFJFBZ [1]; /*部分缴费标志*/
    char ZWLSH [16]; /*账务流水号*/
    char DFNY [6]; /*电费年月*/
    char QFJE [16]; /*欠费金额*/
    char BJ [16]; /*本金*/
    char WYJ [16]; /*违约金*/
}ICS_DEF_460602_N_MOB;

/*
 * 460444
 * 
 */
typedef struct ICS_DEF_460444_I_EFEK_Qry{
    char QDBZ [1]; /*签订标志*/
    char JFH [20]; /*缴费号*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460444_N_EFEK_Qry{
    char  TmpDat[4];       /*package length*/
    char ApCode [2]; /*SC*/
    char OFmtCd [3]; /*D04*/
    char WDMC [64]; /*网点名称*/
    char JYLSH [24]; /*交易流水号*/
    char JYRQ [8]; /*交易日期*/
    char JYSJ [6]; /*交易时间*/
    char YJYLSH [24]; /*原交易流水号*/
    char YJYRQ [8]; /*原交易日期*/
    char YJYSJ [6]; /*原交易时间*/
    char QDBZ [1]; /*签订标志*/
    char JFH [20]; /*缴费号*/
    char JSHMC [64]; /*结算户名称*/
    char YDDZ [128]; /*用电地址*/
    char BZ [128]; /*备注*/
    char YQYYHDM [4]; /*原签约银行代码*/
    char YQYZH [32]; /*原签约账户*/
    char YQYZHMC [128]; /*原签约账号名称*/
}ICS_DEF_460602_N_MOB;

typedef struct ICS_DEF_460444_I_EFEK_Upd{
    char QDBZ [1]; /*签订标志*/
    char JFH [20]; /*缴费号*/
    char JSHMC [64]; /*结算户名称*/
    char YQYYHDM [4]; /*原签约银行代码*/
    char YQYZH [32]; /*原签约账户*/
    char YQYZHMC [128]; /*原签约账号名称*/
    char XQYYHDM [4]; /*新签约银行代码*/
    char XQYZH [32]; /*新签约账户*/
    char XQYZHMC [128]; /*新签约账户名称*/
    char ZHLX [2]; /*账户类型*/
    char ZJLX [2]; /*证件类型*/
    char ZJHM [32]; /*证件号码*/
    char LXDH [20]; /*联系电话*/
    char SJHM [20]; /*手机号码*/
    char EMAIL [64]; /*E-MAIL*/
    char BZ [128]; /*备注*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460444_N_EFEK_Upd{
    char  TmpDat[4];       /*package length*/
    char ApCode [2]; /*SC*/
    char OFmtCd [3]; /*D04*/
}ICS_DEF_460602_N_MOB;

