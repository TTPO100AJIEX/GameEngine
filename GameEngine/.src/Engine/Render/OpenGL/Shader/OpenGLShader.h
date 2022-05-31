#pragma once

#include "../../General/Shader.h"

namespace GameEngine::Render
{
	class OpenGLShader : public Shader
	{
	private:
		#ifdef DEBUG
			static unsigned int BoundShaderId;
		#endif
		
		mutable std::unordered_map<std::string, int> UniformLocationCache;
		int GetUniformLocation(const std::string& name) const;

	public:
		OpenGLShader(const std::unordered_map<GameEngine::Render::ShaderType, const std::string>& data, bool fromFiles = false);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;


		virtual void UploadUniformInt(const std::string& name, int value) const override;

		virtual void UploadUniformFloat(const std::string& name, float value) const override;
		virtual void UploadUniformFloat2(const std::string& name, glm::vec2& value) const override;
		virtual void UploadUniformFloat3(const std::string& name, glm::vec3& value) const override;
		virtual void UploadUniformFloat4(const std::string& name, glm::vec4& value) const override;

		virtual void UploadUniformMat3(const std::string& name, const glm::mat3& value) const override;
		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& value) const override;
	};
}