#pragma once
#ifndef _VIEWSOCKET_H_
#define _VIEWSOCKET_H_

#include "ControllerSocket.h"


using namespace SpaceControllerSocket;
namespace SpaceViewSocket
{
	class ViewSocket
	{
	private:
		ControllerSocket* controllerSocket;
	public:
		ViewSocket();
		~ViewSocket();
		void StartSocket(int portSend, int portRecv);
		ControllerSocket* GetControllerSocket();
		void UpdateControllerInput(IController* controllerInput);
		void UpdateControllerData(IController* controllerData);
	};
}
#endif