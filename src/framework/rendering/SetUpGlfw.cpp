#include "SetUpGlfw.h"

SetUpGlfw::SetUpGlfw()
{
}

SetUpGlfw::~SetUpGlfw()
{
}

bool SetUpGlfw::SetUp()
{
	//initialize glfw
	glfwInit();
	//give major and minor version openglwhich is 3.3 in this case
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//we only want modern stuff so we take core profile, compatibility profile is for legacy stuff as well
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create window
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, "hello world", NULL, NULL);
	//check if window is created
	if (m_Window == NULL)
	{
		std::cout << "window not created" << std::endl;

		glfwTerminate();
		return false;
	}
	//saying we want to use the window by making the window the current context
	glfwMakeContextCurrent(m_Window);
	//load glad to configure opengl
	gladLoadGL();

	//specify viewport from bottom left
	glViewport(0, 0, m_WindowWidth, m_WindowHeight);
	return true;
}

bool SetUpGlfw::CleanUp()
{
	// Delete window before ending the program
	glfwDestroyWindow(m_Window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return true;
}

GLFWwindow* SetUpGlfw::GetWindow()
{
	return m_Window;
}
