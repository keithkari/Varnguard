#include "VG_PCH.h"
#include "Application.h"
#include <stdio.h>
#include <iostream>

LRESULT CALLBACK winproc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_NCCREATE:
		{
			CREATESTRUCT* param = reinterpret_cast<CREATESTRUCT*>(lparam);
			Varnguard::Application* app = reinterpret_cast<Varnguard::Application*>(param->lpCreateParams);
			SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)app);
		}
			std::cout << "Sent Messeage" << std::endl;
			break;
		case WM_CREATE:
		{
			Varnguard::Application* appc = reinterpret_cast <Varnguard::Application*>(GetWindowLongPtr(handle, GWLP_USERDATA));

			appc->oncreate(handle);
		}
		/*case WM_DESTROY:
		{
			Varnguard::Application* appd = reinterpret_cast <Varnguard::Application*>(GetWindowLongPtr(handle, GWLP_USERDATA));

			appd->ondestroy();
			printf("Closing Vanguard engine\n");
			PostQuitMessage(0);
			//DestroyWindow(handle);
			exit(0);
			break;
		}
		*/
	}

	return DefWindowProc(handle, msg, wparam, lparam);
}

namespace Varnguard
{
	Application::Application()
	{
		printf("Welcome to Varnguard engine\n");
	}

	Application::~Application()
	{
		printf("Bye!!\n");
		DestroyWindow(handle);
		exit(0);
	}

	void Application::run()
	{
		MSG msg;
		while (GetMessageA(&msg, handle, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			ren.swap_buffer();
			ren.clear_buffer(0.5f, 1.0f, 0.3f, 1.0f);
		}
	}
	void Application::init()
	{
		const LPCSTR class_name = "Varnguard Engine";
		WNDCLASSEX wc;
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = winproc;
		wc.lpszClassName = class_name;
		wc.hInstance = instance;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.hIconSm = nullptr;
		wc.lpszMenuName = nullptr;
		wc.style = 0;

		RegisterClassEx(&wc);

		handle = CreateWindow(class_name, "Varnguard Engine", WS_OVERLAPPEDWINDOW, 15, 15, 1268, 720, nullptr, nullptr, instance, this);
		if (!handle)
		{
			printf("Error inisilising the window\n");
			exit(-1);
		}
		
		ShowWindow(handle, SW_SHOW);
		UpdateWindow(handle);
	}
	void Application::oncreate(HWND handle)
	{
		std::cout << "Created actual window" << std::endl;
		ren.init(handle);
	}
	void Application::ondestroy()
	{
		std::cout << "Closing Window" << std::endl;
	}
}
