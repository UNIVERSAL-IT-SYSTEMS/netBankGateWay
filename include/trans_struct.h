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
 * ���Žɷ�ǰ��ѯ
 */

typedef struct ICS_DEF_482101_I{
    char RsFld1[4];        /*������������*/
    char RsFld2[4];        /*������ҵ������*/
    char TCusID[30];       /*�ɷѺ���*/
}ICS_DEF_482101_I;

typedef struct ICS_DEF_482101_N{
char  TmpDat[4];                   /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D03*/
char  TCusID[30];                 /*�������*/
char  TCusNm[60];                 /*�ͻ�����*/
char  TxnAmt[15];                  /*���׽��*/
char  RsFld2[4];                  /*ҵ������*/
}ICS_DEF_482101_N;

typedef struct ICS_DEF_482101_E{
char  TmpDat[4];                   /*����*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482101_E;

/*
 * 482102
 * ���շ�
 */

typedef struct ICS_DEF_482102_I{
    char RsFld1[4];        /*������������*/
    char RsFld2[4];        /*������ҵ������*/
    char TCusID[30];        /*�������*/
    char TxnAmt[15];                  /*���׽��*/
    char ActTyp[1];                  /*�ʻ�����*/
    char ActNo[21];                  /*�����ʺ�*/
    char PinBlk[20];                  /*��������*/
    char TxCck2[40];                  /*�ڶ��ŵ�*/
    char TxCck3[110];                  /*�����ŵ�*/
    char  TCusNm[60];      /*�ͻ�����*//*new add20090104*/
}ICS_DEF_482102_I;

typedef struct ICS_DEF_482102_N{
char  TmpDat[4];                   /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D03*/
char  TCusID[30];                 /*�������*/
char  TCusNm[60];                 /*�ͻ�����*/
char  RcvAmt[15];                  /*���׽��*/
char  TckNo[11];                  /*�����ˮ*/
char  RsFld2[4];                  /**/
}ICS_DEF_482102_N;

typedef struct ICS_DEF_482102_E{
char  TmpDat[4];                   /*����*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482102_E;

/*
 * 928460
 * ������֤
 */

typedef struct ICS_DEF_928460_I{
    char TxnCnl[1];   /* ��������:1-�绰����;2-����;3-ATM/CDM/CRS;
                    4-POS;5-��ý��;6-�ֻ� */
    char ActNo[21];   /* �ʺ� */
    char CusId[13];   /* �ͻ��� */
    char PINTyp[1];   /* �������� */
    char PINDat[20];    /* ������ */
    char InqFlg[1];   /* �ͻ���Ϣ��ѯ��־:0������ѯ;1����ѯ */
    char Trk2Dat[37];   /* ת�����ڶ��ŵ���Ϣ */
}ICS_DEF_928460_I;

typedef struct ICS_DEF_928460_N{
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D03*/
char  TCusID[30];                 /*�������*/
char  TCusNm[60];                 /*�ͻ�����*/
char  RcvAmt[15];                  /*���׽��*/
char  TckNo[11];                  /*�����ˮ*/
char  RsFld2[4];                  /**/
}ICS_DEF_928460_N;

/*
 * 482108
 * �ƶ���ѯ
 */

typedef struct ICS_DEF_482108_I{
    char RsFld1[4];        /*������������*/
    char RsFld2[4];        /*������ҵ������*/
    char TCusID[30];       /*�ɷѺ���*/
    char TxnPin[10];       /*�ƶ�����*/
}ICS_DEF_482108_I;

typedef struct ICS_DEF_482108_N{
char  TmpDat[4];    /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D06*/
char  TCusID[30];               /*�������*/
char  TCusNm[60];               /*�ͻ�����*/
char  TxnAmt[15];               /*���׽��*/
char  RsFld2[4];                /*ҵ������*/
}ICS_DEF_482108_N;

typedef struct ICS_DEF_482108_E{
char  TmpDat[4];                 /*����*/
char  ApCode1[2];                /*SC*/
char  OFmtCd[3];                 /*D04*/
char  RspCod[6];                 /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                /*����ԭ��*/
}ICS_DEF_482108_E;

/*
 * 482110
 * �ƶ��ɷ�
 */

typedef struct ICS_DEF_482110_I{
    char RsFld1[4];   /*������������*/
    char RsFld2[4];   /*������ҵ������*/
    char TCusID[30];    /*�������*/
    char TxnAmt[15];    /*���׽��*/
    char ActTyp[1];   /*�ʻ�����*/
    char ActNo[21];   /*�����ʺ�*/
    char PinBlk[20];    /*��������*/
    char TxCck2[40];    /*�ڶ��ŵ�*/
    char TxCck3[110];   /*�����ŵ�*/
    char TxnPin[10];    /*�ƶ�������*/
    char  TCusNm[60];                 /*�ͻ�����*//*new add20090104*/
}ICS_DEF_482110_I;

typedef struct ICS_DEF_482110_N{
char  TmpDat[4];                   /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D03*/
char  TCusID[30];                 /*�������*/
char  TCusNm[60];                 /*�ͻ�����*/
char  RcvAmt[15];                  /*���׽��*/
char  TckNo[11];                  /*�����ˮ*/
char  RsFld2[4];                  /**/
}ICS_DEF_482110_N;

typedef struct ICS_DEF_482110_E{
char  TmpDat[4];                   /*����*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482110_E;

/*
 * 461191
 * ����������ϸ��ѯ
 */

typedef struct ICS_DEF_461191_I{
char TxnCod[ 6];  /*������*/
char PfaSub[ 3];  /*��������*/
char BCusId[18];  /*Ԥ�㵥λ����*/
char CardNo[19];  /*����*/
char BgnDat[ 8];  /*��ʼ����*/
char EndDat[ 8];  /*��ֹ����*/
char MinAmt[15];  /*��ͽ��*/
char MaxAmt[15];  /*��߽��*/
char Dtlsts[ 1];  /*״̬*/
char MaxPNm[ 2];  /*��ѯ������*/
char PageNm[ 4];  /*��ѯҳ��*/    
}ICS_DEF_461191_I;

typedef struct ICS_DEF_461191_O{
char RspCod[ 6];  /*���׷�����*/
char RspMsg[60];  /*���׷���������*/
char RecNum[ 4];  /*����*/
}ICS_DEF_461191_O;

typedef struct ICS_DEF_461191_G{
char DtlSts[ 1];  /*״̬*/
char CardNo[19];  /*����Ա����*/
char CardNm[30];  /*����Ա����*/
char TxnDat[ 8];  /*��������*/
char TxnTim[ 8];  /*����ʱ��*/
char MerId [15];  /*�̻���*/
char TermId[ 8];  /*�ն˺�*/
char MerNam[43];  /*�̻�����*/
char TLogNo[ 6];  /*������ˮ��*/
char DtlAmt[15];  /*���׽��*/
char CcyCod[ 3];  /*���׻���*/
char ThdCod[ 4];  /*������*/
char AuthCd[ 6];  /*��Ȩ��*/
char HActDt[ 8];  /*��ѯ����*/
char SelVal[ 8];  /*��ѯ����*/
char SeqNo [ 2];  /*С���*/
char PfaSub[ 3];  /*��������*/
char BCusId[18];  /*Ԥ�㵥λ����*/
char Year  [ 4];  /*�������*/
char SubCod[12];  /*Ԥ���Ŀ*/
char PrjCod[12];  /*Ԥ����Ŀ*/
char EConTp[12];  /*���÷���*/
char DptCod[ 8];  /*ҵ����*/
char BokAmt[15];  /*ʵ�����*/
char BchNo [ 8];  /*��������*/
char TActDt[ 8];  /*��������*/
char AVchNo[ 8];  /*��Ȩƾ֤����*/
}ICS_DEF_461191_G;

/*
 * 482111
 * ��ͨ��ѯ
 */

typedef struct ICS_DEF_482111_I{
    char RsFld1[4];        /*������������*/
    char RsFld2[4];        /*������ҵ������*/
    char TCusID[30];       /*�ɷѺ���*/
    char Feeflg[ 1];     /*��ֵ�ɷѱ�־0Ƿ��,1��ֵ*/
    char Feefld[ 2];     /*��ͨҵ������*/
}ICS_DEF_482111_I;

typedef struct ICS_DEF_482111_N{
char  TmpDat[4];    /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D06*/
char  TCusID[30];               /*�������*/
char  TCusNm[60];               /*�ͻ�����*/
char  TxnAmt[15];               /*���׽��*/
char  Arefld[2];
char  BusId[20];
char  RsFld2[4];                /*ҵ������*/
}ICS_DEF_482111_N;

typedef struct ICS_DEF_482111_E{
char  TmpDat[4];                 /*����*/
char  ApCode1[2];                /*SC*/
char  OFmtCd[3];                 /*D04*/
char  RspCod[6];                 /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                /*����ԭ��*/
}ICS_DEF_482111_E;

/*
 * 482112
 * ��ͨ�ɷ�
 */

typedef struct ICS_DEF_482112_I{
    char RsFld1[4];        /*������������*/
    char RsFld2[4];        /*������ҵ������*/
    char TCusID[30];        /*�������*/
    char TxnAmt[15];                  /*���׽��*/
    char ActTyp[1];                  /*�ʻ�����*/
    char ActNo[21];                  /*�����ʺ�*/
    char PinBlk[20];                  /*��������*/
    char TxCck2[40];          /*�ڶ��ŵ�*/
    char TxCck3[110];     /*�����ŵ�*/
    char Feeflg[1];   /*��ֵ�ɷѱ�־0Ƿ��,1��ֵ*/
    char Feefld[2];   /*��ͨҵ������*/
    /*char  TCusNm[60];                 �ͻ�����*//*new add20090104*/
    char Arefld[2];
    char BusId[20];
}ICS_DEF_482112_I;

typedef struct ICS_DEF_482112_N{
char  TmpDat[4];                   /*����*/
char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D01*/
char  TCusID[30];                 /*�������*/
char  TCusNm[60];                 /*�ͻ�����*/
char  RcvAmt[15];                  /*���׽��*/
char  TckNo[11];                  /*�����ˮ*/
char  RsFld2[4];                  /**/
}ICS_DEF_482112_N;

typedef struct ICS_DEF_482112_E{
char  TmpDat[4];                   /*����*/
char  ApCode1[2];                   /*SC*/
char  OFmtCd[3];                   /*D04*/
char  RspCod[6];                  /**/
char  InPos[4];                  /*0001*/
char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482112_E;


/** add by viatt lichen 2008-10-10 begin **/
/*
 * 482115
 * ����˰��ѯ
 */

typedef struct ICS_DEF_482115_I{
  char  RsFld1[4];        /*������������*/
  char  RsFld2[4];        /*������ҵ������*/
  char  TCusID[30];       /*�ɷѺ���*/
  char  ActNo[21];        /*�����ʺ�*/
  /*char  TxnAmt[15];*/       /*���׽��*/
  char  CarTyp[2];        /*�������ͣ�A1��������,A2С������,A5�ҳ�,A6������,A7ũ�����䳵,C1�⼮����*/
  /*char  PrvCod[2];*/        /*ʡ�ݴ��룺01�㶫ʡ(��)*/
  /*char  CtyCod[1]; */       /*���д���:A������*/
  char  CarNo[5];          /*�������к�*/
}ICS_DEF_482115_I;

typedef struct ICS_DEF_482115_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D06*/
  char  TCusID[30];      /*�������*/
  char  Rsfld3[60];      /*�ͻ�����*/
  char  STxnAmt[15];     /*���*/
  char  LoSeq[11];       /*��˰��ˮ��*/
  char  PayAmt[15];      /*Ӧ�ɵ�˰����*/
  char  FeeAmt[15];      /*Ӧ�ɵķ�����*/
  char  LatAmt[15];      /*Ӧ�ɵ����ɽ���*/
  char  TCusNm[60];      /*�ͻ�����*/
}ICS_DEF_482115_N;

typedef struct ICS_DEF_482115_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482115_E;

/*
 * 482116
 * �ɳ���˰
 */
typedef struct ICS_DEF_482116_I{
  char  RsFld1[4];       /*������������*/
  char  RsFld2[4];       /*������ҵ������*/
  char  TCusID[30];      /*�ɷѺ���*/
  char  TxnAmt[15];      /*���׽��*/
  char  ActTyp[1];       /*�ʻ�����*/
  char  ActNo[21];       /*�����ʺ�*/
  char  PinBlk[20];      /*��������*/
  char  TxCck2[40];      /*�ڶ��ŵ�*/
  char  TxCck3[110];     /*�����ŵ�*/
  char  CarTyp[2];       /*�������ͣ�A1��������,A2С������,A5�ҳ�,A6������,A7ũ�����䳵,C1�⼮����*/
  /*char  PrvCod[2];*/       /*ʡ�ݴ��룺01�㶫ʡ(��)*/
  /*char  CtyCod[1];*/       /*���д���:A������*/
  char  CarNo[5];        /*�������к�*/
  char  LoSeq[11];       /*��˰��ˮ��*/
  char  Rsfld3[60];      /*�ͻ�����*/
  char  TCusNm[60];                 /*�ͻ�����*//*new add20090104*/
}ICS_DEF_482116_I;

typedef struct ICS_DEF_482116_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  TCusID[30];      /*�������*/
  char  TCusNm[60];      /*�ͻ�����*/
  char  RcvAmt[15];      /*���׽��*/
  char  TckNo[11];       /*�����ˮ*/
  char  RsFld2[4];       /**/
}ICS_DEF_482116_N;

typedef struct ICS_DEF_482116_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482116_E;

/*
 * 482118
 * ��ͨ�ۿ�
 */
typedef struct ICS_DEF_482118_I{
  char  RsFld1[4];       /*������������*/
  char  RsFld2[4];       /*������ҵ������*/
  char  TCusID[30];      /*�ɷѺ���*/
  char  TxnAmt[15];      /*���׽��*/
  char  ActTyp[1];       /*�ʻ�����*/
  char  ActNo[21];       /*�����ʺ�*/
  char  PinBlk[20];      /*��������*/
  char  TxCck2[40];      /*�ڶ��ŵ�*/
  char  TxCck3[110];     /*�����ŵ�*/
  char  Cartyp[4];       /*�������ͣ�50��ֵ 0300,100��ֵ 0301*/
  char  MobTel[60];      /*��ϵ�绰*/
}ICS_DEF_482118_I;

typedef struct ICS_DEF_482118_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  TCusID[30];      /*�������*/
  char  TCusNm[60];      /*�ͻ�����*/
  char  RcvAmt[15];      /*���׽��*/
  char  TypTel[12];       /*��������+���������к�*/
  char  CarMes[60];       /*����Ϣ�ο�ע��*/
}ICS_DEF_482118_N;
            
typedef struct ICS_DEF_482118_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482118_E;

/*
 * 482171
 * �㶫�ƶ��û�״̬��ѯ
 */

typedef struct ICS_DEF_482171_I{
  char  user_number[20];        /*�ֻ�����*/
}ICS_DEF_482171_I;

typedef struct ICS_DEF_482171_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  user_number[20]; /*�ֻ�����*/
  char  User_status[2];  /*�ֻ�״̬*/
}ICS_DEF_482171_N;

