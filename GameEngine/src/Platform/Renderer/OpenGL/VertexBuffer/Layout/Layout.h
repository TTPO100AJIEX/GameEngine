#pragma once

namespace GameEngine::Renderer
{
	struct VertexBufferLayoutElement
	{
	public:
		ShaderDataType type;
		bool normalized;
	};


	class VertexBufferLayout
	{
	private:
		std::vector<VertexBufferLayoutElement> elements;

	public:
		VertexBufferLayout(const std::initializer_list<VertexBufferLayoutElement>& Elements);
		~VertexBufferLayout() = default;

		void Use() const;

		size_t GetStride() const;
	};
}