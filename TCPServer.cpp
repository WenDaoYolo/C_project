#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<Winsock2.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib")
//socket  ����/�����׽���
//�轫c/c++��sdl������Ը�Ϊ��
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
	while (1) {                                          //��������Ӧ�������Ͽ����ӣ�Ӧ���пͻ������
	//5.��ʼͨѶ
		char buffer[1024] = { 0 };                       //���ڴ洢�ͷ��˷��͵�����
		int ret = recv(client_socket, buffer, 1024, 0);  //���տͻ��˷��͵�����
		if (ret <= 0)
			break;
		printf("%llu:%s\n", client_socket,buffer);
	}
	//6.�ر�����
	printf("%llu disconnact\n", client_socket);
	closesocket(client_socket);
	return 0;
}

int main() {
	//0.windwos��ʹ���������ع�����Ҫ�ȿ�������Ȩ��
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	// Windows Socket Asynchronous start up������windwos �첽 socket 
	
	//1.���������׽���socket��������ӿ�
	SOCKET listen_socket=socket(AF_INET, SOCK_STREAM, 0);
	//AF_INET:Address Family - Internet      IPV4��ַЭ���
	//AF_INET6:Address Family - Internet 6   IPV6��ַЭ���
	//STREAM     ��ʽЭ��
	//DGRAM      ���ݱ�(֡ʽ)Э��
	//����ʧ�ܷ���-1(������ʶ��INVALID_SOCKET��ֵΪ-1��ʾ��Ч�����׽���)
	//invalid ��Ч
	if (INVALID_SOCKET == listen_socket) {
		printf("Create socket failed!! %d\n", GetLastError());
		return -1;
	}
	//perror,strerror ->����c���Ա�׼�⺯���Ĵ��󱨸�
	//GetLastError->����windows API�ӿڵ��õĴ��󱨸�

	//2.Ϊsocket��һ���˿ں�
	struct sockaddr_in local= { 0 };
	local.sin_family = AF_INET;
	local.sin_port = htons(8080);
	local.sin_addr.s_addr = inet_addr("0.0.0.0");
	//ͨѶ�ķ�Χȡ���ڷ�������ʹ�õ�ip����������ip��ֻ������ͬ�������в���ͨ��
	//����ͨ�ŵ�ʹ�ù���ip

	//bind  Լ��/��
	if (bind(listen_socket, (sockaddr*)&local, sizeof(local)) == -1)
	{
		printf("bind socket failed!! %d \n", GetLastError());
		return -1;
	}

	//3.Ϊsocket������������
	if (INVALID_SOCKET==listen(listen_socket, 10)) {
		printf("start listen socket failed!! %d \n", GetLastError());
		return -1;
	}
	//4.�ȴ��ͻ��˵�����
	//accept  ����/����;client  �ͻ�

	while (1) {
		SOCKET client_socket = accept(listen_socket, NULL, NULL);    //��������,���ӳɹ���socket�Զ��ر�
		if (INVALID_SOCKET==client_socket)
			continue;
		SOCKET* client_socketfd = (SOCKET*)malloc(sizeof(SOCKET));
		*client_socketfd = client_socket;
		CreateThread(NULL,0,cilent_thread,client_socketfd,0, NULL);
		CreateThread(NULL, 0, cilent_refull, client_socketfd, 0, NULL);
	}
	
	return 0;
}