typedef struct ICS_DEF_482171_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482171_E;

/*
 * 482172
 * �û�Ӧ�ɷ��ò�ѯ
 */

typedef struct ICS_DEF_482172_I{
  char  user_number[20];        /*�ֻ�����*/
}ICS_DEF_482172_I;

typedef struct ICS_DEF_482172_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  user_number[20]; /*�ֻ�����*/
  char  amount[12];      /*Ӧ�ɽ��*/
}ICS_DEF_482172_N;

typedef struct ICS_DEF_482172_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482172_E;

/*
 * 482173
 * �ɳ���˰
 */
typedef struct ICS_DEF_482173_I{
  char  user_number[20]; /*�ֻ�����*/
  char  TxnAmt[15];      /*���׽��*/ 
  char  ActTyp[1];       /*�ʻ�����*/
  char  ActNo[21];       /*�����ʺ�*/
  char  PinBlk[20];      /*��������*/
  char  TxCck2[40];      /*�ڶ��ŵ�*/
  char  TxCck3[110];     /*�����ŵ�*/
}ICS_DEF_482173_I;

typedef struct ICS_DEF_482173_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  user_number[20]; /*�ֻ�����*/
  char  RcvAmt[15];      /*���׽��*/
  char  TckNo[11];       /*�����ˮ*/
}ICS_DEF_482173_N;

