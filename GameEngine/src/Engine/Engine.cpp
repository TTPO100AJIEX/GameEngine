#include <PrecompiledHeaders.h>

#include "Engine.h"

#include "Window/Windows/WindowsWindow.h"
#include "Renderer/OpenGL/OpenGLRenderer2D.h"
#include "Events/App.h"

namespace Engine
{
	Engine::Engine()
	{
		#ifdef PLATFORM_WINDOWS
			window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
		#else
			#error "One of [PLATFORM_WINDOWS] must be defined"
		#endif

		#ifdef RENDERER_USE_OPENGL
			renderer2D = std::make_unique<OpenGLRenderer2D>();
		#else
			#error "One of [RENDERER_USE_OPENGL] must be defined"
		#endif
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
			OnEvent_Internal(AppTickEvent);
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent_Internal(Event& event)
	{
		switch (event.GetEventType())
		{
			[[unlikely]] case (EventTypes::WindowOpen):
			{
				Running = true;
				ENGINE_INFO("Window Created ({0})! Running: {1}", event.ToString(), Running);
				break;
			}
			[[unlikely]] case (EventTypes::WindowClose):
			{
				Running = false;
				window.reset();
				ENGINE_INFO("Window Destroyed ({0})! Running: {1}", event.ToString(), Running);
				break;
			}
			[[likely]] case (EventTypes::AppTick): { window->Update(); [[fallthrough]]; }
			[[likely]] default:
			{
				OnEvent(event);
			}
		}
	}
}