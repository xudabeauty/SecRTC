#include "../inlcude/iocpserver.h"
//void errorHandle(int result,char*msg);
IOCPServer::IOCPServer()
{
    WSADATA wsaData;
    int ret=WSAStartup(MAKEWORD(2,2), &wsaData);
    m_Default_port=6000;
    m_hEvent= NULL;
    //errorHandle(ret,"startup()");
}
IOCPServer::~IOCPServer()
{
    WSACloseEvent(m_hEvent);
    /*closesocket(m_socListen);
    WSACleanup();
    CloseHandle(m_hCompletionPort);*/
}
void IOCPServer::initialize(int port)
{
    hMutex=CreateMutex(NULL, FALSE, NULL);
    m_hCompletionPort=CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, 0, 0);
    initIOCP();
    m_socListen=socket(AF_INET,SOCK_STREAM,0);
    m_hEvent = WSACreateEvent();
    SOCKADDR_IN seraddr;
    seraddr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    seraddr.sin_family=AF_INET;
    seraddr.sin_port=htons(m_Default_port);
    int ret=bind(m_socListen,(sockaddr*)&seraddr,sizeof(sockaddr));
    //errorHandle(ret,"bind()");
    ret=listen(m_socListen,10);
     cout << "listeinging，正在等待客户端的接入...\n";
     HANDLE sendThread = CreateThread(NULL, 0, ServerSendThread, (void*)this, 0, NULL);

    //cout<<"Send_thread:"<<sendThread<<endl;


}


void IOCPServer::initIOCP()
{

    SYSTEM_INFO mySysInfo;
    GetSystemInfo(&mySysInfo);

    // 创建2*cpu个线程
    for(DWORD i = 0; i < (mySysInfo.dwNumberOfProcessors * 2); ++i){
        // 创建服务器工作器线程，并将完成端口传递到该线程

        HANDLE ThreadHandle = CreateThread(NULL,0,ServerWorkThread,(void*)this,0,NULL);
        //cout<<"work_thread"<<i<<ThreadHandle<<endl;
        CloseHandle(ThreadHandle);
    }
}


void IOCPServer::OnAccept()
{
    PER_HANDLE_DATA * PerHandleData = NULL;
    SOCKADDR_IN saRemote;
    int RemoteLen;
    SOCKET acceptSocket;

    RemoteLen = sizeof(saRemote);
    while (true)
    {
        acceptSocket = accept(m_socListen, (SOCKADDR*)&saRemote, &RemoteLen);
        if(SOCKET_ERROR == acceptSocket){	// 接收客户端失败
            cerr << "Accept Socket Error: " << GetLastError() << endl;
            system("pause");
            return ;
        }

        /*CString hostname=GetHostName(acceptSocket);
        LPWSTR host=(LPWSTR)hostname.GetBuffer(0);
        const wchar_t * lpctstr=(LPCTSTR)hostname; */
        char hostname[48]={0};
        GetHostName(acceptSocket,hostname);
        cout<<"host:"<<hostname;
        //printf("%ls", lpctstr);
        cout<<" 连入,打个招呼吧！\n";

        // 创建用来和套接字关联的单句柄数据信息结构
        PerHandleData = (LPPER_HANDLE_DATA)GlobalAlloc(GPTR, sizeof(PER_HANDLE_DATA));	// 在堆中为这个PerHandleData申请指定大小的内存
        PerHandleData -> socket = acceptSocket;
        memcpy (&PerHandleData -> ClientAddr, &saRemote, RemoteLen);
        clientGroup.push_back(PerHandleData);		// 将单个客户端数据指针放到客户端组中

        // 套接字和完成端口关联
        CreateIoCompletionPort((HANDLE)(PerHandleData -> socket), m_hCompletionPort, (DWORD)PerHandleData, 0);

        LPPER_IO_OPERATION_DATA PerIoData = NULL;
        PerIoData = (LPPER_IO_OPERATION_DATA)GlobalAlloc(GPTR, sizeof(PER_IO_OPERATEION_DATA));



        //DWORD RecvBytes;
        //DWORD Flags = 0;
        //WSARecv(PerHandleData->socket, &(PerIoData->databuff), 1, &RecvBytes, &Flags, &(PerIoData->overlapped), NULL);
        postReciv(PerIoData,PerHandleData);
    }

     system("pause");


}


