#pragma once

#include "OpenGL/OpenGLRenderer2D.h"
#include "OpenGL/VertexArray/OpenGLVertexArray.h"
#include "OpenGL/VertexBuffer/OpenGLVertexBuffer.h"
#include "OpenGL/IndexBuffer/OpenGLIndexBuffer.h"

namespace GameEngine::RendererAPI
{
	#ifdef RENDERER_USE_OPENGL
		inline std::shared_ptr<Renderer2D> CreateRenderer() 
		{
			return(std::make_shared<OpenGLRenderer2D>());
		}

		inline std::shared_ptr<Renderer::VertexArray> CreateVertexArray() 
		{
			return(std::make_shared<Renderer::OpenGLVertexArray>());
		}

		inline std::shared_ptr<Renderer::VertexBufferLayout> CreateVertexBufferLayout(const std::initializer_list<Renderer::VertexBufferLayoutElement>& Elements)
		{
			return(std::make_shared<Renderer::OpenGLLayout>(Elements));
		}

		inline std::shared_ptr<Renderer::VertexBuffer> CreateVertexBuffer(void* Data, size_t Amount, const std::shared_ptr<Renderer::OpenGLLayout>& Layout)
		{
			return(std::make_shared<Renderer::OpenGLVertexBuffer>(Data, Amount, Layout));
		}
		inline std::shared_ptr<Renderer::VertexBuffer> CreateVertexBuffer(void* Data, size_t Amount, const std::shared_ptr<Renderer::VertexBufferLayout>& Layout)
		{
			return(CreateVertexBuffer(Data, Amount, std::dynamic_pointer_cast<Renderer::OpenGLLayout>(Layout)));
		}

		inline std::shared_ptr<Renderer::IndexBuffer> CreateIndexBuffer(uint32_t* Data, size_t Amount)
		{
			return(std::make_shared<Renderer::OpenGLIndexBuffer>(Data, Amount));
		}

	#else
		#error "One of [RENDERER_USE_OPENGL] must be defined"
	#endif
}