#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>
#include <stb/stb_image.h>

#include "OpenGLTexture2D.h"

namespace GameEngine::Render
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& Path)
		: Texture2D(Path)
	{
		stbi_set_flip_vertically_on_load(true);
		int channels = 0;
		stbi_uc* data = stbi_load(this->path.c_str(), (int*)(&this->width), (int*)(&this->height), &channels, 0);
		if (!data) { ENGINE_ERROR("OpenGLTexture2D: failed to load image from {0}!", this->path); }

		unsigned int internalFormat = 0, dataFormat = 0;
		if (channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		if (channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}
		if (!internalFormat || !dataFormat) { ENGINE_ERROR("OpenGLTexture2D: invalid channels value ({0})!", channels); }

		glCreateTextures(GL_TEXTURE_2D, 1, &(this->id));
		glTextureStorage2D(this->id, 1, internalFormat, this->width, this->height);

		glTextureParameteri(this->id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(this->id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(this->id, 0, 0, 0, this->width, this->height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &(this->id));
	}


	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, this->id);
	}
	void OpenGLTexture2D::UnBind() const
	{
		glBindTextureUnit(this->bound_slot, 0);
	}
}