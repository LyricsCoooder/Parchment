#pragma once

#include "Parchment/Events/Event.h"

namespace Parch {

	class PCH_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_ClASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		int m_KeyCode;

	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {}

	};

	class PCH_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_CLASS_TYPE(KeyPressed)
	
	private:
		int m_RepeatCount;
	};

	class PCH_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}