typedef struct ICS_DEF_482173_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482173_E;


/*
 * 
 * ����ͨ
 */ 
typedef struct ICS_DEF_482131_I{
  char  Reserve_Code[12];   /*������*/  
  char  Member_id[8];       /*��λ��*/  
}ICS_DEF_482131_I;

typedef struct ICS_DEF_482131_N{
  char  TmpDat[4];                    /*����*/
  char  ApFmt[5];                     /*ǰ�˿ո�ʽ�� 48D01*/
  char  Product_Name[200];            /*Ԥ������*/
  char  Provide_Name[30];             /*������*/
  char  Trans_Toal_Amount[14];        /*�ܽ��*/
  char  Paid_Amount[14];              /*�Ѹ����*/  
  char  Arrearage_Amount[14];         /*Ƿ�ѽ��*/  
  char  Return_Code[3];               /*������*/    
  char  PB_Return_Code_Msg[50];       /*��������Ϣ*/      
}ICS_DEF_482131_N;

typedef struct ICS_DEF_482131_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482131_E;
 
typedef struct ICS_DEF_482132_I{
  char  TCusNm[12];         /*�������*/
  char  Member_id[8];       /*��λ��*/
  char  ActTyp[1];          /*�ʺ�����*/
  char  ActNo[21];          /*�����ʺ�*/
  char  PinBlk[20];         /*��������*/
  char  TxCck2[40];         /*�ڶ��ŵ�*/  
  char  TxCck3[110];        /*�����ŵ�*/  
  char  Trans_Amount1[14];  /*���׽��*/  
  char  Provide_Name[50];   /*������*/  
  char  Product_Name[60];   /*Ԥ������*/  
}ICS_DEF_482132_I;

typedef struct ICS_DEF_482132_N{
  char  TmpDat[4];                    /*����*/
  char  ApFmt[5];                     /*ǰ�˿ո�ʽ�� 48D01*/
  char  TCusNm[12];                   /*�������*/
  char  ThdKey[18];                   /*���н�����ˮ��*/
  char  Return_Code[3];               /*������*/
  char  PB_Return_Code_Msg[30];       /*��������Ϣ*/
  char  TckNo[11];                      /*�����ˮ*/
}ICS_DEF_482132_N;

typedef struct ICS_DEF_482132_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482132_E;


typedef struct ICS_DEF_482133_I{
  char  PagIdx[6];      /*ҳ��*/
}ICS_DEF_482133_I;

typedef struct ICS_DEF_482133_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  SumCnt[4];       /*�ܼ�¼��*/
  char  PagNo[4];        /*ҳ��*/
  char  RecNum[4];       /*����*/
}ICS_DEF_482133_N;

typedef struct ICS_DEF_482133_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482133_E;

typedef struct ICS_DEF_482134_I{
  char  Provider_Code[12];      /*��������*/
}ICS_DEF_482134_I;

typedef struct ICS_DEF_482134_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  SumCnt[4];       /*�ܼ�¼��*/
  char  PagNo[4];        /*ҳ��*/
  char  RecNum[4];       /*����*/
}ICS_DEF_482134_N;

typedef struct ICS_DEF_482134_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482134_E;

typedef struct ICS_DEF_482135_I{
  char  Product_Code[12];         /*��Ʊ����*/
  char  Retail_Price1[14];        /*���м�*/
  char  E_Discount_Price1[14];    /*�����Żݼ�*/
  char  Reserve_Amoun[4];         /*Ԥ����Ʒ����*/
  char  Mobile_Phone_Number[11];  /*�ֻ�����*/
  char  Begin_Date[8];            /*ʹ������*/
  char  Message_Type[2];          /*��������*/
  char  Amount1[14];              /*�ܽ��*/
  char  ActTyp[1];                /*�ʺ�����--NULLABLE*/
  char  ActNo[21];                /*�����ʺ�*/
  char  PinBlk[20];               /*��������*/
  char  TxCck2[40];               /*�ڶ��ŵ�--NULLABLE*/
  char  TxCck3[110];              /*�����ŵ�--NULLABLE*/
  char  Scence_Code[12];          /*��������*/
  char  Scence_Name[60];          /*��������*/
  char  Product_Name[50];         /*��Ʊ����*/
  char  Remark1[160];             /*��ע*/
  char  Valid_Days[3];            /*��Ч����*/            
}ICS_DEF_482135_I;

