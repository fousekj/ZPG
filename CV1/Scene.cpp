#include "Scene.h"

/**
 * @file Scene.cpp
 *
 * @brief Scene.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Scene::Scene()
{
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Scene::addObject(DrawableObject* object)
{
	this->objects.push_back(object);
}

void Scene::addLight(Light* light)
{
	this->lights.push_back(light);
}

void Scene::render()
{
	if (this->lights.size() > 0)
	{
		for (Light* light : lights)
		{
			light->notify_observers();
		}
	}
	for (DrawableObject* obj : objects) {
		obj->draw();
	}
}

void Scene::rotateRandomObject()
{
	int index = rand() % this->objects.size();
	this->objects[index]->updateRotation(1.0f, glm::vec3(0.0f, 1.0f, 0.0f), 2);
}


