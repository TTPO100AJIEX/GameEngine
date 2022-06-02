#include <PrecompiledHeaders.h>

#include "Engine.h"

#include "Events/Event.h"
#include "Events/App.h"
#include "Events/Keyboard.h"
#include "Events/Mouse.h"
#include "Events/Window.h"

#include <Platform/Window/Window.h>
#include <Platform/Renderer/Renderer.h>

namespace GameEngine
{
	Engine::Engine()
	{
		ENGINE_INFO("Engine created!");
		this->l_Window = std::make_unique<Window>(1280, 720, "Hello world", std::bind(&Engine::OnEvent_Internal, this, std::placeholders::_1));
		this->l_Window->Use(true);

		/*this->l_Renderer = RenderAPI::Create(this->l_Window->GetProcAdressFunction());*/
	}
	Engine::~Engine()
	{
		ENGINE_INFO("Engine destroyed!");
	}

	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		std::chrono::clock::time_point PrevTimestamp = std::chrono::clock::now();

		#ifdef DEBUG
			std::chrono::clock::time_point LastFPSOutputTimestamp = std::chrono::clock::now();
			unsigned int fps = 0;
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
			
			AppTick AppTickEvent { NowTimestamp - PrevTimestamp };
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
				/*GameEngine::WindowResize& ev = static_cast<GameEngine::WindowResize&>(event);
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
				break;*/
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