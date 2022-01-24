#pragma once

#include "../Definitions/KeyCodes/KeyCodes.h"
#include "../Events/Events.h"
#include "../Renderer/Context.h"

namespace Engine
{
	class Window
	{
	protected:
		std::shared_ptr<Renderer::Context> RenderingContext;

		struct windowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			std::function<void(Event&)> Callback;
		};
		windowData WindowData;

	public:
		virtual ~Window() = default;

		virtual void RegisterEvents() = 0;
		virtual void OnEvent(Event& event) = 0;

		
		virtual inline bool IsKeyPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline bool IsMouseButtonPressed(KeyCodes::Keys& keycode) = 0;
		virtual inline std::pair<double, double> GetMousePosition() = 0;
		virtual inline double GetMouseX() = 0;
		virtual inline double GetMouseY() = 0;
	};
}