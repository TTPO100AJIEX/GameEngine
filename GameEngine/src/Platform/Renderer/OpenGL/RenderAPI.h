#pragma once

#include "Renderer.h"

namespace GameEngine::RenderAPI
{
	/*std::unique_ptr<Renderer> Create(const void* ProcAdressFunction);

	namespace Camera
	{
		std::shared_ptr<Renderer::Camera> Create(float left, float right, float bottom, float top);
		std::shared_ptr<Renderer::ControlledCamera> CreateControlled(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed);
	}

	namespace VertexBuffer
	{
		namespace Layout
		{
			std::shared_ptr<Render::VertexBufferLayout> Create(const std::initializer_list<Render::VertexBufferLayoutElement>& Elements);
		}
		std::shared_ptr<Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<Render::VertexBufferLayout> Layout);
	}
	namespace IndexBuffer
	{
		std::shared_ptr<Render::IndexBuffer> Create(uint32_t* Data, size_t Amount);
	}
	namespace VertexArray
	{
		std::shared_ptr<Render::VertexArray> Create();
	}

	namespace Shader
	{
		std::shared_ptr<Render::Shader> CreateFromStrings(const std::unordered_map<Render::ShaderType, const std::string>& data);
		std::shared_ptr<Render::Shader> CreateFromFiles(const std::unordered_map<Render::ShaderType, const std::string>& data);
		namespace Library
		{
			std::shared_ptr<Render::ShaderLibrary> Create();
		}
	}

	namespace Texture
	{
		std::shared_ptr<Render::Texture2D> Create2D(const std::string& path);
		namespace Library
		{
			std::shared_ptr<Render::TextureLibrary> Create();
		}
	}*/
}