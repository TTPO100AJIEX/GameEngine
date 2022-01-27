#include <PrecompiledHeaders.h>

#include "OpenGLRenderer2D.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBufferLayout/OpenGLLayout.h"
#include "VertexBuffer/OpenGLVertexBuffer.h"

namespace Engine
{
	void OpenGLRenderer2D::SetClearColor(const glm::vec4& Color)
	{
		glClearColor(Color.r, Color.g, Color.b, Color.a);
	}
	void OpenGLRenderer2D::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	OpenGLRenderer2D::OpenGLRenderer2D()
	{
		if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)))
		{
			ENGINE_CRITICAL("Failed to initialize OpenGL context (GLAD)");
			return;
		}
		ENGINE_WARN("GLAD initialized");
		ENGINE_INFO("OpenGL vendor: {0}", glGetString(GL_VENDOR));
		ENGINE_INFO("OpenGL hardware: {0}", glGetString(GL_RENDERER));
		ENGINE_INFO("OpenGL version: {0}", glGetString(GL_VERSION));


		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);


		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		Renderer::OpenGLVertexBuffer* vb = new Renderer::OpenGLVertexBuffer(&vertices, 3, { {Renderer::VertexBufferLayout::ElementType::Float3, false} }); //MEMORY_LEAK: fix with VAO
		
		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	}

	void OpenGLRenderer2D::BeginScene()
	{
		glBindVertexArray(m_VertexArray);
	}
	void OpenGLRenderer2D::EndScene()
	{
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}
}