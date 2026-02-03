#include <Octopus.h>

class Sandbox : public Octopus::Application
{
public:
	Sandbox()
	{
	}
	
	~Sandbox()
	{
	}
};

Octopus::Application* Octopus::CreateApplication()
{
	return new Sandbox();
}