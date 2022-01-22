#include <PrecompiledHeaders.h>

#include "Engine.h"

namespace Engine
{
	Engine::Engine()
	{

	}

	Engine::~Engine()
	{

	}

	void Engine::Run()
	{
		ENGINE_INFO("Started!");

		#ifdef PLATFORM_WINDOWS
			Window = std::make_unique<WindowsWindow>(1280, 720, "Hello world", std::bind(&Engine::OnEvent, this, std::placeholders::_1));
			//If no callback is specified, Running should be manually set to true
		#endif

		while (Running)
		{
			Window->StartUpdate();

			for (std::vector <Layer*>::iterator i = Layers.begin(); i != Layers.end(); i++)
			{
				(*i)->Update();
			}
			Window->Update();

			Window->FinishUpdate();
		}

		ENGINE_INFO("Terminated!");
	}

	void Engine::OnEvent(Event& New_Event)
	{
		switch (New_Event.GetEventType())
		{
			[[unlikely]] case(EventTypes::WindowOpen):
			{
				Running = true;
				ENGINE_INFO("Window Created! Running: {0}", Running);
				break;
			}
			[[unlikely]] case (EventTypes::WindowClose):
			{
				Running = false;
				ENGINE_INFO("Window Destroyed! Running: {0}", Running);
				break;
			}
			[[likely]] default:
			{
				ENGINE_TRACE("{0}", New_Event.ToString());

				for (std::vector <Layer*>::reverse_iterator i = Layers.rbegin(); i != Layers.rend(); i++)
				{
					(*i)->OnEvent(New_Event);
					if (New_Event.IsHandled()) break;
				}
			}
		}
	}

	
	void Engine::RegisterLayer(Layer* layer, int index)
	{
		Layers.Push(layer, index);
	}
	void Engine::RemoveLayer(unsigned int index)
	{
		Layers.Remove(index);
	}

	/**/inline bool Engine::IsKeyPressed(KeyCodes::Keys keycode) { return(Window->IsKeyPressed(keycode)); }
	inline bool Engine::IsMouseButtonPressed(KeyCodes::Keys keycode) { return(Window->IsMouseButtonPressed(keycode)); }
	inline std::pair<double, double> Engine::GetMousePosition() { return(Window->GetMousePosition()); }
	inline double Engine::GetMouseX() { return(Window->GetMouseX()); }
	inline double Engine::GetMouseY() { return(Window->GetMouseY()); }
}