#pragma once

#include "Parchment/Core.h"
#include "Parchment/Events/Event.h"
#include "Parchment/Events/ApplicationEvent.h"
#include "Parchment/Window.h"
#include "Parchment/LayerStack.h"

namespace Parch {
	
	class PCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

