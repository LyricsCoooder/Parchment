#pragma once

#include "Parchment/Core.h"
#include "Parchment/Events/Event.h"
#include "Parchment/Events/ApplicationEvent.h"
#include "Parchment/Window.h"

namespace Parch {
	
	class PCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

