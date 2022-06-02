#pragma once

#include "../_Window.h"

struct GLFWwindow;

namespace GameEngine
{
	class Window : public _Window
	{
	private:
		GLFWwindow* l_Window;

		virtual void RegisterEvents() const override;

	public:
		Window(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback);
		virtual ~Window();

		virtual void Use(bool vSync) const override;
		//virtual const void* GetProcAdressFunction() const override;

		virtual void SetSize(unsigned int width, unsigned int height) override;


		virtual void Update() override;


		virtual bool IsKeyPressed(const KeyCodes::Keys& keycode) const override;
		virtual bool IsMouseButtonPressed(const KeyCodes::Keys& keycode) const override;
		virtual std::pair<double, double> GetMousePosition() const override;
		virtual double GetMouseX() const override;
		virtual double GetMouseY() const override;
	};
}