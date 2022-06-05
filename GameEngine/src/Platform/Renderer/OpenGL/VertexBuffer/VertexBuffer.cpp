#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>
#include <Platform/ShaderDataType/OpenGL/OpenGL.h>

#include "VertexBuffer.h"

namespace GameEngine::Renderer
{
	VertexBuffer::VertexBuffer(void* Data, size_t Amount, const VertexBufferLayout& layout) : Layout(layout)
	{
		glCreateBuffers(1, &(this->id));
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, Layout.GetStride() * Amount, Data, GL_STATIC_DRAW);
	}
	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &(this->id));
	}

	unsigned int VertexBuffer::GetID() const
	{
		return(this->id);
	}
	const VertexBufferLayout& VertexBuffer::GetLayout() const
	{
		return(this->Layout);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}
	void VertexBuffer::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}