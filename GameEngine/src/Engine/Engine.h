#pragma once

#include "Window/Window.h"
#include "Events/Events.h"

namespace Engine
{
	class Engine
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool Running = false;

	public:
		inline std::unique_ptr<Window>& GetWindow() { return(m_Window); }

		void Run();

		void OnEvent(Event& event);
	};

	//To be defined in client
	Engine* CreateGame();
}