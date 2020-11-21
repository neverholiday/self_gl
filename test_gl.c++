#include <iostream>
#include <algorithm>
#include <vector>

#include <memory>

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
		ShaderProgramLoader( )
		{}

		~ShaderProgramLoader()
		{
			std::cout << "Delete program" << std::endl;
			this->deleteProgram();
		}

		void useProgram()
		{
			glUseProgram( this->shaderProgram );
		}

		void compileVertexShader( std::string vertexShaderFile )
		{
			this->vertexShader = glCreateShader( GL_VERTEX_SHADER );
			this->compileShader( this->vertexShader, vertexShaderFile );
		}
		void compileFragmentShader( std::string fragmentShaderFile )
		{
			this->fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
			this->compileShader( this->fragmentShader, fragmentShaderFile );
		}

		void linkProgram()
		{
			this->shaderProgram = glCreateProgram();
			glAttachShader( this->shaderProgram, this->vertexShader );
			glAttachShader( this->shaderProgram, this->fragmentShader );
			glLinkProgram( this->shaderProgram );

		}

		void detachShader()
		{
			glDetachShader( this->shaderProgram, this->fragmentShader );
			glDetachShader( this->shaderProgram, this->vertexShader );
			glDeleteShader( this->fragmentShader );
			glDeleteShader( this->vertexShader );
		}

		void deleteProgram()
		{
			glDeleteProgram( this->shaderProgram );
		}

		GLuint getAttributeLocation( std::string attributeName )
		{
			return glGetAttribLocation( this->shaderProgram, "vertex" );
		}

	protected:
		//
		//	Function to read shader file to string
		//
		std::string readShaderSourceFile( std::string shaderFile )
		{
			std::cout << "Read File shader = " << shaderFile << std::endl;
			std::ifstream shaderStream( shaderFile );
			std::string shaderSourceString( ( std::istreambuf_iterator<char>( shaderStream ) ),
											( std::istreambuf_iterator<char>() ) );
			return shaderSourceString;
		}

		//
		//	Function to compile shader from type
		//
		void compileShader( GLuint shader, std::string vertexShaderFile )
		{
			std::string shaderSourceString = this->readShaderSourceFile( vertexShaderFile );

			const char* shaderSourceString_cstr = shaderSourceString.c_str();
			glShaderSource( shader, 1, &shaderSourceString_cstr, NULL);
			glCompileShader( shader );

			GLint statusComplile;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &statusComplile);

			if ( statusComplile != GL_TRUE )
			{
				std::cerr << "this shader is compile error with errors" << std::endl;
				char buffer[512];
				glGetShaderInfoLog(shader, 512, NULL, buffer);
				std::cout << buffer << std::endl;

				return;
			}

			std::cout << "Done." << std::endl;

		}


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
