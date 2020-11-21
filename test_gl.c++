#include <iostream>
#include <algorithm>
#include <vector>

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "include/ShaderProgramLoader.h"

#define FRAGMENT std::string( "./shader_program/Triangle.fragmentshader" )
#define VERTEX std::string( "./shader_program/Triangle.vertexshader" )

//	Default checker board for testing
float checkerBoard[] = {
		0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f, 	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f, 	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
	};


void generateSquarecheckerboard( int dim, int numBlock, float* checkerBoard_ret )
{
	//  calculate number to loop
	int numLoop = dim*dim*3;

	//  Initial color value
	float colorValue = 1.0f;

	//	Frequency to check value
	int freq = dim / numBlock;

	//	Step to change
	int stepToChange = freq * dim;

	//  Loop to set value
	for( int i = 0; i < numLoop; i++ )
	{
		//	Loop to put color 
		for( int f = 0; f < freq; freq++ )
		{
			//	Loop all chanal to single pixel
			for( int c = 0; c < 3; c++ )
			{
				checkerBoard_ret[ i ] = colorValue;
				std::cout << colorValue << "	";
			}	
		}

		if( i == stepToChange - 1 )
			continue;
			
		colorValue = 1.0f - colorValue;
	}

}


int main(int argc, char const *argv[])
{

	//	Init window
	glfwInit();

	//	Create window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", nullptr, nullptr); // Windowed

	//	Make context !!!!!!!!!
	glfwMakeContextCurrent(window);


	//	Initi gl extension for make genBuffer compatible
	glewExperimental = GL_TRUE;
	glewInit();

	//	Clear color
	glClearColor(0.35f, 0.35f, 0.35f, 0.0f);

	//
	//	vao and vbo stuff
	//

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray( vao );

	float vertices[] = {
    -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
     0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,// Top-right
     0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,// Bottom-right
    -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,// Bottom-left
	};

	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint elements[] = { 0, 1, 2,
							2, 3, 0 };
	
	GLuint ebo;
	glGenBuffers( 1, &ebo );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebo );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, 
					sizeof( elements ), elements, GL_STATIC_DRAW );

	//	Shader stuff
	//	Initial shader program object
	std::shared_ptr<ShaderProgramLoader> shaderProgramLoader = std::make_shared<ShaderProgramLoader>();

	shaderProgramLoader->compileVertexShader( VERTEX );
	shaderProgramLoader->compileFragmentShader( FRAGMENT );
	shaderProgramLoader->linkProgram();
	shaderProgramLoader->useProgram();

	//	Get vertex attribute location
	GLuint vertexAttributeLocation = shaderProgramLoader->getAttributeLocation( "vertex" );

	//	Get uniform colir
	GLuint colorAttributeLocation = shaderProgramLoader->getAttributeLocation( "inColor" );

	//	Get texture coordinate variable
	GLuint textureAttributeLocation = shaderProgramLoader->getAttributeLocation( "texcoord" );

	//	Get uniform variable
	GLuint textureAttributeUniformLocation = shaderProgramLoader->getUniformAttributeLoaction( "texBase" );

	glEnableVertexAttribArray(vertexAttributeLocation);
	glVertexAttribPointer( vertexAttributeLocation, 
							2, 
							GL_FLOAT, 
							false, 
							7*sizeof( float ), 0 );

	glEnableVertexAttribArray(colorAttributeLocation);
	glVertexAttribPointer( colorAttributeLocation, 
							3, 
							GL_FLOAT, 
							false, 
							7*sizeof( float ),
							(void *)( 2*sizeof( float ) ) );

	glEnableVertexAttribArray(textureAttributeLocation);
	glVertexAttribPointer( textureAttributeLocation,
							2,
							GL_FLOAT,
							false,
							7*sizeof( float ),
							( void *)( 5*sizeof( float ) ) );

	GLuint tex;
	glGenTextures(1, &tex);

	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, tex );

	float imageData[256][256][3]; // Texture image data
	float value;
	for (int row = 0; row < 256; row++) {
		for (int col = 0; col < 256; col++) {
			// Each cell is 8x8, value is 0 or 255 (black or white)
			value = (((row & 32) == 0) ^ ((col & 32) == 0)) * 1.0;
			imageData[row][col][0] = value;
			imageData[row][col][1] = value;
			imageData[row][col][2] = value;
		}
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_FLOAT, imageData);
	glUniform1i( textureAttributeUniformLocation, 0 );
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	while(!glfwWindowShouldClose(window))
	{

		glClear( GL_COLOR_BUFFER_BIT );

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    		glfwSetWindowShouldClose(window, GL_TRUE);

	}

	glDeleteTextures( 1, &tex );

    glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
