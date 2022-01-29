#include <PrecompiledHeaders.h>

#include "Engine.h"

#include "Renderer/RendererAPI.h"

#include "Window/Windows/WindowsWindow.h"
#include "Events/App.h"

namespace GameEngine
{
	Engine::Engine()
	{
		#ifdef PLATFORM_WINDOWS
			this->window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
		#else
			#error "One of [PLATFORM_WINDOWS] must be defined"
		#endif

		this->renderer2D = RendererAPI::CreateRenderer();
	}
	Engine::~Engine()
	{

	}

	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		while (Running) [[likely]]
		{
			AppTick AppTickEvent;
			this->OnEvent_Internal(AppTickEvent);
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent_Internal(Event& event)
	{
		switch (event.GetEventType())
		{
			[[unlikely]] case (EventTypes::WindowOpen):
			{
				this->Running = true;
				ENGINE_INFO("Window Created ({0})! Running: {1}", event.ToString(), this->Running);
				break;
			}
			[[unlikely]] case (EventTypes::WindowClose):
			{
				this->Running = false;
				this->window.reset();
				ENGINE_INFO("Window Destroyed ({0})! Running: {1}", event.ToString(), this->Running);
				break;
			}
			[[likely]] case (EventTypes::AppTick): { this->window->Update(); [[fallthrough]]; }
			[[likely]] default:
			{
				this->OnEvent(event);
			}
		}
	}
}