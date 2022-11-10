
#include "ViewSocket.h"


using namespace SpaceControllerSocket;
namespace SpaceViewSocket
{
	ViewSocket::ViewSocket()
	{
		controllerSocket = new ControllerSocket();
	}
	ViewSocket::~ViewSocket() 
	{
		delete controllerSocket;
	}
	void ViewSocket::StartSocket(int portSend, int portRecv)
	{
		controllerSocket->Init((char*)"RecvSocket", portRecv);
		controllerSocket->AddListConnect((char*)"SendSocket", portSend);
		controllerSocket->UpdateSocket();
	}
	ControllerSocket* ViewSocket::GetControllerSocket()
	{
		return this->controllerSocket;
	}
	void ViewSocket::UpdateControllerInput(IController* controllerInput)
	{

	}
	void ViewSocket::UpdateControllerData(IController* controllerData) 
	{
		this->controllerSocket->AddObserver((IObserver*)controllerData);
	}
}