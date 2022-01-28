#pragma once

namespace Engine::Renderer
{
	class IndexBuffer
	{
	protected:
		unsigned int id;

	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

	};
}