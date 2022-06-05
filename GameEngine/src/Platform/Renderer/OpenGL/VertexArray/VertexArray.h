#pragma once

namespace GameEngine::Renderer
{
	class VertexBuffer;
	class IndexBuffer;
}

namespace GameEngine::Renderer
{
	class VertexArray
	{
	private:
		unsigned int id = 0;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;

	public:
		VertexArray();
		~VertexArray();

		unsigned int GetID() const;

		void Bind() const;
		void UnBind() const;

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer> vertexBuffer);
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer> indexBuffer);

		const std::shared_ptr<IndexBuffer> GetIndexBuffer() const;
	};
}