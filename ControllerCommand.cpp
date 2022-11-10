
#include "ControllerCommand.h"

namespace SpaceControllerCommand
{
	ControllerCommand::ControllerCommand()
	{
		//this->vCommand.push_back("getobject");
		//this->vCommand.push_back("getlistobject");

		this->mapCommand.emplace("addobject", new CommandAddObject());
		this->mapCommand.emplace("addattribute", new CommandAddAttribute());
		this->mapCommand.emplace("addvalue", new CommandAddValue());
		this->mapCommand.emplace("deleteattribute", new CommandDeleteAttribute());
		this->mapCommand.emplace("deleteobject", new CommandDeleteObject());
		//this->mapCommand.emplace("getobject", new CommandGetObject());
		//this->mapCommand.emplace("getlistobject", new CommandGetListObject());
	}
	ControllerCommand::~ControllerCommand() {}

	CommandAddObject::CommandAddObject() {}
	CommandAddObject::~CommandAddObject() {}
	int CommandAddObject::UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput)
	{
		if ((*vectorInput).size() != 2) { return -1; }

		ModelData* md = new ModelData();
		strcpy(md->name, (*vectorInput)[1].data);
		vectorData->push_back(md);
		printf("  Addobject %s\n", md->name);
		return 0;
	}

	CommandAddAttribute::CommandAddAttribute() {}
	CommandAddAttribute::~CommandAddAttribute() {}
	int CommandAddAttribute::UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput)
	{
		if ((*vectorInput).size() != 4) { return -1; }

		for (int j = 0; j < (*vectorData).size(); j++)
		{
			if (strcmp((*vectorData)[j]->name, (*vectorInput)[1].data) == 0)
			{
				if (strcmp((*vectorInput)[2].data, "char") == 0)
				{
					if (strcmp((*vectorInput)[3].data, " ") != 0)
					{
						printf("  AddAttribute %s\n", (*vectorInput)[3].data);
						IAttribute* ia = new IAttribute();
						strcpy(ia->type, (*vectorInput)[2].data);
						strcpy(ia->name, (*vectorInput)[3].data);
						strcpy(((ModelChar*)ia)->text, " ");
						(*vectorData)[j]->iattribute.push_back(ia);
						break;
					}
				}
				if (strcmp((*vectorInput)[2].data, "int") == 0)
				{
					if (strcmp((*vectorInput)[3].data, " ") != 0)
					{
						printf("  AddAttribute %s\n", (*vectorInput)[3].data);
						IAttribute* ia = new IAttribute();
						strcpy(ia->type, (*vectorInput)[2].data);
						strcpy(ia->name, (*vectorInput)[3].data);
						((ModelInt*)ia)->value = 0;
						(*vectorData)[j]->iattribute.push_back(ia);
						break;
					}
				}
				if (strcmp((*vectorInput)[2].data, "bool") == 0)
				{
					printf("  AddAttribute %s\n", (*vectorInput)[3].data);
					IAttribute* ia = new IAttribute();
					strcpy(ia->type, (*vectorInput)[2].data);
					strcpy(ia->name, (*vectorInput)[3].data);
					((ModelBool*)ia)->event = false;
					(*vectorData)[j]->iattribute.push_back(ia);
					break;
				}
			}
		}
		return 0;
	}

	CommandAddValue::CommandAddValue() {}
	CommandAddValue::~CommandAddValue() {}
	int CommandAddValue::UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput)
	{
		if ((*vectorInput).size() != 4) { return -1; }
		int indexData = 0;

		for (int i = 0; i < (*vectorData).size(); i++)
		{
			if (strcmp((*vectorData)[i]->name, (*vectorInput)[1].data) == 0)
			{
				indexData = i;
				break;
			}
		}
		for (int j = 0; j < (*vectorData)[indexData]->iattribute.size(); j++)
		{
			if (strcmp((*vectorData)[indexData]->iattribute[j]->name, (*vectorInput)[2].data) == 0)
			{
				if (strcmp((*vectorData)[indexData]->iattribute[j]->type, "char") == 0)
				{
					strcpy(((ModelChar*)(*vectorData)[indexData]->iattribute[j])->text, (*vectorInput)[3].data);
				}
				if (strcmp((*vectorData)[indexData]->iattribute[j]->type, "int") == 0)
				{
					((ModelInt*)(*vectorData)[indexData]->iattribute[j])->value = atoi((*vectorInput)[3].data);
				}
				if (strcmp((*vectorData)[indexData]->iattribute[j]->type, "bool") == 0)
				{
					if (strcmp((*vectorInput)[3].data, "true") == 0)
					{
						((ModelBool*)(*vectorData)[indexData]->iattribute[j])->event = true;
					}
					if (strcmp((*vectorInput)[3].data, "false") == 0)
					{
						((ModelBool*)(*vectorData)[indexData]->iattribute[j])->event = false;
					}
				}
				printf("  AddValue %s\n", (*vectorInput)[3].data);
				break;
			}
		}
		return 0;
	}

	CommandDeleteAttribute::CommandDeleteAttribute() {}
	CommandDeleteAttribute::~CommandDeleteAttribute() {}
	int CommandDeleteAttribute::UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput)
	{
		if ((*vectorInput).size() != 3) { return -1; }
		int indexData = 0;

		for (int i = 0; i < (*vectorData).size(); i++)
		{
			if (strcmp((*vectorData)[i]->name, (*vectorInput)[1].data) == 0)
			{
				indexData = i;
				break;
			}
		}
		for (int j = 0; j < (*vectorData)[indexData]->iattribute.size(); j++)
		{
			if (j == atoi((*vectorInput)[2].data))
			{
				printf("  DeleteAttribute id:%d\n", atoi((*vectorInput)[2].data));
				(*vectorData)[indexData]->iattribute.erase((*vectorData)[indexData]->iattribute.begin() + j);
				vector<IAttribute*>((*vectorData)[indexData]->iattribute).swap((*vectorData)[indexData]->iattribute);
				break;
			}
		}
		return 0;
	}

	CommandDeleteObject::CommandDeleteObject() {}
	CommandDeleteObject::~CommandDeleteObject() {}
	int CommandDeleteObject::UpdateCommand(vector<ModelData*>* vectorData, vector<cData>* vectorInput)
	{
		if ((*vectorInput).size() != 2) { return -1; }

		for (int i = 0; i < (*vectorData).size(); i++)
		{
			if (strcmp((*vectorData)[i]->name, (*vectorInput)[1].data) == 0)
			{
				printf("  DeleteObject \n");
				(*vectorData).erase((*vectorData).begin() + i);
				vector<ModelData*>(*vectorData).swap(*vectorData);
				break;
			}
		}
		return 0;
	}
}