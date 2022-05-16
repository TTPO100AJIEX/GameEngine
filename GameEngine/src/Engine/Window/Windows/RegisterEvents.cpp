#include <PrecompiledHeaders.h>

#include <GLFW/glfw3.h>
#include "../../Core/KeyCodes/GLFW/GLFW.h"

#include "WindowsWindow.h"

#include "../../Events/Window.h"
#include "../../Events/Keyboard.h"
#include "../../Events/Mouse.h"

namespace GameEngine
{
	void WindowsWindow::RegisterEvents() const
	{
		glfwSetWindowSizeCallback(this->l_Window, [](GLFWwindow* l_window, int Width, int Height)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			window_data.Width = Width;
			window_data.Height = Height;
			WindowResize WindowResizeEvent(window_data.Width, window_data.Height, window_data.get_raw_this());
			window_data.Event_Callback(WindowResizeEvent);
		});
		glfwSetWindowCloseCallback(this->l_Window, [](GLFWwindow* l_window)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			WindowClose WindowCloseEvent(window_data.get_raw_this());
			window_data.Event_Callback(WindowCloseEvent);
		});


		glfwSetKeyCallback(this->l_Window, [](GLFWwindow* l_window, int key, int scancode, int action, int mods)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(key), 0, window_data.get_raw_this());
					window_data.Event_Callback(KeyPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease KeyReleaseEvent(KeyCodes::FromGLFW(key), window_data.get_raw_this());
					window_data.Event_Callback(KeyReleaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(key), 1, window_data.get_raw_this());
					window_data.Event_Callback(KeyPressEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled keyboard key callback action {0}", action); }
			}
		});
		glfwSetCharCallback(this->l_Window, [](GLFWwindow* l_window, unsigned int symbol)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			KeyType KeyTypeEvent((char)(symbol), window_data.get_raw_this());
			window_data.Event_Callback(KeyTypeEvent);
		});



		glfwSetCursorPosCallback(this->l_Window, [](GLFWwindow* l_window, double xPos, double yPos)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			MouseMove MouseMoveEvent(xPos, yPos, window_data.get_raw_this());
			window_data.Event_Callback(MouseMoveEvent);
		});
		glfwSetScrollCallback(this->l_Window, [](GLFWwindow* l_window, double xOffset, double yOffset)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			MouseScroll MouseScrollEvent(xOffset, yOffset, window_data.get_raw_this());
			window_data.Event_Callback(MouseScrollEvent);
		});
		glfwSetMouseButtonCallback(this->l_Window, [](GLFWwindow* l_window, int button, int action, int mods)
		{
			WindowsWindow& window_data = *(WindowsWindow*)(glfwGetWindowUserPointer(l_window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPress MouseButtonPressEvent(KeyCodes::FromGLFW(button), window_data.get_raw_this());
					window_data.Event_Callback(MouseButtonPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonRelease MouseButtonReleaseEvent(KeyCodes::FromGLFW(button), window_data.get_raw_this());
					window_data.Event_Callback(MouseButtonReleaseEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled mouse key callback action {0}", action); }
			}
		});

		WindowOpen WindowOpenEvent(this->Width, this->Height, this);
		this->Event_Callback(WindowOpenEvent);
	}
}