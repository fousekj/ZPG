#include "Model.h"

/**
 * @file Model.cpp
 *
 * @brief Model.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Model::Model(GLenum drawMode, const float* points, int pointsSize) {

	this->drawMode = drawMode;
	this->points = points;
	this->pointsSize = pointsSize;

	//vertex buffer object (VBO)
	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, pointsSize * 6 * sizeof(float), this->points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

	glBindVertexArray(0);
}


void Model::drawModel()
{
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, pointsSize);
}