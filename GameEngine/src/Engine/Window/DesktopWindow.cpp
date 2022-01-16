#include <PrecompiledHeaders.h>

#include "DesktopWindow.h"

namespace Engine
{
	void DesktopWindow::SetOnEventCallback(std::function<void(Event&)> callback)
	{
		WindowData.OnEventCallback = callback;
		RegisterEvents();
	}


	inline double DesktopWindow::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return(x);
	}
	inline double DesktopWindow::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return(y);
	}
}