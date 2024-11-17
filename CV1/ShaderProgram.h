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
 * @author Jiøí Fousek
  **/


#include "Shader.h"
#include "Transformation.h"
#include "Model.h"
#include "ShaderLoader.h"
#include "Light.h"

class ShaderProgram
{
private:
	GLuint programID;
	Light* light;
	void setMat4Uniform(const char* name, glm::mat4 value);
	void setVec3Uniform(const char* name, glm::vec3 value);
	GLuint getTransformID();
	GLuint getProjectionMatrixID();
	GLuint getViewMatrixID();

public:
	ShaderProgram(const char* vertexPath, const char* fragmentPath, Light* light);
	ShaderProgram(const char* vertexPath, const char* fragmentPath);
	void use();

	void setCamMatrix(glm::mat4 projectionMat, glm::mat4 viewMat);
	void setObjectColor(glm::vec3 color);
	void setViewPosition(glm::vec3 position);
	void setTransformMatrix(glm::mat4 matrix);
};

