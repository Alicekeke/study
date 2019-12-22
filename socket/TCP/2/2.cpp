// 2.cpp : Defines the entry point for the console application.
//


//客户端
#include "stdafx.h"
#include <winsock2.h>
#pragma  comment(lib,"ws2_32.lib")

int main()
{
getchar();
WORD sockVersion = MAKEWORD(2,2);
WSADATA wsaData;
WSAStartup(sockVersion, &wsaData);

SOCKET serSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(8888);
sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
connect(serSocket, (sockaddr *)&sin, sizeof(sin));

char * sendData = "你好，TCP服务端，我是客户端!\n";
send(serSocket, sendData, strlen(sendData), 0);

closesocket(serSocket);
WSACleanup();
getchar();
return 0;
}
