#pragma once

#include "../../VertexArray.h"
#include "../VertexBuffer/OpenGLVertexBuffer.h"
#include "../IndexBuffer/OpenGLIndexBuffer.h"

namespace GameEngine::Renderer
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;
		void SetVertexBuffer(const std::shared_ptr<Renderer::OpenGLVertexBuffer>& vertexBuffer);
		void SetIndexBuffer(const std::shared_ptr<Renderer::OpenGLIndexBuffer>& indexBuffer);
		virtual void SetVertexBuffer(const std::shared_ptr<Renderer::VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<Renderer::IndexBuffer>& indexBuffer) override;

	};
}