#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "BasicTransformation.h"
using namespace std;

/**
 * @file Transformation.h
 *
 * @brief Transformation.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/

class Transformation : public BasicTransformation
{
private:
	glm::mat4 modelMatrix;
	vector<BasicTransformation*> transformations;
public:
	Transformation();
	Transformation(float scale, glm::vec3 translation, float angle, glm::vec3 axis);
	void useTransformation(GLuint matrixID);
	glm::mat4 getTransformMatrix() override;
	void addTransformation(BasicTransformation* transformation);
	void updateTransformation(BasicTransformation* transformation, int index);
};

