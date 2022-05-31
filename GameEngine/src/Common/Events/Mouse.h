#pragma once

#include "Event.h"

namespace GameEngine
{
	class Window;
}

namespace GameEngine
{
	class MouseMove : public Event
	{
	private:
		const double X;
		const double Y;

		const Window* s_Window;

	public:
		MouseMove(double x, double y, const Window* window)
			: Event(EventTypes::MouseMove), X(x), Y(y), s_Window(window) {};
		virtual ~MouseMove() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMove: " << X << " " << Y;
				return(ss.str());
			}
		#endif

		const double GetX() { return(this->X); };
		const double GetY() { return(this->Y); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class MouseScroll : public Event
	{
	private:
		const double X;
		const double Y;

		const Window* s_Window;

	public:
		MouseScroll(double x, double y, const Window* window)
			: Event(EventTypes::MouseScroll), X(x), Y(y), s_Window(window) {};
		virtual ~MouseScroll() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScroll: " << X << " " << Y;
				return(ss.str());
			}
		#endif

		const double GetX() { return(this->X); };
		const double GetY() { return(this->Y); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class MouseButtonPress : public Event
	{
	private:
		const KeyCodes::Keys Key;

		const Window* s_Window;

	public:
		MouseButtonPress(KeyCodes::Keys key, const Window* window)
			: Event(EventTypes::MouseButtonPress), Key(key), s_Window(window) {};
		virtual ~MouseButtonPress() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPress: " << KeyCodes::ToString(Key) << " ";
				return(ss.str());
			}
		#endif

		const KeyCodes::Keys& GetKey() { return(this->Key); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class MouseButtonRelease : public Event
	{
	private:
		const KeyCodes::Keys Key;

		const Window* s_Window;

	public:
		MouseButtonRelease(KeyCodes::Keys key, const Window* window)
			: Event(EventTypes::MouseButtonRelease), Key(key), s_Window(window) {};
		virtual ~MouseButtonRelease() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonRelease: " << KeyCodes::ToString(Key) << " ";
				return(ss.str());
			}
		#endif

		const KeyCodes::Keys& GetKey() { return(this->Key); };

		const Window* GetWindow() { return(this->s_Window); }
	};
}