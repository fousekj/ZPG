#include "ShaderProgram.h"

/**
 * @file ShaderProgram.cpp
 *
 * @brief ShaderProgram.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

void ShaderProgram::createShaderProgram()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader_def, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader_def, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
		//glfwDestroyWindow(window);

		glfwTerminate();
		exit(EXIT_SUCCESS);
	}
	glUseProgram(shaderProgram);
}

ShaderProgram::ShaderProgram(const char* vertex_shader, const char* fragment_shader)
{
	this->vertex_shader_def = vertex_shader;
	this->fragment_shader_def = fragment_shader;

}


void ShaderProgram::draw(Model* model)
{
	glUseProgram(shaderProgram);
	model->drawModel();
	
}



