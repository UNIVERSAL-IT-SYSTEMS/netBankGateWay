#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "netbank_mid.h"
#include "trans_macro.h"

int    start_mid_process(char *send_buff,char *recv_buff)
{
    int    ret;
    int     i_biz_id,i_biz_step_id;
    char    s_biz_id[5],s_biz_step_id[5];
    char     s_biz_no[6];
    memset(recv_buff,0,sizeof(recv_buff));
    memset(s_biz_id,'\0',sizeof(s_biz_id));
    memset(s_biz_no,'\0',sizeof(s_biz_no));
    memset(s_biz_step_id,'\0',sizeof(s_biz_step_id));

    flog(STEP_LEVEL, "mid_process.c -->���з�����ɫҵ����... send_buff=[%s]",send_buff);

    i_biz_id=getValueOfInt(send_buff,"biz_id");
    sprintf(s_biz_no,"%05d",i_biz_id);
    i_biz_step_id=getValueOfInt(send_buff,"biz_step_id");

/*
flog(STEP_LEVEL,"i_biz_id=[%d] step_id=[%d] [%s]",i_biz_id,i_biz_step_id,send_buff);
*/

    if ( memcmp( send_buff + 1, "govcard", 7 ) == 0 )
    {
        strcat(recv_buff,"|govcard|");
        setValueOfInt(recv_buff,"biz_id",i_biz_id);
        setValueOfInt(recv_buff,"biz_step_id",i_biz_step_id);
    }
    else
    {
        strcat(recv_buff,"|bocom_mid|");
        setValueOfInt(recv_buff,"biz_id",i_biz_id);
        setValueOfStr(recv_buff,"biz_no",s_biz_no);
        setValueOfInt(recv_buff,"biz_step_id",i_biz_step_id);
    }

    switch(i_biz_id)
    {
        case 1:/*���л���*/
        case 2:/*С��ͨԤ���ѳ�ֵ*/
        case 3:/*����16300������*/
        case 4:/*����ADSL������*/
        case 5:/*����Ԥ�ɷѿ���ֵ*/
        case 6:/*���ſ��Ԥ�ɷ�*/
        /*add 20090315 begin*/
        case 22: /* ����CDMA��ѯ */
        case 23: /* ����CDMAԤ���Ѳ�ѯ */     
            /*add 20090315 end*/
            switch(i_biz_step_id)
            {
                case 1: /*�ɷ�ǰ��ѯ*/
                    ret=ics_proc_482101(send_buff,recv_buff); break;
                            flog(STEP_LEVEL,"--------482101--------ret=[%d]",ret);
                    break;
                case 2: /*���շ�*/
                    ret=ics_proc_482102(send_buff,recv_buff);break;
                            flog(STEP_LEVEL,"--------482102--------ret=[%d]",ret);
                    break;
            }
            break;
        case 7:/*�ƶ�*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482108(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482108--------ret=[%d]",ret);
                    break;
                case 2: /*�ɷ�*/
                    ret=ics_proc_482110(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482110--------ret=[%d]",ret);
                    break;
            }
            break;
        case 8:/*��ͨ*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482111(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482111--------ret=[%d]",ret);
                    break;
                case 2: /*�ɷ�*/
                    ret=ics_proc_482112(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482112--------ret=[%d]",ret);
                    break;
            }
            break;
        case 0:/*����Ա��*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_461191(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------461191--------ret=[%d]",ret);
                    break;
                case 2: /**/
                    break;
            }
            break;
        /*modify 20090315 begin
        case 11:*//*����˰*/
        case 9:
        /*modify 20090315 end*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482115(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482115--------ret=[%d]",ret);
                    break;
                case 2: /*�ɷ�*/
                    ret=ics_proc_482116(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482116--------ret=[%d]",ret);
                    break;
            }
            break;
        /*add 20090315 begin*/
        case 21:    /*����ͨ*/
            switch(i_biz_step_id)
            {
                case 1: /**/
                    ret=ics_proc_482131(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482131--------ret=[%d]",ret);
                    break;
                case 2: /**/
                    ret=ics_proc_482132(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482132--------ret=[%d]",ret);
                    break;                
                case 3: /**/
                    ret=ics_proc_482133(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482133--------ret=[%d]",ret);
                    break;
                case 4: /**/
                    ret=ics_proc_482134(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482134--------ret=[%d]",ret);
                    break;                
                case 5: /**/
                    ret=ics_proc_482135(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482135--------ret=[%d]",ret);
                    break;
                case 6: /**/
                    ret=ics_proc_482147(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482147--------ret=[%d]",ret);
                    break;                                    
            }        
            break;
        case 25:/*���ͨ���г�ֵ*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯǩԼ��Ϣ*/
                    ret=ics_proc_482149(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482149--------ret=[%d]",ret);
                    break;
                case 2: /*ǩԼ����*/
                    ret=ics_proc_482138(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482138--------ret=[%d]",ret);
                    break;
                case 3: /*��Լ����*/
                    ret=ics_proc_482139(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482139--------ret=[%d]",ret);
                    break;
                case 4: /*��ѯ�˻���Ϣ*/
                    ret=ics_proc_482140(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482140--------ret=[%d]",ret);
                    break;    
                case 5: /*�������ͨ*/
                    ret=ics_proc_482136(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482136--------ret=[%d]",ret);
                    break;
                case 6: /*��ѯ��ʷ���׼�¼*/
                    ret=ics_proc_482159(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482159--------ret=[%d]",ret);
                    break;
            }
            break;
        
        /*�㶫ʡ����ֱ����ֵ*/
        case 26:
            switch(i_biz_step_id)
            {
                case 0: /*��ѯ���������*/
                    ret=ics_proc_482180(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482180--------ret=[%d]",ret);
                    break;
                case 1: /*��ѯ���*/
                    ret=ics_proc_482184(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482184--------ret=[%d]",ret);
                    break;
                case 2: /*��ѯ�û�����*/
                    ret=ics_proc_482183(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482183--------ret=[%d]",ret);
                    break;    
                case 3: /*��ֵ*/
                    ret=ics_proc_482183(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482183--------ret=[%d]",ret);
                    break;
                case 4: /*��ѯ�û����Դ����*/
                    ret=ics_proc_482184(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482184--------ret=[%d]",ret);
                break;
            }
            break;

        /*�ƶ���ֵ��*/
        case 28:
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                ret=ics_proc_482171(send_buff,recv_buff);break;
                        flog(STEP_LEVEL,"--------482171------ret=[%d]",ret);
                break;
                case 2: /*�ɷ�*/
                ret=ics_proc_482173(send_buff,recv_buff);break;
                        flog(STEP_LEVEL,"--------482173--------ret=[%d]",ret);
                break;
            }
            break;
        case 30:/*������ʷ��¼��ѯ*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482145(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482145--------ret=[%d]",ret);
                    break;
            }
            break;
        /*add 20090315 end*/
        case 111:/*�̻���ϸ��ѯ*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482148(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482148--------ret=[%d]",ret);
                    break;
            }
            break;
        /*add xuan for test  end*/
        case 999:/*test*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_482999(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482999--------ret=[%d]",ret);
                    break;
            }

        /*add 20100618 ������Ʊ begin*/
        case 29:    /*������Ʊ*/
            switch(i_biz_step_id)
            {
                case 1: /*��ʲ�ѯͶע���*/
                    ret=ics_proc_482103_tc(send_buff,recv_buff);
                    flog(STEP_LEVEL,"--------482103--------ret=[%d]",ret);
                    break;
                case 2: /*��ʹ��ʺ���У��*/
                    ret=ics_proc_482102_tc(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482102--------ret=[%d]",ret);
                    break;                
                case 3: /*��ʹ��ʽ���    */
                    ret=ics_proc_482101_tc(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482133--------ret=[%d]",ret);
                    break;
                /*case 4: 
                    ret=ics_proc_482134(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482134--------ret=[%d]",ret);
                    break;                
                case 5: 
                    ret=ics_proc_482135(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482135--------ret=[%d]",ret);
                    break;
                case 6: 
                    ret=ics_proc_482147(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482147--------ret=[%d]",ret);
                    break;*/
            }        
        break;

        /*add 20111010 ��ѽ��� begin*/ 
        case 31:    /* ��ѽ���*/
            switch(i_biz_step_id)
            {
                case 1: /*��ѯ*/
                    ret=ics_proc_460244_df(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------460244--------ret=[%d]",ret);
                    break;
                case 2: /*�ɷ�*/
                    ret=ics_proc_460245_df(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------460245--------ret=[%d]",ret);
                    break;
            }
        break;
        /*add 20111010 ��ѽ��� end */      

        /*add 20121010 �ƶ����� begin*/ 
        case 32:    /* �ƶ�����*/
            switch(i_biz_step_id)
            {
                case 1: /*�ƶ����۳�ֵҵ��ǩԼ����*/
                    ret=ics_proc_460501_mob(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------460501--------ret=[%d]",ret);
                    break;
                case 2: /*�ƶ����۳�ֵҵ���Լ����*/
                    ret=ics_proc_460506_mob(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------460506--------ret=[%d]",ret);
                    break;
                case 3: /*��ѯ�˻���Ϣ��Ƕ�ף�*/
                    ret=ics_proc_460511_mob(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------460511--------ret=[%d]",ret);
                    break;
            }
            break;
        /*add 20121010 �ƶ����� end */      
        /*add 20121119 ��ֱͨ�� begin*/
        case 33:    /* ��ֱͨ��*/
            switch(i_biz_step_id)
            {
                case 1: /*����ֵ������֤(010201)*/
                    ret=ics_proc_460601_unca(send_buff,recv_buff);
                    break;
                /*case 2: ������ֵ�����ֵ(010202)
                    ret=ics_proc_460602_unca(send_buff,recv_buff);break;
                case 3: ͨ�����Ų�ѯ�ɷѻ����ˮ��
                    ret=ics_proc_460606_unca(send_buff,recv_buff);break;
                case 4: �ɷѼ�¼��ѯ(010204)
                    ret=ics_proc_460604_unca(send_buff,recv_buff);break;*/
            }
            break;
        /*add 20121119 ��ֱͨ�� end */
        
        /*add 20130225 ��˰ҵ�� begin*/
        
        case 34:    /* �����з�˰ҵ��*/
            switch(i_biz_step_id)
            {
                case 1: /*��ͨ��˰��Ӧ�ɲ�ѯ*/
                    ret=ics_proc_461501_pnta(send_buff,recv_buff);
                    flog(STEP_LEVEL,"--------461501--------ret=[%d]",ret);
                    break;
                case 2: /*��ͨ�����Ӧ�ɲ�ѯ*/
                    ret=ics_proc_461509_pnta(send_buff,recv_buff);
                    flog(STEP_LEVEL,"--------461509--------ret=[%d]",ret);
                    break;
                case 3: /*�ۿ��*/
                    ret=ics_proc_461502_pnta(send_buff,recv_buff);
                    flog(STEP_LEVEL,"--------461502--------ret=[%d]",ret);
                    break;
                case 4: /*���Ͳ����ۿ���Ϣ*/
                    ret=ics_proc_461503_pnta(send_buff,recv_buff);
                    flog(STEP_LEVEL,"--------461503--------ret=[%d]",ret);
                    break;
            }
            break;
        /*add 20130225 ��˰ҵ�� end */
        
        
        
        
        default:
            break;
    }

    /* �ж��ӽ��׵��÷������ */
    if (ret < 0)
    return -1;
            
    flog(STEP_LEVEL, "mid_process.c -->������ɫҵ�����[%s]",recv_buff);

    return RETURN_OK;
}

/* End of this file */
