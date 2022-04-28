#pragma once

namespace GameEngine
{
	class Window;
	class Renderer;
	class Event;
}

namespace GameEngine
{
	class Engine
	{
	private:
		std::unique_ptr<Window> l_Window;
		std::unique_ptr<Renderer> l_Renderer;
		bool Running = false;

	public:
		static std::unique_ptr<Engine> CreateGame(); //To be defined in client


		Engine();
		virtual ~Engine();

		Window* GetWindow() const { return(this->l_Window.get()); }
		Renderer* GetRenderer() const { return(this->l_Renderer.get()); }

		void Run();

		void OnEvent_Internal(Event& event);
		virtual void OnEvent(Event& event) = 0;
	};

}