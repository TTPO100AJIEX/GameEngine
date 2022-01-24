#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"
#include "../../Renderer/OpenGL/OpenGLContext.h"

#include "../../Events/App.h"
#include "../../Events/Window.h"
#include "../../Events/Keyboard.h"
#include "../../Events/Mouse.h"

#include <iostream>

namespace Engine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_ERROR("GLFW Error {0}: {1}", error, description);
	}
	static void Check_GLFW_Initialization()
	{
		static bool GLFW_initialized = false;
		if (!GLFW_initialized) [[unlikely]]
		{
			if (!glfwInit()) [[unlikely]]
			{
				ENGINE_CRITICAL("Failed to initialize GLFW!");
				return;
			}
			ENGINE_INFO("Initialized GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFW_initialized = true;
		}
	}


	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string title, std::function<void(Event&)> callback)
	{
		Check_GLFW_Initialization();

		WindowData.Width = width;
		WindowData.Height = height;
		WindowData.Title = title;
		WindowData.Callback = callback;

		m_Window = glfwCreateWindow(WindowData.Width, WindowData.Height, WindowData.Title.c_str(), NULL, NULL);

		RenderingContext = std::make_shared<Renderer::OpenGLContext>(m_Window);

		WindowOpen WindowOpenEvent(WindowData.Width, WindowData.Height);
		WindowData.Callback(WindowOpenEvent);

		glfwSwapInterval(1);
		glfwSetWindowUserPointer(m_Window, &WindowData);

		RegisterEvents();
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		ENGINE_WARN("Terminated GLFW!");
	}



	void WindowsWindow::RegisterEvents()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowResize WindowResizeEvent(width, height);
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;
			data.Callback(WindowResizeEvent);
		});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowClose WindowCloseEvent;
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.Callback(WindowCloseEvent);
		});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 0);
					data.Callback(KeyPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease KeyReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)));
					data.Callback(KeyReleaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 1);
					data.Callback(KeyPressEvent);
					break;
				}
				default:
				{
					ENGINE_ERROR("Unhandled key callback action {0}", action);
				}
			}
		});
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int symbol)
		{
			KeyType KeyTypeEvent((char)(symbol));
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.Callback(KeyTypeEvent);
		});
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			MouseMove MouseMoveEvent(xPos, yPos);
			data.Callback(MouseMoveEvent);
		});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			MouseScroll MouseScrollEvent(xOffset, yOffset);
			data.Callback(MouseScrollEvent);
		});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPress MouseButtonPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					data.Callback(MouseButtonPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonRelease MouseButtonReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					data.Callback(MouseButtonReleaseEvent);
					break;
				}
				default:
				{
					ENGINE_ERROR("Unhandled key callback action {0}", action);
				}
			}
		});
	}


	void WindowsWindow::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			case(EventTypes::AppTick):
			{
				RenderingContext->Clear(m_Window);
				RenderingContext->SwapBuffers(m_Window);
				break;
			}
			default:
			{
				ENGINE_TRACE("{0}", event.ToString());
			}
		}
	}


	inline bool WindowsWindow::IsKeyPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetKey(m_Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	inline bool WindowsWindow::IsMouseButtonPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetMouseButton(m_Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS);
	}
	inline std::pair<double, double> WindowsWindow::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(m_Window, &xpos, &ypos);
		return { xpos, ypos };
	}
	inline double WindowsWindow::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return(x);
	}
	inline double WindowsWindow::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return(y);
	}
}