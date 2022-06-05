#pragma once

namespace GameEngine::Renderer
{
	std::tuple<int, int, size_t> ShaderDataTypeToOpenGL(const ShaderDataType& type);
}