#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"

#include <GLAD/glad.h>

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
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFW_initialized = true;
		}
	}



	void WindowsWindow::Create(unsigned int width, unsigned int height, std::string& title)
	{
		Check_GLFW_Initialization();

		EventsRegistered = false;
		WindowData.Width = width;
		WindowData.Height = height;
		WindowData.Title = title;
		WindowData.OnEventCallback = nullptr;

		Window = glfwCreateWindow(WindowData.Width, WindowData.Height, WindowData.Title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(Window);
/*-----------------------------------------------*/
		int status = gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
		ENGINE_INFO("GLAD status: {0}", status);
/*-----------------------------------------------*/
		glfwSwapInterval(1);
		glfwSetWindowUserPointer(Window, &WindowData);
	}
	void WindowsWindow::RegisterEvents()
	{
		if (EventsRegistered) return;
		EventsRegistered = true;
		
		glfwSetWindowSizeCallback(Window, [](GLFWwindow* window, int width, int height)
		{
			WindowResize WindowResizeEvent(width, height);
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;
			data.OnEventCallback(WindowResizeEvent);
		});
		glfwSetWindowCloseCallback(Window, [](GLFWwindow* window)
		{
			WindowClose WindowCloseEvent;
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.OnEventCallback(WindowCloseEvent);
		});
		glfwSetKeyCallback(Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			switch(action)
			{
				case GLFW_PRESS:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 0);
					data.OnEventCallback(KeyPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease KeyReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)));
					data.OnEventCallback(KeyReleaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPress KeyPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(key)), 1);
					data.OnEventCallback(KeyPressEvent);
					break;
				}
				[[unlikely]] default:
				{
					ENGINE_ERROR("Unhandled key callback action {0}", action);
				}
			}
		});
		glfwSetCharCallback(Window, [](GLFWwindow* window, unsigned int symbol)
		{
			KeyType KeyTypeEvent((char)(symbol));
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			data.OnEventCallback(KeyTypeEvent);
		});
		glfwSetCursorPosCallback(Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			MouseMove MouseMoveEvent(xPos, yPos);
			data.OnEventCallback(MouseMoveEvent);
		});
		glfwSetScrollCallback(Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			MouseScroll MouseScrollEvent(xOffset, yOffset);
			data.OnEventCallback(MouseScrollEvent);
		});
		glfwSetMouseButtonCallback(Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			windowData& data = *(windowData*)(glfwGetWindowUserPointer(window));
			switch(action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPress MouseButtonPressEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					data.OnEventCallback(MouseButtonPressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonRelease MouseButtonReleaseEvent(KeyCodes::FromGLFW(static_cast<KeyCodes::GLFWKeys>(button)));
					data.OnEventCallback(MouseButtonReleaseEvent);
					break;
				}
				[[unlikely]] default:
				{
					ENGINE_ERROR("Unhandled key callback action {0}", action);
				}
			}
		});
	}
	void WindowsWindow::SetOnEventCallback(std::function<void(Event&)> callback)
	{
		WindowData.OnEventCallback = callback;
		RegisterEvents();
	}

	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string title)
	{
		Create(width, height, title);
	}
	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string title, std::function<void(Event&)> callback)
	{
		Create(width, height, title);
		WindowData.OnEventCallback = callback;
		RegisterEvents();

		WindowOpen WindowOpenEvent(WindowData.Width, WindowData.Height);
		WindowData.OnEventCallback(WindowOpenEvent);
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(Window);
		glfwTerminate();
		ENGINE_WARN("Terminated GLFW!");
	}



	void WindowsWindow::StartUpdate()
	{
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void WindowsWindow::Update()
	{
	}
	void WindowsWindow::FinishUpdate()
	{
		glfwSwapBuffers(Window);
		glfwPollEvents();
	}




	inline bool WindowsWindow::IsKeyPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetKey(Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	inline bool WindowsWindow::IsMouseButtonPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetMouseButton(Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS);
	}
	inline std::pair<double, double> WindowsWindow::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(Window, &xpos, &ypos);
		return {xpos, ypos};
	}
	inline double WindowsWindow::GetMouseX()
	{
		auto[x, y] = GetMousePosition();
		return(x);
	}
	inline double WindowsWindow::GetMouseY()
	{
		auto[x, y] = GetMousePosition();
		return(y);
	}
}