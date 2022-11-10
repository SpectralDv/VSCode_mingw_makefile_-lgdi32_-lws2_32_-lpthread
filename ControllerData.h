#pragma once
#ifndef _CONTROLLERDATA_H
#define _CONTROLLERDATA_H

#include "IObserver.h"
#include "ModelData.h"
#include "IController.h"
#include "ControllerCommand.h"


using namespace SpaceControllerCommand;
using namespace SpaceObserver;
using namespace SpaceIController;
using namespace SpaceModelData;
namespace SpaceControllerData
{
	class ControllerData : IController, IObserver, IObservable
	{
	private:
		cData* data;
		ControllerCommand* controllerCommand;
		vector<cData> vectorInput;
		vector<ModelData*> vectorData;
		vector<IObserver*> observers;
	public:
		ControllerData();
		~ControllerData();
		void AddObserver(IObserver* o) override;
		void RemoveObserver(IObserver* o) override;
		void Notify(cData* data) override;
		void UpdateObserver(cData* data) override;
		int UpdateController(cData* data) override;
		int CheckGetMessage();
		int GetSizeData();
		int ProcessingMessage();
		int ProcessingCommand();
		int GetListObject();
		int GetObject();
		int PrintParams(int indexData);
	};
}
#endif