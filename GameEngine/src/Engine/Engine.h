#pragma once

#include "Window/Windows/WindowsWindow.h"
#include "Events/Events.h"
#include "Layers/Layer/Layer.h"
#include "Layers/LayersList/LayersList.h"

namespace Engine
{
	class API Engine
	{
	private:
		#ifdef PLATFORM_WINDOWS
			std::unique_ptr<WindowsWindow> Window;
		#endif
		bool Running = false;
		LayersList Layers;

	public:
		Engine();
		~Engine();

		void Run();

		void OnEvent(Event& New_Event);

		void RegisterLayer(Layer* layer, int index);
		void RemoveLayer(unsigned int index);

		inline bool IsKeyPressed(KeyCodes::Keys keycode);
		inline bool IsMouseButtonPressed(KeyCodes::Keys keycode);
		inline std::pair<double, double> GetMousePosition();
		inline double GetMouseX();
		inline double GetMouseY();
	};

	//To be defined in client
	Engine* CreateGame();
}