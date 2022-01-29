#pragma once

#include "../../VertexBufferLayout.h"

#include "../../../Definitions/VertexBufferLayout/ElementType/OpenGL/OpenGL.h"

namespace GameEngine::Renderer::VertexBufferLayout
{
	class OpenGLLayout : public Layout
	{
	public:
		OpenGLLayout(const std::initializer_list<Element>& Elements);
		virtual ~OpenGLLayout() = default;

		virtual void Use() const override;

		inline size_t GetStride() const;
	};
}