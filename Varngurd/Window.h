#pragma once
#include "Event.h"

namespace Varnguard
{
	class Window
	{
	public:
		using CallbackFn = std::function<void(Events&)>;
		virtual ~Window() = default;
		virtual bool create_window(std::string title, int width, int height) = 0;
		virtual void show() = 0;
		virtual void hide() = 0;
		virtual void destroy() = 0;
	};
}