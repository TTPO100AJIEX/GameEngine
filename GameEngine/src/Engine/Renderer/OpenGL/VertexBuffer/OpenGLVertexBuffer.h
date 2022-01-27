#pragma once

#include "../VertexBufferLayout/OpenGLLayout.h"
#include "../../VertexBuffer.h"

namespace Engine::Renderer
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* Data, size_t Amount, VertexBufferLayout::OpenGLLayout Layout);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;

	};
}