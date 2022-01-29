#pragma once

#include "../Events/Events.h"
#include "../Definitions/KeyCodes/KeyCodes.h"

namespace GameEngine
{
	class Window
	{
	protected:
		std::string title;
		unsigned int width;
		unsigned int height;
		std::function<void(Event&)> event_callback;

		virtual void RegisterEvents() = 0;

	public:
		Window(unsigned int Width, unsigned int Height, std::string Title, std::function<void(Event&)> Event_Callback) : 
			width(Width), height(Height), title(Title), event_callback(Event_Callback) {};
		virtual ~Window() = default;

		virtual void SetSize(unsigned int Width, unsigned int Height) = 0;

		virtual void Use(bool vSync) = 0;
		virtual void Update() = 0;

		
		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline std::pair<float, float> GetMousePosition() = 0;
		virtual inline float GetMouseX() = 0;
		virtual inline float GetMouseY() = 0;
	};
}