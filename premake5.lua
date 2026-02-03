workspace "Octopus"
	architecture "x64"
	startproject "sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Octopus/vendor/GLFW/include"

include "Octopus/vendor/GLFW"

project "Octopus"
	location "Octopus"
	kind "StaticLib"
	language "C++"
	buildoptions{"/utf-8"}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ocpch.h"
	pchsource "Octopus/src/ocpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
	
	filter "configurations:Debug"
		symbols "On"
		defines
		{
			"ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions{"/utf-8"}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Octopus/src",
		"Octopus/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"Octopus"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
	
	filter "configurations:Debug"
		symbols "On"
		defines
		{
			"ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"