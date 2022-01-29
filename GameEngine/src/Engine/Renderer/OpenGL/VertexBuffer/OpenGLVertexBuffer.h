#pragma once

#include "../VertexBufferLayout/OpenGLLayout.h"
#include "../../VertexBuffer.h"

namespace GameEngine::Renderer
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* Data, size_t Amount, std::shared_ptr<VertexBufferLayout::OpenGLLayout> Layout);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	};
}