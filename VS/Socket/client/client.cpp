#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
//#include<Ws2tcpip.h>   //inet_pton
#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll

int main() {
    //��ʼ��DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);

    // 1. �����׽���
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. ���������������
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //inet_addr:old
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    // 3. ���շ��������ص�����
    char szBuffer[MAXBYTE] = { 0 };
    recv(sock, szBuffer, MAXBYTE, NULL);

    // 4. ������յ�������
    printf("Message form server: %s\n", szBuffer);

    // 5. �ر��׽���
    closesocket(sock);

    //��ֹʹ�� DLL
    WSACleanup();

    system("pause");
    return 0;
}