#include "Parchment.h"


class Sandbox : public Parch::Application
{
public:
	Sandbox()
	{
		PushLayer(new Parch::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Parch::Application* Parch::CreateApplication()
{
	return new Sandbox();
}