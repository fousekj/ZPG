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
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Scene::Scene(ShaderProgram* shaderProgram)
{
	this->shaderProgram = shaderProgram;
	this->objects = { };
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
	this->shaderProgram->setCamMatrix(this->camera->getProjectionMatrix(60.0f, 4.0f / 3.0f, 0.1f, 100.0f), this->camera->getViewMatrix());
	for (DrawableObject* obj : objects) {
		obj->draw();
	}
}

vector<DrawableObject*> Scene::getObjects()
{
	return this->objects;
}
