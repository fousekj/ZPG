#include "DrawableObject.h"

/**
 * @file DrawableObject.cpp
 *
 * @brief DrawableObject.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/


DrawableObject::DrawableObject(ShaderProgram* shaderProgram, Model* model)
{
	this->shaderProgram = shaderProgram;
	this->model = model;
	this->transformation = new Transformation();
}

DrawableObject::DrawableObject(ShaderProgram* shaderProgram, Model* model, glm::vec3 color)
{
	this->shaderProgram = shaderProgram;
	this->model = model;
	this->transformation = new Transformation();
	this->color = color;
}

void DrawableObject::setScale(float scale)
{
	this->transformation->addTransformation(new Scale(scale));
	//this->transformation->scale(scale);
}

void DrawableObject::setTranslation(glm::vec3 matrix)
{
	this->transformation->addTransformation(new Translation(matrix));
	//this->transformation->translate(matrix);
}

void DrawableObject::setRotation(float angle, glm::vec3 axis)
{
	this->transformation->addTransformation(new Rotation(angle, axis));
	//this->transformation->rotate(angle, axis);
}

void DrawableObject::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	this->shaderProgram->use();
	this->shaderProgram->setCamMatrix(projectionMatrix, viewMatrix);
	this->shaderProgram->setObjectColor(this->color);
	this->transformation->useTransformation(this->shaderProgram->getTransformID());

	this->model->drawModel();
}

ShaderProgram* DrawableObject::getShaderProgram()
{
	return this->shaderProgram;
}
