#include <PrecompiledHeaders.h>

#include "WindowsWindow.h"

namespace GameEngine
{
	static void GLFWErrorCallback(int error, const char *description)
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


	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback) : Window(width, height, title, event_callback)
	{
		switch_GLFW(GLFW_status::ON);

		this->l_Window = glfwCreateWindow(this->Width, this->Height, this->Title.c_str(), NULL, NULL);
		this->Use(true);

		glfwSetWindowUserPointer(this->l_Window, this);

		this->RegisterEvents();
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(this->l_Window);
		switch_GLFW(GLFW_status::OFF);
	}


	void WindowsWindow::SetSize(unsigned int Width, unsigned int Height)
	{
		this->Width = Width;
		this->Height = Height;
		glfwSetWindowSize(this->l_Window, this->Width, this->Height);
	}


	void WindowsWindow::Use(bool vSync) const
	{
		glfwMakeContextCurrent(this->l_Window);
		glfwSwapInterval((vSync) ? 1 : 0);
	}
	void WindowsWindow::Update()
	{
		glfwSwapBuffers(this->l_Window);
		glfwPollEvents();
	}



	bool WindowsWindow::IsKeyPressed(const KeyCodes::Keys& keycode) const
	{
		int state = glfwGetKey(this->l_Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	bool WindowsWindow::IsMouseButtonPressed(const KeyCodes::Keys& keycode) const
	{
		int state = glfwGetMouseButton(this->l_Window, static_cast<int>(KeyCodes::ToGLFW(keycode)));
		return(state == GLFW_PRESS);
	}
	std::pair<float, float> WindowsWindow::GetMousePosition() const
	{
		double xpos, ypos;
		glfwGetCursorPos(this->l_Window, &xpos, &ypos);
		return { (float)(xpos), (float)(ypos) };
	}
	float WindowsWindow::GetMouseX() const
	{
		auto [x, y] = this->GetMousePosition();
		return(x);
	}
	float WindowsWindow::GetMouseY() const
	{
		auto [x, y] = this->GetMousePosition();
		return(y);
	}
}