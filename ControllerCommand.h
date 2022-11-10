#pragma once
#ifndef _CONTROLLERCOMMAND_H_
#define _CONTROLLERCOMMAND_H_

#include <map>
#include <cstring>

#include "ICommand.h"

using namespace std;

using namespace SpaceICommand;
namespace SpaceControllerCommand
{
	class ControllerCommand
	{
	public:
		//vector<string> vCommand;
		map<string, ICommand*> mapCommand;
	public:
		ControllerCommand();
		~ControllerCommand();
	};

	class CommandAddObject : public ICommand
	{
	public:
		CommandAddObject();
		~CommandAddObject();
		int UpdateCommand(vector<ModelData*> *vectorData, vector<cData>* vectorInput) override;
	};
	class CommandAddAttribute : public ICommand
	{
	public:
		CommandAddAttribute();
		~CommandAddAttribute();
		int UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput) override;
	};
	class CommandAddValue : public ICommand
	{
	public:
		CommandAddValue();
		~CommandAddValue();
		int UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput) override;
	};
	class CommandDeleteAttribute : public ICommand
	{
	public:
		CommandDeleteAttribute();
		~CommandDeleteAttribute();
		int UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput) override;
	};
	class CommandDeleteObject : public ICommand
	{
	public:
		CommandDeleteObject();
		~CommandDeleteObject();
		int UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput) override;
	};
}
#endif