typedef struct ICS_DEF_482135_N{
  char  TmpDat[4];                /*����*/
  char  ApFmt[5];                 /*ǰ�˿ո�ʽ�� 48D01*/
  char  TCUSNM[12];               /*�������*/
  char  ThdKey[18];               /*���н�����ˮ��*/
  char  TXNAMT[14];               /**/
  char  Return_Code[3];           /*������*/
  char  PB_Return_Code_Msg[30];   /*��������Ϣ*/
  char  Remark1[160];             /*��ע*/
  char  TckNo[11];                /*�����ˮ*/
}ICS_DEF_482135_N;

typedef struct ICS_DEF_482135_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482135_E;


typedef struct ICS_DEF_482147_I{
  char  ActNo[21];
}ICS_DEF_482147_I;

typedef struct ICS_DEF_482147_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  SumCnt[4];       /*�ܼ�¼��*/
  char  PagNo[4];        /*ҳ��*/
}ICS_DEF_482147_N;

typedef struct ICS_DEF_482147_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482147_E;
/** add by viatt lichen 2008-10-10 end **/

/** add by viatt lichen 2009-01-07 begin **/
typedef struct ICS_DEF_481152_I{
  char  TxnDat[8];      /*����*/
  char  AbuTyp[4];      /*����*/
}ICS_DEF_481152_I;

typedef struct ICS_DEF_481152_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  PagNo[4];        /*ҳ��*/
  char  VarSize[1];      /*����*/
  char  Ttl[21];         /*��ֵ����Ч�������*/
  char  SubTtl[11];      /*��ѯ����*/
  char  RecNum[3];       /*����*/
}ICS_DEF_481152_N;

typedef struct ICS_DEF_481152_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_481152_E;

typedef struct ICS_DEF_481143_I{
  char  TxnDat[8];        /*��������*/
  char  AbuTyp[4];        /*����*/
  char  BusNam[16];       /*����*/
  char  TxnAmt[15];       /*����ֵ*/
  char  ActTyp[1];        /*�ʺ�����*/
  char  ActNo[21];        /*�����ʺ�*/  
  char  PinBlk[20];       /*��������*/  
  char  TxCck2[40];       /*�ڶ��ŵ�*/  
  char  TxCck3[110];      /*�����ŵ�*/    
}ICS_DEF_481143_I;

typedef struct ICS_DEF_481143_N{
  char  TmpDat[4];        /*����*/
  char  ApFmt[5];         /*ǰ�˿ո�ʽ�� 48D43*/
  char  AbuTyp[4];        /*����*/
  char  BusNam[16];       /*����*/
  char  TxnAmt[15];       /*����ֵ*/
  char  MIdNo[30];        /*�����к�*/
  char  VchNo[30];        /*��ֵ����*/
  char  OpfPin[30];       /*��ֵ������*/
  char  TxnDat[8];        /*��������*/
  char  EndDat[8];        /*��Ч����*/
  char  TckNo[11];        /*�����ˮ*/
  char  BilRmk[80];       /*��ֵ����*/
}ICS_DEF_481143_N;

typedef struct ICS_DEF_481143_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_481143_E;

typedef struct ICS_DEF_482145_I{
  char  ActNo[32];          /*�����ʺ�*/
  char  Jflx[2];            /*ҵ������*/
}ICS_DEF_482145_I;

typedef struct ICS_DEF_482145_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  SumCnt[4];       /*����*/
  char  PagNo[4];        /*ҳ��*/
  char  Stsxx[150];       /*��ܰ��ʾ*/
  char  RecNum[4];       /*����*/
}ICS_DEF_482145_N;

typedef struct ICS_DEF_482145_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482145_E;

typedef struct ICS_DEF_482140_I{
  char  ActNo[21];          /*�ʺ�*/
  char  Ccy[3];             /*����*/
  char  InFlg[1];           /*�˿���ʶ*/
  char  BusTyp[3];          /*JJ��,���ʱ����*/
  char  AcSeq[5];           /*�ʺ����,�˿���ʶΪһ��ͨʱ������*/
}ICS_DEF_482140_I;

typedef struct ICS_DEF_482140_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
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
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482140_E;
/** add by viatt lichen 2009-01-07 end **/

/*add by viatt linzw 2009-02-18 begin*/
typedef struct ICS_DEF_482149_I{
  char  bank_acc[32];           /*�����ʺ�*/
}ICS_DEF_482149_I;

typedef struct ICS_DEF_482149_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  sign_flag[1];     /*ǩԼ���� 0-���� 1-����ͨ */
  char  inst_no[9];       /*ǩԼ���� */
  char  live_flag[1];     /*�����־ 0-���� 1-δ���� */
  char  tran_flag[1];     /*���ױ�־ 0-������ 1-�������� */
  char  acc_type[1];      /*�ۿʽ 1:Ԥ�ۿ��û� 0:ʵʱ�ۿ��û� */
  char  yct_pwd[10];      /*���ͨ���� */
  char  bank_acc[30];     /*�˺� */
  char  oper_tlr[3];      /*����Ա */
  char  tran_date[14];    /*�������� */
  char  sys_no[12];       /*ϵͳ�ο��� */
  char  ret_code[2];      /*��Ӧ���� */
  char  paper_no[21];     /*֤�����ͺ��� */
  char  contact_no[20];   /*��ͬ��� */
  char  cust_name[30];    /*�û����� */
  char  sex_code[1];      /*�Ա� */
  char  phone_no[15];     /*�绰���� */
  char  mobile_no[15];    /*�ֻ����� */
  char  post_no[6];       /*�ʱ� */
  char  address[50];      /*��ַ */
  char  email[50];        /*email���� */
  char  card1[10];        /* ���ͨ����1 */
  char  card2[10];        /* ���ͨ����2 */
  char  card3[10];        /* ���ͨ����3 */
  char  card4[10];        /* ���ͨ����4 */
  char  limite[12];       /*��� */
  char  frequence[4];     /*Ƶ�� */
  char  reg_date[4];      /*ǩԼ���� */
  char  cncl_date[4];     /*��Լ���� */
  char  cncl_flag[4];     /* ǩ��Լ��־ 0 - ǩԼ 1 - ��Լ */
   /*char  address[50];     ��ַ */
  char  reserve1[30];     /*  Ԥ���ֶ�1 */
  char  reserve2[30];     /*  Ԥ���ֶ�2 */
  char  reserve3[30];     /*  Ԥ���ֶ�3 */
  char  reserve4[60];     /*  Ԥ���ֶ�4 */
  char  reserve5[60];     /*  Ԥ���ֶ�5 */
}ICS_DEF_482149_N;

