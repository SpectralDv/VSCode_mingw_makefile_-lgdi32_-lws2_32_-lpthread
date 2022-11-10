
#include "ViewInput.h"


namespace SpaceViewInput
{
	ViewInput::ViewInput() 
	{
		this->controllerInput = new ControllerInput();
		//this->th = new thread(&ControllerInput::InputData, this->controllerInput);
		pthread_create(&th,NULL,ControllerInput::ThreadStub,(void*)NULL);
		pthread_join(th, NULL);
	}
	ViewInput::~ViewInput() 
	{
		//this->th->detach();
		pthread_detach(th);
		delete this->controllerInput;
	}
	ControllerInput* ViewInput::GetControllerInput()
	{	
		return this->controllerInput;
	}
	void ViewInput::UpdateControllerSocket(IController* controllerSocket)
	{

	}
	void ViewInput::UpdateControllerData(IController* controllerData)
	{
		this->controllerInput->AddObserver((IObserver*)controllerData);
	}
}