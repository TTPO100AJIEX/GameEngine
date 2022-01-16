workspace "GameEngine"
    architecture "x64"
    startproject "Game"

    configurations
    {
        "Debug", "Release"
    }

include "GameEngine/Dependencies/GLFW"
include "GameEngine/Dependencies/GLAD"

include "GameEngine"
include "Game"