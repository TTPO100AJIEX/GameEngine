#include <PrecompiledHeaders.h>

#include "OpenGLVertexArray.h"

namespace GameEngine::Render
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &(this->id));
		this->Bind();
	}
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &(this->id));
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(this->id);
	}
	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}


	void OpenGLVertexArray::SetVertexBuffer(const std::shared_ptr<Render::OpenGLVertexBuffer>& l_vertexBuffer)
	{
		this->vertexBuffer = l_vertexBuffer;
		this->Bind();
		this->vertexBuffer->Bind();
	}
	void OpenGLVertexArray::SetVertexBuffer(const std::shared_ptr<Render::VertexBuffer>& l_vertexBuffer)
	{
		this->SetVertexBuffer(std::dynamic_pointer_cast<Render::OpenGLVertexBuffer>(l_vertexBuffer));
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<Render::OpenGLIndexBuffer>& l_indexBuffer)
	{
		this->indexBuffer = l_indexBuffer;
		this->Bind();
		this->indexBuffer->Bind();
	}
	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<Render::IndexBuffer>& l_indexBuffer)
	{
		this->SetIndexBuffer(std::dynamic_pointer_cast<Render::OpenGLIndexBuffer>(l_indexBuffer));
	}
}