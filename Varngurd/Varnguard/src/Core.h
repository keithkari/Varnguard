
#ifdef VG_OS_WINDOWS
	#ifdef VARNGUARD_BUILD_DLL
		#define VARNGUARD_API __declspec(dllexport)
	#else
		#define VARNGUARD_API __declspec(dllimport)
	#endif
#else
	#error "This library is Windows only."
#endif

