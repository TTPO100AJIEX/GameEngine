#pragma once

#include "VertexArray/OpenGLVertexArray.h"
#include "../Renderer2D.h"

namespace GameEngine
{
	class OpenGLRenderer2D : public Renderer2D
	{
	public:
		OpenGLRenderer2D();

		virtual void SetClearColor(const glm::vec4& Color) override;
		virtual void Clear() override;


		virtual void BeginScene() override;

		void DrawIndexed(const std::shared_ptr<Renderer::OpenGLVertexArray> vertexArray);
		virtual void DrawIndexed(const std::shared_ptr<Renderer::VertexArray> vertexArray) override;

		virtual void EndScene() override;
	};
}