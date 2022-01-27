#pragma once

#include "VertexBufferLayout.h"

namespace Engine::Renderer
{
	class VertexBuffer
	{
	protected:
		unsigned int id;

	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

	};
}