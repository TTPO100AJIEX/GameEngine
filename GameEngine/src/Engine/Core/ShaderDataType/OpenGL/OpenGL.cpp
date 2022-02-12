#include <PrecompiledHeaders.h>

namespace GameEngine::Renderer
{
	std::tuple<int, int, size_t> ShaderDataTypeToOpenGL(const ShaderDataType& type)
	{
		switch (type)
		{
			case (ShaderDataType::None): { return { 0, 0, 0 }; break; }

			case (ShaderDataType::Bool): { return { 1, GL_BOOL, sizeof(bool)}; break; }

			case (ShaderDataType::Short): { return { 1, GL_SHORT, sizeof(short) }; break; }
			case (ShaderDataType::Short2): { return { 2, GL_SHORT, sizeof(short) }; break; }
			case (ShaderDataType::Short3): { return { 3, GL_SHORT, sizeof(short) }; break; }
			case (ShaderDataType::Short4): { return { 4, GL_SHORT, sizeof(short) }; break; }

			case (ShaderDataType::UShort): { return { 1, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ShaderDataType::UShort2): { return { 2, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ShaderDataType::UShort3): { return { 3, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }
			case (ShaderDataType::UShort4): { return { 4, GL_UNSIGNED_SHORT, sizeof(unsigned short) }; break; }

			case (ShaderDataType::Int): { return { 1, GL_INT, sizeof(int) }; break; }
			case (ShaderDataType::Int2): { return { 2, GL_INT, sizeof(int) }; break; }
			case (ShaderDataType::Int3): { return { 3, GL_INT, sizeof(int) }; break; }
			case (ShaderDataType::Int4): { return { 4, GL_INT, sizeof(int) }; break; }

			case (ShaderDataType::UInt): { return { 1, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ShaderDataType::UInt2): { return { 2, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ShaderDataType::UInt3): { return { 3, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }
			case (ShaderDataType::UInt4): { return { 4, GL_UNSIGNED_INT, sizeof(unsigned int) }; break; }

			case (ShaderDataType::Float): { return { 1, GL_FLOAT, sizeof(float) }; break; }
			case (ShaderDataType::Float2): { return { 2, GL_FLOAT, sizeof(float) }; break; }
			case (ShaderDataType::Float3): { return { 3, GL_FLOAT, sizeof(float) }; break; }
			case (ShaderDataType::Float4): { return { 4, GL_FLOAT, sizeof(float) }; break; }

			case (ShaderDataType::Double): { return { 1, GL_DOUBLE, sizeof(double) }; break; }
			case (ShaderDataType::Double2): { return { 2, GL_DOUBLE, sizeof(double) }; break; }
			case (ShaderDataType::Double3): { return { 3, GL_DOUBLE, sizeof(double) }; break; }
			case (ShaderDataType::Double4): { return { 4, GL_DOUBLE, sizeof(double) }; break; }

			default: { return { 0, 0, 0 }; }
		}
	}
}