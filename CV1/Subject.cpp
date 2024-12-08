#include "Subject.h"

/**
* @file Subject.cpp
* 
* @brief Subject class implementation
* 
* @author Jiøí Fousek FOU0027
*/

void Subject::attach(Observer* observer)
{
	this->observers.push_back(observer);
	this->notify_observers();
}
