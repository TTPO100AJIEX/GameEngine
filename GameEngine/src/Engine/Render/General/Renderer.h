#pragma once

namespace GameEngine::Render
{
	class Camera;
	class VertexArray;
	class Shader;
}


namespace GameEngine
{
	class Renderer
	{
	protected:
		struct Scene_Data
		{
			glm::mat4 ViewProjectionMatrix;
		};
		Scene_Data SceneData;

	public:
		virtual ~Renderer() = default;

		virtual void SetClearColor(const glm::vec4& Color) = 0;
		virtual void Clear() = 0;


		virtual void BeginScene(const std::shared_ptr<Render::Camera> camera) = 0;

		virtual void DrawIndexed(const std::shared_ptr<Render::VertexArray> vertexArray, const std::shared_ptr<Render::Shader> shader, const glm::mat4& transform = glm::mat4(1.0f)) = 0;

		virtual void EndScene() = 0;
	};
}