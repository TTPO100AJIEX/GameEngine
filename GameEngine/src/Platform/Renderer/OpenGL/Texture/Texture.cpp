#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>

#include "Texture.h"

namespace GameEngine::Renderer
{
	Texture::Texture(const std::string& Path) : path(Path) {};
	Texture::~Texture()
	{
		glDeleteTextures(1, &(this->id));
	}

	unsigned int Texture::GetID() const
	{
		return(this->id);
	}

	void Texture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, this->id);
	}
	void Texture::UnBind() const
	{
		glBindTextureUnit(this->slot, 0);
	}
}