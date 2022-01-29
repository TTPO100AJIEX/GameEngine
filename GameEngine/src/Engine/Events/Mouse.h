#pragma once

#include "Events.h"
#include "../Definitions/KeyCodes/KeyCodes.h"

namespace GameEngine
{
	class MouseMove : public Event
	{
	private:
		const double X;
		const double Y;

	public:
		MouseMove(double x, double y) : Event(EventTypes::MouseMove), X(x), Y(y) {};
		virtual ~MouseMove() = default;

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
		const double X;
		const double Y;

	public:
		MouseScroll(double x, double y) : Event(EventTypes::MouseScroll), X(x), Y(y) {};
		virtual ~MouseScroll() = default;

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
		const KeyCodes::Keys Key;

	public:
		MouseButtonPress(KeyCodes::Keys key) : Event(EventTypes::MouseButtonPress), Key(key) {};
		virtual ~MouseButtonPress() = default;

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
		const KeyCodes::Keys Key;

	public:
		MouseButtonRelease(KeyCodes::Keys key) : Event(EventTypes::MouseButtonRelease), Key(key) {};
		virtual ~MouseButtonRelease() = default;

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