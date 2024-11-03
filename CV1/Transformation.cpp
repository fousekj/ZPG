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
	//this->scale(scale);
	//this->translate(translation);
	//this->rotate(angle, axis);
}

void Transformation::useTransformation(GLuint matrixID)
{
	this->modelMatrix = this->getTransformMatrix();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &this->modelMatrix[0][0]);
}

glm::mat4 Transformation::getTransformMatrix() const
{
	glm::mat4 result = glm::mat4(1.f);
	for (auto transformation : this->transformations) {
		result *= transformation->getTransformMatrix();
	}
	return result;
}

void Transformation::addTransformation(BasicTransformation* transformation)
{
	this->transformations.push_back(transformation);
}


