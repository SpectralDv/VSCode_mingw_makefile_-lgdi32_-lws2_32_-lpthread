#pragma once
#ifndef _CONTROLLER_INPUT_
#define _CONTROLLER_INPUT_

#include <iostream>
#include <pthread.h>

#include "IObserver.h"
#include "IController.h"
#include "sData.h"
#include "ModelSocket.h"


using namespace std;

using namespace SpaceIController;
using namespace SpaceObserver;
using namespace SpaceSData;
namespace SpaceControllerInput
{
	class ControllerInput : IObservable, IController
	{
	private:
		vector<IObserver*> observers;
		vector<cData> vectorData;
	public:
		string name = "ControllerInput";
		cData* inputData;
		cData* command;
		//char nameMethod[16];
		//char nameObject[16];
		//char nameAttribut[16];
		//char nameType[16];
	public:
		ControllerInput();
		~ControllerInput();
		void InputData();
		virtual void ThreadProc(void* param);
		static void *ThreadStub(void* param);
		void AddObserver(IObserver* o) override;
		void RemoveObserver(IObserver* o) override;
		void Notify(cData* data) override;
		cData* GetInputData();
		cData GetVectorData(int index);
		int GetSizeVectorData();
		int ProcessingMessage();
	};
};
#endif