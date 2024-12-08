#include "SkyboxModel.h"

/**
* @file SkyboxModel.cpp
 *
 * @brief SkyboxModel. file with functions definitions
 *
 * This file contains functions definitions for SkyboxModel class
 * which is used for drawing skybox
 *
 *
 * @author Jiøí Fousek FOU0027
*/

SkyboxModel::SkyboxModel()
{
	this->texture = new CubeTexture(1);
	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(skycube), &skycube, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

}

void SkyboxModel::drawModel()
{
	glBindVertexArray(this->vao);
	this->texture->bind();

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glClear(GL_DEPTH_BUFFER_BIT);

	this->texture->unbind();
	glBindVertexArray(0);
}
