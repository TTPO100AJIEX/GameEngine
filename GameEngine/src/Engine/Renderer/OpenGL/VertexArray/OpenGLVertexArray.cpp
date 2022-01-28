#include <PrecompiledHeaders.h>

#include "OpenGLVertexArray.h"

#include <GLAD/glad.h>

namespace Engine::Renderer
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

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(this->id);
	}
	void OpenGLVertexArray::UnBind()
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::SetVertexBuffer(std::shared_ptr<Renderer::OpenGLVertexBuffer> vertexBuffer)
	{
		this->Bind();
		vertexBuffer->Bind();
	}
	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<Renderer::OpenGLIndexBuffer> indexBuffer)
	{
		this->Bind();
		indexBuffer->Bind();
	}
	void OpenGLVertexArray::SetVertexBuffer(std::shared_ptr<Renderer::VertexBuffer> vertexBuffer)
	{
		this->SetVertexBuffer(std::dynamic_pointer_cast<Renderer::OpenGLVertexBuffer>(vertexBuffer));
	}
	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<Renderer::IndexBuffer> indexBuffer)
	{
		this->SetIndexBuffer(std::dynamic_pointer_cast<Renderer::OpenGLIndexBuffer>(indexBuffer));
	}
}