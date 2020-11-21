#include <iostream>
#include <algorithm>
#include <vector>

#include <string>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glxew.h>

#define FRAGMENT std::string( "Triangle.fragmentshader" )
#define VERTEX std::string( "Triangle.vertexshader" )

//	Class define gl loader
class ShaderProgramLoader
{

	//	Attribute
	public:
		GLuint shaderProgram;

		//	Shader program
		GLuint vertexShader;
		GLuint fragmentShader;

	public:
		ShaderProgramLoader();
		~ShaderProgramLoader();

};


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

	glewExperimental = GL_TRUE;
	glewInit();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	
	std::cout << "File vertex shader = " << VERTEX << std::endl;
	std::cout << "File fragment shader = " << FRAGMENT << std::endl;
	std::cout << "Testing draw gl shader" << std::endl;

	std::ifstream vertextStream( VERTEX );
	std::ifstream fragmentStream( FRAGMENT );

	std::string vertexSourceString( ( std::istreambuf_iterator<char>( vertextStream ) ),
									( std::istreambuf_iterator<char>() ) );
	std::string fragmentSourceString( ( std::istreambuf_iterator<char>( fragmentStream ) ),
										( std::istreambuf_iterator<char>() ) );


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
	const char *vertexSourceString_cstr = vertexSourceString.c_str(); 
	const char *fragmentSourceString_cstr = fragmentSourceString.c_str(); 
	
	//	Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSourceString_cstr, NULL);
	glCompileShader( vertexShader );

	GLint statusVertex;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &statusVertex);

	if ( statusVertex != GL_TRUE )
	{
		std::cerr << "vertex shader is compile error" << std::endl;
		return -1;
	}

	//	Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSourceString_cstr, NULL);
	glCompileShader( fragmentShader );

	GLint statusFragment;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &statusFragment);

	if ( statusFragment != GL_TRUE )
	{
		std::cerr << "fragment shader is compile error" << std::endl;
		return -1;
	}

	//	Create program
	//		and attach to shader to the program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram( shaderProgram );


	//	Get attribute 
	//		Get attribute 
	GLint vertexAttribute = glGetAttribLocation(shaderProgram, "vertex");

	std::cout << "Link finish" << std::endl;

	while(!glfwWindowShouldClose(window))
	{

		glClear( GL_COLOR_BUFFER_BIT );

		//	Use the shader program
		glUseProgram( shaderProgram );

		glEnableVertexAttribArray(vertexAttribute);
		glVertexAttribPointer( vertexAttribute, 3, GL_FLOAT, false, 0, 0 );

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    		glfwSetWindowShouldClose(window, GL_TRUE);

	}

	glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();


	return 0;
}
