#include <PrecompiledHeaders.h>

#include "ControlledCamera.h"

#include "../../../../Engine.h"
#include "../../../../Window/Window.h"
#include "../../../RenderAPI.h"

#include "../../../../Events/App.h"
#include "../../../../Events/Keyboard.h"
#include "../../../../Events/Mouse.h"
#include "../../../../Events/Window.h"

#include "../Camera.h"


namespace GameEngine::Render
{
	ControlledCamera::ControlledCamera(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed)
		: Width(width), Height(height), Zoom(zoom), MoveSpeed(move_speed), RotateSpeed(rotate_speed), ZoomSpeed(zoom_speed)
	{
		this->camera = RenderAPI::Camera::Create(0, this->Width * this->Zoom, 0, this->Height * this->Zoom);
	}

	void ControlledCamera::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			[[likely]] case (GameEngine::EventTypes::AppTick):
			{
				AppTick& ev = static_cast<AppTick&>(event);
				float multiplier = (float)(ev.GetFrameTime().GetSeconds());


				Window* window = event.GetEngine()->GetWindow();

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