

#include "ControllerSocket.h"


namespace SpaceControllerSocket
{
	ControllerSocket::ControllerSocket()
	{
		name = "ControllerSocket";
		mSocket = new ModelSocket();
	}
	ControllerSocket::~ControllerSocket()
	{
		delete mSocket;
		sData sendData;
		strcpy(sendData.connect, "disconnected");
		SendData(vConnection[0]->socket, vConnection[0]->addr, vConnection[0]->addr_size, sendData);
		CloseSocket();
		printf("~ControllerSocket");
	}
	void ControllerSocket::AddObserver(IObserver* o)
	{
		//printf("AddObserverSocket %s\n", ((IController*)o)->name.c_str());
		//printf("AddObserverSocket %x\n", ((IController*)o));
		observers.push_back(o);
	}
	void ControllerSocket::RemoveObserver(IObserver* o)
	{
		vector<IObserver*>::iterator itErase = observers.begin();
		for (itErase; itErase != observers.end(); itErase++)
		{
			if (*itErase == o) { observers.erase(itErase); break; }
		}
	}
	void ControllerSocket::Notify(cData* data)
	{
		for (auto o : observers) 
		{ 
			((IController*)o)->UpdateController(data);
			//printf("NotifySocket: %s\n", ((IController*)o)->name.c_str());
			//printf("ControllerData: %s\n", ((ControllerData*)o)->GetModelData(0)->name);
		}
	}
	int ControllerSocket::UpdateController(cData* data)
	{
		if (strcmp(vConnection[0]->sendData->data, "nosend") == 0) { }
		else { strcpy(vConnection[0]->sendData->data, data->data); }
		return 0;
	}

	ModelSocket* ControllerSocket::GetModelSocket()
	{
		return mSocket;
	}

	void ControllerSocket::Init(char* nameSocket, int port)
	{
		//printf("Create Init %s", nameSocket);
		try {
			mSocket->wsOK = WSAStartup(MAKEWORD(2, 2), &mSocket->ws);
			if (mSocket->wsOK != 0) { cout << "Can't start winsock" << endl; }
			mSocket->name = nameSocket;
			// SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			mSocket->socket = socket(PF_INET, SOCK_DGRAM, 0);
			mSocket->addr.sin_family = AF_INET; //IP_W4
			mSocket->addr.sin_port = htons(port);
			mSocket->addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //ADDR_ANY; //
			mSocket->addr_size = sizeof(mSocket->addr);

			//printf(" Successfull \n");
		}
		catch (exception& e) {
			printf("Failed %s\n", e.what());
		}
	}

	void ControllerSocket::AddListConnect(char* nameSocket, int port)
	{
		ModelSocket* ms = new ModelSocket();

		ms->name = nameSocket;
		ms->socket = socket(PF_INET, SOCK_DGRAM, 0);
		ms->addr.sin_family = AF_INET; //IP_W4
		ms->addr.sin_port = htons(port);
		ms->addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //ADDR_ANY; //
		ms->addr_size = sizeof(ms->addr);

		strcpy(ms->sendData->answer, " ");
		strcpy(ms->sendData->connect, "connected");
		strcpy(ms->sendData->data, " ");

		vConnection.push_back(ms);

		//printf("%s", mSocket->name);
		//printf(": AddListConnect: %s\n", vConnection[0]->name);
	}
	void ControllerSocket::RemoveModel(ModelSocket* model)
	{
		vector<ModelSocket*>::iterator it = vConnection.begin();
		for (it; it != vConnection.end(); it++)
		{
			if (*it == model) { vConnection.erase(it); break; }
		}
	}
	void ControllerSocket::RemoveSocket(char* nameSocket)
	{
		for (int i = 0; i < vConnection.size(); i++)
		{
			if (vConnection[i]->name == nameSocket)
			{
				printf("SearchListener: %s\n", vConnection[i]->name);
				RemoveModel(vConnection[i]);
			}
		}
	}
	ModelSocket* ControllerSocket::GetListConnect(string nameListener)
	{
		for (int i = 0; i < vConnection.size(); i++)
		{
			if (vConnection[i]->name == nameListener)
			{
				printf("SearchListener: %s\n", vConnection[i]->name);
				return vConnection[i]; //break; 
			}
		}
		return nullptr;
	}

	void ControllerSocket::UpdateSocket()
	{
		bind(mSocket->socket, (const SOCKADDR*)&(mSocket->addr), mSocket->addr_size);
		listen(mSocket->socket, 1);

		Chat(vConnection[0]->socket, vConnection[0]->addr, vConnection[0]->addr_size, mSocket->socket);
	}

