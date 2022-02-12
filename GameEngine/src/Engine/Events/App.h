#pragma once

#include "Events.h"

namespace GameEngine
{
	class AppTick : public Event
	{
	private:
		long long int FrameTime;
	public:
		AppTick(long long int frameTime) : Event(EventTypes::AppTick), FrameTime(frameTime) {};
		virtual ~AppTick() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "AppTick: " << FrameTime << "ns";
				return(ss.str());
			}
		#endif

		inline long long int GetFrameTime() { return(FrameTime); }
	};
}