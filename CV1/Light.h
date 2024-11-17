#pragma once
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Subject.h"
#include "Observer.h"

class Light : public Subject
{
private:
	int id;
public:
	glm::vec3 position;
	glm::vec3 color;
	Light(glm::vec3 position, glm::vec3 color, int id);
	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);
	void notify_observers() override;
	
	float constant = 1.0f;
	float linear = 0.09f;
	float quadratic = 0.032f;
};