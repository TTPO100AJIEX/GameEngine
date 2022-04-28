project "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
    flags { "MultiProcessorCompile", "OmitDefaultLibrary", "ShadowedVariables" }
	staticruntime "On"
	optimize "Full"

	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
        "src",
		"%{wks.location}/GameEngine/Dependencies",
		"%{wks.location}/GameEngine/src",
		"%{wks.location}/GameEngine/src/PrecompiledHeaders"
	}

	links
	{
		"GameEngine"
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