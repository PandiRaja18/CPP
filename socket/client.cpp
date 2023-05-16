#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <iostream>
#include<cstring>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{
    SOCKET clientsocket,acceptSocket;
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
    clientsocket = INVALID_SOCKET;
    clientsocket = socket(AF_INET,SOCK_STREAM,0);
    if(clientsocket==INVALID_SOCKET)
    {
        cout<<"Error while creating socket : " << WSAGetLastError() <<endl;
    }
    else{
        cout<<"Socket created successfully..." <<endl;
    }
    sockaddr_in client_service;
    client_service.sin_family = AF_INET;
    client_service.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_service.sin_port = htons(1234);
    if(connect(clientsocket,(SOCKADDR *)&client_service,sizeof(client_service)) ==SOCKET_ERROR)
    {
        cout<<"Client connection failed.." <<endl;
        closesocket(clientsocket);
        WSACleanup();
        return 0;
    }
    else{
        cout<<"Connection establicshed between server and client .."<<endl;
    }
    int bytesReceived;
    while(true)
    {
        char buffer[1024] ={0};
        char message[30];
        cout<<"Client : Type your maessage..>"<<endl;
        cin.getline(message,30);
        send(clientsocket, message, strlen(message), 0);
        bytesReceived = recv(clientsocket, buffer, 1024,0);
        if(bytesReceived<=0 || strcmp(message,"bye")==0)
        {
            cout<<"Connection ended";
            break;
        }
        cout <<"Response from server : "<<buffer <<endl;
    }
    // closing the connected socket
    closesocket(clientsocket);
    WSACleanup();
    return 0;
}

    