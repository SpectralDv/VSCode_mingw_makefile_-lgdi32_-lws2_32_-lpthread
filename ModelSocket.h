#pragma once
#ifndef _MODELSOCKET_H_
#define _MODELSOCKET_H_

#include "ISocket.h"

#include "Timer.h"
#include "sData.h"


using namespace SpaceSData;
using namespace SpaceTimer;
using namespace SpaceISocket;
namespace SpaceModelSocket
{

	class ModelSocket
	{
	public:
		ModelSocket();
		~ModelSocket();
	public:
		char* name;
		char* ip;
		int port;
		SOCKET socket;
		SOCKADDR_IN addr;
		int addr_size; 
		WSADATA ws;
		int wsOK;
		bool eventConnection;
		char stateConnection[16] = {};
		//char msgData[32] = {};
		Timer* timer;
		sData* sendData;
		sData* recvData;
		cData* cmdData;
		bool eventAnswer;
	};
}
#endif