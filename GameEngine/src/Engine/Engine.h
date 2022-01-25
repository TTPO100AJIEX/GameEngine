#pragma once

#include "Window/Window.h"
#include "Renderer/Renderer2D.h"
#include "Events/Events.h"

namespace Engine
{
	class Engine
	{
	private:
		std::unique_ptr<Window> window;
		std::unique_ptr<Renderer2D> renderer2D;
		bool Running = false;

	public:
		Engine();
		~Engine();

		inline std::unique_ptr<Window>& GetWindow() { return(window); }
		inline std::unique_ptr<Renderer2D>& GetRenderer2D() { return(renderer2D); }

		void Run();

		void OnEvent_Internal(Event& event);
		virtual void OnEvent(Event& event) = 0;
	};

	//To be defined in client
	Engine* CreateGame();
}