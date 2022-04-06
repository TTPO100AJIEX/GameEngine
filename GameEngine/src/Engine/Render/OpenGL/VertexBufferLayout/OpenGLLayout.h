#pragma once

#include "../../General/VertexBufferLayout.h"

namespace GameEngine::Render
{
	class OpenGLLayout : public VertexBufferLayout
	{
	public:
		OpenGLLayout(const std::initializer_list<VertexBufferLayoutElement>& Elements);
		virtual ~OpenGLLayout() = default;

		virtual void Use() const override;

		size_t GetStride() const;
	};
}