typedef struct ICS_DEF_482149_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482149_E;
/*ǩԼ*/
typedef struct ICS_DEF_482138_I{
    char  sign_flag[1];          /*ǩԼ���� 0-���� 1-����ͨ */
    char  inst_no[9];            /*ǩԼ���� */
    char  live_flag[1];            /*�����־ 0-���� 1-δ���� */
    char  tran_flag[1];            /*���ױ�־ 0-������ 1-�������� */
    char  acc_type[1];            /*�ۿʽ 1:Ԥ�ۿ��û� 0:ʵʱ�ۿ��û� */
    char  yct_pwd[10];            /*���ͨ���� */
    char  bank_acc[19];           /*�˺� */
    char  oper_tlr[3];           /*����Ա */
    char  tran_date[14];           /*�������� */
    char  sys_no[12];           /*ϵͳ�ο��� */
    char  ret_code[2];           /*��Ӧ���� */
    char  paper_no[21];           /*֤�����ͺ��� */
    char  contact_no[20];           /*��ͬ��� */
    char  cust_name[30];           /*�û����� */
    char  sex_code[1];           /*�Ա� */
    char  phone_no[15];           /*�绰���� */
    char  mobile_no[15];           /*�ֻ����� */
    char  post_no[6];           /*�ʱ� */
    char  address[50];           /*��ַ */
    char  email[50];           /*email���� */
    char  card1[10];           /* ���ͨ����1 */
    char  card2[10];           /* ���ͨ����2 */
    char  card3[10];           /* ���ͨ����3 */
    char  card4[10];           /* ���ͨ����4 */
    char  limite[12];           /*��� */
    char  frequence[4];           /*Ƶ�� */
    char  reg_date[4];           /*ǩԼ���� */
    char  cncl_date[4];           /*��Լ���� */
    char  cncl_flag[4];           /* ǩ��Լ��־ 0 - ǩԼ 1 - ��Լ */
     /*char  address[50];          ��ַ */
    char  reserve1[30];           /*  Ԥ���ֶ�1 */
    char  reserve2[30];           /*  Ԥ���ֶ�2 */
    char  reserve3[30];           /*  Ԥ���ֶ�3 */
    char  reserve4[60];           /*  Ԥ���ֶ�4 */
    char  reserve5[60];           /*  Ԥ���ֶ�5 */
}ICS_DEF_482138_I;

typedef struct ICS_DEF_482138_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  sys_no[12];    /*ϵͳ�ο�����*/
}ICS_DEF_482138_N;

typedef struct ICS_DEF_482138_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482138_E;
/* ��Լ*/
typedef struct ICS_DEF_482139_I{
    char  sign_flag[1];     /*ǩԼ���� 0-���� 1-����ͨ */
    char  inst_no[9];            /*ǩԼ���� */
    char  bank_acc[19];           /*�˺� */
    char  card1[10];           /* ��Լ���ͨ����1 */
    char  card2[10];           /* ��Լ���ͨ����2 */
    char  card3[10];           /* ��Լ���ͨ����3 */
}ICS_DEF_482139_I;

typedef struct ICS_DEF_482139_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  sys_no[12];    /*ϵͳ�ο�����*/
}ICS_DEF_482139_N;

typedef struct ICS_DEF_482139_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482139_E;
/* ����*/
typedef struct ICS_DEF_482136_I{
    char  bank_acc[19];           /*�˺� */
    char  card1[10];           /* �������ͨ����1 */
}ICS_DEF_482136_I;

typedef struct ICS_DEF_482136_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/ 
  char  sys_no[12];    /*ϵͳ�ο�����*/
}ICS_DEF_482136_N;

typedef struct ICS_DEF_482136_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482136_E;
typedef struct ICS_DEF_482159_I{
  char  ActNo[21];
}ICS_DEF_482159_I;

typedef struct ICS_DEF_482159_N{
  char  TmpDat[4];       /*����*/
  char  ApFmt[5];        /*ǰ�˿ո�ʽ�� 48D01*/
  char  SumCnt[4];       /*�ܼ�¼��*/
  char  PagNo[4];        /*ҳ��*/
}ICS_DEF_482159_N;

typedef struct ICS_DEF_482159_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482159_E;
/*add by viatt linzw 2009-02-18 end*/

/*add by xuan for test */
typedef struct ICS_DEF_482999_I{
  char  Reserve_Code[12];   /*������*/  
  char  Member_id[8];       /*��λ��*/  
}ICS_DEF_482999_I;

typedef struct ICS_DEF_482999_N{
  char  TmpDat[4];                    /*����*/
  char  ApFmt[5];                     /*ǰ�˿ո�ʽ�� 48D01*/
  char  Product_Name[200];            /*Ԥ������*/
  char  Provide_Name[30];             /*������*/
  char  Trans_Toal_Amount[14];        /*�ܽ��*/
  char  Paid_Amount[14];              /*�Ѹ����*/  
  char  Arrearage_Amount[14];         /*Ƿ�ѽ��*/  
  char  Return_Code[3];               /*������*/    
  char  PB_Return_Code_Msg[50];       /*��������Ϣ*/      
}ICS_DEF_482999_N;

typedef struct ICS_DEF_482999_E{
  char  TmpDat[4];       /*����*/
  char  ApCode1[2];      /*SC*/
  char  OFmtCd[3];       /*D04*/
  char  RspCod[6];       /**/
  char  InPos[4];        /*0001*/
  char  RspMsg[56];      /*����ԭ��*/
}ICS_DEF_482999_E;

/*
 * 
 *������:������Ʊ
 *��  ��:2010.06.21
 */
/* 482101 ��ʹ��ʽ���*/
typedef struct ICS_DEF_482101_I_TC{
  char  CrdNo [30];                   /*����       */
  char  TxnAmt[15];                   /*���׽��   */
  char  TrmCod[15];                   /*�ں�       */
  char  TikMod[2];                    /*��Ʊ��ʽ   */
  char  LotTyp[2];                    /*��Ʊ����   */
  char  SigDup[2];                    /*����ʽ���� */
  char  NotNum[5];                    /*ע��       */
  char  MulTip[2];                    /*����       */
  char  ExtNum[2];                    /*��չ����   */
  char  LotNum[100];                  /*Ͷע����   */
  char  CntTel[20];                   /*�ֻ�����   */
}ICS_DEF_482101_I_TC;

typedef struct ICS_DEF_482101_N_TC{
  char  TmpDat[4];                   /*���ذ��峤��*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*״̬       */
  char  LogNo[14];                    /*������ˮ�� */
  char  TLogNo[30];                   /*������ˮ�� */
  char  NotNum[5];                    /*ע��       */
  char  LotNum1[20];                  /*ע1        */
  char  LotNum2[20];                  /*ע2        */
  char  LotNum3[20];                  /*ע3        */
  char  LotNum4[20];                  /*ע4        */
  char  LotNum5[20];                  /*ע5        */
  char  LotNum6[100];                 /*��ʽע     */
  char  MulTip[2];                    /*����       */
  char  TrmCod[15];                   /*�ں�       */
}ICS_DEF_482101_N_TC;

