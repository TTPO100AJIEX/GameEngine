#include <PrecompiledHeaders.h>

#include "OpenGLShader.h"

namespace GameEngine::Render
{
	#ifdef DEBUG
		unsigned int OpenGLShader::BoundShaderId = 0;
	#endif

	OpenGLShader::OpenGLShader(const std::unordered_map<GameEngine::Render::ShaderType, const std::string>& data, bool fromFiles)
	{
		bool errored = false;
		for (auto& [type, source] : data)
		{
			unsigned int l_type = ShaderTypeToOpenGL(type);
			if (!l_type) [[unlikely]] { continue; }
			if (this->ShaderIds.contains(type)) [[unlikely]]
			{
				ENGINE_WARN("OpenGLShader: attempt to bind two shaders of same type {0} to the same program", type);
				errored = true;
				break;
			}
			unsigned int id = glCreateShader(l_type);
			this->ShaderIds[type] = id;
			if (fromFiles)
			{
				std::ifstream filein(source);
				if (!filein)
				{
					errored = true;
					ENGINE_ERROR("OpenGLShader: failed to open file {0} for shader {1}!", source, type);
					break;
				}
				std::stringstream source_buffer;
				std::string shader_source;
				source_buffer << filein.rdbuf();
				shader_source = source_buffer.str();
				const char* src = shader_source.c_str();
				glShaderSource(id, 1, &src, 0);
			}
			else
			{
				const char* src = source.c_str();
				glShaderSource(id, 1, &src, 0);
			}
			glCompileShader(id);

			int isCompiled = 0;
			glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_TRUE) [[likely]] { continue; }
			errored = true;
			#ifdef DEBUG
				int errorLength = 0;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &errorLength);
				char* error = (char*)(alloca(errorLength * sizeof(char)));
				glGetShaderInfoLog(id, errorLength, &errorLength, error);
				ENGINE_ERROR("OpenGLShader: shader with type {0} failed to compile with error {1}", type, error);
			#endif
			break;
		}
		if (errored) [[unlikely]]
		{
			for (auto& [type, Id] : this->ShaderIds) glDeleteShader(Id);
			return;
		}

		this->id = glCreateProgram();
		for (auto& [type, Id] : this->ShaderIds) glAttachShader(this->id, Id);
		glLinkProgram(this->id);

		int isLinked = 0;
		glGetProgramiv(this->id, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_TRUE) [[likely]]
		{
			for (auto& [type, Id] : this->ShaderIds) glDetachShader(this->id, Id); 
			return;
		}
		#ifdef DEBUG
			int errorLength = 0;
			glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &errorLength);
			char* error = (char*)(alloca(errorLength * sizeof(char)));
			glGetProgramInfoLog(this->id, errorLength, &errorLength, error);
			ENGINE_ERROR("OpenGLShader: failed to link shader program with error {0}", error);
		#endif
		glDeleteProgram(this->id);
		for (auto& [type, Id] : this->ShaderIds) glDeleteShader(Id);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(this->id);
		for (auto& [type, Id] : this->ShaderIds) glDeleteShader(Id);
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

		if (this->UniformLocationCache.contains(name))
			return(this->UniformLocationCache[name]);

		int location = glGetUniformLocation(this->id, name.c_str());
		#ifdef DEBUG
			if (location == -1) ENGINE_WARN("Uniform {0} does not exist for shader {1}", name, this->id);
		#endif
		this->UniformLocationCache[name] = location;
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