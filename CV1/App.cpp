#include "App.h"

/**
 * @file App.cpp
 *
 * @brief App.cpp file with functions implementations
 * This file contains all functions implementations for App class
 *
 * @author Jiøí Fousek FOU0027
  **/


void App::createTriangle()
{
	ShaderProgram* shaderTriangle = new ShaderProgram("4LightsVertex.vert", "PhongFragment.frag", SHADER_PHONG);
	PointLight* light = new PointLight(glm::vec3(0.f, 0.f, 5.f), glm::vec3(1.f, .5f, 0.5f), 0);
	light->attach(shaderTriangle);

	this->camera->attach(shaderTriangle);
	Scene* sceneTriangle = new Scene();
	sceneTriangle->addLight(light);
	DrawableObject* trinagle = new DrawableObject(shaderTriangle, new Model(GL_TRIANGLES, triangle, 3), glm::vec3(1.f));
	trinagle->setScale(0.5f);
	trinagle->setTranslation(glm::vec3(0.0f, 0.0f, 0.f));
	sceneTriangle->addObject(trinagle);
	this->scenes.push_back(sceneTriangle);
}

void App::create4Lights()
{
	PointLight* light = new PointLight(glm::vec3(0.f, 0.f, 5.f), glm::vec3(1.f, 1.f, 1.f), 0);
	glm::vec3 color = glm::vec3(0.2f);
	Model* suzi = new Model(GL_TRIANGLES, suziSmooth, 2904);
	Scene* scene4Lights = new Scene();
	scene4Lights->addLight(light);
	
	ShaderProgram* spPhong = new ShaderProgram("4LightsVertex.vert", "PhongFragment.frag", light, SHADER_PHONG);
	this->camera->attach(spPhong);
	light->attach(spPhong);
	DrawableObject* phong = new DrawableObject(spPhong, suzi, color);
	phong->setScale(1.f);
	phong->setTranslation(glm::vec3(-5.f, 0.f, 0.f));
	phong->setRotation(0.f, glm::vec3(1, 0, 0));
	scene4Lights->addObject(phong);

	
	ShaderProgram* spBlinn = new ShaderProgram("4LightsVertex.vert", "BlinnFragment.frag", light, SHADER_BLINN);
	this->camera->attach(spBlinn);
	light->attach(spBlinn);
	DrawableObject* blinn = new DrawableObject(spBlinn, suzi, color);
	blinn->setScale(1.f);
	blinn->setTranslation(glm::vec3(-1.5f, 0.f, 0.f));
	blinn->setRotation(0.f, glm::vec3(1, 0, 0));
	scene4Lights->addObject(blinn);

	ShaderProgram* spLambert = new ShaderProgram("4LightsVertex.vert", "LambertFragment.frag", light, SHADER_LAMBERT);
	this->camera->attach(spLambert);
	light->attach(spLambert);
	DrawableObject* lambert = new DrawableObject(spLambert, suzi, color);
	lambert->setScale(1.f);
	lambert->setTranslation(glm::vec3(1.5f, 0.f, 0.f));
	lambert->setRotation(0.f, glm::vec3(1, 0, 0));
	scene4Lights->addObject(lambert);
	
	ShaderProgram* spConstant = new ShaderProgram("4LightsVertex.vert", "ConstantFragment.frag", light, SHADER_CONSTANT);
	this->camera->attach(spConstant);
	light->attach(spConstant);
	DrawableObject* constant = new DrawableObject(spConstant, suzi, color);
	constant->setScale(1.f);
	constant->setTranslation(glm::vec3(5.f, 0.f, 0.f));
	constant->setRotation(0.f, glm::vec3(1, 0, 0));
	scene4Lights->addObject(constant);
	
	this->scenes.push_back(scene4Lights);
}

void App::createForestWithLights()
{
	ShaderProgram* shaderForest = new ShaderProgram("MulitpleLightsVert.vert", "MulitpleLightsFrag.frag", SHADER_PHONG);
	PointLight* light = new PointLight(glm::vec3(0.f, 5.f, 0.f), glm::vec3(0.f, 0.f, 1.f), 0);
	light->attach(shaderForest);
	this->camera->attach(shaderForest);
	PointLight* light2 = new PointLight(glm::vec3(30.f, 5.f, 0.f), glm::vec3(1.f, 0.f, 0.f), 1);
	light2->attach(shaderForest);

	PointLight* light3 = new PointLight(glm::vec3(50.f, 5.f, 50.f), glm::vec3(0.f, 1.f, 0.f), 2);
	light3->attach(shaderForest);

	Scene* scene = new Scene();
	scene->addLight(light);
	scene->addLight(light2);
	scene->addLight(light3);


	ShaderProgram* shaderTexture = new ShaderProgram("texturedVertexShader.vert", "texturedFragmentShader.frag", SHADER_PHONG);
	DrawableObject* plainObj = new DrawableObject(shaderTexture, new TexturedModel(GL_TRIANGLES, plain, 6, "grass.png", 1), glm::vec3(1.f, 1.f, 1.f), new Material(0.3, 0.3, 0.3));
	this->camera->attach(shaderTexture);
	light->attach(shaderTexture);
	light2->attach(shaderTexture);
	light3->attach(shaderTexture);
	plainObj->setScale(100.f);
	scene->addObject(plainObj);

	glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float randScale = 1 + (rand() % 3);
			glm::vec3 loc(i * 10.f, 0.f, j * 10);
			float randRot = 1 + (rand() % 180);
			DrawableObject* treeObj = new DrawableObject(shaderForest, new Model(GL_TRIANGLES, tree, 92814), color);
			treeObj->setScale(randScale);
			treeObj->setTranslation(loc);
			treeObj->setDynamicRotation(randRot, glm::vec3(0, 1, 0), 1.f);
			scene->addObject(treeObj);

			loc = glm::vec3(i * 10.f + 5.f, 0.f, j * 10);
			DrawableObject* bushObj = new DrawableObject(shaderForest, new Model(GL_TRIANGLES, bushes, 8730), color);
			bushObj->setScale(randScale);
			bushObj->setTranslation(loc);
			scene->addObject(bushObj);
		}
	}

	this->scenes.push_back(scene);
}

