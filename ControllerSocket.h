#pragma once
#ifndef _CONTROLLERSERVER_H_
#define _CONTROLLERSERVER_H_

#include <iostream>

#include "sData.h"
#include "ModelSocket.h"
#include "Timer.h"
#include "IObserver.h"
#include "IController.h"


using namespace SpaceIController;
using namespace SpaceObserver;
using namespace SpaceSData;
using namespace SpaceTimer;
using namespace SpaceModelSocket;
namespace SpaceControllerSocket
{
	class ControllerSocket : IController, IObservable
	{
	private:
		ModelSocket* mSocket;
		vector<ModelSocket*> vConnection;
		vector<IObserver*> observers;
	public:
		ControllerSocket();
		~ControllerSocket();
		void AddObserver(IObserver* o) override;
		void RemoveObserver(IObserver* o) override;
		void Notify(cData* data) override;
		int UpdateController(cData* data) override;
		ModelSocket* GetModelSocket();
		void Init(char* nameSocket, int port);
		int PressButton(int virtKey);
		void SendData(SOCKET sSend, SOCKADDR_IN addr, int addr_size, sData sendData);
		int RecvData(SOCKET sRecv, SOCKET sSend);
		int CheckConnection();
		void AddListConnect(char* nameSocket, int port);
		void RemoveModel(ModelSocket* mc);
		void RemoveSocket(char* nameSocket);
		ModelSocket* GetListConnect(string nameListener);
		void UpdateSocket();
		void Chat(SOCKET sSend, SOCKADDR_IN addr, int addr_size, SOCKET sRecv);
		void ChatThread(SOCKET sSend, SOCKADDR_IN addr, int addr_size, SOCKET sRecv);
		void CloseSocket();
	};
}
#endif