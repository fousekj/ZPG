#pragma once
#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include "CubeTexture.h"
#include "Observer.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include "skycube.h"
#include "SkyboxModel.h"


/**
 * @file Skybox.h
 *
 * @brief Skybox class
 *
 *  This class is used to create skybox
 *  It is used to create skybox and render it
 * 
 * @author Jiøí Fousek FOU0027
 */

class Skybox : public Observer
{
private:

	SkyboxModel* model;
	bool followCamera = true;
	glm::mat4 modelMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	ShaderProgram* shaderProgram;

public:
	Skybox();
	void draw();
	void update(Camera &camera) override;
	void deattach();
	void attach();

	void update(PointLight& light, int light_id = 0);
	void update(SpotLight& light, int light_id = 0);
	void update(DirectionalLight& light, int light_id = 0);

};

