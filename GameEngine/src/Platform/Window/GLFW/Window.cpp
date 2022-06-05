#include <PrecompiledHeaders.h>

#include <GLFW/glfw3.h>
#include <Platform/KeyCodes/GLFW/GLFW.h>

#include "Window.h"

namespace GameEngine
{
	class Event;
}

namespace GameEngine
{
	static void GLFWErrorCallback(int error, const char* description) { ENGINE_ERROR("GLFW Error {0}: {1}", error, description); }
	enum class GLFW_status : uint8_t { ON, OFF };
	static void switch_GLFW(GLFW_status status)
	{
		static unsigned int GLFW_initialization_count = 0;
		switch (status)
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
				glfwSetErrorCallback(GLFWErrorCallback);
				ENGINE_INFO("Initialized GLFW!");
				break;
			}
			case (GLFW_status::OFF):
			{
				GLFW_initialization_count--;
				if (GLFW_initialization_count > 0) return;
				glfwTerminate();
				ENGINE_INFO("Terminated GLFW!");
				break;
			}
			default: { ENGINE_WARN("switch_GLFW: weird status value {0}!", status); }
		}
	}

	
	Window::Window(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback) :
		Width(width), Height(height), Title(title), EventCallback(event_callback)
	{
		switch_GLFW(GLFW_status::ON);
		this->l_Window = glfwCreateWindow(this->Width, this->Height, this->Title.c_str(), NULL, NULL);
		glfwSetWindowUserPointer(this->l_Window, this);
		this->RegisterEvents();
	}
	Window::~Window()
	{
		glfwDestroyWindow(this->l_Window);
		switch_GLFW(GLFW_status::OFF);
	}

	void Window::Use(bool vSync) const
	{
		glfwMakeContextCurrent(this->l_Window);
		glfwSwapInterval(vSync ? 1 : 0);
	}
	const void* Window::GetProcAdressFunction()
	{
		return(glfwGetProcAddress);
	}

	std::pair<unsigned int, unsigned int> Window::GetSize() const
	{
		return(std::make_pair(this->Width, this->Height));
	}
	void Window::SetSize(unsigned int Width, unsigned int Height)
	{
		this->Width = Width;
		this->Height = Height;
		glfwSetWindowSize(this->l_Window, this->Width, this->Height);
	}


	void Window::Update()
	{
		glfwSwapBuffers(this->l_Window);
		glfwPollEvents();
	}


	bool Window::IsKeyPressed(const KeyCodes::Keys& keycode) const
	{
		int state = glfwGetKey(this->l_Window, KeyCodes::ToGLFW(keycode));
		return(state == GLFW_PRESS || state == GLFW_REPEAT);
	}
	bool Window::IsMouseButtonPressed(const KeyCodes::Keys& keycode) const
	{
		int state = glfwGetMouseButton(this->l_Window, KeyCodes::ToGLFW(keycode));
		return(state == GLFW_PRESS);
	}
	std::pair<double, double> Window::GetMousePosition() const
	{
		double xpos, ypos;
		glfwGetCursorPos(this->l_Window, &xpos, &ypos);
		return { xpos, ypos };
	}
	double Window::GetMouseX() const
	{
		return(this->GetMousePosition().first);
	}
	double Window::GetMouseY() const
	{
		return(this->GetMousePosition().second);
	}
}