#pragma once

//#include "VertexArray.h"

namespace Engine
{
	class Renderer2D
	{
	public:
		virtual void BeginScene() = 0;

		//virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		virtual void EndScene() = 0;
	};
}