#include <PrecompiledHeaders.h>

#include "OpenGLVertexBuffer.h"

#include <GLAD/glad.h>

namespace Engine::Renderer
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(void* Data, size_t Amount, VertexBufferLayout::OpenGLLayout& Layout)
	{
		glCreateBuffers(1, &(this->id));
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, Layout.GetStride() * Amount, Data, GL_STATIC_DRAW);
		Layout.Use();
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &(this->id));
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}
	void OpenGLVertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}