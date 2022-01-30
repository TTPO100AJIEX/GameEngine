#pragma once

namespace GameEngine::Renderer
{
	class Shader
	{
	protected:
		unsigned int id;

	public:
		virtual ~Shader() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}