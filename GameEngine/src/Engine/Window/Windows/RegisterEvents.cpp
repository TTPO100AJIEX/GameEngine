#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"

#include "../../Events/Window.h"
#include "../../Events/Keyboard.h"
#include "../../Events/Mouse.h"

namespace Engine
{
	void WindowsWindow::RegisterEvents()
	{
		glfwSetWindowSizeCallback(window, [](GLFWwindow* l_window, int Width, int Height)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			window_data.width = Width;
			window_data.height = Height;
			WindowResize WindowResizeEvent(window_data.width, window_data.height);
			window_data.event_callback(WindowResizeEvent);
		});
		glfwSetWindowCloseCallback(window, [](GLFWwindow* l_window)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			WindowClose WindowCloseEvent;
			window_data.event_callback(WindowCloseEvent);
		});


		glfwSetKeyCallback(window, [](GLFWwindow* l_window, int key, int scancode, int action, int mods)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 0);
					window_data.event_callback(KeyPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease KeyReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)));
					window_data.event_callback(KeyReleaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 1);
					window_data.event_callback(KeyPressEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled keyboard key callback action {0}", action); }
			}
		});
		glfwSetCharCallback(window, [](GLFWwindow* l_window, unsigned int symbol)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			KeyType KeyTypeEvent((char)(symbol));
			window_data.event_callback(KeyTypeEvent);
		});



		glfwSetCursorPosCallback(window, [](GLFWwindow* l_window, double xPos, double yPos)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			MouseMove MouseMoveEvent(xPos, yPos);
			window_data.event_callback(MouseMoveEvent);
		});
		glfwSetScrollCallback(window, [](GLFWwindow* l_window, double xOffset, double yOffset)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			MouseScroll MouseScrollEvent(xOffset, yOffset);
			window_data.event_callback(MouseScrollEvent);
		});
		glfwSetMouseButtonCallback(window, [](GLFWwindow* l_window, int button, int action, int mods)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPress MouseButtonPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					window_data.event_callback(MouseButtonPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonRelease MouseButtonReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					window_data.event_callback(MouseButtonReleaseEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled mouse key callback action {0}", action); }
			}
		});


		WindowOpen WindowOpenEvent(width, height);
		event_callback(WindowOpenEvent);
	}
}