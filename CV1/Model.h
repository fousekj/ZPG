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

/**
 * @file Model.h
 *
 * @brief Model.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/

class Model
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint vertex_shader, fragment_shader;
	float* points;
	GLenum drawMode;
	int size;
public:
	Model(float* points, int size, GLenum drawMode);
	void createModel();
	void drawModel();
	
};

