/*--------------------------------------------*/
/* 本程序由程序generr自动生成，请不要手工修改 */
/* 如需重新生成该程序，请运行命令generr即可   */
/*--------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static	char	errmsg[100];

char* get_host_errcode_msg(char* errcode)
{
	int	errnum;

	errnum = atoi(errcode);
	memset(errmsg, 0, sizeof(errmsg));
	switch (errnum) {
		case	0	:
			strcpy(errmsg, "主机:交易成功");
			break;
		case	1	:
			strcpy(errmsg, "主机:交易继续");
			break;
		case	1001	:
			strcpy(errmsg, "主机:交易码错");
			break;
		case	1002	:
			strcpy(errmsg, "主机:交易子码错");
			break;
		case	1003	:
			strcpy(errmsg, "主机:无此交易");
			break;
		case	1004	:
			strcpy(errmsg, "主机:写交易流水错");
			break;
		case	1005	:
			strcpy(errmsg, "主机:写交易流水对照表错");
			break;
		case	1006	:
			strcpy(errmsg, "主机:写交易稽核文件出错");
			break;
		case	1007	:
			strcpy(errmsg, "主机:交易已经抹帐");
			break;
		case	1008	:
			strcpy(errmsg, "主机:抹帐的交易不存在");
			break;
		case	1009	:
			strcpy(errmsg, "主机:该笔交易不能抹帐");
			break;
		case	1020	:
			strcpy(errmsg, "主机:被冲正的交易金额不对");
			break;
		case	1021	:
			strcpy(errmsg, "主机:被冲正的交易不存在");
			break;
		case	1030	:
			strcpy(errmsg, "主机:该交易禁止更正");
			break;
		case	1031	:
			strcpy(errmsg, "主机:非此项交易处理范围");
			break;
		case	1032	:
			strcpy(errmsg, "主机:所有交易的操作类别与柜员属性冲突");
			break;
		case	1101	:
			strcpy(errmsg, "主机:系统错误请通知计算中心");
			break;
		case	1102	:
			strcpy(errmsg, "主机:数据库操作失败");
			break;
		case	1103	:
			strcpy(errmsg, "主机:SQL调用错");
			break;
		case	1104	:
			strcpy(errmsg, "主机:没有设置环境变量WORKDIR");
			break;
		case	1105	:
			strcpy(errmsg, "主机:DEC运算错");
			break;
		case	1106	:
			strcpy(errmsg, "主机:DECIMAL型计算错");
			break;
		case	1107	:
			strcpy(errmsg, "主机:通信超时");
			break;
		case	1108	:
			strcpy(errmsg, "主机:上传数据检查出错");
			break;
		case	1109	:
			strcpy(errmsg, "主机:函数出错");
			break;
		case	1110	:
			strcpy(errmsg, "主机:溢出");
			break;
		case	1111	:
			strcpy(errmsg, "主机:接收方密码错");
			break;
		case	1112	:
			strcpy(errmsg, "主机:密码不符");
			break;
		case	1113	:
			strcpy(errmsg, "主机:状态错");
			break;
		case	1114	:
			strcpy(errmsg, "主机:日期出错");
			break;
		case	1115	:
			strcpy(errmsg, "主机:查询结束");
			break;
		case	1116	:
			strcpy(errmsg, "主机:无此分类");
			break;
		case	1117	:
			strcpy(errmsg, "主机:入口参数检查错");
			break;
		case	1118	:
			strcpy(errmsg, "主机:查询结束");
			break;
		case	1119	:
			strcpy(errmsg, "主机:IC卡无效");
			break;
		case	1150	:
			strcpy(errmsg, "主机:打开文件错");
			break;
		case	1151	:
			strcpy(errmsg, "主机:生成文件错");
			break;
		case	1152	:
			strcpy(errmsg, "主机:读文件错");
			break;
		case	1153	:
			strcpy(errmsg, "主机:写文件错");
			break;
		case	1154	:
			strcpy(errmsg, "主机:数据/报表文件不存在");
			break;
		case	1201	:
			strcpy(errmsg, "主机:没有满足条件的记录");
			break;
		case	1202	:
			strcpy(errmsg, "主机:记录已存在");
			break;
		case	1203	:
			strcpy(errmsg, "主机:读错记录");
			break;
		case	1204	:
			strcpy(errmsg, "主机:写记录错");
			break;
		case	1205	:
			strcpy(errmsg, "主机:修改记录出错");
			break;
		case	1206	:
			strcpy(errmsg, "主机:无修改内容");
			break;
		case	1208	:
			strcpy(errmsg, "主机:交易授权已存在");
			break;
		case	1209	:
			strcpy(errmsg, "主机:不同级别的授权方式冲突");
			break;
		case	1210	:
			strcpy(errmsg, "主机:没有找到相应的底卡");
			break;
		case	1211	:
			strcpy(errmsg, "主机:此交易只能在票据签发行使用");
			break;
		case	1212	:
			strcpy(errmsg, "主机:本日所有场次均已结束");
			break;
		case	1213	:
			strcpy(errmsg, "主机:上一场未做提出处理");
			break;
		case	1214	:
			strcpy(errmsg, "主机:两场以上交换场次的情况暂不能处理");
			break;
		case	1215	:
			strcpy(errmsg, "主机:只有管辖行才能做提出处理交易");
			break;
		case	1216	:
			strcpy(errmsg, "主机:全部场次结束标志错");
			break;
		case	1217	:
			strcpy(errmsg, "主机:修改交换自动入帐登记表错");
			break;
		case	1218	:
			strcpy(errmsg, "主机:目前外币交换只有一场");
			break;
		case	1219	:
			strcpy(errmsg, "主机:本日上场未提出不可恢复");
			break;
		case	1220	:
			strcpy(errmsg, "主机:代理行交换还未结束");
			break;
		case	1221	:
			strcpy(errmsg, "主机:已做提出处理的交易不能抹帐");
			break;
		case	1222	:
			strcpy(errmsg, "主机:登记人行资金清算表错");
			break;
		case	1223	:
			strcpy(errmsg, "主机:今日一场交换已经结束");
			break;
		case	1224	:
			strcpy(errmsg, "主机:今日二场交换已经结束");
			break;
		case	1225	:
			strcpy(errmsg, "主机:修改人行资金清算表错");
			break;
		case	1226	:
			strcpy(errmsg, "主机:定期帐号错");
			break;
		case	1227	:
			strcpy(errmsg, "主机:销期收票据登记表错");
			break;
		case	1228	:
			strcpy(errmsg, "主机:改笔流水不允许抹帐");
			break;
		case	1229	:
			strcpy(errmsg, "主机:登记交换转汇登记表错");
			break;
		case	1230	:
			strcpy(errmsg, "主机:计算入帐时间错");
			break;
		case	1231	:
			strcpy(errmsg, "主机:本日提出场次未全部结束");
			break;
		case	1232	:
			strcpy(errmsg, "主机:销帐号错");
			break;
		case	1233	:
			strcpy(errmsg, "主机:汇票类型错");
			break;
		case	1234	:
			strcpy(errmsg, "主机:修改退票登记簿错");
			break;
		case	1235	:
			strcpy(errmsg, "主机:销帐帐号不允许记");
			break;
		case	1236	:
			strcpy(errmsg, "主机:自动扣还贷款本金欠息表错");
			break;
		case	1237	:
			strcpy(errmsg, "主机:定期帐号下的所有存单已结清");
			break;
		case	10001	:
			strcpy(errmsg, "主机:会计帐户出错");
			break;
		case	10002	:
			strcpy(errmsg, "主机:无此会计帐户");
			break;
		case	10003	:
			strcpy(errmsg, "主机:会计帐户存在");
			break;
		case	10004	:
			strcpy(errmsg, "主机:会计帐户状态错");
			break;
		case	10005	:
			strcpy(errmsg, "主机:生成会计帐户出错");
			break;
		case	10006	:
			strcpy(errmsg, "主机:修改会计帐户出错");
			break;
		case	10007	:
			strcpy(errmsg, "主机:变更归属会计帐户出错");
			break;
		case	10008	:
			strcpy(errmsg, "主机:归属会计帐户不同");
			break;
		case	10009	:
			strcpy(errmsg, "主机:生成会计帐户级总帐出错");
			break;
		case	10010	:
			strcpy(errmsg, "主机:会计帐户级总帐出错");
			break;
		case	10011	:
			strcpy(errmsg, "主机:会计帐户级总帐中存在");
			break;
		case	10012	:
			strcpy(errmsg, "主机:生成总帐出错");
			break;
		case	10013	:
			strcpy(errmsg, "主机:更新分户帐错");
			break;
		case	10014	:
			strcpy(errmsg, "主机:更新两呆贷款卡片帐错");
			break;
		case	10015	:
			strcpy(errmsg, "主机:更新按揭贷款卡片帐错");
			break;
		case	10016	:
			strcpy(errmsg, "主机:更新贷款卡片帐错");
			break;
		case	10017	:
			strcpy(errmsg, "主机:会计帐户科目对照表出错");
			break;
		case	10024	:
			strcpy(errmsg, "主机:无对应日会计帐户");
			break;
		case	10025	:
			strcpy(errmsg, "主机:调整前后会计帐户相同");
			break;
		case	10026	:
			strcpy(errmsg, "主机:输入帐户无归属会计帐户");
			break;
		case	10027	:
			strcpy(errmsg, "主机:不归属同一支行");
			break;
		case	10028	:
			strcpy(errmsg, "主机:新部门对应帐户不存在");
			break;
		case	10101	:
			strcpy(errmsg, "主机:公共记帐出错");
			break;
		case	10102	:
			strcpy(errmsg, "主机:公共记帐更新分户帐出错");
			break;
		case	10103	:
			strcpy(errmsg, "主机:公共记帐修改会计流水出错");
			break;
		case	10104	:
			strcpy(errmsg, "主机:公共记帐可支付数不足");
			break;
		case	10105	:
			strcpy(errmsg, "主机:公共记帐分录数出错");
			break;
		case	10106	:
			strcpy(errmsg, "主机:公共记帐借贷金额不平");
			break;
		case	10107	:
			strcpy(errmsg, "主机:公共记帐会计流水已作废");
			break;
		case	10108	:
			strcpy(errmsg, "主机:公共记帐会计流水已抹帐");
			break;
		case	10109	:
			strcpy(errmsg, "主机:公共记帐删除会计流水出错");
			break;
		case	10110	:
			strcpy(errmsg, "主机:公共记帐会计流水状态错");
			break;
		case	10111	:
			strcpy(errmsg, "主机:公共记帐内部帐户控制出错");
			break;
		case	10112	:
			strcpy(errmsg, "主机:帐务性质错");
			break;
		case	10114	:
			strcpy(errmsg, "主机:公共记帐销帐错");
			break;
		case	10115	:
			strcpy(errmsg, "主机:公共记帐销帐金额错");
			break;
		case	10116	:
			strcpy(errmsg, "主机:公共记帐销帐编号错");
			break;
		case	10117	:
			strcpy(errmsg, "主机:公共记帐修改销帐编号错");
			break;
		case	10118	:
			strcpy(errmsg, "主机:公共记帐外汇限额不足");
			break;
		case	10119	:
			strcpy(errmsg, "主机:公共记帐外汇限额修改出错");
			break;
		case	10120	:
			strcpy(errmsg, "主机:公共记帐登记会计流水出错");
			break;
		case	10121	:
			strcpy(errmsg, "主机:公共记帐恢复销帐出错");
			break;
		case	10122	:
			strcpy(errmsg, "主机:帐号类型出错");
			break;
		case	10123	:
			strcpy(errmsg, "主机:无归属中央会计");
			break;
		case	10124	:
			strcpy(errmsg, "主机:预销计息户只出不进");
			break;
		case	10125	:
			strcpy(errmsg, "主机:与会计流水不匹配");
			break;
		case	10201	:
			strcpy(errmsg, "主机:会计日期出错");
			break;
		case	10202	:
			strcpy(errmsg, "主机:取会计日期错");
			break;
		case	10203	:
			strcpy(errmsg, "主机:取会计分录错");
			break;
		case	10204	:
			strcpy(errmsg, "主机:记会计流水错");
			break;
		case	10205	:
			strcpy(errmsg, "主机:自动生成会计分录出错");
			break;
		case	10206	:
			strcpy(errmsg, "主机:调用取会计分录函数错");
			break;
		case	10207	:
			strcpy(errmsg, "主机:系统日期大于会计日期");
			break;
		case	10208	:
			strcpy(errmsg, "主机:参数错");
			break;
		case	10209	:
			strcpy(errmsg, "主机:自动分录不存在");
			break;
		case	10210	:
			strcpy(errmsg, "主机:自动分录序号跳号");
			break;
		case	10301	:
			strcpy(errmsg, "主机:自动细目错");
			break;
		case	10302	:
			strcpy(errmsg, "主机:创建自动细目错");
			break;
		case	10303	:
			strcpy(errmsg, "主机:取销自动细目错");
			break;
		case	10304	:
			strcpy(errmsg, "主机:自动细目已存在");
			break;
		case	20001	:
			strcpy(errmsg, "主机:客户状态错");
			break;
		case	20002	:
			strcpy(errmsg, "主机:客户号无效");
			break;
		case	20003	:
			strcpy(errmsg, "主机:客户号不存在");
			break;
		case	20004	:
			strcpy(errmsg, "主机:客户号超界");
			break;
		case	20005	:
			strcpy(errmsg, "主机:客户已销户");
			break;
		case	20006	:
			strcpy(errmsg, "主机:户名与客户档案不符");
			break;
		case	20007	:
			strcpy(errmsg, "主机:担保单位客户号错");
			break;
		case	20009	:
			strcpy(errmsg, "主机:客户信息不存在");
			break;
		case	20010	:
			strcpy(errmsg, "主机:客户号相同");
			break;
		case	20013	:
			strcpy(errmsg, "主机:结算户客户号与输入的客户号不符");
			break;
		case	20014	:
			strcpy(errmsg, "主机:读对公客户信息错");
			break;
		case	20015	:
			strcpy(errmsg, "主机:取客户号错");
			break;
		case	20016	:
			strcpy(errmsg, "主机:取法人客户号错");
			break;
		case	20051	:
			strcpy(errmsg, "主机:证件号码已使用");
			break;
		case	20052	:
			strcpy(errmsg, "主机:法人客户不存在");
			break;
		case	20053	:
			strcpy(errmsg, "主机:法人客户已销户");
			break;
		case	20054	:
			strcpy(errmsg, "主机:法人客户下有客户未销户");
			break;
		case	20055	:
			strcpy(errmsg, "主机:结算户客户号与定期帐号客户号不同");
			break;
		case	20056	:
			strcpy(errmsg, "主机:法人客户已存在");
			break;
		case	20101	:
			strcpy(errmsg, "主机:相关客户号无效");
			break;
		case	20102	:
			strcpy(errmsg, "主机:相关客户已存在");
			break;
		case	20103	:
			strcpy(errmsg, "主机:相关客户不存在");
			break;
		case	20104	:
			strcpy(errmsg, "主机:相关客户已取消");
			break;
		case	20105	:
			strcpy(errmsg, "主机:证件号码已存在");
			break;
		case	20106	:
			strcpy(errmsg, "主机:黑名单已存在");
			break;
		case	20107	:
			strcpy(errmsg, "主机:黑名单不存在");
			break;
		case	20108	:
			strcpy(errmsg, "主机:该户为黑名单户");
			break;
		case	20109	:
			strcpy(errmsg, "主机:两帐号的客户号相等");
			break;
		case	30001	:
			strcpy(errmsg, "主机:全行未开门");
			break;
		case	30002	:
			strcpy(errmsg, "主机:全行已开门");
			break;
		case	30003	:
			strcpy(errmsg, "主机:读全行表错");
			break;
		case	30004	:
			strcpy(errmsg, "主机:全行表出错");
			break;
		case	30101	:
			strcpy(errmsg, "主机:归属支行出错");
			break;
		case	30102	:
			strcpy(errmsg, "主机:无此支行号");
			break;
		case	30201	:
			strcpy(errmsg, "主机:无此部门");
			break;
		case	30202	:
			strcpy(errmsg, "主机:变更部门出错");
			break;
		case	30203	:
			strcpy(errmsg, "主机:部门级别错");
			break;
		case	30204	:
			strcpy(errmsg, "主机:部门状态错");
			break;
		case	30205	:
			strcpy(errmsg, "主机:部门无此权限");
			break;
		case	30206	:
			strcpy(errmsg, "主机:部门未关门");
			break;
		case	30207	:
			strcpy(errmsg, "主机:部门未开门");
			break;
		case	30208	:
			strcpy(errmsg, "主机:部门已开门");
			break;
		case	30209	:
			strcpy(errmsg, "主机:使用部门错");
			break;
		case	30210	:
			strcpy(errmsg, "主机:部门细目已生成");
			break;
		case	30211	:
			strcpy(errmsg, "主机:部门不允许开门");
			break;
		case	30212	:
			strcpy(errmsg, "主机:非开户部门不能修改");
			break;
		case	30213	:
			strcpy(errmsg, "主机:部门表出错");
			break;
		case	30214	:
			strcpy(errmsg, "主机:计息预提息表出错");
			break;
		case	30215	:
			strcpy(errmsg, "主机:计息预提息表没有满足条件的记录");
			break;
		case	30216	:
			strcpy(errmsg, "主机:部门不同");
			break;
		case	30217	:
			strcpy(errmsg, "主机:已有分户帐信息，无法变更关键属性");
			break;
		case	30218	:
			strcpy(errmsg, "主机:有下级部门，无法变更关键属性");
			break;
		case	30301	:
			strcpy(errmsg, "主机:今日应为假期不允许开门");
			break;
		case	30302	:
			strcpy(errmsg, "主机:无假日需处理");
			break;
		case	30401	:
			strcpy(errmsg, "主机:无此终端");
			break;
		case	30402	:
			strcpy(errmsg, "主机:此终端已使用");
			break;
		case	30403	:
			strcpy(errmsg, "主机:此终端不允许使用");
			break;
		case	30409	:
			strcpy(errmsg, "主机:该控制已存在");
			break;
		case	30501	:
			strcpy(errmsg, "主机:币种错");
			break;
		case	30502	:
			strcpy(errmsg, "主机:无此币种");
			break;
		case	30503	:
			strcpy(errmsg, "主机:币种不同");
			break;
		case	30504	:
			strcpy(errmsg, "主机:币种状态错");
			break;
		case	30505	:
			strcpy(errmsg, "主机:无货币牌价");
			break;
		case	30506	:
			strcpy(errmsg, "主机:输入币种不是人民币");
			break;
		case	30507	:
			strcpy(errmsg, "主机:不允许删除");
			break;
		case	30508	:
			strcpy(errmsg, "主机:欧元标志错");
			break;
		case	30509	:
			strcpy(errmsg, "主机:钞/汇标志与帐户不符");
			break;
		case	30601	:
			strcpy(errmsg, "主机:科目错");
			break;
		case	30602	:
			strcpy(errmsg, "主机:修改科目错");
			break;
		case	30603	:
			strcpy(errmsg, "主机:删除科目错");
			break;
		case	30604	:
			strcpy(errmsg, "主机:科目生成失败");
			break;
		case	30605	:
			strcpy(errmsg, "主机:科目已存在");
			break;
		case	30606	:
			strcpy(errmsg, "主机:科目不存在");
			break;
		case	30607	:
			strcpy(errmsg, "主机:科目总帐存在");
			break;
		case	30608	:
			strcpy(errmsg, "主机:无科目总帐");
			break;
		case	30609	:
			strcpy(errmsg, "主机:科目总帐错");
			break;
		case	30610	:
			strcpy(errmsg, "主机:科目级别非法");
			break;
		case	30611	:
			strcpy(errmsg, "主机:科目状态错");
			break;
		case	30612	:
			strcpy(errmsg, "主机:科目类型非法");
			break;
		case	30613	:
			strcpy(errmsg, "主机:变更归属科目出错");
			break;
		case	30614	:
			strcpy(errmsg, "主机:科目余额方向非法");
			break;
		case	30615	:
			strcpy(errmsg, "主机:科目发生额方向非法");
			break;
		case	30616	:
			strcpy(errmsg, "主机:取科目号利率编号失败");
			break;
		case	30617	:
			strcpy(errmsg, "主机:表内表外标志错");
			break;
		case	30618	:
			strcpy(errmsg, "主机:修改日总帐出错");
			break;
		case	30619	:
			strcpy(errmsg, "主机:修改月总帐出错");
			break;
		case	30620	:
			strcpy(errmsg, "主机:修改日会计帐户总帐出错");
			break;
		case	30621	:
			strcpy(errmsg, "主机:修改月会计帐户总帐出错");
			break;
		case	30622	:
			strcpy(errmsg, "主机:归属科目总帐未开");
			break;
		case	30623	:
			strcpy(errmsg, "主机:所属科目存在");
			break;
		case	30624	:
			strcpy(errmsg, "主机:内部帐号不能变更归属部门");
			break;
		case	30625	:
			strcpy(errmsg, "主机:科目相同");
			break;
		case	30626	:
			strcpy(errmsg, "主机:下辖科目总帐未销");
			break;
		case	30627	:
			strcpy(errmsg, "主机:归属科目总帐未恢复");
			break;
		case	30628	:
			strcpy(errmsg, "主机:修改年总帐出错");
			break;
		case	30629	:
			strcpy(errmsg, "主机:修改年会计帐户总帐出错");
			break;
		case	30701	:
			strcpy(errmsg, "主机:无此柜员");
			break;
		case	30702	:
			strcpy(errmsg, "主机:柜员无此权限");
			break;
		case	30703	:
			strcpy(errmsg, "主机:取柜员流水号出错");
			break;
		case	30704	:
			strcpy(errmsg, "主机:柜员未签到");
			break;
		case	30705	:
			strcpy(errmsg, "主机:柜员未签退");
			break;
		case	30706	:
			strcpy(errmsg, "主机:柜员已临时签退");
			break;
		case	30707	:
			strcpy(errmsg, "主机:柜员级别大于其部门级别");
			break;
		case	30708	:
			strcpy(errmsg, "主机:非全行管理员");
			break;
		case	30709	:
			strcpy(errmsg, "主机:非部门管理员");
			break;
		case	30710	:
			strcpy(errmsg, "主机:出纳员不在工作状态");
			break;
		case	30711	:
			strcpy(errmsg, "主机:帐务柜员无权做管理交易");
			break;
		case	30712	:
			strcpy(errmsg, "主机:管理柜员无权做帐务交易");
			break;
		case	30713	:
			strcpy(errmsg, "主机:非法的交易类别");
			break;
		case	30714	:
			strcpy(errmsg, "主机:非日间交易时间禁止签到!");
			break;
		case	30715	:
			strcpy(errmsg, "主机:系统在做日终或日始禁止签到!");
			break;
		case	30716	:
			strcpy(errmsg, "主机:系统目前状态不允许全行启动!");
			break;
		case	30717	:
			strcpy(errmsg, "主机:柜员属性不对!");
			break;
		case	30718	:
			strcpy(errmsg, "主机:分行级别的部门不能有支行级别的柜员");
			break;
		case	30719	:
			strcpy(errmsg, "主机:该柜员不允许在本前台签到");
			break;
		case	30751	:
			strcpy(errmsg, "主机:交易需要授权");
			break;
		case	30752	:
			strcpy(errmsg, "主机:授权柜员错");
			break;
		case	30753	:
			strcpy(errmsg, "主机:授权柜员密码错");
			break;
		case	30754	:
			strcpy(errmsg, "主机:授权失败");
			break;
		case	30755	:
			strcpy(errmsg, "主机:无此授权级别");
			break;
		case	30756	:
			strcpy(errmsg, "主机:无此授权级别的柜员");
			break;
		case	30757	:
			strcpy(errmsg, "主机:授权柜员级别不够");
			break;
		case	30758	:
			strcpy(errmsg, "主机:授权柜员与操作柜员为同一柜员");
			break;
		case	30759	:
			strcpy(errmsg, "主机:需要同一部门柜员授权");
			break;
		case	30760	:
			strcpy(errmsg, "主机:需要指定部门柜员授权");
			break;
		case	30761	:
			strcpy(errmsg, "主机:已记帐");
			break;
		case	30762	:
			strcpy(errmsg, "主机:未记帐");
			break;
		case	30763	:
			strcpy(errmsg, "主机:已复核");
			break;
		case	30764	:
			strcpy(errmsg, "主机:未复核");
			break;
		case	30765	:
			strcpy(errmsg, "主机:存在未复核交易");
			break;
		case	30771	:
			strcpy(errmsg, "主机:已监督");
			break;
		case	30772	:
			strcpy(errmsg, "主机:未监督");
			break;
		case	30773	:
			strcpy(errmsg, "主机:本批流水存在错误的监督标志");
			break;
		case	30774	:
			strcpy(errmsg, "主机:红蓝字标志错");
			break;
		case	30801	:
			strcpy(errmsg, "主机:记流水表错");
			break;
		case	30802	:
			strcpy(errmsg, "主机:无此交易流水");
			break;
		case	30803	:
			strcpy(errmsg, "主机:无批轧流水");
			break;
		case	30804	:
			strcpy(errmsg, "主机:无此起始流水号");
			break;
		case	30805	:
			strcpy(errmsg, "主机:无此终止流水号");
			break;
		case	30806	:
			strcpy(errmsg, "主机:取系统流水号错");
			break;
		case	30807	:
			strcpy(errmsg, "主机:登记系统流水表错");
			break;
		case	30808	:
			strcpy(errmsg, "主机:修改柜员凭证使用明细表错");
			break;
		case	30809	:
			strcpy(errmsg, "主机:提出票据交换场次不一致");
			break;
		case	30810	:
			strcpy(errmsg, "主机:存在已复核但未记帐会计流水");
			break;
		case	30811	:
			strcpy(errmsg, "主机:本批流水不存在需要监督的流水");
			break;
		case	30901	:
			strcpy(errmsg, "主机:编号错");
			break;
		case	30902	:
			strcpy(errmsg, "主机:编号表状态错");
			break;
		case	30903	:
			strcpy(errmsg, "主机:编号不同");
			break;
		case	30904	:
			strcpy(errmsg, "主机:编号值超界");
			break;
		case	30905	:
			strcpy(errmsg, "主机:业务编号不同");
			break;
		case	30906	:
			strcpy(errmsg, "主机:更新编号表错");
			break;
		case	30907	:
			strcpy(errmsg, "主机:代保管品编号不同");
			break;
		case	30908	:
			strcpy(errmsg, "主机:面函编号不同");
			break;
		case	30909	:
			strcpy(errmsg, "主机:无此联行行号");
			break;
		case	30910	:
			strcpy(errmsg, "主机:通知编号不存在");
			break;
		case	30911	:
			strcpy(errmsg, "主机:此联行行号非人行电子联行行号");
			break;
		case	31001	:
			strcpy(errmsg, "主机:无利率");
			break;
		case	31002	:
			strcpy(errmsg, "主机:取利率失败");
			break;
		case	31003	:
			strcpy(errmsg, "主机:取利率失败起息日过早");
			break;
		case	31004	:
			strcpy(errmsg, "主机:利率代码不同");
			break;
		case	31005	:
			strcpy(errmsg, "主机:固定利率值不同");
			break;
		case	31006	:
			strcpy(errmsg, "主机:浮动利率值不同");
			break;
		case	31007	:
			strcpy(errmsg, "主机:手续费比例不同");
			break;
		case	31008	:
			strcpy(errmsg, "主机:手续费率不同");
			break;
		case	31009	:
			strcpy(errmsg, "主机:计划还款次数不同");
			break;
		case	31010	:
			strcpy(errmsg, "主机:手续费已付");
			break;
		case	31011	:
			strcpy(errmsg, "主机:手续费未付");
			break;
		case	31012	:
			strcpy(errmsg, "主机:转存金额不同");
			break;
		case	31013	:
			strcpy(errmsg, "主机:汇拨金额不同");
			break;
		case	31014	:
			strcpy(errmsg, "主机:手续费计算错");
			break;
		case	31015	:
			strcpy(errmsg, "主机:前后台手续费不同");
			break;
		case	31101	:
			strcpy(errmsg, "主机:无需结息");
			break;
		case	31102	:
			strcpy(errmsg, "主机:分段计息");
			break;
		case	31103	:
			strcpy(errmsg, "主机:不能取息");
			break;
		case	31104	:
			strcpy(errmsg, "主机:计息方式不同");
			break;
		case	31105	:
			strcpy(errmsg, "主机:计息类型不同");
			break;
		case	31106	:
			strcpy(errmsg, "主机:本次取息日未到");
			break;
		case	31107	:
			strcpy(errmsg, "主机:续存日早于起息日");
			break;
		case	31108	:
			strcpy(errmsg, "主机:止息日应晚于起息日");
			break;
		case	31109	:
			strcpy(errmsg, "主机:需输入手工计息结果");
			break;
		case	31110	:
			strcpy(errmsg, "主机:利息金额不对");
			break;
		case	31111	:
			strcpy(errmsg, "主机:利息计算方法不对");
			break;
		case	31112	:
			strcpy(errmsg, "主机:计息日期不同");
			break;
		case	31113	:
			strcpy(errmsg, "主机:调整日期已计息");
			break;
		case	31151	:
			strcpy(errmsg, "主机:罚息代码不同");
			break;
		case	31152	:
			strcpy(errmsg, "主机:欠息金额错");
			break;
		case	31153	:
			strcpy(errmsg, "主机:欠息余额为0");
			break;
		case	31154	:
			strcpy(errmsg, "主机:欠息明细表追加失败");
			break;
		case	31155	:
			strcpy(errmsg, "主机:复息余额为0");
			break;
		case	31156	:
			strcpy(errmsg, "主机:欠息明细表更新失败");
			break;
		case	31157	:
			strcpy(errmsg, "主机:欠息还款明细表更新失败");
			break;
		case	31201	:
			strcpy(errmsg, "主机:发生额不符");
			break;
		case	31202	:
			strcpy(errmsg, "主机:卷别金额错");
			break;
		case	31203	:
			strcpy(errmsg, "主机:限额不存在");
			break;
		case	31204	:
			strcpy(errmsg, "主机:限额已存在");
			break;
		case	31205	:
			strcpy(errmsg, "主机:创建限额出错");
			break;
		case	31206	:
			strcpy(errmsg, "主机:取销限额出错");
			break;
		case	31207	:
			strcpy(errmsg, "主机:修改限额出错");
			break;
		case	31208	:
			strcpy(errmsg, "主机:取款金额应小于余额");
			break;
		case	31209	:
			strcpy(errmsg, "主机:签发金额小于起始金额");
			break;
		case	31210	:
			strcpy(errmsg, "主机:已超出本月起可存入的金额");
			break;
		case	31211	:
			strcpy(errmsg, "主机:发生额检查错");
			break;
		case	31301	:
			strcpy(errmsg, "主机:到期日不同");
			break;
		case	31302	:
			strcpy(errmsg, "主机:摘要不同");
			break;
		case	31303	:
			strcpy(errmsg, "主机:票据逾期");
			break;
		case	31304	:
			strcpy(errmsg, "主机:票据没有逾期");
			break;
		case	31401	:
			strcpy(errmsg, "主机:启动方式出错");
			break;
		case	31402	:
			strcpy(errmsg, "主机:批处理出错");
			break;
		case	31403	:
			strcpy(errmsg, "主机:批处理次序错误");
			break;
		case	31404	:
			strcpy(errmsg, "主机:现金帐未轧平");
			break;
		case	31405	:
			strcpy(errmsg, "主机:帐不平");
			break;
		case	31406	:
			strcpy(errmsg, "主机:全行运送中现金未轧平");
			break;
		case	31407	:
			strcpy(errmsg, "主机:现金库存与现金帐户余额不符");
			break;
		case	31408	:
			strcpy(errmsg, "主机:凭证库存与凭证帐户余额不符");
			break;
		case	31409	:
			strcpy(errmsg, "主机:应接收现金未收到");
			break;
		case	31410	:
			strcpy(errmsg, "主机:应接收凭证未收到");
			break;
		case	31411	:
			strcpy(errmsg, "主机:应接收有价单证未收到");
			break;
		case	31412	:
			strcpy(errmsg, "主机:有价单证库存与帐户余额不符");
			break;
		case	31413	:
			strcpy(errmsg, "主机:存在预销户余额不为零");
			break;
		case	31414	:
			strcpy(errmsg, "主机:应接收国债未收到");
			break;
		case	31415	:
			strcpy(errmsg, "主机:凭证出售库存与凭证1381帐户余额不符");
			break;
		case	31416	:
			strcpy(errmsg, "主机:5011与5081余额不平");
			break;
		case	31417	:
			strcpy(errmsg, "主机:5012与5082余额不平");
			break;
		case	32001	:
			strcpy(errmsg, "主机:凭证不合法");
			break;
		case	32002	:
			strcpy(errmsg, "主机:凭证号码不符");
			break;
		case	32003	:
			strcpy(errmsg, "主机:凭证种类不符");
			break;
		case	32004	:
			strcpy(errmsg, "主机:此凭证没有出售");
			break;
		case	32005	:
			strcpy(errmsg, "主机:凭证号有重复需要输入冠字号");
			break;
		case	32006	:
			strcpy(errmsg, "主机:凭证起始号，结束号与数量不等");
			break;
		case	32007	:
			strcpy(errmsg, "主机:表外凭证未轧平");
			break;
		case	32008	:
			strcpy(errmsg, "主机:查询凭证结束");
			break;
		case	32009	:
			strcpy(errmsg, "主机:凭证与库内记录冲突");
			break;
		case	32010	:
			strcpy(errmsg, "主机:该段凭证帐号不一致");
			break;
		case	32011	:
			strcpy(errmsg, "主机:需要凭证冠字号");
			break;
		case	32012	:
			strcpy(errmsg, "主机:该帐号无此凭证");
			break;
		case	32013	:
			strcpy(errmsg, "主机:操作柜员无此凭证");
			break;
		case	32014	:
			strcpy(errmsg, "主机:该凭证号未使用");
			break;
		case	32015	:
			strcpy(errmsg, "主机:有价单证非法");
			break;
		case	32016	:
			strcpy(errmsg, "主机:有价单证号码输入有误，请重试");
			break;
		case	32017	:
			strcpy(errmsg, "主机:该票据签发金额不正确");
			break;
		case	32018	:
			strcpy(errmsg, "主机:该票据已挂失");
			break;
		case	32019	:
			strcpy(errmsg, "主机:该票据编号不存在");
			break;
		case	32020	:
			strcpy(errmsg, "主机:该票据编号未使用");
			break;
		case	32021	:
			strcpy(errmsg, "主机:该票据已超过期限");
			break;
		case	32022	:
			strcpy(errmsg, "主机:票据金额不同");
			break;
		case	32023	:
			strcpy(errmsg, "主机:票据号码不同");
			break;
		case	32024	:
			strcpy(errmsg, "主机:票据种类不同");
			break;
		case	32025	:
			strcpy(errmsg, "主机:本存折并未挂失");
			break;
		case	32026	:
			strcpy(errmsg, "主机:请先补登存折");
			break;
		case	32027	:
			strcpy(errmsg, "主机:存单/存折号不符");
			break;
		case	32028	:
			strcpy(errmsg, "主机:该票据编号已使用");
			break;
		case	32029	:
			strcpy(errmsg, "主机:凭证号码有错");
			break;
		case	32030	:
			strcpy(errmsg, "主机:该帐号无此凭证号");
			break;
		case	32031	:
			strcpy(errmsg, "主机:该凭证未使用");
			break;
		case	32032	:
			strcpy(errmsg, "主机:该凭证状态错");
			break;
		case	32033	:
			strcpy(errmsg, "主机:该凭证类型错");
			break;
		case	32034	:
			strcpy(errmsg, "主机:凭证代码表前后台不一致");
			break;
		case	32035	:
			strcpy(errmsg, "主机:Errorinsertcert_certusedtl");
			break;
		case	32036	:
			strcpy(errmsg, "主机:凭证日期不符");
			break;
		case	32037	:
			strcpy(errmsg, "主机:凭证日期不符");
			break;
		case	32038	:
			strcpy(errmsg, "主机:是否异地商票不同");
			break;
		case	32039	:
			strcpy(errmsg, "主机:该票据必须输入对应帐号");
			break;
		case	32040	:
			strcpy(errmsg, "主机:票据业务复核后才能抹帐");
			break;
		case	32041	:
			strcpy(errmsg, "主机:汇票密押输入错");
			break;
		case	32042	:
			strcpy(errmsg, "主机:经办柜员不能复核自己交易");
			break;
		case	32043	:
			strcpy(errmsg, "主机:凭证的使用明细不存在或状态错");
			break;
		case	32044	:
			strcpy(errmsg, "主机:该凭证不控号");
			break;
		case	32045	:
			strcpy(errmsg, "主机:该票据种类不能补发");
			break;
		case	32046	:
			strcpy(errmsg, "主机:该凭证已入库过");
			break;
		case	40001	:
			strcpy(errmsg, "主机:分户帐错");
			break;
		case	40002	:
			strcpy(errmsg, "主机:帐号错");
			break;
		case	40003	:
			strcpy(errmsg, "主机:无此帐户");
			break;
		case	40004	:
			strcpy(errmsg, "主机:无此旧帐号");
			break;
		case	40005	:
			strcpy(errmsg, "主机:写分户帐出错");
			break;
		case	40006	:
			strcpy(errmsg, "主机:读帐号出错");
			break;
		case	40007	:
			strcpy(errmsg, "主机:该帐号已存在");
			break;
		case	40008	:
			strcpy(errmsg, "主机:存在符合条件的分户帐");
			break;
		case	40009	:
			strcpy(errmsg, "主机:帐号不存在");
			break;
		case	40010	:
			strcpy(errmsg, "主机:人行帐号错");
			break;
		case	40011	:
			strcpy(errmsg, "主机:拆借帐号错");
			break;
		case	40012	:
			strcpy(errmsg, "主机:保证金帐号错");
			break;
		case	40013	:
			strcpy(errmsg, "主机:投资帐号错");
			break;
		case	40014	:
			strcpy(errmsg, "主机:应计利息帐号错");
			break;
		case	40015	:
			strcpy(errmsg, "主机:其他应收款帐号错");
			break;
		case	40016	:
			strcpy(errmsg, "主机:对方帐号错");
			break;
		case	40017	:
			strcpy(errmsg, "主机:帐号1错");
			break;
		case	40018	:
			strcpy(errmsg, "主机:帐号2错");
			break;
		case	40019	:
			strcpy(errmsg, "主机:欠息卡片错");
			break;
		case	40101	:
			strcpy(errmsg, "主机:帐户已经销户");
			break;
		case	40102	:
			strcpy(errmsg, "主机:没有此销帐号");
			break;
		case	40103	:
			strcpy(errmsg, "主机:该帐户已销户请先取消销户");
			break;
		case	40104	:
			strcpy(errmsg, "主机:该客户号下有帐户未销户");
			break;
		case	40105	:
			strcpy(errmsg, "主机:帐户未冻结");
			break;
		case	40106	:
			strcpy(errmsg, "主机:该帐户部分冻结");
			break;
		case	40107	:
			strcpy(errmsg, "主机:该帐户全部冻结");
			break;
		case	40108	:
			strcpy(errmsg, "主机:帐户已经冻结");
			break;
		case	40109	:
			strcpy(errmsg, "主机:帐户已经暂封");
			break;
		case	40110	:
			strcpy(errmsg, "主机:帐户已到期");
			break;
		case	40111	:
			strcpy(errmsg, "主机:该帐户预销");
			break;
		case	40112	:
			strcpy(errmsg, "主机:帐户已经挂失");
			break;
		case	40113	:
			strcpy(errmsg, "主机:帐户未挂失");
			break;
		case	40114	:
			strcpy(errmsg, "主机:所输的原密码与帐户密码不一致");
			break;
		case	40115	:
			strcpy(errmsg, "主机:帐户性质非贷款户");
			break;
		case	40116	:
			strcpy(errmsg, "主机:帐户非现汇户");
			break;
		case	40117	:
			strcpy(errmsg, "主机:帐户性质错");
			break;
		case	40118	:
			strcpy(errmsg, "主机:帐户类型错");
			break;
		case	40119	:
			strcpy(errmsg, "主机:帐户状态错");
			break;
		case	40120	:
			strcpy(errmsg, "主机:该帐户不使用存折");
			break;
		case	40121	:
			strcpy(errmsg, "主机:帐户余额不足");
			break;
		case	40122	:
			strcpy(errmsg, "主机:无此结算户帐号");
			break;
		case	40123	:
			strcpy(errmsg, "主机:结算户已冻结");
			break;
		case	40124	:
			strcpy(errmsg, "主机:结算户帐户性质错误");
			break;
		case	40125	:
			strcpy(errmsg, "主机:结算户状态错误");
			break;
		case	40126	:
			strcpy(errmsg, "主机:结算户余额不足");
			break;
		case	40127	:
			strcpy(errmsg, "主机:结算户帐户类型不对");
			break;
		case	40128	:
			strcpy(errmsg, "主机:结算户帐号不同");
			break;
		case	40129	:
			strcpy(errmsg, "主机:结算户帐号与贷款卡片表收息帐号不同");
			break;
		case	40130	:
			strcpy(errmsg, "主机:结算户帐号与自动会计分录表中不同");
			break;
		case	40131	:
			strcpy(errmsg, "主机:内部帐户输入错");
			break;
		case	40132	:
			strcpy(errmsg, "主机:保证金帐号不同");
			break;
		case	40133	:
			strcpy(errmsg, "主机:中间帐号不同");
			break;
		case	40134	:
			strcpy(errmsg, "主机:收息帐号不同");
			break;
		case	40135	:
			strcpy(errmsg, "主机:取开户帐号顺序号表错");
			break;
		case	40136	:
			strcpy(errmsg, "主机:生成帐号错");
			break;
		case	40137	:
			strcpy(errmsg, "主机:该客户号已开贷款户");
			break;
		case	40138	:
			strcpy(errmsg, "主机:该户为协定户");
			break;
		case	40139	:
			strcpy(errmsg, "主机:该户对应贷款户未结清");
			break;
		case	40140	:
			strcpy(errmsg, "主机:该户透支不能销户");
			break;
		case	40141	:
			strcpy(errmsg, "主机:该户有未结清银行承兑汇票不能销户");
			break;
		case	40142	:
			strcpy(errmsg, "主机:该户有未结清托收承付票据不能销户");
			break;
		case	40143	:
			strcpy(errmsg, "主机:该户有未收妥交换票据不能销户");
			break;
		case	40144	:
			strcpy(errmsg, "主机:非活期基本户");
			break;
		case	40145	:
			strcpy(errmsg, "主机:协定存款记录已存在");
			break;
		case	40146	:
			strcpy(errmsg, "主机:协定存款记录不存在");
			break;
		case	40147	:
			strcpy(errmsg, "主机:查询条件为空");
			break;
		case	40148	:
			strcpy(errmsg, "主机:汇票明细表无此记录");
			break;
		case	40149	:
			strcpy(errmsg, "主机:承兑汇票明细表无此记录");
			break;
		case	40150	:
			strcpy(errmsg, "主机:本票明细表无此记录");
			break;
		case	40151	:
			strcpy(errmsg, "主机:支票明细表无此记录");
			break;
		case	40152	:
			strcpy(errmsg, "主机:挂失标志状态错");
			break;
		case	40153	:
			strcpy(errmsg, "主机:帐户余额小于冻结金额");
			break;
		case	40154	:
			strcpy(errmsg, "主机:生成冻结业务编号错");
			break;
		case	40155	:
			strcpy(errmsg, "主机:冻结登记簿无相应记录");
			break;
		case	40156	:
			strcpy(errmsg, "主机:冻结暂封标志状态错");
			break;
		case	40157	:
			strcpy(errmsg, "主机:同帐务性质帐号已存在");
			break;
		case	40158	:
			strcpy(errmsg, "主机:取网点交换号错");
			break;
		case	40162	:
			strcpy(errmsg, "主机:无此手续费帐号");
			break;
		case	40163	:
			strcpy(errmsg, "主机:手续费户状态错误");
			break;
		case	40164	:
			strcpy(errmsg, "主机:顺序号错");
			break;
		case	40165	:
			strcpy(errmsg, "主机:顺序号已存在");
			break;
		case	40166	:
			strcpy(errmsg, "主机:该户对应贷款户未结清");
			break;
		case	40167	:
			strcpy(errmsg, "主机:写新旧帐号对照表错");
			break;
		case	40168	:
			strcpy(errmsg, "主机:无此计息帐号");
			break;
		case	40169	:
			strcpy(errmsg, "主机:计息帐号状态错");
			break;
		case	40170	:
			strcpy(errmsg, "主机:计息帐号性质错");
			break;
		case	40171	:
			strcpy(errmsg, "主机:计息帐号客户号错");
			break;
		case	40172	:
			strcpy(errmsg, "主机:计息帐号币种错");
			break;
		case	40173	:
			strcpy(errmsg, "主机:无此付款帐号");
			break;
		case	40174	:
			strcpy(errmsg, "主机:无此收款帐号");
			break;
		case	40175	:
			strcpy(errmsg, "主机:分次付款总数超过原签发金额");
			break;
		case	40176	:
			strcpy(errmsg, "主机:分次付款次数错");
			break;
		case	40177	:
			strcpy(errmsg, "主机:承付类型错");
			break;
		case	40178	:
			strcpy(errmsg, "主机:修改托收分次付款明细表错");
			break;
		case	40179	:
			strcpy(errmsg, "主机:挂失申请书编号重复");
			break;
		case	40180	:
			strcpy(errmsg, "主机:汇票状态错");
			break;
		case	40181	:
			strcpy(errmsg, "主机:批顺序号错");
			break;
		case	40182	:
			strcpy(errmsg, "主机:存款户与贷款户客户号不符");
			break;
		case	40183	:
			strcpy(errmsg, "主机:该户有未结清银行汇票");
			break;
		case	40184	:
			strcpy(errmsg, "主机:该帐号下有未复核的交易");
			break;
		case	40201	:
			strcpy(errmsg, "主机:修改交换自动入帐登记表错");
			break;
		case	40202	:
			strcpy(errmsg, "主机:登记交换自动入帐登记表错");
			break;
		case	40203	:
			strcpy(errmsg, "主机:登记转帐交易流水表错");
			break;
		case	40204	:
			strcpy(errmsg, "主机:修改转帐交易流水表错");
			break;
		case	40205	:
			strcpy(errmsg, "主机:登记非帐务交易错");
			break;
		case	40206	:
			strcpy(errmsg, "主机:登记销帐记录错");
			break;
		case	40207	:
			strcpy(errmsg, "主机:修改销帐记录错");
			break;
		case	40208	:
			strcpy(errmsg, "主机:销帐金额错");
			break;
		case	40209	:
			strcpy(errmsg, "主机:修改卡片帐错");
			break;
		case	40210	:
			strcpy(errmsg, "主机:读卡片帐出错");
			break;
		case	40211	:
			strcpy(errmsg, "主机:登记卡片帐错");
			break;
		case	40212	:
			strcpy(errmsg, "主机:交易日早于卡片帐中上次交易日");
			break;
		case	40213	:
			strcpy(errmsg, "主机:冲补帐日早于交易日");
			break;
		case	40214	:
			strcpy(errmsg, "主机:销帐记录中帐号非法");
			break;
		case	40215	:
			strcpy(errmsg, "主机:销帐记录不存在");
			break;
		case	40219	:
			strcpy(errmsg, "主机:交换场次错");
			break;
		case	40220	:
			strcpy(errmsg, "主机:支票逾期");
			break;
		case	40221	:
			strcpy(errmsg, "主机:远期支票");
			break;
		case	40222	:
			strcpy(errmsg, "主机:交换场次状态设置错");
			break;
		case	40223	:
			strcpy(errmsg, "主机:对方不参加该场交换");
			break;
		case	40224	:
			strcpy(errmsg, "主机:已经提出处理的数据不能再修该");
			break;
		case	40225	:
			strcpy(errmsg, "主机:我方不参加该场交换");
			break;
		case	40226	:
			strcpy(errmsg, "主机:登记应收款项表错");
			break;
		case	40227	:
			strcpy(errmsg, "主机:登记应收应付登记表错");
			break;
		case	40228	:
			strcpy(errmsg, "主机:有应收款项没收");
			break;
		case	40301	:
			strcpy(errmsg, "主机:卡片状态错");
			break;
		case	40302	:
			strcpy(errmsg, "主机:卡片编号重复");
			break;
		case	40303	:
			strcpy(errmsg, "主机:卡片中没有满足条件的记录");
			break;
		case	40304	:
			strcpy(errmsg, "主机:该票据卡片已销号");
			break;
		case	40305	:
			strcpy(errmsg, "主机:到期日小于卡片到期日");
			break;
		case	40306	:
			strcpy(errmsg, "主机:该笔明细是欠息卡片");
			break;
		case	40307	:
			strcpy(errmsg, "主机:欠息卡片标志非1321");
			break;
		case	40308	:
			strcpy(errmsg, "主机:卡片余额不等于发生额");
			break;
		case	40309	:
			strcpy(errmsg, "主机:更新保证金表错");
			break;
		case	40310	:
			strcpy(errmsg, "主机:保证金卡片已销");
			break;
		case	40311	:
			strcpy(errmsg, "主机:保证金卡片不存在");
			break;
		case	40312	:
			strcpy(errmsg, "主机:投资类别错");
			break;
		case	40313	:
			strcpy(errmsg, "主机:核销笔数错");
			break;
		case	40314	:
			strcpy(errmsg, "主机:拆借类型错");
			break;
		case	40315	:
			strcpy(errmsg, "主机:非呆帐贷款");
			break;
		case	40316	:
			strcpy(errmsg, "主机:该笔非坏帐");
			break;
		case	40317	:
			strcpy(errmsg, "主机:欠息卡片不存在");
			break;
		case	40318	:
			strcpy(errmsg, "主机:不能全为销号帐号");
			break;
		case	40319	:
			strcpy(errmsg, "主机:该票据卡片已部分销");
			break;
		case	40320	:
			strcpy(errmsg, "主机:写拆借表错");
			break;
		case	40321	:
			strcpy(errmsg, "主机:写流水表错");
			break;
		case	40322	:
			strcpy(errmsg, "主机:读信贷信息表出错");
			break;
		case	40323	:
			strcpy(errmsg, "主机:拆借金额大于授信余额");
			break;
		case	40324	:
			strcpy(errmsg, "主机:合同号不符");
			break;
		case	40325	:
			strcpy(errmsg, "主机:交易对象帐号不符");
			break;
		case	40326	:
			strcpy(errmsg, "主机:金额不符");
			break;
		case	40327	:
			strcpy(errmsg, "主机:利率不符");
			break;
		case	40328	:
			strcpy(errmsg, "主机:到期日不符");
			break;
		case	40329	:
			strcpy(errmsg, "主机:人行帐号不符");
			break;
		case	40330	:
			strcpy(errmsg, "主机:统计编码不符");
			break;
		case	40331	:
			strcpy(errmsg, "主机:该笔交易已复核");
			break;
		case	40332	:
			strcpy(errmsg, "主机:写拆借还款明细表错");
			break;
		case	40333	:
			strcpy(errmsg, "主机:到期日不能为假日");
			break;
		case	40334	:
			strcpy(errmsg, "主机:申请编号不符");
			break;
		case	40335	:
			strcpy(errmsg, "主机:该笔业务未复核不能展期");
			break;
		case	40336	:
			strcpy(errmsg, "主机:起息日不符");
			break;
		case	40337	:
			strcpy(errmsg, "主机:利息不符");
			break;
		case	40338	:
			strcpy(errmsg, "主机:收报行行号不符");
			break;
		case	40339	:
			strcpy(errmsg, "主机:该笔业务已结清");
			break;
		case	40340	:
			strcpy(errmsg, "主机:该笔业务未复核不能还款");
			break;
		case	40341	:
			strcpy(errmsg, "主机:展期金额错");
			break;
		case	40342	:
			strcpy(errmsg, "主机:统计编码出错");
			break;
		case	40343	:
			strcpy(errmsg, "主机:更新授信余额错");
			break;
		case	40344	:
			strcpy(errmsg, "主机:该笔业务已还款不能展期");
			break;
		case	40345	:
			strcpy(errmsg, "主机:转出路线错");
			break;
		case	40346	:
			strcpy(errmsg, "主机:流水表中无记录");
			break;
		case	40347	:
			strcpy(errmsg, "主机:修改外币兑换流水表错");
			break;
		case	40348	:
			strcpy(errmsg, "主机:修改保证金明细表出错");
			break;
		case	40349	:
			strcpy(errmsg, "主机:登记保证金使用明细表出错");
			break;
		case	40350	:
			strcpy(errmsg, "主机:登记后台保证金交易流水表出错");
			break;
		case	40351	:
			strcpy(errmsg, "主机:修改投资明细表出错");
			break;
		case	40352	:
			strcpy(errmsg, "主机:登记投资使用明细表出错");
			break;
		case	40353	:
			strcpy(errmsg, "主机:登记后台投资交易流水表出错");
			break;
		case	40354	:
			strcpy(errmsg, "主机:修改同业往来交易流水表出错");
			break;
		case	40355	:
			strcpy(errmsg, "主机:删除拆借信息表错");
			break;
		case	40356	:
			strcpy(errmsg, "主机:经办员与复核员相同");
			break;
		case	40357	:
			strcpy(errmsg, "主机:同业帐号货币不符");
			break;
		case	40358	:
			strcpy(errmsg, "主机:该卡片已结清");
			break;
		case	40359	:
			strcpy(errmsg, "主机:该卡片已核销");
			break;
		case	40360	:
			strcpy(errmsg, "主机:同一笔拆借同一天不能还多次");
			break;
		case	40361	:
			strcpy(errmsg, "主机:保证金状态错");
			break;
		case	40362	:
			strcpy(errmsg, "主机:保证金额错");
			break;
		case	40363	:
			strcpy(errmsg, "主机:结算户客户号与保证金帐号客户号不同");
			break;
		case	40364	:
			strcpy(errmsg, "主机:付款金额加已付金额超原托收金额");
			break;
		case	40365	:
			strcpy(errmsg, "主机:此业务不能使用该笔保证金");
			break;
		case	40366	:
			strcpy(errmsg, "主机:该笔业务不存在");
			break;
		case	40367	:
			strcpy(errmsg, "主机:计提费用出错");
			break;
		case	40368	:
			strcpy(errmsg, "主机:计提税金出错");
			break;
		case	40369	:
			strcpy(errmsg, "主机:计提呆帐准备金出错");
			break;
		case	40370	:
			strcpy(errmsg, "主机:计提坏帐准备金出错");
			break;
		case	40371	:
			strcpy(errmsg, "主机:计提投资风险准备金出错");
			break;
		case	40372	:
			strcpy(errmsg, "主机:复息卡片状态错");
			break;
		case	40373	:
			strcpy(errmsg, "主机:对应欠息卡片状态错");
			break;
		case	40374	:
			strcpy(errmsg, "主机:复利卡片不存在");
			break;
		case	40375	:
			strcpy(errmsg, "主机:同一天只可以计提一次");
			break;
		case	40376	:
			strcpy(errmsg, "主机:拆借范围不符");
			break;
		case	40377	:
			strcpy(errmsg, "主机:年终决算交易顺序不对");
			break;
		case	40378	:
			strcpy(errmsg, "主机:置年终决算交易顺序出错");
			break;
		case	40379	:
			strcpy(errmsg, "主机:该笔保证金已使用不能抹帐");
			break;
		case	40380	:
			strcpy(errmsg, "主机:复利卡片生成错");
			break;
		case	40381	:
			strcpy(errmsg, "主机:该帐号是保证金计息帐号且保证金状态错");
			break;
		case	40401	:
			strcpy(errmsg, "主机:该户为长期不动户");
			break;
		case	40402	:
			strcpy(errmsg, "主机:该户被抵押贷款冻结");
			break;
		case	40403	:
			strcpy(errmsg, "主机:该户因其他原因冻结");
			break;
		case	40404	:
			strcpy(errmsg, "主机:存单只能销户");
			break;
		case	40405	:
			strcpy(errmsg, "主机:定期一本通销户交易不允许取消");
			break;
		case	40406	:
			strcpy(errmsg, "主机:存本取息已到期应作销户交易");
			break;
		case	40407	:
			strcpy(errmsg, "主机:此业务应在开户行办理");
			break;
		case	40408	:
			strcpy(errmsg, "主机:该户已经部份提前支取");
			break;
		case	40409	:
			strcpy(errmsg, "主机:查询开销户文件出错");
			break;
		case	40410	:
			strcpy(errmsg, "主机:该帐号没有预销计息");
			break;
		case	40411	:
			strcpy(errmsg, "主机:该帐号已预销计息");
			break;
		case	40412	:
			strcpy(errmsg, "主机:相关帐号已关闭");
			break;
		case	40413	:
			strcpy(errmsg, "主机:此业务需在经办行办理");
			break;
		case	40501	:
			strcpy(errmsg, "主机:汇票号码错");
			break;
		case	40502	:
			strcpy(errmsg, "主机:无此汇票承兑户帐号");
			break;
		case	40503	:
			strcpy(errmsg, "主机:汇票承兑户帐户已冻结");
			break;
		case	40504	:
			strcpy(errmsg, "主机:汇票承兑户帐户性质错");
			break;
		case	40505	:
			strcpy(errmsg, "主机:汇票承兑户帐户状态错");
			break;
		case	40506	:
			strcpy(errmsg, "主机:汇票承兑户帐户余额不足");
			break;
		case	40601	:
			strcpy(errmsg, "主机:积数核对不符");
			break;
		case	40602	:
			strcpy(errmsg, "主机:调整积数出错");
			break;
		case	40603	:
			strcpy(errmsg, "主机:调整积数反向");
			break;
		case	40604	:
			strcpy(errmsg, "主机:调整积数日期小于开户日");
			break;
		case	40701	:
			strcpy(errmsg, "主机:修改本票明细表错");
			break;
		case	40702	:
			strcpy(errmsg, "主机:登记本票明细表错");
			break;
		case	40703	:
			strcpy(errmsg, "主机:修改承兑汇票明细表错");
			break;
		case	40704	:
			strcpy(errmsg, "主机:登记承兑汇票明细表错");
			break;
		case	40705	:
			strcpy(errmsg, "主机:与已输入的汇票信息不符");
			break;
		case	40706	:
			strcpy(errmsg, "主机:修改汇票明细表错");
			break;
		case	40707	:
			strcpy(errmsg, "主机:登记汇票明细表错");
			break;
		case	40708	:
			strcpy(errmsg, "主机:修改交换交易流水表错");
			break;
		case	40709	:
			strcpy(errmsg, "主机:登记交换交易流水表错");
			break;
		case	40710	:
			strcpy(errmsg, "主机:修改交换登记表错");
			break;
		case	40711	:
			strcpy(errmsg, "主机:登记交换登记表错");
			break;
		case	40712	:
			strcpy(errmsg, "主机:修改托收承付流水表错");
			break;
		case	40713	:
			strcpy(errmsg, "主机:登记托收承付流水表错");
			break;
		case	40714	:
			strcpy(errmsg, "主机:修改托收承付明细表错");
			break;
		case	40715	:
			strcpy(errmsg, "主机:登记托收承付明细表错");
			break;
		case	40716	:
			strcpy(errmsg, "主机:修改支票明细表错");
			break;
		case	40717	:
			strcpy(errmsg, "主机:登记支票明细表错");
			break;
		case	40718	:
			strcpy(errmsg, "主机:凭证数量错");
			break;
		case	40719	:
			strcpy(errmsg, "主机:支票已启用");
			break;
		case	40720	:
			strcpy(errmsg, "主机:修改签票流水表错");
			break;
		case	40721	:
			strcpy(errmsg, "主机:登记签票流水表错");
			break;
		case	40722	:
			strcpy(errmsg, "主机:修改定期交易流水表错");
			break;
		case	40723	:
			strcpy(errmsg, "主机:登记定期交易流水表错");
			break;
		case	40724	:
			strcpy(errmsg, "主机:修改定期明细表错");
			break;
		case	40725	:
			strcpy(errmsg, "主机:登记定期明细表错");
			break;
		case	40726	:
			strcpy(errmsg, "主机:本定期存折未打满请输入旧存折号");
			break;
		case	40727	:
			strcpy(errmsg, "主机:本定期存折已打满请输入新存折号");
			break;
		case	40728	:
			strcpy(errmsg, "主机:登记前台交换交易流水表错");
			break;
		case	40729	:
			strcpy(errmsg, "主机:登记前台托收承付流水表错");
			break;
		case	40730	:
			strcpy(errmsg, "主机:登记前台签票流水表错");
			break;
		case	40731	:
			strcpy(errmsg, "主机:登记定期交易流水表错");
			break;
		case	40732	:
			strcpy(errmsg, "主机:登记定期明细表错");
			break;
		case	40733	:
			strcpy(errmsg, "主机:修改联行交易流水表错");
			break;
		case	40734	:
			strcpy(errmsg, "主机:登记联行交易流水表错");
			break;
		case	40735	:
			strcpy(errmsg, "主机:修改联行交易明细表错");
			break;
		case	40736	:
			strcpy(errmsg, "主机:登记联行交易明细表错");
			break;
		case	40737	:
			strcpy(errmsg, "主机:该户不是定期存款");
			break;
		case	40738	:
			strcpy(errmsg, "主机:该定期户已部提过");
			break;
		case	40739	:
			strcpy(errmsg, "主机:该定期户已结清过");
			break;
		case	40740	:
			strcpy(errmsg, "主机:该定期户末到期限，不能结清");
			break;
		case	40741	:
			strcpy(errmsg, "主机:该定期存单已挂失");
			break;
		case	40742	:
			strcpy(errmsg, "主机:该定期存单已冻结");
			break;
		case	40743	:
			strcpy(errmsg, "主机:该定期户已暂封");
			break;
		case	40744	:
			strcpy(errmsg, "主机:定期卡片金额与支取金额不符");
			break;
		case	40745	:
			strcpy(errmsg, "主机:该户不是定活两便存款户");
			break;
		case	40746	:
			strcpy(errmsg, "主机:支付方式错");
			break;
		case	40747	:
			strcpy(errmsg, "主机:通知支取日小于通知期限");
			break;
		case	40748	:
			strcpy(errmsg, "主机:取款金额累积大于通知存款金额");
			break;
		case	40749	:
			strcpy(errmsg, "主机:无对应的通知存款卡片");
			break;
		case	40750	:
			strcpy(errmsg, "主机:余额小于存款起始金额");
			break;
		case	40751	:
			strcpy(errmsg, "主机:取款金额应大于所有通知取款金额");
			break;
		case	40752	:
			strcpy(errmsg, "主机:定期机构类别选择错");
			break;
		case	40753	:
			strcpy(errmsg, "主机:定期期限错");
			break;
		case	40754	:
			strcpy(errmsg, "主机:该通知存款必须一次取清");
			break;
		case	40755	:
			strcpy(errmsg, "主机:该存款必须一次取清");
			break;
		case	40756	:
			strcpy(errmsg, "主机:该定期存单已质押");
			break;
		case	40757	:
			strcpy(errmsg, "主机:该定期通知户没有结清");
			break;
		case	40758	:
			strcpy(errmsg, "主机:该户对应定期通知户没有结清");
			break;
		case	40759	:
			strcpy(errmsg, "主机:该户有未结清本票");
			break;
		case	40760	:
			strcpy(errmsg, "主机:起息日小于上一次计提日");
			break;
		case	40761	:
			strcpy(errmsg, "主机:该定期存单没有质押");
			break;
		case	40801	:
			strcpy(errmsg, "主机:更新协定存款表错");
			break;
		case	40802	:
			strcpy(errmsg, "主机:更新定期存款表错");
			break;
		case	40803	:
			strcpy(errmsg, "主机:零整存款金额已超出");
			break;
		case	40804	:
			strcpy(errmsg, "主机:大额存入金额不对");
			break;
		case	40805	:
			strcpy(errmsg, "主机:已超过存期不可再续存");
			break;
		case	40806	:
			strcpy(errmsg, "主机:存本取息不得无折支取");
			break;
		case	40807	:
			strcpy(errmsg, "主机:存本取息的周期不应是0");
			break;
		case	40808	:
			strcpy(errmsg, "主机:存本取息未取到上次取息日");
			break;
		case	40809	:
			strcpy(errmsg, "主机:存本取息交易只允许冲正前一笔");
			break;
		case	41001	:
			strcpy(errmsg, "主机:外汇编号已注销");
			break;
		case	41002	:
			strcpy(errmsg, "主机:外汇编号不存在");
			break;
		case	41003	:
			strcpy(errmsg, "主机:取外汇编号错");
			break;
		case	41004	:
			strcpy(errmsg, "主机:外汇转出金额错");
			break;
		case	41005	:
			strcpy(errmsg, "主机:外汇业务代号错");
			break;
		case	41006	:
			strcpy(errmsg, "主机:外汇业务类型错");
			break;
		case	41007	:
			strcpy(errmsg, "主机:外汇登记卡状态错");
			break;
		case	41008	:
			strcpy(errmsg, "主机:登记外汇业务编号表错");
			break;
		case	41009	:
			strcpy(errmsg, "主机:登记外汇登记表错");
			break;
		case	41010	:
			strcpy(errmsg, "主机:信用证已撤销");
			break;
		case	41011	:
			strcpy(errmsg, "主机:信用证未撤销");
			break;
		case	41012	:
			strcpy(errmsg, "主机:非简电信用证");
			break;
		case	41013	:
			strcpy(errmsg, "主机:兑换错");
			break;
		case	41014	:
			strcpy(errmsg, "主机:后台计算金额错");
			break;
		case	41015	:
			strcpy(errmsg, "主机:后台计算金额与前台不等");
			break;
		case	41016	:
			strcpy(errmsg, "主机:付手续费帐号错");
			break;
		case	41017	:
			strcpy(errmsg, "主机:手续费帐号状态错");
			break;
		case	41018	:
			strcpy(errmsg, "主机:手续费帐号余额不足");
			break;
		case	41019	:
			strcpy(errmsg, "主机:出帐帐号错");
			break;
		case	41020	:
			strcpy(errmsg, "主机:出帐帐号状态错");
			break;
		case	41021	:
			strcpy(errmsg, "主机:出帐帐号支付数不足");
			break;
		case	41022	:
			strcpy(errmsg, "主机:收帐帐号错");
			break;
		case	41023	:
			strcpy(errmsg, "主机:收帐帐号状态错");
			break;
		case	41024	:
			strcpy(errmsg, "主机:出帐帐号货币不符");
			break;
		case	41025	:
			strcpy(errmsg, "主机:手续费帐号货币不符");
			break;
		case	41026	:
			strcpy(errmsg, "主机:收帐帐号货币不符");
			break;
		case	41027	:
			strcpy(errmsg, "主机:联行帐号货币错");
			break;
		case	41028	:
			strcpy(errmsg, "主机:外汇业务编号已存在");
			break;
		case	41029	:
			strcpy(errmsg, "主机:运保佣帐号错");
			break;
		case	41030	:
			strcpy(errmsg, "主机:运保佣帐号与币种不符");
			break;
		case	41031	:
			strcpy(errmsg, "主机:信用证已转让");
			break;
		case	41032	:
			strcpy(errmsg, "主机:原信用证通知编号错");
			break;
		case	41033	:
			strcpy(errmsg, "主机:读货币表错");
			break;
		case	41034	:
			strcpy(errmsg, "主机:该编号无效");
			break;
		case	41035	:
			strcpy(errmsg, "主机:该笔业务已退汇");
			break;
		case	41036	:
			strcpy(errmsg, "主机:该笔业务已退票(单)");
			break;
		case	41037	:
			strcpy(errmsg, "主机:该笔业务已收汇");
			break;
		case	41038	:
			strcpy(errmsg, "主机:该笔业务已全额转让");
			break;
		case	41039	:
			strcpy(errmsg, "主机:该笔业务已付汇");
			break;
		case	41040	:
			strcpy(errmsg, "主机:该笔业务已撤证");
			break;
		case	41041	:
			strcpy(errmsg, "主机:该笔业务未收汇");
			break;
		case	41042	:
			strcpy(errmsg, "主机:收费金额>单位入帐金额");
			break;
		case	41043	:
			strcpy(errmsg, "主机:收费金额>收汇金额");
			break;
		case	41044	:
			strcpy(errmsg, "主机:扣款金额>原金额");
			break;
		case	41045	:
			strcpy(errmsg, "主机:信用证已结束");
			break;
		case	41046	:
			strcpy(errmsg, "主机:汇款行业务编号重复");
			break;
		case	41047	:
			strcpy(errmsg, "主机:警报:汇入款可能重复录入");
			break;
		case	41048	:
			strcpy(errmsg, "主机:收款人姓名及地址不符");
			break;
		case	41049	:
			strcpy(errmsg, "主机:收款人身份及电话不符");
			break;
		case	41050	:
			strcpy(errmsg, "主机:出帐货币与收汇币种不符");
			break;
		case	41051	:
			strcpy(errmsg, "主机:托收收妥已解付");
			break;
		case	41052	:
			strcpy(errmsg, "主机:牌价表状态错");
			break;
		case	41053	:
			strcpy(errmsg, "主机:更新货币表错");
			break;
		case	41054	:
			strcpy(errmsg, "主机:欧元处理错");
			break;
		case	41055	:
			strcpy(errmsg, "主机:写兑换登记簿错");
			break;
		case	41056	:
			strcpy(errmsg, "主机:该笔业务已申报");
			break;
		case	41058	:
			strcpy(errmsg, "主机:该笔业务已部分转让");
			break;
		case	41059	:
			strcpy(errmsg, "主机:写兑换登记簿欧元处理错");
			break;
		case	41060	:
			strcpy(errmsg, "主机:出帐帐号已经销户");
			break;
		case	41061	:
			strcpy(errmsg, "主机:出帐帐号全部冻结");
			break;
		case	41062	:
			strcpy(errmsg, "主机:出帐帐号已预销");
			break;
		case	41063	:
			strcpy(errmsg, "主机:出帐帐号暂封");
			break;
		case	41064	:
			strcpy(errmsg, "主机:手续费帐号已经销户");
			break;
		case	41065	:
			strcpy(errmsg, "主机:手续费帐号全部冻结");
			break;
		case	41066	:
			strcpy(errmsg, "主机:手续费帐号已预销");
			break;
		case	41067	:
			strcpy(errmsg, "主机:手续费帐号暂封");
			break;
		case	41068	:
			strcpy(errmsg, "主机:收帐帐号已经销户");
			break;
		case	41069	:
			strcpy(errmsg, "主机:收帐帐号已预销");
			break;
		case	41070	:
			strcpy(errmsg, "主机:出帐帐号为定期帐号");
			break;
		case	41071	:
			strcpy(errmsg, "主机:出帐帐号为贷款帐号");
			break;
		case	41072	:
			strcpy(errmsg, "主机:手续费帐号为定期帐号");
			break;
		case	41073	:
			strcpy(errmsg, "主机:手续费帐号为贷款帐号");
			break;
		case	41074	:
			strcpy(errmsg, "主机:收帐帐号为定期帐号");
			break;
		case	41075	:
			strcpy(errmsg, "主机:收帐帐号为贷款帐号");
			break;
		case	41076	:
			strcpy(errmsg, "主机:收报部门网点号错");
			break;
		case	41077	:
			strcpy(errmsg, "主机:结/售汇已平盘");
			break;
		case	41078	:
			strcpy(errmsg, "主机:目前还没有作过结/售汇可稍后再平盘");
			break;
		case	41079	:
			strcpy(errmsg, "主机:读保证金使用明细表错");
			break;
		case	41080	:
			strcpy(errmsg, "主机:写保证金使用明细表错");
			break;
		case	41081	:
			strcpy(errmsg, "主机:读外汇交易流水表错");
			break;
		case	41082	:
			strcpy(errmsg, "主机:抹外汇交易流水表错");
			break;
		case	41083	:
			strcpy(errmsg, "主机:抹外汇登记簿错");
			break;
		case	41084	:
			strcpy(errmsg, "主机:面函已作结束处理");
			break;
		case	41085	:
			strcpy(errmsg, "主机:已作提货担保");
			break;
		case	41086	:
			strcpy(errmsg, "主机:汇入货币与卡片不符");
			break;
		case	41087	:
			strcpy(errmsg, "主机:取联行科目号错");
			break;
		case	41088	:
			strcpy(errmsg, "主机:该交易不能作欧元区货币钞套汇");
			break;
		case	41089	:
			strcpy(errmsg, "主机:更新结/售汇登记簿错");
			break;
		case	41090	:
			strcpy(errmsg, "主机:已作结/售汇平盘不能抹帐");
			break;
		case	41091	:
			strcpy(errmsg, "主机:已补汇不能抹帐");
			break;
		case	41092	:
			strcpy(errmsg, "主机:联行往帐已发送不能抹帐");
			break;
		case	41093	:
			strcpy(errmsg, "主机:抹帐顺序错请先抹派生业务");
			break;
		case	41094	:
			strcpy(errmsg, "主机:联行来帐预处理柜员分配有误");
			break;
		case	41095	:
			strcpy(errmsg, "主机:柜员未分配经办此笔交易");
			break;
		case	41096	:
			strcpy(errmsg, "主机:交易流水已存在");
			break;
		case	41097	:
			strcpy(errmsg, "主机:取帐务中心部门号错");
			break;
		case	41098	:
			strcpy(errmsg, "主机:有汇票需复核后抹帐");
			break;
		case	42001	:
			strcpy(errmsg, "主机:无此贷款户帐号");
			break;
		case	42002	:
			strcpy(errmsg, "主机:贷款户状态错");
			break;
		case	42003	:
			strcpy(errmsg, "主机:贷款户帐户性质错误");
			break;
		case	42004	:
			strcpy(errmsg, "主机:无此贷款");
			break;
		case	42005	:
			strcpy(errmsg, "主机:贷款编号错");
			break;
		case	42006	:
			strcpy(errmsg, "主机:贷款状态错");
			break;
		case	42007	:
			strcpy(errmsg, "主机:贷款类别错");
			break;
		case	42008	:
			strcpy(errmsg, "主机:贷款种类错");
			break;
		case	42009	:
			strcpy(errmsg, "主机:贷款金额不同");
			break;
		case	42010	:
			strcpy(errmsg, "主机:贷款性质不同");
			break;
		case	42011	:
			strcpy(errmsg, "主机:贷款方式不同");
			break;
		case	42012	:
			strcpy(errmsg, "主机:贷款投向不同");
			break;
		case	42013	:
			strcpy(errmsg, "主机:贷款发生额不同");
			break;
		case	42014	:
			strcpy(errmsg, "主机:贷款到期日不同");
			break;
		case	42015	:
			strcpy(errmsg, "主机:贷款发生日不同");
			break;
		case	42016	:
			strcpy(errmsg, "主机:贷款卡片已结清");
			break;
		case	42017	:
			strcpy(errmsg, "主机:发生日期大于贷款到期日");
			break;
		case	42018	:
			strcpy(errmsg, "主机:发生日期小于贷款起始日期");
			break;
		case	42019	:
			strcpy(errmsg, "主机:追加信贷信息表失败");
			break;
		case	42020	:
			strcpy(errmsg, "主机:信用证号不同");
			break;
		case	42021	:
			strcpy(errmsg, "主机:贷款发生额错");
			break;
		case	42022	:
			strcpy(errmsg, "主机:手续费未付");
			break;
		case	42023	:
			strcpy(errmsg, "主机:贷款户帐户类型不对");
			break;
		case	42024	:
			strcpy(errmsg, "主机:结算户暂封");
			break;
		case	42025	:
			strcpy(errmsg, "主机:手续户暂封");
			break;
		case	42026	:
			strcpy(errmsg, "主机:委贷资金户暂封");
			break;
		case	42027	:
			strcpy(errmsg, "主机:保证金户暂封");
			break;
		case	42028	:
			strcpy(errmsg, "主机:手续费户冻结");
			break;
		case	42029	:
			strcpy(errmsg, "主机:信贷信息表错误");
			break;
		case	42030	:
			strcpy(errmsg, "主机:尚未到期");
			break;
		case	42031	:
			strcpy(errmsg, "主机:表中已有相同记录请用查询修改交易进行修改");
			break;
		case	42032	:
			strcpy(errmsg, "主机:是否修改利率错");
			break;
		case	42033	:
			strcpy(errmsg, "主机:展期固定利率错");
			break;
		case	42034	:
			strcpy(errmsg, "主机:展期利率浮动值错");
			break;
		case	42035	:
			strcpy(errmsg, "主机:展期到期日错");
			break;
		case	42036	:
			strcpy(errmsg, "主机:汇票承兑帐号错");
			break;
		case	42037	:
			strcpy(errmsg, "主机:会计帐户不同");
			break;
		case	42038	:
			strcpy(errmsg, "主机:成员行数不同");
			break;
		case	42039	:
			strcpy(errmsg, "主机:批准规模不同");
			break;
		case	42040	:
			strcpy(errmsg, "主机:批准资金不同");
			break;
		case	42041	:
			strcpy(errmsg, "主机:资金帐号不同");
			break;
		case	42042	:
			strcpy(errmsg, "主机:合同日期不同");
			break;
		case	42043	:
			strcpy(errmsg, "主机:利率浮动标志不同");
			break;
		case	42044	:
			strcpy(errmsg, "主机:月再转贴现率不同");
			break;
		case	42045	:
			strcpy(errmsg, "主机:该贷款户没有结清");
			break;
		case	42101	:
			strcpy(errmsg, "主机:委托贷款帐号输入错");
			break;
		case	42102	:
			strcpy(errmsg, "主机:委贷资金帐户状态错");
			break;
		case	42103	:
			strcpy(errmsg, "主机:委贷资金帐户类型错");
			break;
		case	42104	:
			strcpy(errmsg, "主机:委贷资金帐户性质错");
			break;
		case	42105	:
			strcpy(errmsg, "主机:委贷保证金帐户类型错");
			break;
		case	42106	:
			strcpy(errmsg, "主机:委贷保证金帐户性质错");
			break;
		case	42107	:
			strcpy(errmsg, "主机:无此委贷资金户帐号");
			break;
		case	42108	:
			strcpy(errmsg, "主机:无此委贷保证户帐号");
			break;
		case	42109	:
			strcpy(errmsg, "主机:委贷资金户已冻结");
			break;
		case	42110	:
			strcpy(errmsg, "主机:委贷保证金户已冻结");
			break;
		case	42111	:
			strcpy(errmsg, "主机:委贷资金户余额不足");
			break;
		case	42112	:
			strcpy(errmsg, "主机:保证金户余额不足");
			break;
		case	42113	:
			strcpy(errmsg, "主机:委贷保证金户状态错");
			break;
		case	42114	:
			strcpy(errmsg, "主机:委贷资金户不同");
			break;
		case	42115	:
			strcpy(errmsg, "主机:外区标志错");
			break;
		case	42116	:
			strcpy(errmsg, "主机:外区帐号错");
			break;
		case	42201	:
			strcpy(errmsg, "主机:还款金额错");
			break;
		case	42202	:
			strcpy(errmsg, "主机:还款金额小于借款金额");
			break;
		case	42203	:
			strcpy(errmsg, "主机:还款金额大于借款金额");
			break;
		case	42204	:
			strcpy(errmsg, "主机:还息金额大于复息金额");
			break;
		case	42205	:
			strcpy(errmsg, "主机:还息金额大于欠息金额");
			break;
		case	42206	:
			strcpy(errmsg, "主机:还款计划输入错");
			break;
		case	42207	:
			strcpy(errmsg, "主机:还款次数不同");
			break;
		case	42208	:
			strcpy(errmsg, "主机:无此贴现");
			break;
		case	42209	:
			strcpy(errmsg, "主机:贴现类别错");
			break;
		case	42210	:
			strcpy(errmsg, "主机:贴现状态错");
			break;
		case	42211	:
			strcpy(errmsg, "主机:贴现种类错");
			break;
		case	42212	:
			strcpy(errmsg, "主机:合同号错");
			break;
		case	42213	:
			strcpy(errmsg, "主机:合同号不同");
			break;
		case	42301	:
			strcpy(errmsg, "主机:托收费金额不同");
			break;
		case	42302	:
			strcpy(errmsg, "主机:无兑换手续费金额不同");
			break;
		case	42303	:
			strcpy(errmsg, "主机:修改费金额不同");
			break;
		case	42304	:
			strcpy(errmsg, "主机:预收国外银行扣费不对");
			break;
		case	42305	:
			strcpy(errmsg, "主机:邮费快递费金额不同");
			break;
		case	42306	:
			strcpy(errmsg, "主机:电报费金额不同");
			break;
		case	42307	:
			strcpy(errmsg, "主机:押汇息金额不同");
			break;
		case	42308	:
			strcpy(errmsg, "主机:电报费代码不同");
			break;
		case	42309	:
			strcpy(errmsg, "主机:邮费代码不同");
			break;
		case	42310	:
			strcpy(errmsg, "主机:付手续费帐号不同");
			break;
		case	42311	:
			strcpy(errmsg, "主机:手续费率不同");
			break;
		case	42312	:
			strcpy(errmsg, "主机:还款计划错");
			break;
		case	42313	:
			strcpy(errmsg, "主机:没有满足条件的还款计划");
			break;
		case	42314	:
			strcpy(errmsg, "主机:还款卡片状态错");
			break;
		case	42315	:
			strcpy(errmsg, "主机:结算户金额小于零");
			break;
		case	42316	:
			strcpy(errmsg, "主机:帐户余额等于零");
			break;
		case	42320	:
			strcpy(errmsg, "主机:罚息率不同");
			break;
		case	42321	:
			strcpy(errmsg, "主机:还款明细追加错");
			break;
		case	42322	:
			strcpy(errmsg, "主机:帐户余额不等于零");
			break;
		case	42323	:
			strcpy(errmsg, "主机:营业税率不同");
			break;
		case	42324	:
			strcpy(errmsg, "主机:内部帐户余额不等于零不能销户");
			break;
		case	43001	:
			strcpy(errmsg, "主机:票据承兑日期未到");
			break;
		case	43002	:
			strcpy(errmsg, "主机:已过票据兑付日期");
			break;
		case	43003	:
			strcpy(errmsg, "主机:票据签发日期不符");
			break;
		case	43004	:
			strcpy(errmsg, "主机:票据已经结清");
			break;
		case	43005	:
			strcpy(errmsg, "主机:票据未用退回");
			break;
		case	43006	:
			strcpy(errmsg, "主机:计算邮电费出错");
			break;
		case	43007	:
			strcpy(errmsg, "主机:计算手续费出错");
			break;
		case	43008	:
			strcpy(errmsg, "主机:交换登记表无此记录");
			break;
		case	43009	:
			strcpy(errmsg, "主机:付款人帐号不符");
			break;
		case	43010	:
			strcpy(errmsg, "主机:原付款人帐号不符");
			break;
		case	43011	:
			strcpy(errmsg, "主机:交换自动入帐登记表无此记录");
			break;
		case	43012	:
			strcpy(errmsg, "主机:票据金额大于贴现金额");
			break;
		case	43013	:
			strcpy(errmsg, "主机:交换交易流水表无此记录");
			break;
		case	43014	:
			strcpy(errmsg, "主机:无此记录");
			break;
		case	43015	:
			strcpy(errmsg, "主机:金额不一致");
			break;
		case	43016	:
			strcpy(errmsg, "主机:委托收款已注销");
			break;
		case	43017	:
			strcpy(errmsg, "主机:收款人帐号错");
			break;
		case	43018	:
			strcpy(errmsg, "主机:收款人户名错");
			break;
		case	43019	:
			strcpy(errmsg, "主机:收款金额错");
			break;
		case	43020	:
			strcpy(errmsg, "主机:委托收款已拒付");
			break;
		case	43021	:
			strcpy(errmsg, "主机:委托收款已结清");
			break;
		case	43022	:
			strcpy(errmsg, "主机:帐号币种不一致");
			break;
		case	43023	:
			strcpy(errmsg, "主机:修改联行往来登记表错");
			break;
		case	43024	:
			strcpy(errmsg, "主机:该笔流水已经抹帐");
			break;
		case	43025	:
			strcpy(errmsg, "主机:该笔流水已经删除");
			break;
		case	43026	:
			strcpy(errmsg, "主机:该笔流水记帐未复核");
			break;
		case	43027	:
			strcpy(errmsg, "主机:非系统内汇票");
			break;
		case	43028	:
			strcpy(errmsg, "主机:非系统外汇票");
			break;
		case	43029	:
			strcpy(errmsg, "主机:累计金额超过记帐金额");
			break;
		case	43030	:
			strcpy(errmsg, "主机:入帐结束不能再做退票");
			break;
		case	43031	:
			strcpy(errmsg, "主机:录入没有完成");
			break;
		case	43032	:
			strcpy(errmsg, "主机:复核没有完成");
			break;
		case	43033	:
			strcpy(errmsg, "主机:人行资金结算已经结束");
			break;
		case	43034	:
			strcpy(errmsg, "主机:盈余金额方向不一致");
			break;
		case	43035	:
			strcpy(errmsg, "主机:盈余金额不一致");
			break;
		case	43036	:
			strcpy(errmsg, "主机:批量入帐已经结束");
			break;
		case	43037	:
			strcpy(errmsg, "主机:帐号不能为表外帐号");
			break;
		case	43038	:
			strcpy(errmsg, "主机:有退票未复核");
			break;
		case	43039	:
			strcpy(errmsg, "主机:帐号不归属于该交换号");
			break;
		case	43040	:
			strcpy(errmsg, "主机:记录重复");
			break;
		case	43041	:
			strcpy(errmsg, "主机:存在已记帐未复核的交易流水");
			break;
		case	43042	:
			strcpy(errmsg, "主机:部门不归属于该交换号");
			break;
		case	43043	:
			strcpy(errmsg, "主机:托收部门与记帐部门不一致");
			break;
		case	43044	:
			strcpy(errmsg, "主机:帐号必须为表外帐");
			break;
		case	43045	:
			strcpy(errmsg, "主机:必须先做收妥入帐");
			break;
		case	43046	:
			strcpy(errmsg, "主机:联行往帐已发出不能抹帐");
			break;
		case	43047	:
			strcpy(errmsg, "主机:人行资金结算已经结束");
			break;
		case	43048	:
			strcpy(errmsg, "主机:托收种类不符");
			break;
		case	43049	:
			strcpy(errmsg, "主机:卡片状态错");
			break;
		case	43050	:
			strcpy(errmsg, "主机:已收妥入帐");
			break;
		case	43051	:
			strcpy(errmsg, "主机:专用章编号不存在");
			break;
		case	43052	:
			strcpy(errmsg, "主机:专用章编号不符");
			break;
		case	43053	:
			strcpy(errmsg, "主机:此联行行号非人民币行号");
			break;
		case	50001	:
			strcpy(errmsg, "主机:读分户帐错");
			break;
		case	50002	:
			strcpy(errmsg, "主机:会计流水预检查出错");
			break;
		case	50003	:
			strcpy(errmsg, "主机:余额反向");
			break;
		case	50004	:
			strcpy(errmsg, "主机:贷款余额非法");
			break;
		case	50005	:
			strcpy(errmsg, "主机:拆借余额非法");
			break;
		case	50006	:
			strcpy(errmsg, "主机:会计帐户横向不平");
			break;
		case	50007	:
			strcpy(errmsg, "主机:会计科目横向不平");
			break;
		case	50008	:
			strcpy(errmsg, "主机:取分录错");
			break;
		case	50009	:
			strcpy(errmsg, "主机:保证与被保证帐号或编号不符");
			break;
		case	50010	:
			strcpy(errmsg, "主机:判可支付错");
			break;
		case	50011	:
			strcpy(errmsg, "主机:1321标志错");
			break;
		case	50012	:
			strcpy(errmsg, "主机:扎帐不平");
			break;
		case	50013	:
			strcpy(errmsg, "主机:项目代码重复");
			break;
		case	50014	:
			strcpy(errmsg, "主机:打印行号重复");
			break;
		case	50015	:
			strcpy(errmsg, "主机:当前没有记录");
			break;
		case	50016	:
			strcpy(errmsg, "主机:读会计牌价错");
			break;
		case	50017	:
			strcpy(errmsg, "主机:今日非月底");
			break;
		case	50018	:
			strcpy(errmsg, "主机:今日非年底");
			break;
		case	50019	:
			strcpy(errmsg, "主机:当前状态为日间开始不能做");
			break;
		case	50020	:
			strcpy(errmsg, "主机:当前状态为日间结束不能做");
			break;
		case	50021	:
			strcpy(errmsg, "主机:当前状态为日终切换不能做");
			break;
		case	50022	:
			strcpy(errmsg, "主机:当前状态为日终开始不能做");
			break;
		case	50023	:
			strcpy(errmsg, "主机:当前状态为日终结束不能做");
			break;
		case	50024	:
			strcpy(errmsg, "主机:当前状态为日始开始不能做");
			break;
		case	50025	:
			strcpy(errmsg, "主机:当前状态为日始结束不能做");
			break;
		case	50026	:
			strcpy(errmsg, "主机:公共记帐错");
			break;
		case	50027	:
			strcpy(errmsg, "主机:取会计帐户错");
			break;
		case	50028	:
			strcpy(errmsg, "主机:过帐借贷方累计发生额不等");
			break;
		case	50029	:
			strcpy(errmsg, "主机:假期内不同计息天数大于1");
			break;
		case	50030	:
			strcpy(errmsg, "主机:假期内既计息又跨月");
			break;
		case	50031	:
			strcpy(errmsg, "主机:有帐务错误请打印批处理错误信息(050301)!");
			break;
		case	50032	:
			strcpy(errmsg, "主机:存储过程调用错!");
			break;
		case	50033	:
			strcpy(errmsg, "主机:利率浮动标志错!");
			break;
		case	50034	:
			strcpy(errmsg, "主机:积数反向!");
			break;
		case	50035	:
			strcpy(errmsg, "主机:今日非计息日!");
			break;
		case	50036	:
			strcpy(errmsg, "主机:取币种最小记帐单位错!");
			break;
		case	50037	:
			strcpy(errmsg, "主机:利息金额非法!");
			break;
		case	50038	:
			strcpy(errmsg, "主机:读调整积数错!");
			break;
		case	50039	:
			strcpy(errmsg, "主机:备份出错!");
			break;
		case	50040	:
			strcpy(errmsg, "主机:恢复出错!");
			break;
		case	50041	:
			strcpy(errmsg, "主机:调减总帐积数错!");
			break;
		case	50042	:
			strcpy(errmsg, "主机:取上次计息日期错!");
			break;
		case	50043	:
			strcpy(errmsg, "主机:今日非旬末!");
			break;
		case	50044	:
			strcpy(errmsg, "主机:损益表生成错");
			break;
		case	50045	:
			strcpy(errmsg, "主机:批处理不能在事务中进行");
			break;
		case	50046	:
			strcpy(errmsg, "主机:资产负债表生成错");
			break;
		case	50047	:
			strcpy(errmsg, "主机:请先删除数据来源表中该项");
			break;
		case	50048	:
			strcpy(errmsg, "主机:内部帐户贷方积数不为零不能销户");
			break;
		case	50049	:
			strcpy(errmsg, "主机:内部帐户借方积数不为零不能销户");
			break;
		case	130001	:
			strcpy(errmsg, "主机:库存中01完整券数量不符");
			break;
		case	130002	:
			strcpy(errmsg, "主机:库存中02完整券数量不符");
			break;
		case	130003	:
			strcpy(errmsg, "主机:库存中03完整券数量不符");
			break;
		case	130004	:
			strcpy(errmsg, "主机:库存中04完整券数量不符");
			break;
		case	130005	:
			strcpy(errmsg, "主机:库存中05完整券数量不符");
			break;
		case	130006	:
			strcpy(errmsg, "主机:库存中06完整券数量不符");
			break;
		case	130007	:
			strcpy(errmsg, "主机:库存中07完整券数量不符");
			break;
		case	130008	:
			strcpy(errmsg, "主机:库存中08完整券数量不符");
			break;
		case	130009	:
			strcpy(errmsg, "主机:库存中09完整券数量不符");
			break;
		case	130010	:
			strcpy(errmsg, "主机:库存中10完整券数量不符");
			break;
		case	130011	:
			strcpy(errmsg, "主机:库存中11完整券数量不符");
			break;
		case	130012	:
			strcpy(errmsg, "主机:库存中12完整券数量不符");
			break;
		case	130013	:
			strcpy(errmsg, "主机:库存中13完整券数量不符");
			break;
		case	130014	:
			strcpy(errmsg, "主机:库存中14完整券数量不符");
			break;
		case	130015	:
			strcpy(errmsg, "主机:库存中15完整券数量不符");
			break;
		case	130016	:
			strcpy(errmsg, "主机:库存中16完整券数量不符");
			break;
		case	130017	:
			strcpy(errmsg, "主机:库存中17完整券数量不符");
			break;
		case	130018	:
			strcpy(errmsg, "主机:库存中18完整券数量不符");
			break;
		case	130019	:
			strcpy(errmsg, "主机:库存中19完整券数量不符");
			break;
		case	130020	:
			strcpy(errmsg, "主机:库存中20完整券数量不符");
			break;
		case	130021	:
			strcpy(errmsg, "主机:不允许操作员号=9999");
			break;
		case	130022	:
			strcpy(errmsg, "主机:库存表中无满足条件记录");
			break;
		case	130023	:
			strcpy(errmsg, "主机:库存表记录无效");
			break;
		case	130024	:
			strcpy(errmsg, "主机:库存余额不足");
			break;
		case	130025	:
			strcpy(errmsg, "主机:更新库存表余额记录错");
			break;
		case	130027	:
			strcpy(errmsg, "主机:更新库存表入库记录错");
			break;
		case	130029	:
			strcpy(errmsg, "主机:更新库存表出库记录错");
			break;
		case	130031	:
			strcpy(errmsg, "主机:写现金登记簿错");
			break;
		case	130032	:
			strcpy(errmsg, "主机:写现金流水表错");
			break;
		case	130033	:
			strcpy(errmsg, "主机:现金登记簿中无满足条件记录");
			break;
		case	130034	:
			strcpy(errmsg, "主机:此笔交易已复核");
			break;
		case	130035	:
			strcpy(errmsg, "主机:币种不符");
			break;
		case	130036	:
			strcpy(errmsg, "主机:金额不符");
			break;
		case	130037	:
			strcpy(errmsg, "主机:接收方操作员不符");
			break;
		case	130038	:
			strcpy(errmsg, "主机:更新现金登记簿错");
			break;
		case	130041	:
			strcpy(errmsg, "主机:更新现金库存表错");
			break;
		case	130042	:
			strcpy(errmsg, "主机:运送现金登记簿中无满足条件记录");
			break;
		case	130043	:
			strcpy(errmsg, "主机:更新运送现金登记簿错");
			break;
		case	130044	:
			strcpy(errmsg, "主机:写运送现金登记簿错");
			break;
		case	130046	:
			strcpy(errmsg, "主机:库房类型不符");
			break;
		case	130049	:
			strcpy(errmsg, "主机:分户帐表错");
			break;
		case	130050	:
			strcpy(errmsg, "主机:分户帐表中无满足条件记录");
			break;
		case	130051	:
			strcpy(errmsg, "主机:帐号的状态错");
			break;
		case	130052	:
			strcpy(errmsg, "主机:帐号的性质错");
			break;
		case	130053	:
			strcpy(errmsg, "主机:客户的状态错");
			break;
		case	130054	:
			strcpy(errmsg, "主机:调用客户检查函数错");
			break;
		case	130055	:
			strcpy(errmsg, "主机:调取会计分录函数错");
			break;
		case	130056	:
			strcpy(errmsg, "主机:前后台暂收账号不一致");
			break;
		case	130057	:
			strcpy(errmsg, "主机:调取公共会计记帐函数错");
			break;
		case	130058	:
			strcpy(errmsg, "主机:前后台汇率计算不一致");
			break;
		case	130059	:
			strcpy(errmsg, "主机:调取兑换函数错");
			break;
		case	130060	:
			strcpy(errmsg, "主机:国债利息表错");
			break;
		case	130061	:
			strcpy(errmsg, "主机:国债利息表中无此国债品种?");
			break;
		case	130062	:
			strcpy(errmsg, "主机:前后台国债利息计算不一致");
			break;
		case	130063	:
			strcpy(errmsg, "主机:编号表错");
			break;
		case	130064	:
			strcpy(errmsg, "主机:编号表中无此编号");
			break;
		case	130065	:
			strcpy(errmsg, "主机:编号表中该记录的状态错");
			break;
		case	130066	:
			strcpy(errmsg, "主机:此笔交易已抹帐");
			break;
		case	130067	:
			strcpy(errmsg, "主机:此笔交易流水不存在");
			break;
		case	130068	:
			strcpy(errmsg, "主机:不允许输入资产类帐号");
			break;
		case	130070	:
			strcpy(errmsg, "主机:写假币代保管品表错");
			break;
		case	130071	:
			strcpy(errmsg, "主机:写假币代保管品流水表错");
			break;
		case	130072	:
			strcpy(errmsg, "主机:该假币编号已抹帐");
			break;
		case	130073	:
			strcpy(errmsg, "主机:该假币编号已上缴");
			break;
		case	130088	:
			strcpy(errmsg, "主机:完整残损标志不符");
			break;
		case	130101	:
			strcpy(errmsg, "主机:库存中01残损券数量不符");
			break;
		case	130102	:
			strcpy(errmsg, "主机:库存中02残损券数量不符");
			break;
		case	130103	:
			strcpy(errmsg, "主机:库存中03残损券数量不符");
			break;
		case	130104	:
			strcpy(errmsg, "主机:库存中04残损券数量不符");
			break;
		case	130105	:
			strcpy(errmsg, "主机:库存中05残损券数量不符");
			break;
		case	130106	:
			strcpy(errmsg, "主机:库存中06残损券数量不符");
			break;
		case	130107	:
			strcpy(errmsg, "主机:库存中07残损券数量不符");
			break;
		case	130108	:
			strcpy(errmsg, "主机:库存中08残损券数量不符");
			break;
		case	130109	:
			strcpy(errmsg, "主机:库存中09残损券数量不符");
			break;
		case	130110	:
			strcpy(errmsg, "主机:库存中10残损券数量不符");
			break;
		case	130111	:
			strcpy(errmsg, "主机:库存中11残损券数量不符");
			break;
		case	130112	:
			strcpy(errmsg, "主机:库存中12残损券数量不符");
			break;
		case	130113	:
			strcpy(errmsg, "主机:库存中13残损券数量不符");
			break;
		case	130114	:
			strcpy(errmsg, "主机:库存中14残损券数量不符");
			break;
		case	130115	:
			strcpy(errmsg, "主机:库存中15残损券数量不符");
			break;
		case	130116	:
			strcpy(errmsg, "主机:库存中16残损券数量不符");
			break;
		case	130117	:
			strcpy(errmsg, "主机:库存中17残损券数量不符");
			break;
		case	130118	:
			strcpy(errmsg, "主机:库存中18残损券数量不符");
			break;
		case	130119	:
			strcpy(errmsg, "主机:库存中19残损券数量不符");
			break;
		case	130120	:
			strcpy(errmsg, "主机:库存中20残损券数量不符");
			break;
		case	130407	:
			strcpy(errmsg, "主机:接库员未轧平");
			break;
		case	130409	:
			strcpy(errmsg, "主机:预配款接收方错");
			break;
		case	130410	:
			strcpy(errmsg, "主机:写预配款登记簿错");
			break;
		case	130411	:
			strcpy(errmsg, "主机:修改预配款登记簿错");
			break;
		case	135000	:
			strcpy(errmsg, "主机:登记后台外币调拨交易流水表错");
			break;
		case	135001	:
			strcpy(errmsg, "主机:登记调拨登记簿错");
			break;
		case	135002	:
			strcpy(errmsg, "主机:修改调拨登记簿错");
			break;
		case	135003	:
			strcpy(errmsg, "主机:调拨登记簿无对应记录");
			break;
		case	135004	:
			strcpy(errmsg, "主机:调拨登记簿记录已被修改过不可再修改");
			break;
		case	135005	:
			strcpy(errmsg, "主机:调拨登记簿记录已存在");
			break;
		case	140101	:
			strcpy(errmsg, "主机:业务种类错");
			break;
		case	140102	:
			strcpy(errmsg, "主机:包号错");
			break;
		case	140103	:
			strcpy(errmsg, "主机:联行登记簿记录已存在");
			break;
		case	140104	:
			strcpy(errmsg, "主机:联行往来帐未处理");
			break;
		case	140105	:
			strcpy(errmsg, "主机:退汇理由错");
			break;
		case	140501	:
			strcpy(errmsg, "主机:汇总数据错");
			break;
		case	140701	:
			strcpy(errmsg, "主机:签票流水表中无记录请检查套号");
			break;
		case	140702	:
			strcpy(errmsg, "主机:代理兑付金额错");
			break;
		case	140703	:
			strcpy(errmsg, "主机:代理兑付笔数错");
			break;
		case	140704	:
			strcpy(errmsg, "主机:无需要复核的记录");
			break;
		case	140705	:
			strcpy(errmsg, "主机:签票流水表中无该记录");
			break;
		case	140706	:
			strcpy(errmsg, "主机:签票流水表中该记录状态错");
			break;
		case	140707	:
			strcpy(errmsg, "主机:该记录已输入");
			break;
		case	140708	:
			strcpy(errmsg, "主机:记帐时票据类别错");
			break;
		case	141001	:
			strcpy(errmsg, "主机:本场次已提出记帐结束");
			break;
		case	141002	:
			strcpy(errmsg, "主机:今日交换提出全部结束");
			break;
		case	141003	:
			strcpy(errmsg, "主机:交换号不存在");
			break;
		case	141004	:
			strcpy(errmsg, "主机:提出记帐未结束");
			break;
		case	141005	:
			strcpy(errmsg, "主机:提出付方汇总金额不符");
			break;
		case	141006	:
			strcpy(errmsg, "主机:该币种本场次未发生提出交换");
			break;
		case	141007	:
			strcpy(errmsg, "主机:未发现需要恢复的提出数据");
			break;
		case	141008	:
			strcpy(errmsg, "主机:流水与登记簿中需恢复提出收方数据不符，请查明");
			break;
		case	141009	:
			strcpy(errmsg, "主机:流水与登记簿中需恢复提出付方数据不符，请查明");
			break;
		case	141010	:
			strcpy(errmsg, "主机:前一场数据未提出，本场次不可记帐结束");
			break;
		case	141011	:
			strcpy(errmsg, "主机:今日数据未提出，不可输入明日数据");
			break;
		case	141012	:
			strcpy(errmsg, "主机:提出收方汇总金额不符");
			break;
		case	141013	:
			strcpy(errmsg, "主机:前一场数据未复核，本场次不可记帐结束");
			break;
		case	141014	:
			strcpy(errmsg, "主机:本场还有数据未复核");
			break;
		case	141401	:
			strcpy(errmsg, "主机:应收款登记表中无此流水号");
			break;
		case	150101	:
			strcpy(errmsg, "主机:报表差额过大，无法调平");
			break;
		case	150102	:
			strcpy(errmsg, "主机:没有找到可以调帐的科目");
			break;
		case	150103	:
			strcpy(errmsg, "主机:传入日期错误");
			break;
		case	160001	:
			strcpy(errmsg, "主机:贷款户冲正应属贷款类冲正");
			break;
		case	160002	:
			strcpy(errmsg, "主机:输入的帐号存在卡片");
			break;
		case	160003	:
			strcpy(errmsg, "主机:输入的原会计帐户与卡片的会计帐户不符");
			break;
		case	160004	:
			strcpy(errmsg, "主机:红字冲正金额与卡片金额不符");
			break;
		case	160005	:
			strcpy(errmsg, "主机:两冲正帐号帐户性质不同");
			break;
		case	160006	:
			strcpy(errmsg, "主机:还款卡片存在多种状态");
			break;
		case	160007	:
			strcpy(errmsg, "主机:没有可冲正的信息");
			break;
		case	160008	:
			strcpy(errmsg, "主机:原卡片不允许冲回");
			break;
		case	160009	:
			strcpy(errmsg, "主机:需输入对方卡片编号");
			break;
		case	160010	:
			strcpy(errmsg, "主机:该科目帐号不允许冲正");
			break;
		case	160011	:
			strcpy(errmsg, "主机:需输入错帐卡片编号");
			break;
		case	160012	:
			strcpy(errmsg, "主机:所需调整的积数到调整积数交易中去");
			break;
		case	190101	:
			strcpy(errmsg, "主机:所属主件资产不存在或已复核");
			break;
		case	190102	:
			strcpy(errmsg, "主机:不能增加附件所属主件已提折旧");
			break;
		case	190103	:
			strcpy(errmsg, "主机:资产类别代码不存在");
			break;
		case	190104	:
			strcpy(errmsg, "主机:资产已经退出");
			break;
		case	190105	:
			strcpy(errmsg, "主机:资产或该资产的主件未复核");
			break;
		case	190106	:
			strcpy(errmsg, "主机:业务编号溢出");
			break;
		case	190107	:
			strcpy(errmsg, "主机:该资产有操作未经复核");
			break;
		case	190108	:
			strcpy(errmsg, "主机:业务编号不存在或已复核");
			break;
		case	190109	:
			strcpy(errmsg, "主机:资产已复核不能删除");
			break;
		case	190110	:
			strcpy(errmsg, "主机:不能删除其他柜员的交易");
			break;
		case	190111	:
			strcpy(errmsg, "主机:该附件资产的主件未复核");
			break;
		case	190112	:
			strcpy(errmsg, "主机:核实条件不正确");
			break;
		case	190113	:
			strcpy(errmsg, "主机:资产增加类别错");
			break;
		case	190114	:
			strcpy(errmsg, "主机:折旧年限小于零");
			break;
		case	190115	:
			strcpy(errmsg, "主机:取折旧年限错");
			break;
		case	190116	:
			strcpy(errmsg, "主机:业务编号不是该交易或已复核");
			break;
		case	190117	:
			strcpy(errmsg, "主机:取核算帐户序号错");
			break;
		case	190118	:
			strcpy(errmsg, "主机:取净残值率错");
			break;
		case	190119	:
			strcpy(errmsg, "主机:业务编号不存在或未复核");
			break;
		case	190120	:
			strcpy(errmsg, "主机:请先对该资产的附件抹帐");
			break;
		case	190121	:
			strcpy(errmsg, "主机:不是当天的交易请使用冲正");
			break;
		case	190122	:
			strcpy(errmsg, "主机:类别代码已存在");
			break;
		case	190123	:
			strcpy(errmsg, "主机:取科目代码错");
			break;
		case	200101	:
			strcpy(errmsg, "主机:写长期不动户登记表错");
			break;
		case	200102	:
			strcpy(errmsg, "主机:写久悬卡片户登记表错");
			break;
		case	200103	:
			strcpy(errmsg, "主机:该卡为久悬卡片");
			break;
		case	200104	:
			strcpy(errmsg, "主机:长期不动户帐号不存在");
			break;
		case	200105	:
			strcpy(errmsg, "主机:久悬卡号不存在");
			break;
		case	200106	:
			strcpy(errmsg, "主机:写开销户登记表错");
			break;
		case	200107	:
			strcpy(errmsg, "主机:读长期不动户登记表错");
			break;
		case	200108	:
			strcpy(errmsg, "主机:计算不动户活期利息错");
			break;
		case	200401	:
			strcpy(errmsg, "主机:业务种类错");
			break;
		case	200402	:
			strcpy(errmsg, "主机:通知编号错");
			break;
		case	200403	:
			strcpy(errmsg, "主机:通知编号不存在");
			break;
		case	200404	:
			strcpy(errmsg, "主机:通知范围错");
			break;
		case	200405	:
			strcpy(errmsg, "主机:理由代码错");
			break;
		case	200406	:
			strcpy(errmsg, "主机:信用证编号错");
			break;
		case	200407	:
			strcpy(errmsg, "主机:通知面函错");
			break;
		case	200408	:
			strcpy(errmsg, "主机:信用证编号状态错");
			break;
		case	200409	:
			strcpy(errmsg, "主机:记帐复核之间信用证编号状态改变");
			break;
		case	200410	:
			strcpy(errmsg, "主机:5413置为不动户出错");
			break;
		case	200411	:
			strcpy(errmsg, "主机:5413不动户恢复出错");
			break;
		case	200412	:
			strcpy(errmsg, "主机:信用证LP编号错");
			break;
		case	200413	:
			strcpy(errmsg, "主机:出口979销账金额>通知总金额");
			break;
		case	200414	:
			strcpy(errmsg, "主机:信用证总销账金额>信用证总金额");
			break;
		case	200415	:
			strcpy(errmsg, "主机:取最近一期统计牌价错");
			break;
		case	200416	:
			strcpy(errmsg, "主机:取人民币兑美元的统计牌价错");
			break;
		case	200417	:
			strcpy(errmsg, "主机:取外币兑美元的统计牌价错");
			break;
		default	:
			strcpy(errmsg, "主机:未知错误");
			break;
	}

	return errmsg;
}
