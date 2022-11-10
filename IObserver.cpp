
#include "IObserver.h"


namespace SpaceObserver
{
	void IObserver::UpdateObserver(cData* data) {}
	//void IObserver::UpdateCountThread(int p) {}
	//void IObserver::UpdateCountThread(map<string, int> p) {}


	IObservable::~IObservable() {}
	void IObservable::AddObserver(IObserver* o) {}
	void IObservable::RemoveObserver(IObserver* o) {}
	void IObservable::Notify(cData* data) {}
	//void IObservable::Notify(pair<string, int> p) {}
	//void IObservable::Notify(map<string, int> p) {}
}


