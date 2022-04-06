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

		virtual int GetUniformLocation(const std::string& name) const override;

	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const override;
	};
}