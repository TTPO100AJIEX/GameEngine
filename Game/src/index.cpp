#include <EntryPoint.cpp>

class Game : public GameEngine::Engine
{
private:
	std::shared_ptr<GameEngine::Renderer::VertexArray> vao;
	std::shared_ptr<GameEngine::Renderer::VertexBufferLayout::Layout> vbl;
	std::shared_ptr<GameEngine::Renderer::VertexBuffer> vb;
	std::shared_ptr<GameEngine::Renderer::IndexBuffer> ib;

public:
	Game()
	{
		GetRenderer2D()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		this->vao = GameEngine::RendererAPI::CreateVertexArray();

		float vertices[4 * 3] = 
		{
			-0.5f, -0.5f, 1.0f,
			0.5f, -0.5f, 1.0f,
			0.5f, 0.5f, 1.0f,
			-0.5f, 0.5f, 1.0f
		};
		uint32_t indices[6] = { 2, 3, 0, 0, 1, 2 };
		this->vbl = GameEngine::RendererAPI::CreateVertexBufferLayout({ { GameEngine::Renderer::VertexBufferLayout::VertexBufferLayoutElement::ElementType::Float3, false } });
		this->vb = GameEngine::RendererAPI::CreateVertexBuffer(vertices, 4, this->vbl);
		this->ib = GameEngine::RendererAPI::CreateIndexBuffer(indices, 6);

		this->vao->SetVertexBuffer(this->vb);
		this->vao->SetIndexBuffer(this->ib);
	}
	~Game()
	{

	}

	virtual void OnEvent(GameEngine::Event& event) override
	{
		switch (event.GetEventType())
		{
			[[likely]] case (GameEngine::EventTypes::AppTick): 
			{
				this->GetRenderer2D()->Clear();

				this->GetRenderer2D()->BeginScene();

				this->GetRenderer2D()->DrawIndexed(this->vao);

				this->GetRenderer2D()->EndScene();
				break;
			}
			[[unlikely]] default:
			{
				GAME_TRACE(event.ToString());
			}
		}
	}
};


GameEngine::Engine* GameEngine::CreateGame()
{
	return(new Game());
}