#pragma once

#include "../../../General/Textures.h"

namespace GameEngine::Render
{
	class OpenGLTexture2D : public Texture2D
	{
	private:
		uint32_t bound_slot = 0;

	public:
		OpenGLTexture2D(const std::string& Path);
		virtual ~OpenGLTexture2D();

		virtual void Bind(uint32_t slot = 0) const override;
		virtual void UnBind() const override;

	};
}