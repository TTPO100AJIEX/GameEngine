#include <PrecompiledHeaders.h>

#ifdef DEBUG
	#include <spdlog/sinks/stdout_color_sinks.h>

	namespace Engine
	{
		std::shared_ptr<spdlog::logger> Log::EngineLogger;
		std::shared_ptr<spdlog::logger> Log::GameLogger;

		void Log::Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");

			EngineLogger = spdlog::stdout_color_mt("Engine");
			EngineLogger->set_level(spdlog::level::trace);

			GameLogger = spdlog::stdout_color_mt("Game");
			GameLogger->set_level(spdlog::level::trace);
		}
	}
#endif