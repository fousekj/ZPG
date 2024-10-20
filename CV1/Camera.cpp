#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up)
	: Position(position), WorldUp(up), Yaw(-90.0f), Pitch(0.0f), MovementSpeed(2.5f), MouseSensitivity(0.1f) {
	updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(Position, Position + Front, Up);
}

glm::mat4 Camera::getProjectionMatrix(float fov, float aspect, float near, float far) {
	return glm::perspective(glm::radians(fov), aspect, near, far);
}

void Camera::moveForward(float deltaTime) {
	Position += Front * MovementSpeed * deltaTime;
	notify();
}

void Camera::moveBackward(float deltaTime) {
	Position -= Front * MovementSpeed * deltaTime;
	notify();
}

void Camera::moveLeft(float deltaTime) {
	Position -= Right * MovementSpeed * deltaTime;
	notify();
}

void Camera::moveRight(float deltaTime) {
	Position += Right * MovementSpeed * deltaTime;
	notify();
}

void Camera::updatePosition(float xoffset, float yoffset) {
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	updateCameraVectors();
	notify();
}

void Camera::updateCameraVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}


void Camera::attach(Shader* shader) {
	shaders.push_back(shader);
}

void Camera::notify() {
	for (auto shader : shaders) {
		//shader->update();
	}
}

void Camera::updateCamMatrix(GLint matrixID) {

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(this->getProjectionMatrix(60.0f, 4.0f / 3.0f, 0.1f, 100.0f) * this->getViewMatrix()));
}

/*Camera::Camera(int width, int height, glm::vec3 position)
{
	this->width = width;
	this->height = height;
	this->position = position;
	this->yaw = -90.0f;
	this->pitch = 0.0f;
}

void Camera::matrix(float fovDeg, float nearPlane, float farPlane, GLint matrixID)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(this->position, this->position + this->orientation, up);
	projection = glm::perspective(glm::radians(fovDeg), (float)(width / height), nearPlane, farPlane);

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(projection * view));
}

void Camera::cameraMouseMove(GLFWwindow* window)
{
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);
	float xoffset = mouseX - (width / 2);
	float yoffset = (height / 2) - mouseY;

	glfwSetCursorPos(window, width / 2, height / 2);

	xoffset *= this->sensitivity;
	yoffset *= this->sensitivity;

	this->yaw += xoffset;
	this->pitch += yoffset;

	if (this->pitch > 89.0f) { this->pitch = 89.0f; }
	if (this->pitch < -89.0f) { this->pitch = -89.0f; }

	glm::vec3 newFront;
	newFront.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	newFront.y = sin(glm::radians(this->pitch));
	newFront.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	newFront = glm::normalize(newFront);
	this->orientation = glm::normalize(glm::cross(this->position, this->up));
	this->up = glm::normalize(glm::cross(this->orientation, this->position));

	
		
	/*if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = this->sensitivity * (float)(mouseY - (this->height / 2)) / height;
		float rotY = this->sensitivity * (float)(mouseX - (this->width / 2)) / height;

		glm::vec3 newOrientation = glm::rotate(this->orientation, glm::radians(rotX), glm::normalize(glm::cross(orientation, up)));



		this->orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up));

		if (abs(glm::angle(newOrientation, this->up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			this->orientation = newOrientation;
		}

		this->orientation = glm::rotate(this->orientation, glm::radians(-rotY), this->up);

		glfwSetCursorPos(window, (this->width / 2), (this->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}*/
/*}

void Camera::cameraKeyMove(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->position += this->speed * this->orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->position += this->speed * -glm::normalize(glm::cross(this->orientation, this->up));
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->position += this->speed * -this->orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->position += this->speed * glm::normalize(glm::cross(this->orientation, this->up));
	}
}
*/