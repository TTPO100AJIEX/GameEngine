#pragma once

#include "VertexArray/OpenGLVertexArray.h"
#include "Shader/OpenGLShader.h"
#include "../General/Renderer2D.h"

namespace GameEngine
{
	class OpenGLRenderer2D : public Renderer2D
	{
	public:
		OpenGLRenderer2D();
		virtual ~OpenGLRenderer2D();

		virtual void SetClearColor(const glm::vec4& Color) override;
		virtual void Clear() override;


		virtual void BeginScene(const std::shared_ptr<Renderer::Camera>& camera) override;

		void DrawIndexed(const std::shared_ptr<Renderer::OpenGLVertexArray>& vertexArray, const std::shared_ptr<Renderer::OpenGLShader>& shader, const glm::mat4& transform = glm::mat4(1.0f));
		virtual void DrawIndexed(const std::shared_ptr<Renderer::VertexArray>& vertexArray, const std::shared_ptr<Renderer::Shader>& shader, const glm::mat4& transform = glm::mat4(1.0f)) override;

		virtual void EndScene() override;

	};
}