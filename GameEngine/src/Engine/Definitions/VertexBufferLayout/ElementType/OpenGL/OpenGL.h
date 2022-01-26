#pragma once

#include "../ElementType.h"

namespace Engine::Renderer::VertexBufferLayout
{
	std::tuple<int, int, size_t> ToOpenGL(ElementType type);
	//ElementType FromOpenGL(std::tuple<int, unsigned int>& type);
}