#include "VG_PCH.h"
#include "Application.h"
#include "Log.h"


namespace Varnguard
{
	Application::Application()
	{
		window = std::make_unique<Window_Win32>();
		if(window == nullptr)
			VG_LOG_CLIENT_CRITICAL("Unable to create window");
		VG_LOG_CORE_INFO("Welcome to Varnguard Engine");
		window->create_window("Varnguard Engine", 1280, 720);
		window->show();
		oncreate(window->hwnd);
	}

	Application::~Application()
	{
		VG_LOG_CORE_INFO("Closing core engine");
	}

	void Application::run()
	{
		MSG msg = {};
		while (GetMessageA(&msg, window->hwnd, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			VG_LOG_CORE_INFO("Reading windows messeges");
			ren.swap_buffer();
			VG_LOG_CORE_INFO("Buffer Swaped");
			ren.clear_buffer(0.5f, 1.0f, 0.3f, 1.0f);
			VG_LOG_CORE_INFO("Buffer cleared");
		
		}
	}

	void Application::oncreate(HWND handle)
	{
		VG_LOG_CORE_INFO("Window Created");
		ren.init(handle);
	}
	void Application::ondestroy()
	{
		
	}
}
