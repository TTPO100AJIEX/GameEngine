#include <PrecompiledHeaders.h>

#include "Time.h"

#define TO_DURATION2(type, value) std::chrono::duration_cast<std::chrono::duration<type>>(value)
#define TO_DURATION3(type1, type2, value) std::chrono::duration_cast<std::chrono::duration<type1, type2>>(value)
namespace GameEngine
{
	Time::Time(double ns) : nanoseconds(ns) {};
	template <typename Rep, typename Period> Time::Time(std::chrono::duration<Rep, Period>& duration) :
		nanoseconds(TO_DURATION3(double, std::nano, duration)) {};

	double Time::GetNanoseconds() const { return (this->nanoseconds.count()); }
	double Time::GetMicroseconds() const { return (TO_DURATION3(double, std::micro, this->nanoseconds).count()); }
	double Time::GetMilliseconds() const { return (TO_DURATION3(double, std::milli, this->nanoseconds).count()); }
	double Time::GetSeconds() const { return (TO_DURATION2(double, this->nanoseconds).count()); }

	std::ostream& operator<< (std::ostream& os, const Time& e)
	{
		os << e.GetNanoseconds() << "ns";
		return os;
	}
}
#undef TO_DURATION3
#undef TO_DURATION2