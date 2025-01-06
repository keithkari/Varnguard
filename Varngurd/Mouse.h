#pragma once
#include "Core.h"
#include "Event.h"

namespace Varnguard
{
	class VARNGUARD_API MouseMovedEvent : public Events
	{
	public:
		MouseEvent(float x, float y) : x(x), y(y) {};
		
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
	public:
		MouseEvent(float xoff, float yoff) : xoff(xoff), yoff(yoff) {};

		float getxoff() { return xoff; }
		float getyoff() { return yoff; }

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

}
