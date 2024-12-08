#include "Texture.h"

/**
* @file Texture.cpp
* 
* @brief Texture class implementation
* 
* @author Jiøí Fousek FOU0027
*/

Texture::Texture(string texturePath, GLuint id)
{
	this->id = id;
    glActiveTexture(GL_TEXTURE0 + this->id);

    this->textureID = SOIL_load_OGL_texture(texturePath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (this->textureID == NULL) {
        std::cout << "An error occurred while loading texture." << std::endl;
		std::cout << "Error: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }


    glBindTexture(GL_TEXTURE_2D, this->textureID);
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->textureID);
}

void Texture::bindTexture()
{
	glActiveTexture(GL_TEXTURE0 + this->id);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}

void Texture::unbindTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::getTextureID()
{
	return this->textureID;
}
