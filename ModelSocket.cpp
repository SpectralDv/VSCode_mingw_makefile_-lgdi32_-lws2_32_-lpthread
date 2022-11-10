
#include "ModelSocket.h"


namespace SpaceModelSocket
{
	ModelSocket::ModelSocket() 
	{
		eventConnection = false;
		eventAnswer = false;
		timer = new Timer[1];
		sendData = new sData();
		cmdData = new cData();
	} 
	ModelSocket::~ModelSocket() { delete[] timer; delete sendData; delete cmdData; }
}