void App::createBallsWithLights()
{
	ShaderProgram* shaderPhong = new ShaderProgram("MulitpleLightsVert.vert", "MulitpleLightsFrag.frag", SHADER_PHONG);
	PointLight* light = new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), 0);
	light->attach(shaderPhong);
	this->camera->attach(shaderPhong);
	Scene* sceneBalls = new Scene();
	sceneBalls->addLight(light);
	glm::vec3 color = glm::vec3(0.3f, 0.3f, 0.3f);

	DrawableObject* ball_1 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color);
	ball_1->setScale(0.5f);
	ball_1->setTranslation(glm::vec3(-2.0f, 0.0f, 0));
	ball_1->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_1);

	DrawableObject* ball_2 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color);
	ball_2->setScale(0.5f);
	ball_2->setTranslation(glm::vec3(0.0f, 2.0f, 0));
	ball_2->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_2);

	DrawableObject* ball_3 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color);
	ball_3->setScale(0.5f);
	ball_3->setTranslation(glm::vec3(2.0f, 0.0f, 0));
	ball_3->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_3);

	DrawableObject* ball_4 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color);
	ball_4->setScale(0.5f);
	ball_4->setTranslation(glm::vec3(0.0f, -2.0f, 0.f));
	ball_4->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_4);
	this->scenes.push_back(sceneBalls);
}

void App::createNightForest()
{
	ShaderProgram* shaderNight = new ShaderProgram("MulitpleLightsVert.vert", "MulitpleLightsFrag.frag", SHADER_PHONG);
	SpotLight* spotLight = new SpotLight(this->camera, glm::vec3(1.f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(17.5f)), 0);
	spotLight->attach(shaderNight);

	Scene* scene = new Scene();
	scene->addLight(spotLight);
	glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float randScale = 1 + (rand() % 3);
			glm::vec3 loc(i * 10.f, 0.f, j * 10);
			float randRot = 1 + (rand() % 180);
			DrawableObject* treeObj = new DrawableObject(shaderNight, new Model(GL_TRIANGLES, tree, 92814), color);
			treeObj->setScale(randScale);
			treeObj->setTranslation(loc);
			treeObj->setDynamicRotation(randRot, glm::vec3(0, 1, 0), 1.f);
			scene->addObject(treeObj);

			loc = glm::vec3(i * 10.f + 5.f, 0.f, j * 10);
			DrawableObject* bushObj = new DrawableObject(shaderNight, new Model(GL_TRIANGLES, bushes, 8730), color);
			bushObj->setScale(randScale);
			bushObj->setTranslation(loc);
			scene->addObject(bushObj);
		}
	}

	this->scenes.push_back(scene);
}

void App::createBallsDifferentMaterials()
{
	ShaderProgram* shaderPhong = new ShaderProgram("MulitpleLightsVert.vert", "MulitpleLightsFrag.frag", SHADER_PHONG);
	PointLight* light = new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), 0);
	light->attach(shaderPhong);
	this->camera->attach(shaderPhong);
	Scene* sceneBalls = new Scene();
	sceneBalls->addLight(light);
	glm::vec3 color = glm::vec3(0.3f, 0.3f, 0.3f);

	DrawableObject* ball_1 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color, new Material(1, 1, 1));
	ball_1->setScale(0.5f);
	ball_1->setTranslation(glm::vec3(-2.0f, 0.0f, 0));
	ball_1->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_1);

	DrawableObject* ball_2 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color, new Material(0.1, 0.1, 0.1));
	ball_2->setScale(0.5f);
	ball_2->setTranslation(glm::vec3(0.0f, 2.0f, 0));
	ball_2->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_2);

	DrawableObject* ball_3 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color, new Material(0.5, 0.5, 0.5));
	ball_3->setScale(0.5f);
	ball_3->setTranslation(glm::vec3(2.0f, 0.0f, 0));
	ball_3->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_3);

	DrawableObject* ball_4 = new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), color, new Material(0.7, 0.7, 0.7));
	ball_4->setScale(0.5f);
	ball_4->setTranslation(glm::vec3(0.0f, -2.0f, 0.f));
	ball_4->setRotation(0.f, glm::vec3(1, 0, 0));
	sceneBalls->addObject(ball_4);
	this->scenes.push_back(sceneBalls);
}

