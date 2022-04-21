#include <PrecompiledHeaders.h>

#include "RenderAPI.h"

namespace GameEngine::RenderAPI
{
	#ifdef RENDER_USE_OPENGL
		std::shared_ptr<::GameEngine::Renderer> Create()
		{
			return(std::make_shared<::GameEngine::OpenGLRenderer>());
		}
	#endif

	namespace Camera
	{
		std::shared_ptr<::GameEngine::Render::Camera> Create(float left, float right, float bottom, float top)
		{
			return(std::make_shared<::GameEngine::Render::Camera>(left, right, bottom, top));
		}
		std::shared_ptr<::GameEngine::Render::ControlledCamera> CreateControlled(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed)
		{
			return(std::make_shared<::GameEngine::Render::ControlledCamera>(width, height, zoom, move_speed, rotate_speed, zoom_speed));
		}
	}

	#ifdef RENDER_USE_OPENGL

		namespace VertexBuffer
		{
			namespace Layout
			{
				std::shared_ptr<::GameEngine::Render::VertexBufferLayout> Create(const std::initializer_list<::GameEngine::Render::VertexBufferLayoutElement>& Elements)
				{
					return(std::make_shared<::GameEngine::Render::OpenGLLayout>(Elements));
				}
			}
			std::shared_ptr<::GameEngine::Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<::GameEngine::Render::VertexBufferLayout> Layout)
			{
				return(std::make_shared<::GameEngine::Render::OpenGLVertexBuffer>(Data, Amount, Layout));
			}
		}
		namespace IndexBuffer
		{
			std::shared_ptr<::GameEngine::Render::IndexBuffer> Create(uint32_t* Data, size_t Amount)
			{
				return(std::make_shared<::GameEngine::Render::OpenGLIndexBuffer>(Data, Amount));
			}
		}
		namespace VertexArray
		{
			std::shared_ptr<::GameEngine::Render::VertexArray> Create()
			{
				return(std::make_shared<::GameEngine::Render::OpenGLVertexArray>());
			}
		}

		namespace Shader
		{
			std::shared_ptr<::GameEngine::Render::Shader> CreateFromStrings(const std::unordered_map<::GameEngine::Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<Render::OpenGLShader>(data, false));
			}
			std::shared_ptr<::GameEngine::Render::Shader> CreateFromFiles(const std::unordered_map<::GameEngine::Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<::GameEngine::Render::OpenGLShader>(data, true));
			}
			namespace Library
			{
				std::shared_ptr<::GameEngine::Render::ShaderLibrary> Create()
				{
					return(std::make_shared<::GameEngine::Render::ShaderLibrary>());
				}
			}
		}

		namespace Texture
		{
			std::shared_ptr<::GameEngine::Render::Texture2D> Create2D(const std::string& path)
			{
				return(std::make_shared<::GameEngine::Render::OpenGLTexture2D>(path));
			}
		}

	#else
		#error "One of [RENDER_USE_OPENGL] must be defined"
	#endif
}