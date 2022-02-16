#pragma once

namespace std::chrono
{
	using clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady, std::chrono::high_resolution_clock, std::chrono::steady_clock>;
}

#define TO_DURATION3(type1, type2, value) std::chrono::duration_cast<std::chrono::duration<type1, type2>>(value)
#define TO_DURATION2(type, value) std::chrono::duration_cast<std::chrono::duration<type>>(value)
namespace GameEngine
{
	class Time
	{
	private:
		std::chrono::duration<double, std::nano> nanoseconds;

	public:
		Time(double ns) : nanoseconds(ns) {};

		template <typename Rep, typename Period> Time(std::chrono::duration<Rep, Period>& duration) :
			nanoseconds(TO_DURATION3(double, std::nano, duration)) {};

		inline double GetNanoseconds() const { return (this->nanoseconds.count()); }
		inline double GetMicroseconds() const { return (TO_DURATION3(double, std::micro, this->nanoseconds).count()); }
		inline double GetMilliseconds() const { return (TO_DURATION3(double, std::milli, this->nanoseconds).count()); }
		inline double GetSeconds() const { return (TO_DURATION2(double, this->nanoseconds).count()); }

		static inline friend std::ostream& operator<< (std::ostream& os, const Time& e)
		{
			os << e.GetNanoseconds() << "ns";
			return os;
		}
	};
}
#undef TO_DURATION3
#undef TO_DURATION2