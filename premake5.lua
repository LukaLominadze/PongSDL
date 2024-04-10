workspace "PongRemake"
	configurations {
		"Debug",
		"Release"
	}

	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PongRemake"
	location "PongRemake"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	defines { "_CONSOLE" }

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	vpaths {
		["Source Files"] = "%{prj.name}/src/**.cpp",
		["Header Files"] = "%{prj.name}/src/**.h"
	}

	includedirs { "vendor/SDL2/include" }

	libdirs { "vendor/SDL2/lib/x64" }

	links {
		"SDL2.lib",
		"SDL2main.lib"
	}

	configurations {
		"Debug",
		"Release"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		postbuildcommands{
			"{COPYFILE} %[%{wks.location}/vendor/SDL2/lib/x64/SDL2.dll] %[%{prj.location}]"
		}

	filter "configurations:Debug"

		defines { "_DEBUG" }

		architecture "x64"
		symbols "On"

	filter "configurations:Release"

		defines { "NDEBUG" }

		architecture "x64"
		optimize "On"
