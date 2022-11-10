#pragma once
#ifndef _SDATA_H_
#define _SDATA_H_

namespace SpaceSData
{
	struct sData
	{
		int index = 0;
		char answer[16] = {};
		char connect[16] = {};
		char data[32] = {};
	};
	struct cData
	{
		char name[24] = {};
		char data[32] = {};
	};
}
#endif