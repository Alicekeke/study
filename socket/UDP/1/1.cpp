// 1.cpp : Defines the entry point for the console application.
//


//服务器端
#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
//初始化WSA
WORD sockVersion = MAKEWORD(2,2);
WSADATA wsaData;
WSAStartup(sockVersion, &wsaData);

//创建套接字
SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

//绑定IP和端口
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(8888);
sin.sin_addr.S_un.S_addr = INADDR_ANY; 
int len=sizeof(sin);
bind(serSocket, (sockaddr *)&sin, sizeof(sin));

//不监听，无连接，直接接收数据

char revData[255]; 

//接收数据
printf("等待连接...\n");
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