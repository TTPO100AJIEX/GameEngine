#include <PrecompiledHeaders.h>

#include "Engine.h"
#include "Window/Windows/WindowsWindow.h"

#include "Events/App.h"

namespace Engine
{
	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		m_Window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent, this, std::placeholders::_1));

		while (Running)
		{
			AppTick AppTickEvent;
			OnEvent(AppTickEvent);
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
			case (EventTypes::WindowOpen):
			{
				Running = true;
				ENGINE_INFO("Window Created ({0})! Running: {1}", event.ToString(), Running);
				break;
			}
			case (EventTypes::WindowClose):
			{
				ENGINE_INFO("Window Destroyed ({0})! Running: {1}", event.ToString(), Running);
				m_Window.reset();
				Running = false;
				break;
			}
			default:
			{
				m_Window->OnEvent(event);
			}
		}
	}
}