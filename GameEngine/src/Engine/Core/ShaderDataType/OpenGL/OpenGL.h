#pragma once

namespace GameEngine::Render
{
	std::tuple<int, int, size_t> ShaderDataTypeToOpenGL(const ShaderDataType& type);
}