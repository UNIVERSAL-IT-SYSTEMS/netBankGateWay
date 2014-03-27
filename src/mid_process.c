#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "netbank_mid.h"
#include "trans_macro.h"

int	start_mid_process(char *send_buff,char *recv_buff)
{
	int	ret;
	int 	i_biz_id,i_biz_step_id;
	char	s_biz_id[5],s_biz_step_id[5];
	char 	s_biz_no[6];
  memset(recv_buff,0,sizeof(recv_buff));
	memset(s_biz_id,'\0',sizeof(s_biz_id));
	memset(s_biz_no,'\0',sizeof(s_biz_no));
	memset(s_biz_step_id,'\0',sizeof(s_biz_step_id));

	flog(STEP_LEVEL, "mid_process.c -->进行分行特色业务工作... send_buff=[%s]",send_buff);

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
	    case 1:/*长市话费*/
	    case 2:/*小灵通预付费充值*/
	    case 3:/*电信16300上网费*/
	    case 4:/*电信ADSL上网费*/
	    case 5:/*电信预缴费卡充值*/
	    case 6:/*电信宽带预缴费*/
	    /*add 20090315 begin*/
	    case 22: /* 电信CDMA查询 */
	    case 23: /* 电信CDMA预付费查询 */     
      /*add 20090315 end*/
		switch(i_biz_step_id)
		{
		    case 1: /*缴费前查询*/
			ret=ics_proc_482101(send_buff,recv_buff); break;
                	flog(STEP_LEVEL,"--------482101--------ret=[%d]",ret);
			break;
		    case 2: /*代收费*/
			ret=ics_proc_482102(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482102--------ret=[%d]",ret);
			break;
		}
		break;
	    case 7:/*移动*/
		switch(i_biz_step_id)
		{
		    case 1: /*查询*/
			ret=ics_proc_482108(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482108--------ret=[%d]",ret);
			break;
		    case 2: /*缴费*/
			ret=ics_proc_482110(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482110--------ret=[%d]",ret);
			break;
		}
		break;
	    case 8:/*联通*/
		switch(i_biz_step_id)
		{
		    case 1: /*查询*/
			ret=ics_proc_482111(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482111--------ret=[%d]",ret);
			break;
		    case 2: /*缴费*/
			ret=ics_proc_482112(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482112--------ret=[%d]",ret);
			break;
		}
		break;
	    /*modify 20090315 begin
	    case 11:*//*车船税*/
	    case 9:
	    /*modify 20090315 end*/
		switch(i_biz_step_id)
		{
		    case 1: /*查询*/
			ret=ics_proc_482115(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482115--------ret=[%d]",ret);
			break;
		    case 2: /*缴费*/
			ret=ics_proc_482116(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482116--------ret=[%d]",ret);
			break;
		}
		break;
		/*add 20090315 begin*/
			case 21:	/*银旅通*/
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
			case 25:/*羊城通空中充值*/
		switch(i_biz_step_id)
		{
			case 1: /*查询签约信息*/
				ret=ics_proc_482149(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482149--------ret=[%d]",ret);
				break;
			case 2: /*签约交易*/
				ret=ics_proc_482138(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482138--------ret=[%d]",ret);
				break;
			case 3: /*解约交易*/
				ret=ics_proc_482139(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482139--------ret=[%d]",ret);
				break;
			case 4: /*查询账户信息*/
				ret=ics_proc_482140(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482140--------ret=[%d]",ret);
				break;	
			case 5: /*激活羊城通*/
				ret=ics_proc_482136(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482136--------ret=[%d]",ret);
				break;
			case 6: /*查询历史交易记录*/
				ret=ics_proc_482159(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482159--------ret=[%d]",ret);
				break;
		}
		break;
		/*广东省电信直连充值*/
        case 26:
        switch(i_biz_step_id)
            {
            /*
            case 0: //查询号码归属地
                    ret=ics_proc_482180(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482180--------ret=[%d]",ret);
                    break;
            */
            case 1: /*查询余额*/
                ret=ics_proc_482184(send_buff,recv_buff);break;
                flog(STEP_LEVEL,"--------482184--------ret=[%d]",ret);
                break;
            case 2: /*查询用户属性*/
                ret=ics_proc_482183(send_buff,recv_buff);break;
                flog(STEP_LEVEL,"--------482183--------ret=[%d]",ret);
                break;
     case 3: /*充值*/
                    ret=ics_proc_482183(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482183--------ret=[%d]",ret);
                    break;
                case 4: /*查询用户属性带余额*/
                    ret=ics_proc_482184(send_buff,recv_buff);break;
                    flog(STEP_LEVEL,"--------482184--------ret=[%d]",ret);
                break;
            }
        break;
		/*移动充值易*/
		case 28:
		switch(i_biz_step_id)
		{
		    case 1: /*查询*/
			ret=ics_proc_482171(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482171--------ret=[%d]",ret);
			break;
		    case 2: /*缴费*/
			ret=ics_proc_482173(send_buff,recv_buff);break;
                	flog(STEP_LEVEL,"--------482173--------ret=[%d]",ret);
			break;
		}
		break;
			case 30:/*网银历史记录查询*/
		switch(i_biz_step_id)
		{
			case 1: /*查询*/
				ret=ics_proc_482145(send_buff,recv_buff);break;
				flog(STEP_LEVEL,"--------482145--------ret=[%d]",ret);
				break;
		}
		break;

		/*add 20100618 体育彩票 begin*/
		case 29:	/*体育彩票*/
			switch(i_biz_step_id)
			{
				case 1: /*体彩查询投注情况*/
					ret=ics_proc_482103_tc(send_buff,recv_buff);
					flog(STEP_LEVEL,"--------482103--------ret=[%d]",ret);
					break;
				case 2: /*体彩购彩号码校验*/
					ret=ics_proc_482102_tc(send_buff,recv_buff);break;
					flog(STEP_LEVEL,"--------482102--------ret=[%d]",ret);
					break;				
				case 3: /*体彩购彩交易    */
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

   /*add 20111010 电费缴纳 begin*/
     case 31:    /* 电费缴纳*/
        switch(i_biz_step_id)
        {
            case 1: /*查询*/
                ret=ics_proc_460244_df(send_buff,recv_buff);break;
                flog(STEP_LEVEL,"--------460244--------ret=[%d]",ret);
                break;
            case 2: /*缴费*/
                ret=ics_proc_460245_df(send_buff,recv_buff);break;
                flog(STEP_LEVEL,"--------460245--------ret=[%d]",ret);
                break;
        }
        break;
  /*add 20111010 电费缴纳 end */
          /*add 20121010 移动划扣 begin*/ 
            case 32:    /* 移动划扣*/
               switch(i_biz_step_id)
               {
                   case 1: /*移动划扣充值业务签约交易*/
                       ret=ics_proc_460501_mob(send_buff,recv_buff);break;
                       flog(STEP_LEVEL,"--------460501--------ret=[%d]",ret);
                       break;
                   case 2: /*移动划扣充值业务解约交易*/
                       ret=ics_proc_460506_mob(send_buff,recv_buff);break;
                       flog(STEP_LEVEL,"--------460506--------ret=[%d]",ret);
                       break;
                   case 3: /*查询账户信息（嵌套）*/
                       ret=ics_proc_460511_mob(send_buff,recv_buff);break;
                       flog(STEP_LEVEL,"--------460511--------ret=[%d]",ret);
                       break;
               }
               break;
          /*add 20121010 移动划扣 end */

	default:
		break;
	}

	/* 判断子交易调用返回情况 */
	if (ret < 0)
	return -1;
			
	flog(STEP_LEVEL, "mid_process.c -->分行特色业务完成[%s]",recv_buff);

	return RETURN_OK;
}

/* End of this file */
