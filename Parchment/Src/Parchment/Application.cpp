#include "Pchpch.h"
#include "Application.h"

#include "Parchment/Events/ApplicationEvent.h"
#include "Parchment/Log.h"

namespace Parch {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		PCH_INFO("{}: (Height:{}, Width:{})", e.GetName(), e.GetHeight(), e.GetWidth());
		
		while (true)
		{

		}
	}

}
