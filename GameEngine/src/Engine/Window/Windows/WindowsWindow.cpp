#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"

#include "../../Definitions/KeyCodes/GLFW/GLFW.h"

namespace Engine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_ERROR("GLFW Error {0}: {1}", error, description);
	}
	enum class GLFW_status : uint8_t { ON, OFF };
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


	WindowsWindow::WindowsWindow(unsigned int Width, unsigned int Height, std::string Title, std::function<void(Event&)> Event_Callback) : Window(Width, Height, Title, Event_Callback)
	{
		switch_GLFW(GLFW_status::ON);

		this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
		this->Use(true);

		glfwSetWindowUserPointer(this->window, this);

		this->RegisterEvents();
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(this->window);
		switch_GLFW(GLFW_status::OFF);
	}


	void WindowsWindow::SetSize(unsigned int Width, unsigned int Height)
	{
		this->width = Width;
		this->height = Height;
		glfwSetWindowSize(this->window, this->width, this->height);
	}


	void WindowsWindow::Use(bool vSync)
	{
		glfwMakeContextCurrent(this->window);
		glfwSwapInterval((vSync) ? 1 : 0);
	}
	void WindowsWindow::Update()
	{
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}



	inline bool WindowsWindow::IsKeyPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetKey(this->window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	inline bool WindowsWindow::IsMouseButtonPressed(KeyCodes::Keys& keycode)
	{
		int state = glfwGetMouseButton(this->window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS);
	}
	inline std::pair<float, float> WindowsWindow::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(this->window, &xpos, &ypos);
		return { (float)(xpos), (float)(ypos) };
	}
	inline float WindowsWindow::GetMouseX()
	{
		auto [x, y] = this->GetMousePosition();
		return(x);
	}
	inline float WindowsWindow::GetMouseY()
	{
		auto [x, y] = this->GetMousePosition();
		return(y);
	}
}