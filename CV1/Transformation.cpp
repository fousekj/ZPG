#include "Transformation.h"

/**
 * @file Transformation.cpp
 *
 * @brief Transformation.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Transformation::Transformation()
{
	this->modelMatrix = glm::mat4(1.0f);
}

Transformation::Transformation(float scale, glm::vec3 translation, float angle, glm::vec3 axis)
{
	this->modelMatrix = glm::mat4(1.0f);
	this->scale(scale);
	this->translate(translation);
	this->rotate(angle, axis);
}

void Transformation::scale(float scale)
{
	this->modelMatrix = glm::scale(this->modelMatrix, glm::vec3(scale));
}

void Transformation::useTransformation(GLuint matrixID)
{
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &this->modelMatrix[0][0]);
}

void Transformation::translate(glm::vec3 translation)
{
	this->modelMatrix = glm::translate(this->modelMatrix, translation);
}

void Transformation::rotate(float angle, glm::vec3 axis) {
	this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), axis);
}

