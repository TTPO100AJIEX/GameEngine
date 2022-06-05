#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>
#include <Platform/Window/Window.h>
#include <Platform/Renderer/Renderer.h>

#include "Renderer.h"

namespace GameEngine::Renderer
{
	void Init()
	{
		static bool glad_initialized = false;
		if (glad_initialized) return;
		glad_initialized = true;
		if (!gladLoadGLLoader((GLADloadproc)(Window::GetProcAdressFunction())))
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

	void SetClearColor(const glm::vec4& Color)
	{
		glClearColor(Color.r, Color.g, Color.b, Color.a);
	}
	void SetViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	void Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	struct Scene_Data
	{
		glm::mat4 ViewProjectionMatrix;
	};
	static Scene_Data SceneData;

	void BeginScene(const std::shared_ptr<Camera> camera)
	{
		SceneData.ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void DrawIndexed(const std::shared_ptr<VertexArray> vertexArray, const std::shared_ptr<Shader> shader, const glm::mat4& transform)
	{
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjection", SceneData.ViewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, (unsigned int)(vertexArray->GetIndexBuffer()->GetAmount()), GL_UNSIGNED_INT, nullptr);
	}

	void EndScene()
	{
	}
}