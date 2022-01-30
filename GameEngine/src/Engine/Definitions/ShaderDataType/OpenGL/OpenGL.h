#pragma once

#include "../ShaderDataType.h"

namespace GameEngine::Renderer
{
	std::tuple<int, int, size_t> ShaderDataTypeToOpenGL(const ShaderDataType& type);
}