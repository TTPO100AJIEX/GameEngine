#pragma once

#include "../Events/Events.h"
#include "../Definitions/KeyCodes/KeyCodes.h"

namespace Engine
{
	class Window
	{
	protected:
		std::string title;
		unsigned int width;
		unsigned int height;
		std::function<void(Event&)> event_callback;

	public:
		virtual ~Window() = default;

		virtual void RegisterEvents() = 0;

		virtual void SetSize(unsigned int Width, unsigned int Height) = 0;

		virtual void Use(bool vSync) = 0;
		virtual void Update() = 0;

		
		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline std::pair<double, double> GetMousePosition() = 0;
		virtual inline double GetMouseX() = 0;
		virtual inline double GetMouseY() = 0;
	};
}