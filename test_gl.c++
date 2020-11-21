#include <iostream>
#include <algorithm>
#include <vector>

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "include/ShaderProgramLoader.h"

#define FRAGMENT std::string( "shader_program/Triangle.fragmentshader" )
#define VERTEX std::string( "shader_program/Triangle.vertexshader" )


int main(int argc, char const *argv[])
{

	//	Init window
	glfwInit();

	//	Create window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr); // Windowed

	//	Make context !!!!!!!!!
	glfwMakeContextCurrent(window);


	//	Initi gl extension for make genBuffer compatible
	glewExperimental = GL_TRUE;
	glewInit();

	//	Clear color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//
	//	vao and vbo stuff
	//

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray( vao );

	float vertices[] = { 0.0f,  0.5f, 0.0f, // Vertex 1 (X, Y)
							0.5f, -0.5f, 0.0f, // Vertex 2 (X, Y)
							-0.5f, -0.5f, 0.0f,  // Vertex 3 (X, Y)
						};

	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	//	Shader stuff
	//	Initial shader program object
	std::shared_ptr<ShaderProgramLoader> shaderProgramLoader = std::make_shared<ShaderProgramLoader>();

	shaderProgramLoader->compileVertexShader( VERTEX );
	shaderProgramLoader->compileFragmentShader( FRAGMENT );
	shaderProgramLoader->linkProgram();
	shaderProgramLoader->useProgram();

	//	Get vertex attribute location
	GLint vertexAttributeLocation = shaderProgramLoader->getAttributeLocation( "vertex" );

	while(!glfwWindowShouldClose(window))
	{

		glClear( GL_COLOR_BUFFER_BIT );

		glEnableVertexAttribArray(vertexAttributeLocation);
		glVertexAttribPointer( vertexAttributeLocation, 
								3, 
								GL_FLOAT, 
								false, 
								0, 0 );

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    		glfwSetWindowShouldClose(window, GL_TRUE);

	}

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
