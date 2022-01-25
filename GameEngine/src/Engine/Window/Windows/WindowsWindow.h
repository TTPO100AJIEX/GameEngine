#pragma once

#include "../Window.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* window;

	public:
		WindowsWindow(unsigned int Width, unsigned int Height, std::string Title, std::function<void(Event&)> Event_Callback);
		virtual ~WindowsWindow();

		virtual void RegisterEvents() override;

		virtual void SetSize(unsigned int Width, unsigned int Height) override;

		virtual void Use(bool vSync) override;
		virtual void Update() override;

		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) override;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) override;
		virtual inline std::pair<float, float> GetMousePosition() override;
		virtual inline float GetMouseX() override;
		virtual inline float GetMouseY() override;
	};
}