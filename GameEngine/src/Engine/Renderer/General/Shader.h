#pragma once

namespace GameEngine::Renderer
{
	class Shader
	{
	protected:
		unsigned int id;

		virtual int GetUniformLocation(const std::string& name) const = 0;

	public:
		virtual ~Shader() = default;

		inline unsigned int GetID() const { return(id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const = 0;
	};
}