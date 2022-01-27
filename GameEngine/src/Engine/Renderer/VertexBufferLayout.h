#pragma once

#include "../Definitions/VertexBufferLayout/ElementType/ElementType.h"

namespace Engine::Renderer::VertexBufferLayout
{
	struct Element
	{
	public:
		ElementType type;
		bool normalized;
	};


	class Layout
	{
	protected:
		std::vector<Element> elements;

	public:
		virtual ~Layout() = default;
		Layout(const std::initializer_list<Element>& Elements) : elements(Elements) {};

		virtual void Use() = 0;

	};
}