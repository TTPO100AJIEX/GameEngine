#pragma once

#include "../ElementType.h"

namespace Engine::Renderer::VertexBufferLayout
{
	std::tuple<int, int, size_t> ToOpenGL(ElementType type);
}