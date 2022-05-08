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
		this->camera = ::GameEngine::RenderAPI::Camera::Create(0, this->Width * this->Zoom, 0, this->Height * this->Zoom);
	}

	void ControlledCamera::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			[[likely]] case (GameEngine::EventTypes::AppTick):
			{
				::GameEngine::AppTick& ev = static_cast<::GameEngine::AppTick&>(event);
				float multiplier = (float)(ev.GetFrameTime().GetSeconds());


				::GameEngine::Window* window = event.GetEngine()->GetWindow();

				float cameraRotation = this->camera->GetRotation();
				if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::Q)) cameraRotation += this->RotateSpeed * multiplier;
				else if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::E)) cameraRotation -= this->RotateSpeed * multiplier;
				this->camera->SetRotation(cameraRotation);

				glm::vec3 cameraPosition = this->camera->GetPosition();
				if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::D)) cameraPosition.x -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::A)) cameraPosition.x += this->MoveSpeed * multiplier;
				if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::W)) cameraPosition.y -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(::GameEngine::KeyCodes::Keys::S)) cameraPosition.y += this->MoveSpeed * multiplier;
				this->camera->SetPosition(cameraPosition);
				
				break;
			}
			case (GameEngine::EventTypes::MouseScroll):
			{
				::GameEngine::MouseScroll& ev = static_cast<::GameEngine::MouseScroll&>(event);
				this->Zoom -= this->ZoomSpeed * (float)ev.GetY();
				this->Zoom = std::max(this->Zoom, 0.01f);
				this->camera->SetProjection(0, this->Width * this->Zoom, 0, this->Height * this->Zoom);
				break;
			}
			default: { }
		}
	}
}