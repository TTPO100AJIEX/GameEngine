#pragma once

#ifdef DEBUG
	#include <spdlog/spdlog.h>

	namespace GameEngine::Log
	{
		extern std::shared_ptr<spdlog::logger> EngineLogger;
		extern std::shared_ptr<spdlog::logger> GameLogger;

		extern void set_pattern(std::string pattern);
	}

	#define ENGINE_CRITICAL(...) ::GameEngine::Log::EngineLogger->critical(__VA_ARGS__)
	#define ENGINE_ERROR(...) ::GameEngine::Log::EngineLogger->error(__VA_ARGS__)
	#define ENGINE_WARN(...) ::GameEngine::Log::EngineLogger->warn(__VA_ARGS__)
	#define ENGINE_INFO(...) ::GameEngine::Log::EngineLogger->info(__VA_ARGS__)
	#define ENGINE_TRACE(...) ::GameEngine::Log::EngineLogger->trace(__VA_ARGS__)

	#define GAME_CRITICAL(...) ::GameEngine::Log::GameLogger->critical(__VA_ARGS__)
	#define GAME_ERROR(...) ::GameEngine::Log::GameLogger->error(__VA_ARGS__)
	#define GAME_WARN(...) ::GameEngine::Log::GameLogger->warn(__VA_ARGS__)
	#define GAME_INFO(...) ::GameEngine::Log::GameLogger->info(__VA_ARGS__)
	#define GAME_TRACE(...) ::GameEngine::Log::GameLogger->trace(__VA_ARGS__)
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