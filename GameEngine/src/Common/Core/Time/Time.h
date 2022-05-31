#pragma once

namespace std::chrono
{
	using clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady, std::chrono::high_resolution_clock, std::chrono::steady_clock>;
}

namespace GameEngine
{
	class Time
	{
	private:
		std::chrono::duration<double, std::nano> nanoseconds;

	public:
		Time(double ns);
		template <typename Rep, typename Period> Time(std::chrono::duration<Rep, Period>& duration);
		~Time() = default;

		double GetNanoseconds() const;
		double GetMicroseconds() const;
		double GetMilliseconds() const;
		double GetSeconds() const;

		friend std::ostream& operator<< (std::ostream& os, const Time& e);
	};
}