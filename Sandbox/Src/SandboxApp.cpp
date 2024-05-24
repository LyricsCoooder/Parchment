#include "Parchment.h"

class Sandbox : public Parch::Application
{
public:
	Sandbox()
	{
		 
	}

	~Sandbox()
	{

	}
};

Parch::Application* Parch::CreateApplication()
{
	return new Sandbox();
}