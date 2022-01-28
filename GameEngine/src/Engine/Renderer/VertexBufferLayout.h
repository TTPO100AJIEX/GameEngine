#pragma once

#include "../Definitions/VertexBufferLayout/ElementType/ElementType.h"

namespace Engine::Renderer::VertexBufferLayout
{
	struct Element
	{
	public:
		VertexBufferLayoutElement::ElementType type;
		bool normalized;
	};


	class Layout
	{
	protected:
		std::vector<Element> elements;

	public:
		Layout(const std::initializer_list<Element>& Elements) : elements(Elements) {};
		virtual ~Layout() = default;

		virtual void Use() = 0;

	};
}