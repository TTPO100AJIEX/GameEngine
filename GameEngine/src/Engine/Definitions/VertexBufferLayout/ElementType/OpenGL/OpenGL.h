#pragma once

#include "../ElementType.h"

namespace GameEngine::Renderer::VertexBufferLayout::VertexBufferLayoutElement
{
	std::tuple<int, int, size_t> ToOpenGL(const ElementType& type);
}