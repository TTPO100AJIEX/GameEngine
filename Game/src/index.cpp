#include <EntryPoint.cpp>

class Game : public GameEngine::Engine
{
private:
	std::shared_ptr<GameEngine::Renderer::Camera> camera;
	glm::vec3 cameraPosition = glm::vec3(0.0f);
	float cameraRotation = 0.0f;

	std::shared_ptr<GameEngine::Renderer::VertexArray> vao1;
	std::shared_ptr<GameEngine::Renderer::Shader> shader1;

	std::shared_ptr<GameEngine::Renderer::VertexArray> vao2;
	std::shared_ptr<GameEngine::Renderer::Shader> shader2;
	glm::vec3 position2 = glm::vec3(0.0f);
	float rotation2 = 0.0f;
	float scale2 = 1.0f;

public:
	Game()
	{
		GetRenderer2D()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		this->camera = GameEngine::RendererAPI::Camera::Create(-1.6f, 1.6f, -0.9f, 0.9f);

		this->vao1 = GameEngine::RendererAPI::VertexArray::Create();
		float vertices1[4 * 3] = 
		{
			-0.5f, -0.5f, 1.0f,
			0.5f, -0.5f, 1.0f,
			0.5f, 0.5f, 1.0f,
			-0.5f, 0.5f, 1.0f
		};
		uint32_t indices1[6] = { 2, 3, 0, 0, 1, 2 };
		this->vao1->SetVertexBuffer(GameEngine::RendererAPI::VertexBuffer::Create(vertices1, 4, GameEngine::RendererAPI::VertexBuffer::Layout::Create({ { GameEngine::Renderer::ShaderDataType::Float3, false } })));
		this->vao1->SetIndexBuffer(GameEngine::RendererAPI::IndexBuffer::Create(indices1, 6));

		this->shader1 = GameEngine::RendererAPI::Shader::Create(R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
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


		this->vao2 = GameEngine::RendererAPI::VertexArray::Create();
		float vertices2[4 * 3] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		uint32_t indices2[6] = { 0, 1, 2 };
		this->vao2->SetVertexBuffer(GameEngine::RendererAPI::VertexBuffer::Create(vertices2, 4, GameEngine::RendererAPI::VertexBuffer::Layout::Create({ { GameEngine::Renderer::ShaderDataType::Float3, false } })));
		this->vao2->SetIndexBuffer(GameEngine::RendererAPI::IndexBuffer::Create(indices2, 6));

		this->shader2 = GameEngine::RendererAPI::Shader::Create(R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)", R"(
			#version 460 core
			
			layout(location = 0) out vec4 Color;

			in vec3 v_Position;

			void main()
			{
				Color = vec4(0.2, 0.3, 0.8, 1.0);
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

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::D)) this->cameraPosition.x -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::A)) this->cameraPosition.x += 0.25f * multiplier;
				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::W)) this->cameraPosition.y -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::S)) this->cameraPosition.y += 0.25f * multiplier;


				if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_1)) this->rotation2 += 0.5f * multiplier;
				else if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_2)) this->rotation2 -= 0.5f * multiplier;

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::RIGHT)) this->position2.x -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::LEFT)) this->position2.x += 0.25f * multiplier;
				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::UP)) this->position2.y -= 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::DOWN)) this->position2.y += 0.25f * multiplier;

				if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::EQUAL)) this->scale2 += 0.25f * multiplier;
				else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::MINUS)) this->scale2 -= 0.25f * multiplier;
				

				this->camera->SetPosition(this->cameraPosition);
				this->camera->SetRotation(this->cameraRotation);

				this->GetRenderer2D()->BeginScene(this->camera);

				for (int x = 0; x < 10; x++)
				{
					for (int y = 0; y < 10; y++)
					{
						glm::mat4 transform = glm::translate(glm::mat4(1.0f), { 0.155f * (x - 4.5f), 0.155f * (y - 4.5f), 0.0f } );
						transform *= glm::scale(glm::mat4(1.0f), glm::vec3(0.15f));
						this->GetRenderer2D()->DrawIndexed(this->vao1, this->shader1, transform);
					}
				}
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), this->position2);
				transform *= glm::rotate(glm::mat4(1.0f), this->rotation2, glm::vec3(0, 0, 1));
				transform *= glm::scale(glm::mat4(1.0f), glm::vec3(scale2));
				this->GetRenderer2D()->DrawIndexed(this->vao2, this->shader2, transform);

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