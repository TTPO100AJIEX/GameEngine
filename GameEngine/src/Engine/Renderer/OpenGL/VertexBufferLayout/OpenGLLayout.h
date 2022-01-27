#pragma once

#include "../../VertexBufferLayout.h"

#include "../../../Definitions/VertexBufferLayout/ElementType/OpenGL/OpenGL.h"

namespace Engine::Renderer::VertexBufferLayout
{
	class OpenGLLayout : public Layout
	{
	public:
		OpenGLLayout(const std::initializer_list<Element>& Elements);

		virtual void Use() override;

		inline size_t GetStride();
	};
}