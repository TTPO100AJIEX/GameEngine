#pragma once

namespace GameEngine::Renderer
{
	unsigned int ShaderTypeToOpenGL(const ShaderType& type);
	ShaderType OpenGLToShaderType(const unsigned int& type);
}