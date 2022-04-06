#include <PrecompiledHeaders.h>

#include "OpenGLRenderer.h"

namespace GameEngine
{
	void OpenGLRenderer::SetClearColor(const glm::vec4& Color)
	{
		glClearColor(Color.r, Color.g, Color.b, Color.a);
	}
	void OpenGLRenderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	OpenGLRenderer::OpenGLRenderer()
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
	OpenGLRenderer::~OpenGLRenderer()
	{

	}

	void OpenGLRenderer::BeginScene(const std::shared_ptr<Render::Camera>& camera)
	{
		this->SceneData.ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<Render::OpenGLVertexArray>& vertexArray, const std::shared_ptr<Render::OpenGLShader>& shader, const glm::mat4& transform)
	{
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjection", this->SceneData.ViewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetAmount(), GL_UNSIGNED_INT, nullptr);
	}
	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<Render::VertexArray>& vertexArray, const std::shared_ptr<Render::Shader>& shader, const glm::mat4& transform)
	{
		this->DrawIndexed(std::dynamic_pointer_cast<Render::OpenGLVertexArray>(vertexArray), std::dynamic_pointer_cast<Render::OpenGLShader>(shader), transform);
	}

	void OpenGLRenderer::EndScene()
	{
	}
}