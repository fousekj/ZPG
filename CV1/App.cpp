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
	/*
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.2f, glm::vec3(-3.0f, -4.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.2f, glm::vec3(3.0f, -4.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, bushes, 8730), new Transformation(0.2f, glm::vec3(2.0f, -4.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, bushes, 8730), new Transformation(0.2f, glm::vec3(-2.0f, -4.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, bushes, 8730), new Transformation(0.2f, glm::vec3(-1.f, -4.0f, -0.5f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, bushes, 8730), new Transformation(0.2f, glm::vec3(1.f, -4.0f, -0.5f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.15f, glm::vec3(-2.0f, -2.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.15f, glm::vec3(2.0f, -2.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.1f, glm::vec3(-5.0f, -1.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(0.1f, glm::vec3(5.0f, -1.0f, 0.0f), 0.f, glm::vec3(1, 0, 0))));
	*/
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float randScale = (float)rand() / RAND_MAX;
			glm::vec3 loc(i * 10.f, 0.f, j * 10);
			float randRot = 1 + (rand() % 180);
			this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, tree, 92814), new Transformation(randScale, loc, randRot, glm::vec3(0, 1, 0))));
			
			loc = glm::vec3(i * 10.f + 5.f, 0.f, j * 10);
			this->sceneForest->addObject(new DrawableObject(this->sceneForest->getShaderProgram(), new Model(GL_TRIANGLES, bushes, 8730), new Transformation(randScale, loc, randRot, glm::vec3(0, 1, 0))));
		}		
	}

}

void App::createObjects()
{
	this->sceneObjects->addObject(new DrawableObject(this->sceneObjects->getShaderProgram(), new Model(GL_TRIANGLES, suziSmooth, 2904), new Transformation(0.5f, glm::vec3(0.5f, 0.5f, 0), 0.f, glm::vec3(1, 0, 0))));
	this->sceneObjects->addObject(new DrawableObject(this->sceneObjects->getShaderProgram(), new Model(GL_TRIANGLES, suziSmooth, 2904), new Transformation(0.5f, glm::vec3(-0.5f, -0.5f, 0), 0.f, glm::vec3(1, 0, 0))));
}

App::App() 
{ 
	this->forest = true;
}

App::~App() { }

void App::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void App::compileShaders()
{
	const char* vertexShaderForest =
		"#version 330\n"
		"layout(location=0) in vec3 vPos;"
		"layout(location=1) in vec3 vColor;"
		"out vec3 fragColor;"
		"uniform mat4 modelMatrix;"		
		"uniform mat4 projectionMatrix;"
		"uniform mat4 viewMatrix;"
		"void main () {"
		"     gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vPos, 1.0);"
		"     fragColor = vColor;"
		"}";

	const char* fragmentShaderForest =
		"#version 330\n"
		"in vec3 fragColor;"
		"out vec4 fragColorOut;"
		"void main () {"
		"     fragColorOut = vec4 (fragColor, 1.0);"
		"}";

	this->sceneForest = new Scene(new ShaderProgram(new Shader(GL_VERTEX_SHADER, vertexShaderForest), new Shader(GL_FRAGMENT_SHADER, fragmentShaderForest)));


	const char* vertexShaderObjects =
		"#version 330\n"
		"layout(location=0) in vec3 vPos;"
		"layout(location=1) in vec3 vColor;"
		"uniform mat4 modelMatrix;"
		"void main () {"
		"     gl_Position = modelMatrix * vec4 (vPos, 1.0);"
		"}";

	const char* fragmentShaderObjects =
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main () {"
		"     frag_colour = vec4 (0.0, 1.0, 0.0, 1.0);"
		"}";

	this->sceneObjects = new Scene(new ShaderProgram(new Shader(GL_VERTEX_SHADER, vertexShaderObjects), new Shader(GL_FRAGMENT_SHADER, fragmentShaderObjects)));

}



void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == 32 && action == 1) {
		this->forest = !this->forest;
	}

	if (key == 262) {
		this->sceneForest->getObjects()[0]->setTransformRotation(10, glm::vec3(0, 1, 0));
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->sceneForest->camera->moveForward();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->sceneForest->camera->moveBackward();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->sceneForest->camera->moveLeft();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->sceneForest->camera->moveRight();
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
	this->sceneForest->camera->moveMouse(width, height, x, y);

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

	this->createForest();
	this->createObjects();


	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (forest == true)
			this->sceneForest->render();
		else
			this->sceneObjects->render();

		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


