#pragma once

namespace GameEngine::Renderer
{
	class IndexBuffer
	{
	protected:
		unsigned int id;

	public:
		virtual ~IndexBuffer() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

	};
}