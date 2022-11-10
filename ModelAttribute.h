#pragma once
#ifndef _MODELATTRIBUTE_H_
#define _MODELATTRIBUTE_H_

#include <iostream>

namespace SpaceModelAttribute
{
	class PAttribute
	{
	public:
		char* attribute;
	public:
		~PAttribute();
	};
	class IAttribute
	{
	public:
		char name[16] = "iname";
		char type[16] = "iattribute";
	};
	class ModelAttribute
	{
	public:
		char type[16];
		bool event;
		int value;
		char text[32];
	};
	class ModelChar : IAttribute
	{
	public:
		char text[32] = " ";
	public:
		ModelChar();
		~ModelChar();
	};
	class ModelInt : IAttribute
	{
	public:
		int value = 0;
	public:
		ModelInt();
		~ModelInt();
	};
	class ModelBool : IAttribute
	{
	public:
		bool event = false;
	public:
		ModelBool();
		~ModelBool();
	};
}
#endif