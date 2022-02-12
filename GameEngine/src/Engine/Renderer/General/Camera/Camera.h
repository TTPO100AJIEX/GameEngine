#pragma once

namespace GameEngine::Renderer
{
	class Camera
	{
	private:
		glm::mat4 ProjectionMatrix;
		glm::mat4 ViewMatrix;
		glm::mat4 ViewProjectionMatrix;
		glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
		float Rotation = 0.0f;

		void RecalculateViewMatrix();

	public:
		Camera(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3& position);

		float GetRotation() const;
		void SetRotation(float rotation);

		const glm::mat4& GetProjectionMatrix() const;
		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetViewProjectionMatrix() const;
	};
}