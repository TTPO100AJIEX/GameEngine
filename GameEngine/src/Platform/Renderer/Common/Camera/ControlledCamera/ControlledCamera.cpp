#include <PrecompiledHeaders.h>

#include <Common/Engine.h>
#include <Platform/Window/Window.h>
#include <Common/Events/Event.h>
#include <Common/Events/App.h>
#include <Common/Events/Keyboard.h>
#include <Common/Events/Mouse.h>
#include <Common/Events/Window.h>
#include "../Camera.h"

#include "ControlledCamera.h"


namespace GameEngine::Renderer
{
	ControlledCamera::ControlledCamera(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed)
		: Width(width), Height(height), Zoom(zoom), MoveSpeed(move_speed), RotateSpeed(rotate_speed), ZoomSpeed(zoom_speed)
	{
		this->camera = std::make_shared<Camera>(0, this->Width * this->Zoom, 0, this->Height * this->Zoom);
	}
	const std::shared_ptr<Camera> ControlledCamera::GetCamera() const { return(this->camera); }

	void ControlledCamera::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			[[likely]] case (GameEngine::EventTypes::AppTick):
			{
				AppTick& ev = static_cast<AppTick&>(event);
				float multiplier = (float)(ev.GetFrameTime().GetSeconds());

				
				Window* window = event.GetEngine()->GetActiveWindow();
				
				float cameraRotation = this->camera->GetRotation();
				if (window->IsKeyPressed(KeyCodes::Keys::Q)) cameraRotation += this->RotateSpeed * multiplier;
				else if (window->IsKeyPressed(KeyCodes::Keys::E)) cameraRotation -= this->RotateSpeed * multiplier;
				if (cameraRotation > 180.0f) cameraRotation -= 360.0f;
				if (cameraRotation <= -180.0f) cameraRotation += 360.0f;
				this->camera->SetRotation(cameraRotation);
				
				glm::vec3 cameraPosition = this->camera->GetPosition();
				glm::vec2 movement(0.0f);
				if (window->IsKeyPressed(KeyCodes::Keys::D)) movement.x -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(KeyCodes::Keys::A)) movement.x += this->MoveSpeed * multiplier;
				if (window->IsKeyPressed(KeyCodes::Keys::W)) movement.y -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(KeyCodes::Keys::S)) movement.y += this->MoveSpeed * multiplier;
				cameraPosition += glm::vec3(glm::rotate(movement, cameraRotation), 0.0f);
				this->camera->SetPosition(cameraPosition);
				
				break;
			}
			case (GameEngine::EventTypes::MouseScroll):
			{
				MouseScroll& ev = static_cast<MouseScroll&>(event);
				this->Zoom -= this->ZoomSpeed * (float)ev.GetY();
				this->Zoom = std::max(this->Zoom, 0.01f);
				this->camera->SetProjection(0, this->Width * this->Zoom, 0, this->Height * this->Zoom);
				break;
			}
			default: { }
		}
	}
}