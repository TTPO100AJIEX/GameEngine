#include <PrecompiledHeaders.h>

#include "ControlledCamera.h"

#include "../../../../Events/App.h"
#include "../../../../Events/Keyboard.h"
#include "../../../../Events/Mouse.h"
#include "../../../../Events/Window.h"

#include "../../../RenderAPI.h"

namespace GameEngine::Render
{
	ControlledCamera::ControlledCamera(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed)
		: Width(width), Height(height), Zoom(zoom), MoveSpeed(move_speed), RotateSpeed(rotate_speed), ZoomSpeed(zoom_speed)
	{
		float renderWidth = this->Width * this->Zoom / 2;
		float renderHeight = this->Height * this->Zoom / 2;
		this->camera = ::GameEngine::RenderAPI::Camera::Create(-renderWidth, renderWidth, -renderHeight, renderHeight);
	}

	const std::shared_ptr<GameEngine::Render::Camera> ControlledCamera::GetCamera() { return(camera); }

	void ControlledCamera::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			[[likely]] case (GameEngine::EventTypes::AppTick):
			{
				GameEngine::AppTick& ev = static_cast<GameEngine::AppTick&>(event);
				float multiplier = ev.GetFrameTime().GetSeconds();



				auto window = event.GetEngine()->GetWindow(); //want

				/*float cameraRotation = this->camera->GetRotation();
				if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::Q)) cameraRotation += this->RotateSpeed * multiplier;
				else if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::E)) cameraRotation -= this->RotateSpeed * multiplier;
				this->camera->SetRotation(cameraRotation);

				glm::vec3 cameraPosition = this->camera->GetPosition();
				if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::D)) cameraPosition.x -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::A)) cameraPosition.x += this->MoveSpeed * multiplier;
				if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::W)) cameraPosition.y -= this->MoveSpeed * multiplier;
				else if (window->IsKeyPressed(GameEngine::KeyCodes::Keys::S)) cameraPosition.y += this->MoveSpeed * multiplier;
				this->camera->SetPosition(cameraPosition);
				*/
				break;
			}
			case (GameEngine::EventTypes::MouseScroll):
			{
				GameEngine::MouseScroll& ev = static_cast<GameEngine::MouseScroll&>(event);
				this->Zoom -= this->ZoomSpeed * (float)ev.GetY();
				this->Zoom = std::max(this->Zoom, 0.0001f);
				float renderWidth = this->Width * this->Zoom / 2;
				float renderHeight = this->Height * this->Zoom / 2;
				this->camera->SetProjection(-renderWidth, renderWidth, -renderHeight, renderHeight);
				break;
			}
			case (GameEngine::EventTypes::WindowResize):
			{
				GameEngine::WindowResize& ev = static_cast<GameEngine::WindowResize&>(event);
				this->Width = this->Height * ev.GetWidth() / ev.GetHeight();
				float renderWidth = this->Width * this->Zoom / 2;
				float renderHeight = this->Height * this->Zoom / 2;
				this->camera->SetProjection(-renderWidth, renderWidth, -renderHeight, renderHeight);
				break;
			}
			default: { }
		}
	}
}