#include <PrecompiledHeaders.h>

#include "Engine.h"

#include "Window/Windows/WindowsWindow.h"
#include "Events/App.h"

namespace Engine
{
	Engine::Engine()
	{
		window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
		//renderer2D = std::make_unique<OpenGLRenderer2D>()
	}
	Engine::~Engine()
	{

	}

	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		//m_Window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));

		while (Running)
		{
			AppTick AppTickEvent;
			OnEvent_Internal(AppTickEvent);
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent_Internal(Event& event)
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
				Running = false;
				window.reset();
				ENGINE_INFO("Window Destroyed ({0})! Running: {1}", event.ToString(), Running);
				break;
			}
			case (EventTypes::AppTick): { window->Update(); [[fallthrough]]; }
			default:
			{
				OnEvent(event);
			}
		}
	}
}