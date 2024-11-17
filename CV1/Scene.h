#pragma once
#include "DrawableObject.h"
#include "ShaderProgram.h"
#include "Camera.h"

#include <glm/vec3.hpp> // glm::vec3

/**
 * @file Scene.h
 *
 * @brief Scene.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/

class Scene
{
private:
	vector<DrawableObject*> objects;
	vector<Light*> lights;
public:
	Scene();
	void addObject(DrawableObject* object);
	void addLight(Light* light);
	void render();
	Camera* camera;
	void rotateRandomObject();
};


