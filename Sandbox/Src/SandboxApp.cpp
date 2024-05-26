#include "Parchment.h"

class ExampleLayer : public Parch::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	//void OnUpdate() override
	//{
	//	PCH_INFO("ExampleLayer:OnUpdate");
	//}

	void OnEvent(Parch::Event& event) override
	{
		PCH_TRACE("ExampleLayer:   {}", event.GetName());
	}
};

class Sandbox : public Parch::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Parch::Application* Parch::CreateApplication()
{
	return new Sandbox();
}