#pragma once

#include "../ElementType.h"

namespace Engine::Renderer::VertexBufferLayout::VertexBufferLayoutElement
{
	std::tuple<int, int, size_t> ToOpenGL(ElementType type);
}