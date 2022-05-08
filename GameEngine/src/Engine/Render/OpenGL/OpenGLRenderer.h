#pragma once

#include "../General/Renderer.h"

namespace GameEngine::Render
{
	class Camera;
	class OpenGLVertexArray;
	class OpenGLShader;
}

namespace GameEngine
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer();

		virtual void SetClearColor(const glm::vec4& Color) const override;
		virtual void Clear() const override;
		virtual void SetViewport(int x, int y, int width, int height) const override;


		virtual void BeginScene(const std::shared_ptr<Render::Camera> camera) override;

		//void DrawIndexed(const std::shared_ptr<Render::OpenGLVertexArray> vertexArray, const std::shared_ptr<Render::OpenGLShader> shader, const glm::mat4& transform = glm::mat4(1.0f));
		virtual void DrawIndexed(const std::shared_ptr<Render::VertexArray> vertexArray, const std::shared_ptr<Render::Shader> shader, const glm::mat4& transform = glm::mat4(1.0f)) override;

		virtual void EndScene() override;

	};
}