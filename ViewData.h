#pragma once
#ifndef _VIEWDATA_H_
#define _VIEWDATA_H_

#include "ControllerData.h"


using namespace SpaceControllerData;
namespace SpaceViewData
{
	class ViewData
	{
	private:
		ControllerData* controllerData;
	public:
		ViewData();
		~ViewData();
		ControllerData* GetControllerData();
		void UpdateControllerInput(IController* controllerInput);
		void UpdateControllerSocket(IController* controllerSocket);
	};
}
#endif