
#include "ViewData.h"


namespace SpaceViewData
{
	ViewData::ViewData() 
	{
		controllerData = new ControllerData();
	}
	ViewData::~ViewData() 
	{
		delete controllerData;
	}
	ControllerData* ViewData::GetControllerData()
	{
		return this->controllerData;
	}
	void ViewData::UpdateControllerInput(IController* controllerInput)
	{
	
	}
	void ViewData::UpdateControllerSocket(IController* controllerSocket)
	{
		this->controllerData->AddObserver((IObserver*)controllerSocket);
	}
}