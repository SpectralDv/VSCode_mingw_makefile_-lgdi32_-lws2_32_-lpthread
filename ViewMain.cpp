
#include "ViewMain.h"


using namespace SpaceViewSocket;
namespace SpaceViewMain
{
    ViewMain::ViewMain() 
    { 
        //printf("ViewMain \n"); 
        this->viewSocket = new ViewSocket();
        this->viewInput = new ViewInput();
        this->viewData = new ViewData();
    }
    ViewMain::~ViewMain() 
    { 
        printf("~ViewMain"); 
        delete viewSocket;
        delete viewInput;
        delete viewData;
    }

    void ViewMain::Init()
    {
        this->viewSocket->UpdateControllerInput((IController*)this->viewInput->GetControllerInput());
        this->viewSocket->UpdateControllerData((IController*)this->viewData->GetControllerData());

        this->viewInput->UpdateControllerSocket((IController*)this->viewSocket->GetControllerSocket());
        this->viewInput->UpdateControllerData((IController*)this->viewData->GetControllerData());

        this->viewData->UpdateControllerInput((IController*)this->viewInput->GetControllerInput());
        this->viewData->UpdateControllerSocket((IController*)this->viewSocket->GetControllerSocket());
    }

	void ViewMain::Update()
	{
        //printf("ViewMain Update\n");

        char c;
        printf("Input: s - server, c - client\n");
        cin >> c;

        if (c == 'c')
        {
            printf("Client active\n");
            MainInfo();
            this->viewSocket->StartSocket(6000,6001);
        }
        if (c == 's')
        {
            printf("Server active\n");
            MainInfo();
            this->viewSocket->StartSocket(6001,6000);
        }
        if (c != 'c' && c != 's')
        {
            exit(0);
        }
	}

    void ViewMain::MainInfo()
    {
        printf("For create object, input: addobject nameobject \n");
        printf("For get all object, input: getlistobject \n");
        printf("For create attribute in object, input: addattribute nameobject char/int/bool text/value/true \n");
        printf("For get object's params, input: addvalue nameobject nameattribute text/value/true\n");
        printf("For get object's params, input: getobject nameobject \n");
        printf("For delete attribute, input: deleteattribute nameobject indexttribute\n");
        printf("For delete object, input: deleteobject nameobject\n");
        //printf("For exit, input: exit \n");
    }
}


