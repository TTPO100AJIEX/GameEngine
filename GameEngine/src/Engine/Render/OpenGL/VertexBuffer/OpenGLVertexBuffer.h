#pragma once

#include "../../General/VertexBuffer.h"
namespace GameEngine::Render
{
	class OpenGLLayout;
}

namespace GameEngine::Render
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(void *Data, size_t Amount, std::shared_ptr<OpenGLLayout> Layout);
		//OpenGLVertexBuffer(void* Data, size_t Amount, std::shared_ptr<VertexBufferLayout> Layout) : OpenGLVertexBuffer(Data, Amount, std::static_pointer_cast<OpenGLLayout>(Layout)) { }
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	};
}