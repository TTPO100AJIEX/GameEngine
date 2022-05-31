#pragma once

namespace GameEngine
{
	class Event;
	class Engine;
}
namespace GameEngine::Render
{
	class Camera;
}

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
		const std::shared_ptr<GameEngine::Render::Camera> GetCamera() { return(camera); }

		void OnEvent(Event& event);
	};
}