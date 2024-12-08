#pragma once
#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include "CubeTexture.h"
#include "Observer.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include "skycube.h"


class Skybox : public Observer
{
private:
	CubeTexture* texture;
	GLuint VAO;
	GLuint VBO;
	bool followCamera = true;
	glm::mat4 modelMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	ShaderProgram* shaderProgram;

public:
	Skybox();
	~Skybox();
	void draw();
	//void setTexture(GLuint texture);
	void update(Camera &camera) override;
	// implement all the necessary functions from observer
	void update(PointLight& light, int light_id = 0);
	void update(SpotLight& light, int light_id = 0);
	void update(DirectionalLight& light, int light_id = 0) ;

};

