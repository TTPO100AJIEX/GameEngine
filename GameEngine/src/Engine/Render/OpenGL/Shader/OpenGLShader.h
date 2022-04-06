#pragma once

#include "../../General//Shader.h"

namespace GameEngine::Render
{
	class OpenGLShader : public Shader
	{
	private:
		#ifdef DEBUG
			static unsigned int BoundShaderId;
		#endif

		int GetUniformLocation(const std::string& name) const;

	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;


		void UploadUniformInt(const std::string& name, int value) const;

		void UploadUniformFloat(const std::string& name, float value) const;
		void UploadUniformFloat2(const std::string& name, glm::vec2& value) const;
		void UploadUniformFloat3(const std::string& name, glm::vec3& value) const;
		void UploadUniformFloat4(const std::string& name, glm::vec4& value) const;

		void UploadUniformMat3(const std::string& name, const glm::mat3& value) const;
		void UploadUniformMat4(const std::string& name, const glm::mat4& value) const;
	};
}