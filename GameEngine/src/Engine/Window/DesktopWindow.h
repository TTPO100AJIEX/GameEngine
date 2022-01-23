#pragma once

#include "../Events/Window.h"
#include "../Events/Keyboard.h"
#include "../Events/Mouse.h"

#include "../Renderer/General/Context.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	class DesktopWindow
	{
	protected:
		GLFWwindow* Window;
		std::unique_ptr<Renderer::Context> RenderingContext;
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
		inline GLFWwindow* GetWindow();

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