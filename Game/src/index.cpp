#include <PrecompiledHeaders.h>

#include "Game.cpp"

int main(int argc, char** argv)
{
	#ifdef DEBUG
		GameEngine::Log::set_pattern("[%d-%m-%Y %T.%e] [%n]-[%L:%l] %^%v%$");
		GAME_WARN("Initialized log!");
	#endif

	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->Run();

	return 0;
}