#pragma once

#include "Events.h"

namespace GameEngine
{
	class WindowOpen : public Event
	{
	private:
		const int Width;
		const int Height;

	public:
		WindowOpen(int width, int height) : Event(EventTypes::WindowOpen), Width(width), Height(height) {};
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
	};

	class WindowResize : public Event
	{
	private:
		const int Width;
		const int Height;

	public:
		WindowResize(int width, int height) : Event(EventTypes::WindowResize), Width(width), Height(height) {};
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
	};

	class WindowClose : public Event
	{
	public:
		WindowClose() : Event(EventTypes::WindowClose) {};
		virtual ~WindowClose() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				return("WindowClose");
			}
		#endif
	};
}