#pragma once

#include "Event.h"

namespace GameEngine
{
	class Window;
}

namespace GameEngine
{
	class WindowOpen : public Event
	{
	private:
		const int Width;
		const int Height;

		const Window* s_Window;

	public:
		WindowOpen(int width, int height, const Window* window)
			: Event(EventTypes::WindowOpen), Width(width), Height(height), s_Window(window) {};
		virtual ~WindowOpen() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "WindowOpen: " << Width << " " << Height;
				return(ss.str());
			}
		#endif

		const int GetWidth() { return(this->Width); };
		const int GetHeight() { return(this->Height); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class WindowResize : public Event
	{
	private:
		const int Width;
		const int Height;

		const Window* s_Window;

	public:
		WindowResize(int width, int height, const Window* window)
			: Event(EventTypes::WindowResize), Width(width), Height(height), s_Window(window) {};
		virtual ~WindowResize() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "WindowResize: " << Width << " " << Height;
				return(ss.str());
			}
		#endif

		const int GetWidth() { return(this->Width); };
		const int GetHeight() { return(this->Height); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class WindowClose : public Event
	{
	private:
		const Window* s_Window;

	public:
		WindowClose(const Window* window)
			: Event(EventTypes::WindowClose), s_Window(window) {};
		virtual ~WindowClose() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				return("WindowClose");
			}
		#endif
			
		const Window* GetWindow() { return(this->s_Window); }
	};
}