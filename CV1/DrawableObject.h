#pragma once

#include "ShaderProgram.h"
#include "BaseModel.h"
#include "Model.h"
#include "Transformation.h"
#include "Scale.h"
#include "Rotation.h"
#include "Translation.h"
#include "DynamicRotation.h"
#include "Material.h"
#include "TexturedModel.h"
#include "Texture.h"
#include "AssimpModel.h"

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
	BaseModel* model;
	Transformation* transformation;
	glm::vec3 color;
	Material* material;
	Texture* texture;
public:
	DrawableObject(ShaderProgram* shaderProgram, BaseModel* model, glm::vec3 color);
	DrawableObject(ShaderProgram* shaderProgram, BaseModel* model, glm::vec3 color, Material* material);
	void setScale(float scale);
	void setTranslation(glm::vec3 matrix);
	void setRotation(float angle, glm::vec3 axis);
	void setDynamicRotation(float angle, glm::vec3 axis, float speed);
	void addTransformation(BasicTransformation* transformation);
	void updateRotation(float angle, glm::vec3 axis, int index);
	void draw();
	void useProgram();
	void stopProgram();

};