void IOCPServer::postReciv(PER_IO_DATA*periodata,PER_HANDLE_DATA*perhandledata)
{
    ZeroMemory(&(periodata -> overlapped), sizeof(OVERLAPPED));
    periodata->databuff.len = 1024;
    periodata->databuff.buf = periodata->buffer;
    periodata->operationType = 0;	// read
    DWORD RecvBytes;
    DWORD Flags = 0;
    WSARecv(perhandledata->socket, &(periodata->databuff), 1, &RecvBytes, &Flags, &(periodata->overlapped), NULL);
}

DWORD WINAPI IOCPServer::ServerWorkThread(LPVOID lpParam)
{
    WSANETWORKEVENTS events;
    IOCPServer* pthis=(IOCPServer*)lpParam;
    HANDLE CompletionPort = pthis->m_hCompletionPort;
    DWORD BytesTransferred;
    LPOVERLAPPED IpOverlapped;
    LPPER_HANDLE_DATA PerHandleData = NULL;
    LPPER_IO_DATA PerIoData = NULL;

    DWORD RecvBytes;
    DWORD Flags = 0;
    BOOL bRet = false;
    int port=pthis->m_Default_port;

    while(true){
        bRet = GetQueuedCompletionStatus(CompletionPort, &BytesTransferred, (PULONG_PTR)&PerHandleData, (LPOVERLAPPED*)&IpOverlapped, INFINITE);
        if(bRet == 0){
            cerr << "GetQueuedCompletionStatus Error: " << GetLastError() << endl;
            return -1;
        }
        PerIoData = (LPPER_IO_DATA)CONTAINING_RECORD(IpOverlapped, PER_IO_DATA, overlapped);

        // 检查在套接字上是否有错误发生
        if(0 == BytesTransferred){
            closesocket(PerHandleData->socket);
            GlobalFree(PerHandleData);
            GlobalFree(PerIoData);
            continue;
        }


        // 开始数据处理，接收来自客户端的数据
        WaitForSingleObject(pthis->hMutex,INFINITE);
        /*
        TO DO
        */
        cout << "A Client says: " << PerIoData->databuff.buf << endl;
        ReleaseMutex(pthis->hMutex);

        // 为下一个重叠调用建立单I/O操作数据
        //void IOCPServer::postReciv(PerIoData*periodata,PER_HANDLE_DATA perhandledata);
        IOCPServer *iocpsserver=new IOCPServer();
        iocpsserver->postReciv(PerIoData,PerHandleData);
        delete iocpsserver;
    }
    return 0;
}

DWORD WINAPI IOCPServer:: ServerSendThread(LPVOID IpParam)
{
    IOCPServer *pthis=(IOCPServer*)(IpParam);
    while (true)
    {
        char talk[200];
        gets(talk);
        int len;
        for (len = 0; talk[len] != '\0'; ++len){
            // 找出这个字符组的长度
        }
        talk[len] = '\n';
        talk[++len] = '\0';
        printf("\nI Say:");
        cout << talk;
        //char message[200];
        WaitForSingleObject(pthis->hMutex,INFINITE);
        for(int i = 0; i < pthis->clientGroup.size(); ++i){
            send(pthis->clientGroup[i]->socket, talk, 200, 0);  // 发送信息
        }
        ReleaseMutex(pthis->hMutex);
    }


    return 0;
}


void IOCPServer::GetHostName(SOCKET socket,char *hostname)
{
    sockaddr_in  sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));

    int nSockAddrLen = sizeof(sockAddr);

    BOOL bResult = getpeername(socket,(SOCKADDR*)&sockAddr, &nSockAddrLen);
    char * host=inet_ntoa(sockAddr.sin_addr);
    strcpy(hostname,host);

}


//void errorHandle(int result,char msg)
//{
//	if(result==SOCKET_ERROR)
//	{
//		cout<<msg<<"error"<<endl;
//	}
//}
