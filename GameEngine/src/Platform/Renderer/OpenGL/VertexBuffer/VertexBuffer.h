#pragma once

#include "Layout/Layout.h"

namespace GameEngine::Renderer
{
	class VertexBuffer
	{
	private:
		unsigned int id = 0;
		const VertexBufferLayout Layout;

	public:
		VertexBuffer(void* Data, size_t Amount, const VertexBufferLayout& Layout);
		~VertexBuffer();

		unsigned int GetID() const;
		const VertexBufferLayout& GetLayout() const;

		void Bind() const;
		void UnBind() const;
	};
}