#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>

#include "IndexBuffer.h"

namespace GameEngine::Renderer
{
	IndexBuffer::IndexBuffer(uint32_t* Data, size_t Amount) : amount(Amount)
	{
		glCreateBuffers(1, &(this->id));
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Amount * sizeof(uint32_t), Data, GL_STATIC_DRAW);
	}
	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &(this->id));
	}

	unsigned int IndexBuffer::GetID() const { return(this->id); }
	const size_t IndexBuffer::GetAmount() const { return(this->amount); }

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	}
	void IndexBuffer::UnBind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}