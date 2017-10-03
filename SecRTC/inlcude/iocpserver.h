#ifndef IOCPSERVER_H
#define IOCPSERVER_H
#include<winsock2.h>
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma  comment(lib,"ws2_32")
#pragma  comment(lib,"kernel32")
const int DataBuffSize  = 2 * 1024;
typedef struct
{
    OVERLAPPED overlapped;
    WSABUF databuff;
    char buffer[ DataBuffSize ];
    int BufferLen;
    int operationType;
}PER_IO_OPERATEION_DATA, *LPPER_IO_OPERATION_DATA, *LPPER_IO_DATA, PER_IO_DATA;

/**
 * 结构体名称：PER_HANDLE_DATA
 * 结构体存储：记录单个套接字的数据，包括了套接字的变量及套接字的对应的客户端的地址。
 * 结构体作用：当服务器连接上客户端时，信息存储到该结构体中，知道客户端的地址以便于回访。
 **/
typedef struct
{
    SOCKET socket;
    SOCKADDR_STORAGE ClientAddr;
}PER_HANDLE_DATA, *LPPER_HANDLE_DATA;


class IOCPServer

{
public:
    IOCPServer();
    ~IOCPServer();
    void initialize(int port);
    static DWORD WINAPI ServerWorkThread(LPVOID lpParam);
    static DWORD WINAPI ServerSendThread(LPVOID lpPrama);
    void OnAccept();
    void initIOCP();
    void postReciv(PER_IO_DATA*periodata,PER_HANDLE_DATA *perhandledata);
    void sendData(char *data);
    void recvData();
    void shoutdown();
    void GetHostName(SOCKET sock,char *hostname);
    vector < PER_HANDLE_DATA* > clientGroup;
protected:
    SOCKET	m_socListen;
    UINT m_Default_port;
    HANDLE	m_hCompletionPort;
    HANDLE hMutex;
    WSAEVENT m_hEvent;


private:
};
#endif // IOCPSERVER_H
