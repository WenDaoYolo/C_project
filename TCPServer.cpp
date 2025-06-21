#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<Winsock2.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib")
//socket  插座/网络套接字
//需将c/c++的sdl检查属性改为否
DWORD WINAPI cilent_refull(LPVOID lp) {
	SOCKET client_socket = *(SOCKET*)lp;
	char buffer[1024];
	while (1) {
		scanf("%s", buffer);
		send(client_socket, buffer, sizeof(buffer), 0);
	}
	return 0;
}

DWORD WINAPI cilent_thread(LPVOID lp) {
	SOCKET client_socket = *(SOCKET*)lp;
	printf("%llu connact\n", client_socket);
	free(lp);
	while (1) {                                          //服务器不应该主动断开连接，应该有客户端完成
	//5.开始通讯
		char buffer[1024] = { 0 };                       //用于存储客服端发送的数据
		int ret = recv(client_socket, buffer, 1024, 0);  //接收客户端发送的数据
		if (ret <= 0)
			break;
		printf("%llu:%s\n", client_socket,buffer);
	}
	//6.关闭连接
	printf("%llu disconnact\n", client_socket);
	closesocket(client_socket);
	return 0;
}

int main() {
	//0.windwos上使用网络的相关功能需要先开启网络权限
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	// Windows Socket Asynchronous start up，开启windwos 异步 socket 
	
	//1.创建网络套接字socket，即网络接口
	SOCKET listen_socket=socket(AF_INET, SOCK_STREAM, 0);
	//AF_INET:Address Family - Internet      IPV4地址协议簇
	//AF_INET6:Address Family - Internet 6   IPV6地址协议簇
	//STREAM     流式协议
	//DGRAM      数据报(帧式)协议
	//创建失败返回-1(常量标识符INVALID_SOCKET，值为-1表示无效网络套接字)
	//invalid 无效
	if (INVALID_SOCKET == listen_socket) {
		printf("Create socket failed!! %d\n", GetLastError());
		return -1;
	}
	//perror,strerror ->用于c语言标准库函数的错误报告
	//GetLastError->用于windows API接口调用的错误报告

	//2.为socket绑定一个端口号
	struct sockaddr_in local= { 0 };
	local.sin_family = AF_INET;
	local.sin_port = htons(8080);
	local.sin_addr.s_addr = inet_addr("0.0.0.0");
	//通讯的范围取决于服务器所使用的ip，若是内网ip则只能在相同的内网中才能通信
	//若想通信得使用公网ip

	//bind  约束/绑定
	if (bind(listen_socket, (sockaddr*)&local, sizeof(local)) == -1)
	{
		printf("bind socket failed!! %d \n", GetLastError());
		return -1;
	}

	//3.为socket开启监听属性
	if (INVALID_SOCKET==listen(listen_socket, 10)) {
		printf("start listen socket failed!! %d \n", GetLastError());
		return -1;
	}
	//4.等待客户端的连接
	//accept  接收/接受;client  客户

	while (1) {
		SOCKET client_socket = accept(listen_socket, NULL, NULL);    //阻塞函数,连接成功后socket自动关闭
		if (INVALID_SOCKET==client_socket)
			continue;
		SOCKET* client_socketfd = (SOCKET*)malloc(sizeof(SOCKET));
		*client_socketfd = client_socket;
		CreateThread(NULL,0,cilent_thread,client_socketfd,0, NULL);
		CreateThread(NULL, 0, cilent_refull, client_socketfd, 0, NULL);
	}
	
	return 0;
}