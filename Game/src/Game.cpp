#include <PrecompiledHeaders.h>

#include "Game.h"

Game::Game()
{
	this->GetRenderer()->SetClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });
	this->camera = GameEngine::RenderAPI::Camera::CreateControlled(1920.0f, 1080.0f, 1.0f, 300.0f, 1.0f, 0.05f);

	this->shaders = GameEngine::RenderAPI::Shader::Library::Create();
	this->shaders->LoadFromFiles("solid", {
		{ GameEngine::Render::ShaderType::Vertex, "assets/shaders/solid/vertex.glsl" },
		{ GameEngine::Render::ShaderType::Fragment, "assets/shaders/solid/fragment.glsl" }
	});
	this->shaders->LoadFromFiles("texture", {
		{ GameEngine::Render::ShaderType::Vertex, "assets/shaders/texture/vertex.glsl" },
		{ GameEngine::Render::ShaderType::Fragment, "assets/shaders/texture/fragment.glsl" }
	});
	this->textures = GameEngine::RenderAPI::Texture::Library::Create();
	this->textures->Load2D("avatar", "assets/textures/avatar.png");
	this->textures->Load2D("avatar_template", "assets/textures/avatar_template.png");

	this->vao1 = GameEngine::RenderAPI::VertexArray::Create();
	float vertices1[4 * 3] =
	{
		400.0f,  100.0f,  1.0f,
		1300.0f, 100.0f,  1.0f,
		1300.0f, 1000.0f, 1.0f,
		400.0f,  1000.0f, 1.0f
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
		400.0f,  100.0f,  1.0f, 0.0f, 0.0f,
		1300.0f, 100.0f,  1.0f, 1.0f, 0.0f,
		1300.0f, 1000.0f, 1.0f, 1.0f, 1.0f,
		400.0f,  1000.0f, 1.0f, 0.0f, 1.0f
	};
	uint32_t indices2[6] = { 2, 3, 0, 0, 1, 2 };
	this->vao2->SetVertexBuffer(GameEngine::RenderAPI::VertexBuffer::Create(vertices2, 4,
		GameEngine::RenderAPI::VertexBuffer::Layout::Create({
			{ GameEngine::Render::ShaderDataType::Float3, false },
			{ GameEngine::Render::ShaderDataType::Float2, false }
		})
	));
	this->vao2->SetIndexBuffer(GameEngine::RenderAPI::IndexBuffer::Create(indices2, 6));
}
Game::~Game()
{

}

void Game::OnEvent(GameEngine::Event& event)
{
	switch (event.GetEventType())
	{
		[[likely]] case (GameEngine::EventTypes::AppTick):
		{
			this->camera->OnEvent(event);

			GameEngine::AppTick& ev = static_cast<GameEngine::AppTick&>(event);
			float multiplier = (float)(ev.GetFrameTime().GetSeconds());
			if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_1)) this->rotation2 += 0.5f * multiplier;
			else if (this->GetWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_2)) this->rotation2 -= 0.5f * multiplier;

			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::RIGHT)) this->position2.x += 250.0f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::LEFT)) this->position2.x -= 250.0f * multiplier;
			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::UP)) this->position2.y += 250.0f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::DOWN)) this->position2.y -= 250.0f * multiplier;

			if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::EQUAL)) this->scale2 += 0.05f * multiplier;
			else if (this->GetWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::MINUS)) this->scale2 -= 0.05f * multiplier;
			this->scale2 = std::min(this->scale2, 1.0f);


			this->GetRenderer()->Clear();
			this->GetRenderer()->BeginScene(this->camera->GetCamera());

			for (int x = 0; x < 18; x++)
			{
				for (int y = 0; y < 13; y++)
				{
					glm::mat4 transform = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
					transform *= glm::translate(glm::mat4(1.0f), { 925.0f * x, 925.0f * y, 0.0f });
					this->GetRenderer()->DrawIndexed(this->vao1, this->shaders->Get("solid"), transform);
				}
			}

			glm::mat4 transform = glm::translate(glm::mat4(1.0f), this->position2);
			transform *= glm::rotate(glm::mat4(1.0f), this->rotation2, glm::vec3(0, 0, 1));
			transform *= glm::scale(glm::mat4(1.0f), glm::vec3(this->scale2));

			const std::shared_ptr<GameEngine::Render::Shader> textureShader = this->shaders->Bind("texture");
			this->textures->Bind("avatar", 1);
			textureShader->UploadUniformInt("u_Texture", 1);
			this->GetRenderer()->DrawIndexed(this->vao2, textureShader, transform);

			this->textures->Bind("avatar_template", 2);
			textureShader->UploadUniformInt("u_Texture", 2);
			this->GetRenderer()->DrawIndexed(this->vao2, textureShader, transform);


			this->GetRenderer()->EndScene();
			break;
		}
		[[unlikely]] default:
		{
			this->camera->OnEvent(event);
		}
	}
}