project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "on"
    flags { "MultiProcessorCompile", "ShadowedVariables" }
    optimize "Full"

    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin/intermediates/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

	files
	{
		"glad.h",
		"KHR/khrplatform.h",
		"src/glad.c"
	}
    
    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "Full"

    filter "configurations:Release"
        runtime "Release"
        flags { "LinkTimeOptimization" }