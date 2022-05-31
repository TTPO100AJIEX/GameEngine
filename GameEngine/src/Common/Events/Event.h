#pragma once

namespace GameEngine
{
	class Engine;
}

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

		std::optional<const Engine*> s_Engine;

	public:
		Event(EventTypes eventType) : EventType(eventType) {};
		virtual ~Event() = default;

		EventTypes GetEventType() const { return(EventType); }

		#ifdef DEBUG
			virtual std::string ToString() const = 0;
		#endif

		void SetEngine(const Engine* engine)
		{
			#ifdef DEBUG
				if (this->s_Engine.has_value()) [[unlikely]] { ENGINE_WARN("SetEngine used on Event that already has s_Engine defined!"); }
			#endif
			this->s_Engine = engine;
		}
		const Engine* GetEngine()
		{
			#ifdef DEBUG
				if (!this->s_Engine.has_value()) [[unlikely]] { ENGINE_WARN("GetEngine used on Event that does not have s_Engine defined!"); }
			#endif
			return(this->s_Engine.value_or(nullptr));
		}
	};
}