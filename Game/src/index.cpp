#include <EntryPoint.cpp>

class Game : public Engine::Engine
{
public:
	Game()
	{
		GetRenderer2D()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });
	}
	~Game()
	{

	}

	virtual void OnEvent(::Engine::Event& event) override
	{
		switch (event.GetEventType())
		{
			[[likely]] case (::Engine::EventTypes::AppTick): 
			{
				GetRenderer2D()->BeginScene();

				GetRenderer2D()->EndScene();
				break;
			}
			[[unlikely]] default:
			{
				GAME_TRACE(event.ToString());
			}
		}
	}
};


Engine::Engine* Engine::CreateGame()
{
	return(new Game());
}