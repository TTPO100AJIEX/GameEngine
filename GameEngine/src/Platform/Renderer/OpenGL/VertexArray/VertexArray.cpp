#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>
#include "../VertexBuffer/VertexBuffer.h"
#include "../IndexBuffer/IndexBuffer.h"

#include "VertexArray.h"

namespace GameEngine::Renderer
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &(this->id));
		this->Bind();
	}
	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &(this->id));
	}

	unsigned int VertexArray::GetID() const { return(this->id); }

	void VertexArray::Bind() const
	{
		glBindVertexArray(this->id);
	}
	void VertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> l_vertexBuffer)
	{
		this->vertexBuffer = l_vertexBuffer;
		this->Bind();
		this->vertexBuffer->Bind();
		this->vertexBuffer->GetLayout().Use();
	}
	void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> l_indexBuffer)
	{
		this->indexBuffer = l_indexBuffer;
		this->Bind();
		this->indexBuffer->Bind();
	}

	const std::shared_ptr<VertexBuffer> VertexArray::GetVertexBuffer() const { return(this->vertexBuffer); }
	const std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer() const { return(this->indexBuffer); }
}