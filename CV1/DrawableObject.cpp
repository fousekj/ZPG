#include "DrawableObject.h"

/**
 * @file DrawableObject.cpp
 *
 * @brief DrawableObject.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/


DrawableObject::DrawableObject(ShaderProgram* shaderProgram, Model* model, glm::vec3 color)
{
	this->shaderProgram = shaderProgram;
	this->model = model;
	this->transformation = new Transformation();
	this->color = color;
	this->material = new Material(1, 1, 1);
}

DrawableObject::DrawableObject(ShaderProgram* shaderProgram, Model* model, glm::vec3 color, Material* material)
{
	this->shaderProgram = shaderProgram;
	this->model = model;
	this->transformation = new Transformation();
	this->color = color;
	this->material = material;
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
	this->shaderProgram->setMaterial(this->material);
	this->shaderProgram->setObjectColor(this->color);
	this->shaderProgram->setTransformMatrix(this->transformation->getTransformMatrix());
	this->model->drawModel();
}

void DrawableObject::useProgram()
{
	this->shaderProgram->use();
}

void DrawableObject::stopProgram()
{
	this->shaderProgram->stop();
}
