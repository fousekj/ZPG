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
#include "ShaderProgram.h"

#include <vector>


/**
 * @file App.H
 *
 * @brief App. file with functions declarations
 *
 * @author Jiøí Fousek
  **/


class App
{
private:
	GLFWwindow* window;

	static void error_callback(int error, const char* description);
	void compileShaders();
	void createModels();
	void draw();
	ShaderProgram* shaderProgram;
	Model* model;
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);
public:
	App();
	~App();
	void initialization();
	void run();

};

