#pragma once
#include "Core.h"
#include "Event.h"

namespace Varnguard
{
	class VARNGUARD_API WindowResize : public Events
	{
	public:
		WindowResize(int width, int height) : m_width(width), m_height(height){}

		int get_width() { return m_width; }

		int get_height() { return m_height; }

		EVENT_FLAG_TYPE(Window);

		EVENT_TYPE(WindowResize);

	private:
		int m_width;
		int m_height;
	};

	class VARNGUARD_API Windowclose : public Events
	{
	public:
		Windowclose();

		EVENT_FLAG_TYPE(Window);

		EVENT_TYPE(WindowClose);
	};

	class VARNGUARD_API Appupdate : public Events
	{
	public:
		Appupdate();

		EVENT_FLAG_TYPE(Application);

		EVENT_TYPE(AppUpdate);
	};

	class VARNGUARD_API Apprender : public Events
	{
		Apprender();

		EVENT_FLAG_TYPE(Application);

		EVENT_TYPE(AppRender);
	};
}