typedef struct ICS_DEF_482101_E_TC{
  char  TmpDat[4];                    /*����       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*������     */
  char  RspMsg[54];                   /*����ԭ��   */
}ICS_DEF_482101_E_TC;

/* 482102 ��ʹ��ʺ���У��*/
typedef struct ICS_DEF_482102_I_TC{
  char  TikMod[2];                    /*��Ʊ��ʽ   */
  char  SigDup[2];                    /*����ʽ���� */
  char  NotNum[5];                    /*��ѡע��   */
  char  LotNum[100];                  /*Ͷע����   */
  char  LotTyp[2];                    /*��Ʊ����   */
  char  MulTip[2];                    /*����       */
  char  ExtNum[2];                    /*��չ����   */
}ICS_DEF_482102_I_TC;

typedef struct ICS_DEF_482102_N_TC{
  char  TmpDat[4];                   /*���ذ��峤��*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*״̬       */
  char  NotNum[5];                    /*ע��       */
  char  LotNum1[20];                  /*ע1        */
  char  LotNum2[20];                  /*ע2        */
  char  LotNum3[20];                  /*ע3        */
  char  LotNum4[20];                  /*ע4        */
  char  LotNum5[20];                  /*ע5        */
  char  LotNum6[100];                 /*��ʽע     */
  char  TxnAmt[15];                   /*���       */
  char  MulTip[2];                    /*����       */
  char  TrmCod[15];                   /*�ں�       */
}ICS_DEF_482102_N_TC;

typedef struct ICS_DEF_482102_E_TC{
  char  TmpDat[4];                    /*����       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*������     */
  char  RspMsg[56];                   /*����ԭ��   */
}ICS_DEF_482102_E_TC;

/* 482103 ��ʲ�ѯͶע�������*/
typedef struct ICS_DEF_482103_I_TC{
  char  TLogNo[30];                   /*������ˮ�� */ 
}ICS_DEF_482103_I_TC;

typedef struct ICS_DEF_482103_N_TC{
  char  TmpDat[4];                   /*���ذ��峤��*/
  char  ApCode[2];                    /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  TRspCd[4];                    /*״̬       */
  char  TrmCod[15];                   /*�ں�       */
  char  SigDup[2];                    /*����ʽ���� */
  char  LotTyp[2];                    /*��Ʊ����   */ 
  char  TLogNo[30];                   /*������ˮ�� */ 
  char  LotNum[150];                  /*Ͷע����     */
  char  NotNum[5];                    /*ע��       */     
  char  TxnAmt[15];                   /*���       */     
}ICS_DEF_482103_N_TC;

typedef struct ICS_DEF_482103_E_TC{
  char  TmpDat[4];                    /*����       */
  char  ApCode1[2];                   /*SC         */
  char  OFmtCd[3];                    /*D04        */
  char  RspCod[6];                    /*������     */
  char  RspMsg[56];                   /*����ԭ��   */
}ICS_DEF_482103_E_TC;

/*
 * 482180
 * �㶫ʡ���Ų�ѯ���������
 */

typedef struct ICS_DEF_482180_I{
    char TCusID[20];       /*�ɷѺ���*/
}ICS_DEF_482180_I;

typedef struct ICS_DEF_482180_N{
  char  TmpDat[4];                  /*����*/
  char  ApFmt[5];                   /*ǰ�˿ո�ʽ�� 48D03*/
  char  TCusID[20];									/*�ɷѺ���*/
  char  DqCode[5];								/*��������*/
}ICS_DEF_482180_N;

