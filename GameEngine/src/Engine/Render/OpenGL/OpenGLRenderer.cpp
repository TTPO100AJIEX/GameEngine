#include <PrecompiledHeaders.h>

#include "OpenGLRenderer.h"

#include "VertexBuffer/OpenGLVertexBuffer.h"
#include "VertexBufferLayout/OpenGLLayout.h"
#include "IndexBuffer/OpenGLIndexBuffer.h"
#include "VertexArray/OpenGLVertexArray.h"
#include "Shader/OpenGLShader.h"
#include "Texture/Texture2D/OpenGLTexture2D.h"

#include "../General/Camera/Camera.h"

namespace GameEngine
{
	void OpenGLRenderer::SetClearColor(const glm::vec4& Color) const
	{
		glClearColor(Color.r, Color.g, Color.b, Color.a);
	}
	void OpenGLRenderer::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLRenderer::SetViewport(int x, int y, int width, int height) const
	{
		glViewport(x, y, width, height);
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
		int versionMajor, versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
		ENGINE_INFO("OpenGL major version: {0}", versionMajor);
		ENGINE_INFO("OpenGL minor version: {0}", versionMinor);
		if (versionMajor < 4 || (versionMajor == 4 && versionMinor < 5)) { ENGINE_CRITICAL("Engine requires OpenGL version 4.5.0 or above!"); return; }

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	OpenGLRenderer::~OpenGLRenderer()
	{

	}

	void OpenGLRenderer::BeginScene(const std::shared_ptr<Render::Camera> camera)
	{
		this->SceneData.ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<Render::VertexArray> vertexArray, const std::shared_ptr<Render::Shader> shader, const glm::mat4& transform)
	{
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjection", this->SceneData.ViewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, (unsigned int)(vertexArray->GetIndexBuffer()->GetAmount()), GL_UNSIGNED_INT, nullptr);
	}

	void OpenGLRenderer::EndScene()
	{
	}
}