#ifndef _SHADER_HPP_INCLUDED
#define _SHADER_HPP_INCLUDED

#include "glad/glad.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief      Class to store opengl shader objects.
 * Loads, compiles, and stores shader objects. 
 * Automatically deletes the shader object on deletion
 * 
 */
class Shader {

public:
	/**
	 * @brief   The different possible shader types supported by opengl
	 */
	enum Type : GLuint {
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	Shader() : shaderObject(0) {}

	virtual ~Shader() {
		deleteShaderObject();
	}

	void deleteShaderObject() {
		glDeleteShader(shaderObject);
		shaderObject = 0;
	}
  
  /**
   * @brief      checks if the stored shader object compiled successfully
   *
   * @return     returns true if compilation was successful, false otherwise
   */
	bool checkCompilationStatus() {

		GLint data;
		glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &data);
		return data == 1;
	}

	const GLuint getShaderObject() {
		return shaderObject;
	}

	bool loadAndCompileShader(const Type &type, const std::string &filename);

private:

	void printCompilerError(const int &bufferSize = 256);

	GLuint shaderObject;
};

#endif