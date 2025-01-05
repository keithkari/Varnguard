#pragma once
#include "Core.h"
#include "Event.h"

namespace Varnguard
{
	class VARNGUARD_API MouseMovedEvent : public Events
	{
		MouseEvent(float x, float y) : x(x), y(y){}
		
		float getx() { return x; }
		float gety() { return y; }

		EVENT_FLAG_TYPE(Input | Mouse);
		EVENT_TYPE(MouseMove);
	private:
		float x;
		float y;
	};

	class VARNGUARD_API MouseScrolledEvent : public Events
	{
		MouseEvent(float xoff, float yoff) : xoff(xoff), yoff(yoff) {}

		float getx() { return xoff; }
		float gety() { return yoff; }

		EVENT_FLAG_TYPE(Input | Mouse);
		EVENT_TYPE(MouseScroll);
	private:
		float xoff;
		float yoff;
	};

	class VARNGUARD_API mouseclick : public Events
	{
	public:
		int GetMouseButton() { return m_button; }

		EVENT_FLAG_TYPE(Mouse | Input);
	protected:
		mouseclick(int button) : m_button(button) {}

		int m_button;
	};

	class VARNGUARD_API mouse_clicke : public mouseclick
	{
	public:
		key_pressed(int button) : mouseclick(button) {}

		EVENT_TYPE(MouseClicked);
	};

	class VARNGUARD_API key_released : public mouseclick
	{
	public:
		key_released(int button) : mouseclick(button) {}

		EVENT_TYPE(MouseReleased);
	};
}
