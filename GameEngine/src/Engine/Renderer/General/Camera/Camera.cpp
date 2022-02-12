#include <PrecompiledHeaders.h>

#include "Camera.h"

namespace GameEngine::Renderer
{
	Camera::Camera(float left, float right, float bottom, float top)
		: ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), ViewMatrix(1.0f)
	{
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	}

	void Camera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), Position) * glm::rotate(glm::mat4(1.0f), Rotation, glm::vec3(0, 0, 1));
		ViewMatrix = glm::inverse(transform);
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	}


	const glm::vec3& Camera::GetPosition() const { return(Position); }
	void Camera::SetPosition(const glm::vec3& position)
	{
		Position = position;
		RecalculateViewMatrix();
	}

	float Camera::GetRotation() const { return(Rotation); }
	void Camera::SetRotation(float rotation)
	{
		Rotation = rotation;
		RecalculateViewMatrix();
	}

	const glm::mat4& Camera::GetProjectionMatrix() const { return(ProjectionMatrix); }
	const glm::mat4& Camera::GetViewMatrix() const { return(ViewMatrix); }
	const glm::mat4& Camera::GetViewProjectionMatrix() const { return(ViewProjectionMatrix); }
}