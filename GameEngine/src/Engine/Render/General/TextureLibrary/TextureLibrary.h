#pragma once

namespace GameEngine::Render
{
	class Texture;
}

namespace GameEngine::Render
{
	class TextureLibrary
	{
	private:
		std::unordered_map<std::string, std::shared_ptr<Texture>> textures;

	public:
		void Add(const std::string& name, const std::shared_ptr<Texture> texture);
		void Load2D(const std::string& name, const std::string& path);

		bool Exists(const std::string& name) const;
		const std::shared_ptr<Texture> Get(const std::string& name) const;

		std::shared_ptr<Texture> Remove(const std::string& name);

		const std::shared_ptr<Texture> Bind(const std::string& name, uint32_t slot) const;

	};
}