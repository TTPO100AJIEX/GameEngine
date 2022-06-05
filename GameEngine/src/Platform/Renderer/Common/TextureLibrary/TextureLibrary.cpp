#include <PrecompiledHeaders.h>

#include <Platform/Renderer/Renderer.h>

#include "TextureLibrary.h"

namespace GameEngine::Renderer
{
	void TextureLibrary::Add(const std::string& name, const std::shared_ptr<Texture> texture)
	{
		#ifdef DEBUG
			if (this->Exists(name)) ENGINE_WARN("TextureLibrary::Add: overriding a texture with name {0}!", name);
		#endif
		this->textures[name] = texture;
	}
	void TextureLibrary::Load2D(const std::string& name, const std::string& path)
	{
		#ifdef DEBUG
			if (this->Exists(name)) ENGINE_WARN("TextureLibrary::Load2D: overriding a texture with name {0}!", name);
		#endif
		this->textures[name] = std::make_shared<Texture2D>(path);
	}

	bool TextureLibrary::Exists(const std::string& name) const
	{
		return(this->textures.contains(name));
	}
	const std::shared_ptr<Texture> TextureLibrary::Get(const std::string& name) const
	{
		#ifdef DEBUG
			if (!this->Exists(name)) 
			{
				ENGINE_WARN("TextureLibrary::Get: texture with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		return(this->textures.at(name));
	}

	std::shared_ptr<Texture> TextureLibrary::Remove(const std::string& name)
	{
		#ifdef DEBUG
			if (!this->Exists(name)) 
			{
				ENGINE_WARN("TextureLibrary::Remove: texture with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		std::shared_ptr<Texture> save = this->textures.at(name);
		this->textures.erase(name);
		return(save);
	}

	const std::shared_ptr<Texture> TextureLibrary::Bind(const std::string& name, uint32_t slot) const
	{
		const std::shared_ptr<Texture> texture = this->Get(name);
		#ifdef DEBUG
			if (!texture)
			{
				ENGINE_WARN("TextureLibrary::Bind: texture with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		texture->Bind(slot);
		return(texture);
	}
}