#include "Model.h"

Model::Model(float* points, int size, GLenum drawMode)
{
	this->points = points;
	this->size = size;
	this->drawMode = drawMode;

}

void Model::createModel()
{
	//vertex buffer object (VBO)
	glGenBuffers(1, &this->vbo); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->points), this->points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &this->vao); //generate the VAO
	glBindVertexArray(this->vao); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Model::drawModel()
{
	glBindVertexArray(this->vao);
	glDrawArrays(this->drawMode, 0, this->size);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
