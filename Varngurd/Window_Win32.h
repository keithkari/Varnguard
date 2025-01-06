#ifdef VG_OS_WINDOWS

#pragma once
#include "Window.h"
#include "KeyEvents.h"
#include "Mouse.h"
#include "ApplicationEvents.h"

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
	
		HWND hwnd;
		HINSTANCE instance;
	private:
		static LRESULT CALLBACK winproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			static Event_dispatcher dispatcher;

			static bool Initilised = false;

			if (!Initilised)
			{
				dispatcher.Add_Listeners<key_pressed>([](Events& e)
					{
						auto& keyp_event = static_cast<key_pressed&>(e);
						VG_LOG_CLIENT_INFO("Key Pressed: {0}", keyp_event.GetKeyCode());
					})
			}

			dispatcher.Add_Listeners<MouseMovedEvent>([](Events& e)
				{
					auto& mousem_event = static_cast<MouseMovedEvent&>(e);
					VG_LOG_CLIENT_INFO("Mouse Moved to:""(x = {0}, y = {1})""", mousem_event.getx(), mousem_event.gety());
				});

			Initilised = true;

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
			case WM_KEYDOWN:
			{
				key_pressed key(static_cast<int>(wparam));
				dispatcher.Dispach_Messege<key_pressed>(key);
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
