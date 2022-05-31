#pragma once

#include "../../General/VertexArray.h"
namespace GameEngine::Render
{
	class OpenGLVertexBuffer;
	class OpenGLIndexBuffer;
}

namespace GameEngine::Render
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;
		void SetVertexBuffer(const std::shared_ptr<Render::OpenGLVertexBuffer> vertexBuffer);
		void SetIndexBuffer(const std::shared_ptr<Render::OpenGLIndexBuffer> indexBuffer);
		virtual void SetVertexBuffer(const std::shared_ptr<Render::VertexBuffer> vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<Render::IndexBuffer> indexBuffer) override;

	};
}