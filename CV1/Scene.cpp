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
	//this->camera = new Camera(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	this->skybox = NULL;

}

void Scene::addObject(DrawableObject* object)
{
	this->objects.push_back(object);
}

void Scene::addLight(PointLight* light)
{
	this->lights.push_back(light);
}

void Scene::addLight(SpotLight* light)
{
	this->spotlights.push_back(light);
}

void Scene::addLight(DirectionalLight* light)
{
	this->directionalLights.push_back(light);
}

void Scene::render()
{
	if (this->skybox != NULL)
		skybox->draw();
	
	for (DrawableObject* obj : objects) {
		
		for (SpotLight* light : spotlights)
			light->notify_observers();

		for (PointLight* light : lights)
			light->notify_observers();
		
		for (DirectionalLight* light : directionalLights)
			light->notify_observers();

		obj->useProgram();
		obj->draw();
		obj->stopProgram();
	}
	
}

void Scene::rotateRandomObject()
{
	int index = rand() % this->objects.size();
	this->objects[index]->updateRotation(1.0f, glm::vec3(0.0f, 1.0f, 0.0f), 2);
}

void Scene::setSkybox(Skybox* skybox)
{
	this->skybox = skybox;
}



