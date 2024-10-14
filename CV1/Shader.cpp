#include "Shader.h"

/**
 * @file Shader.cpp
 *
 * @brief Shader.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

Shader::Shader(GLenum shaderType, const char* shaderSource)
{
    this->shaderType = shaderType;
    this->shaderSource = shaderSource;
    this->shaderID = glCreateShader(this->shaderType);
    glShaderSource(this->shaderID, 1, &this->shaderSource, NULL);
    glCompileShader(this->shaderID);


    GLint status;
    glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(this->shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(this->shaderID, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}
GLuint Shader::getShaderId()
{
    return this->shaderID;
}
