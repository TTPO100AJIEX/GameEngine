#include <PrecompiledHeaders.h>

#include "OpenGLLayout.h"

#include <GLAD/glad.h>

namespace GameEngine::Renderer::VertexBufferLayout
{
	OpenGLLayout::OpenGLLayout(const std::initializer_list<Element>& Elements) : Layout(Elements) {};

	void OpenGLLayout::Use() const
	{
		size_t stride = this->GetStride(), offset = 0;
		for (int i = 0; i < this->elements.size(); i++)
		{
			auto [amount, type, size] = VertexBufferLayoutElement::ToOpenGL(elements[i].type);
			glEnableVertexAttribArray(i);
			if (type == GL_BYTE || type == GL_UNSIGNED_BYTE || type == GL_SHORT || type == GL_UNSIGNED_SHORT || type == GL_INT || type == GL_UNSIGNED_INT)
			{
				glVertexAttribIPointer(i, amount, type, (int)(stride), (const void*)(offset));
			}
			else
			{
				glVertexAttribPointer(i, amount, type, elements[i].normalized ? GL_TRUE : GL_FALSE, (int)(stride), (const void*)(offset));
			}
			offset += amount * size;
		}
	}

	inline size_t OpenGLLayout::GetStride() const
	{
		size_t stride = 0;
		for (int i = 0; i < this->elements.size(); i++)
		{
			auto [amount, type, size] = VertexBufferLayoutElement::ToOpenGL(elements[i].type);
			stride += amount * size;
		}
		return(stride);
	}
}