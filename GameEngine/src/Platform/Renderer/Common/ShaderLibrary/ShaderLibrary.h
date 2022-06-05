#pragma once

namespace GameEngine::Renderer
{
	class Shader;
}

namespace GameEngine::Renderer
{
	class ShaderLibrary
	{
	private:
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;

	public:
		void Add(const std::string& name, const std::shared_ptr<Shader> shader);
		void LoadFromStrings(const std::string& name, const std::unordered_map<ShaderType, const std::string>& data);
		void LoadFromFiles(const std::string& name, const std::unordered_map<ShaderType, const std::string>& data);

		bool Exists(const std::string& name) const;
		const std::shared_ptr<Shader> Get(const std::string& name) const;

		std::shared_ptr<Shader> Remove(const std::string& name);

		const std::shared_ptr<Shader> Bind(const std::string& name) const;
	};
}