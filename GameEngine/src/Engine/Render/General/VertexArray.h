#pragma once

namespace GameEngine::Render
{
	class VertexBuffer;
	class IndexBuffer;
}

namespace GameEngine::Render
{
	class VertexArray
	{
	protected:
		unsigned int id = 0;
		std::shared_ptr<Render::VertexBuffer> vertexBuffer;
		std::shared_ptr<Render::IndexBuffer> indexBuffer;

	public:
		virtual ~VertexArray() = default;

		unsigned int GetID() const { return(this->id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetVertexBuffer(const std::shared_ptr<Render::VertexBuffer> l_vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<Render::IndexBuffer> l_indexBuffer) = 0;

		const std::shared_ptr<Render::VertexBuffer> GetVertexBuffer() const { return(this->vertexBuffer); }
		const std::shared_ptr<Render::IndexBuffer> GetIndexBuffer() const { return(this->indexBuffer); }
	};
}