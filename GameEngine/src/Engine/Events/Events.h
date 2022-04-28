#pragma once

#include "../Engine.h" //circular dependency

namespace GameEngine
{
	//class Engine; //does not help

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

		//std::optional<const std::shared_ptr<Engine>> s_Engine;
		std::shared_ptr<Engine> s_Engine;

	public:
		Event(EventTypes eventType) : EventType(eventType) {};
		virtual ~Event() = default;

		EventTypes GetEventType() const { return(EventType); }

		#ifdef DEBUG
			virtual std::string ToString() const = 0;
		#endif

		void SetEngine(std::shared_ptr<Engine> engine)
		{
			this->s_Engine = engine;
		}
		std::shared_ptr<Engine>& GetEngine()
		{
			return(this->s_Engine);
		}
	};
}