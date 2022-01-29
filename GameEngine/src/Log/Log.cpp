#include <PrecompiledHeaders.h>

#ifdef DEBUG
	#include <spdlog/sinks/stdout_color_sinks.h>

	namespace GameEngine::Log
	{
		std::shared_ptr<spdlog::logger> EngineLogger = spdlog::stdout_color_mt("Engine");
		std::shared_ptr<spdlog::logger> GameLogger = spdlog::stdout_color_mt("Game");

		void set_pattern(std::string pattern)
		{
			spdlog::set_pattern(pattern);
			EngineLogger->set_level(spdlog::level::trace);
			GameLogger->set_level(spdlog::level::trace);
		}
	}
#endif