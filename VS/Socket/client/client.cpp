#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
//#include<Ws2tcpip.h>   //inet_pton
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

int main() {
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);

    // 1. 创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. 向服务器发起请求
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //inet_addr:old
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    // 3. 接收服务器传回的数据
    char szBuffer[MAXBYTE] = { 0 };
    recv(sock, szBuffer, MAXBYTE, NULL);

    // 4. 输出接收到的数据
    printf("Message form server: %s\n", szBuffer);

    // 5. 关闭套接字
    closesocket(sock);

    //终止使用 DLL
    WSACleanup();

    system("pause");
    return 0;
}