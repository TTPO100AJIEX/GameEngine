#pragma once

#include "../Renderer2D.h"

namespace Engine
{
	class OpenGLRenderer2D : public Renderer2D
	{
	private:
		unsigned int m_VertexArray;
		unsigned int m_IndexBuffer;

	public:
		OpenGLRenderer2D();

		virtual void SetClearColor(const glm::vec4& Color) override;
		virtual void Clear() override;


		virtual void BeginScene() override;

		//virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		virtual void EndScene() override;
	};
}