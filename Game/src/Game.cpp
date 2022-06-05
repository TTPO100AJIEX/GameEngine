#include <pch.h>

#include "Game.h"

Game::Game()
{
	GameEngine::Renderer::SetClearColor({0.0f, 1.0f, 0.0f, 1.0f});
	this->camera = std::make_shared<GameEngine::Renderer::ControlledCamera>(1920.0f, 1080.0f, 1.0f, 300.0f, 1.0f, 0.05f);
	
	this->shaders = std::make_shared<GameEngine::Renderer::ShaderLibrary>();
	this->shaders->LoadFromFiles("solid", {
		{ GameEngine::Renderer::ShaderType::Vertex, "assets/shaders/solid/vertex.glsl" },
		{ GameEngine::Renderer::ShaderType::Fragment, "assets/shaders/solid/fragment.glsl" }
	});
	this->shaders->LoadFromFiles("texture", {
		{ GameEngine::Renderer::ShaderType::Vertex, "assets/shaders/texture/vertex.glsl" },
		{ GameEngine::Renderer::ShaderType::Fragment, "assets/shaders/texture/fragment.glsl" }
	});
	this->textures = std::make_shared<GameEngine::Renderer::TextureLibrary>();
	this->textures->Load2D("avatar", "assets/textures/avatar.png");
	this->textures->Load2D("avatar_template", "assets/textures/avatar_template.png");
	

	this->vao1 = std::make_shared<GameEngine::Renderer::VertexArray>();
	float vertices1[4 * 3] =
	{
		400.0f,  100.0f,  0.0f,
		1300.0f, 100.0f,  0.0f,
		1300.0f, 1000.0f, 0.0f,
		400.0f,  1000.0f, 0.0f
	};
	this->vao1->AddVertexBuffer(std::make_shared<GameEngine::Renderer::VertexBuffer>(vertices1, 4, GameEngine::Renderer::VertexBufferLayout({ { GameEngine::Renderer::ShaderDataType::Float3, false } })));
	uint32_t indices1[6] = { 2, 3, 0, 0, 1, 2 };
	this->vao1->SetIndexBuffer(std::make_shared<GameEngine::Renderer::IndexBuffer>(indices1, 6));

	this->vao2 = std::make_shared<GameEngine::Renderer::VertexArray>();
	float vertices2[4 * 5] =
	{
		400.0f,  100.0f,  0.0f, 0.0f, 0.0f,
		1300.0f, 100.0f,  0.0f, 1.0f, 0.0f,
		1300.0f, 1000.0f, 0.0f, 1.0f, 1.0f,
		400.0f,  1000.0f, 0.0f, 0.0f, 1.0f
	};
	uint32_t indices2[6] = { 2, 3, 0, 0, 1, 2 };
	this->vao2->AddVertexBuffer(std::make_shared<GameEngine::Renderer::VertexBuffer>(vertices2, 4, GameEngine::Renderer::VertexBufferLayout({
		{ GameEngine::Renderer::ShaderDataType::Float3, false },
		{ GameEngine::Renderer::ShaderDataType::Float2, false }
	})));
	this->vao2->SetIndexBuffer(std::make_shared<GameEngine::Renderer::IndexBuffer>(indices2, 6));
}
Game::~Game()
{

}

void Game::OnEvent(GameEngine::Event& event)
{
	this->camera->OnEvent(event);
	switch (event.GetEventType())
	{
		[[likely]] case (GameEngine::EventTypes::AppTick):
		{
			GameEngine::AppTick& ev = static_cast<GameEngine::AppTick&>(event);
			float multiplier = (float)(ev.GetFrameTime().GetSeconds());

			if (this->GetActiveWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_1)) this->rotation2 += 0.5f * multiplier;
			else if (this->GetActiveWindow()->IsMouseButtonPressed(GameEngine::KeyCodes::Keys::MOUSE_BUTTON_2)) this->rotation2 -= 0.5f * multiplier;

			if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::RIGHT)) this->position2.x += 250.0f * multiplier;
			else if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::LEFT)) this->position2.x -= 250.0f * multiplier;
			if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::UP)) this->position2.y += 250.0f * multiplier;
			else if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::DOWN)) this->position2.y -= 250.0f * multiplier;

			if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::EQUAL)) this->scale2 += 0.05f * multiplier;
			else if (this->GetActiveWindow()->IsKeyPressed(GameEngine::KeyCodes::Keys::MINUS)) this->scale2 -= 0.05f * multiplier;
			this->scale2 = std::min(this->scale2, 1.0f);


			GameEngine::Renderer::Clear();
			GameEngine::Renderer::BeginScene(this->camera->GetCamera());


			for (int x = 0; x < 18; x++)
			{
				for (int y = 0; y < 13; y++)
				{
					glm::mat4 transform = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
					transform *= glm::translate(glm::mat4(1.0f), { 925.0f * x, 925.0f * y, 0.0f });
					GameEngine::Renderer::DrawIndexed(this->vao1, this->shaders->Get("solid"), transform);
				}
			}
			
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), this->position2);
			transform *= glm::rotate(glm::mat4(1.0f), this->rotation2, glm::vec3(0, 0, 1));
			transform *= glm::scale(glm::mat4(1.0f), glm::vec3(this->scale2));

			const std::shared_ptr<GameEngine::Renderer::Shader> textureShader = this->shaders->Bind("texture");
			this->textures->Bind("avatar", 1);
			textureShader->UploadUniformInt("u_Texture", 1);
			GameEngine::Renderer::DrawIndexed(this->vao2, textureShader, transform);

			this->textures->Bind("avatar_template", 2);
			textureShader->UploadUniformInt("u_Texture", 2);
			GameEngine::Renderer::DrawIndexed(this->vao2, textureShader, transform);
			

			GameEngine::Renderer::EndScene();
			break;
		}
		[[unlikely]] default:
		{
		}
	}
}