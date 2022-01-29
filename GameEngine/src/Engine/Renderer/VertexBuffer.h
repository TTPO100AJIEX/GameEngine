#pragma once

#include "VertexBufferLayout.h"

namespace GameEngine::Renderer
{
	class VertexBuffer
	{
	protected:
		unsigned int id;

	public:
		virtual ~VertexBuffer() = default;

		inline unsigned int GetID() { return(id); }

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

	};
}