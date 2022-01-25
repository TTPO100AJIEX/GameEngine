#pragma once

namespace Engine
{
	enum class EventTypes
	{
		None = 0,
		WindowOpen, WindowResize, WindowClose,
		AppTick,
		KeyPress, KeyRelease, KeyType,
		MouseMove, MouseScroll, MouseButtonPress, MouseButtonRelease
	};

	class Event
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