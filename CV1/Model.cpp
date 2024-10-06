#include "Model.h"

/**
 * @file Model.cpp
 *
 * @brief Model.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Model::Model(GLenum drawMode)
{
	this->drawMode = drawMode;

	float points[] = {
	-0.5f, 0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	};

	//vertex buffer object (VBO)
	glGenBuffers(1, &this->vbo); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &this->vao); //generate the VAO
	glBindVertexArray(this->vao); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

}

void Model::createModel()
{
	
}

void Model::drawModel()
{
	glBindVertexArray(this->vao);
	glDrawArrays(this->drawMode, 0, 3);
	//glDisableVertexAttribArray(0);
	//glBindVertexArray(0);
}
