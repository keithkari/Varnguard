#pragma once
#include "Core.h"
#include "Event.h"

namespace Varnguard
{
	class VARNGUARD_API keyevent : public Events
	{
	public:
		int GetKeyCode() { return m_keycode; }

		EVENT_FLAG_TYPE(Keyboard | Input);
	protected:
		keyevent(int keycode) : m_keycode(keycode) {}

		int m_keycode;
	};

	class VARNGUARD_API key_pressed : public keyevent
	{
	public:
		key_pressed(int keycode, int repeat) : keyevent(keycode), m_repeat(repeat) {}

		int get_reapeat() { return m_repeat; }

		EVENT_TYPE(KeyPressed);
		
	private:
		int m_repeat;	
	};

	class VARNGUARD_API key_released : public keyevent
	{
	public:
		key_released(int keycode) : keyevent(keycode){}

		EVENT_TYPE(KeyReleased);
	};
}