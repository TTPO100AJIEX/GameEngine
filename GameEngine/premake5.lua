project "GameEngine"
    kind "SharedLib"
    language "C++"
	cppdialect "C++20"
	staticruntime "off"

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
        "GLAD"
    }

	defines
	{
		"BUILD_DLL", "GLFW_INCLUDE_NONE"
	}

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PLATFORM_WINDOWS"
        }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Game/\"")
		}

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        optimize "On"