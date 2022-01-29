#pragma once

#include "../Events/Events.h"
#include "../Definitions/KeyCodes/KeyCodes.h"

namespace GameEngine
{
	class Window
	{
	protected:
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		std::function<void(Event&)> Event_Callback;

		virtual void RegisterEvents() const = 0;

	public:
		Window(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback) : 
			Width(width), Height(height), Title(title), Event_Callback(event_callback) {};
		virtual ~Window() = default;

		virtual void SetSize(unsigned int width, unsigned int height) = 0;

		virtual void Use(bool vSync) const = 0;
		virtual void Update() = 0;

		
		virtual inline bool IsKeyPressed(const KeyCodes::Keys& keycode) const = 0;
		virtual inline bool IsMouseButtonPressed(const KeyCodes::Keys& keycode) const = 0;
		virtual inline std::pair<float, float> GetMousePosition() const = 0;
		virtual inline float GetMouseX() const = 0;
		virtual inline float GetMouseY() const = 0;
	};
}