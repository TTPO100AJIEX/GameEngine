#include <PrecompiledHeaders.h>

#include "OpenGLIndexBuffer.h"

namespace GameEngine::Renderer
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* Data, size_t Amount) : IndexBuffer(Amount)
	{
		glCreateBuffers(1, &(this->id));
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Amount * sizeof(uint32_t), Data, GL_STATIC_DRAW);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &(this->id));
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	}
	void OpenGLIndexBuffer::UnBind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}