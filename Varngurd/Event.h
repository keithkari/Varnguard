#pragma once
#include "Core.h"
#include <vector>
#include <tuple>
#include <unordered_map>
#include <memory>
#include <string>
#include <functional>

namespace Varnguard
{
	enum class Event_Type
	{
		None = 0,
		WindowResize, WindowClose,  WindowMove,
		KeyPressed, KeyReleased,
		AppUpdate, AppRender,
		MouseMove, MouseClicked, MouseReleased, MouseScrolled
	};

	#define EVENT_FLAG_TYPE(flag) virtual int get_flag() override { return flag; }

	enum Event_Category
	{
		None = 0,
		Input = SET_BIT(1),
		Keyboard = SET_BIT(2),
		Window = SET_BIT(3),
		Application = SET_BIT(4),
		Mouse = SET_BIT(5),
	};

	class VARNGUARD_API Events
	{
	public:
		virtual Event_Type get_event_type() = 0;
		virtual std::string get_event_name() = 0;
		virtual int get_flag() = 0;

		inline bool is_in_category(Event_Category category)
		{
			return (get_flag() & category) != 0;
		}

		bool m_handled = false;
	};


	class Event_dispatcher
	{
		template<typename T>
		using Callback = std::function<bool(T&)>;
	public:
		Event_dispatcher(Events& event) : m_event(event)
		{

		}

		template<typename T>
		bool dispach(Callback<T> func)
		{
			if (m_event.get_event_type() == T::get_static_event())
			{
				m_event.m_handled = func(static_cast<T&>(m_event));
				return m_event.m_handled;
			}
			return false;
		}

	private:
		Events& m_event;
	};

	template<Event_Type type>
	class Evaluate_Event_Type : public Events
	{
	public:
		Evaluate_Event_Type() = default;

		Event_Type get_static_event() { return type; }

		virtual Event_Type get_event_type() override { return get_static_event(); }

		virtual std::string get_event_name() override
		{
			size_t index = static_cast<size_t>(type);

			std::vector<std::string> eventType =
			{
				"None", "WindowResize", "WindowClose",  "WindowMove",
				"KeyPressed", "KeyReleased", "AppUpdate", "AppRender", "MouseMove",
				"MouseClicked", "MouseReleased", "MouseScrolled"
			};

			if (index < eventType.size())
			{
				return eventType[index];
			}
			return "Unknown";
		}
	};

}

#define EVENT_TYPE(type) std::make_tuple( \
  Varnguard::Evaluate_Event_Type<Varnguard::Event_Type::type>::get_static_event(),\
  Varnguard::Evaluate_Event_Type<Varnguard::Event_Type::type>::get_event_type(), \
  Varnguard::Evaluate_Event_Type<Varnguard::Event_Type::type>::get_event_name() \
)