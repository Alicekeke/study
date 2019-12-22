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
SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
SOCKET serSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

//绑定IP和端口
sockaddr_in sin;
sin.sin_family = AF_INET;
sin.sin_port = htons(8888);
sin.sin_addr.S_un.S_addr = INADDR_ANY;

bind(slisten, (LPSOCKADDR)&sin, sizeof(sin));

//开始监听
listen(slisten,4);

//接受链接
sockaddr_in remoteAddr;
int nAddrlen = sizeof(remoteAddr);

printf("等待连接...\n");
serSocket = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));

//接收数据
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