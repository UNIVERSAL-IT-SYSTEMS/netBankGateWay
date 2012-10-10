/***************************************************************
 DATE:	2003-06-07 chongqing 
 NOTE:  ���и����������к궨�� 
***************************************************************/

/*����Ҫ�غ궨��*/
#define  AreaCode       "078"        /*���е�����*/
#define  ORGCode        "001"        /*���ػ�����*/
#define  TTYNCode       "W0010926"   /*���������ն˺�*/ 
#define  OPTPCode       "07"          /*ҵ������*/ 

/* ���и����������в������� */
#define  LEN_ICS_PROC_BUF       8192
#define  LEN_POST_MID_PROC_BUF  4096
#define  LEN_MID_PROC_BUF  	4096
#define  LEN_TMP_VAL_STR        256
#define  LEN_TMP_VAL_BUF        1024

#define  LEN_MOBILE_NO		11+1
#define  LEN_PAY_AMT		14+1
#define  LEN_CARD_NO		17+1
#define  LEN_PSSD_NO		6+1


/* ע��,TLNO and AUTL ���߶�����ͬ����,�ҳ������趨ΪAUTL,
   �������д���ҵ���Ա�ź���Ȩ��Ա����0926 */
#define  AUTLCode       "0926"          /*�������й�Ա��*/ 

/*���ݿ��ֶγ��Ⱥ궨��*/
/*����ϵͳ���ݿ�*/
#define A1               1           /*CICS��ʽLEN+1*/
#define A0               0           /*TCPIP��ʽLEN+0*/
#define LEN_RGCD         3           /*��������*/
#define LEN_CDST         4           /*��������*/

#define LEN_ACOPTM       14          /*����ʱ��*/
#define LEN_CTOPTM       14          /*֤������ʱ��*/
#define LEN_CTEDTM       14          /*֤���ֹʱ��*/
#define LEN_NCTOPTM      14          /*��֤������ʱ��*/
#define LEN_NCTEDTM      14          /*��֤���ֹʱ��*/ 
#define LEN_TRDTTM       14          /*����ʱ��*/

#define LEN_CTSQ	 12
#define LEN_CTEL	 15
#define LEN_USNM	 60
#define LEN_NAME	 60		/*�ͻ�����*/
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







#define LEN_CUID         13          /*�ͻ���*/
#define LEN_NOTP	 1
#define LEN_FISQ	 4
#define LEN_PSWD	 8
#define LEN_NUTP	 1
#define LEN_PYNU	 20
#define LEN_OMSG	 20
#define LEN_AUNO         8           /*��Ȩ��*/ 
#define LEN_IDNO         32          /*���֤����*/
#define LEN_IDTP         1           /*���֤���*/
#define LEN_CUNM         20          /*�ͻ�����*/
#define LEN_OPTP         1           /*ҵ�����*/
#define LEN_CANO         20          /*�����ʻ�����*/
#define LEN_CTNO         10          /*֤���*/
#define LEN_CTST         1           /*֤��״̬*/
#define LEN_EMAL         32          /*EMAIL��ַ*/
#define LEN_TEL1         32          /*�绰����*/
#define LEN_TEL		 32          
#define LEN_OGCD         3           /*��������*/
#define LEN_TLNO         4           /*��Ա����*/
#define LEN_TTYN         8           /*�ն˺�*/
#define LEN_MGID         7           /*��Ϣ��*/
#define LEN_TRCD         4           /*���״���*/
#define LEN_OANO         20          /*ת���ʻ�*/        
#define LEN_IANO         20          /*ת���ʻ�*/
#define LEN_TRAM         15          /*���׽��*/
#define LEN_AMN0	 15	     /*Ӧ�ս��*/
#define LEN_AMN1	 15	     /*Ӧ�ս��*/
#define LEN_AMN2	 15	     /*Ӧ�ս��*/
#define LEN_ACBL         17          /*�ʻ����*/ 
#define LEN_CACO         2           /*�ʻ�����*/
#define LEN_STNM         8           /*��־��ˮ��*/
#define LEN_CTEF         2           /*֤����Ч��*/
#define LEN_RFPS         6           /*����*/ 
#define LEN_AUD2         8           /*��Ȩ��ֹ����*/
#define LEN_CACK         1           /*��־λ���������غ͸���*/
#define LEN_RGCD         3           /*��������*/
#define LEN_CDNO         19          /*����*/
#define LEN_TRDT         8           /*��������*/
#define LEN_TRTM         6           /*����ʱ��*/
#define LEN_TLCS         8           /*��Ա��ˮ��*/
#define LEN_INTT         15          /*�ۼ���Ϣ*/
#define LEN_DESP         8           /*DES����*/
#define LEN_DSMK         1           /*������־*/
#define LEN_ACUR         3           /*�ظ�����*/
#define LEN_PACUR         3          /*�ظ�����*/
#define LEN_USEB         17          /*�������*/
#define LEN_INAM         15          /*��Ϣ*/
#define LEN_PIDNO        20          /*֤������*/
#define LEN_AUTL         4           /*��Ȩ��Ա*/
#define LEN_ASAM         15          /*������*/
#define LEN_JYDM         40          /*���׵ص���������*/
#define LEN_SPTP         1           /*��Լ�̺�����*/
#define LEN_SPCD         4           /*��Լ�̺�*/
#define LEN_ACNO         20          /*�ʺ�*/
#define LEN_SPNM         40          /*�̻�����*/
#define LEN_BVNM         20          /*��������*/
#define LEN_LNAC         20          /*�����ʺ�*/
#define LEN_TOBL         17          /*ת���ʻ����*/  
#define LEN_TIBL         17          /*ת���ʻ����*/
#define LEN_AUNB         6           /*��Ȩ��*/
#define LEN_RFPD         6           /*���ʽ��ʻ�����*/
#define LEN_CUNB         13          /*�ͻ���*/
#define LEN_SVPD         3           /*����*/
#define LEN_EXDT         8           /*��������*/
#define LEN_INRT         11          /*����*/
#define LEN_INOV         15          /*������Ϣ*/
#define LEN_SRNO         3           /*С���*/
#define LEN_OTCD         3           /*ҵ�����,��"218"*/
#define LEN_BTMT         2           /*ȡϢ���*/
#define LEN_INEP         15          /*ÿ�θ�Ϣ���*/
#define LEN_OGNM         30          /*������������*/
#define LEN_BLAM         17          /*���ý����*/
#define LEN_EVAM         15          /*ÿ�´��*/
#define LEN_DGCD         4           /*ժҪ����*/
#define LEN_TRFG         1           /*���ױ�־��'0'��������'1'������*/
#define LEN_DLTP         1
#define LEN_INTX         15          /*��Ϣ˰*/
#define LEN_ONAM         15          /*����*/
#define LEN_TTAM         17          /*�ܼƽ��*/
#define LEN_PRFG         1           /*��ǰ֧ȡ��־��'0'�����ڣ�'1'����ǰ*/
#define LEN_INPD         15          /*�Ѹ���Ϣ*/
#define LEN_ARIN         15          /*������Ϣ*/
#define LEN_MVIN         15          /*��ֵ��Ϣ*/
#define LEN_RLAM         15          /*ʵ�ʽ��*/
#define LEN_ISDT         8           /*��Ϣ����*/
#define LEN_RCNB         8           /*ƾ֤����*/
#define LEN_CDOU         17          /*ת������*/
#define LEN_CDIN         17          /*ת�뿨��*/
#define LEN_CAOU         20          /*ת�������ʺ�*/
#define LEN_CAIN         20          /*ת�뿨���ʺ�*/
#define LEN_OGNB         4           /*��λ���*/
#define LEN_TRPS         6           /*��������*/
#define LEN_STRN         6           /*��ʼ��¼��*/
#define LEN_RCAM         6           /*��¼����*/
#define LEN_CYTP         2           /*��������*/
#define LEN_IDDT         8           /*��������*/
#define LEN_ISDT         8           /*��Ϣ����*/
#define LEN_IDTL         4           /*������Ա*/
#define LEN_CFQT         8           /*�Ʒ�����*/
#define LEN_AUCR         10          /*�ظ�����*/
#define LEN_ACFG         1           /*��־��'0'��������'1'��׷�ӿ�*/
                                     /* '2'��ɾ����'3'��ɾ����*/
