#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include <iostream>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

class SetUpGlfw final
{
private:
	GLFWwindow* m_Window;
public:
	SetUpGlfw();
	~SetUpGlfw();
	bool SetUp();
	bool CleanUp();

	GLFWwindow* GetWindow();
};

