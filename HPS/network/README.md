network通信模块：
	由于标准的socket通信api接口的调用过程、参数传递过于复杂，所以参考了Qt中QTcpSocket、QTcpServer、QUdpServer相关类的封装效果
	class NetWork
	{
		int sock; //socket描述符号
		int type; //协议类型
		sockaddr_in addr; //通信地址
		socklen_t addrlen; //通信地址结构体大小
		bool is_svr; //服务端or客户端
	}
	构造函数：
		负责成员变量赋值，没有在此创建socket
	析构函数：
		关闭socket
	start：
		创建socket
		服务端：绑定、监听(tcp)
		客户端：连接(tcp)
	accept：
		tcp服务端等待连接
	send/recv：
		发送/接收数据
	TCP编程模型：

	UDP编程模型：

