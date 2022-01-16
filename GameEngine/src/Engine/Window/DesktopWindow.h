#pragma once

#include "../Events/Events.h"
#include "../Events/Window.h"
#include "../Events/Keyboard.h"
#include "../Events/Mouse.h"

#include "../Definitions/KeyCodes.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	class API DesktopWindow
	{
	protected:
		GLFWwindow* Window;
		bool EventsRegistered;

		struct windowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			std::function<void(Event&)> OnEventCallback;
		};
		windowData WindowData;

		virtual void Create(unsigned int width, unsigned int height, std::string& title) = 0;
		virtual void RegisterEvents() = 0;

	public:
		void SetOnEventCallback(std::function<void(Event&)> callback);

		virtual void StartUpdate() = 0;
		virtual void Update() = 0;
		virtual void FinishUpdate() = 0;


		inline unsigned int GetWidth() { return(WindowData.Width); }
		inline unsigned int GetHeight() { return(WindowData.Height); }


		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline std::pair<double, double> GetMousePosition() = 0;
		inline double GetMouseX();
		inline double GetMouseY();
	};
}