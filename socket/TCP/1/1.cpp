// 1.cpp : Defines the entry point for the console application.
//


//��������
#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
//��ʼ��WSA
WORD sockVersion = MAKEWORD(2,2);
WSADATA wsaData;
WSAStartup(sockVersion, &wsaData);

//�����׽���
SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
SOCKET serSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

//��IP�Ͷ˿�
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(8888);
sin.sin_addr.S_un.S_addr = INADDR_ANY;

bind(slisten, (LPSOCKADDR)&sin, sizeof(sin));

//��ʼ����
listen(slisten,4);

//��������
sockaddr_in remoteAddr;
int nAddrlen = sizeof(remoteAddr);

printf("�ȴ�����...\n");
serSocket = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(remoteAddr.sin_addr));

//��������
char revData[255]; 
int ret=recv(serSocket , revData, 255, 0); 
printf("%d",ret);
revData[ret] = 0x00;
printf(revData);


closesocket(serSocket);
closesocket(slisten);
WSACleanup();
getchar();
return 0;
}