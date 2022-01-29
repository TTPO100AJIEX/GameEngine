#pragma once

#include "Events.h"

namespace GameEngine
{
	class AppTick : public Event
	{
	private:
	public:
		AppTick() { EventType = EventTypes::AppTick; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				return("AppTick");
			}
		#endif
	};
}