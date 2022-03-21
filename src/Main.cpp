#include <vld.h>
#include<iostream>

#include"SetUpGlfw.h"
#include"rectangle.h"


int main()
{
	SetUpGlfw glfw;
	if (!glfw.SetUp())
	{
		return -1;
	};
	GLFWwindow* window = glfw.GetWindow();

	Rectangle* rect = new Rectangle();

	//main loop waiting for the glfw window to close
	while (!glfwWindowShouldClose(window))
	{
		rect->Draw();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	delete rect;
	
	glfw.CleanUp();
	return 0;
}