void App::createSkyboxScene()
{
	Scene* skyboxScene = new Scene();
	Skybox* skybox = new Skybox();
	this->camera->attach(skybox);
	skyboxScene->setSkybox(skybox);

	ShaderProgram* shaderForest = new ShaderProgram("MulitpleLightsVert.vert", "MulitpleLightsFrag.frag", SHADER_PHONG);
	this->camera->attach(shaderForest);

	DirectionalLight* light = new DirectionalLight(glm::vec3(1.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), 0);
	light->attach(shaderForest);
	skyboxScene->addLight(light);


	glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float randScale = 1 + (rand() % 3);
			glm::vec3 loc(i * 10.f, 0.f, j * 10);
			float randRot = 1 + (rand() % 180);
			DrawableObject* treeObj = new DrawableObject(shaderForest, new Model(GL_TRIANGLES, tree, 92814), color);
			treeObj->setScale(randScale);
			treeObj->setTranslation(loc);
			treeObj->setDynamicRotation(randRot, glm::vec3(0, 1, 0), 1.f);
			skyboxScene->addObject(treeObj);

			loc = glm::vec3(i * 10.f + 5.f, 0.f, j * 10);
			DrawableObject* bushObj = new DrawableObject(shaderForest, new Model(GL_TRIANGLES, bushes, 8730), color);
			bushObj->setScale(randScale);
			bushObj->setTranslation(loc);
			skyboxScene->addObject(bushObj);
		}
	}


	this->scenes.push_back(skyboxScene);

}

void App::createHouse()
{
	ShaderProgram* shaderAssimp = new ShaderProgram("texturedVertexShader.vert", "texturedFragmentShader.frag", SHADER_PHONG);
	PointLight* light = new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), 0);
	light->attach(shaderAssimp);
	DrawableObject* assimp = new DrawableObject(shaderAssimp, new AssimpModel("house.obj", "house.png", 2), glm::vec3(1.f, 1.f, 1.f));
	
	this->camera->attach(shaderAssimp);
	Scene* scene = new Scene();
	scene->addLight(light);
	scene->addObject(assimp);
	this->scenes.push_back(scene);
	

}

App::App() 
{ 
	this->currentScene = 0;
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f));
}

App::~App() { }

void App::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void App::compileShaders()
{
	this->createTriangle();
	this->createForestWithLights();
	this->createNightForest();
	this->createBallsWithLights();
	this->createBallsDifferentMaterials();
	this->createHouse();
	this->createSkyboxScene();
	this->create4Lights();
	
}



void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		this->currentScene++;
		if (this->currentScene == this->scenes.size())
			this->currentScene = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->camera->moveForward();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->camera->moveBackward();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->camera->moveLeft();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->camera->moveRight();
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		if (this->scenes[currentScene]->isSkyboxSet())
			this->scenes[currentScene]->deattachSkybox();
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		if (this->scenes[currentScene]->isSkyboxSet())
			this->scenes[currentScene]->attachSkybox();
	}

}

void App::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void App::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void App::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
	this->camera->setAspect(width / height);
}

void App::cursor_callback(GLFWwindow* window, double x, double y) { 
	//printf("cursor_callback \n");
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);
	this->camera->moveMouse(width, height, x, y);

}

void App::button_callback(GLFWwindow* window, int button, int action, int mode) {
	//if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void App::error_callback_static(int error, const char* description) { fputs(description, stderr); }

void App::key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods) {
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->key_callback(window, key, scancode, action, mods); 
}

void App::window_focus_callback_static(GLFWwindow* window, int focused) {
	//App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	//app->window_focus_callback(window, focused); 
}

void App::window_iconify_callback_static(GLFWwindow* window, int iconified) {
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->window_iconify_callback(window, iconified);
}

void App::window_size_callback_static(GLFWwindow* window, int width, int height) {
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->window_size_callback(window, width, height);
}

void App::cursor_callback_static(GLFWwindow* window, double x, double y) {
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->cursor_callback(window, x, y); 
}

void App::button_callback_static(GLFWwindow* window, int button, int action, int mode) {
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->button_callback(window, button, action, mode);
}

void App::initialization()
{
	glfwSetErrorCallback(this->error_callback_static);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!this->window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetWindowUserPointer(window, this);
	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);

	glewExperimental = GL_TRUE;
	glewInit();


	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(this->window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

	int a;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &a);
	printf("Texture units: %d", a);
}

void App::run()
{
	glfwSetKeyCallback(this->window, this->key_callback_static);
	glfwSetWindowFocusCallback(this->window, this->window_focus_callback_static);
	glfwSetWindowIconifyCallback(this->window, this->window_iconify_callback_static);
	glfwSetWindowSizeCallback(this->window, this->window_size_callback_static);
	glfwSetMouseButtonCallback(this->window, this->button_callback_static);
	glfwSetCursorPosCallback(this->window, this->cursor_callback_static);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->scenes[currentScene]->render();


		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


