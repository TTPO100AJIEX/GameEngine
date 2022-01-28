#include <PrecompiledHeaders.h>

#include "OpenGLIndexBuffer.h"

#include <GLAD/glad.h>

namespace Engine::Renderer
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* Data, size_t Amount)
	{
		glCreateBuffers(1, &id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Amount * sizeof(uint32_t), Data, GL_STATIC_DRAW);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}
	void OpenGLIndexBuffer::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}