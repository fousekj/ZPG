#include "App.h"

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

/**
 * @file main.cpp
 *
 * @brief Main function
 *
 * @author Jiří Fousek
  **/

float points[] = {
   -0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f,
};

const char* vertex_shader2 =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader2 =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = vec4 (0.6, 0.2, 0.9, 1.0);"
"}";



//static void error_callback(int error, const char* description) { fputs(description, stderr); }






int main(void)
{
	
	App* app = new App();
	app->initialization();
	app->run();

	//vertex buffer object (VBO)
	/*GLuint VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)
	GLuint VAO = 0;
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	//create and compile shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram); 

	GLuint vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader2, 1, &vertex_shader2, NULL);
	glCompileShader(vertexShader2);
	GLuint fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragment_shader2, NULL);
	glCompileShader(fragmentShader2);
	GLuint shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, fragmentShader2);
	glAttachShader(shaderProgram2, vertexShader2);
	glLinkProgram(shaderProgram2);*/

	/*GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
		glfwDestroyWindow(window);

		glfwTerminate();
		exit(EXIT_SUCCESS);
	}*/


	/*while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count


		glUseProgram(shaderProgram2);
		glBindVertexArray(VAO2);
		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);*/

}

/*
#include "Application.h"
int main(void)
{
	Application* app = new Application();
	app->initialization(); //OpenGL inicialization

	//Loading scene
	app->createShaders();
	app->createModels();
	app->run(); //Rendering 
}*/