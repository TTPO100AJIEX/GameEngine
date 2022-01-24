#pragma once

#include "../Context.h"

namespace Engine::Renderer
{
	class OpenGLContext : public Context
	{
	private:
		unsigned int m_VertexArray;
		unsigned int m_VertexBuffer;
		unsigned int m_IndexBuffer;

	public:
		OpenGLContext(GLFWwindow* window);


		virtual void Clear(GLFWwindow* window) override;

		virtual void SwapBuffers(GLFWwindow* window) override;
	};
}