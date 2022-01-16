#pragma once

namespace Engine
{
	enum class EventTypes
	{
		None = 0,
		WindowOpen, WindowResize, WindowClose,
		KeyPress, KeyRelease, KeyType,
		MouseMove, MouseScroll, MouseButtonPress, MouseButtonRelease
	};

	class API Event
	{

	protected:
		bool handled = false;
		EventTypes EventType;

	public:
		inline EventTypes GetEventType() { return(EventType); }

		#ifdef DEBUG
			virtual std::string ToString() const = 0;
		#endif

		inline bool IsHandled() { return(handled); }
	};
}