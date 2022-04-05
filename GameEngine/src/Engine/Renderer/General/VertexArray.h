#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace GameEngine::Renderer
{
	class VertexArray
	{
	protected:
		unsigned int id;
		std::shared_ptr<Renderer::VertexBuffer> vertexBuffer;
		std::shared_ptr<Renderer::IndexBuffer> indexBuffer;

	public:
		virtual ~VertexArray() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetVertexBuffer(const std::shared_ptr<Renderer::VertexBuffer>& l_vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<Renderer::IndexBuffer>& l_indexBuffer) = 0;

	};
}