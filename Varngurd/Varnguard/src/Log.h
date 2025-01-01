#pragma once
#include "Core.h"

namespace Varnguard
{
	class VARNGUARD_API Log
	{
	public:
		Log();
		~Log();

		template<typename... Args>
		void info (const char* fmt, Args... args);

		template<typename... Args>
		void warning(const char* fmt, Args... args);

		template<typename... Args>
		void error(const char* fmt, Args... args);

		template<typename... Args>
		void fatal(const char* fmt, Args... args);

		#define VG_LOG_INFO(fmt, ...) info(fmt, __VA_ARGS__)
		#define VG_LOG_WARNING(fmt, ...) warning(fmt, __VA_ARGS__)
		#define VG_LOG_ERROR(fmt, ...) error(fmt, __VA_ARGS__)
		#define VG_LOG_FATAL(fmt, ...) fatal(fmt, __VA_ARGS__)

	};
}

