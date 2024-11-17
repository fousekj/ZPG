#include "ShaderProgram.h"

/**
 * @file ShaderProgram.cpp
 *
 * @brief ShaderProgram.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, Light* light)
{
	ShaderLoader* shaderLoader = new ShaderLoader();
	this->programID = shaderLoader->loadShader(vertexPath, fragmentPath);
	//this->light = light;
}

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
{
	ShaderLoader* shaderLoader = new ShaderLoader();
	this->programID = shaderLoader->loadShader(vertexPath, fragmentPath);
	//this->light = NULL;
}

void ShaderProgram::use()
{
	glUseProgram(this->programID);
	/*if (this->light != NULL) {
		this->setVec3Uniform("lightPosition", this->light->position);
		this->setVec3Uniform("lightColor", this->light->color);
	}*/
}

GLuint ShaderProgram::getTransformID()
{
	GLuint modelMatrix = glGetUniformLocation(this->programID, "modelMatrix");
	if (modelMatrix == -1)
	{
		fprintf(stderr, "Error: Uniform variable 'modelMatrix' not found in shader program.\n");
		exit(EXIT_FAILURE);
	}
	return modelMatrix;
}

GLuint ShaderProgram::getProjectionMatrixID()
{
	GLuint projMat = glGetUniformLocation(this->programID, "projectionMatrix");
	if (projMat == -1)
	{
		fprintf(stderr, "Error: Uniform variable 'projectionMatrix' not found in shader program.\n");
		exit(EXIT_FAILURE);
	}
	return projMat;
}

GLuint ShaderProgram::getViewMatrixID()
{
	GLuint viewMat = glGetUniformLocation(this->programID, "viewMatrix");
	if (viewMat == -1)
	{
		fprintf(stderr, "Error: Uniform variable 'viewMatrix' not found in shader program.\n");
		exit(EXIT_FAILURE);
	}
	return viewMat;
}

void ShaderProgram::setCamMatrix(glm::mat4 projectionMat, glm::mat4 viewMat)
{
	glUniformMatrix4fv(this->getViewMatrixID(), 1, GL_FALSE, glm::value_ptr(viewMat));
	glUniformMatrix4fv(this->getProjectionMatrixID(), 1, GL_FALSE, glm::value_ptr(projectionMat));
}

void ShaderProgram::setObjectColor(glm::vec3 color)
{
	this->setVec3Uniform("objectColor", color);
}

void ShaderProgram::setViewPosition(glm::vec3 position)
{
	this->setVec3Uniform("viewPosition", position);
}

void ShaderProgram::setTransformMatrix(glm::mat4 matrix)
{
	glUniformMatrix4fv(this->getTransformID(), 1, GL_FALSE, &matrix[0][0]);
}

void ShaderProgram::update(Camera& camera)
{
	this->setCamMatrix(camera.getProjectionMatrix(), camera.getViewMatrix());
	this->setViewPosition(camera.getPosition());
}

void ShaderProgram::update(Light& light, int light_id)
{
	this->setVec3Uniform("pointLights[" + to_string(light_id) + "].position", light.position);
	this->setVec3Uniform("pointLights[" + to_string(light_id) + "].color", light.color);
	this->setFloatUniform("pointLights[" + to_string(light_id) + "].constant", light.constant);
	this->setFloatUniform("pointLights[" + to_string(light_id) + "].linear", light.linear);
	this->setFloatUniform("pointLights[" + to_string(light_id) + "].quadratic", light.quadratic);

	//this->setVec3Uniform("lightPosition", light.position);
	//this->setVec3Uniform("lightColor", light.color);
}

void ShaderProgram::setMat4Uniform(string name, glm::mat4 value)
{
	GLuint id = glGetUniformLocation(this->programID, name.c_str());
	if (id == -1) {
		fprintf(stderr, "Error: Uniform variable '%s' not found in shader program.\n", name.c_str());
		exit(EXIT_FAILURE);
	}
	glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setVec3Uniform(string name, glm::vec3 value)
{
	GLuint id = glGetUniformLocation(this->programID, name.c_str());
	if (id == -1) {
		fprintf(stderr, "Error: Uniform variable '%s' not found in shader program.\n", name.c_str());
		exit(EXIT_FAILURE);
	}
	glUniform3fv(id, 1, glm::value_ptr(value));
}

void ShaderProgram::setFloatUniform(string name, float value)
{
	GLuint id = glGetUniformLocation(this->programID, name.c_str());
	if (id == -1) {
		fprintf(stderr, "Error: Uniform variable '%s' not found in shader program.\n", name.c_str());
		exit(EXIT_FAILURE);
	}
	glUniform1f(id, value);
}

