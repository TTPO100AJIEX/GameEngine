#include <PrecompiledHeaders.h>

#include "OpenGLShader.h"

namespace GameEngine::Render
{
	#ifdef DEBUG
		unsigned int OpenGLShader::BoundShaderId = 0;
	#endif

	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSrc)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char *vertexSourceC = vertexSource.c_str();
		glShaderSource(vertexShader, 1, &vertexSourceC, 0);
		glCompileShader(vertexShader);
		int isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);
			char *infoLog = (char*)(alloca(maxLength * sizeof(char)));
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, infoLog);
			ENGINE_ERROR("{0}", infoLog);
			glDeleteShader(vertexShader);
			return;
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char *fragmentSrcC = fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &fragmentSrcC, 0);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
			char *infoLog = (char*)(alloca(maxLength * sizeof(char)));
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, infoLog);
			ENGINE_ERROR("{0}", infoLog);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			return;
		}

		this->id = glCreateProgram();
		glAttachShader(this->id, vertexShader);
		glAttachShader(this->id, fragmentShader);
		glLinkProgram(this->id);
		int isLinked = 0;
		glGetProgramiv(this->id, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			int maxLength = 0;
			glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &maxLength);
			char *infoLog = (char*)(alloca(maxLength * sizeof(char)));
			glGetProgramInfoLog(this->id, maxLength, &maxLength, infoLog);
			ENGINE_ERROR("{0}", infoLog);
			glDeleteProgram(this->id);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			return;
		}

		glDetachShader(this->id, vertexShader);
		glDetachShader(this->id, fragmentShader);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(this->id);
	}


	void OpenGLShader::Bind() const
	{
		#ifdef DEBUG
			this->BoundShaderId = this->id;
		#endif
		glUseProgram(id);
	}
	void OpenGLShader::UnBind() const
	{
		#ifdef DEBUG
			this->BoundShaderId = 0;
		#endif
		glUseProgram(0);
	}


	int OpenGLShader::GetUniformLocation(const std::string& name) const
	{
		#ifdef DEBUG
			if (this->BoundShaderId != this->id) ENGINE_WARN("Attempt to set uniform {0} for an unbound shader {1}", name, this->id);
		#endif
		int location = glGetUniformLocation(this->id, name.c_str());
		#ifdef DEBUG
			if (location == -1) ENGINE_WARN("Uniform {0} does not exist for shader {1}", name, this->id);
		#endif
		return(location);
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform1i(location, value);
	}
	
	void OpenGLShader::UploadUniformFloat(const std::string& name, float value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform1f(location, value);
	}
	void OpenGLShader::UploadUniformFloat2(const std::string& name, glm::vec2& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform2f(location, value.x, value.y);
	}
	void OpenGLShader::UploadUniformFloat3(const std::string& name, glm::vec3& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform3f(location, value.x, value.y, value.z);
	}
	void OpenGLShader::UploadUniformFloat4(const std::string& name, glm::vec4& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
}