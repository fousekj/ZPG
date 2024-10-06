#include "App.h"

App::App()
{

}

App::~App()
{
	for (int i = 0; i < shaderPrograms.size(); i++)
	{
		delete shaderPrograms[i];
	}
	for (int i = 0; i < models.size(); i++)
	{
		delete models[i];
	}
}

void App::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void App::compileShaders()
{
	const char* vertex_shader =
	"#version 330\n"
	"layout(location=0) in vec3 vp;"
	"void main () {"
	"     gl_Position = vec4 (vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 330\n"
	"out vec4 frag_colour;"
	"void main () {"
	"     frag_colour = vec4 (0.6, 0.2, 0.9, 1.0);"
	"}";
	ShaderProgram* shaderProgram = new ShaderProgram(vertex_shader, fragment_shader);
	shaderProgram->createShaderProgram();
	shaderPrograms.push_back(shaderProgram);
	

}

void App::createModels()
{
	float points[] = {
	-0.5f, 0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	};

	Model* model1 = new Model(points, sizeof(points), GL_TRIANGLES);
	model1->createModel();
	shaderPrograms[0]->addModel(model1);
	models.push_back(model1);

	
}

void App::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < models.size(); i++)
	{
		shaderPrograms[i]->draw();
	}
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y) { printf("cursor_callback \n"); }

static void button_callback(GLFWwindow* window, int button, int action, int mode) {

	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void App::initialization()
{
	glfwSetErrorCallback(this->error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!this->window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);

	// start GLEW extension handler
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
	/*
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetMouseButtonCallback(window, button_callback);*/

	compileShaders();
	createModels();

	while (!glfwWindowShouldClose(this->window))
	{
		draw();
		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);

}

