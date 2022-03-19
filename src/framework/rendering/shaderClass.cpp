#include "shaderClass.h"

// Reads a text file and outputs a string with everything in the text file
std::string GetShaderFromFile(const char* filename)
{
	const char* path = "ResourceFiles/Shaders/";

	std::string fullPath(std::string(path) + filename);

	std::ifstream in(fullPath, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Read vertexFile and fragmentFile and store the strings
	std::string vertexCode = GetShaderFromFile(vertexFile);
	std::string fragmentCode = GetShaderFromFile(fragmentFile);


	// Convert the shader source strings into character arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// create vertex shader object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//gpu cant read uncompiled sorce codecode
	glCompileShader(vertexShader);
	CompileErrors(vertexShader,"VERTEX");


	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	CompileErrors(fragmentShader, "FRAGMENT");

	//create a program to hold the shaders
	ID = glCreateProgram();

	//attach shaders to program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	//wrap up program
	glLinkProgram(ID);

	CompileErrors(ID, "PROGRAM");

	//the shaders are already in the program and can be deleted here
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

// Checks if the different Shaders have compiled properly
void Shader::CompileErrors(unsigned int shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (strcmp(type,"PROGRAM")!=0)
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}