#include <EntryPoint.cpp>

#include "Game.cpp"

std::unique_ptr<GameEngine::Engine> GameEngine::Engine::CreateGame()
{
	return(std::make_unique<Game>());
}