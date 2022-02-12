#pragma once

#include "Camera/Camera.h"
#include "VertexArray.h"
#include "Shader.h"

namespace GameEngine
{
	class Renderer2D
	{
	protected:
		struct Scene_Data
		{
			glm::mat4 ViewProjectionMatrix;
		};
		Scene_Data SceneData;

	public:
		virtual ~Renderer2D() = default;

		virtual void SetClearColor(const glm::vec4& Color) = 0;
		virtual void Clear() = 0;


		virtual void BeginScene(const std::shared_ptr<Renderer::Camera>& camera) = 0;

		virtual void DrawIndexed(const std::shared_ptr<Renderer::VertexArray>& vertexArray, const std::shared_ptr<Renderer::Shader>& shader) = 0;

		virtual void EndScene() = 0;
	};
}