#include <PrecompiledHeaders.h>

#include "Engine/Engine.h"

#ifdef PLATFORM_WINDOWS

	int main(int argc, char** argv)
	{
		#ifdef DEBUG
			GameEngine::Log::set_pattern("[%d-%m-%Y %T.%e] [%n]-[%L:%l] %^%v%$");
			ENGINE_WARN("Initialized log!");
		#endif

		std::shared_ptr<GameEngine::Engine> game = GameEngine::CreateGame();
		game->Run();

		return 0;
	}

#endif