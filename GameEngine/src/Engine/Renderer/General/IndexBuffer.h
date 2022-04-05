#pragma once

namespace GameEngine::Renderer
{
	class IndexBuffer
	{
	protected:
		unsigned int id = 0;
		size_t amount;

	public:
		IndexBuffer(size_t Amount) : amount(Amount) {}
		virtual ~IndexBuffer() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		const size_t& GetAmount() const { return(amount); }
	};
}