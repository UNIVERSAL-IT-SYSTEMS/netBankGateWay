/*--------------------------------------------*/
/* �������ɳ���generr�Զ����ɣ��벻Ҫ�ֹ��޸� */
/* �����������ɸó�������������generr����   */
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
			strcpy(errmsg, "����:���׳ɹ�");
			break;
		case	1	:
			strcpy(errmsg, "����:���׼���");
			break;
		case	1001	:
			strcpy(errmsg, "����:�������");
			break;
		case	1002	:
			strcpy(errmsg, "����:���������");
			break;
		case	1003	:
			strcpy(errmsg, "����:�޴˽���");
			break;
		case	1004	:
			strcpy(errmsg, "����:д������ˮ��");
			break;
		case	1005	:
			strcpy(errmsg, "����:д������ˮ���ձ��");
			break;
		case	1006	:
			strcpy(errmsg, "����:д���׻����ļ�����");
			break;
		case	1007	:
			strcpy(errmsg, "����:�����Ѿ�Ĩ��");
			break;
		case	1008	:
			strcpy(errmsg, "����:Ĩ�ʵĽ��ײ�����");
			break;
		case	1009	:
			strcpy(errmsg, "����:�ñʽ��ײ���Ĩ��");
			break;
		case	1020	:
			strcpy(errmsg, "����:�������Ľ��׽���");
			break;
		case	1021	:
			strcpy(errmsg, "����:�������Ľ��ײ�����");
			break;
		case	1030	:
			strcpy(errmsg, "����:�ý��׽�ֹ����");
			break;
		case	1031	:
			strcpy(errmsg, "����:�Ǵ���״���Χ");
			break;
		case	1032	:
			strcpy(errmsg, "����:���н��׵Ĳ���������Ա���Գ�ͻ");
			break;
		case	1101	:
			strcpy(errmsg, "����:ϵͳ������֪ͨ��������");
			break;
		case	1102	:
			strcpy(errmsg, "����:���ݿ����ʧ��");
			break;
		case	1103	:
			strcpy(errmsg, "����:SQL���ô�");
			break;
		case	1104	:
			strcpy(errmsg, "����:û�����û�������WORKDIR");
			break;
		case	1105	:
			strcpy(errmsg, "����:DEC�����");
			break;
		case	1106	:
			strcpy(errmsg, "����:DECIMAL�ͼ����");
			break;
		case	1107	:
			strcpy(errmsg, "����:ͨ�ų�ʱ");
			break;
		case	1108	:
			strcpy(errmsg, "����:�ϴ����ݼ�����");
			break;
		case	1109	:
			strcpy(errmsg, "����:��������");
			break;
		case	1110	:
			strcpy(errmsg, "����:���");
			break;
		case	1111	:
			strcpy(errmsg, "����:���շ������");
			break;
		case	1112	:
			strcpy(errmsg, "����:���벻��");
			break;
		case	1113	:
			strcpy(errmsg, "����:״̬��");
			break;
		case	1114	:
			strcpy(errmsg, "����:���ڳ���");
			break;
		case	1115	:
			strcpy(errmsg, "����:��ѯ����");
			break;
		case	1116	:
			strcpy(errmsg, "����:�޴˷���");
			break;
		case	1117	:
			strcpy(errmsg, "����:��ڲ�������");
			break;
		case	1118	:
			strcpy(errmsg, "����:��ѯ����");
			break;
		case	1119	:
			strcpy(errmsg, "����:IC����Ч");
			break;
		case	1150	:
			strcpy(errmsg, "����:���ļ���");
			break;
		case	1151	:
			strcpy(errmsg, "����:�����ļ���");
			break;
		case	1152	:
			strcpy(errmsg, "����:���ļ���");
			break;
		case	1153	:
			strcpy(errmsg, "����:д�ļ���");
			break;
		case	1154	:
			strcpy(errmsg, "����:����/�����ļ�������");
			break;
		case	1201	:
			strcpy(errmsg, "����:û�����������ļ�¼");
			break;
		case	1202	:
			strcpy(errmsg, "����:��¼�Ѵ���");
			break;
		case	1203	:
			strcpy(errmsg, "����:�����¼");
			break;
		case	1204	:
			strcpy(errmsg, "����:д��¼��");
			break;
		case	1205	:
			strcpy(errmsg, "����:�޸ļ�¼����");
			break;
		case	1206	:
			strcpy(errmsg, "����:���޸�����");
			break;
		case	1208	:
			strcpy(errmsg, "����:������Ȩ�Ѵ���");
			break;
		case	1209	:
			strcpy(errmsg, "����:��ͬ�������Ȩ��ʽ��ͻ");
			break;
		case	1210	:
			strcpy(errmsg, "����:û���ҵ���Ӧ�ĵ׿�");
			break;
		case	1211	:
			strcpy(errmsg, "����:�˽���ֻ����Ʊ��ǩ����ʹ��");
			break;
		case	1212	:
			strcpy(errmsg, "����:�������г��ξ��ѽ���");
			break;
		case	1213	:
			strcpy(errmsg, "����:��һ��δ���������");
			break;
		case	1214	:
			strcpy(errmsg, "����:�������Ͻ������ε�����ݲ��ܴ���");
			break;
		case	1215	:
			strcpy(errmsg, "����:ֻ�й�Ͻ�в��������������");
			break;
		case	1216	:
			strcpy(errmsg, "����:ȫ�����ν�����־��");
			break;
		case	1217	:
			strcpy(errmsg, "����:�޸Ľ����Զ����ʵǼǱ��");
			break;
		case	1218	:
			strcpy(errmsg, "����:Ŀǰ��ҽ���ֻ��һ��");
			break;
		case	1219	:
			strcpy(errmsg, "����:�����ϳ�δ������ɻָ�");
			break;
		case	1220	:
			strcpy(errmsg, "����:�����н�����δ����");
			break;
		case	1221	:
			strcpy(errmsg, "����:�����������Ľ��ײ���Ĩ��");
			break;
		case	1222	:
			strcpy(errmsg, "����:�Ǽ������ʽ�������");
			break;
		case	1223	:
			strcpy(errmsg, "����:����һ�������Ѿ�����");
			break;
		case	1224	:
			strcpy(errmsg, "����:���ն��������Ѿ�����");
			break;
		case	1225	:
			strcpy(errmsg, "����:�޸������ʽ�������");
			break;
		case	1226	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	1227	:
			strcpy(errmsg, "����:������Ʊ�ݵǼǱ��");
			break;
		case	1228	:
			strcpy(errmsg, "����:�ı���ˮ������Ĩ��");
			break;
		case	1229	:
			strcpy(errmsg, "����:�Ǽǽ���ת��ǼǱ��");
			break;
		case	1230	:
			strcpy(errmsg, "����:��������ʱ���");
			break;
		case	1231	:
			strcpy(errmsg, "����:�����������δȫ������");
			break;
		case	1232	:
			strcpy(errmsg, "����:���ʺŴ�");
			break;
		case	1233	:
			strcpy(errmsg, "����:��Ʊ���ʹ�");
			break;
		case	1234	:
			strcpy(errmsg, "����:�޸���Ʊ�Ǽǲ���");
			break;
		case	1235	:
			strcpy(errmsg, "����:�����ʺŲ������");
			break;
		case	1236	:
			strcpy(errmsg, "����:�Զ��ۻ������ǷϢ���");
			break;
		case	1237	:
			strcpy(errmsg, "����:�����ʺ��µ����д浥�ѽ���");
			break;
		case	10001	:
			strcpy(errmsg, "����:����ʻ�����");
			break;
		case	10002	:
			strcpy(errmsg, "����:�޴˻���ʻ�");
			break;
		case	10003	:
			strcpy(errmsg, "����:����ʻ�����");
			break;
		case	10004	:
			strcpy(errmsg, "����:����ʻ�״̬��");
			break;
		case	10005	:
			strcpy(errmsg, "����:���ɻ���ʻ�����");
			break;
		case	10006	:
			strcpy(errmsg, "����:�޸Ļ���ʻ�����");
			break;
		case	10007	:
			strcpy(errmsg, "����:�����������ʻ�����");
			break;
		case	10008	:
			strcpy(errmsg, "����:��������ʻ���ͬ");
			break;
		case	10009	:
			strcpy(errmsg, "����:���ɻ���ʻ������ʳ���");
			break;
		case	10010	:
			strcpy(errmsg, "����:����ʻ������ʳ���");
			break;
		case	10011	:
			strcpy(errmsg, "����:����ʻ��������д���");
			break;
		case	10012	:
			strcpy(errmsg, "����:�������ʳ���");
			break;
		case	10013	:
			strcpy(errmsg, "����:���·ֻ��ʴ�");
			break;
		case	10014	:
			strcpy(errmsg, "����:�����������Ƭ�ʴ�");
			break;
		case	10015	:
			strcpy(errmsg, "����:���°��Ҵ��Ƭ�ʴ�");
			break;
		case	10016	:
			strcpy(errmsg, "����:���´��Ƭ�ʴ�");
			break;
		case	10017	:
			strcpy(errmsg, "����:����ʻ���Ŀ���ձ����");
			break;
		case	10024	:
			strcpy(errmsg, "����:�޶�Ӧ�ջ���ʻ�");
			break;
		case	10025	:
			strcpy(errmsg, "����:����ǰ�����ʻ���ͬ");
			break;
		case	10026	:
			strcpy(errmsg, "����:�����ʻ��޹�������ʻ�");
			break;
		case	10027	:
			strcpy(errmsg, "����:������ͬһ֧��");
			break;
		case	10028	:
			strcpy(errmsg, "����:�²��Ŷ�Ӧ�ʻ�������");
			break;
		case	10101	:
			strcpy(errmsg, "����:�������ʳ���");
			break;
		case	10102	:
			strcpy(errmsg, "����:�������ʸ��·ֻ��ʳ���");
			break;
		case	10103	:
			strcpy(errmsg, "����:���������޸Ļ����ˮ����");
			break;
		case	10104	:
			strcpy(errmsg, "����:�������ʿ�֧��������");
			break;
		case	10105	:
			strcpy(errmsg, "����:�������ʷ�¼������");
			break;
		case	10106	:
			strcpy(errmsg, "����:�������ʽ����ƽ");
			break;
		case	10107	:
			strcpy(errmsg, "����:�������ʻ����ˮ������");
			break;
		case	10108	:
			strcpy(errmsg, "����:�������ʻ����ˮ��Ĩ��");
			break;
		case	10109	:
			strcpy(errmsg, "����:��������ɾ�������ˮ����");
			break;
		case	10110	:
			strcpy(errmsg, "����:�������ʻ����ˮ״̬��");
			break;
		case	10111	:
			strcpy(errmsg, "����:���������ڲ��ʻ����Ƴ���");
			break;
		case	10112	:
			strcpy(errmsg, "����:�������ʴ�");
			break;
		case	10114	:
			strcpy(errmsg, "����:�����������ʴ�");
			break;
		case	10115	:
			strcpy(errmsg, "����:�����������ʽ���");
			break;
		case	10116	:
			strcpy(errmsg, "����:�����������ʱ�Ŵ�");
			break;
		case	10117	:
			strcpy(errmsg, "����:���������޸����ʱ�Ŵ�");
			break;
		case	10118	:
			strcpy(errmsg, "����:������������޶��");
			break;
		case	10119	:
			strcpy(errmsg, "����:������������޶��޸ĳ���");
			break;
		case	10120	:
			strcpy(errmsg, "����:�������ʵǼǻ����ˮ����");
			break;
		case	10121	:
			strcpy(errmsg, "����:�������ʻָ����ʳ���");
			break;
		case	10122	:
			strcpy(errmsg, "����:�ʺ����ͳ���");
			break;
		case	10123	:
			strcpy(errmsg, "����:�޹���������");
			break;
		case	10124	:
			strcpy(errmsg, "����:Ԥ����Ϣ��ֻ������");
			break;
		case	10125	:
			strcpy(errmsg, "����:������ˮ��ƥ��");
			break;
		case	10201	:
			strcpy(errmsg, "����:������ڳ���");
			break;
		case	10202	:
			strcpy(errmsg, "����:ȡ������ڴ�");
			break;
		case	10203	:
			strcpy(errmsg, "����:ȡ��Ʒ�¼��");
			break;
		case	10204	:
			strcpy(errmsg, "����:�ǻ����ˮ��");
			break;
		case	10205	:
			strcpy(errmsg, "����:�Զ����ɻ�Ʒ�¼����");
			break;
		case	10206	:
			strcpy(errmsg, "����:����ȡ��Ʒ�¼������");
			break;
		case	10207	:
			strcpy(errmsg, "����:ϵͳ���ڴ��ڻ������");
			break;
		case	10208	:
			strcpy(errmsg, "����:������");
			break;
		case	10209	:
			strcpy(errmsg, "����:�Զ���¼������");
			break;
		case	10210	:
			strcpy(errmsg, "����:�Զ���¼�������");
			break;
		case	10301	:
			strcpy(errmsg, "����:�Զ�ϸĿ��");
			break;
		case	10302	:
			strcpy(errmsg, "����:�����Զ�ϸĿ��");
			break;
		case	10303	:
			strcpy(errmsg, "����:ȡ���Զ�ϸĿ��");
			break;
		case	10304	:
			strcpy(errmsg, "����:�Զ�ϸĿ�Ѵ���");
			break;
		case	20001	:
			strcpy(errmsg, "����:�ͻ�״̬��");
			break;
		case	20002	:
			strcpy(errmsg, "����:�ͻ�����Ч");
			break;
		case	20003	:
			strcpy(errmsg, "����:�ͻ��Ų�����");
			break;
		case	20004	:
			strcpy(errmsg, "����:�ͻ��ų���");
			break;
		case	20005	:
			strcpy(errmsg, "����:�ͻ�������");
			break;
		case	20006	:
			strcpy(errmsg, "����:������ͻ���������");
			break;
		case	20007	:
			strcpy(errmsg, "����:������λ�ͻ��Ŵ�");
			break;
		case	20009	:
			strcpy(errmsg, "����:�ͻ���Ϣ������");
			break;
		case	20010	:
			strcpy(errmsg, "����:�ͻ�����ͬ");
			break;
		case	20013	:
			strcpy(errmsg, "����:���㻧�ͻ���������Ŀͻ��Ų���");
			break;
		case	20014	:
			strcpy(errmsg, "����:���Թ��ͻ���Ϣ��");
			break;
		case	20015	:
			strcpy(errmsg, "����:ȡ�ͻ��Ŵ�");
			break;
		case	20016	:
			strcpy(errmsg, "����:ȡ���˿ͻ��Ŵ�");
			break;
		case	20051	:
			strcpy(errmsg, "����:֤��������ʹ��");
			break;
		case	20052	:
			strcpy(errmsg, "����:���˿ͻ�������");
			break;
		case	20053	:
			strcpy(errmsg, "����:���˿ͻ�������");
			break;
		case	20054	:
			strcpy(errmsg, "����:���˿ͻ����пͻ�δ����");
			break;
		case	20055	:
			strcpy(errmsg, "����:���㻧�ͻ����붨���ʺſͻ��Ų�ͬ");
			break;
		case	20056	:
			strcpy(errmsg, "����:���˿ͻ��Ѵ���");
			break;
		case	20101	:
			strcpy(errmsg, "����:��ؿͻ�����Ч");
			break;
		case	20102	:
			strcpy(errmsg, "����:��ؿͻ��Ѵ���");
			break;
		case	20103	:
			strcpy(errmsg, "����:��ؿͻ�������");
			break;
		case	20104	:
			strcpy(errmsg, "����:��ؿͻ���ȡ��");
			break;
		case	20105	:
			strcpy(errmsg, "����:֤�������Ѵ���");
			break;
		case	20106	:
			strcpy(errmsg, "����:�������Ѵ���");
			break;
		case	20107	:
			strcpy(errmsg, "����:������������");
			break;
		case	20108	:
			strcpy(errmsg, "����:�û�Ϊ��������");
			break;
		case	20109	:
			strcpy(errmsg, "����:���ʺŵĿͻ������");
			break;
		case	30001	:
			strcpy(errmsg, "����:ȫ��δ����");
			break;
		case	30002	:
			strcpy(errmsg, "����:ȫ���ѿ���");
			break;
		case	30003	:
			strcpy(errmsg, "����:��ȫ�б��");
			break;
		case	30004	:
			strcpy(errmsg, "����:ȫ�б����");
			break;
		case	30101	:
			strcpy(errmsg, "����:����֧�г���");
			break;
		case	30102	:
			strcpy(errmsg, "����:�޴�֧�к�");
			break;
		case	30201	:
			strcpy(errmsg, "����:�޴˲���");
			break;
		case	30202	:
			strcpy(errmsg, "����:������ų���");
			break;
		case	30203	:
			strcpy(errmsg, "����:���ż����");
			break;
		case	30204	:
			strcpy(errmsg, "����:����״̬��");
			break;
		case	30205	:
			strcpy(errmsg, "����:�����޴�Ȩ��");
			break;
		case	30206	:
			strcpy(errmsg, "����:����δ����");
			break;
		case	30207	:
			strcpy(errmsg, "����:����δ����");
			break;
		case	30208	:
			strcpy(errmsg, "����:�����ѿ���");
			break;
		case	30209	:
			strcpy(errmsg, "����:ʹ�ò��Ŵ�");
			break;
		case	30210	:
			strcpy(errmsg, "����:����ϸĿ������");
			break;
		case	30211	:
			strcpy(errmsg, "����:���Ų�������");
			break;
		case	30212	:
			strcpy(errmsg, "����:�ǿ������Ų����޸�");
			break;
		case	30213	:
			strcpy(errmsg, "����:���ű����");
			break;
		case	30214	:
			strcpy(errmsg, "����:��ϢԤ��Ϣ�����");
			break;
		case	30215	:
			strcpy(errmsg, "����:��ϢԤ��Ϣ��û�����������ļ�¼");
			break;
		case	30216	:
			strcpy(errmsg, "����:���Ų�ͬ");
			break;
		case	30217	:
			strcpy(errmsg, "����:���зֻ�����Ϣ���޷�����ؼ�����");
			break;
		case	30218	:
			strcpy(errmsg, "����:���¼����ţ��޷�����ؼ�����");
			break;
		case	30301	:
			strcpy(errmsg, "����:����ӦΪ���ڲ�������");
			break;
		case	30302	:
			strcpy(errmsg, "����:�޼����账��");
			break;
		case	30401	:
			strcpy(errmsg, "����:�޴��ն�");
			break;
		case	30402	:
			strcpy(errmsg, "����:���ն���ʹ��");
			break;
		case	30403	:
			strcpy(errmsg, "����:���ն˲�����ʹ��");
			break;
		case	30409	:
			strcpy(errmsg, "����:�ÿ����Ѵ���");
			break;
		case	30501	:
			strcpy(errmsg, "����:���ִ�");
			break;
		case	30502	:
			strcpy(errmsg, "����:�޴˱���");
			break;
		case	30503	:
			strcpy(errmsg, "����:���ֲ�ͬ");
			break;
		case	30504	:
			strcpy(errmsg, "����:����״̬��");
			break;
		case	30505	:
			strcpy(errmsg, "����:�޻����Ƽ�");
			break;
		case	30506	:
			strcpy(errmsg, "����:������ֲ��������");
			break;
		case	30507	:
			strcpy(errmsg, "����:������ɾ��");
			break;
		case	30508	:
			strcpy(errmsg, "����:ŷԪ��־��");
			break;
		case	30509	:
			strcpy(errmsg, "����:��/���־���ʻ�����");
			break;
		case	30601	:
			strcpy(errmsg, "����:��Ŀ��");
			break;
		case	30602	:
			strcpy(errmsg, "����:�޸Ŀ�Ŀ��");
			break;
		case	30603	:
			strcpy(errmsg, "����:ɾ����Ŀ��");
			break;
		case	30604	:
			strcpy(errmsg, "����:��Ŀ����ʧ��");
			break;
		case	30605	:
			strcpy(errmsg, "����:��Ŀ�Ѵ���");
			break;
		case	30606	:
			strcpy(errmsg, "����:��Ŀ������");
			break;
		case	30607	:
			strcpy(errmsg, "����:��Ŀ���ʴ���");
			break;
		case	30608	:
			strcpy(errmsg, "����:�޿�Ŀ����");
			break;
		case	30609	:
			strcpy(errmsg, "����:��Ŀ���ʴ�");
			break;
		case	30610	:
			strcpy(errmsg, "����:��Ŀ����Ƿ�");
			break;
		case	30611	:
			strcpy(errmsg, "����:��Ŀ״̬��");
			break;
		case	30612	:
			strcpy(errmsg, "����:��Ŀ���ͷǷ�");
			break;
		case	30613	:
			strcpy(errmsg, "����:���������Ŀ����");
			break;
		case	30614	:
			strcpy(errmsg, "����:��Ŀ����Ƿ�");
			break;
		case	30615	:
			strcpy(errmsg, "����:��Ŀ�������Ƿ�");
			break;
		case	30616	:
			strcpy(errmsg, "����:ȡ��Ŀ�����ʱ��ʧ��");
			break;
		case	30617	:
			strcpy(errmsg, "����:���ڱ����־��");
			break;
		case	30618	:
			strcpy(errmsg, "����:�޸������ʳ���");
			break;
		case	30619	:
			strcpy(errmsg, "����:�޸������ʳ���");
			break;
		case	30620	:
			strcpy(errmsg, "����:�޸��ջ���ʻ����ʳ���");
			break;
		case	30621	:
			strcpy(errmsg, "����:�޸��»���ʻ����ʳ���");
			break;
		case	30622	:
			strcpy(errmsg, "����:������Ŀ����δ��");
			break;
		case	30623	:
			strcpy(errmsg, "����:������Ŀ����");
			break;
		case	30624	:
			strcpy(errmsg, "����:�ڲ��ʺŲ��ܱ����������");
			break;
		case	30625	:
			strcpy(errmsg, "����:��Ŀ��ͬ");
			break;
		case	30626	:
			strcpy(errmsg, "����:��Ͻ��Ŀ����δ��");
			break;
		case	30627	:
			strcpy(errmsg, "����:������Ŀ����δ�ָ�");
			break;
		case	30628	:
			strcpy(errmsg, "����:�޸������ʳ���");
			break;
		case	30629	:
			strcpy(errmsg, "����:�޸������ʻ����ʳ���");
			break;
		case	30701	:
			strcpy(errmsg, "����:�޴˹�Ա");
			break;
		case	30702	:
			strcpy(errmsg, "����:��Ա�޴�Ȩ��");
			break;
		case	30703	:
			strcpy(errmsg, "����:ȡ��Ա��ˮ�ų���");
			break;
		case	30704	:
			strcpy(errmsg, "����:��Աδǩ��");
			break;
		case	30705	:
			strcpy(errmsg, "����:��Աδǩ��");
			break;
		case	30706	:
			strcpy(errmsg, "����:��Ա����ʱǩ��");
			break;
		case	30707	:
			strcpy(errmsg, "����:��Ա��������䲿�ż���");
			break;
		case	30708	:
			strcpy(errmsg, "����:��ȫ�й���Ա");
			break;
		case	30709	:
			strcpy(errmsg, "����:�ǲ��Ź���Ա");
			break;
		case	30710	:
			strcpy(errmsg, "����:����Ա���ڹ���״̬");
			break;
		case	30711	:
			strcpy(errmsg, "����:�����Ա��Ȩ��������");
			break;
		case	30712	:
			strcpy(errmsg, "����:�����Ա��Ȩ��������");
			break;
		case	30713	:
			strcpy(errmsg, "����:�Ƿ��Ľ������");
			break;
		case	30714	:
			strcpy(errmsg, "����:���ռ佻��ʱ���ֹǩ��!");
			break;
		case	30715	:
			strcpy(errmsg, "����:ϵͳ�������ջ���ʼ��ֹǩ��!");
			break;
		case	30716	:
			strcpy(errmsg, "����:ϵͳĿǰ״̬������ȫ������!");
			break;
		case	30717	:
			strcpy(errmsg, "����:��Ա���Բ���!");
			break;
		case	30718	:
			strcpy(errmsg, "����:���м���Ĳ��Ų�����֧�м���Ĺ�Ա");
			break;
		case	30719	:
			strcpy(errmsg, "����:�ù�Ա�������ڱ�ǰ̨ǩ��");
			break;
		case	30751	:
			strcpy(errmsg, "����:������Ҫ��Ȩ");
			break;
		case	30752	:
			strcpy(errmsg, "����:��Ȩ��Ա��");
			break;
		case	30753	:
			strcpy(errmsg, "����:��Ȩ��Ա�����");
			break;
		case	30754	:
			strcpy(errmsg, "����:��Ȩʧ��");
			break;
		case	30755	:
			strcpy(errmsg, "����:�޴���Ȩ����");
			break;
		case	30756	:
			strcpy(errmsg, "����:�޴���Ȩ����Ĺ�Ա");
			break;
		case	30757	:
			strcpy(errmsg, "����:��Ȩ��Ա���𲻹�");
			break;
		case	30758	:
			strcpy(errmsg, "����:��Ȩ��Ա�������ԱΪͬһ��Ա");
			break;
		case	30759	:
			strcpy(errmsg, "����:��Ҫͬһ���Ź�Ա��Ȩ");
			break;
		case	30760	:
			strcpy(errmsg, "����:��Ҫָ�����Ź�Ա��Ȩ");
			break;
		case	30761	:
			strcpy(errmsg, "����:�Ѽ���");
			break;
		case	30762	:
			strcpy(errmsg, "����:δ����");
			break;
		case	30763	:
			strcpy(errmsg, "����:�Ѹ���");
			break;
		case	30764	:
			strcpy(errmsg, "����:δ����");
			break;
		case	30765	:
			strcpy(errmsg, "����:����δ���˽���");
			break;
		case	30771	:
			strcpy(errmsg, "����:�Ѽල");
			break;
		case	30772	:
			strcpy(errmsg, "����:δ�ල");
			break;
		case	30773	:
			strcpy(errmsg, "����:������ˮ���ڴ���ļල��־");
			break;
		case	30774	:
			strcpy(errmsg, "����:�����ֱ�־��");
			break;
		case	30801	:
			strcpy(errmsg, "����:����ˮ���");
			break;
		case	30802	:
			strcpy(errmsg, "����:�޴˽�����ˮ");
			break;
		case	30803	:
			strcpy(errmsg, "����:��������ˮ");
			break;
		case	30804	:
			strcpy(errmsg, "����:�޴���ʼ��ˮ��");
			break;
		case	30805	:
			strcpy(errmsg, "����:�޴���ֹ��ˮ��");
			break;
		case	30806	:
			strcpy(errmsg, "����:ȡϵͳ��ˮ�Ŵ�");
			break;
		case	30807	:
			strcpy(errmsg, "����:�Ǽ�ϵͳ��ˮ���");
			break;
		case	30808	:
			strcpy(errmsg, "����:�޸Ĺ�Աƾ֤ʹ����ϸ���");
			break;
		case	30809	:
			strcpy(errmsg, "����:���Ʊ�ݽ������β�һ��");
			break;
		case	30810	:
			strcpy(errmsg, "����:�����Ѹ��˵�δ���ʻ����ˮ");
			break;
		case	30811	:
			strcpy(errmsg, "����:������ˮ��������Ҫ�ල����ˮ");
			break;
		case	30901	:
			strcpy(errmsg, "����:��Ŵ�");
			break;
		case	30902	:
			strcpy(errmsg, "����:��ű�״̬��");
			break;
		case	30903	:
			strcpy(errmsg, "����:��Ų�ͬ");
			break;
		case	30904	:
			strcpy(errmsg, "����:���ֵ����");
			break;
		case	30905	:
			strcpy(errmsg, "����:ҵ���Ų�ͬ");
			break;
		case	30906	:
			strcpy(errmsg, "����:���±�ű��");
			break;
		case	30907	:
			strcpy(errmsg, "����:������Ʒ��Ų�ͬ");
			break;
		case	30908	:
			strcpy(errmsg, "����:�溯��Ų�ͬ");
			break;
		case	30909	:
			strcpy(errmsg, "����:�޴������к�");
			break;
		case	30910	:
			strcpy(errmsg, "����:֪ͨ��Ų�����");
			break;
		case	30911	:
			strcpy(errmsg, "����:�������кŷ����е��������к�");
			break;
		case	31001	:
			strcpy(errmsg, "����:������");
			break;
		case	31002	:
			strcpy(errmsg, "����:ȡ����ʧ��");
			break;
		case	31003	:
			strcpy(errmsg, "����:ȡ����ʧ����Ϣ�չ���");
			break;
		case	31004	:
			strcpy(errmsg, "����:���ʴ��벻ͬ");
			break;
		case	31005	:
			strcpy(errmsg, "����:�̶�����ֵ��ͬ");
			break;
		case	31006	:
			strcpy(errmsg, "����:��������ֵ��ͬ");
			break;
		case	31007	:
			strcpy(errmsg, "����:�����ѱ�����ͬ");
			break;
		case	31008	:
			strcpy(errmsg, "����:�������ʲ�ͬ");
			break;
		case	31009	:
			strcpy(errmsg, "����:�ƻ����������ͬ");
			break;
		case	31010	:
			strcpy(errmsg, "����:�������Ѹ�");
			break;
		case	31011	:
			strcpy(errmsg, "����:������δ��");
			break;
		case	31012	:
			strcpy(errmsg, "����:ת���ͬ");
			break;
		case	31013	:
			strcpy(errmsg, "����:�㲦��ͬ");
			break;
		case	31014	:
			strcpy(errmsg, "����:�����Ѽ����");
			break;
		case	31015	:
			strcpy(errmsg, "����:ǰ��̨�����Ѳ�ͬ");
			break;
		case	31101	:
			strcpy(errmsg, "����:�����Ϣ");
			break;
		case	31102	:
			strcpy(errmsg, "����:�ֶμ�Ϣ");
			break;
		case	31103	:
			strcpy(errmsg, "����:����ȡϢ");
			break;
		case	31104	:
			strcpy(errmsg, "����:��Ϣ��ʽ��ͬ");
			break;
		case	31105	:
			strcpy(errmsg, "����:��Ϣ���Ͳ�ͬ");
			break;
		case	31106	:
			strcpy(errmsg, "����:����ȡϢ��δ��");
			break;
		case	31107	:
			strcpy(errmsg, "����:������������Ϣ��");
			break;
		case	31108	:
			strcpy(errmsg, "����:ֹϢ��Ӧ������Ϣ��");
			break;
		case	31109	:
			strcpy(errmsg, "����:�������ֹ���Ϣ���");
			break;
		case	31110	:
			strcpy(errmsg, "����:��Ϣ����");
			break;
		case	31111	:
			strcpy(errmsg, "����:��Ϣ���㷽������");
			break;
		case	31112	:
			strcpy(errmsg, "����:��Ϣ���ڲ�ͬ");
			break;
		case	31113	:
			strcpy(errmsg, "����:���������Ѽ�Ϣ");
			break;
		case	31151	:
			strcpy(errmsg, "����:��Ϣ���벻ͬ");
			break;
		case	31152	:
			strcpy(errmsg, "����:ǷϢ����");
			break;
		case	31153	:
			strcpy(errmsg, "����:ǷϢ���Ϊ0");
			break;
		case	31154	:
			strcpy(errmsg, "����:ǷϢ��ϸ��׷��ʧ��");
			break;
		case	31155	:
			strcpy(errmsg, "����:��Ϣ���Ϊ0");
			break;
		case	31156	:
			strcpy(errmsg, "����:ǷϢ��ϸ�����ʧ��");
			break;
		case	31157	:
			strcpy(errmsg, "����:ǷϢ������ϸ�����ʧ��");
			break;
		case	31201	:
			strcpy(errmsg, "����:�������");
			break;
		case	31202	:
			strcpy(errmsg, "����:������");
			break;
		case	31203	:
			strcpy(errmsg, "����:�޶����");
			break;
		case	31204	:
			strcpy(errmsg, "����:�޶��Ѵ���");
			break;
		case	31205	:
			strcpy(errmsg, "����:�����޶����");
			break;
		case	31206	:
			strcpy(errmsg, "����:ȡ���޶����");
			break;
		case	31207	:
			strcpy(errmsg, "����:�޸��޶����");
			break;
		case	31208	:
			strcpy(errmsg, "����:ȡ����ӦС�����");
			break;
		case	31209	:
			strcpy(errmsg, "����:ǩ�����С����ʼ���");
			break;
		case	31210	:
			strcpy(errmsg, "����:�ѳ���������ɴ���Ľ��");
			break;
		case	31211	:
			strcpy(errmsg, "����:���������");
			break;
		case	31301	:
			strcpy(errmsg, "����:�����ղ�ͬ");
			break;
		case	31302	:
			strcpy(errmsg, "����:ժҪ��ͬ");
			break;
		case	31303	:
			strcpy(errmsg, "����:Ʊ������");
			break;
		case	31304	:
			strcpy(errmsg, "����:Ʊ��û������");
			break;
		case	31401	:
			strcpy(errmsg, "����:������ʽ����");
			break;
		case	31402	:
			strcpy(errmsg, "����:���������");
			break;
		case	31403	:
			strcpy(errmsg, "����:������������");
			break;
		case	31404	:
			strcpy(errmsg, "����:�ֽ���δ��ƽ");
			break;
		case	31405	:
			strcpy(errmsg, "����:�ʲ�ƽ");
			break;
		case	31406	:
			strcpy(errmsg, "����:ȫ���������ֽ�δ��ƽ");
			break;
		case	31407	:
			strcpy(errmsg, "����:�ֽ������ֽ��ʻ�����");
			break;
		case	31408	:
			strcpy(errmsg, "����:ƾ֤�����ƾ֤�ʻ�����");
			break;
		case	31409	:
			strcpy(errmsg, "����:Ӧ�����ֽ�δ�յ�");
			break;
		case	31410	:
			strcpy(errmsg, "����:Ӧ����ƾ֤δ�յ�");
			break;
		case	31411	:
			strcpy(errmsg, "����:Ӧ�����м۵�֤δ�յ�");
			break;
		case	31412	:
			strcpy(errmsg, "����:�м۵�֤������ʻ�����");
			break;
		case	31413	:
			strcpy(errmsg, "����:����Ԥ������Ϊ��");
			break;
		case	31414	:
			strcpy(errmsg, "����:Ӧ���չ�ծδ�յ�");
			break;
		case	31415	:
			strcpy(errmsg, "����:ƾ֤���ۿ����ƾ֤1381�ʻ�����");
			break;
		case	31416	:
			strcpy(errmsg, "����:5011��5081��ƽ");
			break;
		case	31417	:
			strcpy(errmsg, "����:5012��5082��ƽ");
			break;
		case	32001	:
			strcpy(errmsg, "����:ƾ֤���Ϸ�");
			break;
		case	32002	:
			strcpy(errmsg, "����:ƾ֤���벻��");
			break;
		case	32003	:
			strcpy(errmsg, "����:ƾ֤���಻��");
			break;
		case	32004	:
			strcpy(errmsg, "����:��ƾ֤û�г���");
			break;
		case	32005	:
			strcpy(errmsg, "����:ƾ֤�����ظ���Ҫ������ֺ�");
			break;
		case	32006	:
			strcpy(errmsg, "����:ƾ֤��ʼ�ţ�����������������");
			break;
		case	32007	:
			strcpy(errmsg, "����:����ƾ֤δ��ƽ");
			break;
		case	32008	:
			strcpy(errmsg, "����:��ѯƾ֤����");
			break;
		case	32009	:
			strcpy(errmsg, "����:ƾ֤����ڼ�¼��ͻ");
			break;
		case	32010	:
			strcpy(errmsg, "����:�ö�ƾ֤�ʺŲ�һ��");
			break;
		case	32011	:
			strcpy(errmsg, "����:��Ҫƾ֤���ֺ�");
			break;
		case	32012	:
			strcpy(errmsg, "����:���ʺ��޴�ƾ֤");
			break;
		case	32013	:
			strcpy(errmsg, "����:������Ա�޴�ƾ֤");
			break;
		case	32014	:
			strcpy(errmsg, "����:��ƾ֤��δʹ��");
			break;
		case	32015	:
			strcpy(errmsg, "����:�м۵�֤�Ƿ�");
			break;
		case	32016	:
			strcpy(errmsg, "����:�м۵�֤������������������");
			break;
		case	32017	:
			strcpy(errmsg, "����:��Ʊ��ǩ������ȷ");
			break;
		case	32018	:
			strcpy(errmsg, "����:��Ʊ���ѹ�ʧ");
			break;
		case	32019	:
			strcpy(errmsg, "����:��Ʊ�ݱ�Ų�����");
			break;
		case	32020	:
			strcpy(errmsg, "����:��Ʊ�ݱ��δʹ��");
			break;
		case	32021	:
			strcpy(errmsg, "����:��Ʊ���ѳ�������");
			break;
		case	32022	:
			strcpy(errmsg, "����:Ʊ�ݽ�ͬ");
			break;
		case	32023	:
			strcpy(errmsg, "����:Ʊ�ݺ��벻ͬ");
			break;
		case	32024	:
			strcpy(errmsg, "����:Ʊ�����಻ͬ");
			break;
		case	32025	:
			strcpy(errmsg, "����:�����۲�δ��ʧ");
			break;
		case	32026	:
			strcpy(errmsg, "����:���Ȳ��Ǵ���");
			break;
		case	32027	:
			strcpy(errmsg, "����:�浥/���ۺŲ���");
			break;
		case	32028	:
			strcpy(errmsg, "����:��Ʊ�ݱ����ʹ��");
			break;
		case	32029	:
			strcpy(errmsg, "����:ƾ֤�����д�");
			break;
		case	32030	:
			strcpy(errmsg, "����:���ʺ��޴�ƾ֤��");
			break;
		case	32031	:
			strcpy(errmsg, "����:��ƾ֤δʹ��");
			break;
		case	32032	:
			strcpy(errmsg, "����:��ƾ֤״̬��");
			break;
		case	32033	:
			strcpy(errmsg, "����:��ƾ֤���ʹ�");
			break;
		case	32034	:
			strcpy(errmsg, "����:ƾ֤�����ǰ��̨��һ��");
			break;
		case	32035	:
			strcpy(errmsg, "����:Errorinsertcert_certusedtl");
			break;
		case	32036	:
			strcpy(errmsg, "����:ƾ֤���ڲ���");
			break;
		case	32037	:
			strcpy(errmsg, "����:ƾ֤���ڲ���");
			break;
		case	32038	:
			strcpy(errmsg, "����:�Ƿ������Ʊ��ͬ");
			break;
		case	32039	:
			strcpy(errmsg, "����:��Ʊ�ݱ��������Ӧ�ʺ�");
			break;
		case	32040	:
			strcpy(errmsg, "����:Ʊ��ҵ�񸴺˺����Ĩ��");
			break;
		case	32041	:
			strcpy(errmsg, "����:��Ʊ��Ѻ�����");
			break;
		case	32042	:
			strcpy(errmsg, "����:�����Ա���ܸ����Լ�����");
			break;
		case	32043	:
			strcpy(errmsg, "����:ƾ֤��ʹ����ϸ�����ڻ�״̬��");
			break;
		case	32044	:
			strcpy(errmsg, "����:��ƾ֤���غ�");
			break;
		case	32045	:
			strcpy(errmsg, "����:��Ʊ�����಻�ܲ���");
			break;
		case	32046	:
			strcpy(errmsg, "����:��ƾ֤������");
			break;
		case	40001	:
			strcpy(errmsg, "����:�ֻ��ʴ�");
			break;
		case	40002	:
			strcpy(errmsg, "����:�ʺŴ�");
			break;
		case	40003	:
			strcpy(errmsg, "����:�޴��ʻ�");
			break;
		case	40004	:
			strcpy(errmsg, "����:�޴˾��ʺ�");
			break;
		case	40005	:
			strcpy(errmsg, "����:д�ֻ��ʳ���");
			break;
		case	40006	:
			strcpy(errmsg, "����:���ʺų���");
			break;
		case	40007	:
			strcpy(errmsg, "����:���ʺ��Ѵ���");
			break;
		case	40008	:
			strcpy(errmsg, "����:���ڷ��������ķֻ���");
			break;
		case	40009	:
			strcpy(errmsg, "����:�ʺŲ�����");
			break;
		case	40010	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	40011	:
			strcpy(errmsg, "����:����ʺŴ�");
			break;
		case	40012	:
			strcpy(errmsg, "����:��֤���ʺŴ�");
			break;
		case	40013	:
			strcpy(errmsg, "����:Ͷ���ʺŴ�");
			break;
		case	40014	:
			strcpy(errmsg, "����:Ӧ����Ϣ�ʺŴ�");
			break;
		case	40015	:
			strcpy(errmsg, "����:����Ӧ�տ��ʺŴ�");
			break;
		case	40016	:
			strcpy(errmsg, "����:�Է��ʺŴ�");
			break;
		case	40017	:
			strcpy(errmsg, "����:�ʺ�1��");
			break;
		case	40018	:
			strcpy(errmsg, "����:�ʺ�2��");
			break;
		case	40019	:
			strcpy(errmsg, "����:ǷϢ��Ƭ��");
			break;
		case	40101	:
			strcpy(errmsg, "����:�ʻ��Ѿ�����");
			break;
		case	40102	:
			strcpy(errmsg, "����:û�д����ʺ�");
			break;
		case	40103	:
			strcpy(errmsg, "����:���ʻ�����������ȡ������");
			break;
		case	40104	:
			strcpy(errmsg, "����:�ÿͻ��������ʻ�δ����");
			break;
		case	40105	:
			strcpy(errmsg, "����:�ʻ�δ����");
			break;
		case	40106	:
			strcpy(errmsg, "����:���ʻ����ֶ���");
			break;
		case	40107	:
			strcpy(errmsg, "����:���ʻ�ȫ������");
			break;
		case	40108	:
			strcpy(errmsg, "����:�ʻ��Ѿ�����");
			break;
		case	40109	:
			strcpy(errmsg, "����:�ʻ��Ѿ��ݷ�");
			break;
		case	40110	:
			strcpy(errmsg, "����:�ʻ��ѵ���");
			break;
		case	40111	:
			strcpy(errmsg, "����:���ʻ�Ԥ��");
			break;
		case	40112	:
			strcpy(errmsg, "����:�ʻ��Ѿ���ʧ");
			break;
		case	40113	:
			strcpy(errmsg, "����:�ʻ�δ��ʧ");
			break;
		case	40114	:
			strcpy(errmsg, "����:�����ԭ�������ʻ����벻һ��");
			break;
		case	40115	:
			strcpy(errmsg, "����:�ʻ����ʷǴ��");
			break;
		case	40116	:
			strcpy(errmsg, "����:�ʻ����ֻ㻧");
			break;
		case	40117	:
			strcpy(errmsg, "����:�ʻ����ʴ�");
			break;
		case	40118	:
			strcpy(errmsg, "����:�ʻ����ʹ�");
			break;
		case	40119	:
			strcpy(errmsg, "����:�ʻ�״̬��");
			break;
		case	40120	:
			strcpy(errmsg, "����:���ʻ���ʹ�ô���");
			break;
		case	40121	:
			strcpy(errmsg, "����:�ʻ�����");
			break;
		case	40122	:
			strcpy(errmsg, "����:�޴˽��㻧�ʺ�");
			break;
		case	40123	:
			strcpy(errmsg, "����:���㻧�Ѷ���");
			break;
		case	40124	:
			strcpy(errmsg, "����:���㻧�ʻ����ʴ���");
			break;
		case	40125	:
			strcpy(errmsg, "����:���㻧״̬����");
			break;
		case	40126	:
			strcpy(errmsg, "����:���㻧����");
			break;
		case	40127	:
			strcpy(errmsg, "����:���㻧�ʻ����Ͳ���");
			break;
		case	40128	:
			strcpy(errmsg, "����:���㻧�ʺŲ�ͬ");
			break;
		case	40129	:
			strcpy(errmsg, "����:���㻧�ʺ�����Ƭ����Ϣ�ʺŲ�ͬ");
			break;
		case	40130	:
			strcpy(errmsg, "����:���㻧�ʺ����Զ���Ʒ�¼���в�ͬ");
			break;
		case	40131	:
			strcpy(errmsg, "����:�ڲ��ʻ������");
			break;
		case	40132	:
			strcpy(errmsg, "����:��֤���ʺŲ�ͬ");
			break;
		case	40133	:
			strcpy(errmsg, "����:�м��ʺŲ�ͬ");
			break;
		case	40134	:
			strcpy(errmsg, "����:��Ϣ�ʺŲ�ͬ");
			break;
		case	40135	:
			strcpy(errmsg, "����:ȡ�����ʺ�˳��ű��");
			break;
		case	40136	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	40137	:
			strcpy(errmsg, "����:�ÿͻ����ѿ����");
			break;
		case	40138	:
			strcpy(errmsg, "����:�û�ΪЭ����");
			break;
		case	40139	:
			strcpy(errmsg, "����:�û���Ӧ���δ����");
			break;
		case	40140	:
			strcpy(errmsg, "����:�û�͸֧��������");
			break;
		case	40141	:
			strcpy(errmsg, "����:�û���δ�������гжһ�Ʊ��������");
			break;
		case	40142	:
			strcpy(errmsg, "����:�û���δ�������ճи�Ʊ�ݲ�������");
			break;
		case	40143	:
			strcpy(errmsg, "����:�û���δ���׽���Ʊ�ݲ�������");
			break;
		case	40144	:
			strcpy(errmsg, "����:�ǻ��ڻ�����");
			break;
		case	40145	:
			strcpy(errmsg, "����:Э������¼�Ѵ���");
			break;
		case	40146	:
			strcpy(errmsg, "����:Э������¼������");
			break;
		case	40147	:
			strcpy(errmsg, "����:��ѯ����Ϊ��");
			break;
		case	40148	:
			strcpy(errmsg, "����:��Ʊ��ϸ���޴˼�¼");
			break;
		case	40149	:
			strcpy(errmsg, "����:�жһ�Ʊ��ϸ���޴˼�¼");
			break;
		case	40150	:
			strcpy(errmsg, "����:��Ʊ��ϸ���޴˼�¼");
			break;
		case	40151	:
			strcpy(errmsg, "����:֧Ʊ��ϸ���޴˼�¼");
			break;
		case	40152	:
			strcpy(errmsg, "����:��ʧ��־״̬��");
			break;
		case	40153	:
			strcpy(errmsg, "����:�ʻ����С�ڶ�����");
			break;
		case	40154	:
			strcpy(errmsg, "����:���ɶ���ҵ���Ŵ�");
			break;
		case	40155	:
			strcpy(errmsg, "����:����Ǽǲ�����Ӧ��¼");
			break;
		case	40156	:
			strcpy(errmsg, "����:�����ݷ��־״̬��");
			break;
		case	40157	:
			strcpy(errmsg, "����:ͬ���������ʺ��Ѵ���");
			break;
		case	40158	:
			strcpy(errmsg, "����:ȡ���㽻���Ŵ�");
			break;
		case	40162	:
			strcpy(errmsg, "����:�޴��������ʺ�");
			break;
		case	40163	:
			strcpy(errmsg, "����:�����ѻ�״̬����");
			break;
		case	40164	:
			strcpy(errmsg, "����:˳��Ŵ�");
			break;
		case	40165	:
			strcpy(errmsg, "����:˳����Ѵ���");
			break;
		case	40166	:
			strcpy(errmsg, "����:�û���Ӧ���δ����");
			break;
		case	40167	:
			strcpy(errmsg, "����:д�¾��ʺŶ��ձ��");
			break;
		case	40168	:
			strcpy(errmsg, "����:�޴˼�Ϣ�ʺ�");
			break;
		case	40169	:
			strcpy(errmsg, "����:��Ϣ�ʺ�״̬��");
			break;
		case	40170	:
			strcpy(errmsg, "����:��Ϣ�ʺ����ʴ�");
			break;
		case	40171	:
			strcpy(errmsg, "����:��Ϣ�ʺſͻ��Ŵ�");
			break;
		case	40172	:
			strcpy(errmsg, "����:��Ϣ�ʺű��ִ�");
			break;
		case	40173	:
			strcpy(errmsg, "����:�޴˸����ʺ�");
			break;
		case	40174	:
			strcpy(errmsg, "����:�޴��տ��ʺ�");
			break;
		case	40175	:
			strcpy(errmsg, "����:�ִθ�����������ԭǩ�����");
			break;
		case	40176	:
			strcpy(errmsg, "����:�ִθ��������");
			break;
		case	40177	:
			strcpy(errmsg, "����:�и����ʹ�");
			break;
		case	40178	:
			strcpy(errmsg, "����:�޸����շִθ�����ϸ���");
			break;
		case	40179	:
			strcpy(errmsg, "����:��ʧ���������ظ�");
			break;
		case	40180	:
			strcpy(errmsg, "����:��Ʊ״̬��");
			break;
		case	40181	:
			strcpy(errmsg, "����:��˳��Ŵ�");
			break;
		case	40182	:
			strcpy(errmsg, "����:�������ͻ��Ų���");
			break;
		case	40183	:
			strcpy(errmsg, "����:�û���δ�������л�Ʊ");
			break;
		case	40184	:
			strcpy(errmsg, "����:���ʺ�����δ���˵Ľ���");
			break;
		case	40201	:
			strcpy(errmsg, "����:�޸Ľ����Զ����ʵǼǱ��");
			break;
		case	40202	:
			strcpy(errmsg, "����:�Ǽǽ����Զ����ʵǼǱ��");
			break;
		case	40203	:
			strcpy(errmsg, "����:�Ǽ�ת�ʽ�����ˮ���");
			break;
		case	40204	:
			strcpy(errmsg, "����:�޸�ת�ʽ�����ˮ���");
			break;
		case	40205	:
			strcpy(errmsg, "����:�ǼǷ������״�");
			break;
		case	40206	:
			strcpy(errmsg, "����:�Ǽ����ʼ�¼��");
			break;
		case	40207	:
			strcpy(errmsg, "����:�޸����ʼ�¼��");
			break;
		case	40208	:
			strcpy(errmsg, "����:���ʽ���");
			break;
		case	40209	:
			strcpy(errmsg, "����:�޸Ŀ�Ƭ�ʴ�");
			break;
		case	40210	:
			strcpy(errmsg, "����:����Ƭ�ʳ���");
			break;
		case	40211	:
			strcpy(errmsg, "����:�Ǽǿ�Ƭ�ʴ�");
			break;
		case	40212	:
			strcpy(errmsg, "����:���������ڿ�Ƭ�����ϴν�����");
			break;
		case	40213	:
			strcpy(errmsg, "����:�岹�������ڽ�����");
			break;
		case	40214	:
			strcpy(errmsg, "����:���ʼ�¼���ʺŷǷ�");
			break;
		case	40215	:
			strcpy(errmsg, "����:���ʼ�¼������");
			break;
		case	40219	:
			strcpy(errmsg, "����:�������δ�");
			break;
		case	40220	:
			strcpy(errmsg, "����:֧Ʊ����");
			break;
		case	40221	:
			strcpy(errmsg, "����:Զ��֧Ʊ");
			break;
		case	40222	:
			strcpy(errmsg, "����:��������״̬���ô�");
			break;
		case	40223	:
			strcpy(errmsg, "����:�Է����μӸó�����");
			break;
		case	40224	:
			strcpy(errmsg, "����:�Ѿ������������ݲ������޸�");
			break;
		case	40225	:
			strcpy(errmsg, "����:�ҷ����μӸó�����");
			break;
		case	40226	:
			strcpy(errmsg, "����:�Ǽ�Ӧ�տ�����");
			break;
		case	40227	:
			strcpy(errmsg, "����:�Ǽ�Ӧ��Ӧ���ǼǱ��");
			break;
		case	40228	:
			strcpy(errmsg, "����:��Ӧ�տ���û��");
			break;
		case	40301	:
			strcpy(errmsg, "����:��Ƭ״̬��");
			break;
		case	40302	:
			strcpy(errmsg, "����:��Ƭ����ظ�");
			break;
		case	40303	:
			strcpy(errmsg, "����:��Ƭ��û�����������ļ�¼");
			break;
		case	40304	:
			strcpy(errmsg, "����:��Ʊ�ݿ�Ƭ������");
			break;
		case	40305	:
			strcpy(errmsg, "����:������С�ڿ�Ƭ������");
			break;
		case	40306	:
			strcpy(errmsg, "����:�ñ���ϸ��ǷϢ��Ƭ");
			break;
		case	40307	:
			strcpy(errmsg, "����:ǷϢ��Ƭ��־��1321");
			break;
		case	40308	:
			strcpy(errmsg, "����:��Ƭ�����ڷ�����");
			break;
		case	40309	:
			strcpy(errmsg, "����:���±�֤����");
			break;
		case	40310	:
			strcpy(errmsg, "����:��֤��Ƭ����");
			break;
		case	40311	:
			strcpy(errmsg, "����:��֤��Ƭ������");
			break;
		case	40312	:
			strcpy(errmsg, "����:Ͷ������");
			break;
		case	40313	:
			strcpy(errmsg, "����:����������");
			break;
		case	40314	:
			strcpy(errmsg, "����:������ʹ�");
			break;
		case	40315	:
			strcpy(errmsg, "����:�Ǵ��ʴ���");
			break;
		case	40316	:
			strcpy(errmsg, "����:�ñʷǻ���");
			break;
		case	40317	:
			strcpy(errmsg, "����:ǷϢ��Ƭ������");
			break;
		case	40318	:
			strcpy(errmsg, "����:����ȫΪ�����ʺ�");
			break;
		case	40319	:
			strcpy(errmsg, "����:��Ʊ�ݿ�Ƭ�Ѳ�����");
			break;
		case	40320	:
			strcpy(errmsg, "����:д�����");
			break;
		case	40321	:
			strcpy(errmsg, "����:д��ˮ���");
			break;
		case	40322	:
			strcpy(errmsg, "����:���Ŵ���Ϣ�����");
			break;
		case	40323	:
			strcpy(errmsg, "����:���������������");
			break;
		case	40324	:
			strcpy(errmsg, "����:��ͬ�Ų���");
			break;
		case	40325	:
			strcpy(errmsg, "����:���׶����ʺŲ���");
			break;
		case	40326	:
			strcpy(errmsg, "����:����");
			break;
		case	40327	:
			strcpy(errmsg, "����:���ʲ���");
			break;
		case	40328	:
			strcpy(errmsg, "����:�����ղ���");
			break;
		case	40329	:
			strcpy(errmsg, "����:�����ʺŲ���");
			break;
		case	40330	:
			strcpy(errmsg, "����:ͳ�Ʊ��벻��");
			break;
		case	40331	:
			strcpy(errmsg, "����:�ñʽ����Ѹ���");
			break;
		case	40332	:
			strcpy(errmsg, "����:д��軹����ϸ���");
			break;
		case	40333	:
			strcpy(errmsg, "����:�����ղ���Ϊ����");
			break;
		case	40334	:
			strcpy(errmsg, "����:�����Ų���");
			break;
		case	40335	:
			strcpy(errmsg, "����:�ñ�ҵ��δ���˲���չ��");
			break;
		case	40336	:
			strcpy(errmsg, "����:��Ϣ�ղ���");
			break;
		case	40337	:
			strcpy(errmsg, "����:��Ϣ����");
			break;
		case	40338	:
			strcpy(errmsg, "����:�ձ����кŲ���");
			break;
		case	40339	:
			strcpy(errmsg, "����:�ñ�ҵ���ѽ���");
			break;
		case	40340	:
			strcpy(errmsg, "����:�ñ�ҵ��δ���˲��ܻ���");
			break;
		case	40341	:
			strcpy(errmsg, "����:չ�ڽ���");
			break;
		case	40342	:
			strcpy(errmsg, "����:ͳ�Ʊ������");
			break;
		case	40343	:
			strcpy(errmsg, "����:������������");
			break;
		case	40344	:
			strcpy(errmsg, "����:�ñ�ҵ���ѻ����չ��");
			break;
		case	40345	:
			strcpy(errmsg, "����:ת��·�ߴ�");
			break;
		case	40346	:
			strcpy(errmsg, "����:��ˮ�����޼�¼");
			break;
		case	40347	:
			strcpy(errmsg, "����:�޸���Ҷһ���ˮ���");
			break;
		case	40348	:
			strcpy(errmsg, "����:�޸ı�֤����ϸ�����");
			break;
		case	40349	:
			strcpy(errmsg, "����:�ǼǱ�֤��ʹ����ϸ�����");
			break;
		case	40350	:
			strcpy(errmsg, "����:�ǼǺ�̨��֤������ˮ�����");
			break;
		case	40351	:
			strcpy(errmsg, "����:�޸�Ͷ����ϸ�����");
			break;
		case	40352	:
			strcpy(errmsg, "����:�Ǽ�Ͷ��ʹ����ϸ�����");
			break;
		case	40353	:
			strcpy(errmsg, "����:�ǼǺ�̨Ͷ�ʽ�����ˮ�����");
			break;
		case	40354	:
			strcpy(errmsg, "����:�޸�ͬҵ����������ˮ�����");
			break;
		case	40355	:
			strcpy(errmsg, "����:ɾ�������Ϣ���");
			break;
		case	40356	:
			strcpy(errmsg, "����:����Ա�븴��Ա��ͬ");
			break;
		case	40357	:
			strcpy(errmsg, "����:ͬҵ�ʺŻ��Ҳ���");
			break;
		case	40358	:
			strcpy(errmsg, "����:�ÿ�Ƭ�ѽ���");
			break;
		case	40359	:
			strcpy(errmsg, "����:�ÿ�Ƭ�Ѻ���");
			break;
		case	40360	:
			strcpy(errmsg, "����:ͬһ�ʲ��ͬһ�첻�ܻ����");
			break;
		case	40361	:
			strcpy(errmsg, "����:��֤��״̬��");
			break;
		case	40362	:
			strcpy(errmsg, "����:��֤����");
			break;
		case	40363	:
			strcpy(errmsg, "����:���㻧�ͻ����뱣֤���ʺſͻ��Ų�ͬ");
			break;
		case	40364	:
			strcpy(errmsg, "����:��������Ѹ���ԭ���ս��");
			break;
		case	40365	:
			strcpy(errmsg, "����:��ҵ����ʹ�øñʱ�֤��");
			break;
		case	40366	:
			strcpy(errmsg, "����:�ñ�ҵ�񲻴���");
			break;
		case	40367	:
			strcpy(errmsg, "����:������ó���");
			break;
		case	40368	:
			strcpy(errmsg, "����:����˰�����");
			break;
		case	40369	:
			strcpy(errmsg, "����:�������׼�������");
			break;
		case	40370	:
			strcpy(errmsg, "����:���ỵ��׼�������");
			break;
		case	40371	:
			strcpy(errmsg, "����:����Ͷ�ʷ���׼�������");
			break;
		case	40372	:
			strcpy(errmsg, "����:��Ϣ��Ƭ״̬��");
			break;
		case	40373	:
			strcpy(errmsg, "����:��ӦǷϢ��Ƭ״̬��");
			break;
		case	40374	:
			strcpy(errmsg, "����:������Ƭ������");
			break;
		case	40375	:
			strcpy(errmsg, "����:ͬһ��ֻ���Լ���һ��");
			break;
		case	40376	:
			strcpy(errmsg, "����:��跶Χ����");
			break;
		case	40377	:
			strcpy(errmsg, "����:���վ��㽻��˳�򲻶�");
			break;
		case	40378	:
			strcpy(errmsg, "����:�����վ��㽻��˳�����");
			break;
		case	40379	:
			strcpy(errmsg, "����:�ñʱ�֤����ʹ�ò���Ĩ��");
			break;
		case	40380	:
			strcpy(errmsg, "����:������Ƭ���ɴ�");
			break;
		case	40381	:
			strcpy(errmsg, "����:���ʺ��Ǳ�֤���Ϣ�ʺ��ұ�֤��״̬��");
			break;
		case	40401	:
			strcpy(errmsg, "����:�û�Ϊ���ڲ�����");
			break;
		case	40402	:
			strcpy(errmsg, "����:�û�����Ѻ�����");
			break;
		case	40403	:
			strcpy(errmsg, "����:�û�������ԭ�򶳽�");
			break;
		case	40404	:
			strcpy(errmsg, "����:�浥ֻ������");
			break;
		case	40405	:
			strcpy(errmsg, "����:����һ��ͨ�������ײ�����ȡ��");
			break;
		case	40406	:
			strcpy(errmsg, "����:�汾ȡϢ�ѵ���Ӧ����������");
			break;
		case	40407	:
			strcpy(errmsg, "����:��ҵ��Ӧ�ڿ����а���");
			break;
		case	40408	:
			strcpy(errmsg, "����:�û��Ѿ�������ǰ֧ȡ");
			break;
		case	40409	:
			strcpy(errmsg, "����:��ѯ�������ļ�����");
			break;
		case	40410	:
			strcpy(errmsg, "����:���ʺ�û��Ԥ����Ϣ");
			break;
		case	40411	:
			strcpy(errmsg, "����:���ʺ���Ԥ����Ϣ");
			break;
		case	40412	:
			strcpy(errmsg, "����:����ʺ��ѹر�");
			break;
		case	40413	:
			strcpy(errmsg, "����:��ҵ�����ھ����а���");
			break;
		case	40501	:
			strcpy(errmsg, "����:��Ʊ�����");
			break;
		case	40502	:
			strcpy(errmsg, "����:�޴˻�Ʊ�жһ��ʺ�");
			break;
		case	40503	:
			strcpy(errmsg, "����:��Ʊ�жһ��ʻ��Ѷ���");
			break;
		case	40504	:
			strcpy(errmsg, "����:��Ʊ�жһ��ʻ����ʴ�");
			break;
		case	40505	:
			strcpy(errmsg, "����:��Ʊ�жһ��ʻ�״̬��");
			break;
		case	40506	:
			strcpy(errmsg, "����:��Ʊ�жһ��ʻ�����");
			break;
		case	40601	:
			strcpy(errmsg, "����:�����˶Բ���");
			break;
		case	40602	:
			strcpy(errmsg, "����:������������");
			break;
		case	40603	:
			strcpy(errmsg, "����:������������");
			break;
		case	40604	:
			strcpy(errmsg, "����:������������С�ڿ�����");
			break;
		case	40701	:
			strcpy(errmsg, "����:�޸ı�Ʊ��ϸ���");
			break;
		case	40702	:
			strcpy(errmsg, "����:�ǼǱ�Ʊ��ϸ���");
			break;
		case	40703	:
			strcpy(errmsg, "����:�޸ĳжһ�Ʊ��ϸ���");
			break;
		case	40704	:
			strcpy(errmsg, "����:�Ǽǳжһ�Ʊ��ϸ���");
			break;
		case	40705	:
			strcpy(errmsg, "����:��������Ļ�Ʊ��Ϣ����");
			break;
		case	40706	:
			strcpy(errmsg, "����:�޸Ļ�Ʊ��ϸ���");
			break;
		case	40707	:
			strcpy(errmsg, "����:�Ǽǻ�Ʊ��ϸ���");
			break;
		case	40708	:
			strcpy(errmsg, "����:�޸Ľ���������ˮ���");
			break;
		case	40709	:
			strcpy(errmsg, "����:�Ǽǽ���������ˮ���");
			break;
		case	40710	:
			strcpy(errmsg, "����:�޸Ľ����ǼǱ��");
			break;
		case	40711	:
			strcpy(errmsg, "����:�Ǽǽ����ǼǱ��");
			break;
		case	40712	:
			strcpy(errmsg, "����:�޸����ճи���ˮ���");
			break;
		case	40713	:
			strcpy(errmsg, "����:�Ǽ����ճи���ˮ���");
			break;
		case	40714	:
			strcpy(errmsg, "����:�޸����ճи���ϸ���");
			break;
		case	40715	:
			strcpy(errmsg, "����:�Ǽ����ճи���ϸ���");
			break;
		case	40716	:
			strcpy(errmsg, "����:�޸�֧Ʊ��ϸ���");
			break;
		case	40717	:
			strcpy(errmsg, "����:�Ǽ�֧Ʊ��ϸ���");
			break;
		case	40718	:
			strcpy(errmsg, "����:ƾ֤������");
			break;
		case	40719	:
			strcpy(errmsg, "����:֧Ʊ������");
			break;
		case	40720	:
			strcpy(errmsg, "����:�޸�ǩƱ��ˮ���");
			break;
		case	40721	:
			strcpy(errmsg, "����:�Ǽ�ǩƱ��ˮ���");
			break;
		case	40722	:
			strcpy(errmsg, "����:�޸Ķ��ڽ�����ˮ���");
			break;
		case	40723	:
			strcpy(errmsg, "����:�ǼǶ��ڽ�����ˮ���");
			break;
		case	40724	:
			strcpy(errmsg, "����:�޸Ķ�����ϸ���");
			break;
		case	40725	:
			strcpy(errmsg, "����:�ǼǶ�����ϸ���");
			break;
		case	40726	:
			strcpy(errmsg, "����:�����ڴ���δ����������ɴ��ۺ�");
			break;
		case	40727	:
			strcpy(errmsg, "����:�����ڴ����Ѵ����������´��ۺ�");
			break;
		case	40728	:
			strcpy(errmsg, "����:�Ǽ�ǰ̨����������ˮ���");
			break;
		case	40729	:
			strcpy(errmsg, "����:�Ǽ�ǰ̨���ճи���ˮ���");
			break;
		case	40730	:
			strcpy(errmsg, "����:�Ǽ�ǰ̨ǩƱ��ˮ���");
			break;
		case	40731	:
			strcpy(errmsg, "����:�ǼǶ��ڽ�����ˮ���");
			break;
		case	40732	:
			strcpy(errmsg, "����:�ǼǶ�����ϸ���");
			break;
		case	40733	:
			strcpy(errmsg, "����:�޸����н�����ˮ���");
			break;
		case	40734	:
			strcpy(errmsg, "����:�Ǽ����н�����ˮ���");
			break;
		case	40735	:
			strcpy(errmsg, "����:�޸����н�����ϸ���");
			break;
		case	40736	:
			strcpy(errmsg, "����:�Ǽ����н�����ϸ���");
			break;
		case	40737	:
			strcpy(errmsg, "����:�û����Ƕ��ڴ��");
			break;
		case	40738	:
			strcpy(errmsg, "����:�ö��ڻ��Ѳ����");
			break;
		case	40739	:
			strcpy(errmsg, "����:�ö��ڻ��ѽ����");
			break;
		case	40740	:
			strcpy(errmsg, "����:�ö��ڻ�ĩ�����ޣ����ܽ���");
			break;
		case	40741	:
			strcpy(errmsg, "����:�ö��ڴ浥�ѹ�ʧ");
			break;
		case	40742	:
			strcpy(errmsg, "����:�ö��ڴ浥�Ѷ���");
			break;
		case	40743	:
			strcpy(errmsg, "����:�ö��ڻ����ݷ�");
			break;
		case	40744	:
			strcpy(errmsg, "����:���ڿ�Ƭ�����֧ȡ����");
			break;
		case	40745	:
			strcpy(errmsg, "����:�û����Ƕ��������");
			break;
		case	40746	:
			strcpy(errmsg, "����:֧����ʽ��");
			break;
		case	40747	:
			strcpy(errmsg, "����:֪֧ͨȡ��С��֪ͨ����");
			break;
		case	40748	:
			strcpy(errmsg, "����:ȡ�����ۻ�����֪ͨ�����");
			break;
		case	40749	:
			strcpy(errmsg, "����:�޶�Ӧ��֪ͨ��Ƭ");
			break;
		case	40750	:
			strcpy(errmsg, "����:���С�ڴ����ʼ���");
			break;
		case	40751	:
			strcpy(errmsg, "����:ȡ����Ӧ��������֪ͨȡ����");
			break;
		case	40752	:
			strcpy(errmsg, "����:���ڻ������ѡ���");
			break;
		case	40753	:
			strcpy(errmsg, "����:�������޴�");
			break;
		case	40754	:
			strcpy(errmsg, "����:��֪ͨ������һ��ȡ��");
			break;
		case	40755	:
			strcpy(errmsg, "����:�ô�����һ��ȡ��");
			break;
		case	40756	:
			strcpy(errmsg, "����:�ö��ڴ浥����Ѻ");
			break;
		case	40757	:
			strcpy(errmsg, "����:�ö���֪ͨ��û�н���");
			break;
		case	40758	:
			strcpy(errmsg, "����:�û���Ӧ����֪ͨ��û�н���");
			break;
		case	40759	:
			strcpy(errmsg, "����:�û���δ���屾Ʊ");
			break;
		case	40760	:
			strcpy(errmsg, "����:��Ϣ��С����һ�μ�����");
			break;
		case	40761	:
			strcpy(errmsg, "����:�ö��ڴ浥û����Ѻ");
			break;
		case	40801	:
			strcpy(errmsg, "����:����Э�������");
			break;
		case	40802	:
			strcpy(errmsg, "����:���¶��ڴ����");
			break;
		case	40803	:
			strcpy(errmsg, "����:����������ѳ���");
			break;
		case	40804	:
			strcpy(errmsg, "����:���������");
			break;
		case	40805	:
			strcpy(errmsg, "����:�ѳ������ڲ���������");
			break;
		case	40806	:
			strcpy(errmsg, "����:�汾ȡϢ��������֧ȡ");
			break;
		case	40807	:
			strcpy(errmsg, "����:�汾ȡϢ�����ڲ�Ӧ��0");
			break;
		case	40808	:
			strcpy(errmsg, "����:�汾ȡϢδȡ���ϴ�ȡϢ��");
			break;
		case	40809	:
			strcpy(errmsg, "����:�汾ȡϢ����ֻ�������ǰһ��");
			break;
		case	41001	:
			strcpy(errmsg, "����:�������ע��");
			break;
		case	41002	:
			strcpy(errmsg, "����:����Ų�����");
			break;
		case	41003	:
			strcpy(errmsg, "����:ȡ����Ŵ�");
			break;
		case	41004	:
			strcpy(errmsg, "����:���ת������");
			break;
		case	41005	:
			strcpy(errmsg, "����:���ҵ����Ŵ�");
			break;
		case	41006	:
			strcpy(errmsg, "����:���ҵ�����ʹ�");
			break;
		case	41007	:
			strcpy(errmsg, "����:���Ǽǿ�״̬��");
			break;
		case	41008	:
			strcpy(errmsg, "����:�Ǽ����ҵ���ű��");
			break;
		case	41009	:
			strcpy(errmsg, "����:�Ǽ����ǼǱ��");
			break;
		case	41010	:
			strcpy(errmsg, "����:����֤�ѳ���");
			break;
		case	41011	:
			strcpy(errmsg, "����:����֤δ����");
			break;
		case	41012	:
			strcpy(errmsg, "����:�Ǽ������֤");
			break;
		case	41013	:
			strcpy(errmsg, "����:�һ���");
			break;
		case	41014	:
			strcpy(errmsg, "����:��̨�������");
			break;
		case	41015	:
			strcpy(errmsg, "����:��̨��������ǰ̨����");
			break;
		case	41016	:
			strcpy(errmsg, "����:���������ʺŴ�");
			break;
		case	41017	:
			strcpy(errmsg, "����:�������ʺ�״̬��");
			break;
		case	41018	:
			strcpy(errmsg, "����:�������ʺ�����");
			break;
		case	41019	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	41020	:
			strcpy(errmsg, "����:�����ʺ�״̬��");
			break;
		case	41021	:
			strcpy(errmsg, "����:�����ʺ�֧��������");
			break;
		case	41022	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	41023	:
			strcpy(errmsg, "����:�����ʺ�״̬��");
			break;
		case	41024	:
			strcpy(errmsg, "����:�����ʺŻ��Ҳ���");
			break;
		case	41025	:
			strcpy(errmsg, "����:�������ʺŻ��Ҳ���");
			break;
		case	41026	:
			strcpy(errmsg, "����:�����ʺŻ��Ҳ���");
			break;
		case	41027	:
			strcpy(errmsg, "����:�����ʺŻ��Ҵ�");
			break;
		case	41028	:
			strcpy(errmsg, "����:���ҵ�����Ѵ���");
			break;
		case	41029	:
			strcpy(errmsg, "����:�˱�Ӷ�ʺŴ�");
			break;
		case	41030	:
			strcpy(errmsg, "����:�˱�Ӷ�ʺ�����ֲ���");
			break;
		case	41031	:
			strcpy(errmsg, "����:����֤��ת��");
			break;
		case	41032	:
			strcpy(errmsg, "����:ԭ����֤֪ͨ��Ŵ�");
			break;
		case	41033	:
			strcpy(errmsg, "����:�����ұ��");
			break;
		case	41034	:
			strcpy(errmsg, "����:�ñ����Ч");
			break;
		case	41035	:
			strcpy(errmsg, "����:�ñ�ҵ�����˻�");
			break;
		case	41036	:
			strcpy(errmsg, "����:�ñ�ҵ������Ʊ(��)");
			break;
		case	41037	:
			strcpy(errmsg, "����:�ñ�ҵ�����ջ�");
			break;
		case	41038	:
			strcpy(errmsg, "����:�ñ�ҵ����ȫ��ת��");
			break;
		case	41039	:
			strcpy(errmsg, "����:�ñ�ҵ���Ѹ���");
			break;
		case	41040	:
			strcpy(errmsg, "����:�ñ�ҵ���ѳ�֤");
			break;
		case	41041	:
			strcpy(errmsg, "����:�ñ�ҵ��δ�ջ�");
			break;
		case	41042	:
			strcpy(errmsg, "����:�շѽ��>��λ���ʽ��");
			break;
		case	41043	:
			strcpy(errmsg, "����:�շѽ��>�ջ���");
			break;
		case	41044	:
			strcpy(errmsg, "����:�ۿ���>ԭ���");
			break;
		case	41045	:
			strcpy(errmsg, "����:����֤�ѽ���");
			break;
		case	41046	:
			strcpy(errmsg, "����:�����ҵ�����ظ�");
			break;
		case	41047	:
			strcpy(errmsg, "����:����:���������ظ�¼��");
			break;
		case	41048	:
			strcpy(errmsg, "����:�տ�����������ַ����");
			break;
		case	41049	:
			strcpy(errmsg, "����:�տ�����ݼ��绰����");
			break;
		case	41050	:
			strcpy(errmsg, "����:���ʻ������ջ���ֲ���");
			break;
		case	41051	:
			strcpy(errmsg, "����:���������ѽ⸶");
			break;
		case	41052	:
			strcpy(errmsg, "����:�Ƽ۱�״̬��");
			break;
		case	41053	:
			strcpy(errmsg, "����:���»��ұ��");
			break;
		case	41054	:
			strcpy(errmsg, "����:ŷԪ�����");
			break;
		case	41055	:
			strcpy(errmsg, "����:д�һ��Ǽǲ���");
			break;
		case	41056	:
			strcpy(errmsg, "����:�ñ�ҵ�����걨");
			break;
		case	41058	:
			strcpy(errmsg, "����:�ñ�ҵ���Ѳ���ת��");
			break;
		case	41059	:
			strcpy(errmsg, "����:д�һ��Ǽǲ�ŷԪ�����");
			break;
		case	41060	:
			strcpy(errmsg, "����:�����ʺ��Ѿ�����");
			break;
		case	41061	:
			strcpy(errmsg, "����:�����ʺ�ȫ������");
			break;
		case	41062	:
			strcpy(errmsg, "����:�����ʺ���Ԥ��");
			break;
		case	41063	:
			strcpy(errmsg, "����:�����ʺ��ݷ�");
			break;
		case	41064	:
			strcpy(errmsg, "����:�������ʺ��Ѿ�����");
			break;
		case	41065	:
			strcpy(errmsg, "����:�������ʺ�ȫ������");
			break;
		case	41066	:
			strcpy(errmsg, "����:�������ʺ���Ԥ��");
			break;
		case	41067	:
			strcpy(errmsg, "����:�������ʺ��ݷ�");
			break;
		case	41068	:
			strcpy(errmsg, "����:�����ʺ��Ѿ�����");
			break;
		case	41069	:
			strcpy(errmsg, "����:�����ʺ���Ԥ��");
			break;
		case	41070	:
			strcpy(errmsg, "����:�����ʺ�Ϊ�����ʺ�");
			break;
		case	41071	:
			strcpy(errmsg, "����:�����ʺ�Ϊ�����ʺ�");
			break;
		case	41072	:
			strcpy(errmsg, "����:�������ʺ�Ϊ�����ʺ�");
			break;
		case	41073	:
			strcpy(errmsg, "����:�������ʺ�Ϊ�����ʺ�");
			break;
		case	41074	:
			strcpy(errmsg, "����:�����ʺ�Ϊ�����ʺ�");
			break;
		case	41075	:
			strcpy(errmsg, "����:�����ʺ�Ϊ�����ʺ�");
			break;
		case	41076	:
			strcpy(errmsg, "����:�ձ���������Ŵ�");
			break;
		case	41077	:
			strcpy(errmsg, "����:��/�ۻ���ƽ��");
			break;
		case	41078	:
			strcpy(errmsg, "����:Ŀǰ��û��������/�ۻ���Ժ���ƽ��");
			break;
		case	41079	:
			strcpy(errmsg, "����:����֤��ʹ����ϸ���");
			break;
		case	41080	:
			strcpy(errmsg, "����:д��֤��ʹ����ϸ���");
			break;
		case	41081	:
			strcpy(errmsg, "����:����㽻����ˮ���");
			break;
		case	41082	:
			strcpy(errmsg, "����:Ĩ��㽻����ˮ���");
			break;
		case	41083	:
			strcpy(errmsg, "����:Ĩ���Ǽǲ���");
			break;
		case	41084	:
			strcpy(errmsg, "����:�溯������������");
			break;
		case	41085	:
			strcpy(errmsg, "����:�����������");
			break;
		case	41086	:
			strcpy(errmsg, "����:��������뿨Ƭ����");
			break;
		case	41087	:
			strcpy(errmsg, "����:ȡ���п�Ŀ�Ŵ�");
			break;
		case	41088	:
			strcpy(errmsg, "����:�ý��ײ�����ŷԪ�����ҳ��׻�");
			break;
		case	41089	:
			strcpy(errmsg, "����:���½�/�ۻ�Ǽǲ���");
			break;
		case	41090	:
			strcpy(errmsg, "����:������/�ۻ�ƽ�̲���Ĩ��");
			break;
		case	41091	:
			strcpy(errmsg, "����:�Ѳ��㲻��Ĩ��");
			break;
		case	41092	:
			strcpy(errmsg, "����:���������ѷ��Ͳ���Ĩ��");
			break;
		case	41093	:
			strcpy(errmsg, "����:Ĩ��˳�������Ĩ����ҵ��");
			break;
		case	41094	:
			strcpy(errmsg, "����:��������Ԥ�����Ա��������");
			break;
		case	41095	:
			strcpy(errmsg, "����:��Աδ���侭��˱ʽ���");
			break;
		case	41096	:
			strcpy(errmsg, "����:������ˮ�Ѵ���");
			break;
		case	41097	:
			strcpy(errmsg, "����:ȡ�������Ĳ��źŴ�");
			break;
		case	41098	:
			strcpy(errmsg, "����:�л�Ʊ�踴�˺�Ĩ��");
			break;
		case	42001	:
			strcpy(errmsg, "����:�޴˴���ʺ�");
			break;
		case	42002	:
			strcpy(errmsg, "����:���״̬��");
			break;
		case	42003	:
			strcpy(errmsg, "����:����ʻ����ʴ���");
			break;
		case	42004	:
			strcpy(errmsg, "����:�޴˴���");
			break;
		case	42005	:
			strcpy(errmsg, "����:�����Ŵ�");
			break;
		case	42006	:
			strcpy(errmsg, "����:����״̬��");
			break;
		case	42007	:
			strcpy(errmsg, "����:��������");
			break;
		case	42008	:
			strcpy(errmsg, "����:���������");
			break;
		case	42009	:
			strcpy(errmsg, "����:�����ͬ");
			break;
		case	42010	:
			strcpy(errmsg, "����:�������ʲ�ͬ");
			break;
		case	42011	:
			strcpy(errmsg, "����:���ʽ��ͬ");
			break;
		case	42012	:
			strcpy(errmsg, "����:����Ͷ��ͬ");
			break;
		case	42013	:
			strcpy(errmsg, "����:������ͬ");
			break;
		case	42014	:
			strcpy(errmsg, "����:������ղ�ͬ");
			break;
		case	42015	:
			strcpy(errmsg, "����:������ղ�ͬ");
			break;
		case	42016	:
			strcpy(errmsg, "����:���Ƭ�ѽ���");
			break;
		case	42017	:
			strcpy(errmsg, "����:�������ڴ��ڴ������");
			break;
		case	42018	:
			strcpy(errmsg, "����:��������С�ڴ�����ʼ����");
			break;
		case	42019	:
			strcpy(errmsg, "����:׷���Ŵ���Ϣ��ʧ��");
			break;
		case	42020	:
			strcpy(errmsg, "����:����֤�Ų�ͬ");
			break;
		case	42021	:
			strcpy(errmsg, "����:��������");
			break;
		case	42022	:
			strcpy(errmsg, "����:������δ��");
			break;
		case	42023	:
			strcpy(errmsg, "����:����ʻ����Ͳ���");
			break;
		case	42024	:
			strcpy(errmsg, "����:���㻧�ݷ�");
			break;
		case	42025	:
			strcpy(errmsg, "����:�������ݷ�");
			break;
		case	42026	:
			strcpy(errmsg, "����:ί���ʽ��ݷ�");
			break;
		case	42027	:
			strcpy(errmsg, "����:��֤���ݷ�");
			break;
		case	42028	:
			strcpy(errmsg, "����:�����ѻ�����");
			break;
		case	42029	:
			strcpy(errmsg, "����:�Ŵ���Ϣ�����");
			break;
		case	42030	:
			strcpy(errmsg, "����:��δ����");
			break;
		case	42031	:
			strcpy(errmsg, "����:����������ͬ��¼���ò�ѯ�޸Ľ��׽����޸�");
			break;
		case	42032	:
			strcpy(errmsg, "����:�Ƿ��޸����ʴ�");
			break;
		case	42033	:
			strcpy(errmsg, "����:չ�ڹ̶����ʴ�");
			break;
		case	42034	:
			strcpy(errmsg, "����:չ�����ʸ���ֵ��");
			break;
		case	42035	:
			strcpy(errmsg, "����:չ�ڵ����մ�");
			break;
		case	42036	:
			strcpy(errmsg, "����:��Ʊ�ж��ʺŴ�");
			break;
		case	42037	:
			strcpy(errmsg, "����:����ʻ���ͬ");
			break;
		case	42038	:
			strcpy(errmsg, "����:��Ա������ͬ");
			break;
		case	42039	:
			strcpy(errmsg, "����:��׼��ģ��ͬ");
			break;
		case	42040	:
			strcpy(errmsg, "����:��׼�ʽ�ͬ");
			break;
		case	42041	:
			strcpy(errmsg, "����:�ʽ��ʺŲ�ͬ");
			break;
		case	42042	:
			strcpy(errmsg, "����:��ͬ���ڲ�ͬ");
			break;
		case	42043	:
			strcpy(errmsg, "����:���ʸ�����־��ͬ");
			break;
		case	42044	:
			strcpy(errmsg, "����:����ת�����ʲ�ͬ");
			break;
		case	42045	:
			strcpy(errmsg, "����:�ô��û�н���");
			break;
		case	42101	:
			strcpy(errmsg, "����:ί�д����ʺ������");
			break;
		case	42102	:
			strcpy(errmsg, "����:ί���ʽ��ʻ�״̬��");
			break;
		case	42103	:
			strcpy(errmsg, "����:ί���ʽ��ʻ����ʹ�");
			break;
		case	42104	:
			strcpy(errmsg, "����:ί���ʽ��ʻ����ʴ�");
			break;
		case	42105	:
			strcpy(errmsg, "����:ί����֤���ʻ����ʹ�");
			break;
		case	42106	:
			strcpy(errmsg, "����:ί����֤���ʻ����ʴ�");
			break;
		case	42107	:
			strcpy(errmsg, "����:�޴�ί���ʽ��ʺ�");
			break;
		case	42108	:
			strcpy(errmsg, "����:�޴�ί����֤���ʺ�");
			break;
		case	42109	:
			strcpy(errmsg, "����:ί���ʽ��Ѷ���");
			break;
		case	42110	:
			strcpy(errmsg, "����:ί����֤���Ѷ���");
			break;
		case	42111	:
			strcpy(errmsg, "����:ί���ʽ�����");
			break;
		case	42112	:
			strcpy(errmsg, "����:��֤������");
			break;
		case	42113	:
			strcpy(errmsg, "����:ί����֤��״̬��");
			break;
		case	42114	:
			strcpy(errmsg, "����:ί���ʽ𻧲�ͬ");
			break;
		case	42115	:
			strcpy(errmsg, "����:������־��");
			break;
		case	42116	:
			strcpy(errmsg, "����:�����ʺŴ�");
			break;
		case	42201	:
			strcpy(errmsg, "����:�������");
			break;
		case	42202	:
			strcpy(errmsg, "����:������С�ڽ����");
			break;
		case	42203	:
			strcpy(errmsg, "����:��������ڽ����");
			break;
		case	42204	:
			strcpy(errmsg, "����:��Ϣ�����ڸ�Ϣ���");
			break;
		case	42205	:
			strcpy(errmsg, "����:��Ϣ������ǷϢ���");
			break;
		case	42206	:
			strcpy(errmsg, "����:����ƻ������");
			break;
		case	42207	:
			strcpy(errmsg, "����:���������ͬ");
			break;
		case	42208	:
			strcpy(errmsg, "����:�޴�����");
			break;
		case	42209	:
			strcpy(errmsg, "����:��������");
			break;
		case	42210	:
			strcpy(errmsg, "����:����״̬��");
			break;
		case	42211	:
			strcpy(errmsg, "����:���������");
			break;
		case	42212	:
			strcpy(errmsg, "����:��ͬ�Ŵ�");
			break;
		case	42213	:
			strcpy(errmsg, "����:��ͬ�Ų�ͬ");
			break;
		case	42301	:
			strcpy(errmsg, "����:���շѽ�ͬ");
			break;
		case	42302	:
			strcpy(errmsg, "����:�޶һ������ѽ�ͬ");
			break;
		case	42303	:
			strcpy(errmsg, "����:�޸ķѽ�ͬ");
			break;
		case	42304	:
			strcpy(errmsg, "����:Ԥ�չ������п۷Ѳ���");
			break;
		case	42305	:
			strcpy(errmsg, "����:�ʷѿ�ݷѽ�ͬ");
			break;
		case	42306	:
			strcpy(errmsg, "����:�籨�ѽ�ͬ");
			break;
		case	42307	:
			strcpy(errmsg, "����:Ѻ��Ϣ��ͬ");
			break;
		case	42308	:
			strcpy(errmsg, "����:�籨�Ѵ��벻ͬ");
			break;
		case	42309	:
			strcpy(errmsg, "����:�ʷѴ��벻ͬ");
			break;
		case	42310	:
			strcpy(errmsg, "����:���������ʺŲ�ͬ");
			break;
		case	42311	:
			strcpy(errmsg, "����:�������ʲ�ͬ");
			break;
		case	42312	:
			strcpy(errmsg, "����:����ƻ���");
			break;
		case	42313	:
			strcpy(errmsg, "����:û�����������Ļ���ƻ�");
			break;
		case	42314	:
			strcpy(errmsg, "����:���Ƭ״̬��");
			break;
		case	42315	:
			strcpy(errmsg, "����:���㻧���С����");
			break;
		case	42316	:
			strcpy(errmsg, "����:�ʻ���������");
			break;
		case	42320	:
			strcpy(errmsg, "����:��Ϣ�ʲ�ͬ");
			break;
		case	42321	:
			strcpy(errmsg, "����:������ϸ׷�Ӵ�");
			break;
		case	42322	:
			strcpy(errmsg, "����:�ʻ���������");
			break;
		case	42323	:
			strcpy(errmsg, "����:Ӫҵ˰�ʲ�ͬ");
			break;
		case	42324	:
			strcpy(errmsg, "����:�ڲ��ʻ��������㲻������");
			break;
		case	43001	:
			strcpy(errmsg, "����:Ʊ�ݳж�����δ��");
			break;
		case	43002	:
			strcpy(errmsg, "����:�ѹ�Ʊ�ݶҸ�����");
			break;
		case	43003	:
			strcpy(errmsg, "����:Ʊ��ǩ�����ڲ���");
			break;
		case	43004	:
			strcpy(errmsg, "����:Ʊ���Ѿ�����");
			break;
		case	43005	:
			strcpy(errmsg, "����:Ʊ��δ���˻�");
			break;
		case	43006	:
			strcpy(errmsg, "����:�����ʵ�ѳ���");
			break;
		case	43007	:
			strcpy(errmsg, "����:���������ѳ���");
			break;
		case	43008	:
			strcpy(errmsg, "����:�����ǼǱ��޴˼�¼");
			break;
		case	43009	:
			strcpy(errmsg, "����:�������ʺŲ���");
			break;
		case	43010	:
			strcpy(errmsg, "����:ԭ�������ʺŲ���");
			break;
		case	43011	:
			strcpy(errmsg, "����:�����Զ����ʵǼǱ��޴˼�¼");
			break;
		case	43012	:
			strcpy(errmsg, "����:Ʊ�ݽ��������ֽ��");
			break;
		case	43013	:
			strcpy(errmsg, "����:����������ˮ���޴˼�¼");
			break;
		case	43014	:
			strcpy(errmsg, "����:�޴˼�¼");
			break;
		case	43015	:
			strcpy(errmsg, "����:��һ��");
			break;
		case	43016	:
			strcpy(errmsg, "����:ί���տ���ע��");
			break;
		case	43017	:
			strcpy(errmsg, "����:�տ����ʺŴ�");
			break;
		case	43018	:
			strcpy(errmsg, "����:�տ��˻�����");
			break;
		case	43019	:
			strcpy(errmsg, "����:�տ����");
			break;
		case	43020	:
			strcpy(errmsg, "����:ί���տ��Ѿܸ�");
			break;
		case	43021	:
			strcpy(errmsg, "����:ί���տ��ѽ���");
			break;
		case	43022	:
			strcpy(errmsg, "����:�ʺű��ֲ�һ��");
			break;
		case	43023	:
			strcpy(errmsg, "����:�޸����������ǼǱ��");
			break;
		case	43024	:
			strcpy(errmsg, "����:�ñ���ˮ�Ѿ�Ĩ��");
			break;
		case	43025	:
			strcpy(errmsg, "����:�ñ���ˮ�Ѿ�ɾ��");
			break;
		case	43026	:
			strcpy(errmsg, "����:�ñ���ˮ����δ����");
			break;
		case	43027	:
			strcpy(errmsg, "����:��ϵͳ�ڻ�Ʊ");
			break;
		case	43028	:
			strcpy(errmsg, "����:��ϵͳ���Ʊ");
			break;
		case	43029	:
			strcpy(errmsg, "����:�ۼƽ������ʽ��");
			break;
		case	43030	:
			strcpy(errmsg, "����:���ʽ�������������Ʊ");
			break;
		case	43031	:
			strcpy(errmsg, "����:¼��û�����");
			break;
		case	43032	:
			strcpy(errmsg, "����:����û�����");
			break;
		case	43033	:
			strcpy(errmsg, "����:�����ʽ�����Ѿ�����");
			break;
		case	43034	:
			strcpy(errmsg, "����:ӯ�����һ��");
			break;
		case	43035	:
			strcpy(errmsg, "����:ӯ���һ��");
			break;
		case	43036	:
			strcpy(errmsg, "����:���������Ѿ�����");
			break;
		case	43037	:
			strcpy(errmsg, "����:�ʺŲ���Ϊ�����ʺ�");
			break;
		case	43038	:
			strcpy(errmsg, "����:����Ʊδ����");
			break;
		case	43039	:
			strcpy(errmsg, "����:�ʺŲ������ڸý�����");
			break;
		case	43040	:
			strcpy(errmsg, "����:��¼�ظ�");
			break;
		case	43041	:
			strcpy(errmsg, "����:�����Ѽ���δ���˵Ľ�����ˮ");
			break;
		case	43042	:
			strcpy(errmsg, "����:���Ų������ڸý�����");
			break;
		case	43043	:
			strcpy(errmsg, "����:���ղ�������ʲ��Ų�һ��");
			break;
		case	43044	:
			strcpy(errmsg, "����:�ʺű���Ϊ������");
			break;
		case	43045	:
			strcpy(errmsg, "����:����������������");
			break;
		case	43046	:
			strcpy(errmsg, "����:���������ѷ�������Ĩ��");
			break;
		case	43047	:
			strcpy(errmsg, "����:�����ʽ�����Ѿ�����");
			break;
		case	43048	:
			strcpy(errmsg, "����:�������಻��");
			break;
		case	43049	:
			strcpy(errmsg, "����:��Ƭ״̬��");
			break;
		case	43050	:
			strcpy(errmsg, "����:����������");
			break;
		case	43051	:
			strcpy(errmsg, "����:ר���±�Ų�����");
			break;
		case	43052	:
			strcpy(errmsg, "����:ר���±�Ų���");
			break;
		case	43053	:
			strcpy(errmsg, "����:�������кŷ�������к�");
			break;
		case	50001	:
			strcpy(errmsg, "����:���ֻ��ʴ�");
			break;
		case	50002	:
			strcpy(errmsg, "����:�����ˮԤ������");
			break;
		case	50003	:
			strcpy(errmsg, "����:����");
			break;
		case	50004	:
			strcpy(errmsg, "����:�������Ƿ�");
			break;
		case	50005	:
			strcpy(errmsg, "����:������Ƿ�");
			break;
		case	50006	:
			strcpy(errmsg, "����:����ʻ�����ƽ");
			break;
		case	50007	:
			strcpy(errmsg, "����:��ƿ�Ŀ����ƽ");
			break;
		case	50008	:
			strcpy(errmsg, "����:ȡ��¼��");
			break;
		case	50009	:
			strcpy(errmsg, "����:��֤�뱻��֤�ʺŻ��Ų���");
			break;
		case	50010	:
			strcpy(errmsg, "����:�п�֧����");
			break;
		case	50011	:
			strcpy(errmsg, "����:1321��־��");
			break;
		case	50012	:
			strcpy(errmsg, "����:���ʲ�ƽ");
			break;
		case	50013	:
			strcpy(errmsg, "����:��Ŀ�����ظ�");
			break;
		case	50014	:
			strcpy(errmsg, "����:��ӡ�к��ظ�");
			break;
		case	50015	:
			strcpy(errmsg, "����:��ǰû�м�¼");
			break;
		case	50016	:
			strcpy(errmsg, "����:������Ƽ۴�");
			break;
		case	50017	:
			strcpy(errmsg, "����:���շ��µ�");
			break;
		case	50018	:
			strcpy(errmsg, "����:���շ����");
			break;
		case	50019	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ�ռ俪ʼ������");
			break;
		case	50020	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ�ռ����������");
			break;
		case	50021	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ�����л�������");
			break;
		case	50022	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ���տ�ʼ������");
			break;
		case	50023	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ���ս���������");
			break;
		case	50024	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ��ʼ��ʼ������");
			break;
		case	50025	:
			strcpy(errmsg, "����:��ǰ״̬Ϊ��ʼ����������");
			break;
		case	50026	:
			strcpy(errmsg, "����:�������ʴ�");
			break;
		case	50027	:
			strcpy(errmsg, "����:ȡ����ʻ���");
			break;
		case	50028	:
			strcpy(errmsg, "����:���ʽ�����ۼƷ������");
			break;
		case	50029	:
			strcpy(errmsg, "����:�����ڲ�ͬ��Ϣ��������1");
			break;
		case	50030	:
			strcpy(errmsg, "����:�����ڼȼ�Ϣ�ֿ���");
			break;
		case	50031	:
			strcpy(errmsg, "����:������������ӡ�����������Ϣ(050301)!");
			break;
		case	50032	:
			strcpy(errmsg, "����:�洢���̵��ô�!");
			break;
		case	50033	:
			strcpy(errmsg, "����:���ʸ�����־��!");
			break;
		case	50034	:
			strcpy(errmsg, "����:��������!");
			break;
		case	50035	:
			strcpy(errmsg, "����:���շǼ�Ϣ��!");
			break;
		case	50036	:
			strcpy(errmsg, "����:ȡ������С���ʵ�λ��!");
			break;
		case	50037	:
			strcpy(errmsg, "����:��Ϣ���Ƿ�!");
			break;
		case	50038	:
			strcpy(errmsg, "����:������������!");
			break;
		case	50039	:
			strcpy(errmsg, "����:���ݳ���!");
			break;
		case	50040	:
			strcpy(errmsg, "����:�ָ�����!");
			break;
		case	50041	:
			strcpy(errmsg, "����:�������ʻ�����!");
			break;
		case	50042	:
			strcpy(errmsg, "����:ȡ�ϴμ�Ϣ���ڴ�!");
			break;
		case	50043	:
			strcpy(errmsg, "����:���շ�Ѯĩ!");
			break;
		case	50044	:
			strcpy(errmsg, "����:��������ɴ�");
			break;
		case	50045	:
			strcpy(errmsg, "����:���������������н���");
			break;
		case	50046	:
			strcpy(errmsg, "����:�ʲ���ծ�����ɴ�");
			break;
		case	50047	:
			strcpy(errmsg, "����:����ɾ��������Դ���и���");
			break;
		case	50048	:
			strcpy(errmsg, "����:�ڲ��ʻ�����������Ϊ�㲻������");
			break;
		case	50049	:
			strcpy(errmsg, "����:�ڲ��ʻ��跽������Ϊ�㲻������");
			break;
		case	130001	:
			strcpy(errmsg, "����:�����01����ȯ��������");
			break;
		case	130002	:
			strcpy(errmsg, "����:�����02����ȯ��������");
			break;
		case	130003	:
			strcpy(errmsg, "����:�����03����ȯ��������");
			break;
		case	130004	:
			strcpy(errmsg, "����:�����04����ȯ��������");
			break;
		case	130005	:
			strcpy(errmsg, "����:�����05����ȯ��������");
			break;
		case	130006	:
			strcpy(errmsg, "����:�����06����ȯ��������");
			break;
		case	130007	:
			strcpy(errmsg, "����:�����07����ȯ��������");
			break;
		case	130008	:
			strcpy(errmsg, "����:�����08����ȯ��������");
			break;
		case	130009	:
			strcpy(errmsg, "����:�����09����ȯ��������");
			break;
		case	130010	:
			strcpy(errmsg, "����:�����10����ȯ��������");
			break;
		case	130011	:
			strcpy(errmsg, "����:�����11����ȯ��������");
			break;
		case	130012	:
			strcpy(errmsg, "����:�����12����ȯ��������");
			break;
		case	130013	:
			strcpy(errmsg, "����:�����13����ȯ��������");
			break;
		case	130014	:
			strcpy(errmsg, "����:�����14����ȯ��������");
			break;
		case	130015	:
			strcpy(errmsg, "����:�����15����ȯ��������");
			break;
		case	130016	:
			strcpy(errmsg, "����:�����16����ȯ��������");
			break;
		case	130017	:
			strcpy(errmsg, "����:�����17����ȯ��������");
			break;
		case	130018	:
			strcpy(errmsg, "����:�����18����ȯ��������");
			break;
		case	130019	:
			strcpy(errmsg, "����:�����19����ȯ��������");
			break;
		case	130020	:
			strcpy(errmsg, "����:�����20����ȯ��������");
			break;
		case	130021	:
			strcpy(errmsg, "����:���������Ա��=9999");
			break;
		case	130022	:
			strcpy(errmsg, "����:������������������¼");
			break;
		case	130023	:
			strcpy(errmsg, "����:�����¼��Ч");
			break;
		case	130024	:
			strcpy(errmsg, "����:�������");
			break;
		case	130025	:
			strcpy(errmsg, "����:���¿�������¼��");
			break;
		case	130027	:
			strcpy(errmsg, "����:���¿�������¼��");
			break;
		case	130029	:
			strcpy(errmsg, "����:���¿�������¼��");
			break;
		case	130031	:
			strcpy(errmsg, "����:д�ֽ�Ǽǲ���");
			break;
		case	130032	:
			strcpy(errmsg, "����:д�ֽ���ˮ���");
			break;
		case	130033	:
			strcpy(errmsg, "����:�ֽ�Ǽǲ���������������¼");
			break;
		case	130034	:
			strcpy(errmsg, "����:�˱ʽ����Ѹ���");
			break;
		case	130035	:
			strcpy(errmsg, "����:���ֲ���");
			break;
		case	130036	:
			strcpy(errmsg, "����:����");
			break;
		case	130037	:
			strcpy(errmsg, "����:���շ�����Ա����");
			break;
		case	130038	:
			strcpy(errmsg, "����:�����ֽ�Ǽǲ���");
			break;
		case	130041	:
			strcpy(errmsg, "����:�����ֽ�����");
			break;
		case	130042	:
			strcpy(errmsg, "����:�����ֽ�Ǽǲ���������������¼");
			break;
		case	130043	:
			strcpy(errmsg, "����:���������ֽ�Ǽǲ���");
			break;
		case	130044	:
			strcpy(errmsg, "����:д�����ֽ�Ǽǲ���");
			break;
		case	130046	:
			strcpy(errmsg, "����:�ⷿ���Ͳ���");
			break;
		case	130049	:
			strcpy(errmsg, "����:�ֻ��ʱ��");
			break;
		case	130050	:
			strcpy(errmsg, "����:�ֻ��ʱ���������������¼");
			break;
		case	130051	:
			strcpy(errmsg, "����:�ʺŵ�״̬��");
			break;
		case	130052	:
			strcpy(errmsg, "����:�ʺŵ����ʴ�");
			break;
		case	130053	:
			strcpy(errmsg, "����:�ͻ���״̬��");
			break;
		case	130054	:
			strcpy(errmsg, "����:���ÿͻ���麯����");
			break;
		case	130055	:
			strcpy(errmsg, "����:��ȡ��Ʒ�¼������");
			break;
		case	130056	:
			strcpy(errmsg, "����:ǰ��̨�����˺Ų�һ��");
			break;
		case	130057	:
			strcpy(errmsg, "����:��ȡ������Ƽ��ʺ�����");
			break;
		case	130058	:
			strcpy(errmsg, "����:ǰ��̨���ʼ��㲻һ��");
			break;
		case	130059	:
			strcpy(errmsg, "����:��ȡ�һ�������");
			break;
		case	130060	:
			strcpy(errmsg, "����:��ծ��Ϣ���");
			break;
		case	130061	:
			strcpy(errmsg, "����:��ծ��Ϣ�����޴˹�ծƷ��?");
			break;
		case	130062	:
			strcpy(errmsg, "����:ǰ��̨��ծ��Ϣ���㲻һ��");
			break;
		case	130063	:
			strcpy(errmsg, "����:��ű��");
			break;
		case	130064	:
			strcpy(errmsg, "����:��ű����޴˱��");
			break;
		case	130065	:
			strcpy(errmsg, "����:��ű��иü�¼��״̬��");
			break;
		case	130066	:
			strcpy(errmsg, "����:�˱ʽ�����Ĩ��");
			break;
		case	130067	:
			strcpy(errmsg, "����:�˱ʽ�����ˮ������");
			break;
		case	130068	:
			strcpy(errmsg, "����:�����������ʲ����ʺ�");
			break;
		case	130070	:
			strcpy(errmsg, "����:д�ٱҴ�����Ʒ���");
			break;
		case	130071	:
			strcpy(errmsg, "����:д�ٱҴ�����Ʒ��ˮ���");
			break;
		case	130072	:
			strcpy(errmsg, "����:�üٱұ����Ĩ��");
			break;
		case	130073	:
			strcpy(errmsg, "����:�üٱұ�����Ͻ�");
			break;
		case	130088	:
			strcpy(errmsg, "����:���������־����");
			break;
		case	130101	:
			strcpy(errmsg, "����:�����01����ȯ��������");
			break;
		case	130102	:
			strcpy(errmsg, "����:�����02����ȯ��������");
			break;
		case	130103	:
			strcpy(errmsg, "����:�����03����ȯ��������");
			break;
		case	130104	:
			strcpy(errmsg, "����:�����04����ȯ��������");
			break;
		case	130105	:
			strcpy(errmsg, "����:�����05����ȯ��������");
			break;
		case	130106	:
			strcpy(errmsg, "����:�����06����ȯ��������");
			break;
		case	130107	:
			strcpy(errmsg, "����:�����07����ȯ��������");
			break;
		case	130108	:
			strcpy(errmsg, "����:�����08����ȯ��������");
			break;
		case	130109	:
			strcpy(errmsg, "����:�����09����ȯ��������");
			break;
		case	130110	:
			strcpy(errmsg, "����:�����10����ȯ��������");
			break;
		case	130111	:
			strcpy(errmsg, "����:�����11����ȯ��������");
			break;
		case	130112	:
			strcpy(errmsg, "����:�����12����ȯ��������");
			break;
		case	130113	:
			strcpy(errmsg, "����:�����13����ȯ��������");
			break;
		case	130114	:
			strcpy(errmsg, "����:�����14����ȯ��������");
			break;
		case	130115	:
			strcpy(errmsg, "����:�����15����ȯ��������");
			break;
		case	130116	:
			strcpy(errmsg, "����:�����16����ȯ��������");
			break;
		case	130117	:
			strcpy(errmsg, "����:�����17����ȯ��������");
			break;
		case	130118	:
			strcpy(errmsg, "����:�����18����ȯ��������");
			break;
		case	130119	:
			strcpy(errmsg, "����:�����19����ȯ��������");
			break;
		case	130120	:
			strcpy(errmsg, "����:�����20����ȯ��������");
			break;
		case	130407	:
			strcpy(errmsg, "����:�ӿ�Աδ��ƽ");
			break;
		case	130409	:
			strcpy(errmsg, "����:Ԥ�����շ���");
			break;
		case	130410	:
			strcpy(errmsg, "����:дԤ���Ǽǲ���");
			break;
		case	130411	:
			strcpy(errmsg, "����:�޸�Ԥ���Ǽǲ���");
			break;
		case	135000	:
			strcpy(errmsg, "����:�ǼǺ�̨��ҵ���������ˮ���");
			break;
		case	135001	:
			strcpy(errmsg, "����:�Ǽǵ����Ǽǲ���");
			break;
		case	135002	:
			strcpy(errmsg, "����:�޸ĵ����Ǽǲ���");
			break;
		case	135003	:
			strcpy(errmsg, "����:�����Ǽǲ��޶�Ӧ��¼");
			break;
		case	135004	:
			strcpy(errmsg, "����:�����Ǽǲ���¼�ѱ��޸Ĺ��������޸�");
			break;
		case	135005	:
			strcpy(errmsg, "����:�����Ǽǲ���¼�Ѵ���");
			break;
		case	140101	:
			strcpy(errmsg, "����:ҵ�������");
			break;
		case	140102	:
			strcpy(errmsg, "����:���Ŵ�");
			break;
		case	140103	:
			strcpy(errmsg, "����:���еǼǲ���¼�Ѵ���");
			break;
		case	140104	:
			strcpy(errmsg, "����:����������δ����");
			break;
		case	140105	:
			strcpy(errmsg, "����:�˻����ɴ�");
			break;
		case	140501	:
			strcpy(errmsg, "����:�������ݴ�");
			break;
		case	140701	:
			strcpy(errmsg, "����:ǩƱ��ˮ�����޼�¼�����׺�");
			break;
		case	140702	:
			strcpy(errmsg, "����:����Ҹ�����");
			break;
		case	140703	:
			strcpy(errmsg, "����:����Ҹ�������");
			break;
		case	140704	:
			strcpy(errmsg, "����:����Ҫ���˵ļ�¼");
			break;
		case	140705	:
			strcpy(errmsg, "����:ǩƱ��ˮ�����޸ü�¼");
			break;
		case	140706	:
			strcpy(errmsg, "����:ǩƱ��ˮ���иü�¼״̬��");
			break;
		case	140707	:
			strcpy(errmsg, "����:�ü�¼������");
			break;
		case	140708	:
			strcpy(errmsg, "����:����ʱƱ������");
			break;
		case	141001	:
			strcpy(errmsg, "����:��������������ʽ���");
			break;
		case	141002	:
			strcpy(errmsg, "����:���ս������ȫ������");
			break;
		case	141003	:
			strcpy(errmsg, "����:�����Ų�����");
			break;
		case	141004	:
			strcpy(errmsg, "����:�������δ����");
			break;
		case	141005	:
			strcpy(errmsg, "����:����������ܽ���");
			break;
		case	141006	:
			strcpy(errmsg, "����:�ñ��ֱ�����δ�����������");
			break;
		case	141007	:
			strcpy(errmsg, "����:δ������Ҫ�ָ����������");
			break;
		case	141008	:
			strcpy(errmsg, "����:��ˮ��Ǽǲ�����ָ�����շ����ݲ����������");
			break;
		case	141009	:
			strcpy(errmsg, "����:��ˮ��Ǽǲ�����ָ�����������ݲ����������");
			break;
		case	141010	:
			strcpy(errmsg, "����:ǰһ������δ����������β��ɼ��ʽ���");
			break;
		case	141011	:
			strcpy(errmsg, "����:��������δ���������������������");
			break;
		case	141012	:
			strcpy(errmsg, "����:����շ����ܽ���");
			break;
		case	141013	:
			strcpy(errmsg, "����:ǰһ������δ���ˣ������β��ɼ��ʽ���");
			break;
		case	141014	:
			strcpy(errmsg, "����:������������δ����");
			break;
		case	141401	:
			strcpy(errmsg, "����:Ӧ�տ�ǼǱ����޴���ˮ��");
			break;
		case	150101	:
			strcpy(errmsg, "����:����������޷���ƽ");
			break;
		case	150102	:
			strcpy(errmsg, "����:û���ҵ����Ե��ʵĿ�Ŀ");
			break;
		case	150103	:
			strcpy(errmsg, "����:�������ڴ���");
			break;
		case	160001	:
			strcpy(errmsg, "����:�������Ӧ�����������");
			break;
		case	160002	:
			strcpy(errmsg, "����:������ʺŴ��ڿ�Ƭ");
			break;
		case	160003	:
			strcpy(errmsg, "����:�����ԭ����ʻ��뿨Ƭ�Ļ���ʻ�����");
			break;
		case	160004	:
			strcpy(errmsg, "����:���ֳ�������뿨Ƭ����");
			break;
		case	160005	:
			strcpy(errmsg, "����:�������ʺ��ʻ����ʲ�ͬ");
			break;
		case	160006	:
			strcpy(errmsg, "����:���Ƭ���ڶ���״̬");
			break;
		case	160007	:
			strcpy(errmsg, "����:û�пɳ�������Ϣ");
			break;
		case	160008	:
			strcpy(errmsg, "����:ԭ��Ƭ��������");
			break;
		case	160009	:
			strcpy(errmsg, "����:������Է���Ƭ���");
			break;
		case	160010	:
			strcpy(errmsg, "����:�ÿ�Ŀ�ʺŲ��������");
			break;
		case	160011	:
			strcpy(errmsg, "����:��������ʿ�Ƭ���");
			break;
		case	160012	:
			strcpy(errmsg, "����:��������Ļ�������������������ȥ");
			break;
		case	190101	:
			strcpy(errmsg, "����:���������ʲ������ڻ��Ѹ���");
			break;
		case	190102	:
			strcpy(errmsg, "����:�������Ӹ����������������۾�");
			break;
		case	190103	:
			strcpy(errmsg, "����:�ʲ������벻����");
			break;
		case	190104	:
			strcpy(errmsg, "����:�ʲ��Ѿ��˳�");
			break;
		case	190105	:
			strcpy(errmsg, "����:�ʲ�����ʲ�������δ����");
			break;
		case	190106	:
			strcpy(errmsg, "����:ҵ�������");
			break;
		case	190107	:
			strcpy(errmsg, "����:���ʲ��в���δ������");
			break;
		case	190108	:
			strcpy(errmsg, "����:ҵ���Ų����ڻ��Ѹ���");
			break;
		case	190109	:
			strcpy(errmsg, "����:�ʲ��Ѹ��˲���ɾ��");
			break;
		case	190110	:
			strcpy(errmsg, "����:����ɾ��������Ա�Ľ���");
			break;
		case	190111	:
			strcpy(errmsg, "����:�ø����ʲ�������δ����");
			break;
		case	190112	:
			strcpy(errmsg, "����:��ʵ��������ȷ");
			break;
		case	190113	:
			strcpy(errmsg, "����:�ʲ���������");
			break;
		case	190114	:
			strcpy(errmsg, "����:�۾�����С����");
			break;
		case	190115	:
			strcpy(errmsg, "����:ȡ�۾����޴�");
			break;
		case	190116	:
			strcpy(errmsg, "����:ҵ���Ų��Ǹý��׻��Ѹ���");
			break;
		case	190117	:
			strcpy(errmsg, "����:ȡ�����ʻ���Ŵ�");
			break;
		case	190118	:
			strcpy(errmsg, "����:ȡ����ֵ�ʴ�");
			break;
		case	190119	:
			strcpy(errmsg, "����:ҵ���Ų����ڻ�δ����");
			break;
		case	190120	:
			strcpy(errmsg, "����:���ȶԸ��ʲ��ĸ���Ĩ��");
			break;
		case	190121	:
			strcpy(errmsg, "����:���ǵ���Ľ�����ʹ�ó���");
			break;
		case	190122	:
			strcpy(errmsg, "����:�������Ѵ���");
			break;
		case	190123	:
			strcpy(errmsg, "����:ȡ��Ŀ�����");
			break;
		case	200101	:
			strcpy(errmsg, "����:д���ڲ������ǼǱ��");
			break;
		case	200102	:
			strcpy(errmsg, "����:д������Ƭ���ǼǱ��");
			break;
		case	200103	:
			strcpy(errmsg, "����:�ÿ�Ϊ������Ƭ");
			break;
		case	200104	:
			strcpy(errmsg, "����:���ڲ������ʺŲ�����");
			break;
		case	200105	:
			strcpy(errmsg, "����:�������Ų�����");
			break;
		case	200106	:
			strcpy(errmsg, "����:д�������ǼǱ��");
			break;
		case	200107	:
			strcpy(errmsg, "����:�����ڲ������ǼǱ��");
			break;
		case	200108	:
			strcpy(errmsg, "����:���㲻����������Ϣ��");
			break;
		case	200401	:
			strcpy(errmsg, "����:ҵ�������");
			break;
		case	200402	:
			strcpy(errmsg, "����:֪ͨ��Ŵ�");
			break;
		case	200403	:
			strcpy(errmsg, "����:֪ͨ��Ų�����");
			break;
		case	200404	:
			strcpy(errmsg, "����:֪ͨ��Χ��");
			break;
		case	200405	:
			strcpy(errmsg, "����:���ɴ����");
			break;
		case	200406	:
			strcpy(errmsg, "����:����֤��Ŵ�");
			break;
		case	200407	:
			strcpy(errmsg, "����:֪ͨ�溯��");
			break;
		case	200408	:
			strcpy(errmsg, "����:����֤���״̬��");
			break;
		case	200409	:
			strcpy(errmsg, "����:���ʸ���֮������֤���״̬�ı�");
			break;
		case	200410	:
			strcpy(errmsg, "����:5413��Ϊ����������");
			break;
		case	200411	:
			strcpy(errmsg, "����:5413�������ָ�����");
			break;
		case	200412	:
			strcpy(errmsg, "����:����֤LP��Ŵ�");
			break;
		case	200413	:
			strcpy(errmsg, "����:����979���˽��>֪ͨ�ܽ��");
			break;
		case	200414	:
			strcpy(errmsg, "����:����֤�����˽��>����֤�ܽ��");
			break;
		case	200415	:
			strcpy(errmsg, "����:ȡ���һ��ͳ���Ƽ۴�");
			break;
		case	200416	:
			strcpy(errmsg, "����:ȡ����Ҷ���Ԫ��ͳ���Ƽ۴�");
			break;
		case	200417	:
			strcpy(errmsg, "����:ȡ��Ҷ���Ԫ��ͳ���Ƽ۴�");
			break;
		default	:
			strcpy(errmsg, "����:δ֪����");
			break;
	}

	return errmsg;
}
