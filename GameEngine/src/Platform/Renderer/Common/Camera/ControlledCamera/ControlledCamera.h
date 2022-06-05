#pragma once

namespace GameEngine
{
	class Event;
	namespace Renderer
	{
		class Camera;
	}
}

namespace GameEngine::Renderer
{
	class ControlledCamera
	{
	private:
		std::shared_ptr<Camera> camera;

		float Width, Height;
		float MoveSpeed, RotateSpeed, ZoomSpeed;
		float Zoom;

	public:
		ControlledCamera(float width, float height, float zoom, float move_speed, float rotate_speed, float zoom_speed);
		~ControlledCamera() = default;
		const std::shared_ptr<Camera> GetCamera() const;

		void OnEvent(Event& event);
	};
}