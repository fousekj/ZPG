#pragma once
#include "BaseModel.h"
#include "Texture.h"

class TexturedModel : public BaseModel
{
private:
	Texture* texture;

public:
	TexturedModel(GLenum drawMode, const float* points, int pointsSize, string path, GLuint id);
	void drawModel() override;
	Texture* getTexture();
};
