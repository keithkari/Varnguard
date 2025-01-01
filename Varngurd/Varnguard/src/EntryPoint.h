#pragma once

#include "VG_PCH.h"
#include "Application.h"
#include "Log.h"

namespace Varnguard {
	extern std::unique_ptr<Application> createobject();
}


int main(int args, char* argv[])
{
	Varnguard::Log log{ argv[] };
	auto app = Varnguard::createobject();
	app->init();
	app->run();
}
