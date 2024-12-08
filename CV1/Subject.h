#pragma once

#include <vector>	
using namespace std;

/**
* @file Subject.h
* 
* @brief Subject class with functions declarations
* 
* @author Jiøí Fousek FOU0027
*/

class Observer;

class Subject {
protected:
    vector<Observer*> observers;

public:
    void attach(Observer* observer);
    virtual void notify_observers() = 0;
};
