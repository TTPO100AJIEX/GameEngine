#pragma once

namespace Engine::Renderer::VertexBufferLayout
{
	enum class ElementType
	{
		None,
		Bool,
		Int, Int2, Int3, Int4,
		Float, Float2, Float3, Float4,
		Double, Double2, Double3, Double4
	};
}