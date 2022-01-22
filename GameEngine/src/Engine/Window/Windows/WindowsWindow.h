#pragma once

#include "../DesktopWindow.h"

namespace Engine
{
	class WindowsWindow : public DesktopWindow
	{
	private:
		virtual void Create(unsigned int width, unsigned int height, std::string& title) override;
		virtual void RegisterEvents() override;

	public:
		WindowsWindow(unsigned int width, unsigned int height, std::string title);
		WindowsWindow(unsigned int width, unsigned int height, std::string title, std::function<void(Event&)> callback);
		~WindowsWindow();


		virtual void StartUpdate() override;
		virtual void Update() override;
		virtual void FinishUpdate() override;


		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) override;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) override;
		virtual inline std::pair<double, double> GetMousePosition() override;
	};
}