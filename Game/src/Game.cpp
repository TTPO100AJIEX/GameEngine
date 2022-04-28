#include <PrecompiledHeaders.h>
#include <GameEngine.h>

class Game : public GameEngine::Engine
{
private:
	std::shared_ptr<GameEngine::Render::ControlledCamera> camera;

	std::shared_ptr<GameEngine::Render::ShaderLibrary> shaders;

	std::shared_ptr<GameEngine::Render::VertexArray> vao1;

	std::shared_ptr<GameEngine::Render::VertexArray> vao2;
	glm::vec3 position2 = glm::vec3(0.0f);
	float rotation2 = 0.0f;
	float scale2 = 1.0f;

	std::shared_ptr<GameEngine::Render::Texture2D> texture1;
	std::shared_ptr<GameEngine::Render::Texture2D> texture2;

public:
	Game()
	{
		this->GetRenderer()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		this->camera = GameEngine::RenderAPI::Camera::CreateControlled(1280.0f, 720.0f, 0.0025f, 1.0f, 1.0f, 0.00025f);

		this->shaders = GameEngine::RenderAPI::Shader::Library::Create();
		this->shaders->LoadFromFiles("solid", {
			{ GameEngine::Render::ShaderType::Vertex, "assets/shaders/solid/vertex.glsl" },
			{ GameEngine::Render::ShaderType::Fragment, "assets/shaders/solid/fragment.glsl" }
			});
		this->shaders->LoadFromFiles("texture", {
			{ GameEngine::Render::ShaderType::Vertex, "assets/shaders/texture/vertex.glsl" },
			{ GameEngine::Render::ShaderType::Fragment, "assets/shaders/texture/fragment.glsl" }
			});

		this->vao1 = GameEngine::RenderAPI::VertexArray::Create();
		float vertices1[4 * 3] =
		{
			-0.5f, -0.5f, 1.0f,
			0.5f, -0.5f, 1.0f,
			0.5f, 0.5f, 1.0f,
			-0.5f, 0.5f, 1.0f
		};
		uint32_t indices1[6] = { 2, 3, 0, 0, 1, 2 };
		this->vao1->SetVertexBuffer(GameEngine::RenderAPI::VertexBuffer::Create(vertices1, 4,
			GameEngine::RenderAPI::VertexBuffer::Layout::Create({
				{ GameEngine::Render::ShaderDataType::Float3, false }
				})
		));
		this->vao1->SetIndexBuffer(GameEngine::RenderAPI::IndexBuffer::Create(indices1, 6));

		this->vao2 = GameEngine::RenderAPI::VertexArray::Create();
		float vertices2[4 * 5] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		uint32_t indices2[6] = { 2, 3, 0, 0, 1, 2 };
		this->vao2->SetVertexBuffer(GameEngine::RenderAPI::VertexBuffer::Create(vertices2, 4,
			GameEngine::RenderAPI::VertexBuffer::Layout::Create({
				{ GameEngine::Render::ShaderDataType::Float3, false },
				{ GameEngine::Render::ShaderDataType::Float2, false }
				})
		));
		this->vao2->SetIndexBuffer(GameEngine::RenderAPI::IndexBuffer::Create(indices2, 6));

		this->texture1 = GameEngine::RenderAPI::Texture::Create2D("assets/textures/avatar.png");
		this->texture2 = GameEngine::RenderAPI::Texture::Create2D("assets/textures/avatar_template.png");
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
			this->camera->OnEvent(event);


			GameEngine::AppTick& ev = static_cast<GameEngine::AppTick&>(event);
			float multiplier = ev.GetFrameTime().GetSeconds();
			if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_1)) this->rotation2 += 0.5f * multiplier;
			else if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_2)) this->rotation2 -= 0.5f * multiplier;

			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::RIGHT)) this->position2.x -= 0.25f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::LEFT)) this->position2.x += 0.25f * multiplier;
			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::UP)) this->position2.y -= 0.25f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::DOWN)) this->position2.y += 0.25f * multiplier;

			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::EQUAL)) this->scale2 += 0.25f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::MINUS)) this->scale2 -= 0.25f * multiplier;


			this->GetRenderer()->Clear();
			this->GetRenderer()->BeginScene(this->camera->GetCamera());


			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), { 0.155f * (x - 4.5f), 0.155f * (y - 4.5f), 0.0f });
					transform *= glm::scale(glm::mat4(1.0f), glm::vec3(0.15f));
					this->GetRenderer()->DrawIndexed(this->vao1, this->shaders->Get("solid"), transform);
				}
			}

			glm::mat4 transform = glm::translate(glm::mat4(1.0f), this->position2);
			transform *= glm::rotate(glm::mat4(1.0f), this->rotation2, glm::vec3(0, 0, 1));
			transform *= glm::scale(glm::mat4(1.0f), glm::vec3(scale2));

			const std::shared_ptr<GameEngine::Render::Shader> textureShader = this->shaders->Bind("texture");
			this->texture1->Bind(1);
			textureShader->UploadUniformInt("u_Texture", 1);
			this->GetRenderer()->DrawIndexed(this->vao2, this->shaders->Get("texture"), transform);

			this->texture2->Bind(2);
			textureShader->UploadUniformInt("u_Texture", 2);
			this->GetRenderer()->DrawIndexed(this->vao2, this->shaders->Get("texture"), transform);


			this->GetRenderer()->EndScene();
			break;
		}
		[[unlikely]] default:
		{
			this->camera->OnEvent(event);
		}
		}
	}
};