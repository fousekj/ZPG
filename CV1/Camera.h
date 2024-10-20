#pragma once


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

#include "ShaderProgram.h"


class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;

	float MovementSpeed;
	float MouseSensitivity;

	void updateCameraVectors();

	std::vector<Shader*> shaders;

	Camera(glm::vec3 position, glm::vec3 up);

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float fov, float aspect, float near, float far);

	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void moveLeft(float deltaTime);
	void moveRight(float deltaTime);

	void updatePosition(float xoffset, float yoffset);

	void attach(Shader* shader);
	void notify();
	void updateCamMatrix(GLint matrixID);

// old
	/*glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	int width;
	int height; 
	float yaw;
	float pitch;

	float speed = 0.1f;
	float sensitivity = 100.0f;

	Camera(int width, int height, glm::vec3 position);
	void matrix(float fovDeg, float nearPlane, float farPlane, GLint uniform);

	void cameraKeyMove(GLFWwindow* window);
	void cameraMouseMove(GLFWwindow* window);
	*/

};

