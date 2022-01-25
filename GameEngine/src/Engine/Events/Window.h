#pragma once

#include "Events.h"

namespace Engine
{
	class WindowOpen : public Event
	{
	private:
		int Width;
		int Height;

	public:
		WindowOpen(int width, int height) : Width(width), Height(height) { EventType = EventTypes::WindowOpen; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "WindowOpen: " << Width << " " << Height;
				return(ss.str());
			}
		#endif
	};

	class WindowResize : public Event
	{
	private:
		int Width;
		int Height;

	public:
		WindowResize(int width, int height) : Width(width), Height(height) { EventType = EventTypes::WindowResize; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "WindowResize: " << Width << " " << Height;
				return(ss.str());
			}
		#endif
	};

	class WindowClose : public Event
	{
	public:
		WindowClose() { EventType = EventTypes::WindowClose; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				return("WindowClose");
			}
		#endif
	};
}