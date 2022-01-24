#pragma once

#include <GLFW/glfw3.h>

#include "../Window.h"

namespace Engine
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_Window;

	public:
		WindowsWindow(unsigned int width, unsigned int height, std::string title, std::function<void(Event&)> callback);
		virtual ~WindowsWindow();

		virtual void RegisterEvents() override;
		virtual void OnEvent(Event& event) override;

		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) override;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) override;
		virtual inline std::pair<double, double> GetMousePosition() override;
		virtual inline double GetMouseX() override;
		virtual inline double GetMouseY() override;
	};
}