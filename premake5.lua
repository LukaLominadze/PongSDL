workspace "NigoziEngine"
	configurations {
		"Debug",
		"Release"
	}

	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NigoziEngine"
	location "NigoziEngine"
	kind "SharedLib"

	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	defines { "NG_PLATFORM_WINDOWS", "NG_BUILD_DLL"}
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	vpaths {
		["Source Files"] = "%{prj.name}/src/**.cpp",
		["Header Files"] = "%{prj.name}/src/**.h"
	}

	includedirs { "%{prj.name}/src/" }

	pchheader "ngpch.h"
	pchsource "ngpch.cpp"

	configurations {
		"Debug",
		"Release"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		postbuildcommands{
			"{COPYFILE} %[%{wks.location}/bin/" ..outputdir.. "/%{prj.name}/NigoziEngine.dll] %[%{wks.location}/bin/" ..outputdir.. "/Sandbox/]"
		}

	filter "configurations:Debug"
		
		defines { "_DEBUG" }
		
		architecture "x64"
		symbols "On"

	filter "configurations:Release"
		
		defines { "NDEBUG" }

		architecture "x64"
		optimize "On"
