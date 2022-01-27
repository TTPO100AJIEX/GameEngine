project "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/GameEngine/Dependencies",
		"%{wks.location}/GameEngine/src",
		"%{wks.location}/GameEngine/src/PrecompiledHeaders"
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