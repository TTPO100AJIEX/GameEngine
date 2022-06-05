#pragma once

namespace GameEngine::Renderer
{
	class Shader
	{
	private:
		#ifdef DEBUG
			static unsigned int BoundShaderId;
		#endif

		unsigned int id = 0;
		mutable std::unordered_map<std::string, int> UniformLocationCache;
		std::unordered_map <ShaderType, unsigned int> ShaderIds;

		int GetUniformLocation(const std::string& name) const;

	public:
		Shader(const std::unordered_map<ShaderType, const std::string>& data, bool fromFiles = false);
		~Shader();

		unsigned int GetID() const { return(this->id); }

		void Bind() const;
		void UnBind() const;


		void UploadUniformInt(const std::string& name, int value) const;

		void UploadUniformFloat(const std::string& name, float value) const;
		void UploadUniformFloat2(const std::string& name, glm::vec2& value) const;
		void UploadUniformFloat3(const std::string& name, glm::vec3& value) const;
		void UploadUniformFloat4(const std::string& name, glm::vec4& value) const;

		void UploadUniformMat3(const std::string& name, const glm::mat3& value) const;
		void UploadUniformMat4(const std::string& name, const glm::mat4& value) const;
	};
}