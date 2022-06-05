#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>

#include "OpenGL.h"

namespace GameEngine::Renderer
{
	unsigned int ShaderTypeToOpenGL(const ShaderType& type)
	{
		switch (type)
		{
			case (ShaderType::Vertex): { return(GL_VERTEX_SHADER); break; }
			case (ShaderType::Fragment): { return(GL_FRAGMENT_SHADER); break; }
			default: { ENGINE_WARN("ShaderTypeToOpenGL: unknown shader type {0}", type); }
		}
		return(0);
	}

	ShaderType OpenGLToShaderType(const unsigned int& type)
	{
		switch (type)
		{
			case (GL_VERTEX_SHADER): { return(ShaderType::Vertex); break; }
			case (GL_FRAGMENT_SHADER): { return(ShaderType::Fragment); break; }
			default: { ENGINE_WARN("OpenGLToShaderType: unknown shader type {0}", type); }
		}
		return(ShaderType::Unknown);
	}
}