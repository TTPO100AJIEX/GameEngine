#include <PrecompiledHeaders.h>

#include "OpenGL.h"

#include <GLAD/glad.h>

namespace Engine::Renderer::VertexBufferLayout::VertexBufferLayoutElement
{
	std::tuple<int, int, size_t> ToOpenGL(ElementType type)
	{
		switch (type)
		{
			case (ElementType::None): { return { 0, 0, 0 }; break; }

			case (ElementType::Bool): { return { 1, GL_BOOL, sizeof(bool)}; break; }

			case (ElementType::Short): { return { 1, GL_SHORT, sizeof(short) }; break; }
			case (ElementType::Short2): { return { 2, GL_SHORT, sizeof(short) }; break; }
			case (ElementType::Short3): { return { 3, GL_SHORT, sizeof(short) }; break; }
			case (ElementType::Short4): { return { 4, GL_SHORT, sizeof(short) }; break; }

			case (ElementType::UShort): { return { 1, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ElementType::UShort2): { return { 2, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ElementType::UShort3): { return { 3, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ElementType::UShort4): { return { 4, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }

			case (ElementType::Int): { return { 1, GL_INT, sizeof(int) }; break; }
			case (ElementType::Int2): { return { 2, GL_INT, sizeof(int) }; break; }
			case (ElementType::Int3): { return { 3, GL_INT, sizeof(int) }; break; }
			case (ElementType::Int4): { return { 4, GL_INT, sizeof(int) }; break; }

			case (ElementType::UInt): { return { 1, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ElementType::UInt2): { return { 2, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ElementType::UInt3): { return { 3, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ElementType::UInt4): { return { 4, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }

			case (ElementType::Float): { return { 1, GL_FLOAT, sizeof(float) }; break; }
			case (ElementType::Float2): { return { 2, GL_FLOAT, sizeof(float) }; break; }
			case (ElementType::Float3): { return { 3, GL_FLOAT, sizeof(float) }; break; }
			case (ElementType::Float4): { return { 4, GL_FLOAT, sizeof(float) }; break; }

			case (ElementType::Double): { return { 1, GL_DOUBLE, sizeof(double) }; break; }
			case (ElementType::Double2): { return { 2, GL_DOUBLE, sizeof(double) }; break; }
			case (ElementType::Double3): { return { 3, GL_DOUBLE, sizeof(double) }; break; }
			case (ElementType::Double4): { return { 4, GL_DOUBLE, sizeof(double) }; break; }

			default: { return { 0, 0, 0 }; }
		}
	}
}