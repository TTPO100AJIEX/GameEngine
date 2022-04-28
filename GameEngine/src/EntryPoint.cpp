#include <PrecompiledHeaders.h>

#include "Engine/Engine.h"

int main(int argc, char** argv)
{
	#ifdef DEBUG
		GameEngine::Log::set_pattern("[%d-%m-%Y %T.%e] [%n]-[%L:%l] %^%v%$");
		ENGINE_WARN("Initialized log!");
	#endif

	std::unique_ptr<GameEngine::Engine> game = GameEngine::Engine::CreateGame();
	game->Run();

	return 0;
}