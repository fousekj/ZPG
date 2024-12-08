#include "ShaderProgram.h"

/**
 * @file ShaderProgram.cpp
 *
 * @brief ShaderProgram.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, PointLight* light)
{
	ShaderLoader* shaderLoader = new ShaderLoader();
	this->programID = shaderLoader->loadShader(vertexPath, fragmentPath);
	this->use();
}

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
{
	ShaderLoader* shaderLoader = new ShaderLoader();
	this->programID = shaderLoader->loadShader(vertexPath, fragmentPath);
	this->use();
}

void ShaderProgram::use()
{
	glUseProgram(this->programID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
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

void ShaderProgram::setMaterial(Material* material)
{
	//this->use();
	if (material != NULL)
	{
		this->setFloatUniform("r_a", material->r_a);
		this->setFloatUniform("r_d", material->r_d);
		this->setFloatUniform("r_s", material->r_s);
	}

	//this->stop();
}

void ShaderProgram::setTexture(Texture* texture)
{
	this->setIntUniform("textureID", texture->getTextureID());
}

void ShaderProgram::update(Camera& camera)
{
	this->use();
	this->setCamMatrix(camera.getProjectionMatrix(), camera.getViewMatrix());
	this->setViewPosition(camera.getPosition());
	this->stop();
}

void ShaderProgram::update(PointLight& light, int light_id)
{
	this->use();
	this->setVec3Uniform("lights[" + to_string(light_id) + "].position", light.position);
	this->setVec3Uniform("lights[" + to_string(light_id) + "].color", light.color);
	this->setFloatUniform("lights[" + to_string(light_id) + "].constant", light.constant);
	this->setFloatUniform("lights[" + to_string(light_id) + "].linear", light.linear);
	this->setFloatUniform("lights[" + to_string(light_id) + "].quadratic", light.quadratic);
	this->setIntUniform("lights[" + to_string(light_id) + "].type", POINT_LIGHT);
	this->setIntUniform("lightCount", light_id + 1);
	this->stop();
}

void ShaderProgram::update(SpotLight& light, int light_id)
{
	this->use();
	this->setVec3Uniform("lights[" + to_string(light_id) + "].position", light.position);
	this->setVec3Uniform("lights[" + to_string(light_id) + "].color", light.color);
	this->setFloatUniform("lights[" + to_string(light_id) + "].constant", light.constant);
	this->setFloatUniform("lights[" + to_string(light_id) + "].linear", light.linear);
	this->setFloatUniform("lights[" + to_string(light_id) + "].quadratic", light.quadratic);
	this->setVec3Uniform("lights[" + to_string(light_id) + "].direction", light.direction);
	this->setFloatUniform("lights[" + to_string(light_id) + "].cutOff", light.cutOff);
	this->setIntUniform("lights[" + to_string(light_id) + "].type", SPOT_LIGHT);
	this->setIntUniform("lightCount", light_id + 1);
	this->stop();
}

void ShaderProgram::update(DirectionalLight& light, int light_id)
{
	this->use();
	this->setVec3Uniform("lights[" + to_string(light_id) + "].direction", light.direction);
	this->setVec3Uniform("lights[" + to_string(light_id) + "].color", light.color);
	this->setIntUniform("lights[" + to_string(light_id) + "].type", DIRECTIONAL_LIGHT);
	this->setIntUniform("lightCount", light_id + 1);
	this->stop();
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

void ShaderProgram::setIntUniform(string name, int value)
{
	GLuint id = glGetUniformLocation(this->programID, name.c_str());
	if (id == -1) {
		fprintf(stderr, "Error: Uniform variable '%s' not found in shader program.\n", name.c_str());
		exit(EXIT_FAILURE);
	}
	glUniform1i(id, value);
}

