
#include "ControllerData.h"


namespace SpaceControllerData
{
	ControllerData::ControllerData() 
	{
		name = "ControllerData"; 
		this->data = new cData;
		controllerCommand = new ControllerCommand();
	}
	ControllerData::~ControllerData() { delete data; delete controllerCommand; printf("~ControllerData"); }
	void ControllerData::AddObserver(IObserver* o)
	{
		observers.push_back(o);
	}
	void ControllerData::RemoveObserver(IObserver* o)
	{
		vector<IObserver*>::iterator itErase = observers.begin();
		for (itErase; itErase != observers.end(); itErase++)
		{
			if (*itErase == o) { observers.erase(itErase); break; }
		}
	}
	void ControllerData::Notify(cData* data)
	{
		for (auto o : observers)
		{
			((IController*)o)->UpdateController(data);
		}
	}
	void ControllerData::UpdateObserver(cData* data){}
	int ControllerData::UpdateController(cData* data)
	{
		strcpy(this->data->data, data->data);
		this->ProcessingMessage();

		if (strcmp(data->name, "ControllerInput") == 0)
		{
			if (this->CheckGetMessage() != 0)
			{
				strcpy(data->data, " ");
			}
			this->Notify(data);
		}
		this->ProcessingCommand();
		return 0;
	}
	int ControllerData::GetSizeData()
	{
		return (int)this->vectorData.size();
	}
	int ControllerData::ProcessingMessage()
	{
		this->vectorInput.clear();

		static char str[32] = "";

		strcpy(str, this->data->data);

		int i = 0; int index = 0;
		int countSpace = 0; int beginStr = 0;
		while (str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\0') { i++; }
			while (str[i + countSpace] == ' ') { countSpace++; }
			str[i] = 0;
			cData d;
			strcpy(d.data, &str[beginStr]);
			this->vectorInput.push_back(d);
			strcpy(str, this->data->data);
			beginStr = i + countSpace;
			i += countSpace;
			countSpace = 0;
			index++;
		}
		return 0;
	}
	int ControllerData::ProcessingCommand()
	{
		if (this->CheckGetMessage() == 1) { this->GetListObject(); return 1; }
		if (this->CheckGetMessage() == 2) { this->GetObject(); return 1; }

		for (int i = 0; i < this->vectorInput.size(); i++)
		{
			auto it = this->controllerCommand->mapCommand.find(this->vectorInput[i].data);
			if (it == controllerCommand->mapCommand.end()) { break; }

			if (strcmp(this->vectorInput[i].data, it->first.c_str()) == 0)
			{
				(it->second)->UpdateCommand(&vectorData, &vectorInput);
				break;
			}
		}
		return 0;
	}
	int ControllerData::CheckGetMessage()
	{
		for (int i = 0; i < this->vectorInput.size(); i++)
		{
			if (strcmp(this->vectorInput[i].data, "getlistobject") == 0)
			{return 1;}
			else if (strcmp(this->vectorInput[i].data, "getobject") == 0)
			{return 2;}
		}
		return 0;
	}
	int ControllerData::GetListObject()
	{
		//printf("  ListObject \n");
		for (int i = 0; i < this->vectorData.size(); i++)
		{
			printf("  %s\n", vectorData[i]->name);
		}
		return 0;
	}
	int ControllerData::GetObject()
	{
		for (int j = 0; j < this->vectorData.size(); j++)
		{
			if (strcmp(this->vectorData[j]->name, this->vectorInput[1].data) == 0)
			{
				PrintParams(j);
				break;
			}
		}
		return 0;
	}
	int ControllerData::PrintParams(int indexData)
	{
		printf("  Object   Attribute    Name     Type     Value\n");
		for (int i = 0; i < this->vectorData[indexData]->iattribute.size(); i++)
		{
			printf("  %s", this->vectorData[indexData]->name);
			printf("          %d", i);
			printf("        %s", (this->vectorData[indexData]->iattribute[i]->name));
			printf("     %s", (this->vectorData[indexData]->iattribute[i]->type));
			if (strcmp(this->vectorData[indexData]->iattribute[i]->type, "char") == 0)
			{
				printf("     %s\n", ((ModelChar*)this->vectorData[indexData]->iattribute[i])->text);
			}
			if (strcmp(this->vectorData[indexData]->iattribute[i]->type, "int") == 0)
			{
				printf("     %d\n", ((ModelInt*)this->vectorData[indexData]->iattribute[i])->value);
			}
			if (strcmp(this->vectorData[indexData]->iattribute[i]->type, "bool") == 0)
			{
				printf("     %d\n", ((ModelBool*)this->vectorData[indexData]->iattribute[i])->event);
			}
		}
		printf("\n");
		return 0;
	}
}