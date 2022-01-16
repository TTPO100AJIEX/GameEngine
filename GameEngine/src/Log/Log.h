#pragma once

#ifdef DEBUG
	#include <Engine/Definitions/Core.h>

	#include <spdlog/spdlog.h>

	namespace Engine
	{
		class API Log
		{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return (EngineLogger); }
			inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return (GameLogger); }

		private:
			static std::shared_ptr<spdlog::logger> EngineLogger;
			static std::shared_ptr<spdlog::logger> GameLogger;
		};
	}

	#define ENGINE_CRITICAL(...) ::Engine::Log::GetEngineLogger()->critical(__VA_ARGS__)
	#define ENGINE_ERROR(...) ::Engine::Log::GetEngineLogger()->error(__VA_ARGS__)
	#define ENGINE_WARN(...) ::Engine::Log::GetEngineLogger()->warn(__VA_ARGS__)
	#define ENGINE_INFO(...) ::Engine::Log::GetEngineLogger()->info(__VA_ARGS__)
	#define ENGINE_TRACE(...) ::Engine::Log::GetEngineLogger()->trace(__VA_ARGS__)

	#define GAME_CRITICAL(...) ::Engine::Log::GetGameLogger()->critical(__VA_ARGS__)
	#define GAME_ERROR(...) ::Engine::Log::GetGameLogger()->error(__VA_ARGS__)
	#define GAME_WARN(...) ::Engine::Log::GetGameLogger()->warn(__VA_ARGS__)
	#define GAME_INFO(...) ::Engine::Log::GetGameLogger()->info(__VA_ARGS__)
	#define GAME_TRACE(...) ::Engine::Log::GetGameLogger()->trace(__VA_ARGS__)
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