#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>

#pragma comment(lib,"ws2_32.lib")

DWORD WINAPI replay(LPVOID lp) {
	SOCKET client_socket = *(SOCKET*)lp;
	char buffer[1024];
	while (1) {
		scanf("%s", buffer);
		if (strcmp(buffer, "exit") == 0)
			break;
		send(client_socket, buffer, (int)strlen(buffer), 0);
	}
	return 0;
}

DWORD WINAPI view(LPVOID lp) {
	SOCKET client_socket = *(SOCKET*)lp;
	while (1) {
		char buffer[1024] = { 0 };                       //用于存储客服端发送的数据
		int ret = recv(client_socket, buffer, 1024, 0);  //接收客户端发送的数据
		if (ret <= 0)
			break;
		printf("server:%s\n", buffer);
	}
	closesocket(client_socket);
	return 0;
}

int main() {

	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	//Windows Socket Asynchronous Start up
	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == client_socket)
	{
		printf("Create socket failed!! %d\n", GetLastError());
		return -1;
	}
	struct sockaddr_in target;
	target.sin_family = AF_INET;
	target.sin_port = htons(33724);
	target.sin_addr.s_addr = inet_addr("115.236.153.172");
	if (INVALID_SOCKET == connect(client_socket, (struct sockaddr*)&target, sizeof(target)))
	{
		printf("connect target port failed!! %d\n", GetLastError());
		closesocket(client_socket);
		return -1;
	}
	SOCKET* client_socketfd = (SOCKET*)malloc(sizeof(SOCKET));
	*client_socketfd = client_socket;
	HANDLE t1 = CreateThread(NULL, 0, replay, client_socketfd, 0, NULL);
	CreateThread(NULL, 0, view, client_socketfd, 0, NULL);

	WaitForSingleObject(t1, INFINITE);

	closesocket(client_socket);


	return 0;
}