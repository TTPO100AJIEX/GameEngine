#include <PrecompiledHeaders.h>

#include "Camera.h"

namespace GameEngine::Renderer
{
	Camera::Camera(float left, float right, float bottom, float top)
		: ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), ViewMatrix(1.0f)
	{
		this->ViewProjectionMatrix = this->ProjectionMatrix * this->ViewMatrix;
	}

	void Camera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), this->Position) * glm::rotate(glm::mat4(1.0f), this->Rotation, glm::vec3(0, 0, 1));
		this->ViewMatrix = glm::inverse(transform);
		this->ViewProjectionMatrix = this->ProjectionMatrix * this->ViewMatrix;
	}

	void Camera::SetProjection(float left, float right, float bottom, float top)
	{
		this->ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		this->RecalculateViewMatrix();
	}

	const glm::vec3& Camera::GetPosition() const { return(this->Position); }
	void Camera::SetPosition(const glm::vec3& position)
	{
		this->Position = position;
		this->RecalculateViewMatrix();
	}

	float Camera::GetRotation() const { return(this->Rotation); }
	void Camera::SetRotation(float rotation)
	{
		this->Rotation = rotation;
		this->RecalculateViewMatrix();
	}

	const glm::mat4& Camera::GetProjectionMatrix() const { return(this->ProjectionMatrix); }
	const glm::mat4& Camera::GetViewMatrix() const { return(this->ViewMatrix); }
	const glm::mat4& Camera::GetViewProjectionMatrix() const { return(this->ViewProjectionMatrix); }
}