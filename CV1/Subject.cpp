#include "Subject.h"

void Subject::attach(Observer* observer)
{
	this->observers.push_back(observer);
	this->notify_observers();
}
