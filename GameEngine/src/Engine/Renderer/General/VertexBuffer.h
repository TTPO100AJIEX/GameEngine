#pragma once

#include "VertexBufferLayout.h"

namespace GameEngine::Renderer
{
	class VertexBuffer
	{
	protected:
		unsigned int id = 0;

	public:
		virtual ~VertexBuffer() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

	};
}