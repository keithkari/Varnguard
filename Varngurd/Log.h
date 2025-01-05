#pragma once

#define SPDLOG_COMPILED_LIB
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"
#include "Core.h"

namespace Varnguard
{
	class VARNGUARD_API Log
	{
	public:
		Log();
		~Log();

		inline static std::shared_ptr<spdlog::logger>& getcore(){ return m_core; }

		inline static std::shared_ptr<spdlog::logger>& getclient() { return m_client; }

		void init();

	private:
		static std::shared_ptr<spdlog::logger> m_core;
		static std::shared_ptr<spdlog::logger> m_client;
	};

}

#define VG_LOG_CORE_INFO(...) ::Varnguard::Log::getcore()->info( __VA_ARGS__)
#define VG_LOG_CORE_WARNING(...) ::Varnguard::Log::getcore()->warn( __VA_ARGS__)
#define VG_LOG_CORE_ERROR(...) ::Varnguard::Log::getcore()->error( __VA_ARGS__)
#define VG_LOG_CORE_CRITICAL(...)::Varnguard::Log:: getcore()->critical( __VA_ARGS__)

#define VG_LOG_CLIENT_INFO( ...) ::Varnguard::Log::getclient()->info( __VA_ARGS__) 
#define VG_LOG_CLIENT_WARNING( ...) ::Varnguard::Log::getclient()->warn( __VA_ARGS__)
#define VG_LOG_CLIENT_ERROR( ...) ::Varnguard::Log::getclient()->error( __VA_ARGS__) 
#define VG_LOG_CLIENT_CRITICAL( ...) ::Varnguard::Log::getclient()->critical( __VA_ARGS__)

