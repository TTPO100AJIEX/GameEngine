#include <PrecompiledHeaders.h>

#include "Render/RenderAPI.h"

#include "Engine.h"

#include "Window/Windows/WindowsWindow.h"

#include "Events/App.h"
#include "Events/Keyboard.h"
#include "Events/Mouse.h"
#include "Events/Window.h"

namespace GameEngine
{
	Engine::Engine()
	{
		ENGINE_WARN("Engine created!");

		#ifdef PLATFORM_WINDOWS
			this->l_Window = std::make_shared<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
			this->l_Window->Use(true);
		#else
			#error "One of [PLATFORM_WINDOWS] must be defined"
		#endif

		this->l_Renderer = RenderAPI::Create();
	}
	Engine::~Engine()
	{
		ENGINE_WARN("Engine destroyed!");
	}

	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		std::chrono::clock::time_point PrevTimestamp = std::chrono::clock::now();

		#ifdef DEBUG
			std::chrono::clock::time_point LastFPSOutputTimestamp = std::chrono::clock::now();
			int fps = 0;
		#endif

		while (this->Running) [[likely]]
		{
			std::chrono::clock::time_point NowTimestamp = std::chrono::clock::now();

			#ifdef DEBUG
				fps++;
				if (std::chrono::duration_cast<std::chrono::seconds>(NowTimestamp - LastFPSOutputTimestamp).count() >= 1)
				{
					ENGINE_TRACE("FPS: {0}", fps);
					fps = 0;
					LastFPSOutputTimestamp = std::chrono::clock::now();
				}
			#endif
			
			std::chrono::duration<double, std::nano> tmp = NowTimestamp - PrevTimestamp;
			AppTick AppTickEvent(tmp);
			this->OnEvent_Internal(AppTickEvent);

			PrevTimestamp = NowTimestamp;
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent_Internal(Event& event)
	{
		if (event.GetEventType() != EventTypes::WindowOpen) [[likely]] 
		{
			event.SetEngine(this->shared_from_this());
		}
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
				this->l_Window.reset();
				ENGINE_INFO("Window Destroyed ({0})! Running: {1}", event.ToString(), this->Running);
				break;
			}
			[[likely]] case (EventTypes::AppTick): 
			{
				this->l_Window->Update();
				if (!this->Running) [[unlikely]] { return; }
				[[fallthrough]];
			}
			[[likely]] default:
			{
				this->OnEvent(event);
			}
		}
	}
}