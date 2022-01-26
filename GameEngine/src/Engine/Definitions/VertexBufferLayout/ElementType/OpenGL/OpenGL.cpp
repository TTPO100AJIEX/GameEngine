#include <PrecompiledHeaders.h>

#include "OpenGL.h"

#include <GLAD/glad.h>

namespace Engine::Renderer::VertexBufferLayout
{
	/*static const std::unordered_map <ElementType, std::tuple<int, unsigned int>> To_OpenGL({
		{ ElementType::None, { 0, 0 } },
		{ ElementType::Bool, { 1, GL_BOOL } },
		{ ElementType::Int, { 1, GL_INT } }, { ElementType::Int2, { 2, GL_INT } }, { ElementType::Int3, { 3, GL_INT } }, { ElementType::Int4, { 4, GL_INT } },
		{ ElementType::Float, { 1, GL_FLOAT } }, { ElementType::Float2, { 2, GL_FLOAT } }, { ElementType::Float3, { 3, GL_FLOAT } }, { ElementType::Float4, { 4, GL_FLOAT } },
		{ ElementType::Double, { 1, GL_DOUBLE } }, { ElementType::Double2, { 2, GL_DOUBLE } }, { ElementType::Double3, { 3, GL_DOUBLE } }, { ElementType::Double4, { 4, GL_DOUBLE } },
	});
	static const std::unordered_map <std::tuple<int, unsigned int>, ElementType> From_OpenGL = traverse_unordered_map<std::tuple<int, unsigned int>, ElementType>(To_OpenGL);
	*/

	std::tuple<int, int, size_t> ToOpenGL(ElementType type)
	{
		switch (type)
		{
			case (ElementType::None): { return { 0, 0, 0 }; break; }
			case (ElementType::Float3): { return { 3, GL_FLOAT, sizeof(float)}; break; }
			default: { return { 0, 0, 0 }; }
		}
	}
	/*ElementType FromOpenGL(std::tuple<int, unsigned int>& type)
	{
		std::unordered_map<std::tuple<int, unsigned int>, ElementType>::const_iterator element = From_OpenGL.find(type);
		if (element == From_OpenGL.end()) [[unlikely]] return(ElementType::None);
		return(element->second);
	}*/
}