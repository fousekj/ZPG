#pragma once
#include <GL/glew.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <SOIL.h>

using namespace std;

/**
* @file Texture.h
 *
 * @brief Texture class
 *
 * This class is used for loading textures
 * and binding them to the objects
 *
 * @author Jiøí Fousek FOU0027
 *
 *
*/

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

