#pragma once

#include "Events.h"

namespace GameEngine
{
	class AppTick : public Event
	{
	private:
	public:
		AppTick() : Event(EventTypes::AppTick) {};
		virtual ~AppTick() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				return("AppTick");
			}
		#endif
	};
}