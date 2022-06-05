#pragma once

#include "VertexBuffer/Layout/Layout.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"

#include "Shader/Shader.h"

#include "Texture/Texture.h"
#include "Texture/2D/2D.h"

namespace GameEngine::Renderer
{
	class Camera;
}

namespace GameEngine::Renderer
{
	void Init();

	void SetClearColor(const glm::vec4& Color);
	void SetViewport(int x, int y, int width, int height);

	void Clear();

	
	void BeginScene(const std::shared_ptr<Camera> camera);

	void DrawIndexed(const std::shared_ptr<VertexArray> vertexArray, const std::shared_ptr<Shader> shader, const glm::mat4& transform = glm::mat4(1.0f));

	void EndScene();
}