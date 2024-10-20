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
using namespace std;

/**
 * @file ShaderProgram.h
 *
 * @brief ShaderProgram.h file with functions implementations
 *
 * @author Ji�� Fousek
  **/


#include "Shader.h"
#include "Transformation.h"
#include "Model.h"

class ShaderProgram
{
private:

	Shader* vertexShader;
	Shader* fragmentShader;
	GLuint programID;

public:

	ShaderProgram(Shader* vertexShader, Shader* fragmentShader);
	void use();
	GLuint getTransformID();
	GLuint getProjectionMatrixID();
	GLuint getViewMatrixID();
	void setCamMatrix(glm::mat4 projectionMat, glm::mat4 viewMat);
};

