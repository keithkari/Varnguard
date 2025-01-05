#pragma once

#include"VG_PCH.h"
#include "Window.h"
#include "Window_Win32.h"
#include "Renderer.h"

namespace Varnguard
{
	class VARNGUARD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		void oncreate(HWND handle);
		void ondestroy();
		Renderer ren;

	private:
		std::unique_ptr<Window_Win32> window;
	};

	std::unique_ptr<Application> createobject();
}