	void ControllerSocket::Chat(SOCKET sSend, SOCKADDR_IN addr, int addr_size, SOCKET sRecv)
	{
		//WSAEventSelect(sRecv, 0, FD_READ);
		//WSAAsyncSelect(sRecv, 0,0,0);

		do {
			if (PressButton(0x70) == 0) {}

			SendData(sSend, addr, addr_size, *vConnection[0]->sendData);

			CheckConnection();

			RecvData(sRecv, sSend);
			
			Sleep(1);
		//} while (strcmp(vConnection[0]->sendData->data, "exit") != 0);
		} while ((GetKeyState(VK_ESCAPE) >= 0) || (GetForegroundWindow() != GetConsoleWindow()));
	}

	void ControllerSocket::ChatThread(SOCKET sSend, SOCKADDR_IN addr, int addr_size, SOCKET sRecv)
	{
		SendData(sSend, addr, addr_size, *vConnection[0]->sendData);

		CheckConnection();

		RecvData(sRecv, sSend);
	}

	int ControllerSocket::CheckConnection()
	{
		if (vConnection[0]->eventConnection == false)
		{
			if (strcmp(vConnection[0]->stateConnection, "connected") == 0)
			{
				vConnection[0]->eventConnection = true;
				printf("\n");
				printf("%s", inet_ntoa(vConnection[0]->addr.sin_addr));
				printf(": %d", ntohs(vConnection[0]->addr.sin_port));
				printf(" %s\n", vConnection[0]->stateConnection);
				return 0;
			}
		}
		if (vConnection[0]->eventConnection == true)
		{
			if (vConnection[0]->timer[0].GetTimer(1000) == 1)
			{
				strcpy(vConnection[0]->stateConnection, "disconnected");
			}
			if (strcmp(vConnection[0]->stateConnection, "disconnected") == 0)
			{
				vConnection[0]->eventConnection = false;
				printf("\n");
				printf("%s", inet_ntoa(vConnection[0]->addr.sin_addr));
				printf(": %d", ntohs(vConnection[0]->addr.sin_port));
				printf(" %s\n", vConnection[0]->stateConnection);
				return 0;
			}
		}
		return 0;
	}

	int ControllerSocket::PressButton(int virtKey)
	{
		static bool event_down = false; static bool event_state = false;
		if (GetKeyState(virtKey) < 0)
		{
			event_state = true;
			if ((event_down != event_state) && (GetForegroundWindow() == GetConsoleWindow()))
			{
				event_down = event_state;
				return 0;
			}
		}
		else { event_state = false; event_down = false; }
		return 1;
	}

	void ControllerSocket::SendData(SOCKET sSend, SOCKADDR_IN addr, int addr_size, sData sendData)
	{
		int sb;
		sb = sendto(sSend, (const char*)&sendData, sizeof(sendData), 0, (SOCKADDR*)&addr, addr_size);
		if (strcmp(vConnection[0]->sendData->data, " ") != 0)
		{
			strcpy(vConnection[0]->sendData->data, " ");
		}
		if (strcmp(vConnection[0]->sendData->answer, " ") != 0)
		{
			strcpy(vConnection[0]->sendData->answer, " ");
		}
	}
	int ControllerSocket::RecvData(SOCKET sRecv, SOCKET sSend)
	{
		sData rdata;

		int rb;
		SOCKADDR_IN addrRecv;
		int sizeRecv = sizeof(addrRecv);

		rb = recvfrom(sRecv, (char*)&rdata, sizeof(rdata), 0, (SOCKADDR*)&addrRecv, &sizeRecv);

		if (rb > 0)
		{
			vConnection[0]->timer[0].ResetTimer();

			strcpy(vConnection[0]->stateConnection, rdata.connect);

			if (strcmp(rdata.data, " ") != 0)
			{
				printf("%s", inet_ntoa(vConnection[0]->addr.sin_addr));
				printf(": %d", ntohs(vConnection[0]->addr.sin_port));
				printf(": %s\n", rdata.data);
				strcpy(vConnection[0]->cmdData->data, rdata.data);
				strcpy(vConnection[0]->cmdData->name, "ControllerSocket");
				this->Notify(vConnection[0]->cmdData);
			}
		}
		return 0;
	}

	void ControllerSocket::CloseSocket()
	{
		closesocket(mSocket->socket);
		for (int i = 0; i < vConnection.size(); i++)
		{
			closesocket(vConnection[i]->socket);
		}
		WSACleanup();
	}
}