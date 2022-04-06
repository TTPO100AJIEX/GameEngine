#pragma once

#include "Render/RenderAPI.h"

#include "Window/Window.h"
#include "Render/General/Renderer.h"

#include "Events/App.h"
#include "Events/Keyboard.h"
#include "Events/Mouse.h"
#include "Events/Window.h"

namespace GameEngine
{
	class Engine
	{
	private:
		std::unique_ptr<Window> l_Window;
		std::shared_ptr<Renderer> l_Renderer;
		bool Running = false;

	public:
		Engine();
		virtual ~Engine();

		inline const std::unique_ptr<Window>& GetWindow() const { return(this->l_Window); }
		inline const std::shared_ptr<Renderer>& GetRenderer() const { return(this->l_Renderer); }

		void Run();

		void OnEvent_Internal(Event& event);
		virtual void OnEvent(Event& event) = 0;
	};

	//To be defined in client
	Engine* CreateGame();
}