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
SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

//��IP�Ͷ˿�
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(8888);
sin.sin_addr.S_un.S_addr = INADDR_ANY; 
int len=sizeof(sin);
bind(serSocket, (sockaddr *)&sin, sizeof(sin));

//�������������ӣ�ֱ�ӽ�������

char revData[255]; 

//��������
printf("�ȴ�����...\n");
int ret = recvfrom(serSocket, revData, 255, 0, (sockaddr *)&sin, &len); 
if(ret>0)
{
revData[ret] = 0x00; //'\0'
printf(revData);
}

closesocket(serSocket);
WSACleanup();
getchar();
return 0;
}