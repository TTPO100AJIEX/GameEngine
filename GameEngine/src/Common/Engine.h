#pragma once

namespace GameEngine
{
	//class Window;
	class Event;
}

namespace GameEngine
{
	class Engine
	{
	private:
		//std::unique_ptr<Window> l_Window;
		bool Running = false;
		bool Minimized = false;

	public:
		Engine();
		virtual ~Engine();

		//Window* GetWindow() const { return(this->l_Window.get()); }

		void Run();

		void OnEvent_Internal(Event& event);
		virtual void OnEvent(Event& event) = 0;
	};
}