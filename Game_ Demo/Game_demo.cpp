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
	return std::make_unique<game>();
}

game::game()
{
}

game::~game()
{
	printf("Bye game!!\n");
	DestroyWindow(handle);
}