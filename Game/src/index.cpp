#include <EntryPoint.cpp>

class Game : public Engine::Engine
{
public:
	Game()
	{

	}
	~Game()
	{

	}
};


Engine::Engine* Engine::CreateGame()
{
	return(new Game());
}