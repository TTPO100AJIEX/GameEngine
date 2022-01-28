#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Engine::Renderer
{
	class VertexArray
	{
	protected:
		unsigned int id;

	public:
		virtual ~VertexArray() = default;

		inline unsigned int GetID() { return(id); }

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual void SetVertexBuffer(std::shared_ptr<Renderer::VertexBuffer> vertexBuffer) = 0;
		virtual void SetIndexBuffer(std::shared_ptr<Renderer::IndexBuffer> indexBuffer) = 0;

	};
}