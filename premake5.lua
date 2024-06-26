workspace "Parchment"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Parchment/vendor/GLFW/include"
IncludeDir["Glad"] = "Parchment/vendor/Glad/include"
IncludeDir["Imgui"] = "Parchment/vendor/imgui"
 
include "Parchment/vendor/GLFW"
include "Parchment/vendor/Glad"
include "Parchment/vendor/imgui"

project "Parchment"
	location "Parchment"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Pchpch.h"
	pchsource "Parchment/Src/Pchpch.cpp"

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/Src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.Imgui}"
	}

	links
	{
		"ImGui",
		"GLFW",
		"Glad",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PCH_PLATFORM_WINDOWS",
			"PCH_BUUILD_DLL",
			"PCH_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PCH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PCH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PCH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"Parchment/vendor/spdlog/include",
		"Parchment/Src"
	}

	links
	{
		"Parchment"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PCH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PCH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PCH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PCH_DIST"
		optimize "On"