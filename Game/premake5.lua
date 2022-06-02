project "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
    flags { "MultiProcessorCompile", "ShadowedVariables" }
	staticruntime "On"
	optimize "Full"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    pchheader "pch.h"
    pchsource "src/pch/pch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
        "Dependencies",
        "src",
        "src/pch",

		"%{wks.location}/GameEngine/src",
        "%{wks.location}/GameEngine/src/Common/PrecompiledHeaders",
        "%{wks.location}/GameEngine/Dependencies",
	}

	links
	{
		"GameEngine"
	}
	
	defines
	{
		"RENDERER_USE_OPENGL"
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