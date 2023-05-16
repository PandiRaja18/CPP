#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{
    SOCKET serverSocket,acceptSocket;
    int port =1234;
    WSADATA wsaData;
    int wsaerror;
    WORD wVersionRequested = MAKEWORD(2,2);
    wsaerror = WSAStartup(wVersionRequested,&wsaData);
    if(wsaerror!=0)
    {
        cout<<" The winshock library was not found" <<endl;
        return 0;
    }
    else{
        cout<<"WSA started current status is -> "<<wsaData.szSystemStatus <<endl;
    }
    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET,SOCK_STREAM,0);
    if(serverSocket==INVALID_SOCKET)
    {
        cout<<"Error while creating socket : " << WSAGetLastError() <<endl;
    }
    else{
        cout<<"Socket created successfully..." <<endl;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    //InetPton(AF_INET,_T("127.0.0.1"),&service,sin_addr.s_addr);
    // if we don't know the IP address of our machine we can use spl IP 
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(port);
    if(bind(serverSocket,(SOCKADDR *)&service,sizeof(service))== SOCKET_ERROR)
    {
        cout<<"Bind Failed.." <<WSAGetLastError()<<endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }
    else{
        cout<<"Bind successfully done"<<endl;
    }
    if(listen(serverSocket,2)==SOCKET_ERROR)
    {
        cout<<"Problem arise while listening" <<endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }
    cout << "Server Listening for Incoming Connection .."<<endl;
    acceptSocket = accept(serverSocket,NULL,NULL);
    if(acceptSocket == INVALID_SOCKET)
    {
        cout<<"Problem while accepting connection .."<<endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }
    cout<<"Connection accepted .."<<endl;
    char buffer[4096] ={0};
    int bytesReceived;
    while (true) {
        // Receive data from the client
        char buffer[4096] ={0};
        bytesReceived = recv(acceptSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0 || strcmp(buffer,"bye")==0) {
            cout << "Connection closed by client." << endl;
            break;
        }
        else{
            cout <<"From Client :"<<buffer<<endl;
            send(acceptSocket, buffer, bytesReceived, 0);
        }
        
    }

    // Close the socket
    closesocket(acceptSocket);
    closesocket(serverSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}