#include "Rectangle.h"

//// Vertices coordinates for a rectangle with 30 degrees tilt
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS      /   TexCoord  //
//	-0.18f, -0.68f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
//	-0.68f, 0.18f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
//	 0.18f, 0.68f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
//	 0.68f, -0.18f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
//};

Rectangle::Rectangle():
	m_Vertices{ -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
		-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
		 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
		 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner},
	},
	m_Indices{	0, 2, 1, // Upper triangle
				0, 3, 2 }, // Lower triangle
	m_ShaderProgram( "default.vert", "default.frag" ),
	m_VBO( m_Vertices, sizeof(m_Vertices) ),
	m_EBO( m_Indices, sizeof(m_Indices) ),
	m_UniID(glGetUniformLocation(m_ShaderProgram.ID, "scale")),
	m_PopCat("ResourceFiles/Textures/pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE)
{

	m_VAO.Bind();
	m_VBO.Bind();
	m_EBO.Bind();

	// Links VBO attributes such as coordinates and colors to VAO
	m_VAO.LinkAttrib(m_VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	m_VAO.LinkAttrib(m_VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	m_VAO.LinkAttrib(m_VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	m_VAO.Unbind();
	m_VBO.Unbind();
	m_EBO.Unbind();

	m_PopCat.texUnit(m_ShaderProgram, "tex0", 0);
}

Rectangle::~Rectangle()
{
	// Delete all the objects we've created
	m_VAO.Delete();
	m_VBO.Delete();
	m_EBO.Delete();
	m_PopCat.Delete();
	m_ShaderProgram.Delete();
}

void Rectangle::Draw()
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Tell OpenGL which Shader Program we want to use
	m_ShaderProgram.Activate();
	glUniform1f(m_UniID, 1.0f);

	m_PopCat.Bind();
	// Bind the VAO so OpenGL knows to use it
	m_VAO.Bind();


	// Draw primitives, number of indices, datatype of indices, index of indices
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
