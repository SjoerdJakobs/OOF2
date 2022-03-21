#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include <iostream>
//
//constexpr int m_WindowWidth = 800;
//constexpr int m_WindowHeight = 800;

class SetUpGlfw final
{
private:
	GLFWwindow* m_Window;
public:
	SetUpGlfw();
	~SetUpGlfw();
	bool SetUp();
	bool CleanUp();
	const int m_WindowWidth = 800;
	const int m_WindowHeight = 800;

	GLFWwindow* GetWindow();
};

