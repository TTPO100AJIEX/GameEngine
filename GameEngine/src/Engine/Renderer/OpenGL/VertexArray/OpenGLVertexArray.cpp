#include <PrecompiledHeaders.h>

#include "OpenGLVertexArray.h"

#include <GLAD/glad.h>

namespace Engine::Renderer
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &id);
		Bind();
	}
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(id);
	}
	void OpenGLVertexArray::UnBind()
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::SetVertexBuffer(std::shared_ptr<Renderer::OpenGLVertexBuffer> vertexBuffer)
	{
		Bind();
		vertexBuffer->Bind();
	}
	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<Renderer::OpenGLIndexBuffer> indexBuffer)
	{
		Bind();
		indexBuffer->Bind();
	}
	void OpenGLVertexArray::SetVertexBuffer(std::shared_ptr<Renderer::VertexBuffer> vertexBuffer)
	{
		SetVertexBuffer(std::dynamic_pointer_cast<Renderer::OpenGLVertexBuffer>(vertexBuffer));
	}
	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<Renderer::IndexBuffer> indexBuffer)
	{
		SetIndexBuffer(std::dynamic_pointer_cast<Renderer::OpenGLIndexBuffer>(indexBuffer));
	}
}