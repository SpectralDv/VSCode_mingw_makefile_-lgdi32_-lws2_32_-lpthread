
#include "ControllerInput.h"


namespace SpaceControllerInput
{
	ControllerInput::ControllerInput() 
	{ 
		this->inputData = new cData(); this->command = new cData();
		strcpy(this->inputData->name, "ControllerInput");
	}
	ControllerInput::~ControllerInput() 
	{ 
		delete this->inputData; delete this->command; 
		printf("~ControllerInput"); 
	}
	void ControllerInput::AddObserver(IObserver* o)
	{
		//printf("AddObserverInput: %s\n", ((IController*)o)->name.c_str());
		//printf("AddObserverInput: %x\n", o);
		observers.push_back(o);
	}
	void ControllerInput::RemoveObserver(IObserver* o)
	{
		vector<IObserver*>::iterator itErase = observers.begin();
		for (itErase; itErase != observers.end(); itErase++)
		{
			if (*itErase == o) { observers.erase(itErase); break; }
		}
	}
	void ControllerInput::Notify(cData* data)
	{
		for (auto o : this->observers)
		{
			//printf("NotifyInput: %s\n", ((IController*)o)->name.c_str());
			((IController*)o)->UpdateController(data);
		}
	}
	void ControllerInput::InputData()
	{
		while (true)
		{
			//cout << "msg: ";
			static bool inputStart;
			if (!inputStart) { cin.ignore(); inputStart = true; }
			cin.getline(this->inputData->data, sizeof(this->inputData->data));
			//printf("%s\n", this->inputData->data);

			if (strcmp(this->inputData->data, " ") != 0)
			{
				Notify(this->inputData);
				//ProcessingMessage();
				//UpdateInput();
			}

			//string str;
			//scanf_s("\n\0%[A-z]", str.c_str());
			//*data->data = getchar();
			//_getch();
			//cin.seekg(0, ios::end);

			//while (fgetc(stdin) != '\n');
			//while (cin.get() != '\n');
			//(cin >> data->data).get();
			//cin.clear();
			//cin.sync();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//strcpy(data->data, inputStr);
			//cin>> str;
			//copy(str.cbegin(), str.cend(), cptr);
			//cptr[str.length()] = '\0';
		}
	}
	void ControllerInput::ThreadProc(void* param)
   	{
        cout << "ThreadProc OK\n";
        //pthread_detach(pthread_self());
		cin.getline(this->inputData->data, sizeof(this->inputData->data));
		//printf("%s\n", this->inputData->data);

		if (strcmp(this->inputData->data, " ") != 0)
		{
			Notify(this->inputData);
		}
   	}
	void *ControllerInput::ThreadStub(void* param)
   	{
       	ControllerInput *ci = (ControllerInput*)param;
      	ci->ThreadProc((void*)NULL);
		return 0;
   	}
	cData* ControllerInput::GetInputData()
	{
		return this->inputData;
	}
	int ControllerInput::ProcessingMessage()
	{
		vectorData.clear();

		static char str[32] = "";

		strcpy(this->command->data, this->inputData->data);
		strcpy(str, this->inputData->data);

		int i = 0; int index = 0;
		int countSpace = 0; int beginStr = 0;
		while (str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\0') { i++; }
			while (str[i + countSpace] == ' ') { countSpace++; }
			str[i] = 0;
			cData d;
			strcpy(d.data, &str[beginStr]);
			this->vectorData.push_back(d);
			strcpy(str, this->inputData->data);
			//printf("vectorData: %s\n", this->vectorData[index].data);
			beginStr = i + countSpace;
			i += countSpace;
			countSpace = 0;
			index++;
		}
		return 0;
	}
	cData ControllerInput::GetVectorData(int index)
	{
		return this->vectorData[index];
	}
	int ControllerInput::GetSizeVectorData()
	{
		return (int)vectorData.size();
	}
}