#pragma once

namespace GameEngine
{
	enum class EventTypes : uint8_t
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
		const EventTypes EventType;

	public:
		Event(EventTypes eventType) : EventType(eventType) {};
		virtual ~Event() = default;

		inline EventTypes GetEventType() const { return(EventType); }

		#ifdef DEBUG
			virtual std::string ToString() const = 0;
		#endif

		inline bool IsHandled() const { return(handled); }
	};
}