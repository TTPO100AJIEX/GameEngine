#pragma once

#include "../Texture.h"

namespace GameEngine::Renderer
{
	class Texture2D : public Texture
	{
	protected:
		unsigned int width = 0, height = 0;

	public:
		Texture2D(const std::string& Path);
		~Texture2D() = default;

		unsigned int GetWidth() const;
		unsigned int GetHeight() const;
	};
}