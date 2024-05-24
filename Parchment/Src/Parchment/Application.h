#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Parch {
	
	class PCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

