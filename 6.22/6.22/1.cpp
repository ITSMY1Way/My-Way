//Linux  网络编程2    计算器的
#include "tcp_thread_srever.hpp"//服务器端
//请求 10 20+   响应30
//使用Json的方式进行序列化和反序列化
//{"num1" :10,   "num2" : 20,   "op0" : + ,}
///////////改进nums [10,20,30,40]
//{"result" : 30}
int main(){
	TcepThreadServer server;
	server.Strat("0.0.0.0", 9090, [](const std::string& req, std::string* resp)){
	//1.先将 req 进行反序列化
		Json::Reader reader;//表示一个Json数据
		Json::Value req_json;//把字符串转换成 Json::Value
		//Json::write  把Jason::Value 转成字符串
		reader.prse(req, req_json);
	//2.根据反序列化的结果，进行计算
		int  num1 = req_jsomn["[num1]"].asInt();
		int  num2 = req_jsomn["[num2]"].asInt();
/////////更复杂的操作 Json::Value& nums = req_jsomn["nums"];
		std::string op = req_json["op"].asString();
		int result = 0;
//////////////for(size_t i = 0li<nums.size();++i)
		if (op == "+"){
			result = num1 + num2;
		}///////////result += nums[(int)i].asInt();
		else if (op == "-"){
			result = num1 - num2;
		}//////////////result -= nums[(int)i].asInt();
		//3.需要把结果再序列化回一个字符串
		Json::FastWriter writer;
		Json::Value resp_jspn;
		resp_json["result"] = result;
		*
	});
	return 0;
}//用第三方库
/////////////////////////////////////////////yum  list | grep 
//////安装devel.  后缀的 
////ll  jsoncpp/
//#include <jsoncpp/json/json.h>



//client

int main()
{//1.创建一个tcp客户端
	TcpClient client;
	bool ret = Clinet.Connect("127.0.0.1", 9090);
	if (!ret)
	{
		printf("connect failed!\n");
		return 1;
	}
//2.循环从标准输入读入数据
	while (true){
		prinft("请输入2个操作数和一个操作符");
		fflush(stdout);
		int num1, num2;
		char op[10] = { 0 };
		scanf("%d %d %s", &num1, &num2, cp);
//3.根据用户输入的内容，构建一个Json对象
		Json::FastwWriter writer;//Fast 改成 stlye 输出结果格式会换行，，
		std::string req = writer.wirter(req_json);
		printf("req:%s\n", req.c_str);
//4.把Json对象序列化成一个字符串
//5.把字符串发送到服务器
//6.从服务器读取返回的结果
//7.服务器返回结果再进行Json解析
	}
}

void HttpProcess(const std::string& req, std::string* resp){
	//不管用户输入什么请求，都返回 hello world
	(void)req;
	
}
int main()
{
	TcpThreadServer server;
}