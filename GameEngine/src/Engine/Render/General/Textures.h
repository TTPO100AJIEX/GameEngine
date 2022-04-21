#pragma once

namespace GameEngine::Render
{
	class Texture
	{
	protected:
		unsigned int id = 0;
		std::string path;

	public:
		Texture(const std::string& Path) : path(Path) {};
		virtual ~Texture() = default;

		unsigned int GetID() const { return(this->id); }

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void UnBind() const = 0;
	};

	class Texture2D : public Texture
	{
	protected:
		unsigned int width = 0, height = 0;

	public:
		Texture2D(const std::string& Path) : Texture(Path) {};
		virtual ~Texture2D() = default;

		unsigned int GetWidth() const { return(this->width); }
		unsigned int GetHeight() const { return(this->height); }
	};
}