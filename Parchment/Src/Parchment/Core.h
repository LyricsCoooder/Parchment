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

#define BIT(x) (1 << x)
