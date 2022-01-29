#pragma once

namespace GameEngine::Renderer::VertexBufferLayout::VertexBufferLayoutElement
{
	enum class ElementType : uint8_t
	{
		None,
		Bool,
		Short, Short2, Short3, Short4,
		UShort, UShort2, UShort3, UShort4,
		Int, Int2, Int3, Int4,
		UInt, UInt2, UInt3, UInt4,
		Float, Float2, Float3, Float4,
		Double, Double2, Double3, Double4
	};
}