#define LEN_SADT         8           /*��������*/
#define LEN_ITSG         1           /*��Ŀ�洢��1������ 2������ 3������*/
                                     /*4���汾 5������ 6��֪ͨ*/
#define LEN_HMAR         60          /*��ͥ��ַ*/
#define LEN_OGAR         60          /*��λ��ַ*/
#define LEN_HMTN         20          /*��ͥ�绰*/
#define LEN_BPNB         20          /*��������*/
#define LEN_OFTN         20          /*�칫�绰*/
#define LEN_PEMAL        60          /*��̨�ϴ���EMALE���� */
#define LEN_TRPW         8           /*����*/ 
#define LEN_TMP          4096
#define LEN_CANO_SIGN    1           /*account sign 1-���ÿ���2-��ǿ���3-�����ʺ�
                                       4-��㱦��δ�ã�*/ 
#define LEN_ERR          100          /*������Ϣ*/

#define LEN_DTTP         1           /*��ȡ��־*/
#define LEN_NOTP         1           /*��������*/
#define LEN_SSTP         1           /*�ʽ��ʻ�����*/
#define LEN_NGPS         8           /*֤ȯ�ʽ��ȡ����*/

#define LEN_BDAC         18          /*�ʽ��ʻ�*/
#define LEN_CUNM         20          /*�ͻ�����*/
#define LEN_GDCD         10          /*�ɶ�����*/ 

#define LEN_SSTP         1           /*�ʽ��ʻ�����*/
/*CGI���״���궨��*/
/*���潻�״���궨��*/
#define AcctOpen         1101        /*���濪��*/
#define AcctAdd          1102        /*����׷���ʺ�*/ 
#define AcctDel          1103        /*�����ʻ�����*/ 
#define TLCancel         1104        /*����ͻ�������*/       
#define Query            1105        /*��ѯ�ͻ���*/  

/*���Ͻ��״���궨��*/
#define Login            1201        /*�ͻ����ϵ�¼*/
#define NetAdd           1202        /*����׷���ʺ�*/
#define NetDel           1203        /*���ϵ����ʻ�����*/
#define NetCancel        1204        /*���Ͽͻ�������*/
#define QueryTransDetail 1206        /*��ѯ��������ϸ*/    

/*CA�ཻ�״���궨��*/
#define CustomCheck      1301        /*��֤�ͻ���Ϣ*/
#define CustomFillCIDB   1302        /*����CIDB֤���*/
#define CustomUpdateCheck 1303       /*�ͻ�������֤��Ϣ*/
#define BankCancel       1304        /*������������*/ 
#define BlackList        1305        /*д�������б�*/




/*ҵ���״���궨��*/
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
/*���������ɫҵ��begin*/
/*1.��Ѻ����*/
#define Trans8480        "8480"
/*���������ɫҵ��end*/


/*��Ϣ����궨��*/
#define TRCDNOEXIST      -1000
#define TRANSOVER         0
#define TRANSOK          "AAAAAAA"

#define TRANERRHEAD      "1234567"
#define TRANERRBODY      "ϵͳ��"

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
