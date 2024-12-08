#pragma once
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Subject.h"
#include "Observer.h"
#include "Camera.h"

class SpotLight : public Subject
{
private:
	int id;
public:
	Camera* camera;
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 color;
	float cutOff;
	float outerCutOff;
	float constant = 1.0f;
	float linear = 0.09f;
	float quadratic = 0.032f;
	SpotLight(Camera* camera, glm::vec3 color, float cutOff, float outerCutOff, int id);
	void notify_observers() override;


};

