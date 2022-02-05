#pragma once

#include "../../Definitions/ShaderDataType/ShaderDataType.h"

namespace GameEngine::Renderer
{
	struct VertexBufferLayoutElement
	{
	public:
		ShaderDataType type;
		bool normalized;
	};


	class VertexBufferLayout
	{
	protected:
		std::vector<VertexBufferLayoutElement> elements;

	public:
		VertexBufferLayout(const std::initializer_list<VertexBufferLayoutElement>& Elements) : elements(Elements) {};
		virtual ~VertexBufferLayout() = default;

		virtual void Use() const = 0;

	};
}