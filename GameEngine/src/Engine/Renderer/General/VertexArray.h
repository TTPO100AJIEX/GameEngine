#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace GameEngine::Renderer
{
	class VertexArray
	{
	protected:
		unsigned int id;

	public:
		virtual ~VertexArray() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetVertexBuffer(const std::shared_ptr<Renderer::VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<Renderer::IndexBuffer>& indexBuffer) = 0;

	};
}