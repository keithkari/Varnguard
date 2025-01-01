#pragma once

#include"VG_PCH.h"
#include "Renderer.h"

namespace Varnguard
{
	class VARNGUARD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		void init();
		void oncreate(HWND handle);
		void ondestroy();
		HWND handle;
		HINSTANCE instance;
		Renderer ren;
	};

	std::unique_ptr<Application> createobject();
}

