workspace "GameEngine"
    architecture "x64"
    startproject "Game"

    configurations
    {
        "Debug", "Release"
    }
    
	flags
	{
		"MultiProcessorCompile"
	}
    
group "Dependencies"
    include "GameEngine/Dependencies/GLFW"
    include "GameEngine/Dependencies/GLAD"

group ""
    include "GameEngine"
    include "Game"