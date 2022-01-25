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

	virtual void OnEvent(::Engine::Event& event) override
	{
		//GAME_TRACE(event.ToString());
	}
};


Engine::Engine* Engine::CreateGame()
{
	return(new Game());
}