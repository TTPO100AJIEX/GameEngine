#pragma once


#include "General/Renderer.h"

#include "General/Camera/Camera.h"
#include "General/Camera/ControlledCamera/ControlledCamera.h"

#include "General/VertexBuffer.h"
#include "General/VertexBufferLayout.h"
#include "General/IndexBuffer.h"
#include "General/VertexArray.h"

#include "General/Shader.h"
#include "General/ShaderLibrary/ShaderLibrary.h"

#include "General/Textures.h"

namespace GameEngine::RenderAPI
{
	std::unique_ptr<::GameEngine::Renderer> Create();

	namespace Camera
	{
		std::shared_ptr<::GameEngine::Render::Camera> Create(float left, float right, float bottom, float top);
		std::shared_ptr<::GameEngine::Render::ControlledCamera> CreateControlled(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed);
	}
	
	namespace VertexBuffer
	{
		namespace Layout
		{
			std::shared_ptr<::GameEngine::Render::VertexBufferLayout> Create(const std::initializer_list<::GameEngine::Render::VertexBufferLayoutElement>& Elements);
		}
		std::shared_ptr<::GameEngine::Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<::GameEngine::Render::VertexBufferLayout> Layout);
	}
	namespace IndexBuffer
	{
		std::shared_ptr<::GameEngine::Render::IndexBuffer> Create(uint32_t* Data, size_t Amount);
	}
	namespace VertexArray
	{
		std::shared_ptr<::GameEngine::Render::VertexArray> Create();
	}

	namespace Shader
	{
		std::shared_ptr<::GameEngine::Render::Shader> CreateFromStrings(const std::unordered_map<::GameEngine::Render::ShaderType, const std::string>& data);
		std::shared_ptr<::GameEngine::Render::Shader> CreateFromFiles(const std::unordered_map<::GameEngine::Render::ShaderType, const std::string>& data);
		namespace Library
		{
			std::shared_ptr<::GameEngine::Render::ShaderLibrary> Create();
		}
	}

	namespace Texture
	{
		std::shared_ptr<::GameEngine::Render::Texture2D> Create2D(const std::string& path);
	}
}