#include "TexturedModel.h"

TexturedModel::TexturedModel(GLenum drawMode, const float* points, int pointsSize, string path, GLuint id)
{
	this->drawMode = drawMode;
	this->points = points;
	this->pointsSize = pointsSize;
	this->texture = new Texture(path, id);

	//vertex buffer object (VBO)
	this->vao = 0;
	this->vbo = 0;
	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, pointsSize * 8 * sizeof(float), this->points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float) * 3));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float) * 6));

	glBindVertexArray(0);

}

void TexturedModel::drawModel()
{
	this->texture->bindTexture();
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, this->pointsSize);
	glBindVertexArray(0);
	this->texture->unbindTexture();

}

Texture* TexturedModel::getTexture()
{
	return this->texture;
}
