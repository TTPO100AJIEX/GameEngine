#pragma once

#include "../General/Context.h"

namespace Engine::Renderer
{
	class OpenGLContext : public Context
	{
	public:
		OpenGLContext(GLFWwindow* window);


		virtual void Clear() override;

		virtual void SwapBuffers() override;
	};
}