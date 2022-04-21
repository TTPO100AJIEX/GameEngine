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
		const EventTypes EventType;

	public:
		Event(EventTypes eventType) : EventType(eventType) {};
		virtual ~Event() = default;

		EventTypes GetEventType() const { return(EventType); }

		#ifdef DEBUG
			virtual std::string ToString() const = 0;
		#endif
	};
}