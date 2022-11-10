#pragma once
#ifndef _ICONTROLLER_H_
#define _ICONTROLLER_H_

#include <iostream>

#include "sData.h"

using namespace SpaceSData;
namespace SpaceIController
{
	class IController
	{
	public:
		std::string name = "IController";
	public:
		virtual int UpdateController(cData* data);
	};
}
#endif