#pragma once

#include "Renderer/RendererAPI.h"

#include "Window/Window.h"
#include "Renderer/General/Renderer2D.h"
#include "Events/Events.h"

namespace GameEngine
{
	class Engine
	{
	private:
		std::unique_ptr<Window> l_Window;
		std::shared_ptr<Renderer2D> l_Renderer2D;
		bool Running = false;

	public:
		Engine();
		virtual ~Engine();

		inline const std::unique_ptr<Window>& GetWindow() const { return(l_Window); }
		inline const std::shared_ptr<Renderer2D>& GetRenderer2D() const { return(l_Renderer2D); }

		void Run();

		void OnEvent_Internal(Event& event);
		virtual void OnEvent(Event& event) = 0;
	};

	//To be defined in client
	Engine* CreateGame();
}