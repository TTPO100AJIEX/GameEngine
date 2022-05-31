#include <PrecompiledHeaders.h>

#include "RenderAPI.h"

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
		std::unique_ptr<Renderer> Create(const void* ProcAdressFunction)
		{
			return(std::make_unique<OpenGLRenderer>(ProcAdressFunction));
		}
	#endif

	namespace Camera
	{
		std::shared_ptr<Render::Camera> Create(float left, float right, float bottom, float top)
		{
			return(std::make_shared<Render::Camera>(left, right, bottom, top));
		}
		std::shared_ptr<Render::ControlledCamera> CreateControlled(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed)
		{
			return(std::make_shared<Render::ControlledCamera>(width, height, zoom, move_speed, rotate_speed, zoom_speed));
		}
	}

	#ifdef RENDER_USE_OPENGL

		namespace VertexBuffer
		{
			namespace Layout
			{
				std::shared_ptr<Render::VertexBufferLayout> Create(const std::initializer_list<Render::VertexBufferLayoutElement>& Elements)
				{
					return(std::make_shared<Render::OpenGLLayout>(Elements));
				}
			}
			std::shared_ptr<Render::VertexBuffer> Create(void* Data, size_t Amount, const std::shared_ptr<Render::VertexBufferLayout> Layout)
			{
				return(std::make_shared<Render::OpenGLVertexBuffer>(Data, Amount, std::dynamic_pointer_cast<Render::OpenGLLayout>(Layout)));
			}
		}
		namespace IndexBuffer
		{
			std::shared_ptr<Render::IndexBuffer> Create(uint32_t* Data, size_t Amount)
			{
				return(std::make_shared<Render::OpenGLIndexBuffer>(Data, Amount));
			}
		}
		namespace VertexArray
		{
			std::shared_ptr<Render::VertexArray> Create()
			{
				return(std::make_shared<Render::OpenGLVertexArray>());
			}
		}

		namespace Shader
		{
			std::shared_ptr<Render::Shader> CreateFromStrings(const std::unordered_map<Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<Render::OpenGLShader>(data, false));
			}
			std::shared_ptr<Render::Shader> CreateFromFiles(const std::unordered_map<Render::ShaderType, const std::string>& data)
			{
				return(std::make_shared<Render::OpenGLShader>(data, true));
			}
			namespace Library
			{
				std::shared_ptr<Render::ShaderLibrary> Create()
				{
					return(std::make_shared<Render::ShaderLibrary>());
				}
			}
		}

		namespace Texture
		{
			std::shared_ptr<Render::Texture2D> Create2D(const std::string& path)
			{
				return(std::make_shared<Render::OpenGLTexture2D>(path));
			}
			namespace Library
			{
				std::shared_ptr<Render::TextureLibrary> Create()
				{
					return(std::make_shared<Render::TextureLibrary>());
				}
			}
		}

	#endif
}