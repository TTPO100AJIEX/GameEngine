#include <PrecompiledHeaders.h>

#include "OpenGLContext.h"

#include <GLAD/glad.h>

namespace Engine::Renderer
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
	{
		Window = window;
		glfwMakeContextCurrent(Window);
		int status = gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
		ENGINE_INFO("GLAD status: {0}", status);
	}


	void OpenGLContext::Clear()
	{
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(Window);
		glfwPollEvents();
	}
}