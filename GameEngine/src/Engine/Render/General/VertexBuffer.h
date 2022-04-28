#pragma once

namespace GameEngine::Render
{
	class VertexBuffer
	{
	protected:
		unsigned int id = 0;

	public:
		virtual ~VertexBuffer() = default;

		unsigned int GetID() const { return(this->id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

	};
}