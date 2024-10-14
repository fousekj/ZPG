#include "Scene.h"

/**
 * @file Scene.cpp
 *
 * @brief Scene.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Scene::Scene(vector<DrawableObject*> objects, ShaderProgram* shaderProgram)
{
	this->objects = objects;
	this->shaderProgram = shaderProgram;
}

Scene::Scene(ShaderProgram* shaderProgram)
{
	this->shaderProgram = shaderProgram;
	this->objects = { };
}

void Scene::addObject(DrawableObject* object)
{
	this->objects.push_back(object);
}

ShaderProgram* Scene::getShaderProgram()
{
	return this->shaderProgram;
}


void Scene::render()
{
	this->shaderProgram->use();
	for (DrawableObject* obj : objects) {
		obj->draw();
	}
}