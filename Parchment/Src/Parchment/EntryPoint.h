#pragma once

#ifdef PCH_PLATFORM_WINDOWS

extern Parch::Application* Parch::CreateApplication();

int main(int argc, char** argv)
{
	Parch::Log::Init();

	PCH_CORE_INFO("Initialized Log!");

	auto app = Parch::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Parchment only supports Windows£¡
#endif