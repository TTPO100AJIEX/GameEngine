#pragma once

#include "../Camera.h"

#include "../../../../Events/Events.h"
#include "../../../../Window/Window.h"

namespace GameEngine::Render
{
	class ControlledCamera
	{
	private:
		std::shared_ptr<GameEngine::Render::Camera> camera;

		float Width, Height;
		float MoveSpeed, RotateSpeed, ZoomSpeed;
		float Zoom;

	public:
		ControlledCamera(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed);
		const std::shared_ptr<GameEngine::Render::Camera> GetCamera();

		void OnEvent(Event& event);
	};
}