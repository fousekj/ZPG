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
#include "Model.h"
#include <vector>

/**
 * @file ShaderProgram.h
 *
 * @brief ShaderProgram.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/


class ShaderProgram
{
private:
	GLuint vertexShader, fragmentShader;
	GLuint shaderProgram;
	float points;
	const char* vertex_shader_def;
	const char* fragment_shader_def;
	//vector<Model*> models;



public:
	void createShaderProgram();
	ShaderProgram(const char* vertex_shader, const char* fragment_shader);
	
	void draw(Model* model);
};

