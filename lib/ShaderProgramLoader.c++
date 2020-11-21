#include <iostream>

#include "ShaderProgramLoader.h"


ShaderProgramLoader::ShaderProgramLoader()
{
	
}

ShaderProgramLoader::~ShaderProgramLoader()
{
	std::cout << "Delete program" << std::endl;
	this->deleteProgram();
}

void ShaderProgramLoader::useProgram()
{
	glUseProgram( this->shaderProgram );
}

void ShaderProgramLoader::compileVertexShader( std::string vertexShaderFile )
{
	this->vertexShader = glCreateShader( GL_VERTEX_SHADER );
	this->compileShader( this->vertexShader, vertexShaderFile );
}

void ShaderProgramLoader::compileFragmentShader( std::string fragmentShaderFile )
{
	this->fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
	this->compileShader( this->fragmentShader, fragmentShaderFile );
}

void ShaderProgramLoader::linkProgram()
{
	this->shaderProgram = glCreateProgram();
	glAttachShader( this->shaderProgram, this->vertexShader );
	glAttachShader( this->shaderProgram, this->fragmentShader );
	glLinkProgram( this->shaderProgram );

}

void ShaderProgramLoader::detachShader()
{
	glDetachShader( this->shaderProgram, this->fragmentShader );
	glDetachShader( this->shaderProgram, this->vertexShader );
	glDeleteShader( this->fragmentShader );
	glDeleteShader( this->vertexShader );
}

void ShaderProgramLoader::deleteProgram()
{
	glDeleteProgram( this->shaderProgram );
}

GLuint ShaderProgramLoader::getAttributeLocation( std::string attributeName )
{
	return glGetAttribLocation( this->shaderProgram, attributeName.c_str() );
}

GLuint ShaderProgramLoader::getUniformAttributeLoaction( std::string attributeName )
{
	return glGetUniformLocation( this->shaderProgram, attributeName.c_str() );
}

std::string ShaderProgramLoader::readShaderSourceFile( std::string shaderFile )
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
void ShaderProgramLoader::compileShader( GLuint shader, std::string vertexShaderFile )
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