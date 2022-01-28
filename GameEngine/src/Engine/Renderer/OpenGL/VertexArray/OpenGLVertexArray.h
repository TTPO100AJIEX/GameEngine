#pragma once

#include "../../VertexArray.h"
#include "../VertexBuffer/OpenGLVertexBuffer.h"
#include "../IndexBuffer/OpenGLIndexBuffer.h"

namespace Engine::Renderer
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() override;
		virtual void UnBind() override;

		void SetVertexBuffer(std::shared_ptr<Renderer::OpenGLVertexBuffer> vertexBuffer);
		void SetIndexBuffer(std::shared_ptr<Renderer::OpenGLIndexBuffer> indexBuffer);
		virtual void SetVertexBuffer(std::shared_ptr<Renderer::VertexBuffer> vertexBuffer) override;
		virtual void SetIndexBuffer(std::shared_ptr<Renderer::IndexBuffer> indexBuffer) override;

	};
}