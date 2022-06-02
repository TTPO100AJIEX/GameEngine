#include <PrecompiledHeaders.h>

#include <GLFW/glfw3.h>
#include <Common/Events/Event.h>
#include <Common/Events/App.h>
#include <Common/Events/Keyboard.h>
#include <Common/Events/Mouse.h>
#include <Common/Events/Window.h>
#include <Platform/KeyCodes/GLFW/Keys.h>

#include "Window.h"

namespace GameEngine
{
	void Window::RegisterEvents() const
	{
		glfwSetWindowSizeCallback(this->l_Window, [](GLFWwindow* window, int Width, int Height)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			window_data->Width = Width;
			window_data->Height = Height;
			WindowResize WindowResizeEvent(window_data->Width, window_data->Height, window_data);
			window_data->EventCallback(WindowResizeEvent);
		});
		glfwSetWindowCloseCallback(this->l_Window, [](GLFWwindow* window)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			WindowClose WindowCloseEvent(window_data);
			window_data->EventCallback(WindowCloseEvent);
		});
		

		glfwSetKeyCallback(this->l_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(key), 0, window_data);
					window_data->EventCallback(KeyPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease KeyReleaseEvent(KeyCodes::FromGLFW(key), window_data);
					window_data->EventCallback(KeyReleaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(key), 1, window_data);
					window_data->EventCallback(KeyPressEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled keyboard key callback action {0}", action); }
			}
		});
		glfwSetCharCallback(this->l_Window, [](GLFWwindow* window, unsigned int symbol)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			KeyType KeyTypeEvent((char)(symbol), window_data);
			window_data->EventCallback(KeyTypeEvent);
		});


		glfwSetCursorPosCallback(this->l_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			MouseMove MouseMoveEvent(xPos, yPos, window_data);
			window_data->EventCallback(MouseMoveEvent);
		});
		glfwSetScrollCallback(this->l_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			MouseScroll MouseScrollEvent(xOffset, yOffset, window_data);
			window_data->EventCallback(MouseScrollEvent);
		});
		glfwSetMouseButtonCallback(this->l_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Window* window_data = (Window*)(glfwGetWindowUserPointer(window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPress MouseButtonPressEvent(KeyCodes::FromGLFW(button), window_data);
					window_data->EventCallback(MouseButtonPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonRelease MouseButtonReleaseEvent(KeyCodes::FromGLFW(button), window_data);
					window_data->EventCallback(MouseButtonReleaseEvent);
					break;
				}
				[[unlikely]] default: { ENGINE_ERROR("Unhandled mouse key callback action {0}", action); }
			}
		});

		WindowOpen WindowOpenEvent(this->Width, this->Height, this);
		this->EventCallback(WindowOpenEvent);
	}
}