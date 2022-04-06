#pragma once

#include "../VertexBufferLayout/OpenGLLayout.h"
#include "../../General/VertexBuffer.h"

namespace GameEngine::Render
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(void *Data, size_t Amount, std::shared_ptr<OpenGLLayout> Layout);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	};
}