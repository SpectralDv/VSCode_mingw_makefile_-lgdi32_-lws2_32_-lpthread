#pragma once
#ifndef _MODELDATA_H_
#define _MODELDATA_H_

#include <vector>

#include "ModelAttribute.h"

using namespace std;

using namespace SpaceModelAttribute;
namespace SpaceModelData
{
	class ModelData
	{
	public:
		char name[32];
		vector<IAttribute*> iattribute;
	public:
		ModelData();
		~ModelData();
	};
}
#endif