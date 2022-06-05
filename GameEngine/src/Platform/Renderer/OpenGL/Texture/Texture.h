#pragma once

namespace GameEngine::Renderer
{
	class Texture
	{
	protected:
		unsigned int id = 0;
		uint32_t slot = 0;
		std::string path;

	public:
		Texture(const std::string& Path);
		virtual ~Texture();

		unsigned int GetID() const;

		void Bind(uint32_t slot = 0) const;
		void UnBind() const;
	};
}