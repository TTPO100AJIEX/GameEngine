#include <EntryPoint.cpp>

class Game : public GameEngine::Engine
{
private:
	std::shared_ptr<GameEngine::Renderer::Camera> camera;
	glm::vec3 cameraPosition;
	float cameraRotation;

	std::shared_ptr<GameEngine::Renderer::VertexArray> vao;
	std::shared_ptr<GameEngine::Renderer::Shader> shader;

public:
	Game() : cameraPosition(0.0f), cameraRotation(0.0f)
	{
		GetRenderer2D()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		this->camera = GameEngine::RendererAPI::Camera::Create(-1.6f, 1.6f, -0.9f, 0.9f);

		this->vao = GameEngine::RendererAPI::VertexArray::Create();
		float vertices[4 * 3] = 
		{
			-0.5f, -0.5f, 1.0f,
			0.5f, -0.5f, 1.0f,
			0.5f, 0.5f, 1.0f,
			-0.5f, 0.5f, 1.0f
		};
		uint32_t indices[6] = { 2, 3, 0, 0, 1, 2 };
		this->vao->SetVertexBuffer(GameEngine::RendererAPI::VertexBuffer::Create(vertices, 4, GameEngine::RendererAPI::VertexBuffer::Layout::Create({ { GameEngine::Renderer::ShaderDataType::Float3, false } })));
		this->vao->SetIndexBuffer(GameEngine::RendererAPI::IndexBuffer::Create(indices, 6));


		this->shader = GameEngine::RendererAPI::Shader::Create(R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)", R"(
			#version 460 core
			
			layout(location = 0) out vec4 Color;

			in vec3 v_Position;

			void main()
			{
				Color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)");
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

				GameEngine::AppTick& ev = static_cast<GameEngine::AppTick&>(event);
				float multiplier = ev.GetFrameTime().GetSeconds();

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::Q)) this->cameraRotation += 0.5f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::E)) this->cameraRotation -= 0.5f * multiplier;

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::RIGHT) || this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::D)) this->cameraPosition.x -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::LEFT) || this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::A)) this->cameraPosition.x += 0.25f * multiplier;

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::UP) || this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::W)) this->cameraPosition.y -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::DOWN) || this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::S)) this->cameraPosition.y += 0.25f * multiplier;
				

				this->camera->SetPosition(this->cameraPosition);
				this->camera->SetRotation(this->cameraRotation);

				this->GetRenderer2D()->BeginScene(this->camera);

				this->GetRenderer2D()->DrawIndexed(this->vao, this->shader);

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