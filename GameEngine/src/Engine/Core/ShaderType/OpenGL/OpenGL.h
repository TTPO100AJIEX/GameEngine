#pragma once

namespace GameEngine::Render
{
	unsigned int ShaderTypeToOpenGL(const ShaderType& type);
	ShaderType OpenGLToShaderType(const unsigned int& type);
}