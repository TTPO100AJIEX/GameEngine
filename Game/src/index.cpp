#include <EntryPoint.cpp>

class Game : public Engine::Engine
{
private:
	std::shared_ptr<::Engine::Renderer::VertexArray> vao;
	std::shared_ptr<::Engine::Renderer::VertexBuffer> vb;
	std::shared_ptr<::Engine::Renderer::IndexBuffer> ib;

public:
	Game()
	{
		GetRenderer2D()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		this->vao = std::make_shared<::Engine::Renderer::OpenGLVertexArray>();

		float vertices[4 * 3] = {
			-0.5f, -0.5f, 1.0f,
			0.5f, -0.5f, 1.0f,
			0.5f, 0.5f, 1.0f,
			-0.5f, 0.5f, 1.0f
		};
		uint32_t indices[6] = { 2, 3, 0, 0, 1, 2 };
		::Engine::Renderer::VertexBufferLayout::OpenGLLayout vbl({ { ::Engine::Renderer::VertexBufferLayout::VertexBufferLayoutElement::ElementType::Float3, false } });
		this->vb = std::make_shared<::Engine::Renderer::OpenGLVertexBuffer>(vertices, 4, vbl);
		this->ib = std::make_shared<::Engine::Renderer::OpenGLIndexBuffer>(indices, 6);

		this->vao->SetVertexBuffer(this->vb);
		this->vao->SetIndexBuffer(this->ib);
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


Engine::Engine* Engine::CreateGame()
{
	return(new Game());
}