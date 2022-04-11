#pragma once

namespace GameEngine::Render
{
	class IndexBuffer
	{
	protected:
		unsigned int id = 0;
		size_t amount;

	public:
		IndexBuffer(size_t Amount) : amount(Amount) {}
		virtual ~IndexBuffer() = default;

		unsigned int GetID() const { return(this->id); }
		const size_t& GetAmount() const { return(this->amount); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

	};
}