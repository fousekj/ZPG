#pragma once

#include <vector>	
using namespace std;

class Observer;

class Subject {
protected:
    vector<Observer*> observers;

public:
    void attach(Observer* observer);
    virtual void notify_observers() = 0;
};
