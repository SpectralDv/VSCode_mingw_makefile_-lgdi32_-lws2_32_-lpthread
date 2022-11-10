#pragma once
#ifndef _VIEWMAIN_H_
#define _VIEWMAIN_H_

#include <iostream>

#include "ViewSocket.h"
#include "ViewInput.h"
#include "ViewData.h"
#include "IController.h"


using namespace std;

using namespace SpaceIController;
using namespace SpaceViewInput;
using namespace SpaceViewSocket;
using namespace SpaceViewData;
namespace SpaceViewMain
{
	class ViewMain
	{
	public:
		ViewSocket* viewSocket;
		ViewInput* viewInput;
		ViewData* viewData;
	public:
		ViewMain();
		~ViewMain();
		void Init();
		void Update();
		void MainInfo();
	};
}
#endif