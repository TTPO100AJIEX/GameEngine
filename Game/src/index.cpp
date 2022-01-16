#include <Engine.h>




class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
	{

	}

	virtual void OnAdd() override
	{
		GAME_INFO("ExmapleLayer: Added. ID: {0}", ID);
	}
	virtual void OnRemove() override
	{
		GAME_INFO("ExmapleLayer: Removed");
	}
	virtual void Update() override
	{
		//GAME_TRACE("ExampleLayer::Update");
	}
	virtual void OnEvent(Engine::Event& New_Event) override
	{
		GAME_TRACE("{0}", New_Event.ToString());
	}
};





class Game : public Engine::Engine
{
public:
	Game()
	{
		RegisterLayer(new ExampleLayer(), 0);
	}
	~Game()
	{

	}
};


Engine::Engine* Engine::CreateGame()
{
	return(new Game());
}