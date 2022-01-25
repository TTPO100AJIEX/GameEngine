#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"

namespace Engine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_ERROR("GLFW Error {0}: {1}", error, description);
	}
	enum class GLFW_status { ON, OFF };
	static void switch_GLFW(GLFW_status status)
	{
		static bool GLFW_initialized = false;
		if (status == GLFW_status::ON)
		{
			if (GLFW_initialized) return;
			if (!glfwInit()) [[unlikely]]
			{
				ENGINE_CRITICAL("Failed to initialize GLFW!");
				return;
			}
			ENGINE_WARN("Initialized GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFW_initialized = true;
		}
		else
		{
			if (!GLFW_initialized) return;
			glfwTerminate();
			GLFW_initialized = false;
			ENGINE_WARN("Terminated GLFW!");
		}
	}


	WindowsWindow::WindowsWindow(unsigned int Width, unsigned int Height, std::string Title, std::function<void(Event&)> Event_Callback)
	{
		width = Width;
		height = Height;
		title = Title;
		event_callback = Event_Callback;

		switch_GLFW(GLFW_status::ON);

		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		Use(true);

		glfwSetWindowUserPointer(window, this);

		RegisterEvents();
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(window);
		switch_GLFW(GLFW_status::OFF);
	}


	void WindowsWindow::SetSize(unsigned int Width, unsigned int Height)
	{
		width = Width;
		height = Height;
		glfwSetWindowSize(window, width, height);
	}


	void WindowsWindow::Use(bool vSync)
	{
		glfwMakeContextCurrent(window);
		glfwSwapInterval((vSync) ? 1 : 0);
	}
	void WindowsWindow::Update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	inline bool WindowsWindow::IsKeyPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetKey(window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	inline bool WindowsWindow::IsMouseButtonPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetMouseButton(window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS);
	}
	inline std::pair<float, float> WindowsWindow::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)(xpos), (float)(ypos) };
	}
	inline float WindowsWindow::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return(x);
	}
	inline float WindowsWindow::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return(y);
	}
}