typedef struct ICS_DEF_482180_E{
  char  TmpDat[4];                   /*����*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482180_E;

/*
 * 482181
 * �㶫ʡ���ų�ֵǰ��ѯ
 */

typedef struct ICS_DEF_482181_I{
  char TCusID[20];       /*�ɷѺ���*/
  char DestAttr[4];      /*�û�����*/
}ICS_DEF_482181_I;

typedef struct ICS_DEF_482181_N{
  char  TmpDat[4];                  /*����*/
  char  ApFmt[5];                   /*ǰ�˿ո�ʽ�� 48D03*/
  char  BalTyp[8];                  /*�������*/
  char  Balance[12];                /*���*/
  char  BalanceUnit[2];             /*��λ*/
  char  EffTime[14];                /*�����Ч�ڿ�ʼʱ��*/
  char	ExpireTime[14];             /*����ʱ�䣬YYYYMMDDHHMMSS*/
}ICS_DEF_482181_N;

typedef struct ICS_DEF_482181_E{
  char  TmpDat[4];                  /*����*/
  char  ApCode1[2];                 /*SC*/
  char  OFmtCd[3];                  /*D04*/
  char  RspCod[6];                  /**/
  char  InPos[4];                   /*0001*/
  char  RspMsg[56];                 /*����ԭ��*/
}ICS_DEF_482181_E;

/*
 * 482182
 * �㶫ʡ�����û����Բ�ѯ
 */

typedef struct ICS_DEF_482182_I{
  char TCusID[20];       /*�ɷѺ���*/
  char DestAttr[4];      /*�û�����*/
}ICS_DEF_482182_I;

typedef struct ICS_DEF_482182_N{
  char  TmpDat[4];                  /*����*/
  char  ApFmt[5];                   /*ǰ�˿ո�ʽ�� 48D03*/
  char  BillMode[3];                 /*�û���������*/
  char  DestAttr[4];                /*����ѯ�û�����*/
  char  DqCode[5];             			/*�������������*/
  char  objectHome[2];              /*�������ƽ̨*/
}ICS_DEF_482182_N;

typedef struct ICS_DEF_482182_E{
  char  TmpDat[4];                   /*����*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482182_E;

/*
 * 482183
 * �㶫ʡ�����û����Բ�ѯ�����
 */

typedef struct ICS_DEF_482183_I{
  char TCusID[20];        /*�ɷѺ���*/
  char TxnAmt[15];       /*���׽��*/
  char DestAttr[4];       /*�û�����*/
  char ActTyp[1];         /*�ʻ�����*/
  char ActNo[21];         /*�����ʺ�*/
  char PinBlk[20];        /*��������*/
  char TxCck2[40];        /*�ڶ��ŵ�*/
  char TxCck3[110];       /*�����ŵ�*/
}ICS_DEF_482183_I;

typedef struct ICS_DEF_482183_N{
  char  TmpDat[4];                  /*����*/
  char  ApFmt[5];                   /*ǰ�˿ո�ʽ�� 48D03*/
  char  BalTyp[8];                  /*�������*/
  char  Balance[12];                /*���*/
  char  BalanceUnit[2];             /*��λ*/
  char  EffTime[14];                /*�����Ч�ڿ�ʼʱ��*/
  char	ExpireTime[14];             /*����ʱ�䣬YYYYMMDDHHMMSS*/
  char  TckNo[11];                  /*�����ˮ*/
}ICS_DEF_482183_N;

typedef struct ICS_DEF_482183_E{
  char  TmpDat[4];                   /*����*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482183_E;

/*
 * 482184
 * �㶫ʡ�����û����Դ�����ѯ
 */

typedef struct ICS_DEF_482184_I{
  char TCusID[20];       /*�ɷѺ���*/
  char DestAttr[4];      /*�û�����*/
}ICS_DEF_482184_I;

typedef struct ICS_DEF_482184_N{
  char  TmpDat[4];                  /*����*/
  char  ApFmt[5];                   /*ǰ�˿ո�ʽ�� 48D03*/  
  char  BalTyp[8];                  /*�������*/
  char  Balance[12];                /*���*/
  char  EffTime[14];                /*�����Ч�ڿ�ʼʱ��*/
  char	ExpireTime[14];             /*����ʱ�䣬YYYYMMDDHHMMSS*/
  char  BillMode[3];                /*�û���������*/
  char  DestAttr[4];                /*����ѯ�û�����*/
  char  DqCode[5];             			/*�������������*/
  char  objectHome[2];              /*�������ƽ̨*/
  char 	TCusID[20];       					/*�ɷѺ���*/
  char	Param1[40];									/*Ԥ���ֶ�*/
}ICS_DEF_482184_N;

typedef struct ICS_DEF_482184_E{
  char  TmpDat[4];                   /*����*/
  char  ApCode1[2];                  /*SC*/
  char  OFmtCd[3];                   /*D04*/
  char  RspCod[6];                   /**/
  char  InPos[4];                    /*0001*/
  char  RspMsg[56];                  /*����ԭ��*/
}ICS_DEF_482184_E;
 


/*
 * 460244
 * ��ѽɷ�ǰ��ѯ
 */

typedef struct ICS_DEF_460244_I{
    char ActNo[21];   /*���п���*/
    char TCusId[21];     /*�ͻ����*/
    char LChkTm[8];  /*����·ݣ�99999999��ʾ����Ƿ�ѣ�yyyymm99��������Ƿ��*/
}ICS_DEF_460244_I;


typedef struct ICS_DEF_460244_N{
    char TmpDat[4];      /*package length*/ 
    char ApCode[2];     /*SC*/
    char OFmtCd[3];     /*D04*/
    char TxnAmt[15];   /*���׽��*/
    char ChkTim[10];   /*��������ʱ��*/
    char DptTyp[4];    /*��Ӫ������*/
    char UsrNam[23];   /*�û�����*/
    char UsrAdd[32];   /*�õ��ַ*/
 }ICS_DEF_460244_N;

typedef struct ICS_DEF_460244_E{
    char TmpDat[4];     /*package length*/
    char ApCode[2];     /*SC*/
    char OFmtCd[3];     /*D04*/
    char  RspCod[6];    /* */
    char InPos[4];     /*0001*/
    char RspMsg[56];/*����ԭ��*/
}ICS_DEF_460244_E;



/*
 * 460245
 *��ѽ���ʵʱ�ɷѽ���
 */

typedef struct ICS_DEF_460245_I{
    char ActNo[21];   /*���˺�*/
    char TCusId[21];  /*�ͻ����*/
    char TCusNm[23];  /*�û�����*/
    char LChkTm[8];   /*����·ݣ�99999999��ʾ����Ƿ�ѣ�yyyymm99��������Ƿ��*/
    char DptTyp[4];   /*���Ͳ�����*/
    char TxnAmt[12];  /*���׽��*/
    char Fee[12];     /*����������*/
    char VchTyp[3];   /*����ƾ֤*/
    char VchNo[8];    /*ƾ֤��*/
    char BilDat[8];   /*ƾ֤����*/
    char PinBlk[20];  /*����*/
}ICS_DEF_460245_I;

typedef struct  ICS_DEF_460245_N{
    char TmpDat[4];   /*package length*/
	  char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char TLogNo[12];  /*���繫˾ϵͳ�ο���*/
    char TckNo[12];   /*���ҵ����ˮ��*/
    char TActDt[4];   /*���繫˾��������*/
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
 * 461501
 * ��ͨ��˰Ӧ����Ϣ��ѯ
 */
typedef struct ICS_DEF_461501_I{
    char AdnCod[20];   /*֪ͨ����*/
    char PBilTyp[10];  /*��ӡƱ������*/
    char PBilNo[20];   /*��ӡƱ�ݱ��*/
    char HndFlg[1];    /*֪ͨ����д��ʽ*/
    char UpdAdnFg[1];  /*��ѯˢ�±�־*/
    char RipFlg[1];    /*˹����Ʊ��־*/
    char DitCod[6];    /*��������*/
}ICS_DEF_461501_I;

typedef struct  ICS_DEF_461501_N{
    char AdnCod[20];   /*֪ͨ����*/
    char PBilTyp[10];  /*��ӡƱ������*/
    char PBilNo[20];   /*��ӡƱ�ݱ��*/
		char LevFlg[3];    /*���շ�ʽ*/
		char WriDat[8];    /*��������*/
		char DitCod[6];    /*��������*/
		char ColUntCd[42]; /*ִ�յ�λ*/
		char ColUntNm[100]; /*ִ�յ�λ����*/
		char CsgUntCd[42];  /*ί�е�λ����*/
		char CsgUntNm[100]; /*ί�е�λ����*/
		char XpayNam[80];   /*���渶������*/
		char XpayAct[40];   /*���渶���˺�*/
		char XpayObk[80];   /*���渶������*/
		char XgatNam[80];   /*�����տ�����*/
		char XgatAct[40];   /*�����տ��˺�*/
		char XgatObk[80];   /*�����տ�����*/
		char AdnSmr[240];   /*��ע*/
		char StpDat[8];     /*�ɿ��ֹ����*/
		char AdnMac[4];     /*У����*/
		char AdnAmt[15];    /*Ӧ���ܽ��*/
		char FinAccIn[21];  /*�����˺�*/
		char PntAmt[15];    /*��˰������*/
		char AgtAmt[15];    /*������ս��*/
		char AgtFlg[1];     /*���ձ�ʾ*/
		char RgnFlg[1];     /*�����־*/
		char AdnTyp[10];    /*֪ͨ������*/
		char RecNum[2];     /*ѭ������*/
		char ItmSeq[1];     /*��Ŀ˳��*/
		char ItmCod[42];    /*������Ŀ����*/
		char ItmNam[100];   /*������Ŀ����*/
		char ItmNum[18];    /*����*/
		char ItmAmt[15];    /*���*/
		char LatTyp[1];     /*���ɽ�����*/
		char ItmTyp[1];     /*��Ŀ����*/
    char IgatAct[40];   /*�����˺�*/
    char IgatNam[80];   /*���뻧��*/
    char IgatBnm[80];	/*��������*/	  
}ICS_DEF_461501_N;

typedef struct ICS_DEF_461501_E{
    char sjcd[4];    /*���ݳ���*/
		char sjgs[5];    /*���ݸ�ʽ*/
		char RspCod[6];
		char InPos[4];
		char RspMsg[56];
}ICS_DEF_461501_E;  


/*
 * 460501
 * �ƶ����۳�ֵҵ��ǩԼ����
 */
typedef struct ICS_DEF_460501_I_MOB{
    char SigTyp[1];   /*ǩԼ����*/
    char VchNO[8];  /*ƾ֤��*/
    char ActTyp[1];  /*�˺�����*/
    char ActNo[28];   /*�����˺�*/
    char ActNam[32];   /*�����˺�����*/
    char IdTyp[02];  /*֤������*/
    char IdNo[20];     /*֤������*/
    char CusNam[32];   /*�ͻ�����*/
    char MstTel[20];    /*���ֻ�����*/
    char SigTel[20];   /*ǩԼ�ֻ�����*/
    char SigFlg[1];  /*ǩԼ��ǣ���0/��1��*/
    char PINDat[20];  /*���н�������*/
}ICS_DEF_460501_I_MOB;

typedef struct  ICS_DEF_460501_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char MstTel[20];  /*���ֻ�����*/
    char SigTel[20];   /*ǩԼ�ֻ�����*/
    char LogNo[30];   /*�ƶ�������ˮ��*/
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
 * �ƶ����۳�ֵҵ���Լ����
 */
typedef struct ICS_DEF_460506_I_MOB{
    char  BisTyp  [1]   ; /*��������1��������������2��ȫ��ǩԼ������*/
    char  ActTyp  [1]   ; /*�˺�����*/
    char  ActNo   [28]  ; /*�����˺�*/
    char  ActNam  [32]  ; /*�����˺�����*/
    char  VchNO   [8]   ; /*ƾ֤��*/
    char  IdTyp   [2]   ; /*֤������*/
    char  IdNo    [20]  ; /*֤������*/
    char  CusNam  [32]  ; /*֤������*/
    char  MstTel  [20]  ; /*���ֻ�����*/
    char  PINDat  [20]  ; /*���н�������*/
}ICS_DEF_460506_I_MOB;

typedef struct  ICS_DEF_460506_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  ActTyp  [1]   ; /* �˺����� */
    char  ActNo   [28]  ; /*�����˺�*/
    char  IdTyp   [2]   ; /* ֤������ */
    char  IdNo    [20]  ; /* ֤������ */
    char  CusNam  [32]  ; /* ֤������ */
    char  MstTel  [20]  ; /* ���ֻ����� */
}ICS_DEF_460506_N_MOB;

typedef struct ICS_DEF_460506_E_MOB{
    char TmpDat[4];
    char ApCode[2];  /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char RspCod[6];  /* */
    char InPos[4];   /*0001*/
    char RspMsg[56]; /* ������Ϣ */
}ICS_DEF_460506_E_MOB;  

/*
 * 460511
 * ��ѯ�˻���Ϣ��Ƕ�ף�
 */
typedef struct ICS_DEF_460511_I_MOB{
    char  ActNo  [21]   ; /*�ʺ�*/
}ICS_DEF_460511_I_MOB;

typedef struct  ICS_DEF_460511_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  IdTyp  [2]  ; /*֤������*/
    char  IdNo   [20] ; /*֤������*/
    char  ActNam [32] ; /*����*/
    char  ActSts [1]  ; /*�ʻ�״̬*/
}ICS_DEF_460511_N_MOB;

typedef struct ICS_DEF_460511_E_MOB{
    char TmpDat[4];
    char ApCode[2];  /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char RspCod[6];  /* */
    char InPos[4];   /*0001*/
    char RspMsg[56]; /* ������Ϣ */
}ICS_DEF_460511_E_MOB;  

/*
 * ͨ�ô���
 */
typedef struct ICS_DEF_DEFAULT_E{
    char  TmpDat[4];
    char  ApCode[2];  /*"SC"*/
    char  OFmtCd[3];  /*"D04"*/
    char  RspCod[6];  /* */
    char  InPos[4];   /*0001*/
    char  RspMsg[56]; /* ������Ϣ */
}ICS_DEF_DEFAULT_E;  


/*
 * 460601
 * ����ֵ������֤(010201)
 */
typedef struct ICS_DEF_460601_I_MOB{
    char  TelNum  [20]   ; /*�ʺ�*/
}ICS_DEF_460601_I_MOB;

typedef struct  ICS_DEF_460601_N_MOB{
    char  TmpDat[4];   /*package length*/
    char  ApCode[2];   /*"SC"*/
    char  OFmtCd[3];  /*"D04"*/
    char  AreCod[4]  ; /*������*/
}ICS_DEF_460601_N_MOB;

/*
 * 460602
 * ������ֵ�����ֵ(010202)
 */
typedef struct ICS_DEF_460602_I_MOB{
    char  TelNum  [20];  /*����ֵ����*/
    char  CrdNo  [15];  /*����*/
    char  TxnAmt  [15];  /*��ֵ���*/
}ICS_DEF_460602_I_MOB;

typedef struct  ICS_DEF_460602_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  ActDat  [8];  /*�������*/
    char  TckNo  [12];  /*�����ˮ��*/
    char  TLogNo  [20];  /*��ͨ��ˮ��*/
}ICS_DEF_460602_N_MOB;

/*
 * 460606
 * ͨ�����Ų�ѯ�ɷѻ����ˮ��
 * TODO �о������ʽ
 */
typedef struct ICS_DEF_460606_I_MOB{
    char  CrdNo  [15];    /*����*/
    char  PagIdx  [6];    /*ҳ����*/
}ICS_DEF_460606_I_MOB;

typedef struct  ICS_DEF_460606_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char  SumCnt[4];       /*�ܼ�¼��*/
    char  PagNo[4];        /*ҳ��*/
    char  RecNum[4];       /*����*/
}ICS_DEF_460606_N_MOB;

/*
 * 460604
 * �ɷѼ�¼��ѯ(010204)
 */
typedef struct ICS_DEF_460604_I_MOB{
    char  ActDat  [8]   ; /*�������*/
    char  RsFld1  [20]  ; /*������ˮ��*/
}ICS_DEF_460604_I_MOB;

typedef struct  ICS_DEF_460604_N_MOB{
    char TmpDat[4];   /*package length*/
    char ApCode[2];   /*"SC"*/
    char OFmtCd[3];  /*"D04"*/
    char TelNum[15]  ; /*����ֵ����*/
    char LogNo[20]  ; /*��ֵ��ˮ��*/
    char TDatTim[20]  ; /*��ֵʱ��*/
    char TResult[2]  ; /*��ֵ�ṹ*/
    char TxnAmt[10]  ; /*��ֵ���*/
}ICS_DEF_460604_N_MOB;
