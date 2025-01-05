#include <Windows.h>
#include "Log.h"

#ifdef VG_OS_WINDOWS
	#ifdef VARNGUARD_BUILD_DLL
		#define VARNGUARD_API __declspec(dllexport)
	#else
		#define VARNGUARD_API __declspec(dllimport)
	#endif
#else
	#error "This library is Windows only."
#endif

#ifdef VG_OS_WINDOWS
	#ifdef _DEBUG

		#define VG_CORE_EVALUATE(x, ...) if(x != S_OK) {VG_LOG_CORE_CRITICAL("Evaluation Failed {0}", __VA_ARGS__); __debugbreak();}

		#define VG_CLIENT_EVALUATE(x, ...) if(x != S_OK) {VG_LOG_CLIENT_CRITICAL("Evaluation Failed {0}", __VA_ARGS__); __debugbreak();}
	#else
	#define VG_CORE_EVALUATE(x, ...) if(x != S_OK) {VG_LOG_CORE_CRITICAL("Evaluation Failed {0}", __VA_ARGS__); exit(-1);}

	#define VG_CLIENT_EVALUATE(x, ...) if(x != S_OK) {VG_LOG_CLIENT_CRITICAL("Evaluation Failed {0}", __VA_ARGS__); exit(-1); }
	#endif 
#endif

#define SET_BIT(x) (1 << (x))