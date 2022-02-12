#include <PrecompiledHeaders.h>

#include "OpenGLRenderer2D.h"

#include <GLAD/glad.h>

namespace GameEngine
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
	}
	OpenGLRenderer2D::~OpenGLRenderer2D()
	{

	}

	void OpenGLRenderer2D::BeginScene(const std::shared_ptr<Renderer::Camera>& camera)
	{
		SceneData.ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void OpenGLRenderer2D::DrawIndexed(const std::shared_ptr<Renderer::OpenGLVertexArray>& vertexArray, const std::shared_ptr<Renderer::OpenGLShader>& shader)
	{
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjection", SceneData.ViewProjectionMatrix);
		glBindVertexArray(vertexArray->GetID());
	}
	void OpenGLRenderer2D::DrawIndexed(const std::shared_ptr<Renderer::VertexArray>& vertexArray, const std::shared_ptr<Renderer::Shader>& shader)
	{
		this->DrawIndexed(std::dynamic_pointer_cast<Renderer::OpenGLVertexArray>(vertexArray), std::dynamic_pointer_cast<Renderer::OpenGLShader>(shader));
	}

	void OpenGLRenderer2D::EndScene()
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}