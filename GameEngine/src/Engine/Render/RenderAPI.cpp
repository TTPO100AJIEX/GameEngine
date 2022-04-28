#include <PrecompiledHeaders.h>

#include "RenderAPI.h"


#include "General/Camera/Camera.h"
#include "General/Camera/ControlledCamera/ControlledCamera.h"

#include "General/ShaderLibrary/ShaderLibrary.h"

#ifdef RENDER_USE_OPENGL
	#include "OpenGL/OpenGLRenderer.h"

	#include "OpenGL/VertexArray/OpenGLVertexArray.h"
	#include "OpenGL/VertexBuffer/OpenGLVertexBuffer.h"
	#include "OpenGL/VertexBufferLayout/OpenGLLayout.h"
	#include "OpenGL/IndexBuffer/OpenGLIndexBuffer.h"

	#include "OpenGL/Shader/OpenGLShader.h"

	#include "OpenGL/Texture/Texture2D/OpenGLTexture2D.h"
#else
	#error "One of [RENDER_USE_OPENGL] must be defined"
#endif

namespace GameEngine::RenderAPI
{
	#ifdef RENDER_USE_OPENGL
		std::unique_ptr<::GameEngine::Renderer> Create()
		{
			return(std::make_unique<::GameEngine::OpenGLRenderer>());
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
				return(std::make_shared<::GameEngine::Render::OpenGLVertexBuffer>(Data, Amount, std::dynamic_pointer_cast<::GameEngine::Render::OpenGLLayout>(Layout)));
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

	#endif
}