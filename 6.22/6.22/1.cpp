//Linux  ������2    ��������
#include "tcp_thread_srever.hpp"//��������
//���� 10 20+   ��Ӧ30
//ʹ��Json�ķ�ʽ�������л��ͷ����л�
//{"num1" :10,   "num2" : 20,   "op0" : + ,}
///////////�Ľ�nums [10,20,30,40]
//{"result" : 30}
int main(){
	TcepThreadServer server;
	server.Strat("0.0.0.0", 9090, [](const std::string& req, std::string* resp)){
	//1.�Ƚ� req ���з����л�
		Json::Reader reader;//��ʾһ��Json����
		Json::Value req_json;//���ַ���ת���� Json::Value
		//Json::write  ��Jason::Value ת���ַ���
		reader.prse(req, req_json);
	//2.���ݷ����л��Ľ�������м���
		int  num1 = req_jsomn["[num1]"].asInt();
		int  num2 = req_jsomn["[num2]"].asInt();
/////////�����ӵĲ��� Json::Value& nums = req_jsomn["nums"];
		std::string op = req_json["op"].asString();
		int result = 0;
//////////////for(size_t i = 0li<nums.size();++i)
		if (op == "+"){
			result = num1 + num2;
		}///////////result += nums[(int)i].asInt();
		else if (op == "-"){
			result = num1 - num2;
		}//////////////result -= nums[(int)i].asInt();
		//3.��Ҫ�ѽ�������л���һ���ַ���
		Json::FastWriter writer;
		Json::Value resp_jspn;
		resp_json["result"] = result;
		*
	});
	return 0;
}//�õ�������
/////////////////////////////////////////////yum  list | grep 
//////��װdevel.  ��׺�� 
////ll  jsoncpp/
//#include <jsoncpp/json/json.h>



//client

int main()
{//1.����һ��tcp�ͻ���
	TcpClient client;
	bool ret = Clinet.Connect("127.0.0.1", 9090);
	if (!ret)
	{
		printf("connect failed!\n");
		return 1;
	}
//2.ѭ���ӱ�׼�����������
	while (true){
		prinft("������2����������һ��������");
		fflush(stdout);
		int num1, num2;
		char op[10] = { 0 };
		scanf("%d %d %s", &num1, &num2, cp);
//3.�����û���������ݣ�����һ��Json����
		Json::FastwWriter writer;//Fast �ĳ� stlye ��������ʽ�ỻ�У���
		std::string req = writer.wirter(req_json);
		printf("req:%s\n", req.c_str);
//4.��Json�������л���һ���ַ���
//5.���ַ������͵�������
//6.�ӷ�������ȡ���صĽ��
//7.���������ؽ���ٽ���Json����
	}
}

void HttpProcess(const std::string& req, std::string* resp){
	//�����û�����ʲô���󣬶����� hello world
	(void)req;
	
}
int main()
{
	TcpThreadServer server;
}