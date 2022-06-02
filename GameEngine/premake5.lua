project "GameEngine"
    kind "StaticLib"
    language "C++"
	cppdialect "C++20"
    flags { "MultiProcessorCompile", "ShadowedVariables" }
	staticruntime "On"
    optimize "Full"

    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    pchheader "PrecompiledHeaders.h"
    pchsource "src/Common/PrecompiledHeaders/PrecompiledHeaders.cpp"

    files
    {
        "src/Common/**.h",
        "src/Common/**.cpp",

        "src/Platform/Window/*.h",
        "src/Platform/Window/GLFW/**.h",
        "src/Platform/Window/GLFW/**.cpp",
        "src/Platform/KeyCodes/GLFW/**.h",
        "src/Platform/KeyCodes/GLFW/**.cpp"
    }

    includedirs
    {
        "Dependencies",
        "src",
        "src/Common/PrecompiledHeaders"
    }

    links
    {
        "GLFW",
        "Dwmapi.lib",
        "GLAD",
        "opengl32.lib"
    }

	defines
	{
		"GLFW_INCLUDE_NONE",
		"STB_IMAGE_IMPLEMENTATION"
	}

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "Full"

    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        flags { "LinkTimeOptimization" }