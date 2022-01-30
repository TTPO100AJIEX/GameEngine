#include <PrecompiledHeaders.h>

#include "OpenGLShader.h"

#include <GLAD/glad.h>

namespace GameEngine::Renderer
{
	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSrc)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* vertexSourceC = vertexSource.c_str();
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
		const char* fragmentSrcC = fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &fragmentSrcC, 0);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
			char* infoLog = (char*)(alloca(maxLength * sizeof(char)));
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, infoLog);
			ENGINE_ERROR("{0}", infoLog);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			return;
		}

		id = glCreateProgram();
		glAttachShader(id, vertexShader);
		glAttachShader(id, fragmentShader);
		glLinkProgram(id);
		int isLinked = 0;
		glGetProgramiv(id, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			int maxLength = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
			char* infoLog = (char*)(alloca(maxLength * sizeof(char)));
			glGetProgramInfoLog(id, maxLength, &maxLength, infoLog);
			ENGINE_ERROR("{0}", infoLog);
			glDeleteProgram(id);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			return;
		}

		glDetachShader(id, vertexShader);
		glDetachShader(id, fragmentShader);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(id);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(id);
	}
	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}
}