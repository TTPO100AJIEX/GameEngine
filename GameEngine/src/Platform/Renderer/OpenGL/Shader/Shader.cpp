#include <PrecompiledHeaders.h>

#include <GLAD/glad.h>
#include <Platform/ShaderType/OpenGL/OpenGL.h>

#include "Shader.h"

namespace GameEngine::Renderer
{
	#ifdef DEBUG
		unsigned int Shader::BoundShaderId = 0;
	#endif

	Shader::Shader(const std::unordered_map<ShaderType, const std::string>& data, bool fromFiles)
	{
		bool errored = false;
		for (auto& [type, source] : data)
		{
			unsigned int l_type = ShaderTypeToOpenGL(type);
			if (!l_type) [[unlikely]] { ENGINE_WARN("Shader: invalid shader type {0}!", type);  continue; }
			if (this->ShaderIds.contains(type)) [[unlikely]]
			{
				ENGINE_WARN("Shader: attempt to bind two shaders of same type {0} to the same program", type);
				errored = true;
				break;
			}
			unsigned int id = glCreateShader(l_type);
			this->ShaderIds[type] = id;
			if (fromFiles)
			{
				std::ifstream filein(source, std::ios::in);
				if (!filein)
				{
					errored = true;
					ENGINE_ERROR("Shader: failed to open file {0} for shader {1}!", source, type);
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
				ENGINE_ERROR("Shader: shader with type {0} failed to compile with error {1}", type, error);
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
		for (auto& [type, Id] : this->ShaderIds) { glDetachShader(this->id, Id); glDeleteShader(Id); }

		int isLinked = 0;
		glGetProgramiv(this->id, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_TRUE) [[likely]] { return; }
		#ifdef DEBUG
			int errorLength = 0;
			glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &errorLength);
			char* error = (char*)(alloca(errorLength * sizeof(char)));
			glGetProgramInfoLog(this->id, errorLength, &errorLength, error);
			ENGINE_ERROR("Shader: failed to link shader program with error {0}", error);
		#endif
		glDeleteProgram(this->id);
	}
	Shader::~Shader()
	{
		glDeleteProgram(this->id);
	}


	void Shader::Bind() const
	{
		#ifdef DEBUG
			this->BoundShaderId = this->id;
		#endif
		glUseProgram(id);
	}
	void Shader::UnBind() const
	{
		#ifdef DEBUG
			this->BoundShaderId = 0;
		#endif
		glUseProgram(0);
	}


	int Shader::GetUniformLocation(const std::string& name) const
	{
		#ifdef DEBUG
			if (this->BoundShaderId != this->id) ENGINE_WARN("Attempt to get uniform {0} location for an unbound shader {1}", name, this->id);
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

	void Shader::UploadUniformInt(const std::string& name, int value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform1i(location, value);
	}
	
	void Shader::UploadUniformFloat(const std::string& name, float value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform1f(location, value);
	}
	void Shader::UploadUniformFloat2(const std::string& name, glm::vec2& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform2f(location, value.x, value.y);
	}
	void Shader::UploadUniformFloat3(const std::string& name, glm::vec3& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform3f(location, value.x, value.y, value.z);
	}
	void Shader::UploadUniformFloat4(const std::string& name, glm::vec4& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void Shader::UploadUniformMat3(const std::string& name, const glm::mat3& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
	void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& value) const
	{
		int location = this->GetUniformLocation(name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
}