#include <PrecompiledHeaders.h>

#include "Engine.h"


#ifdef PLATFORM_WINDOWS
	#include "Window/Windows/WindowsWindow.h"
#endif

#include "Render/RenderAPI.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/App.h"
#include "Engine/Events/Keyboard.h"
#include "Engine/Events/Mouse.h"
#include "Engine/Events/Window.h"


namespace GameEngine
{
	Engine::Engine()
	{
		ENGINE_WARN("Engine created!");

		#ifdef PLATFORM_WINDOWS
			this->l_Window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
		#else
			#error "One of [PLATFORM_WINDOWS] must be defined"
		#endif
		this->l_Window->Use(false);

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
			
			std::chrono::duration<double, std::nano> delta_time = NowTimestamp - PrevTimestamp;
			AppTick AppTickEvent(delta_time);
			this->OnEvent_Internal(AppTickEvent);

			PrevTimestamp = NowTimestamp;
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent_Internal(Event& event)
	{
		event.SetEngine(this);
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
			[[unlikely]] case (EventTypes::WindowResize):
			{
				GameEngine::WindowResize& ev = static_cast<GameEngine::WindowResize&>(event);
				if (ev.GetHeight() == 0 || ev.GetWidth() == 0)
				{
					this->Minimized = true;
					this->OnEvent(event);
					ENGINE_WARN("Window has been minimized: {0}", ev.ToString());
					break;
				}
				this->l_Renderer->SetViewport(0, 0, ev.GetWidth(), ev.GetHeight());
				this->Minimized = false;
				this->OnEvent(event);
				break;
			}
			[[likely]] case (EventTypes::AppTick): 
			{
				this->l_Window->Update();
				if (this->Minimized || !this->Running) [[unlikely]] { break; }
				[[fallthrough]];
			}
			[[likely]] default:
			{
				this->OnEvent(event);
			}
		}
	}
}