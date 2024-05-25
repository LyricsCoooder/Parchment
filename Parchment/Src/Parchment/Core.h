#pragma once

#ifdef PCH_PLATFORM_WINDOWS
	#ifdef PCH_BUUILD_DLL
		#define PCH_API __declspec(dllexport)
	#else	
		#define PCH_API __declspec(dllimport)
	#endif
#else
	#error Parchment only supports Windows£¡
#endif

#ifdef PCH_ENABLE_ASSERTS
	#define PCH_ASSERT(x, ...) {if(!(x)) { PCH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PCH_CORE_ASSERT(x, ...) {if(!(x)) { PCH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PCH_ASSERT(x, ...)
	#define PCH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
