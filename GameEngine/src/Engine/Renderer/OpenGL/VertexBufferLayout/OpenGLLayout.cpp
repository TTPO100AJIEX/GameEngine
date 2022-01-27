#include <PrecompiledHeaders.h>

#include "OpenGLLayout.h"

#include <GLAD/glad.h>

namespace Engine::Renderer::VertexBufferLayout
{
	OpenGLLayout::OpenGLLayout(const std::initializer_list<Element>& Elements) : Layout(Elements) {};

	void OpenGLLayout::Use()
	{
		size_t stride = 0, offset = 0;
		for (int i = 0; i < elements.size(); i++)
		{
			auto [amount, type, size] = ToOpenGL(elements[i].type);
			stride += amount * size;
		}
		for (int i = 0; i < elements.size(); i++)
		{
			auto [amount, type, size] = ToOpenGL(elements[i].type);
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, amount, type, elements[i].normalized ? GL_TRUE : GL_FALSE, stride, (const void*)(offset));
			offset += amount * size;
		}
	}
}