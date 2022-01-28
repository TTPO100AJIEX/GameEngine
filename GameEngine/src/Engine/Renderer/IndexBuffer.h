#pragma once

namespace Engine::Renderer
{
	class IndexBuffer
	{
	protected:
		unsigned int id;

	public:
		virtual ~IndexBuffer() = default;

		inline unsigned int GetID() { return(id); }

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

	};
}