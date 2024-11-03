#include "App.h"

/**
 * @file App.cpp
 *
 * @brief App.cpp file with functions implementations
 *
 * @author Jiøí Fousek
  **/

void App::createForest()
{
	ShaderProgram* shaderForest = new ShaderProgram("ForestVertex.vert", "ForestFragment.frag");
	Scene* scene = new Scene();
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float randScale = (float)rand() / RAND_MAX;
			glm::vec3 loc(i * 10.f, 0.f, j * 10);
			float randRot = 1 + (rand() % 180);
			scene->addObject(new DrawableObject(shaderForest, new Model(GL_TRIANGLES, tree, 92814), new Transformation(randScale, loc, randRot, glm::vec3(0, 1, 0))));
			
			loc = glm::vec3(i * 10.f + 5.f, 0.f, j * 10);
			scene->addObject(new DrawableObject(shaderForest, new Model(GL_TRIANGLES, bushes, 8730), new Transformation(randScale, loc, randRot, glm::vec3(0, 1, 0))));
		}		
	}
	this->scenes.push_back(scene);

}

void App::createBalls()
{
	//this->sceneObjects->addObject(new DrawableObject(this->sceneObjects->getShaderProgram(), new Model(GL_TRIANGLES, suziSmooth, 2904), new Transformation(0.5f, glm::vec3(0.5f, 0.5f, 0), 0.f, glm::vec3(1, 0, 0))));
	//this->sceneObjects->addObject(new DrawableObject(this->sceneObjects->getShaderProgram(), new Model(GL_TRIANGLES, suziSmooth, 2904), new Transformation(0.5f, glm::vec3(-0.5f, -0.5f, 0), 0.f, glm::vec3(1, 0, 0))));
	ShaderProgram* shaderPhong = new ShaderProgram("BallsVertex.vert", "BallsFragment.frag", new Light(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));
	Scene* sceneBalls = new Scene();
	sceneBalls->addObject(new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), new Transformation(0.5f, glm::vec3(-2.0f, 0.0f, 0), 0.f, glm::vec3(1, 0, 0))));
	sceneBalls->addObject(new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), new Transformation(0.5f, glm::vec3(0.0f, 2.0f, 0), 0.f, glm::vec3(1, 0, 0))));
	sceneBalls->addObject(new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), new Transformation(0.5f, glm::vec3(2.0f, 0.0f, 0), 0.f, glm::vec3(1, 0, 0))));
	sceneBalls->addObject(new DrawableObject(shaderPhong, new Model(GL_TRIANGLES, sphere, 2880), new Transformation(0.5f, glm::vec3(0.0f, -2.0f, 0), 0.f, glm::vec3(1, 0, 0))));
	this->scenes.push_back(sceneBalls);
}

void App::createTriangle()
{
	ShaderProgram* shaderTriangle = new ShaderProgram("TriangleVertex.vert", "TriangleFragment.frag");
	Scene* sceneTriangle = new Scene();
	sceneTriangle->addObject(new DrawableObject(shaderTriangle, new Model(GL_TRIANGLES, triangle, 3), new Transformation(0.5f, glm::vec3(0.f, 0.f, 0.f), 0.f, glm::vec3(1, 0, 0))));
	this->scenes.push_back(sceneTriangle);
}

App::App() 
{ 
	this->currentScene = 0;
}

App::~App() { }

void App::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void App::compileShaders()
{
	//this->sceneForest = new Scene(new ShaderProgram("ForestVertex.vert", "ForestFragment.frag"));

	//this->sceneObjects = new Scene(new ShaderProgram("BallsVertex.vert", "BallsFragment.frag"));

	this->createTriangle();

	this->createForest();
	this->createBalls();

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

	if (key == 262) {
		//this->sceneForest->getObjects()[0]->setTransformRotation(10, glm::vec3(0, 1, 0));
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->scenes[this->currentScene]->camera->moveForward();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->scenes[this->currentScene]->camera->moveBackward();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->scenes[this->currentScene]->camera->moveLeft();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->scenes[this->currentScene]->camera->moveRight();
	}

	//printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void App::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void App::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void App::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void App::cursor_callback(GLFWwindow* window, double x, double y) { 
	//printf("cursor_callback \n");
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);
	this->scenes[this->currentScene]->camera->moveMouse(width, height, x, y);

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
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
	app->window_focus_callback(window, focused); 
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

		/*if (forest == true)
			this->sceneForest->render();
		else
			this->sceneObjects->render();*/

		this->scenes[currentScene]->render();

		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


