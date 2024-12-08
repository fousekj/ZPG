#pragma once
#include "BaseModel.h"
#include "Texture.h"

/**
* @file TexturedModel.h
* 
* @brief TexturedModel class
* 
* Class for textured models
* 
* @author Jiøí Fousek FOU0027
*/

class TexturedModel : public BaseModel
{
private:
	Texture* texture;

public:
	TexturedModel(GLenum drawMode, const float* points, int pointsSize, string path, GLuint id);
	void drawModel() override;
	Texture* getTexture();
};
