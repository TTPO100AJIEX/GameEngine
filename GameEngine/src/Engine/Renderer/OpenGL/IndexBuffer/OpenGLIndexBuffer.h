#pragma once

#include "../../IndexBuffer.h"

namespace Engine::Renderer
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* Data, size_t Amount);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;

	};
}