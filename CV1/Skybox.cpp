#include "Skybox.h"

Skybox::Skybox()
{
	this->followCamera = true;
	this->shaderProgram = new ShaderProgram("skyboxVertex.vert", "skyboxFragment.frag", SHADER_SKYBOX);
	this->modelMatrix = glm::mat4(1.0f);
	this->viewMatrix = glm::mat4(1.0f);
	this->projectionMatrix = glm::mat4(1.0f);
	this->model = new SkyboxModel();
}

void Skybox::draw()
{
	this->shaderProgram->use();
	this->shaderProgram->setCamMatrix(this->projectionMatrix, this->viewMatrix);
	this->shaderProgram->setTransformMatrix(this->modelMatrix);
	this->shaderProgram->setIntUniform("skybox", 1);
	this->model->drawModel();
	this->shaderProgram->stop();
}

void Skybox::update(Camera& camera)
{
	this->viewMatrix = camera.getViewMatrix();
	this->projectionMatrix = camera.getProjectionMatrix();
	if (this->followCamera) {
		this->modelMatrix = glm::translate(glm::mat4(1.0f), camera.getPosition());
	}
}

void Skybox::deattach()
{
	this->followCamera = false;
}

void Skybox::attach()
{
	this->followCamera = true;
}

void Skybox::update(PointLight& light, int light_id)
{
}

void Skybox::update(SpotLight& light, int light_id)
{
}

void Skybox::update(DirectionalLight& light, int light_id)
{
}
