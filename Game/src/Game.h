#pragma once

#include <GameEngine.h>

class Game : public GameEngine::Engine
{
private:
	std::shared_ptr<GameEngine::Renderer::ControlledCamera> camera;

	std::shared_ptr<GameEngine::Renderer::ShaderLibrary> shaders;

	std::shared_ptr<GameEngine::Renderer::VertexArray> vao1;

	std::shared_ptr<GameEngine::Renderer::VertexArray> vao2;
	glm::vec3 position2 = glm::vec3(0.0f);
	float rotation2 = 0.0f;
	float scale2 = 1.0f;

	std::shared_ptr<GameEngine::Renderer::TextureLibrary> textures;

public:
	Game();
	~Game();

	virtual void OnEvent(GameEngine::Event& event) override;
};