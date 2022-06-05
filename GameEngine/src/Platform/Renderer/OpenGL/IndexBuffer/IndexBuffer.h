#pragma once

namespace GameEngine::Renderer
{
	class IndexBuffer
	{
	private:
		unsigned int id = 0;
		size_t amount;

	public:
		IndexBuffer(uint32_t* Data, size_t Amount);
		~IndexBuffer();

		unsigned int GetID() const;
		const size_t GetAmount() const;

		void Bind() const;
		void UnBind() const;
	};
}