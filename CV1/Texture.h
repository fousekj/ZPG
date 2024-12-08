#pragma once
#include <GL/glew.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <SOIL.h>

using namespace std;

#define MAX_TEXTURES 32

class Texture
{
private:
	GLuint textureID;
	GLuint id;
public:
	Texture(string texturePath, GLuint id);
	~Texture();
	void bindTexture();
	void unbindTexture();
	GLuint getTextureID();

};

