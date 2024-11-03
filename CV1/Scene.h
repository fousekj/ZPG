#pragma once
#include "DrawableObject.h"
#include "ShaderProgram.h"
#include "Camera.h"

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
	ShaderProgram* shaderProgram;
	
public:
	Scene(vector<DrawableObject*> objects, ShaderProgram* shaderProgram);
	Scene(ShaderProgram* shaderProgram);
	Scene();
	void addObject(DrawableObject* object);
	ShaderProgram* getShaderProgram();
	void render();
	Camera* camera;
};


