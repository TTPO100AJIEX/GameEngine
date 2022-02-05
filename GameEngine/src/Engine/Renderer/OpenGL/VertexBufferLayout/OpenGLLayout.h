#pragma once

#include "../../General/VertexBufferLayout.h"

#include "../../../Definitions/ShaderDataType/OpenGL/OpenGL.h"

namespace GameEngine::Renderer
{
	class OpenGLLayout : public VertexBufferLayout
	{
	public:
		OpenGLLayout(const std::initializer_list<VertexBufferLayoutElement>& Elements);
		virtual ~OpenGLLayout() = default;

		virtual void Use() const override;

		inline size_t GetStride() const;
	};
}