#pragma once

#include "Events.h"

namespace GameEngine
{
	class AppTick : public Event
	{
	private:
		unsigned long long int FrameTime;
	public:
		AppTick(unsigned long long int frameTime) : Event(EventTypes::AppTick), FrameTime(frameTime) {};
		virtual ~AppTick() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "AppTick: " << FrameTime << "ns";
				return(ss.str());
			}
		#endif
	};
}