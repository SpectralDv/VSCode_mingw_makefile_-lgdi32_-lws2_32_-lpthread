#pragma once
#ifndef _ISOCKET_H
#define _ISOCKET_H


//#define _CRT_SECURE_NO_WARNINGS
//#define _WINSOCK_DEPRECATED_NO_WARNINGS // for inet_addr("127.0.0.1");
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//#include <ws2tcpip.h>
#include <winsock.h>
//#include <windows.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <conio.h>
#include <chrono> 
#include <cstring>

//#pragma comment(lib,"ws2_32.lib")


using namespace std;

namespace SpaceISocket
{
    class ISocket
    {
    public:
        virtual void Start();
        virtual ~ISocket();

        virtual void Connection();
        virtual void Update();
    };
}
#endif