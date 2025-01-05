#ifdef VG_OS_WINDOWS

#pragma once
#include "Window.h"

namespace Varnguard
{
	class Window_Win32 : public Window
	{
	public:
		Window_Win32() : hwnd(nullptr), instance(GetModuleHandle(nullptr)) {};
		~Window_Win32();

		bool create_window(std::string title, int width, int height) override;
		void show() override;
		void hide() override;
		void destroy() override;
		CallbackFn& SetEventCallback(const CallbackFn& callback) override { return EventCallback = callback; }
	
		HWND hwnd;
		HINSTANCE instance;
	private:
		static LRESULT CALLBACK winproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			switch (msg)
			{
			case WM_NCCREATE:
			{
				CREATESTRUCT* param = reinterpret_cast<CREATESTRUCT*>(lparam);
				Window_Win32* app = reinterpret_cast<Window_Win32*>(param->lpCreateParams);
				SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)app);

				VG_LOG_CORE_INFO("Window created: WM_NCCREATE.");
				break;
			}
			case WM_CLOSE:
			{
				VG_LOG_CORE_INFO("Close confirmation requested.");
				if (MessageBox(hwnd, "Are you sure you want to exit?", "Quit Confirmation", MB_OKCANCEL | MB_ICONWARNING) == IDOK)
				{
					DestroyWindow(hwnd);
				}
				else
					return 0;

				break;
			}

			case WM_DESTROY:
			{
				Window_Win32* appd = reinterpret_cast <Window_Win32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

				appd->destroy();

				break;
			}
			}

			return DefWindowProc(hwnd, msg, wparam, lparam);
		}

	};
}
#else
	#error This is the windows windowing system.
#endif
