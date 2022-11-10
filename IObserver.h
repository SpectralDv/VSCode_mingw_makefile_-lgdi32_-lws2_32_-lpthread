#pragma once
#ifndef _IOBSERVER_H
#define _IOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "sData.h"

using namespace std;


using namespace SpaceSData;
namespace SpaceObserver
{
    class IObserver
    {
    public:
        virtual void UpdateObserver(cData* data);
        //virtual void UpdateObserver(sData* data);
        //virtual void UpdateCountThread(int p);
        //virtual void UpdateCountThread(map<string, int> p);
    };

    class IObservable
    {
    public:
        virtual ~IObservable();
        virtual void AddObserver(IObserver* o);
        virtual void RemoveObserver(IObserver* o);
        virtual void Notify(cData* data);
        //virtual void Notify(pair<string, int> p);
        //virtual void Notify(map<string, int> p);
    };
}
#endif