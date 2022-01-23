#pragma once

#include <GLFW/glfw3.h>

namespace Engine::Renderer
{
	class Context
	{
	protected:
		GLFWwindow* Window;

	public:
		virtual void Clear() = 0;

		virtual void SwapBuffers() = 0;
	};
}