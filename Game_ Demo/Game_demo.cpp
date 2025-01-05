#define SPDLOG_COMPILED_LIB
#include <Varnguard.h>
#include <memory>
#include <stdio.h>

using namespace Varnguard;

class game : public Application
{
public:
	game();
	~game();
};

std::unique_ptr<Application> Varnguard::createobject()
{
	VG_LOG_CLIENT_INFO("Returning client object");
	return std::make_unique<game>();
}

game::game()
{
	VG_LOG_CLIENT_INFO("Client created");
}

game::~game()
{
	VG_LOG_CLIENT_INFO("Client destroyed");
}