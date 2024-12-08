#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

/**
 * @file ShaderProgram.h
 *
 * @brief ShaderProgram.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/

#include "Observer.h"

#include "Shader.h"
#include "Transformation.h"
#include "Model.h"
#include "ShaderLoader.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionalLight.h"
#include "Camera.h"
#include "Material.h"
#include "Texture.h"
#include "TexturedModel.h"

#define SHADER_PHONG 0
#define SHADER_LAMBERT 1
#define SHADER_BLINN 2
#define SHADER_CONSTANT 3
#define SHADER_SKYBOX 4



class ShaderProgram : public Observer

{
private:
	GLuint programID;

	void setVec3Uniform(string name, glm::vec3 value);
	void setFloatUniform(string name, float value);

	int shaderType;

	GLuint getTransformID();
	GLuint getProjectionMatrixID();
	GLuint getViewMatrixID();


public:
	ShaderProgram(const char* vertexPath, const char* fragmentPath, PointLight* light, int shaderType);
	ShaderProgram(const char* vertexPath, const char* fragmentPath, int shaderType);
	void use();
	void stop();
	void setCamMatrix(glm::mat4 projectionMat, glm::mat4 viewMat);
	void setObjectColor(glm::vec3 color);
	void setViewPosition(glm::vec3 position);
	void setTransformMatrix(glm::mat4 matrix);
	void setMaterial(Material* material);
	void setTexture(Texture* texture);
	void setMat4Uniform(string name, glm::mat4 value);
	void setIntUniform(string name, int value);
	
	void update(Camera& camera);
	void update(PointLight& light, int light_id);
	void update(SpotLight& light, int light_id);
	void update(DirectionalLight& light, int light_id);
};

