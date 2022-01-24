#pragma once

#ifdef DEBUG
	#include <spdlog/spdlog.h>

	namespace Engine::Log
	{
		extern std::shared_ptr<spdlog::logger> EngineLogger;
		extern std::shared_ptr<spdlog::logger> GameLogger;

		extern void set_pattern(std::string pattern);
	}

	#define ENGINE_CRITICAL(...) ::Engine::Log::EngineLogger->critical(__VA_ARGS__)
	#define ENGINE_ERROR(...) ::Engine::Log::EngineLogger->error(__VA_ARGS__)
	#define ENGINE_WARN(...) ::Engine::Log::EngineLogger->warn(__VA_ARGS__)
	#define ENGINE_INFO(...) ::Engine::Log::EngineLogger->info(__VA_ARGS__)
	#define ENGINE_TRACE(...) ::Engine::Log::EngineLogger->trace(__VA_ARGS__)

	#define GAME_CRITICAL(...) ::Engine::Log::GameLogger->critical(__VA_ARGS__)
	#define GAME_ERROR(...) ::Engine::Log::GameLogger->error(__VA_ARGS__)
	#define GAME_WARN(...) ::Engine::Log::GameLogger->warn(__VA_ARGS__)
	#define GAME_INFO(...) ::Engine::Log::GameLogger->info(__VA_ARGS__)
	#define GAME_TRACE(...) ::Engine::Log::GameLogger->trace(__VA_ARGS__)
#else
	#define ENGINE_CRITICAL(...)
	#define ENGINE_ERROR(...)
	#define ENGINE_WARN(...)
	#define ENGINE_INFO(...)
	#define ENGINE_TRACE(...)

	#define GAME_CRITICAL(...)
	#define GAME_ERROR(...)
	#define GAME_WARN(...)
	#define GAME_INFO(...)
	#define GAME_TRACE(...)
#endif