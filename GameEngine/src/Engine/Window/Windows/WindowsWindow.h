#pragma once

#include "../../Events/Events.h"
#include "../../Events/Window.h"
#include "../../Events/Keyboard.h"
#include "../../Events/Mouse.h"

#include "../../Definitions/KeyCodes.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	class API WindowsWindow
	{
	private:
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

		void Create(unsigned int width, unsigned int height, std::string& title);
		void RegisterEvents();
	public:
		WindowsWindow(unsigned int width, unsigned int height, std::string title);
		WindowsWindow(unsigned int width, unsigned int height, std::string title, std::function<void(Event&)> callback);
		~WindowsWindow();

		void SetOnEventCallback(std::function<void(Event&)> callback);

		void StartUpdate();
		void Update();
		void FinishUpdate();


		inline unsigned int GetWidth() { return(WindowData.Width); }
		inline unsigned int GetHeight() { return(WindowData.Height); }


		inline bool IsKeyPressed(KeyCodes::Keys& keycode);
		inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode);
		inline std::pair<double, double> GetMousePosition();
		inline double GetMouseX();
		inline double GetMouseY();
	};
}