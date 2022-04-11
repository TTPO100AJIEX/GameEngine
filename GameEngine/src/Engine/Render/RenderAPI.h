#pragma once

#include "General/Camera/Camera.h"
#include "General/ShaderLibrary/ShaderLibrary.h"

#ifdef RENDER_USE_OPENGL
	#include "OpenGL/OpenGLRenderer.h"
	#include "OpenGL/VertexArray/OpenGLVertexArray.h"
	#include "OpenGL/VertexBuffer/OpenGLVertexBuffer.h"
	#include "OpenGL/IndexBuffer/OpenGLIndexBuffer.h"
	#include "OpenGL/Shader/OpenGLShader.h"
	#include "OpenGL/Texture/Texture2D/OpenGLTexture2D.h"
#endif

namespace GameEngine::RenderAPI
{
	std::shared_ptr<::GameEngine::Renderer> Create();

	namespace Camera
	{
		std::shared_ptr<::GameEngine::Render::Camera> Create(float left, float right, float bottom, float top);
	}

	namespace VertexBuffer
	{
		namespace Layout
		{
			std::shared_ptr<::GameEngine::Render::VertexBufferLayout> Create(const std::initializer_list<::GameEngine::Render::VertexBufferLayoutElement>& Elements);
		}
		std::shared_ptr<::GameEngine::Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<::GameEngine::Render::VertexBufferLayout>& Layout);
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