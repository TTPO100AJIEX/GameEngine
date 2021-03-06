#pragma once

#include "Event.h"

namespace GameEngine
{
	class AppTick : public Event
	{
	private:
		Time FrameTime;

	public:
		AppTick(Time frameTime) : Event(EventTypes::AppTick), FrameTime(frameTime) {};
		virtual ~AppTick() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "AppTick: " << this->FrameTime;
				return(ss.str());
			}
		#endif

		Time GetFrameTime() { return(this->FrameTime); }
	};
}