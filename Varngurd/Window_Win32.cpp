#include "VG_PCH.h"
#include "Window_Win32.h"

namespace Varnguard
{
	Window_Win32::~Window_Win32()
	{
	}

	bool Window_Win32::create_window(std::string title, int width, int height)
	{
		const LPCSTR class_name = "Varnguard Engine";
		WNDCLASSEX wc;
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = winproc;
		wc.lpszClassName = class_name;
		wc.hInstance = instance;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.hIconSm = nullptr;
		wc.lpszMenuName = nullptr;
		wc.style = 0;

		if (!RegisterClassEx(&wc)) {
			VG_LOG_CORE_CRITICAL("Failed to register window class");
			return false;
		}

		hwnd = CreateWindow(class_name, title.c_str(), WS_OVERLAPPEDWINDOW, 43, 24, width, height, nullptr, nullptr, instance, this);
		if (!hwnd)
		{
			VG_LOG_CORE_CRITICAL("Unable to initilise window");
			exit(-1);
			return false;
		}
		else
			VG_LOG_CORE_INFO("Window Initilised size: width = {0}, height = {1} and name = {2}", width, height, title);

		return true;
	}

	void Window_Win32::show()
	{
		if (hwnd) {
			ShowWindow(hwnd, SW_SHOW);
			UpdateWindow(hwnd);
		}
		else {
			VG_LOG_CORE_WARNING("Attempted to show an uninitialized window");
		}
	}

	void Window_Win32::hide()
	{
		if (hwnd) {
			ShowWindow(hwnd, SW_HIDE);
		}
		else {
			VG_LOG_CORE_WARNING("Attempted to hide an uninitialized window");
		}
	}

	void Window_Win32::destroy()
	{
		if (hwnd) {
			VG_LOG_CORE_INFO("Destroying window");
			PostQuitMessage(0);
			hwnd = nullptr;
		}
		else {
			VG_LOG_CORE_WARNING("Attempted to destroy an uninitialized window");
		}
	}
	
}