#pragma once
#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

#include <iostream>
#include <vector>

#include "sData.h"
#include "ModelData.h"

using namespace SpaceSData;
using namespace SpaceModelData;
namespace SpaceICommand
{
	class ICommand
	{
	public:
		virtual int UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput);
	};
}
#endif