#pragma once
#include <GL/glew.h>
#include <string>
#include <stdio.h>
#include <iostream>

#include "SOIL.h"
#include "skycube.h"

/**
 * @file CubeTexture.h
 *
 * @brief CubeTexture class
 *
 * This class is used for creating a cube texture
 * 
 * @author Jiri Fousek FOU0027
*/

using namespace std;
class CubeTexture
{
private:
	GLuint textureID;
	GLuint id;
public:
	CubeTexture(GLuint id);
	~CubeTexture();
	void bind();
	void unbind();
};

