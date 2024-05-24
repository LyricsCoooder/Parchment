#pragma once

#include "Core.h"

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

