#pragma once

#include "ShaderProgram.h"
#include "Model.h"
#include "Transformation.h"

/**
 * @file DrawableObject.cpp
 *
 * @brief DrawableObject.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

class DrawableObject
{
private:
	ShaderProgram* shaderProgram;
	Model* model;
	Transformation* transformation;
public:
	DrawableObject(ShaderProgram* shaderProgram, Model* model, Transformation* transformation);
	void setTransformScale(float scale);
	void setTransformTranslation(glm::vec3 matrix);
	void setTransformRotation(float angle, glm::vec3 axis);
	void draw();
};

