#pragma once
#include "Observer.h"
#include <vector>	
using namespace std;

template <class T>
class Subject
{
private:
	vector<Observer<T>*> observers;

public:
	void addObserver(Observer<T>* observer)
	{
		this->observers.push_back(observer);
	}

	void notifyObservers()
	{
		for (Observer<T>* observer : this->observers)
		{
			observer->update(static_cast<T*>(this));
		}
	}

	void notifyObservers(int descriptor)
	{
		for (Observer<T>* observer : this->observers)
		{
			observer->update(static_cast<T*>(this), descriptor);
		}
	}

};

