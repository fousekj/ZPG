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
}

void DrawableObject::setTranslation(glm::vec3 matrix)
{
	this->transformation->addTransformation(new Translation(matrix));
}

void DrawableObject::setRotation(float angle, glm::vec3 axis)
{
	this->transformation->addTransformation(new Rotation(angle, axis));
}

void DrawableObject::setDynamicRotation(float angle, glm::vec3 axis)
{
	this->transformation->addTransformation(new DynamicRotation(angle, axis));
}

void DrawableObject::updateRotation(float angle, glm::vec3 axis, int index)
{
	this->transformation->updateTransformation(new Rotation(angle, axis), index);
}

void DrawableObject::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::vec3 viewPosition)
{
	this->shaderProgram->use();
	this->shaderProgram->setCamMatrix(projectionMatrix, viewMatrix);
	this->shaderProgram->setObjectColor(this->color);
	this->shaderProgram->setViewPosition(viewPosition);
	this->shaderProgram->setTransformMatrix(this->transformation->getTransformMatrix());


	this->model->drawModel();
}
