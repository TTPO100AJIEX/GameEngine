#pragma once

struct GLFWwindow;

namespace Engine::Renderer
{
	class Context
	{
	protected:
	public:
		virtual void Clear(GLFWwindow* window) = 0;

		virtual void SwapBuffers(GLFWwindow* window) = 0;
	};
}