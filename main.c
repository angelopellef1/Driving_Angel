
#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include "protocol.h"


#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>

// Need to link with Ws2_32.lib
//#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"



#if 0
#ifdef _WIN32
//For Windows
int betriebssystem = 1;
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <ws2def.h>
#pragma comment(lib, "Ws2_32.lib")
#include <windows.h>
#include <io.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int betriebssystem = 2;
#endif
#endif

struct Key_Action   *strike;
INPUT ip;

extern struct Protocol_Row Table[];


void Release(INPUT *ip,unsigned  char key)
{
    ip->ki.wVk = key; // virtual-key code for the "a" key
    ip->ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, ip, sizeof(INPUT));
}

void Press(INPUT *ip,unsigned  char key)
{
    ip->ki.wVk = key; // virtual-key code for the "a" key
    ip->ki.dwFlags = 0; // 0 for key press
    SendInput(1, ip, sizeof(INPUT));
}

void PressAndRelease(INPUT *ip,unsigned  char key)
{
    ip->ki.wVk = key; // virtual-key code for the "a" key
    ip->ki.dwFlags = 0; // 0 for key press
    SendInput(1, ip, sizeof(INPUT));
 
    // Release the "A" key
    ip->ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, ip, sizeof(INPUT));
}

void KeyInject(char *buffer_rcv){
     int i, s, r,a;

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    char cmdtype_pr_raw = buffer_rcv[0];
    char action = buffer_rcv[1];

    if(PRESET == (enum Command_Type)cmdtype_pr_raw)
    {
        for(i=0;i<MAX_COMM;i++){
            if(Table[i].action == action) 
                break;
        }

        if(i== MAX_COMM) {
            return ;
        }

        if(Table[i].type == PRESET){
            a=0;
            strike = Table[i].key_act;
            while(strike->beha < STOP)
            {

                printf("\nDo protocol row  %2i action %2i", i,a);
                if(strike->beha == COMBO){
                    for(r=0;r<strike->repeat;r++){
                        Press(&ip,strike->key1);
                        PressAndRelease(&ip,strike->key2);
                        Release(&ip,strike->key2);
                        Sleep(300);
                    }
                }
                else if(strike->beha == SINGLE){ 
                    for(r=0;r<strike->repeat;r++){
                        printf("\ntimes %2i ", r);

                        PressAndRelease(&ip,strike->key1);
                        Sleep(300);
                    }

                }
                a++;
                strike++;
            }
                        printf("\nend preset ");

        }
    }
    else
    {
        PressAndRelease(&ip,buffer_rcv[1]);
    }

}



int __cdecl main(){
    
     WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    
    printf("DRIVING ANGEL v%.3i \n\rConnect to port 27015 on one of following IP:\n\r",VERSION);
    system("ipconfig | findstr IPv4");
     

    do{
         // Initialize Winsock
        if (iResult != 0) {
            printf("WSAStartup failed with error: %d\n", iResult);
            return 1;
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_PASSIVE;

        // Resolve the server address and port
        iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
        if ( iResult != 0 ) {
            printf("getaddrinfo failed with error: %d\n", iResult);
            WSACleanup();
            return 1;
        }

        // Create a SOCKET for connecting to server
        ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (ListenSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            freeaddrinfo(result);
            WSACleanup();
            return 1;
        }

        // Setup the TCP listening socket
        iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            printf("bind failed with error: %d\n", WSAGetLastError());
            freeaddrinfo(result);
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }

        freeaddrinfo(result);

        iResult = listen(ListenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR) {
            printf("listen failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }

        // Accept a client socket
        ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket == INVALID_SOCKET) {
            printf("accept failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }

        // No longer need server socket
        closesocket(ListenSocket);

        // Receive until the peer shuts down the connection
        do {

            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0) {
                printf("Bytes received: %d\n", iResult);


            // Echo the buffer back to the sender
            iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult);

            //Do the key inject
            KeyInject(recvbuf);

            
            }
            else if (iResult == 0){
                    //printf("Connection closing...\n");
            } else  {
                printf("recv failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }

        } while (iResult > 0);

        // shutdown the connection since we're done
        iResult = shutdown(ClientSocket, SD_SEND);
        if (iResult == SOCKET_ERROR) {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

        // cleanup
        closesocket(ClientSocket);
        WSACleanup();
    }while(1);
    

    return 0;

}


