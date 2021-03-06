#include <PrecompiledHeaders.h>

#include <Platform/Renderer/Renderer.h>

#include "ShaderLibrary.h"

namespace GameEngine::Renderer
{
	void ShaderLibrary::Add(const std::string& name, const std::shared_ptr<Shader> shader)
	{
		#ifdef DEBUG
			if (this->Exists(name)) ENGINE_WARN("ShaderLibrary::Add: overriding a shader with name {0}!", name);
		#endif
		this->shaders[name] = shader;
	}
	void ShaderLibrary::LoadFromStrings(const std::string& name, const std::unordered_map<ShaderType, const std::string>& data)
	{
		#ifdef DEBUG
			if (this->Exists(name)) ENGINE_WARN("ShaderLibrary::LoadFromStrings: overriding a shader with name {0}!", name);
		#endif
		this->shaders[name] = std::make_shared<Shader>(data, false);
	}
	void ShaderLibrary::LoadFromFiles(const std::string& name, const std::unordered_map<ShaderType, const std::string>& data)
	{
		#ifdef DEBUG
			if (this->Exists(name)) ENGINE_WARN("ShaderLibrary::LoadFromFiles: overriding a shader with name {0}!", name);
		#endif
		this->shaders[name] = std::make_shared<Shader>(data, true);
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return(this->shaders.contains(name));
	}
	const std::shared_ptr<Shader> ShaderLibrary::Get(const std::string& name) const
	{
		#ifdef DEBUG
			if (!this->Exists(name)) 
			{
				ENGINE_WARN("ShaderLibrary::Get: shader with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		return(this->shaders.at(name));
	}

	std::shared_ptr<Shader> ShaderLibrary::Remove(const std::string& name)
	{
		#ifdef DEBUG
			if (!this->Exists(name)) 
			{
				ENGINE_WARN("ShaderLibrary::Remove: shader with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		std::shared_ptr<Shader> save = this->shaders.at(name);
		this->shaders.erase(name);
		return(save);
	}

	const std::shared_ptr<Shader> ShaderLibrary::Bind(const std::string& name) const
	{
		const std::shared_ptr<Shader> shader = this->Get(name);
		#ifdef DEBUG
			if (!shader)
			{
				ENGINE_WARN("ShaderLibrary::Bind: shader with name {0} does not exist!", name); 
				return(nullptr);
			}
		#endif
		shader->Bind();
		return(shader);
	}
}