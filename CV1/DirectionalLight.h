#pragma once

#include <glm/vec3.hpp> // glm::vec3

#include "Subject.h"
#include "Observer.h"

/**
* @file DirectionalLight.h
* 
* @brief DirectionalLight class
* 
* @author Jiri Fousek FOu0027
* 
*/

class DirectionalLight : public Subject
{
private:
	int id;
public:
	glm::vec3 direction;
	glm::vec3 color;
	DirectionalLight(glm::vec3 direction, glm::vec3 color, int id);
	void notify_observers() override;
};

