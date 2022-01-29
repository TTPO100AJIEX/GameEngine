#pragma once

#include "../Window.h"

#include <GLFW/glfw3.h>

namespace GameEngine
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* l_Window;

		virtual void RegisterEvents() const override;

	public:
		WindowsWindow(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback);
		virtual ~WindowsWindow();

		virtual void SetSize(unsigned int width, unsigned int height) override;

		virtual void Use(bool vSync) const override;
		virtual void Update() override;

		virtual inline bool IsKeyPressed(const KeyCodes::Keys& keycode) const override;
		virtual inline bool IsMouseButtonPressed(const KeyCodes::Keys& keycode) const override;
		virtual inline std::pair<float, float> GetMousePosition() const override;
		virtual inline float GetMouseX() const override;
		virtual inline float GetMouseY() const override;
	};
}