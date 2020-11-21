#ifndef ShaderProgramLoader_H
#define ShaderProgramLoader_H

#include <string>
#include <fstream>

#include <GL/glew.h>

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

	public:

		void useProgram();

		void compileVertexShader( std::string vertexShaderFile );
		void compileFragmentShader( std::string fragmentShaderFile );

		void linkProgram();

		void detachShader();
		void deleteProgram();

	public:

		////////////////////////////////////////////////////////////////////////
		//
		//	Public function to get all attribute which defined in shader program
		//

		GLuint getAttributeLocation( std::string attributeName );

		GLuint getUniformAttributeLoaction( std::string attributName );

	protected:
		//
		//	Function to read shader file to string
		//
		std::string readShaderSourceFile( std::string shaderFile );

		//
		//	Function to compile shader from type
		//
		void compileShader( GLuint shader, std::string vertexShaderFile );

};

#endif