#pragma once

#include "Events.h"

namespace Engine
{
	class MouseMove : public Event
	{
	private:
		double X;
		double Y;
	public:
		MouseMove(double x, double y) : X(x), Y(y) { EventType = EventTypes::MouseMove; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMove: " << X << " " << Y;
				return(ss.str());
			}
		#endif
	};

	class MouseScroll : public Event
	{
	private:
		double X;
		double Y;
	public:
		MouseScroll(double x, double y) : X(x), Y(y) { EventType = EventTypes::MouseScroll; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScroll: " << X << " " << Y;
				return(ss.str());
			}
		#endif
	};

	class MouseButtonPress : public Event
	{
	private:
		KeyCodes::Keys Key;
	public:
		MouseButtonPress(KeyCodes::Keys key) : Key(key) { EventType = EventTypes::MouseButtonPress; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPress: " << KeyCodes::ToString(Key) << " ";
				return(ss.str());
			}
		#endif
	};

	class MouseButtonRelease : public Event
	{
	private:
		KeyCodes::Keys Key;
	public:
		MouseButtonRelease(KeyCodes::Keys key) : Key(key) { EventType = EventTypes::MouseButtonRelease; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonRelease: " << KeyCodes::ToString(Key) << " ";
				return(ss.str());
			}
		#endif
	};
}