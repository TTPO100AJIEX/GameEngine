#include <PrecompiledHeaders.h>

#include <GLFW/glfw3.h>
#include "../../Core/KeyCodes/GLFW/GLFW.h"

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
		static unsigned int GLFW_initialization_count = 0;
		switch(status)
		{
			case (GLFW_status::ON):
			{
				GLFW_initialization_count++;
				if (GLFW_initialization_count > 1) return;
				if (!glfwInit()) [[unlikely]]
				{
					ENGINE_CRITICAL("Failed to initialize GLFW!");
					return;
				}
				ENGINE_WARN("Initialized GLFW!");
				glfwSetErrorCallback(GLFWErrorCallback);
				break;
			}
			case (GLFW_status::OFF):
			{
				GLFW_initialization_count--;
				if (GLFW_initialization_count > 0) return;
				glfwTerminate();
				ENGINE_WARN("Terminated GLFW!");
				break;
			}
			default: 
			{
				ENGINE_WARN("switch_GLFW: weird status value {0}!", status);
			}
		}
	}


	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback) : Window(width, height, title, event_callback)
	{
		switch_GLFW(GLFW_status::ON);

		this->l_Window = glfwCreateWindow(this->Width, this->Height, this->Title.c_str(), NULL, NULL);

		glfwSetWindowUserPointer(this->l_Window, this);

		this->RegisterEvents();
	}
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(this->l_Window);
		switch_GLFW(GLFW_status::OFF);
	}

	void WindowsWindow::Use(bool vSync) const
	{
		glfwMakeContextCurrent(this->l_Window);
		glfwSwapInterval((vSync) ? 1 : 0);
	}
	const void* WindowsWindow::GetProcAdressFunction() const
	{
		return(glfwGetProcAddress);
	}

	void WindowsWindow::SetSize(unsigned int Width, unsigned int Height)
	{
		this->Width = Width;
		this->Height = Height;
		glfwSetWindowSize(this->l_Window, this->Width, this->Height);
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