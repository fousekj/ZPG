#pragma once

#include "ShaderProgram.h"
#include "Model.h"
#include "Transformation.h"
#include "Scale.h"
#include "Rotation.h"
#include "Translation.h"

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
	glm::vec3 color;
public:
	DrawableObject(ShaderProgram* shaderProgram, Model* model);
	DrawableObject(ShaderProgram* shaderProgram, Model* model, glm::vec3 color);
	void setScale(float scale);
	void setTranslation(glm::vec3 matrix);
	void setRotation(float angle, glm::vec3 axis);
	void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	ShaderProgram* getShaderProgram();
};

