#pragma once

namespace GameEngine::Render
{
	class Shader
	{
	protected:
		unsigned int id;
		std::unordered_map <ShaderType, unsigned int> ShaderIds;

	public:
		virtual ~Shader() = default;

		unsigned int GetID() const { return(this->id); }

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void UploadUniformInt(const std::string& name, int value) const = 0;

		virtual void UploadUniformFloat(const std::string& name, float value) const = 0;
		virtual void UploadUniformFloat2(const std::string& name, glm::vec2& value) const = 0;
		virtual void UploadUniformFloat3(const std::string& name, glm::vec3& value) const = 0;
		virtual void UploadUniformFloat4(const std::string& name, glm::vec4& value) const = 0;

		virtual void UploadUniformMat3(const std::string& name, const glm::mat3& value) const = 0;
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& value) const = 0;
	};
}