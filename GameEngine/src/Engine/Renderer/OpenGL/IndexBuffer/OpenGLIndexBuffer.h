#pragma once

#include "../../IndexBuffer.h"

namespace GameEngine::Renderer
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* Data, size_t Amount);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	};
}