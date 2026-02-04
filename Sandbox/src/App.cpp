#include <Octopus.h>

class ExampleLayer : public Octopus::Layer
{
	public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
	}

	void OnEvent(Octopus::Event& event) override
	{
	}
};

class Sandbox : public Octopus::Application
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

Octopus::Application* Octopus::CreateApplication()
{
	return new Sandbox();
}