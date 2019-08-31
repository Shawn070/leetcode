#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll

int main() {
    //初始化 DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);

    // 1. 创建套接字 
    //int socket(int af, int type, int protocol);
    //af:   PF_INET 与 AF_INET 等效
    //type: SOCK_STREAM(基于TCP，有保障) SOCK_DGRAM(基于UDP，无保障)
    //protocol: IPPROTO_TCP IPPTOTO_UDP; 可设为 0，系统会自动推演出应该使用什么协议
    //TCP:
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);    //确定套接字的各种属性
    //UDP:
    //SOCKET udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  //IPPROTO_UDP表示UDP协议

    /*
    struct sockaddr_in{
        sa_family_t     sin_family;   //地址族（Address Family），也就是地址类型
        uint16_t        sin_port;     //16位的端口号,系统：0~1023，用户：1024~65536 ；Web 服务的端口号为 80，FTP 服务的端口号为 21
        struct in_addr  sin_addr;     //32位IP地址，如下
        char            sin_zero[8];  //不使用，一般用0填充
    };

    in_addr_t 在头文件 <netinet/in.h> 中定义，等价于 unsigned long，长度为4个字节。
    struct in_addr{
        in_addr_t  s_addr;  //32位的IP地址
    };

    struct sockaddr{
        sa_family_t  sin_family;   //地址族（Address Family），也就是地址类型
        char         sa_data[14];  //IP地址和端口号
    };
    */
    // 2. 绑定套接字         
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    sockAddr.sin_port = htons(1234);  //端口
    //int bind(SOCKET sock, const struct sockaddr *addr, int addrlen);
    //sock：socket 文件描述符
    //addr：sockaddr 结构体变量的指针
    //addrlen : addr 变量的大小，可由 sizeof() 计算得出
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR)); //将套接字与特定的 IP 地址和端口绑定起来

    // 3. 进入监听状态
    listen(servSock, 20);

    // 4. 通过服务器套接字servSock，接收客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);

    // 5. 通过客户端套接字clntSock，向客户端发送数据
    char *str = "Hello World!";
    send(clntSock, str, strlen(str) + sizeof(char), NULL);

    // 6. 关闭套接字
    /*
    close() / closesocket() 用来关闭套接字，将套接字描述符（或句柄）从内存清除，之后再也不能使用该套接字。
    shutdown() 用来关闭连接，而不是套接字，不管调用多少次 shutdown()，套接字依然存在，直到调用 close() / closesocket() 将套接字从内存清除。
    默认情况下，close()/closesocket() 会立即向网络中发送FIN包，不管输出缓冲区中是否还有数据，而shutdown() 会等输出缓冲区中的数据传输完毕再发送FIN包。也就意味着，调用 close()/closesocket() 将丢失输出缓冲区中的数据，而调用 shutdown() 不会。
    */
    closesocket(clntSock);
    closesocket(servSock);

    //终止 DLL 的使用
    WSACleanup();

    return 0;
}