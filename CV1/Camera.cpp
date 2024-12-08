#include "Camera.h"

/**
* @file Camera.cpp
 *
 * @brief Camera file with functions definitions
 *
 * This file contains definitions of functions for Camera class
 *
 * @author Jiøí Fousek FOU0027
*/

Camera::Camera(glm::vec3 position, glm::vec3 up) {
	this->position = position;
	this->worldUp = up;
	this->yaw = -90.f;
	this->pitch = 0.f;
	this->speed = 1.f;
	this->sensitivity = 0.1f;
	this->fov = 60.f;
	this->aspect = 4.f / 3.f;
	this->near = 0.1f;
	this->far = 100.f;

	updateVectors();
	
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(this->position, this->position + this->front, this->up);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}

void Camera::setAspect(float aspect)
{
	this->aspect = aspect;
	this->notify_observers();
}

void Camera::moveForward() {
	this->position += this->front * this->speed;
	this->notify_observers();
}

void Camera::moveBackward() {
	this->position -= this->front * this->speed;
	this->notify_observers();
}

void Camera::moveLeft() {
	this->position -= this->right * this->speed;
	this->notify_observers();
}

void Camera::moveRight() {
	this->position += this->right * this->speed;
	this->notify_observers();
}

void Camera::moveMouse(float width, float height, float posX, float posY) {
	this->yaw = yaw + (posX - (width / 2)) * sensitivity;
	this->pitch = pitch + ((height / 2) - posY) * sensitivity;

	if (this->pitch > 89.0f)
		this->pitch = 89.0f;
	if (this->pitch < -89.0f)
		this->pitch = -89.0f;

	updateVectors();
}

glm::vec3 Camera::getPosition()
{
	return this->position;
}

glm::vec3 Camera::getFront()
{
	return this->front;
}

void Camera::notify_observers()
{
	for (int i = 0; i < this->observers.size(); i++)
	{
		this->observers[i]->update(*this);
	}
}

void Camera::updateVectors() {
	glm::vec3 newFfront;
	newFfront.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	newFfront.y = sin(glm::radians(this->pitch));
	newFfront.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front = glm::normalize(newFfront);
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->front));
	this->notify_observers();
}
