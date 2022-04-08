project "GameEngine"
    kind "StaticLib"
    language "C++"
	cppdialect "C++20"
    flags { "MultiProcessorCompile", "OmitDefaultLibrary", "ShadowedVariables" }
	staticruntime "On"
    optimize "Full"

    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    pchheader "PrecompiledHeaders.h"
    pchsource "src/PrecompiledHeaders/PrecompiledHeaders.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "Dependencies",
        "src",
        "src/PrecompiledHeaders"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "Dwmapi.lib",
        "GLAD"
    }

	defines
	{
        "RENDERER_USE_OPENGL",
		"GLFW_INCLUDE_NONE",
		"STB_IMAGE_IMPLEMENTATION"
	}

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "Full"

    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        flags { "LinkTimeOptimization" }