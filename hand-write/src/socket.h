// 手写socket连接过程

#include <iostream>
// 注意api的头文件
#include <sys/socket.h>
// 专用socket地址+转换
#include <arpa/inet.h>
// bzero
#include <string.h>
#include <assert.h>

// 一些参数的宏
// #include <sys/types.h>
using namespace std;

// socket->connect
void client()
{
    char* IP = "127.0.0.1";
    int port = 54321;

    sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET,IP,&server_addr.sin_addr);

    int socket_fd = socket(PF_INET,SOCK_STREAM,0);
    assert(socket_fd >= 0);

    // connect只需要地址长度的值，而accpet需要指针
    int res = connect(socket_fd,(sockaddr*)&server_addr,sizeof(server_addr));
}

// socket->bind->listen->accept
void server()
{
    char* IP = "127.0.0.1";
    int port = 54321;

    // (domain/协议族：IPv4, type, protocol)
    int socket_fd = socket(PF_INET,SOCK_STREAM,0);
    
    sockaddr_in address;  
    bzero(&address,sizeof(address));
    // 地址族：IPv4
    address.sin_family = AF_INET;
    // 点分十进制 -> 网络字节序整数
    inet_pton(AF_INET,IP,&address.sin_addr);
    // 整型 主机字节序 -> 网络字节序
    address.sin_port = htons(port);

    // (socket_fd, sockaddr指针, 地址的长度)
    int res = bind(socket_fd,(sockaddr*)&address,sizeof(address));
    assert(res != -1);

    res = listen(socket_fd,5);
    assert(res != -1);

    sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int conn_fd = accept(socket_fd,(sockaddr*)&client_addr,&client_addr_len);

}