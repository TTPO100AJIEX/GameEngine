#pragma once

#include "General/Camera/Camera.h"

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
	namespace Camera
	{
		inline std::shared_ptr<Render::Camera> Create(float left, float right, float bottom, float top)
		{
			return(std::make_shared<Render::Camera>(left, right, bottom, top));
		}
	}

	#ifdef RENDER_USE_OPENGL
		inline std::shared_ptr<Renderer> Create()
		{
			return(std::make_shared<OpenGLRenderer>());
		}

		namespace VertexArray
		{
			inline std::shared_ptr<Render::VertexArray> Create()
			{
				return(std::make_shared<Render::OpenGLVertexArray>());
			}
		}

		namespace VertexBuffer
		{
			namespace Layout
			{
				inline std::shared_ptr<Render::VertexBufferLayout> Create(const std::initializer_list<Render::VertexBufferLayoutElement>& Elements)
				{
					return(std::make_shared<Render::OpenGLLayout>(Elements));
				}
			}
			inline std::shared_ptr<Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<Render::OpenGLLayout>& Layout)
			{
				return(std::make_shared<Render::OpenGLVertexBuffer>(Data, Amount, Layout));
			}
			inline std::shared_ptr<Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<Render::VertexBufferLayout>& Layout)
			{
				return(Create(Data, Amount, std::static_pointer_cast<Render::OpenGLLayout>(Layout)));
			}
		}

		namespace IndexBuffer
		{
			inline std::shared_ptr<Render::IndexBuffer> Create(uint32_t* Data, size_t Amount)
			{
				return(std::make_shared<Render::OpenGLIndexBuffer>(Data, Amount));
			}
		}

		namespace Shader
		{
			inline std::shared_ptr<Render::Shader> CreateFromStrings(const std::unordered_map<GameEngine::Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<Render::OpenGLShader>(data, false));
			}
			inline std::shared_ptr<Render::Shader> CreateFromFiles(const std::unordered_map<GameEngine::Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<Render::OpenGLShader>(data, true));
			}
		}

		namespace Texture
		{
			inline std::shared_ptr<Render::Texture2D> Create2D(const std::string& path)
			{
				return(std::make_shared<Render::OpenGLTexture2D>(path));
			}
		}

	#else
		#error "One of [RENDER_USE_OPENGL] must be defined"
	#endif
}