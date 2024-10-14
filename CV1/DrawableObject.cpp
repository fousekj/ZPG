#include "DrawableObject.h"

/**
 * @file DrawableObject.cpp
 *
 * @brief DrawableObject.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/


DrawableObject::DrawableObject(ShaderProgram* shaderProgram, Model* model, Transformation* transformation)
{
	this->shaderProgram = shaderProgram;
	this->model = model;
	this->transformation = transformation;
}

void DrawableObject::setTransformScale(float scale)
{
	this->transformation->scale(scale);
}

void DrawableObject::setTransformTranslation(glm::vec3 matrix)
{
	this->transformation->translate(matrix);
}

void DrawableObject::setTransformRotation(float angle, glm::vec3 axis)
{
	this->transformation->rotate(angle, axis);
}

void DrawableObject::draw()
{
	this->shaderProgram->use();
	
	this->transformation->useTransformation(this->shaderProgram->getTransformID());

	this->model->drawModel();
}