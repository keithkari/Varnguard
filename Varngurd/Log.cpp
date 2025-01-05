#include "VG_PCH.h"
#include "Log.h"
#include <format>

namespace Varnguard
{
	std::shared_ptr<spdlog::logger> Log::m_core;
	std::shared_ptr<spdlog::logger> Log::m_client;

	Log::Log()
	{

	}

	Log::~Log()
	{

	}

	void Log::init()
	{
		/*
		* The pattern flags:
		* %^ -> starts coloring of log message.
		* [%c] -> displays full date for example: "[2025-01-02 12:00:02]"
		* [%l] -> displays log level eg: [INFO].
		* [%t %P %s %! %#] -> displays thead id eg: main thead, proccess id eg: 1254, source file eg: main.cpp, function name eg: func(), line number eg: 81.
		  %n: -> displays the logger eg : VARNGUARD CORE:.
		  %v -> Log messege eg: "Engine initililesed".
		  %$ -> end coloration in log messege.
		*/
		spdlog::set_pattern("%^[%c][%l][%t %P][%s:%#] %n: %v%$");
		m_core = spdlog::stdout_color_mt("VARNGUARD CORE");
		m_core->set_level(spdlog::level::info);
		m_client = spdlog::stdout_color_mt("CLIENT APP");
		m_client->set_level(spdlog::level::info);
	}

}