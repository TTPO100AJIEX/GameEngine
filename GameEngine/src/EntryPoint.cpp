#include <PrecompiledHeaders.h>

#include "Engine/Engine.h"

#ifdef PLATFORM_WINDOWS

	int main(int argc, char** argv)
	{
		#ifdef DEBUG
			Engine::Log::set_pattern("[%d-%m-%Y %T.%e] [%n]-[%L:%l] %^%v%$");
			ENGINE_WARN("Initialized log!");
		#endif

		Engine::Engine* game = Engine::CreateGame();
		game->Run();
		delete game;

		return 0;
	}

#endif