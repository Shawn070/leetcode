#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll

int main() {
    //��ʼ�� DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);

    // 1. �����׽��� 
    //int socket(int af, int type, int protocol);
    //af:   PF_INET �� AF_INET ��Ч
    //type: SOCK_STREAM(����TCP���б���) SOCK_DGRAM(����UDP���ޱ���)
    //protocol: IPPROTO_TCP IPPTOTO_UDP; ����Ϊ 0��ϵͳ���Զ����ݳ�Ӧ��ʹ��ʲôЭ��
    //TCP:
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);    //ȷ���׽��ֵĸ�������
    //UDP:
    //SOCKET udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  //IPPROTO_UDP��ʾUDPЭ��

    /*
    struct sockaddr_in{
        sa_family_t     sin_family;   //��ַ�壨Address Family����Ҳ���ǵ�ַ����
        uint16_t        sin_port;     //16λ�Ķ˿ں�,ϵͳ��0~1023���û���1024~65536 ��Web ����Ķ˿ں�Ϊ 80��FTP ����Ķ˿ں�Ϊ 21
        struct in_addr  sin_addr;     //32λIP��ַ������
        char            sin_zero[8];  //��ʹ�ã�һ����0���
    };

    in_addr_t ��ͷ�ļ� <netinet/in.h> �ж��壬�ȼ��� unsigned long������Ϊ4���ֽڡ�
    struct in_addr{
        in_addr_t  s_addr;  //32λ��IP��ַ
    };

    struct sockaddr{
        sa_family_t  sin_family;   //��ַ�壨Address Family����Ҳ���ǵ�ַ����
        char         sa_data[14];  //IP��ַ�Ͷ˿ں�
    };
    */
    // 2. ���׽���         
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //�����IP��ַ
    sockAddr.sin_port = htons(1234);  //�˿�
    //int bind(SOCKET sock, const struct sockaddr *addr, int addrlen);
    //sock��socket �ļ�������
    //addr��sockaddr �ṹ�������ָ��
    //addrlen : addr �����Ĵ�С������ sizeof() ����ó�
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR)); //���׽������ض��� IP ��ַ�Ͷ˿ڰ�����

    // 3. �������״̬
    listen(servSock, 20);

    // 4. ͨ���������׽���servSock�����տͻ�������
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);

    // 5. ͨ���ͻ����׽���clntSock����ͻ��˷�������
    char *str = "Hello World!";
    send(clntSock, str, strlen(str) + sizeof(char), NULL);

    // 6. �ر��׽���
    /*
    close() / closesocket() �����ر��׽��֣����׽��������������������ڴ������֮����Ҳ����ʹ�ø��׽��֡�
    shutdown() �����ر����ӣ��������׽��֣����ܵ��ö��ٴ� shutdown()���׽�����Ȼ���ڣ�ֱ������ close() / closesocket() ���׽��ִ��ڴ������
    Ĭ������£�close()/closesocket() �������������з���FIN��������������������Ƿ������ݣ���shutdown() �������������е����ݴ�������ٷ���FIN����Ҳ����ζ�ţ����� close()/closesocket() ����ʧ����������е����ݣ������� shutdown() ���ᡣ
    */
    closesocket(clntSock);
    closesocket(servSock);

    //��ֹ DLL ��ʹ��
    WSACleanup();

    return 0;
}