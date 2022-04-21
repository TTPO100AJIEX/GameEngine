#pragma once

#include "VertexArray/OpenGLVertexArray.h"
#include "Shader/OpenGLShader.h"
#include "../General/Renderer.h"

namespace GameEngine
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer();

		virtual void SetClearColor(const glm::vec4& Color) override;
		virtual void Clear() override;


		virtual void BeginScene(const std::shared_ptr<Render::Camera> camera) override;

		void DrawIndexed(const std::shared_ptr<Render::OpenGLVertexArray> vertexArray, const std::shared_ptr<Render::OpenGLShader> shader, const glm::mat4& transform = glm::mat4(1.0f));
		virtual void DrawIndexed(const std::shared_ptr<Render::VertexArray> vertexArray, const std::shared_ptr<Render::Shader> shader, const glm::mat4& transform = glm::mat4(1.0f)) override;

		virtual void EndScene() override;

	};
}