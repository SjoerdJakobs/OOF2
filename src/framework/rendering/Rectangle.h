#pragma once

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


class Rectangle
{
	// Vertices coordinates
	GLfloat m_Vertices[32];

	// Indices for vertices order
	GLuint m_Indices[6];
	Shader m_ShaderProgram;
	
	// Generate Vertex Array Object and binds it
	VAO m_VAO;
	// Generate Vertex Buffer Object and links it to vertices
	VBO m_VBO;
	// Generate Element Buffer Object and links it to indices
	EBO m_EBO;
	GLuint m_UniID;

	// Texture
	Texture m_PopCat;

public:
	Rectangle();
	~Rectangle();

	void Draw();

};

