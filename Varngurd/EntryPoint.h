#pragma once

#include "VG_PCH.h"
#include "Application.h"
#include "Log.h"

namespace Varnguard {
	extern std::unique_ptr<Application> createobject();
}

using namespace Varnguard;

int main(int args, char* argv[])
{
	Log log;
	log.init();

	auto app = createobject();
	VG_LOG_CLIENT_INFO("Created Application object");
	VG_LOG_CLIENT_INFO("Engine Initilied");
	app->run();
	VG_LOG_CLIENT_INFO("Engine Running");
}
