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
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
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

void DrawableObject::setDynamicRotation(float angle, glm::vec3 axis, float speed)
{
	this->transformation->addTransformation(new DynamicRotation(angle, axis, speed));
}

void DrawableObject::addTransformation(BasicTransformation* transformation)
{
	this->transformation->addTransformation(transformation);
}

void DrawableObject::updateRotation(float angle, glm::vec3 axis, int index)
{
	this->transformation->updateTransformation(new Rotation(angle, axis), index);
}

void DrawableObject::draw()
{
	this->shaderProgram->use();
	this->shaderProgram->setObjectColor(this->color);
	this->shaderProgram->setTransformMatrix(this->transformation->getTransformMatrix());


	this->model->drawModel();
}
