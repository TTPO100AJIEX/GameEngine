#pragma once

#include <GLM/glm.hpp>

#include "VertexArray.h"

namespace Engine
{
	class Renderer2D
	{
	public:
		virtual void SetClearColor(const glm::vec4& Color) = 0;
		virtual void Clear() = 0;


		virtual void BeginScene() = 0;

		virtual void DrawIndexed(const std::shared_ptr<Renderer::VertexArray> vertexArray) = 0;

		virtual void EndScene() = 0;
	};
}