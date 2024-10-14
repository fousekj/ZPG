#pragma once
#include "DrawableObject.h"
#include "ShaderProgram.h"

class Scene
{
private:
	vector<DrawableObject*> objects;
	ShaderProgram* shaderProgram;
public:
	Scene(vector<DrawableObject*> objects, ShaderProgram* shaderProgram);
	void render();

};


