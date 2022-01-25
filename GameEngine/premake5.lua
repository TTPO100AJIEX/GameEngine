project "GameEngine"
    kind "StaticLib"
    language "C++"
	cppdialect "C++20"
	staticruntime "on"

    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    pchheader "PrecompiledHeaders.h"
    pchsource "Dependencies/PrecompiledHeaders/PrecompiledHeaders.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "Dependencies/PrecompiledHeaders/**.h",
        "Dependencies/PrecompiledHeaders/**.cpp"
    }

    includedirs
    {
        "Dependencies",
        "Dependencies/PrecompiledHeaders",
        "src"
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
		"GLFW_INCLUDE_NONE"
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
        symbols "on"

    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        optimize "on"